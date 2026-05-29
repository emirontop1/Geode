#!/usr/bin/env python3
"""Small repository check for the generated Geode menu source.

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
SOURCE = ROOT / "src" / "main.cpp"


def main() -> int:
    source = SOURCE.read_text(encoding="utf-8")

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

    print(f"OK: {len(member_names)} void definitions checked, {len(selectors)} menu selectors resolved")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
