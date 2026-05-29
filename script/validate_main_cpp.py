#!/usr/bin/env python3
"""Small repository check for Geode menu source files.

This catches the exact class of regressions that previously broke Android CI:
accidentally duplicated ModernMenu handler/helper definitions, and menu_selector
callbacks that do not have a matching method body.
"""

from __future__ import annotations

import re
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCES = sorted((ROOT / "src").glob("*.cpp"))


def main() -> int:
    if not SOURCES:
        print("No src/*.cpp files found", file=sys.stderr)
        return 1

    source = "\n".join(path.read_text(encoding="utf-8") for path in SOURCES)

    member_names = re.findall(r"^\s{4}void\s+(\w+)\s*\(", source, flags=re.MULTILINE)
    counts = Counter(member_names)
    duplicates = sorted(name for name, count in counts.items() if count > 1)

    selectors = set(re.findall(r"menu_selector\(ModernMenu::(\w+)\)", source))
    missing_selectors = sorted(name for name in selectors if counts[name] == 0)

    if duplicates or missing_selectors:
        if duplicates:
            print("Duplicate ModernMenu/global void definitions:", ", ".join(duplicates), file=sys.stderr)
        if missing_selectors:
            print("menu_selector callbacks without handlers:", ", ".join(missing_selectors), file=sys.stderr)
        return 1

    files = ", ".join(str(path.relative_to(ROOT)) for path in SOURCES)
    print(f"OK: {len(member_names)} void definitions checked, {len(selectors)} menu selectors resolved in {files}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
