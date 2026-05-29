# Geode SDK — Complete Class & Function Reference

Bu belge Geode SDK'nın tüm sınıflarını ve fonksiyonlarını içermektedir.
Kaynak: `geode-sdk/bindings` (GD v2.2081) + `geode-sdk/geode` loader headers

**Toplam Sınıf:** 726  
**Toplam Metod:** 10476  

---

## Geometry Dash (608 classes)

### `AccountHelpLayer` : GJDropDownLayer, GJAccountDelegate, FLAlertLayerProtocol

**Functions:**

- `AccountHelpLayer()`
- `~AccountHelpLayer()`
- `static AccountHelpLayer* create()`
- `virtual void customSetup()`
- `virtual void layerHidden()`
- `virtual void accountStatusChanged()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void doUnlink()`
- `void exitLayer()`
- `void onAccountManagement(cocos2d::CCObject* sender)`
- `void onReLogin(cocos2d::CCObject* sender)`
- `void onUnlink(cocos2d::CCObject* sender)`
- `void updatePage()`
- `void verifyUnlink()`

**Members:**

- `cocos2d::CCLabelBMFont* m_loginStatusLabel`
- `TextArea* m_textArea`
- `CCMenuItemSpriteExtra* m_refreshLoginButton`
- `CCMenuItemSpriteExtra* m_unlinkAccountButton`
- `bool m_unk290`

### `AccountLayer` : GJDropDownLayer, GJAccountDelegate, GJAccountBackupDelegate, GJAccountSyncDelegate, FLAlertLayerProtocol

**Functions:**

- `static AccountLayer* create()`
- `virtual void customSetup()`
- `virtual void layerHidden()`
- `virtual void backupAccountFinished()`
- `virtual void backupAccountFailed(BackupAccountError errorType, int response)`
- `virtual void syncAccountFinished()`
- `virtual void syncAccountFailed(BackupAccountError errorType, int response)`
- `virtual void accountStatusChanged()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void createToggleButton(gd::string text, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `void doBackup()`
- `void doSync()`
- `void exitLayer()`
- `void hideLoadingUI()`
- `void onBackup(cocos2d::CCObject* sender)`
- `void onHelp(cocos2d::CCObject* sender)`
- `void onLogin(cocos2d::CCObject* sender)`
- `void onMore(cocos2d::CCObject* sender)`
- `void onRegister(cocos2d::CCObject* sender)`
- `void onSync(cocos2d::CCObject* sender)`
- `void showLoadingUI()`
- `void toggleUI(bool enable)`
- `void updatePage(bool changed)`

**Members:**

- `cocos2d::CCLabelBMFont* m_linkedAccountTitle`
- `TextArea* m_textArea`
- `CCMenuItemSpriteExtra* m_loginButton`
- `CCMenuItemSpriteExtra* m_registerButton`
- `CCMenuItemSpriteExtra* m_backupButton`
- `CCMenuItemSpriteExtra* m_syncButton`
- `CCMenuItemSpriteExtra* m_helpButton`
- `CCMenuItemSpriteExtra* m_moreButton`
- `LoadingCircle* m_loadingCircle`
- `int m_accountHelpRelated`
- `bool m_isLoggedIn`

### `AccountLoginLayer` : FLAlertLayer, TextInputDelegate, GJAccountLoginDelegate, FLAlertLayerProtocol

**Functions:**

- `static AccountLoginLayer* create(gd::string username)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void loginAccountFinished(int accountID, int userID)`
- `virtual void loginAccountFailed(AccountError errorType)`
- `cocos2d::extension::CCScale9Sprite* createTextBackground(cocos2d::CCPoint position, char const* text, cocos2d::CCSize size)`
- `CCTextInputNode* createTextInput(cocos2d::CCPoint position, cocos2d::CCSize size, char const* text, int tag)`
- `cocos2d::CCLabelBMFont* createTextLabel(cocos2d::CCPoint position, char const* text, cocos2d::CCSize size)`
- `void disableNodes()`
- `void hideLoadingUI()`
- `bool init(gd::string username)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onForgotPassword(cocos2d::CCObject* sender)`
- `void onForgotUser(cocos2d::CCObject* sender)`
- `void onSubmit(cocos2d::CCObject* sender)`
- `void resetLabel(int tag)`
- `void resetLabels()`
- `void showLoadingUI()`
- `void toggleUI(bool enable)`
- `void updateLabel(AccountError type)`

**Members:**

- `CCTextInputNode* m_usernameInput`
- `CCTextInputNode* m_passwordInput`
- `cocos2d::CCLabelBMFont* m_usernameLabel`
- `cocos2d::CCLabelBMFont* m_passwordLabel`
- `LoadingCircle* m_loadingCircle`
- `gd::string m_username`
- `gd::string m_password`

### `AccountRegisterLayer` : FLAlertLayer, TextInputDelegate, GJAccountRegisterDelegate, FLAlertLayerProtocol

**Functions:**

- `AccountRegisterLayer()`
- `~AccountRegisterLayer()`
- `static AccountRegisterLayer* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `virtual bool allowTextInput(CCTextInputNode* node)`
- `virtual void registerAccountFinished()`
- `virtual void registerAccountFailed(AccountError errorType)`
- `cocos2d::extension::CCScale9Sprite* createTextBackground(cocos2d::CCPoint position, cocos2d::CCSize size)`
- `CCTextInputNode* createTextInput(cocos2d::CCPoint position, cocos2d::CCSize size, gd::string text, int tag)`
- `cocos2d::CCLabelBMFont* createTextLabel(cocos2d::CCPoint position, gd::string text, cocos2d::CCSize size)`
- `void disableNodes()`
- `void hideLoadingUI()`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSubmit(cocos2d::CCObject* sender)`
- `void resetLabel(int tag)`
- `void resetLabels()`
- `void showLoadingUI()`
- `void toggleUI(bool enable)`
- `void updateLabel(AccountError type)`
- `bool validEmail(gd::string email)`
- `bool validPassword(gd::string password)`
- `bool validUser(gd::string username)`

**Members:**

- `CCTextInputNode* m_usernameField`
- `CCTextInputNode* m_passwordField`
- `CCTextInputNode* m_confirmPasswordField`
- `CCTextInputNode* m_emailField`
- `CCTextInputNode* m_verifyEmailField`
- `cocos2d::CCLabelBMFont* m_usernameLabel`
- `cocos2d::CCLabelBMFont* m_passwordLabel`
- `cocos2d::CCLabelBMFont* m_confirmPasswordLabel`
- `cocos2d::CCLabelBMFont* m_emailLabel`
- `cocos2d::CCLabelBMFont* m_verifyEmailLabel`
- `LoadingCircle* m_loadingCircle`
- `bool m_lockInput`

### `AchievementBar` : cocos2d::CCNodeRGBA

**Functions:**

- `AchievementBar()`
- `static AchievementBar* create(char const* title, char const* desc, char const* icon, bool quest)`
- `virtual void setOpacity(unsigned char opacity)`
- `bool init(char const* title, char const* desc, char const* icon, bool quest)`
- `void show()`

**Members:**

- `cocos2d::CCLayerColor* m_layerColor`
- `int m_unkUnused`
- `cocos2d::CCScene* m_nextScene`
- `cocos2d::extension::CCScale9Sprite* m_bg`
- `cocos2d::extension::CCScale9Sprite* m_bg2`
- `cocos2d::CCSprite* m_achievementGlowSprite`
- `cocos2d::CCSprite* m_achievementSprite`
- `cocos2d::CCLabelBMFont* m_titleLabel`
- `TextArea* m_achievementDescription`

### `AchievementCell` : TableViewCell

**Functions:**

- `AchievementCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromDict(cocos2d::CCDictionary* dict)`
- `void updateBGColor(int index)`

### `AchievementManager` : cocos2d::CCNode

**Functions:**

- `static AchievementManager* sharedState()`
- `virtual bool init()`
- `gd::string achievementForUnlock(int id, UnlockType type)`
- `void addAchievement(gd::string identifier, gd::string title, gd::string achievedDescription, gd::string unachievedDescription, gd::string icon, int limits)`
- `void addManualAchievements()`
- `bool areAchievementsEarned(cocos2d::CCArray* achievements)`
- `void checkAchFromUnlock(char const* id)`
- `void dataLoaded(DS_Dictionary* dict)`
- `void encodeDataTo(DS_Dictionary* dict)`
- `void firstSetup()`
- `cocos2d::CCDictionary* getAchievementRewardDict()`
- `cocos2d::CCDictionary* getAchievementsWithID(char const* id)`
- `cocos2d::CCArray* getAllAchievements()`
- `cocos2d::CCArray* getAllAchievementsSorted(bool available)`
- `bool isAchievementAvailable(gd::string id)`
- `bool isAchievementEarned(char const* ach)`
- `int limitForAchievement(gd::string id)`
- `void notifyAchievement(char const* title, char const* description, char const* icon)`
- `void notifyAchievementWithID(char const* id)`
- `int percentageForCount(int count, int total)`
- `int percentForAchievement(char const* id)`
- `void reportAchievementWithID(char const* id, int percent, bool dontNotify)`
- `void reportPlatformAchievementWithID(char const* id, int percent)`
- `void resetAchievement(char const* id)`
- `void resetAchievements()`
- `void setup()`
- `void storeAchievementUnlocks()`

**Members:**

- `cocos2d::CCArray* m_allAchievements`
- `cocos2d::CCDictionary* m_platformAchievements`
- `cocos2d::CCDictionary* m_achievementUnlocks`
- `void* m_unkPtrUnused`
- `cocos2d::CCDictionary* m_reportedAchievements`
- `bool m_dontNotify`
- `cocos2d::CCArray* m_allAchievementsSorted`
- `int m_order`
- `cocos2d::CCDictionary* m_unAchieved`

### `AchievementNotifier` : cocos2d::CCNode

**Functions:**

- `static AchievementNotifier* sharedState()`
- `virtual bool init()`
- `void achievementDisplayFinished()`
- `void notifyAchievement(char const* title, char const* desc, char const* icon, bool quest)`
- `void showNextAchievement()`
- `void willSwitchToScene(cocos2d::CCScene* scene)`

**Members:**

- `cocos2d::CCScene* m_nextScene`
- `cocos2d::CCArray* m_achievementBarArray`
- `AchievementBar* m_activeAchievementBar`

### `AchievementsLayer` : GJDropDownLayer

**Functions:**

- `AchievementsLayer()`
- `static AchievementsLayer* create()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void customSetup()`
- `void loadPage(int page)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void setupLevelBrowser(cocos2d::CCArray* arr)`
- `void setupPageInfo(int itemCount, int pageStartIdx, int pageEndIdx)`

**Members:**

- `int m_currentPage`
- `CCMenuItemSpriteExtra* m_nextPageButton`
- `CCMenuItemSpriteExtra* m_prevPageButton`
- `cocos2d::CCLabelBMFont* m_pageLabel`
- `cocos2d::CCPoint m_unkPoint`

### `AdToolbox`

**Functions:**

- `static void cacheInterstitial()`
- `static void cacheRewardedVideo()`
- `static void disableBanner()`
- `static void enableBanner()`
- `static void enableBannerNoRefresh()`
- `static bool hasCachedInterstitial()`
- `static bool hasCachedRewardedVideo()`
- `static bool isShowingAd()`
- `static void queueRefreshBanner()`
- `static void setupAds()`
- `static void showDebug()`
- `static void showInterstitial()`
- `static void showRewardedVideo()`

### `AdvFollowSetup`

**Members:**

- `gd::unordered_set<int> m_centerIDs`
- `gd::unordered_set<int> m_groupIDs`
- `gd::unordered_set<int> m_controlIDs`
- `int m_delay`

### `AdvancedFollowEditObject` : AdvancedFollowTriggerObject

**Functions:**

- `AdvancedFollowEditObject()`
- `static AdvancedFollowEditObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `float m_modX`
- `float m_modXVariance`
- `float m_modY`
- `float m_modYVariance`
- `bool m_redirectDirection`

### `AdvancedFollowTriggerObject` : EffectGameObject

**Functions:**

- `AdvancedFollowTriggerObject()`
- `static AdvancedFollowTriggerObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `int getAdvancedFollowID()`
- `bool init(char const* frame)`

**Members:**

- `float m_delay`
- `float m_delayVariance`
- `float m_startSpeed`
- `float m_startSpeedVariance`
- `int m_startSpeedReference`
- `float m_startDirection`
- `float m_startDirectionVariance`
- `int m_startDirectionReference`
- `float m_maxSpeed`
- `float m_maxSpeedVariance`
- `bool m_xOnly`
- `bool m_yOnly`
- `float m_maxRange`
- `float m_maxRangeVariance`
- `float m_property310`
- `float m_property311`
- `float m_acceleration`
- `float m_accelerationVariance`
- `float m_property312`
- `float m_property313`
- `float m_property314`
- `float m_property315`
- `float m_steerForce`
- `float m_steerForceVariance`
- `bool m_steerForceLowEnabled`
- `float m_steerForceLow`
- `float m_steerForceLowVariance`
- `bool m_steerForceHighEnabled`
- `float m_steerForceHigh`
- `float m_steerFroceHighVariance`
- `float m_speedRangeLow`
- `float m_speedRangeLowVariance`
- `float m_speedRangeHigh`
- `float m_speedRangeHighVariance`
- `float m_breakForce`
- `float m_breakForceVariance`
- `float m_breakAngle`
- `float m_breakAngleVariance`
- `float m_breakSteerForce`
- `float m_breakSteerForceVariance`
- `float m_breakSteerSpeedLimit`
- `float m_breakSteerSpeedLimitVariance`
- `bool m_targetDirection`
- `bool m_ignoreDisabled`
- `bool m_rotateDirection`
- `float m_rotationOffset`
- `float m_nearAcceleration`
- `float m_nearAccelerationVariance`
- `float m_nearDistance`
- `float m_nearDistanceVariance`
- `float m_nearFriction`
- `float m_nearFrictionVariance`
- `float m_friction`
- `float m_frictionVariance`
- `float m_easing`
- `float m_easingVariance`
- `float m_rotateEasing`
- `float m_rotateDeadZ`
- `int m_priority`
- `int m_unk7fc`
- `int m_maxRangeReference`
- `int m_followMode`
- `bool m_exclusive`
- `int m_startMode`

### `AnimatedGameObject` : EnhancedGameObject, AnimatedSpriteDelegate, SpritePartDelegate

**Functions:**

- `AnimatedGameObject()`
- `~AnimatedGameObject()`
- `static gd::string animationForID(int type, int id)`
- `static AnimatedGameObject* create(int id)`
- `static float getTweenTime(int type, int id)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void setChildColor(cocos2d::ccColor3B const& color)`
- `virtual void resetObject()`
- `virtual void activateObject()`
- `virtual void deactivateObject(bool deactivate)`
- `virtual void setObjectColor(cocos2d::ccColor3B const& color)`
- `virtual void animationFinished(char const* key)`
- `virtual void displayFrameChanged(cocos2d::CCObject* sprite, gd::string frameName)`
- `bool init(int id)`
- `void playAnimation(int type)`
- `void setupAnimatedSize(int id)`
- `void setupChildSprites()`
- `void updateChildSpriteColor(cocos2d::ccColor3B color)`
- `void updateObjectAnimation()`

**Members:**

- `CCAnimatedSprite* m_animatedSprite`
- `cocos2d::CCSprite* m_childSprite`
- `CCSpritePart* m_eyeSpritePart`
- `bool m_finishedAnimating`
- `bool m_playingAnimation`
- `gd::string m_currentAnimation`
- `bool m_notGrounded`
- `int m_animationID`

### `AnimatedShopKeeper` : CCAnimatedSprite

**Functions:**

- `AnimatedShopKeeper()`
- `static AnimatedShopKeeper* create(ShopType type)`
- `virtual void animationFinished(char const* key)`
- `bool init(ShopType type)`
- `void playReactAnimation()`
- `void startAnimating()`

**Members:**

- `ShopType m_type`
- `int m_idleInt1`
- `int m_idleInt2`
- `bool m_looking`
- `bool m_reacting`
- `int m_reactCount`
- `int m_gruntIndex`

### `AnimatedSpriteDelegate`

**Functions:**

- `virtual void animationFinished(char const* key)`

### `AppDelegate` : cocos2d::CCApplication, cocos2d::CCSceneDelegate

**Functions:**

- `static AppDelegate* get()`
- `virtual bool applicationDidFinishLaunching()`
- `virtual void applicationDidEnterBackground()`
- `virtual void applicationWillEnterForeground()`
- `virtual void applicationWillBecomeActive()`
- `virtual void applicationWillResignActive()`
- `virtual void trySaveGame(bool force)`
- `virtual void willSwitchToScene(cocos2d::CCScene* scene)`
- `float bgScale()`
- `void checkSound()`
- `void hideLoadingCircle()`
- `void loadingIsFinished()`
- `bool musicTest()`
- `void pauseGame()`
- `void pauseSound()`
- `void platformShutdown()`
- `void resumeSound()`
- `void setIdleTimerDisabled(bool disabled)`
- `void setupGLView()`
- `void showLoadingCircle(bool unk1, bool unk2, bool unk3)`

**Members:**

- `bool m_glViewSetup`
- `bool m_gamePaused`
- `cocos2d::CCScene* m_runningScene`
- `bool m_loadingFinished`
- `bool m_unk0e9`
- `bool m_ios`
- `bool m_unk0eb`
- `bool m_unk0ec`
- `bool m_needsSafeArea`
- `float m_saveTime`

### `ArtTriggerGameObject` : EffectGameObject

**Functions:**

- `ArtTriggerGameObject()`
- `static ArtTriggerGameObject* create(char const* frame)`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `int m_artIndex`

### `ArtistCell` : TableViewCell

**Functions:**

- `ArtistCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromObject(SongInfoObject* object)`
- `void onNewgrounds(cocos2d::CCObject* sender)`
- `void onYouTube(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `SongInfoObject* m_songInfo`

### `AudioAssetsBrowser` : FLAlertLayer, TableViewCellDelegate, MusicDownloadDelegate

**Functions:**

- `AudioAssetsBrowser()`
- `~AudioAssetsBrowser()`
- `static AudioAssetsBrowser* create(gd::vector<int>& songIds, gd::vector<int>& sfxIds)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void musicActionFinished(GJMusicAction action)`
- `virtual void musicActionFailed(GJMusicAction action)`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `virtual int getSelectedCellIdx()`
- `virtual int getCellDelegateType()`
- `bool init(gd::vector<int>& songIds, gd::vector<int>& sfxIds)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onPage(cocos2d::CCObject* sender)`
- `void setupList()`
- `void trySetupAudioBrowser()`
- `void updatePageLabel()`

**Members:**

- `cocos2d::CCArray* m_songInfoObjects`
- `GJCommentListLayer* m_songList`
- `cocos2d::CCLabelBMFont* m_pageIndicatorLabel`
- `gd::vector<int> m_songsIds`
- `gd::vector<int> m_sfxIds`
- `LoadingCircleSprite* m_loadingCircle`

### `AudioEffectsLayer` : cocos2d::CCLayerColor

**Functions:**

- `AudioEffectsLayer()`
- `~AudioEffectsLayer()`
- `static AudioEffectsLayer* create(gd::string audioString)`
- `virtual void draw()`
- `virtual void updateTweenAction(float value, char const* key)`
- `void audioStep(float dt)`
- `cocos2d::CCSprite* getBGSquare()`
- `void goingDown()`
- `bool init(gd::string audioString)`
- `void resetAudioVars()`
- `void triggerEffect(float pulse)`

**Members:**

- `cocos2d::CCSpriteBatchNode* m_batchNode`
- `cocos2d::CCArray* m_unk1bc`
- `cocos2d::CCArray* m_unk1c0`
- `float m_timeElapsed`
- `float m_audioPulseMod`
- `bool m_goingDown`
- `float m_audioScale`
- `bool m_unk1d4`

### `AudioLineGuideGameObject` : EffectGameObject

**Functions:**

- `AudioLineGuideGameObject()`
- `static AudioLineGuideGameObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `int m_beatsPerMinute`
- `int m_beatsPerBar`
- `Speed m_speed`
- `bool m_disabled`

### `BitmapFontCache` : cocos2d::CCObject

**Functions:**

- `BitmapFontCache()`
- `~BitmapFontCache()`
- `static void purgeSharedFontCache()`
- `static BitmapFontCache* sharedFontCache()`
- `FontObject* fontWithConfigFile(char const* font, float scale)`
- `bool init()`

**Members:**

- `cocos2d::CCDictionary* m_cache`

### `BonusDropdown` : cocos2d::CCNode

**Functions:**

- `static BonusDropdown* create(gd::string text, int price)`
- `bool init(gd::string text, int price)`
- `void show()`

**Members:**

- `cocos2d::CCLayerColor* m_layerColor`
- `float m_yPosition`
- `cocos2d::CCScene* m_scene`

### `BoomListLayer` : cocos2d::CCLayerColor

**Functions:**

- `static BoomListLayer* create(BoomListView* listView, char const* title)`
- `bool init(BoomListView* listView, char const* title)`

### `BoomListView` : cocos2d::CCLayer, TableViewDelegate, TableViewDataSource

**Functions:**

- `BoomListView()`
- `~BoomListView()`
- `static BoomListView* create(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y)`
- `virtual void draw()`
- `virtual void setupList(float yOffset)`
- `virtual void TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView)`
- `virtual float cellHeightForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView)`
- `virtual void didSelectRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView)`
- `virtual int numberOfRowsInSection(unsigned int section, TableView* tableView)`
- `virtual unsigned int numberOfSectionsInTableView(TableView* tableView)`
- `virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView)`
- `virtual void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView* tableView, TableViewCellEditingStyle style, CCIndexPath& indexPath)`
- `virtual void TableViewWillReloadCellForRowAtIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView)`
- `virtual TableViewCell* getListCell(char const* identifier)`
- `virtual void loadCell(TableViewCell* cell, int index)`
- `void addObjectToList(cocos2d::CCNode* node)`
- `bool init(cocos2d::CCArray* entries, BoomListType type, float width, float height)`
- `bool init(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y)`
- `void lockList(bool locked)`

**Members:**

- `TableView* m_tableView`
- `cocos2d::CCArray* m_entries`
- `BoomListType m_type`
- `float m_height`
- `float m_width`
- `float m_itemSeparation`
- `int m_currentPage`
- `bool m_locked`

### `BoomScrollLayer` : cocos2d::CCLayer

**Functions:**

- `BoomScrollLayer()`
- `~BoomScrollLayer()`
- `static BoomScrollLayer* create(cocos2d::CCArray* pages, int offset, bool looped)`
- `static BoomScrollLayer* create(cocos2d::CCArray* pages, int offset, bool looped, cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate)`
- `virtual void visit()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `void addPage(cocos2d::CCLayer* page)`
- `void addPage(cocos2d::CCLayer* page, int index)`
- `void cancelAndStoleTouch(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `void claimTouch(cocos2d::CCTouch* touch)`
- `cocos2d::CCLayer* getPage(int page)`
- `int getRelativePageForNum(int page)`
- `cocos2d::CCPoint getRelativePosForPage(int page)`
- `int getTotalPages()`
- `bool init(cocos2d::CCArray* pages, int offset, bool looped, cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate)`
- `void instantMoveToPage(int page)`
- `void moveToPage(int page)`
- `void moveToPageEnded()`
- `int pageNumberForPosition(cocos2d::CCPoint position)`
- `cocos2d::CCPoint positionForPageWithNumber(int page)`
- `void quickUpdate()`
- `void removePage(cocos2d::CCLayer* page)`
- `void removePageWithNumber(int page)`
- `void repositionPagesLooped()`
- `void selectPage(int page)`
- `void setDotScale(float scale)`
- `void setPagesIndicatorPosition(cocos2d::CCPoint pos)`
- `void setupDynamicScrolling(cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate)`
- `void togglePageIndicators(bool visible)`
- `void updateDots(float dt)`
- `void updatePages()`

**Members:**

- `cocos2d::CCArray* m_dots`
- `int m_slowPage`
- `float m_touchX`
- `float m_touchQuotient`
- `bool m_looped`
- `DynamicScrollDelegate* m_dynamicDelegate`
- `cocos2d::CCArray* m_dynamicObjects`
- `bool m_dynamic`
- `int m_touchType`
- `bool m_ignoreTouchCancel`
- `cocos2d::CCTouch* m_touch`
- `cocos2d::CCArray* m_pages`
- `double m_touchTime`
- `cocos2d::CCPoint m_position`
- `ExtendedLayer* m_extendedLayer`
- `cocos2d::CCRect m_rect`
- `float m_unkFloat1`
- `float m_maxSpeed`
- `float m_minSpeed`
- `float m_unkFloat2`
- `BoomScrollLayerDelegate* m_delegate`
- `bool m_pageMoving`
- `bool m_pagesInvisible`
- `float m_minimumTouchLengthToSlide`
- `float m_minimumTouchLengthToChangePage`
- `float m_width; //marginOffset in Rob terms`
- `bool m_cancelAndStealTouch`
- `bool m_dotsVisible`
- `cocos2d::CCPoint m_dotPosition`
- `cocos2d::ccColor4B m_selectedPageColor`
- `cocos2d::ccColor4B m_normalPageColor`
- `int m_page`
- `float m_pageOffset`
- `void* m_unkPtr`
- `bool m_doVisit`
- `cocos2d::CCRect m_clippingRect`

### `BoomScrollLayerDelegate`

**Functions:**

- `virtual void scrollLayerScrollingStarted(BoomScrollLayer* layer)`
- `virtual void scrollLayerScrolledToPage(BoomScrollLayer* layer, int page)`
- `virtual void scrollLayerMoved(cocos2d::CCPoint position)`
- `virtual void scrollLayerWillScrollToPage(BoomScrollLayer* layer, int page)`

### `BrowseSmartKeyLayer` : BrowseSmartTemplateLayer

**Functions:**

- `BrowseSmartKeyLayer()`
- `static BrowseSmartKeyLayer* create(GJSmartTemplate* smartTemplate, gd::string prefabKey)`
- `virtual void onBack(cocos2d::CCObject* sender)`
- `void addChanceToSelected(int chance, bool zero)`
- `void createTemplateObjects()`
- `void deletedSelectedItems()`
- `cocos2d::CCArray* getAllSelectedBlocks()`
- `bool init(GJSmartTemplate* smartTemplate, gd::string prefabKey)`
- `void onButton(cocos2d::CCObject* sender)`
- `void onPrefabObject(cocos2d::CCObject* sender)`
- `void updateChanceValues()`

**Members:**

- `gd::string m_prefabKey`
- `int m_templatePage`

### `BrowseSmartTemplateLayer` : FLAlertLayer

**Functions:**

- `BrowseSmartTemplateLayer()`
- `~BrowseSmartTemplateLayer()`
- `static BrowseSmartTemplateLayer* create(GJSmartTemplate* smartTemplate, SmartBrowseFilter browseFilter)`
- `virtual void keyBackClicked()`
- `virtual void onBack(cocos2d::CCObject* sender)`
- `void addObjectToPage(cocos2d::CCObject* object, int page)`
- `void addPrefabMenuItem(SmartPrefabResult result, int index)`
- `void baseSetup()`
- `void createDots()`
- `void createPrefab(gd::string key, int id)`
- `void goToPage(int page)`
- `bool init(GJSmartTemplate* smartTemplate, SmartBrowseFilter browseFilter)`
- `void onClick(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onTemplateObject(cocos2d::CCObject* sender)`
- `void updateDots()`

**Members:**

- `GJSmartTemplate* m_template`
- `cocos2d::CCArray* m_pages`
- `int m_page`
- `cocos2d::CCNode* m_nextPageBtn`
- `cocos2d::CCNode* m_prevPageBtn`
- `cocos2d::CCArray* m_dotsArray`

### `ButtonPage` : cocos2d::CCLayer

**Functions:**

- `ButtonPage()`
- `static ButtonPage* create(cocos2d::CCArray* objects, cocos2d::CCPoint position, int rows, float spacing)`
- `bool init(cocos2d::CCArray* objects, cocos2d::CCPoint position, int rows, float spacing)`

### `ButtonSprite` : cocos2d::CCSprite

**Functions:**

- `ButtonSprite()`
- `static ButtonSprite* create(char const* caption)`
- `static ButtonSprite* create(cocos2d::CCSprite* topSprite)`
- `static ButtonSprite* create(char const* caption, float scale)`
- `static ButtonSprite* create(char const* caption, const char* font, const char* texture)`
- `static ButtonSprite* create(char const* caption, const char* font, const char* texture, float scale)`
- `static ButtonSprite* create(char const* caption, int width, int minWidth, float scale, bool absolute)`
- `static ButtonSprite* create(cocos2d::CCSprite* topSprite, int width, bool absolute, float height, const char* texture, float scale)`
- `static ButtonSprite* create(cocos2d::CCSprite* topSprite, int width, int minWidth, float height, float scale, bool absolute)`
- `static ButtonSprite* create(char const* caption, int width, int minWidth, float scale, bool absolute, char const* font, char const* bg)`
- `static ButtonSprite* create(const char* caption, int width, bool absolute, const char* font, const char* texture, float height, float scale)`
- `static ButtonSprite* create(char const* caption, int width, int minWidth, float scale, bool absolute, char const* font, char const* bg, float height)`
- `static ButtonSprite* create(cocos2d::CCSprite* topSprite, int width, int minWidth, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG)`
- `bool init(char const* caption, int width, int minWidth, float scale, bool absolute, char const* font, char const* bg, float height)`
- `bool init(cocos2d::CCSprite* topSprite, int width, int minWidth, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG)`
- `void setColor(cocos2d::ccColor3B color)`
- `void setString(char const* text)`
- `void updateBGImage(char const* filename)`
- `void updateSpriteBGSize()`
- `void updateSpriteOffset(cocos2d::CCPoint offset)`

**Members:**

- `int m_mode`
- `float m_width`
- `float m_minWidth`
- `float m_scale`
- `float m_height`
- `bool m_absolute`
- `cocos2d::CCLabelBMFont* m_label`
- `cocos2d::CCSprite* m_subSprite`
- `cocos2d::CCSprite* m_subBGSprite`
- `cocos2d::extension::CCScale9Sprite* m_BGSprite`
- `cocos2d::CCPoint m_textOffset`
- `cocos2d::CCPoint m_spritePosition`
- `gd::string m_caption`

### `CCAlertCircle` : cocos2d::CCNode

**Functions:**

- `static CCAlertCircle* create()`
- `virtual bool init()`
- `virtual void draw()`

**Members:**

- `CCCircleAlert* m_circleAlert`

### `CCAnimateFrameCache` : cocos2d::CCObject

**Functions:**

- `static CCAnimateFrameCache* get()`
- `static CCAnimateFrameCache* sharedSpriteFrameCache()`
- `void addCustomSpriteFramesWithFile(char const* filename)`
- `cocos2d::CCDictionary* addDict(DS_Dictionary* dict, char const* filename)`
- `cocos2d::CCDictionary* addDict(cocos2d::CCDictionary* dict, char const* filename)`
- `cocos2d::CCDictionary* addSpriteFramesWithFile(char const* filename)`
- `bool init()`
- `void purgeSharedSpriteFrameCache()`
- `void removeSpriteFrames()`
- `cocos2d::CCArray* spriteFrameByName(char const* name)`

**Members:**

- `cocos2d::CCDictionary* m_animateFrames`
- `cocos2d::CCDictionary* m_unk040`
- `cocos2d::CCDictionary* m_animateDescriptions`

### `CCAnimatedSprite` : cocos2d::CCSprite

**Functions:**

- `CCAnimatedSprite()`
- `~CCAnimatedSprite()`
- `static CCAnimatedSprite* createWithType(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void setColor(cocos2d::ccColor3B const& color)`
- `virtual void animationFinished(char const* key)`
- `virtual void animationFinishedO(cocos2d::CCObject* str)`
- `void cleanupSprite()`
- `bool initWithType(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture)`
- `void loadType(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture)`
- `void runAnimation(gd::string animation)`
- `void runAnimationForced(gd::string animation)`
- `void stopTween()`
- `void switchToMode(spriteMode mode)`
- `void tweenToAnimation(gd::string animation, float duration)`
- `void tweenToAnimationFinished()`
- `void willPlayAnimation()`

**Members:**

- `gd::string m_unkString1`
- `gd::string m_activeTween`
- `SpriteAnimationManager* m_animationManager`
- `cocos2d::CCSprite* m_sprite`
- `cocos2d::CCSprite* m_fbfSprite`
- `CCPartAnimSprite* m_paSprite`
- `spriteMode m_spriteMode`
- `gd::string m_currentAnim`
- `AnimatedSpriteDelegate* m_delegate`

### `CCBlockLayer` : cocos2d::CCLayerColor

**Functions:**

- `CCBlockLayer()`
- `~CCBlockLayer()`
- `static CCBlockLayer* create()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void customSetup()`
- `virtual void enterLayer()`
- `virtual void exitLayer()`
- `virtual void showLayer(bool instant)`
- `virtual void hideLayer(bool instant)`
- `virtual void layerVisible()`
- `virtual void layerHidden()`
- `virtual void enterAnimFinished()`
- `virtual void disableUI()`
- `virtual void enableUI()`
- `void decrementForcePrio()`
- `void incrementForcePrio()`

**Members:**

- `bool m_closeOnHide`
- `bool m_forcePrioRegistered`

### `CCCircleAlert` : CCCircleWave

**Functions:**

- `static CCCircleAlert* create(float duration, float startRadius, float endRadius)`
- `bool init(float duration, float startRadius, float endRadius)`

### `CCCircleWave` : cocos2d::CCNode

**Functions:**

- `static CCCircleWave* create(float startRadius, float endRadius, float duration, bool fadeIn)`
- `static CCCircleWave* create(float startRadius, float endRadius, float duration, bool fadeIn, bool easeOut)`
- `virtual void setPosition(cocos2d::CCPoint const& position)`
- `virtual void removeMeAndCleanup()`
- `virtual void draw()`
- `virtual void updateTweenAction(float value, char const* key)`
- `void baseSetup(float radius)`
- `void followObject(cocos2d::CCNode* newTarget, bool staticPosition)`
- `bool init(float startRadius, float endRadius, float duration, bool fadeIn, bool easeOut)`
- `void updatePosition(float dt)`

**Members:**

- `cocos2d::CCNode* m_target`
- `float m_width`
- `float m_radius`
- `float m_opacity`
- `cocos2d::ccColor3B m_color`
- `cocos2d::CCPoint m_position`
- `CircleMode m_circleMode`
- `int m_lineWidth`
- `float m_opacityMod`
- `bool m_blendAdditive`
- `CCCircleWaveDelegate* m_delegate`

### `CCCircleWaveDelegate`

**Functions:**

- `virtual void circleWaveWillBeRemoved(CCCircleWave* circleWave)`

### `CCContentLayer` : cocos2d::CCLayerColor

**Functions:**

- `CCContentLayer()`
- `static CCContentLayer* create(cocos2d::ccColor4B const& color, float width, float height)`
- `virtual void setPosition(cocos2d::CCPoint const& position)`

### `CCCountdown` : cocos2d::CCSprite

**Functions:**

- `static CCCountdown* create()`
- `virtual bool init()`
- `virtual void setOpacity(unsigned char opacity)`
- `void lapFinished()`
- `void startTimerWithSeconds(float seconds, cocos2d::SEL_CallFunc selector, cocos2d::CCNode* target)`

**Members:**

- `cocos2d::CCProgressTimer* m_progressTimer`
- `float m_unk260`
- `int m_seconds`
- `cocos2d::CCLabelBMFont* m_countdownLabel`
- `cocos2d::SEL_CallFunc m_callbackSelector`
- `cocos2d::CCNode* m_targetNode`

### `CCCounterLabel` : cocos2d::CCLabelBMFont

**Functions:**

- `CCCounterLabel()`
- `static CCCounterLabel* create(int count, char const* font, FormatterType type)`
- `void calculateStepSize(int steps)`
- `void disableCounter()`
- `void enableCounter()`
- `void fastUpdateCounter()`
- `int getTargetCount()`
- `bool init(int count, char const* font, FormatterType type)`
- `void setTargetCount(int count)`
- `void updateCounter(float dt)`
- `void updateString()`

**Members:**

- `int m_stepSize`
- `int m_targetCount`
- `int m_currentCount`
- `bool m_counterEnabled`
- `int m_stepCount`
- `bool m_dontSchedule`
- `FormatterType m_formatterType`

### `CCExtenderNode` : cocos2d::CCNode

**Functions:**

- `void setOpacity(unsigned int opacity)`

### `CCIndexPath` : cocos2d::CCObject

**Functions:**

- `CCIndexPath()`
- `static CCIndexPath* CCIndexPathWithSectionRow(int section, int row)`

**Members:**

- `int m_row`
- `int m_section`

### `CCLightFlash` : cocos2d::CCNode

**Functions:**

- `CCLightFlash()`
- `~CCLightFlash()`
- `static CCLightFlash* create()`
- `virtual bool init()`
- `void cleanupFlash()`
- `void fadeAndRemove()`
- `void playEffect(cocos2d::CCPoint pos, cocos2d::ccColor3B col, float startWidth, float startWidthVariation, float endWidth, float endWidthVariation, float endHeight, float stripDuration, float stripDurationVariance, float stripInterval, float stripStartDelay, float stripStartDelayVariation, float stripRotation, float stripRotationVariation, float stripOpacity, float stripOpacityVariation, int stripCount, bool circleRotation, bool fadeIn, float delay)`
- `void removeLights()`
- `void showFlash()`

**Members:**

- `cocos2d::CCArray* m_lightStripArray`
- `cocos2d::CCLayerColor* m_layerColor`
- `bool m_dontFadeOut`
- `cocos2d::CCNode* m_mainLayer`
- `int m_layerColorZOrder`

### `CCLightStrip` : cocos2d::CCNode

**Functions:**

- `CCLightStrip()`
- `static CCLightStrip* create(float width, float toWidth, float toHeight, float duration, float delay)`
- `virtual void draw()`
- `virtual void updateTweenAction(float value, char const* keyword)`
- `bool init(float width, float toWidth, float toHeight, float duration, float delay)`

**Members:**

- `float m_objectWidth`
- `float m_toWidth`
- `float m_toHeight`
- `float m_duration`
- `cocos2d::ccColor4B m_color`
- `float m_opacity`
- `float m_width`
- `float m_height`

### `CCMenuItemSpriteExtra` : cocos2d::CCMenuItemSprite

**Functions:**

- `CCMenuItemSpriteExtra()`
- `static CCMenuItemSpriteExtra* create(cocos2d::CCNode* sprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback)`
- `static CCMenuItemSpriteExtra* create(cocos2d::CCNode* sprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback)`
- `virtual void activate()`
- `virtual void selected()`
- `virtual void unselected()`
- `bool init(cocos2d::CCNode* sprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback)`
- `void setSizeMult(float mult)`
- `void setSprite(cocos2d::CCSprite* sprite)`
- `void updateSprite()`
- `void useAnimationType(MenuAnimationType type)`

**Members:**

- `float m_scaleMultiplier`
- `float m_baseScale`
- `bool m_animationEnabled`
- `bool m_colorEnabled`
- `float m_volume`
- `gd::string m_activateSound`
- `gd::string m_selectSound`
- `float m_colorDip`
- `cocos2d::CCPoint m_offset`
- `float m_duration`
- `float m_unselectedDuration`
- `MenuAnimationType m_animationType`
- `cocos2d::CCPoint m_startPosition`
- `IconType m_iconType`

### `CCMenuItemToggler` : cocos2d::CCMenuItem

**Functions:**

- `CCMenuItemToggler()`
- `static CCMenuItemToggler* create(cocos2d::CCNode* off, cocos2d::CCNode* on, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback)`
- `static CCMenuItemToggler* createWithSize(const char* spr1, const char* spr2, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale)`
- `static CCMenuItemToggler* createWithStandardSprites(cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale)`
- `virtual void activate()`
- `virtual void selected()`
- `virtual void unselected()`
- `virtual void setEnabled(bool enabled)`
- `CCMenuItemSpriteExtra* activeItem()`
- `bool init(cocos2d::CCNode* off, cocos2d::CCNode* on, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback)`
- `bool isOn()`
- `bool isToggled()`
- `void normalTouch(cocos2d::CCObject* sender)`
- `void selectedTouch(cocos2d::CCObject* sender)`
- `void setClickable(bool on)`
- `void setSizeMult(float mult)`
- `void toggle(bool on)`
- `void toggleWithCallback(bool on)`
- `void updateSprite()`

**Members:**

- `CCMenuItemSpriteExtra* m_offButton`
- `CCMenuItemSpriteExtra* m_onButton`
- `bool m_toggled`
- `bool m_notClickable`

### `CCMoveCNode` : cocos2d::CCObject

**Functions:**

- `CCMoveCNode()`
- `static CCMoveCNode* create()`
- `bool init()`
- `void reset()`

**Members:**

- `double m_unk038`
- `double m_unk040`
- `double m_unk048`
- `void* m_unk050`
- `double m_unk058`
- `double m_unk060`
- `double m_unk068`
- `bool m_unk070`
- `bool m_unk071`
- `int m_unk074`
- `bool m_unk078`
- `int m_unk07c`
- `double m_unk080`
- `double m_unk088`
- `double m_unk090`
- `double m_unk098`
- `double m_unk0a0`
- `double m_unk0a8`
- `double m_unk0b0`
- `int m_unk0b8`
- `double m_unk0c0`
- `GroupCommandObject2* m_groupObject`
- `bool m_unk0d0`
- `bool m_unk0d1`
- `gd::vector<GroupCommandObject2*> m_groupObjects`

### `CCNodeContainer` : cocos2d::CCNode

**Functions:**

- `static CCNodeContainer* create()`
- `virtual bool init()`
- `virtual void visit()`

### `CCPartAnimSprite` : cocos2d::CCSprite

**Functions:**

- `CCPartAnimSprite()`
- `~CCPartAnimSprite()`
- `static CCPartAnimSprite* createWithAnimDesc(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture)`
- `virtual void setScaleX(float scaleX)`
- `virtual void setScaleY(float scaleY)`
- `virtual void setScale(float scale)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void setBlendFunc(cocos2d::ccBlendFunc blendFunc)`
- `virtual void setDisplayFrame(cocos2d::CCSpriteFrame* frame)`
- `virtual bool isFrameDisplayed(cocos2d::CCSpriteFrame* frame)`
- `virtual cocos2d::CCSpriteFrame* displayFrame()`
- `void changeTextureOfID(char const* key, char const* frame)`
- `int countParts()`
- `void dirtify()`
- `CCSpritePart* getSpriteForKey(char const* key)`
- `bool initWithAnimDesc(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture)`
- `void setColor(cocos2d::ccColor3B color)`
- `void setFlipX(bool flipX)`
- `void setFlipY(bool flipY)`
- `void transformSprite(SpriteDescription* description)`
- `void tweenSpriteTo(SpriteDescription* description, float duration)`
- `void tweenToFrame(cocos2d::CCSpriteFrame* frame, float duration)`

**Members:**

- `cocos2d::CCDictionary* m_spritePartIDs`
- `cocos2d::CCSpriteFrame* m_spriteFrame`
- `bool m_hasChanged`
- `cocos2d::CCSize m_unkSize`
- `cocos2d::CCArray* m_spriteParts`

### `CCScrollLayerExt` : cocos2d::CCLayer

**Functions:**

- `CCScrollLayerExt(cocos2d::CCRect rect)`
- `~CCScrollLayerExt()`
- `virtual void visit()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void preVisitWithClippingRect(cocos2d::CCRect rect)`
- `virtual void postVisit()`
- `void constraintContent()`
- `void doConstraintContent(bool instant)`
- `float getMaxY()`
- `float getMinY()`
- `void moveToTop()`
- `void moveToTopWithOffset(float offset)`
- `void scrollingEnd()`
- `void scrollLayer(float offset)`
- `void setContentLayerSize(cocos2d::CCSize size)`
- `void setContentOffset(cocos2d::CCPoint offset, bool animate)`
- `void updateIndicators(float dt)`

**Members:**

- `cocos2d::CCTouch* m_touch`
- `cocos2d::CCPoint m_touchPosition`
- `cocos2d::CCPoint m_touchStartPosition`
- `cocos2d::cc_timeval m_timeValue`
- `bool m_touchDown`
- `bool m_notAtEndOfScroll`
- `cocos2d::CCLayerColor* m_verticalScrollbar`
- `cocos2d::CCLayerColor* m_horizontalScrollbar`
- `CCScrollLayerExtDelegate* m_delegate`
- `CCContentLayer* m_contentLayer`
- `bool m_cutContent`
- `bool m_vScrollbarVisible`
- `bool m_hScrollbarVisible`
- `bool m_disableHorizontal`
- `bool m_disableVertical`
- `bool m_disableMovement`
- `float m_scrollLimitTop`
- `float m_scrollLimitBottom`
- `float m_peekLimitTop`
- `float m_peekLimitBottom`

### `CCScrollLayerExtDelegate`

**Functions:**

- `virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt* layer)`
- `virtual void scrollViewDidEndDecelerating(CCScrollLayerExt* layer)`
- `virtual void scrollViewTouchMoving(CCScrollLayerExt* layer)`
- `virtual void scrollViewDidEndMoving(CCScrollLayerExt* layer)`
- `virtual void scrollViewTouchBegin(CCScrollLayerExt* layer)`
- `virtual void scrollViewTouchEnd(CCScrollLayerExt* layer)`

### `CCSpriteCOpacity` : cocos2d::CCSprite

**Functions:**

- `CCSpriteCOpacity()`
- `static CCSpriteCOpacity* createWithSpriteFrame(cocos2d::CCSpriteFrame* frame)`
- `static CCSpriteCOpacity* createWithSpriteFrameName(char const* frameName)`
- `virtual void setOpacity(unsigned char opacity)`

### `CCSpriteGrayscale` : CCSpriteWithHue

**Functions:**

- `CCSpriteGrayscale()`
- `static CCSpriteGrayscale* create(gd::string const& file)`
- `static CCSpriteGrayscale* create(gd::string const& file, cocos2d::CCRect const& rect)`
- `static CCSpriteGrayscale* createWithSpriteFrame(cocos2d::CCSpriteFrame* frame)`
- `static CCSpriteGrayscale* createWithSpriteFrameName(gd::string const& frameName)`
- `static CCSpriteGrayscale* createWithTexture(cocos2d::CCTexture2D* texture)`
- `static CCSpriteGrayscale* createWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated)`
- `virtual gd::string getShaderName()`
- `virtual const char* shaderBody()`

### `CCSpritePart` : CCSpritePlus

**Functions:**

- `CCSpritePart()`
- `static CCSpritePart* create(cocos2d::CCTexture2D* texture)`
- `static CCSpritePart* createWithSpriteFrameName(char const* frame)`
- `virtual void setVisible(bool visible)`
- `void frameChanged(gd::string frame)`
- `bool getBeingUsed()`
- `void hideInactive()`
- `void markAsNotBeingUsed()`
- `void resetTextureRect()`
- `void setBeingUsed(bool beingUsed)`
- `void updateDisplayFrame(gd::string frame)`

**Members:**

- `bool m_isBeingUsed`
- `gd::string m_spriteFrameName`
- `SpritePartDelegate* m_delegate`

### `CCSpritePlus` : cocos2d::CCSprite

**Functions:**

- `CCSpritePlus()`
- `~CCSpritePlus()`
- `static CCSpritePlus* createWithSpriteFrame(cocos2d::CCSpriteFrame* frame)`
- `static CCSpritePlus* createWithSpriteFrameName(char const* frame)`
- `virtual void setScaleX(float scaleX)`
- `virtual void setScaleY(float scaleY)`
- `virtual void setScale(float scale)`
- `virtual void setPosition(cocos2d::CCPoint const& position)`
- `virtual void setRotation(float rotation)`
- `virtual void setRotationX(float rotationX)`
- `virtual void setRotationY(float rotationY)`
- `virtual bool initWithTexture(cocos2d::CCTexture2D* texture)`
- `virtual bool initWithSpriteFrameName(char const* frameName)`
- `virtual void setFlipX(bool flipX)`
- `virtual void setFlipY(bool flipY)`
- `void addFollower(cocos2d::CCNode* follower)`
- `void followSprite(CCSpritePlus* sprite)`
- `CCSpritePlus* getFollower()`
- `void removeFollower(cocos2d::CCNode* sprite)`
- `void stopFollow()`

**Members:**

- `cocos2d::CCArray* m_followers`
- `CCSpritePlus* m_followingSprite`
- `bool m_hasFollower`
- `bool m_propagateScaleChanges`
- `bool m_propagateFlipChanges`

### `CCSpriteWithHue` : cocos2d::CCSprite

**Functions:**

- `CCSpriteWithHue()`
- `static CCSpriteWithHue* create(gd::string const& file)`
- `static CCSpriteWithHue* create(gd::string const& file, cocos2d::CCRect const& rect)`
- `static CCSpriteWithHue* createWithSpriteFrame(cocos2d::CCSpriteFrame* frame)`
- `static CCSpriteWithHue* createWithSpriteFrameName(gd::string const& frameName)`
- `static CCSpriteWithHue* createWithTexture(cocos2d::CCTexture2D* texture)`
- `static CCSpriteWithHue* createWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated)`
- `virtual void draw()`
- `virtual bool initWithTexture(cocos2d::CCTexture2D* texture)`
- `virtual bool initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect)`
- `virtual bool initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated)`
- `virtual bool initWithSpriteFrame(cocos2d::CCSpriteFrame* frame)`
- `virtual gd::string getShaderName()`
- `virtual const char* shaderBody()`
- `virtual void updateColor()`
- `float getAlpha()`
- `float getHue()`
- `void getUniformLocations()`
- `void initShader()`
- `void setCustomLuminance(float r, float g, float b)`
- `void setEvenLuminance(float luminance)`
- `void setHue(float hue)`
- `void setHueDegrees(float degrees)`
- `void setLuminance(float luminance)`
- `void setupDefaultSettings()`
- `void updateColorMatrix()`
- `void updateHue(float unused)`

**Members:**

- `float m_hue`
- `std::array<float, 3> m_luminance`
- `std::array<std::array<float, 3>, 3> m_colorMatrix`
- `int m_uHueLoc`
- `int m_uAlphaLoc`
- `int m_uLumLoc`

### `CCTextInputNode` : cocos2d::CCLayer, cocos2d::CCIMEDelegate, cocos2d::CCTextFieldDelegate

**Functions:**

- `CCTextInputNode()`
- `~CCTextInputNode()`
- `static CCTextInputNode* create(float width, float height, char const* placeholder, char const* fontPath)`
- `static CCTextInputNode* create(float width, float height, char const* placeholder, int fontSize, char const* fontPath)`
- `static CCTextInputNode* create(float width, float height, char const* placeholder, char const* textFont, int fontSize, char const* labelFont)`
- `virtual void visit()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void textChanged()`
- `virtual void onClickTrackNode(bool selected)`
- `virtual void keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info)`
- `virtual void keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info)`
- `virtual bool onTextFieldInsertText(cocos2d::CCTextFieldTTF* pSender, char const* text, int nLen, cocos2d::enumKeyCodes keyCodes)`
- `virtual bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF* tField)`
- `virtual bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF* tField)`
- `void addTextArea(TextArea* textArea)`
- `void forceOffset()`
- `gd::string getString()`
- `cocos2d::CCLabelBMFont* getTextLabel()`
- `bool init(float width, float height, char const* placeholder, char const* textFont, int fontSize, char const* labelFont)`
- `void refreshLabel()`
- `void setAllowedChars(gd::string filter)`
- `void setDelegate(TextInputDelegate* delegate)`
- `void setLabelNormalColor(cocos2d::ccColor3B color)`
- `void setLabelPlaceholderColor(cocos2d::ccColor3B color)`
- `void setLabelPlaceholderScale(float v)`
- `void setMaxLabelLength(int v)`
- `void setMaxLabelScale(float v)`
- `void setMaxLabelWidth(float v)`
- `void setString(gd::string text)`
- `void updateBlinkLabel()`
- `void updateBlinkLabelToChar(int index)`
- `void updateCursorPosition(cocos2d::CCPoint position, cocos2d::CCRect rect)`
- `void updateDefaultFontValues(gd::string font)`
- `void updateLabel(gd::string text)`

**Members:**

- `bool m_numberInput`
- `gd::string m_caption`
- `int m_unknown1`
- `bool m_selected`
- `bool m_unknown2`
- `float m_fontValue1`
- `float m_fontValue2`
- `bool m_isChatFont`
- `gd::string m_allowedChars`
- `float m_maxLabelWidth`
- `float m_maxLabelScale`
- `float m_placeholderScale`
- `cocos2d::ccColor3B m_placeholderColor`
- `cocos2d::ccColor3B m_textColor`
- `cocos2d::CCLabelBMFont* m_cursor`
- `cocos2d::CCTextFieldTTF* m_textField`
- `TextInputDelegate* m_delegate`
- `int m_maxLabelLength`
- `cocos2d::CCLabelBMFont* m_textLabel`
- `bool m_filterSwearWords`
- `bool m_usePasswordChar`
- `bool m_forceOffset`
- `TextArea* m_textArea`
- `InputValueType m_valueType`
- `int m_decimalPlaces`
- `int m_kerningAmount`

### `CCURLObject` : cocos2d::CCObject

**Functions:**

- `static CCURLObject* create(gd::string name, gd::string url)`
- `bool init(gd::string name, gd::string url)`

**Members:**

- `gd::string m_name`
- `gd::string m_url`

### `CameraTriggerGameObject` : EffectGameObject

**Functions:**

- `CameraTriggerGameObject()`
- `static CameraTriggerGameObject* create(char const* frame)`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `bool m_exitStatic`
- `bool m_followObject`
- `float m_followEasing`
- `int m_edgeDirection`
- `bool m_smoothVelocity`
- `float m_velocityModifier`
- `bool m_exitInstant`
- `float m_previewOpacity`

### `ChallengeNode` : cocos2d::CCNode

**Functions:**

- `ChallengeNode()`
- `~ChallengeNode()`
- `static ChallengeNode* create(GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew)`
- `bool init(GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew)`
- `void onClaimReward(cocos2d::CCObject* sender)`
- `void updateTimeLabel(gd::string text)`

**Members:**

- `ChallengesPage* m_challengesPage`
- `GJChallengeItem* m_challengeItem`
- `cocos2d::CCPoint m_unkPoint`
- `cocos2d::CCLabelBMFont* m_countdownLabel`
- `bool m_unloaded`

### `ChallengesPage` : FLAlertLayer, FLAlertLayerProtocol, GJChallengeDelegate, CurrencyRewardDelegate

**Functions:**

- `ChallengesPage()`
- `~ChallengesPage()`
- `static ChallengesPage* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void challengeStatusFinished()`
- `virtual void challengeStatusFailed()`
- `virtual void currencyWillExit(CurrencyRewardLayer* layer)`
- `void claimItem(ChallengeNode* node, GJChallengeItem* item, cocos2d::CCPoint position)`
- `ChallengeNode* createChallengeNode(int number, bool skipAnimation, float animLength, bool isNew)`
- `void exitNodeAtSlot(int position, float delay)`
- `void onClose(cocos2d::CCObject* sender)`
- `void tryGetChallenges()`
- `void updateDots()`
- `callback void updateTimers(float dt)`

**Members:**

- `cocos2d::CCArray* m_dots`
- `cocos2d::CCLabelBMFont* m_countdownLabel`
- `LoadingCircle* m_circle`
- `bool m_triedToLoad`
- `bool m_unkBool`
- `CurrencyRewardLayer* m_currencyRewardLayer`
- `cocos2d::CCDictionary* m_challengeNodes`

### `ChanceTriggerGameObject` : EffectGameObject

**Functions:**

- `ChanceTriggerGameObject()`
- `bool containsTargetID(int id)`
- `void editChanceObject(int oldID, int newID)`
- `void getTargetIDs(gd::vector<int>& ids)`
- `bool init(char const* frame)`
- `void remapChanceObjects(gd::unordered_map<int, int> const* remap)`
- `void revertChanceRemap()`

**Members:**

- `gd::vector<ChanceObject> m_chanceObjects`

### `CharacterColorDelegate`

**Functions:**

- `virtual void playerColorChanged()`
- `virtual void showUnlockPopup(int id, UnlockType type)`

### `CharacterColorPage` : FLAlertLayer

**Functions:**

- `CharacterColorPage()`
- `~CharacterColorPage()`
- `static CharacterColorPage* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `int activeColorForMode(int mode)`
- `bool checkColor(int id, UnlockType type)`
- `int colorForIndex(int index)`
- `void createColorMenu()`
- `void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `cocos2d::CCPoint offsetForIndex(int index)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onMode(cocos2d::CCObject* sender)`
- `void onPlayerColor(cocos2d::CCObject* sender)`
- `void toggleGlow(cocos2d::CCObject* sender)`
- `void toggleGlowItems(bool visible)`
- `void toggleShip(cocos2d::CCObject* sender)`
- `void updateColorMode(int mode)`
- `void updateIconColors()`

**Members:**

- `int m_colorMode`
- `float m_height`
- `float m_width`
- `cocos2d::CCArray* m_playerObjects`
- `cocos2d::CCArray* m_modeButtons`
- `cocos2d::CCDictionary* m_colorButtons`
- `cocos2d::CCArray* m_cursors`
- `CharacterColorDelegate* m_delegate`
- `CCMenuItemToggler* m_glowToggler`
- `cocos2d::CCLabelBMFont* m_glowLabel`

### `CheckpointGameObject` : EffectGameObject

**Functions:**

- `CheckpointGameObject()`
- `static CheckpointGameObject* create()`
- `virtual bool init()`
- `virtual void setupCustomSprites(gd::string frameName)`
- `virtual void resetObject()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void triggerActivated(float xPosition)`
- `virtual void restoreObject()`
- `virtual void updateSyncedAnimation(float totalTime, int frameIndex)`
- `void resetCheckpoint()`
- `void updateCheckpointSpriteVisibility()`

**Members:**

- `bool m_checkpointActivated`
- `int m_respawnID`

### `CheckpointObject` : cocos2d::CCNode

**Functions:**

- `CheckpointObject()`
- `~CheckpointObject()`
- `static CheckpointObject* create()`
- `virtual bool init()`
- `GameObject* getObject()`
- `void setObject(GameObject* object)`

**Members:**

- `GJGameState m_gameState`
- `GJShaderState m_shaderState`
- `FMODAudioState m_audioState`
- `GameObject* m_physicalCheckpointObject`
- `PlayerCheckpoint* m_player1Checkpoint`
- `PlayerCheckpoint* m_player2Checkpoint`
- `int m_unke78`
- `int m_unke7c`
- `float m_unke80`
- `bool m_ground2Invisible`
- `bool m_streakBlend`
- `int m_uniqueID`
- `int m_respawnID`
- `gd::vector<SavedObjectStateRef> m_vectorSavedObjectStateRef`
- `gd::vector<SavedActiveObjectState> m_vectorActiveSaveObjectState`
- `gd::vector<SavedSpecialObjectState> m_vectorSpecialSaveObjectState`
- `EffectManagerState m_effectManagerState`
- `cocos2d::CCArray* m_gradientTriggerObjectArray`
- `bool m_unk11e8`
- `gd::unordered_map<int,SequenceTriggerState> m_sequenceTriggerStateUnorderedMap`
- `int m_commandIndex`

### `CollisionBlockPopup` : FLAlertLayer, TextInputDelegate

**Functions:**

- `static CollisionBlockPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `void determineStartValues()`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDynamicBlock(cocos2d::CCObject* sender)`
- `void onItemIDArrow(cocos2d::CCObject* sender)`
- `void onNextItemID(cocos2d::CCObject* sender)`
- `void updateEditorLabel()`
- `void updateItemID()`
- `void updateTextInputLabel()`

**Members:**

- `EffectGameObject* m_gameObject`
- `cocos2d::CCArray* m_gameObjects`
- `CCTextInputNode* m_blockIDInput`
- `int m_blockID`
- `bool m_dynamicBlock`
- `bool m_disableDelegate`

### `CollisionTriggerAction`

**Members:**

- `bool m_disabled`
- `int m_blockAID`
- `int m_blockBID`
- `int m_targetGroupID`
- `int m_triggerOnExit`
- `bool m_activateGroup`
- `int m_triggerUniqueID`
- `int m_controlID`
- `gd::vector<int> m_remapKeys`

### `ColorAction` : cocos2d::CCObject

**Functions:**

- `ColorAction()`
- `static ColorAction* create()`
- `static ColorAction* create(cocos2d::ccColor3B color, bool blending, int playerColor)`
- `static ColorAction* create(cocos2d::ccColor3B fromColor, cocos2d::ccColor3B toColor, float duration, double unused, bool blending)`
- `static ColorAction* create(cocos2d::ccColor3B fromColor, cocos2d::ccColor3B toColor, float duration, double unused, bool blending, int playerColor, float fromOpacity, float toOpacity)`
- `ColorAction* getCopy()`
- `bool init(cocos2d::ccColor3B fromColor, cocos2d::ccColor3B toColor, float duration, double unused, bool blending, int playerColor, float fromOpacity, float toOpacity)`
- `bool isInUse()`
- `void loadFromState(CAState& state)`
- `void resetAction()`
- `void saveToState(CAState& state)`
- `void setupFromMap(gd::map<gd::string, gd::string>& setup)`
- `void setupFromString(gd::string setup)`
- `void step(float dt)`
- `void updateCustomColor(cocos2d::ccColor3B color1, cocos2d::ccColor3B color2)`

**Members:**

- `bool m_stepFinished`
- `bool m_paused`
- `cocos2d::ccColor3B m_color`
- `float m_currentOpacity`
- `float m_deltaTime`
- `cocos2d::ccColor3B m_fromColor`
- `cocos2d::ccColor3B m_toColor`
- `float m_duration`
- `bool m_blending`
- `int m_playerColor`
- `int m_colorID`
- `float m_fromOpacity`
- `float m_toOpacity`
- `cocos2d::ccHSVValue m_copyHSV`
- `int m_copyID`
- `bool m_copyColorCalculated`
- `bool m_copyOpacity`
- `bool m_copyColorLoop`
- `int m_uniqueID`
- `int m_controlID`
- `bool m_legacyHSV`
- `ColorActionSprite* m_colorSprite`
- `InheritanceNode* m_inheritanceNode`
- `float m_actionDelay`
- `float m_stepInterval`

### `ColorAction2`

**Functions:**

- `ColorAction2(cocos2d::ccColor3B fromColor, cocos2d::ccColor3B toColor, float duration, double unused, bool blending, int playerColor, float fromOpacity, float toOpacity)`
- `void resetAction()`
- `void step(float dt)`
- `void updateCustomColor(cocos2d::ccColor3B color1, cocos2d::ccColor3B color2)`

**Members:**

- `bool m_stepFinished`
- `bool m_paused`
- `cocos2d::ccColor3B m_color`
- `float m_currentOpacity`
- `float m_deltaTime`
- `cocos2d::ccColor3B m_fromColor`
- `cocos2d::ccColor3B m_toColor`
- `float m_duration`
- `bool m_blending`
- `int m_playerColor`
- `int m_colorID`
- `float m_fromOpacity`
- `float m_toOpacity`
- `cocos2d::ccHSVValue m_copyHSV`
- `int m_copyID`
- `bool m_copyColorCalculated`
- `bool m_copyOpacity`
- `bool m_copyColorLoop`
- `int m_uniqueID`
- `bool m_legacyHSV`
- `ColorActionSprite* m_colorSprite`
- `float m_actionDelay`
- `float m_stepInterval`

### `ColorActionSprite` : cocos2d::CCNode

**Functions:**

- `ColorActionSprite()`
- `static ColorActionSprite* create()`
- `virtual bool init()`

**Members:**

- `float m_opacity`
- `cocos2d::ccColor3B m_color`
- `cocos2d::ccColor3B m_copyColor`
- `int m_colorID`
- `cocos2d::ccColor3B m_pulseColor`
- `ColorAction* m_colorAction`

### `ColorChannelSprite` : cocos2d::CCSprite

**Functions:**

- `static ColorChannelSprite* create()`
- `virtual bool init()`
- `void updateBlending(bool enabled)`
- `void updateCopyLabel(int channelID, bool copyColorLoop)`
- `void updateOpacity(float alpha)`
- `void updateValues(ColorAction* action)`

**Members:**

- `cocos2d::CCLabelBMFont* m_copyLabel`
- `cocos2d::CCLabelBMFont* m_opacityLabel`
- `cocos2d::CCLabelBMFont* m_blendingLabel`

### `ColorSelectDelegate`

**Functions:**

- `virtual void colorSelectClosed(cocos2d::CCNode* popup)`

### `ColorSelectLiveOverlay` : FLAlertLayer

**Functions:**

- `static ColorSelectLiveOverlay* create(ColorAction* baseAction, ColorAction* detailAction, EffectGameObject* object)`
- `static ColorSelectLiveOverlay* createWithActions(ColorAction* baseAction, ColorAction* detailAction)`
- `static ColorSelectLiveOverlay* createWithObject(EffectGameObject* object)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `void closeColorSelect(cocos2d::CCObject* sender)`
- `void colorValueChanged(cocos2d::ccColor3B color)`
- `CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `void determineStartValues()`
- `cocos2d::ccColor3B getColorValue()`
- `bool init(ColorAction* baseAction, ColorAction* detailAction, EffectGameObject* object)`
- `void onSelectTab(cocos2d::CCObject* sender)`
- `void selectColor(cocos2d::ccColor3B color)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void textChanged(CCTextInputNode* node)`
- `void textInputClosed(CCTextInputNode* node)`
- `void toggleControls(bool visible)`
- `void updateColorLabel()`
- `void updateColorValue()`
- `void updateOpacity()`

**Members:**

- `EffectGameObject* m_effectGameObject`
- `cocos2d::CCArray* m_barSprites`
- `cocos2d::CCArray* m_12buttons`
- `ColorAction* m_baseColorAction`
- `ColorAction* m_detailColorAction`
- `cocos2d::ccColor3B m_mainColor`
- `cocos2d::ccColor3B m_detailColor`
- `cocos2d::ccColor3B m_targetColor`
- `float m_unk2ac`
- `int m_unk2b0`
- `int m_unk2b4`
- `float m_opacity`
- `ColorSelectDelegate* m_delegate`
- `bool m_disableTextDelegate`
- `bool m_unk2c9`
- `bool m_updateColor`
- `Slider* m_hueSlider`
- `Slider* m_saturationSlider`
- `Slider* m_valueSlider`
- `Slider* m_opacitySlider`
- `cocos2d::CCSprite* m_colorSprite`
- `cocos2d::CCSprite* m_oldColorSprite`
- `cocos2d::CCSprite* m_saturationSprite`
- `cocos2d::CCSprite* m_valueSprite`
- `cocos2d::CCSprite* m_opacitySprite`
- `double m_hue`
- `double m_saturation`
- `double m_value`
- `cocos2d::CCLabelBMFont* m_colorLabel`
- `bool m_detailColorSelected`
- `bool m_closeButtonPressed`

### `ColorSelectPopup` : SetupTriggerPopup, cocos2d::extension::ColorPickerDelegate, GJSpecialColorSelectDelegate

**Functions:**

- `ColorSelectPopup()`
- `~ColorSelectPopup()`
- `static gd::string colorToHex(cocos2d::ccColor3B color)`
- `static ColorSelectPopup* create(ColorAction* action)`
- `static ColorSelectPopup* create(cocos2d::ccColor3B color)`
- `static ColorSelectPopup* create(EffectGameObject* effect, cocos2d::CCArray* array)`
- `static ColorSelectPopup* create(EffectGameObject* effect, cocos2d::CCArray* array, ColorAction* action)`
- `static cocos2d::ccColor3B hexToColor(gd::string hex)`
- `virtual void show()`
- `virtual void determineStartValues()`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void colorValueChanged(cocos2d::ccColor3B color)`
- `virtual void colorSelectClosed(GJSpecialColorSelect* select, int id)`
- `virtual void keyBackClicked()`
- `void closeColorSelect(cocos2d::CCObject* sender)`
- `cocos2d::ccColor3B getColorValue()`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects, ColorAction* action)`
- `void onCopy(cocos2d::CCObject* sender)`
- `void onCopyOpacity(cocos2d::CCObject* sender)`
- `void onDefault(cocos2d::CCObject* sender)`
- `void onHSVLegacyMode(cocos2d::CCObject* sender)`
- `void onPaste(cocos2d::CCObject* sender)`
- `void onPlayerColor1(cocos2d::CCObject* sender)`
- `void onPlayerColor2(cocos2d::CCObject* sender)`
- `void onSelectSpecialColor(cocos2d::CCObject* sender)`
- `void onTintGround(cocos2d::CCObject* sender)`
- `void onToggleHSVMode(cocos2d::CCObject* sender)`
- `void onToggleTintMode(cocos2d::CCObject* sender)`
- `void onUpdateCopyColor(cocos2d::CCObject* sender)`
- `void onUpdateCustomColor(cocos2d::CCObject* sender)`
- `void selectColor(cocos2d::ccColor3B color)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateColorLabels()`
- `void updateColorValue()`
- `void updateCopyColor()`
- `void updateCopyColorTextInputLabel()`
- `void updateCustomColorIdx()`
- `void updateDuration()`
- `void updateDurLabel()`
- `void updateHSVMode()`
- `void updateHSVValue()`
- `void updateOpacity()`
- `void updateOpacityLabel()`
- `void updateTextInputLabel()`

**Members:**

- `cocos2d::extension::CCControlColourPicker* m_colorPicker`
- `bool m_unk3c0`
- `cocos2d::CCLabelBMFont* m_opacityLabel`
- `Slider* m_fadeTimeSlider`
- `Slider* m_opacitySlider`
- `CCMenuItemToggler* m_playerColor1Toggle`
- `CCMenuItemToggler* m_playerColor2Toggle`
- `cocos2d::ccColor3B m_originalColor`
- `cocos2d::CCSprite* m_currentColorSprite`
- `cocos2d::CCSprite* m_originalColorSprite`
- `cocos2d::ccColor3B m_currentColor`
- `ColorSelectDelegate* m_delegate`
- `float m_fadeTime`
- `int m_playerColor`
- `int m_blending`
- `float m_opacity`
- `ColorAction* m_colorAction`
- `CCTextInputNode* m_colorInput`
- `bool m_backgroundTrigger`
- `bool m_tintGround`
- `bool m_legacyHSV`
- `bool m_colorTrigger`
- `bool m_noChannel`
- `bool m_newColorTrigger`
- `int m_colorID`
- `bool m_initializing`
- `int m_copyColorID`
- `bool m_copyOpacity`
- `ConfigureHSVWidget* m_hsvWidget`
- `cocos2d::ccHSVValue m_hsv`
- `cocos2d::CCArray* m_colorObjects`
- `cocos2d::CCArray* m_copyObjects`
- `CCTextInputNode* m_copyColorInput`
- `CCTextInputNode* m_fadeTimeInput`
- `void* m_unk488`
- `void* m_unk490`
- `bool m_showCopyObjects`
- `CCTextInputNode* m_rInput`
- `CCTextInputNode* m_gInput`
- `CCTextInputNode* m_bInput`
- `CCTextInputNode* m_hexInput`

### `ColorSetupDelegate`

**Functions:**

- `virtual void colorSetupClosed(int id)`

### `CommentCell` : TableViewCell, LikeItemDelegate, FLAlertLayerProtocol

**Functions:**

- `CommentCell(char const* identifier, float width, float height)`
- `~CommentCell()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual void likedItem(LikeItemType type, int id, bool liked)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void incrementDislikes()`
- `void incrementLikes()`
- `void loadFromComment(GJComment* comment)`
- `void onConfirmDelete(cocos2d::CCObject* sender)`
- `void onDelete()`
- `void onGoToLevel(cocos2d::CCObject* sender)`
- `void onLike(cocos2d::CCObject* sender)`
- `void onUndelete()`
- `void onUnhide(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`
- `void updateLabelValues()`

**Members:**

- `cocos2d::CCSprite* m_iconSprite`
- `cocos2d::CCLabelBMFont* m_likeLabel`
- `GJComment* m_comment`
- `bool m_accountComment`
- `bool m_unk259`
- `bool m_compactMode`

### `CommentUploadDelegate`

**Functions:**

- `virtual void commentUploadFinished(int parentID)`
- `virtual void commentUploadFailed(int parentID, CommentError errorType)`
- `virtual void commentDeleteFailed(int id, int parentID)`

### `CommunityCreditNode` : cocos2d::CCNode

**Functions:**

- `static CommunityCreditNode* create(int unlockType, int iconID, int unknown, gd::string author)`
- `bool init(int unlockType, int iconID, int unknown, gd::string author)`

**Members:**

- `int m_unlockType`
- `int m_iconID`
- `int m_unknown`
- `gd::string m_author`

### `CommunityCreditsPage` : FLAlertLayer

**Functions:**

- `CommunityCreditsPage()`
- `~CommunityCreditsPage()`
- `static CommunityCreditsPage* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `void FLAlert_Clicked(FLAlertLayer* alert, bool btn2)`
- `void goToPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSwitchPage(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCDictionary* m_pageObjects`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `int m_page`

### `ConfigureHSVWidget` : cocos2d::CCNode, TextInputDelegate

**Functions:**

- `static ConfigureHSVWidget* create(cocos2d::ccHSVValue hsv, bool noBackground, bool addInputs)`
- `static cocos2d::ccHSVValue getHSV(GameObject* object, cocos2d::CCArray* objects, int mode)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void createTextInputNode(cocos2d::CCPoint position, int tag)`
- `bool init(cocos2d::ccHSVValue hsv, bool noBackground, bool addInputs)`
- `void onClose()`
- `void onResetHSV(cocos2d::CCObject* sender)`
- `void onToggleSConst(cocos2d::CCObject* sender)`
- `void onToggleVConst(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateLabels()`
- `void updateSliders()`

**Members:**

- `cocos2d::CCLabelBMFont* m_hueLabel`
- `cocos2d::CCLabelBMFont* m_saturationLabel`
- `cocos2d::CCLabelBMFont* m_brightnessLabel`
- `Slider* m_hueSlider`
- `Slider* m_saturationSlider`
- `Slider* m_brightnessSlider`
- `cocos2d::ccHSVValue m_hsv`
- `bool m_mixed`
- `HSVWidgetDelegate* m_delegate`
- `bool m_addInputs`
- `bool m_updating`
- `cocos2d::CCDictionary* m_inputs`

### `ConfigureValuePopup` : FLAlertLayer, TextInputDelegate

**Functions:**

- `static ConfigureValuePopup* create(ConfigureValuePopupDelegate* delegate, float value, float minimum, float maximum, gd::string title, gd::string description, int type)`
- `virtual void keyBackClicked()`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void addInfoAlertButton(gd::string title, gd::string description)`
- `bool init(ConfigureValuePopupDelegate* delegate, float value, float minimum, float maximum, gd::string title, gd::string description, int type)`
- `void onArrow(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateTextInputLabel()`

**Members:**

- `int m_type`
- `float m_value`
- `float m_minimum`
- `float m_maximum`
- `bool m_enableDelegate`
- `bool m_disableTextDelegate`
- `ConfigureValuePopupDelegate* m_delegate`
- `CCTextInputNode* m_input`
- `Slider* m_slider`

### `ConfigureValuePopupDelegate`

**Functions:**

- `virtual void valuePopupClosed(ConfigureValuePopup* popup, float value)`

### `CountTriggerAction`

**Functions:**

- `CountTriggerAction()`
- `CountTriggerAction(int targetID, int targetCount, bool activateGroup, bool multiActivate, int itemID, int previousCount, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`

**Members:**

- `bool m_disabled`
- `int m_previousCount`
- `int m_targetCount`
- `int m_targetGroupID`
- `bool m_activateGroup`
- `int m_triggerUniqueID`
- `int m_controlID`
- `int m_itemID`
- `bool m_multiActivate`
- `gd::vector<int> m_remapKeys`

### `CountTriggerGameObject` : EffectGameObject

**Functions:**

- `CountTriggerGameObject()`
- `static CountTriggerGameObject* create(char const* frame)`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `int m_pickupCount`
- `int m_pickupTriggerMode`
- `bool m_multiActivate`
- `bool m_isOverride`
- `float m_pickupTriggerMultiplier`

### `CreateGuidelinesLayer` : FLAlertLayer, FLAlertLayerProtocol

**Functions:**

- `CreateGuidelinesLayer()`
- `~CreateGuidelinesLayer()`
- `static CreateGuidelinesLayer* create(CustomSongDelegate* delegate, AudioGuidelinesType type)`
- `virtual void update(float dt)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void keyUp(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void playMusic()`
- `virtual void registerTouch()`
- `virtual void onInfo(cocos2d::CCObject* sender)`
- `virtual void onRecord(cocos2d::CCObject* sender)`
- `virtual void recordingDidStop()`
- `void doClearGuidelines()`
- `gd::string getMergedRecordString(gd::string str1, gd::string str2)`
- `bool init(CustomSongDelegate* delegate, AudioGuidelinesType type)`
- `void onClearGuidelines(cocos2d::CCObject* sender)`
- `void onStop(cocos2d::CCObject* sender)`
- `void toggleItems(bool visible)`

**Members:**

- `CustomSongDelegate* m_delegate`
- `CCTextInputNode* m_offsetInput`
- `cocos2d::CCArray* m_nonRecordingObjects`
- `cocos2d::CCArray* m_recordingObjects`
- `cocos2d::CCLabelBMFont* m_infoLabel`
- `cocos2d::CCSprite* m_circleSprite`
- `float m_elapsed`
- `bool m_recording`
- `bool m_unk2b5`
- `int m_guidelines`
- `gd::string m_guidelineString`

### `CreateMenuItem` : CCMenuItemSpriteExtra

**Functions:**

- `static CreateMenuItem* create(cocos2d::CCNode* normal, cocos2d::CCNode* selected, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector)`
- `bool init(cocos2d::CCNode* normal, cocos2d::CCNode* selected, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector)`

**Members:**

- `gd::string m_spriteFileName`
- `int m_objectID`
- `int m_pageIndex`
- `int m_tabIndex`

### `CreateParticlePopup` : FLAlertLayer, TextInputDelegate, ColorSelectDelegate, SliderDelegate

**Functions:**

- `static CreateParticlePopup* create(gd::string str)`
- `static CreateParticlePopup* create(ParticleGameObject* object, cocos2d::CCArray* objects)`
- `static CreateParticlePopup* create(ParticleGameObject* object, cocos2d::CCArray* objects, gd::string str)`
- `virtual void update(float dt)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void keyBackClicked()`
- `virtual void sliderBegan(Slider* slider)`
- `virtual void sliderEnded(Slider* slider)`
- `virtual void colorSelectClosed(cocos2d::CCNode* popup)`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void centerAlignParticle(cocos2d::CCObject* sender)`
- `void createParticleSlider(gjParticleValue value, int page, bool centerLabel, cocos2d::CCPoint position, cocos2d::CCArray* displayNodes)`
- `cocos2d::CCNode* getPage(int page)`
- `CCMenuItemSpriteExtra* getPageButton(int page)`
- `cocos2d::CCArray* getPageContainer(int page)`
- `cocos2d::CCDictionary* getPageInputNodes(int page)`
- `cocos2d::CCMenu* getPageMenu(int page)`
- `cocos2d::CCDictionary* getPageSliders(int page)`
- `bool init(ParticleGameObject* object, cocos2d::CCArray* objects, gd::string str)`
- `float maxSliderValueForType(gjParticleValue type)`
- `float minSliderValueForType(gjParticleValue type)`
- `void onAnimateActiveOnly(cocos2d::CCObject* sender)`
- `void onAnimateOnTrigger(cocos2d::CCObject* sender)`
- `void onCalcEmission(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCopySettings(cocos2d::CCObject* sender)`
- `void onDuplicateColor(cocos2d::CCObject* sender)`
- `void onDurationForever(cocos2d::CCObject* sender)`
- `void onDynamicColor(cocos2d::CCObject* sender)`
- `void onDynamicRotation(cocos2d::CCObject* sender)`
- `void onEmitterMode(cocos2d::CCObject* sender)`
- `void onEndRGBVarSync(cocos2d::CCObject* sender)`
- `void onMaxEmission(cocos2d::CCObject* sender)`
- `void onMode(cocos2d::CCObject* sender)`
- `void onOrderSensitive(cocos2d::CCObject* sender)`
- `void onPage(cocos2d::CCObject* sender)`
- `void onPasteSettings(cocos2d::CCObject* sender)`
- `void onPosType(cocos2d::CCObject* sender)`
- `void onQuickStart(cocos2d::CCObject* sender)`
- `void onSelectColor(cocos2d::CCObject* sender)`
- `void onSelectParticleTexture(cocos2d::CCObject* sender)`
- `void onStartRGBVarSync(cocos2d::CCObject* sender)`
- `void onToggleBlending(cocos2d::CCObject* sender)`
- `void onTogglePerfLog(cocos2d::CCObject* sender)`
- `void onToggleStartRadiusEqualToEnd(cocos2d::CCObject* sender)`
- `void onToggleStartRotationIsDir(cocos2d::CCObject* sender)`
- `void onToggleStartSizeEqualToEnd(cocos2d::CCObject* sender)`
- `void onToggleStartSpinEqualToEnd(cocos2d::CCObject* sender)`
- `void onUniformColor(cocos2d::CCObject* sender)`
- `bool particleValueIsInt(gjParticleValue type)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `gd::string titleForParticleValue(gjParticleValue type)`
- `void toggleGravityMode(bool gravityMode)`
- `void updateColorSprite(int tag)`
- `void updateInputNodeStringForType(gjParticleValue type)`
- `void updateParticleValueForType(float value, gjParticleValue type, cocos2d::CCParticleSystemQuad* particle)`
- `void updateSliderForType(gjParticleValue type)`
- `float valueForParticleValue(gjParticleValue type)`
- `void willClose()`

**Members:**

- `ParticleGameObject* m_targetObject`
- `cocos2d::CCArray* m_targetObjects`
- `cocos2d::CCArray* m_particles`
- `bool m_disableTextDelegate`
- `cocos2d::CCParticleSystemQuad* m_particle`
- `cocos2d::CCParticleSystemQuad* m_standaloneParticle`
- `int m_touchID`
- `cocos2d::CCPoint m_touchDelta`
- `cocos2d::CCArray* m_inputDicts`
- `cocos2d::CCArray* m_sliderDicts`
- `cocos2d::CCArray* m_pageNodes`
- `cocos2d::CCArray* m_pageButtons`
- `cocos2d::CCArray* m_pageMenus`
- `cocos2d::CCArray* m_pageObjectArrays`
- `ParticlePreviewLayer* m_previewLayer`
- `CCMenuItemSpriteExtra* m_mode1Button`
- `CCMenuItemSpriteExtra* m_mode2Button`
- `CCMenuItemSpriteExtra* m_mode3Button`
- `float m_elapsed`
- `int m_selectedMode`
- `CCMenuItemToggler* m_freeToggler`
- `CCMenuItemToggler* m_relativeToggler`
- `CCMenuItemToggler* m_groupedToggler`
- `CCMenuItemToggler* m_objColorToggler`
- `CCMenuItemToggler* m_uniformColorToggler`
- `CCMenuItemToggler* m_gravityToggler`
- `CCMenuItemToggler* m_radiusToggler`
- `cocos2d::CCSprite* m_selectSprite`
- `cocos2d::CCSprite* m_particleColorSprite`
- `cocos2d::CCSprite* m_startColorSprite`
- `cocos2d::CCSprite* m_endColorSprite`
- `cocos2d::CCArray* m_gravityObjects`
- `cocos2d::CCArray* m_radiusObjects`
- `bool m_perfLogEnabled`
- `float m_perfLogElapsed`
- `cocos2d::CCLabelBMFont* m_perfLogLabel`
- `int m_particleIndex`
- `int m_page`
- `bool m_useObjectColor`
- `bool m_animateOnTrigger`
- `bool m_onlyAnimateActive`
- `bool m_quickStart`
- `float m_respawnResult`

### `CreatorLayer` : cocos2d::CCLayer, cocos2d::CCSceneTransitionDelegate, DialogDelegate

**Functions:**

- `CreatorLayer()`
- `static CreatorLayer* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void sceneWillResume()`
- `virtual void dialogClosed(DialogLayer* layer)`
- `bool canPlayOnlineLevels()`
- `void checkQuestsStatus()`
- `void onAdventureMap(cocos2d::CCObject* sender)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onChallenge(cocos2d::CCObject* sender)`
- `void onDailyLevel(cocos2d::CCObject* sender)`
- `void onEventLevel(cocos2d::CCObject* sender)`
- `void onFameLevels(cocos2d::CCObject* sender)`
- `void onFeaturedLevels(cocos2d::CCObject* sender)`
- `void onGauntlets(cocos2d::CCObject* sender)`
- `void onLeaderboards(cocos2d::CCObject* sender)`
- `void onMapPacks(cocos2d::CCObject* sender)`
- `void onMultiplayer(cocos2d::CCObject* sender)`
- `void onMyLevels(cocos2d::CCObject* sender)`
- `void onOnlineLevels(cocos2d::CCObject* sender)`
- `void onOnlyFullVersion(cocos2d::CCObject* sender)`
- `void onPaths(cocos2d::CCObject* sender)`
- `void onSavedLevels(cocos2d::CCObject* sender)`
- `void onSecretVault(cocos2d::CCObject* sender)`
- `void onTopLists(cocos2d::CCObject* sender)`
- `void onTreasureRoom(cocos2d::CCObject* sender)`
- `void onWeeklyLevel(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCSprite* m_secretDoorSprite`
- `cocos2d::CCSprite* m_questsSprite`
- `int m_vaultDialogIndex`
- `int m_versusDialogIndex`

### `CurrencyRewardDelegate`

**Functions:**

- `virtual void currencyWillExit(CurrencyRewardLayer* layer)`

### `CurrencyRewardLayer` : cocos2d::CCLayer

**Functions:**

- `static CurrencyRewardLayer* create(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time)`
- `virtual void update(float dt)`
- `void createObjects(CurrencySpriteType type, int count, cocos2d::CCPoint position, float time)`
- `void createObjectsFull(CurrencySpriteType type, int count, cocos2d::CCSprite* sprite, cocos2d::CCPoint position, float time)`
- `void createUnlockObject(cocos2d::CCSprite* sprite, cocos2d::CCPoint position, float time)`
- `void incrementCount(int count)`
- `void incrementDiamondsCount(int count)`
- `void incrementMoonsCount(int count)`
- `void incrementSpecialCount1(int count)`
- `void incrementSpecialCount2(int count)`
- `void incrementStarsCount(int count)`
- `bool init(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time)`
- `void pulseSprite(cocos2d::CCSprite* sprite)`

**Members:**

- `CurrencyRewardDelegate* m_delegate`
- `cocos2d::CCArray* m_objects`
- `cocos2d::CCLabelBMFont* m_orbsLabel`
- `cocos2d::CCLabelBMFont* m_starsLabel`
- `cocos2d::CCLabelBMFont* m_moonsLabel`
- `cocos2d::CCLabelBMFont* m_diamondsLabel`
- `cocos2d::CCLabelBMFont* m_keysLabel`
- `cocos2d::CCLabelBMFont* m_shardsLabel`
- `cocos2d::CCSprite* m_orbsSprite`
- `cocos2d::CCSprite* m_starsSprite`
- `cocos2d::CCSprite* m_moonsSprite`
- `cocos2d::CCSprite* m_diamondsSprite`
- `CurrencySprite* m_keysSprite`
- `CurrencySprite* m_shardsSprite`
- `cocos2d::CCSpriteBatchNode* m_currencyBatchNode`
- `cocos2d::CCSpriteBatchNode* m_orbBatchNode`
- `int m_orbs`
- `int m_stars`
- `int m_moons`
- `int m_diamonds`
- `int m_keys`
- `int m_shards`
- `float m_elapsed`
- `float m_unknown`
- `float m_time`
- `cocos2d::CCPoint m_orbsPosition`
- `cocos2d::CCPoint m_starsPosition`
- `cocos2d::CCPoint m_moonsPosition`
- `cocos2d::CCPoint m_diamondsPosition`
- `cocos2d::CCPoint m_keysPosition`
- `cocos2d::CCPoint m_shardsPosition`
- `bool m_particlesAdded`
- `bool m_objectsAdded`
- `cocos2d::CCNode* m_mainNode`
- `int m_rewardCount`
- `CurrencyRewardType m_rewardType`

### `CurrencySprite` : CCSpritePlus

**Functions:**

- `CurrencySprite()`
- `~CurrencySprite()`
- `static CurrencySprite* create(CurrencySpriteType type, bool burst)`
- `static CurrencySprite* createWithSprite(cocos2d::CCSprite* sprite)`
- `static CurrencySpriteType rewardToSpriteType(int rewardType)`
- `static gd::string spriteTypeToStat(CurrencySpriteType type)`
- `bool init(CurrencySpriteType type, bool burst)`
- `bool initWithSprite(cocos2d::CCSprite* sprite)`

**Members:**

- `float m_unkFloat1`
- `float m_unkFloat2`
- `float m_unkFloat3`
- `float m_remaining`
- `int m_count`
- `cocos2d::CCParticleSystemQuad* m_particleSystem`
- `CurrencySpriteType m_spriteType`
- `cocos2d::CCPoint m_position`
- `cocos2d::CCSprite* m_burstSprite`

### `CustomListView` : BoomListView

**Functions:**

- `CustomListView()`
- `static CustomListView* create(cocos2d::CCArray* entries, BoomListType type, float height, float width)`
- `static CustomListView* create(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y)`
- `static float getCellHeight(BoomListType type)`
- `virtual void setupList(float yOffset)`
- `virtual TableViewCell* getListCell(char const* identifier)`
- `virtual void loadCell(TableViewCell* cell, int index)`
- `void reloadAll()`

**Members:**

- `int m_cellMode`

### `CustomMusicCell` : CustomSongCell

**Functions:**

- `CustomMusicCell(char const* identifier, float width, float height)`
- `void loadFromObject(SongInfoObject* object)`
- `void updateBGColor(int index)`

### `CustomSFXCell` : TableViewCell, CustomSFXDelegate

**Functions:**

- `CustomSFXCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `virtual void sfxObjectSelected(SFXInfoObject* object)`
- `virtual int getActiveSFXID()`
- `void loadFromObject(SFXInfoObject* object)`
- `bool shouldReload()`
- `void updateBGColor(int index)`

**Members:**

- `SFXInfoObject* m_sfxObject`
- `bool m_selected`
- `bool m_compactMode`

### `CustomSFXDelegate`

**Functions:**

- `virtual void sfxObjectSelected(SFXInfoObject* object)`
- `virtual int getActiveSFXID()`
- `virtual bool overridePlaySFX(SFXInfoObject* object)`

### `CustomSFXWidget` : cocos2d::CCNode, MusicDownloadDelegate, FLAlertLayerProtocol

**Functions:**

- `static CustomSFXWidget* create(SFXInfoObject* object, CustomSFXDelegate* delegate, bool showDelete, bool showPlay, bool showDownload, bool noBackground, bool compactMode)`
- `virtual void downloadSFXFinished(int id)`
- `virtual void downloadSFXFailed(int id, GJSongError errorType)`
- `virtual void songStateChanged()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void deleteSFX()`
- `void downloadFailed()`
- `void hideLoadingArt()`
- `bool init(SFXInfoObject* object, CustomSFXDelegate* delegate, bool showDelete, bool showPlay, bool showDownload, bool noBackground, bool compactMode)`
- `void onCancelDownload(cocos2d::CCObject* sender)`
- `void onDelete(cocos2d::CCObject* sender)`
- `void onDownload(cocos2d::CCObject* sender)`
- `void onPlayback(cocos2d::CCObject* sender)`
- `void onSelect(cocos2d::CCObject* sender)`
- `void showLoadingArt()`
- `void startDownload()`
- `void startMonitorDownload()`
- `void updateDownloadProgress(float dt)`
- `void updateError(GJSongError errorType)`
- `void updateLengthMod(float mod)`
- `void updatePlaybackBtn()`
- `void updateProgressBar(int progress)`
- `void updateSFXInfo()`
- `void updateSFXObject(SFXInfoObject* object)`
- `bool verifySFXID(int id)`

**Members:**

- `SFXInfoObject* m_sfxObject`
- `cocos2d::CCMenu* m_buttonMenu`
- `cocos2d::CCLabelBMFont* m_titleLabel`
- `cocos2d::CCLabelBMFont* m_idLabel`
- `cocos2d::CCLabelBMFont* m_errorLabel`
- `CCMenuItemSpriteExtra* m_downloadButton`
- `CCMenuItemSpriteExtra* m_cancelButton`
- `CCMenuItemSpriteExtra* m_selectButton`
- `CCMenuItemSpriteExtra* m_playButton`
- `CCMenuItemSpriteExtra* m_deleteButton`
- `cocos2d::CCSprite* m_progressOutlineSprite`
- `cocos2d::CCSprite* m_progressBarSprite`
- `cocos2d::CCSprite* m_clockSprite`
- `CustomSFXDelegate* m_delegate`
- `bool m_showDelete`
- `bool m_showPlay`
- `bool m_showDownload`
- `bool m_showCancel`
- `bool m_compactMode`
- `int m_sfxID`
- `float m_lengthMod`

### `CustomSongCell` : TableViewCell, CustomSongDelegate

**Functions:**

- `CustomSongCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `virtual void songIDChanged(int id)`
- `virtual int getActiveSongID()`
- `virtual gd::string getSongFileName()`
- `virtual LevelSettingsObject* getLevelSettings()`
- `void loadFromObject(SongInfoObject* object)`
- `void onDelete(cocos2d::CCObject* sender)`
- `bool shouldReload()`
- `void updateBGColor(int index)`

**Members:**

- `SongInfoObject* m_songInfoObject`
- `bool m_selected`

### `CustomSongDelegate`

**Functions:**

- `virtual void songIDChanged(int id)`
- `virtual int getActiveSongID()`
- `virtual gd::string getSongFileName()`
- `virtual LevelSettingsObject* getLevelSettings()`

### `CustomSongLayer` : FLAlertLayer, TextInputDelegate, GJDropDownLayerDelegate, MusicBrowserDelegate

**Functions:**

- `CustomSongLayer()`
- `static CustomSongLayer* create(CustomSongDelegate* delegate)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `virtual void dropDownLayerWillClose(GJDropDownLayer* layer)`
- `virtual void musicBrowserClosed(MusicBrowser* browser)`
- `bool init(CustomSongDelegate* delegate)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCreateLines(cocos2d::CCObject* sender)`
- `void onMusicBrowser(cocos2d::CCObject* sender)`
- `void onNCSBrowser(cocos2d::CCObject* sender)`
- `void onNewgroundsBrowser(cocos2d::CCObject* sender)`
- `void onOptions(cocos2d::CCObject* sender)`
- `void onSearch(cocos2d::CCObject* sender)`
- `void onSongBrowser(cocos2d::CCObject* sender)`
- `void showNewgroundsMessage()`

**Members:**

- `CustomSongDelegate* m_songDelegate`
- `CCTextInputNode* m_songIDInput`
- `CustomSongWidget* m_songWidget`
- `CustomSongLayerDelegate* m_delegate`

### `CustomSongLayerDelegate`

**Functions:**

- `virtual void customSongLayerClosed()`

### `CustomSongWidget` : cocos2d::CCNode, MusicDownloadDelegate, FLAlertLayerProtocol

**Functions:**

- `CustomSongWidget()`
- `~CustomSongWidget()`
- `static CustomSongWidget* create(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk)`
- `virtual void loadSongInfoFinished(SongInfoObject* object)`
- `virtual void loadSongInfoFailed(int id, GJSongError errorType)`
- `virtual void downloadSongStarted(int id)`
- `virtual void downloadSongFinished(int id)`
- `virtual void downloadSongFailed(int id, GJSongError errorType)`
- `virtual void downloadSFXFinished(int id)`
- `virtual void downloadSFXFailed(int id, GJSongError errorType)`
- `virtual void musicActionFinished(GJMusicAction action)`
- `virtual void musicActionFailed(GJMusicAction action)`
- `virtual void songStateChanged()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void addExtraVisuals(bool newMusic, bool newLibraryMusic)`
- `void deleteSong()`
- `void downloadAssetFailed(int id, GJAssetType type, GJSongError errorType)`
- `void downloadAssetFinished(int id, GJAssetType type)`
- `void downloadFailed()`
- `void getSongInfoIfUnloaded()`
- `bool init(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk)`
- `void onCancelDownload(cocos2d::CCObject* sender)`
- `void onDelete(cocos2d::CCObject* sender)`
- `void onDownload(cocos2d::CCObject* sender)`
- `void onGetSongInfo(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onMore(cocos2d::CCObject* sender)`
- `void onPlayback(cocos2d::CCObject* sender)`
- `void onSelect(cocos2d::CCObject* sender)`
- `void positionInfoObjects()`
- `void processNextMultiAsset()`
- `void showError(bool fast)`
- `void startDownload()`
- `void startMonitorDownload()`
- `void startMultiAssetDownload()`
- `void toggleUpdateButton(bool enabled)`
- `void updateDownloadProgress(float dt)`
- `void updateError(GJSongError errorType)`
- `void updateLengthMod(float lengthMod)`
- `void updateMultiAssetInfo(bool update)`
- `void updatePlaybackBtn()`
- `void updateProgressBar(int progress)`
- `void updateSongInfo()`
- `void updateSongObject(SongInfoObject* songInfo)`
- `void updateWithMultiAssets(gd::string songList, gd::string sfxList, int bytes)`
- `bool verifySongID(int id)`

**Members:**

- `SongInfoObject* m_songInfoObject`
- `cocos2d::CCMenu* m_buttonMenu`
- `cocos2d::CCLabelBMFont* m_songLabel`
- `cocos2d::CCLabelBMFont* m_artistLabel`
- `cocos2d::CCLabelBMFont* m_songIDLabel`
- `cocos2d::CCLabelBMFont* m_errorLabel`
- `CCMenuItemSpriteExtra* m_downloadBtn`
- `CCMenuItemSpriteExtra* m_cancelDownloadBtn`
- `CCMenuItemSpriteExtra* m_selectSongBtn`
- `CCMenuItemSpriteExtra* m_getSongInfoBtn`
- `CCMenuItemSpriteExtra* m_playbackBtn`
- `CCMenuItemSpriteExtra* m_moreBtn`
- `CCMenuItemSpriteExtra* m_deleteBtn`
- `CCMenuItemSpriteExtra* m_infoBtn`
- `cocos2d::CCSprite* m_sliderGroove`
- `cocos2d::CCSprite* m_sliderBar`
- `cocos2d::CCSprite* m_ncsLogo`
- `cocos2d::extension::CCScale9Sprite* m_bgSpr`
- `CustomSongDelegate* m_songDelegate`
- `bool m_showSelectSongBtn`
- `bool m_showPlayMusicBtn`
- `bool m_showDownloadBtn`
- `bool m_isNotDownloading`
- `bool m_isRobtopSong`
- `bool m_isMusicLibrary`
- `int m_customSongID`
- `float m_lengthMod`
- `bool m_isInCell`
- `SongPlaybackDelegate* m_playbackDelegate`
- `bool m_hasLibrarySongs`
- `bool m_hasSFX`
- `bool m_unkBool2`
- `gd::map<int, bool> m_songs`
- `gd::map<int, bool> m_sfx`
- `gd::vector<GJAssetDownloadAction> m_undownloadedAssets`
- `int m_totalBytes`
- `gd::set<int> m_nextSongIDs`

### `CustomizeObjectLayer` : FLAlertLayer, TextInputDelegate, HSVWidgetDelegate, ColorSelectDelegate, ColorSetupDelegate

**Functions:**

- `static CustomizeObjectLayer* create(GameObject* object, cocos2d::CCArray* objects)`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void hsvPopupClosed(HSVWidgetPopup* popup, cocos2d::ccHSVValue value)`
- `virtual void colorSelectClosed(cocos2d::CCNode* popup)`
- `virtual void colorSetupClosed(int id)`
- `CCMenuItemToggler* createToggleButton(gd::string text, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `void determineStartValues()`
- `int getActiveMode(bool ignoreDefault)`
- `ButtonSprite* getButtonByTag(int tag)`
- `cocos2d::ccHSVValue getHSV()`
- `void highlightSelected(ButtonSprite* sprite)`
- `bool init(GameObject* object, cocos2d::CCArray* objects)`
- `void onBreakApart(cocos2d::CCObject* sender)`
- `void onBrowse(cocos2d::CCObject* sender)`
- `void onClear(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCopy(cocos2d::CCObject* sender)`
- `void onEditColor(cocos2d::CCObject* sender)`
- `void onHSV(cocos2d::CCObject* sender)`
- `void onLiveEdit(cocos2d::CCObject* sender)`
- `void onNextColorChannel(cocos2d::CCObject* sender)`
- `void onPaste(cocos2d::CCObject* sender)`
- `void onSelectColor(cocos2d::CCObject* sender)`
- `void onSelectMode(cocos2d::CCObject* sender)`
- `void onSettings(cocos2d::CCObject* sender)`
- `void onUpdateCustomColor(cocos2d::CCObject* sender)`
- `void recreateLayer()`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void toggleVisible()`
- `void updateChannelLabel(int channel)`
- `void updateColorSprite()`
- `void updateCurrentSelection()`
- `void updateCustomColorLabels()`
- `void updateHSVButtons()`
- `void updateKerningLabel()`
- `void updateSelected(int id)`

**Members:**

- `GameObject* m_targetObject`
- `cocos2d::CCArray* m_targetObjects`
- `cocos2d::CCArray* m_colorButtons`
- `cocos2d::CCArray* m_colorTabNodes`
- `cocos2d::CCArray* m_textTabNodes`
- `cocos2d::CCArray* m_unkArray`
- `cocos2d::CCArray* m_detailTabNodes`
- `int m_selectedMode`
- `int m_customColorChannel`
- `bool m_hasBaseColor`
- `bool m_hasDetailColor`
- `bool m_glowDisabled`
- `CCMenuItemSpriteExtra* m_baseButton`
- `CCMenuItemSpriteExtra* m_detailButton`
- `CCMenuItemSpriteExtra* m_textButton`
- `CCMenuItemSpriteExtra* m_baseColorHSV`
- `CCMenuItemSpriteExtra* m_detailColorHSV`
- `cocos2d::CCLabelBMFont* m_titleLabel`
- `cocos2d::CCLabelBMFont* m_selectedColorLabel`
- `CCTextInputNode* m_customColorInput`
- `CCTextInputNode* m_textInput`
- `int m_kerningAmount`
- `cocos2d::CCLabelBMFont* m_kerningLabel`
- `Slider* m_kerningSlider`
- `ButtonSprite* m_customColorButtonSprite`
- `CCMenuItemSpriteExtra* m_customColorButton`
- `CCMenuItemSpriteExtra* m_arrowDown`
- `CCMenuItemSpriteExtra* m_arrowUp`
- `cocos2d::extension::CCScale9Sprite* m_customColorInputBG`
- `ColorChannelSprite* m_colorSprite`
- `CCMenuItemSpriteExtra* m_colorSpriteButton`
- `CCMenuItemSpriteExtra* m_liveSelectButton`
- `bool m_showTextInput`
- `bool m_customColorSelected`
- `bool m_disableTextDelegate`

### `CustomizeObjectSettingsPopup` : SetupTriggerPopup

**Functions:**

- `CustomizeObjectSettingsPopup()`
- `static CustomizeObjectSettingsPopup* create(GameObject* object, cocos2d::CCArray* objects, CustomizeObjectLayer* layer)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(GameObject* object, cocos2d::CCArray* objects, CustomizeObjectLayer* layer)`

**Members:**

- `CustomizeObjectLayer* m_customizeLayer`
- `bool m_settingsChanged`

### `DailyLevelNode` : cocos2d::CCNode, FLAlertLayerProtocol

**Functions:**

- `DailyLevelNode()`
- `~DailyLevelNode()`
- `static DailyLevelNode* create(GJGameLevel* level, DailyLevelPage* page, bool isNew)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `bool init(GJGameLevel* level, DailyLevelPage* page, bool isNew)`
- `void onClaimReward(cocos2d::CCObject* sender)`
- `void onSkipLevel(cocos2d::CCObject* sender)`
- `void showSkipButton()`
- `void updateTimeLabel(gd::string text)`

**Members:**

- `GJGameLevel* m_level`
- `DailyLevelPage* m_page`
- `cocos2d::CCLabelBMFont* m_timeLabel`
- `cocos2d::CCPoint m_unkPoint`
- `CCMenuItemSpriteExtra* m_skipButton`
- `bool m_unkBool`
- `bool m_needsDownloading`

### `DailyLevelPage` : FLAlertLayer, FLAlertLayerProtocol, GJDailyLevelDelegate, LevelDownloadDelegate

**Functions:**

- `static DailyLevelPage* create(GJTimedLevelType type)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void dailyStatusFinished(GJTimedLevelType type)`
- `virtual void dailyStatusFailed(GJTimedLevelType type, GJErrorCode errorType)`
- `virtual void levelDownloadFinished(GJGameLevel* level)`
- `virtual void levelDownloadFailed(int response)`
- `void claimLevelReward(DailyLevelNode* node, GJGameLevel* level, cocos2d::CCPoint position)`
- `void createDailyNode(GJGameLevel* level, bool instant, float delay, bool isNew)`
- `void createNodeIfLoaded()`
- `void downloadAndCreateNode()`
- `void exitDailyNode(DailyLevelNode* node, float delay)`
- `int getDailyTime()`
- `gd::string getDailyTimeString(int timeLeft)`
- `bool init(GJTimedLevelType type)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onTheSafe(cocos2d::CCObject* sender)`
- `void refreshDailyPage()`
- `void skipDailyLevel(DailyLevelNode* node, GJGameLevel* level)`
- `void tryGetDailyStatus()`
- `callback void updateTimers(float dt)`

**Members:**

- `cocos2d::CCLabelBMFont* m_timeLabel`
- `LoadingCircle* m_timeCircle`
- `LoadingCircle* m_nodeCircle`
- `bool m_gettingDailyStatus`
- `DailyLevelNode* m_dailyNode`
- `bool m_downloadStarted`
- `GJTimedLevelType m_type`
- `int m_downloadLevelID`

### `DashRingObject` : RingObject

**Functions:**

- `DashRingObject()`
- `static DashRingObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `float m_dashSpeed`
- `float m_endBoost`
- `float m_maxDuration`
- `bool m_allowCollide`
- `bool m_stopSlide`

### `DelayedSpawnNode`

**Members:**

- `EffectGameObject* m_gameObject`
- `float m_spawnDelay`

### `DemonFilterDelegate`

**Functions:**

- `virtual void demonFilterSelectClosed(int filter)`

### `DemonFilterSelectLayer` : FLAlertLayer

**Functions:**

- `DemonFilterSelectLayer()`
- `~DemonFilterSelectLayer()`
- `static DemonFilterSelectLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void onClose(cocos2d::CCObject* sender)`
- `void selectRating(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCArray* m_demons`
- `void* m_unkPtr`
- `int m_currentDemon`
- `DemonFilterDelegate* m_delegate`

### `DemonInfoPopup` : FLAlertLayer

**Functions:**

- `static DemonInfoPopup* create(int easyClassic, int mediumClassic, int hardClassic, int insaneClassic, int extremeClassic, int easyPlatformer, int mediumPlatformer, int hardPlatformer, int insanePlatformer, int extremePlatformer, int weekly, int gauntlet)`
- `static DemonInfoPopup* createFromString(gd::string str)`
- `virtual void keyBackClicked()`
- `bool init(int easyClassic, int mediumClassic, int hardClassic, int insaneClassic, int extremeClassic, int easyPlatformer, int mediumPlatformer, int hardPlatformer, int insanePlatformer, int extremePlatformer, int weekly, int gauntlet)`
- `void onClose(cocos2d::CCObject* sender)`

### `DialogDelegate`

**Functions:**

- `virtual void dialogClosed(DialogLayer* layer)`

### `DialogLayer` : cocos2d::CCLayerColor, TextAreaDelegate

**Functions:**

- `DialogLayer()`
- `~DialogLayer()`
- `static DialogLayer* create(DialogObject* object, int background)`
- `static DialogLayer* createDialogLayer(DialogObject* object, cocos2d::CCArray* objects, int background)`
- `static DialogLayer* createWithObjects(cocos2d::CCArray* objects, int background)`
- `virtual void onEnter()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void fadeInTextFinished(TextArea* textArea)`
- `void addToMainScene()`
- `void animateIn(DialogAnimationType type)`
- `void animateInDialog()`
- `void animateInRandomSide()`
- `void displayDialogObject(DialogObject* object)`
- `void displayNextObject()`
- `void finishCurrentAnimation()`
- `void handleDialogTap()`
- `bool init(DialogObject* object, cocos2d::CCArray* objects, int background)`
- `void onClose()`
- `void updateChatPlacement(DialogChatPlacement placement)`
- `void updateNavButtonFrame()`

**Members:**

- `float m_animateTime`
- `cocos2d::CCLayer* m_mainLayer`
- `cocos2d::CCLabelBMFont* m_characterLabel`
- `TextArea* m_textArea`
- `cocos2d::CCSprite* m_characterSprite`
- `cocos2d::CCArray* m_dialogObjects`
- `int m_touchID`
- `cocos2d::CCSprite* m_navButtonSprite`
- `bool m_animating`
- `bool m_skippable`
- `DialogDelegate* m_delegate`
- `bool m_handleTap`
- `DialogAnimationType m_animationType`
- `bool m_noRemove`

### `DialogObject` : cocos2d::CCObject

**Functions:**

- `DialogObject()`
- `static DialogObject* create(gd::string character, gd::string text, int characterFrame, float textScale, bool skippable, cocos2d::ccColor3B color)`
- `bool init(gd::string character, gd::string text, int characterFrame, float textScale, bool skippable, cocos2d::ccColor3B color)`

**Members:**

- `gd::string m_text`
- `gd::string m_character`
- `int m_characterFrame`
- `cocos2d::ccColor3B m_color`
- `float m_textScale`
- `bool m_skippable`

### `DownloadMessageDelegate`

**Functions:**

- `virtual void downloadMessageFinished(GJUserMessage* message)`
- `virtual void downloadMessageFailed(int id)`

### `DrawGridLayer` : cocos2d::CCLayer

**Functions:**

- `static DrawGridLayer* create(cocos2d::CCNode* parent, LevelEditorLayer* layer)`
- `virtual void update(float dt)`
- `virtual void draw()`
- `void addAudioLineObject(AudioLineGuideGameObject* object)`
- `void addToEffects(EffectGameObject* object)`
- `void addToGuides(GameObject* object)`
- `void addToSpeedObjects(EffectGameObject* object)`
- `cocos2d::CCPoint getPortalMinMax(GameObject* object)`
- `bool init(cocos2d::CCNode* parent, LevelEditorLayer* layer)`
- `void loadTimeMarkers(gd::string markers)`
- `cocos2d::CCPoint posForTime(float time)`
- `void postUpdate()`
- `void removeAudioLineObject(AudioLineGuideGameObject* object)`
- `void removeFromEffects(EffectGameObject* object)`
- `void removeFromGuides(GameObject* object)`
- `void removeFromSpeedObjects(EffectGameObject* object)`
- `void sortSpeedObjects()`
- `float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, bool ignoreWarp, bool ignoreRotate, int id)`
- `void updateMusicGuideTime(float time)`
- `void updateTimeMarkers()`

**Members:**

- `std::array<cocos2d::CCPoint, 400>* m_pointArray1`
- `std::array<cocos2d::CCPoint, 400>* m_pointArray2`
- `std::array<cocos2d::CCPoint, 400>* m_pointArray3`
- `gd::unordered_map<int, AudioLineGuideGameObject*> m_audioLineObjects`
- `float m_musicTime`
- `float m_playbackTime`
- `float m_oldPlaybackTime`
- `float m_playbackX`
- `float m_playbackY`
- `bool m_sortEffects`
- `LevelEditorLayer* m_editorLayer`
- `gd::string m_timeMarkerString`
- `cocos2d::CCNode* m_objectLayer`
- `cocos2d::CCArray* m_timeMarkers`
- `cocos2d::CCArray* m_effectGameObjects`
- `cocos2d::CCArray* m_guideObjects`
- `cocos2d::CCArray* m_speedObjects`
- `double m_unk258`
- `float m_currentSpeed`
- `float m_slowSpeed`
- `float m_normalSpeed`
- `float m_fastSpeed`
- `float m_fasterSpeed`
- `float m_fastestSpeed`
- `bool m_updateTimeMarkers`
- `bool m_updateSpeedObjects`
- `float m_gridSize`

### `DungeonBarsSprite` : cocos2d::CCNode

**Functions:**

- `DungeonBarsSprite()`
- `static DungeonBarsSprite* create()`
- `virtual bool init()`
- `virtual void visit()`
- `void animateOutBars()`

**Members:**

- `cocos2d::CCSprite* m_barsSprite`

### `DynamicBitset`

**Functions:**

- `void resize(size_t size)`

**Members:**

- `gd::vector<unsigned int> m_bits`

### `DynamicScrollDelegate`

**Functions:**

- `virtual void updatePageWithObject(cocos2d::CCObject* layer, cocos2d::CCObject* object)`

### `EditButtonBar` : cocos2d::CCNode

**Functions:**

- `static EditButtonBar* create(cocos2d::CCArray* objects, cocos2d::CCPoint position, int tab, bool hasCreateItems, int columns, int rows)`
- `int getPage()`
- `void goToPage(int page)`
- `bool init(cocos2d::CCArray* objects, cocos2d::CCPoint position, int tab, bool hasCreateItems, int columns, int rows)`
- `void loadFromItems(cocos2d::CCArray* objects, int rows, int columns, bool keepPage)`
- `void onLeft(cocos2d::CCObject* sender)`
- `void onRight(cocos2d::CCObject* sender)`
- `void reloadItems(int rowCount, int columnCount)`

**Members:**

- `cocos2d::CCPoint m_position`
- `int m_tabIndex`
- `bool m_hasCreateItems`
- `cocos2d::CCArray* m_buttonArray`
- `BoomScrollLayer* m_scrollLayer`
- `cocos2d::CCArray* m_pagesArray`

### `EditGameObjectPopup` : SetupTriggerPopup

**Functions:**

- `EditGameObjectPopup()`
- `static EditGameObjectPopup* create(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer)`

### `EditLevelLayer` : cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol, UploadActionDelegate, UploadPopupDelegate, SetIDPopupDelegate

**Functions:**

- `EditLevelLayer()`
- `~EditLevelLayer()`
- `static EditLevelLayer* create(GJGameLevel* level)`
- `static cocos2d::CCScene* scene(GJGameLevel* level)`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void setIDPopupClosed(SetIDPopup* popup, int value)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `void closeTextInputs()`
- `void confirmClone(cocos2d::CCObject* sender)`
- `void confirmDelete(cocos2d::CCObject* sender)`
- `void confirmMoveToTop(cocos2d::CCObject* sender)`
- `bool init(GJGameLevel* level)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onClone()`
- `void onDelete()`
- `void onEdit(cocos2d::CCObject* sender)`
- `void onGuidelines(cocos2d::CCObject* sender)`
- `void onHelp(cocos2d::CCObject* sender)`
- `void onLevelInfo(cocos2d::CCObject* sender)`
- `void onLevelLeaderboard(cocos2d::CCObject* sender)`
- `void onLevelOptions(cocos2d::CCObject* sender)`
- `void onMoveToTop()`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onSetFolder(cocos2d::CCObject* sender)`
- `void onShare(cocos2d::CCObject* sender)`
- `void onTest(cocos2d::CCObject* sender)`
- `void onUpdateDescription(cocos2d::CCObject* sender)`
- `void playStep2()`
- `void playStep3()`
- `void setupLevelInfo()`
- `void updateDescText(char const* text)`
- `void verifyLevelName()`

**Members:**

- `cocos2d::CCMenu* m_buttonMenu`
- `GJGameLevel* m_level`
- `cocos2d::CCArray* m_textInputs`
- `cocos2d::CCLabelBMFont* m_folderLabel`
- `bool m_exiting`
- `GJLevelType m_levelType`
- `gd::string m_levelName`
- `UploadActionPopup* m_descriptionPopup`

### `EditTriggersPopup` : SetupTriggerPopup

**Functions:**

- `static EditTriggersPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `EditorOptionsLayer` : GJOptionsLayer

**Functions:**

- `EditorOptionsLayer()`
- `static EditorOptionsLayer* create()`
- `virtual bool init()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void setupOptions()`
- `void onButtonRows(cocos2d::CCObject* sender)`
- `void onButtonsPerRow(cocos2d::CCObject* sender)`

**Members:**

- `int m_buttonsPerRow`
- `int m_buttonRows`
- `cocos2d::CCLabelBMFont* m_buttonsPerRowLabel`
- `cocos2d::CCLabelBMFont* m_buttonRowsLabel`

### `EditorPauseLayer` : CCBlockLayer, FLAlertLayerProtocol

**Functions:**

- `EditorPauseLayer()`
- `static EditorPauseLayer* create(LevelEditorLayer* layer)`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void customSetup()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void doResetUnused()`
- `bool init(LevelEditorLayer* layer)`
- `void onAlignX(cocos2d::CCObject* sender)`
- `void onAlignY(cocos2d::CCObject* sender)`
- `void onBuildHelper(cocos2d::CCObject* sender)`
- `void onCopyWColor(cocos2d::CCObject* sender)`
- `void onCreateExtras(cocos2d::CCObject* sender)`
- `void onCreateLoop(cocos2d::CCObject* sender)`
- `void onCreateTemplate(cocos2d::CCObject* sender)`
- `void onExitEditor(cocos2d::CCObject* sender)`
- `void onExitNoSave(cocos2d::CCObject* sender)`
- `void onHelp(cocos2d::CCObject* sender)`
- `void onKeybindings(cocos2d::CCObject* sender)`
- `void onNewGroupX(cocos2d::CCObject* sender)`
- `void onNewGroupY(cocos2d::CCObject* sender)`
- `void onOptions(cocos2d::CCObject* sender)`
- `void onPasteWColor(cocos2d::CCObject* sender)`
- `void onReGroup(cocos2d::CCObject* sender)`
- `void onResetUnusedColors(cocos2d::CCObject* sender)`
- `void onResume(cocos2d::CCObject* sender)`
- `void onSave(cocos2d::CCObject* sender)`
- `void onSaveAndExit(cocos2d::CCObject* sender)`
- `void onSaveAndPlay(cocos2d::CCObject* sender)`
- `void onSelectAll(cocos2d::CCObject* sender)`
- `void onSelectAllLeft(cocos2d::CCObject* sender)`
- `void onSelectAllRight(cocos2d::CCObject* sender)`
- `void onSong(cocos2d::CCObject* sender)`
- `void onUnlockAllLayers(cocos2d::CCObject* sender)`
- `void playStep2()`
- `void playStep3()`
- `void saveLevel()`
- `void toggleDebugDraw(cocos2d::CCObject* sender)`
- `void toggleEditorBackground(cocos2d::CCObject* sender)`
- `void toggleEditorColorMode(cocos2d::CCObject* sender)`
- `void toggleEditorGrid(cocos2d::CCObject* sender)`
- `void toggleEditorGround(cocos2d::CCObject* sender)`
- `void toggleEffectDuration(cocos2d::CCObject* sender)`
- `void toggleEffectLines(cocos2d::CCObject* sender)`
- `void toggleFollowPlayer(cocos2d::CCObject* sender)`
- `void toggleGridOnTop(cocos2d::CCObject* sender)`
- `void toggleHideInvisible(cocos2d::CCObject* sender)`
- `void toggleIgnoreDamage(cocos2d::CCObject* sender)`
- `void togglePlaytestMusic(cocos2d::CCObject* sender)`
- `void togglePreviewAnim(cocos2d::CCObject* sender)`
- `void togglePreviewParticles(cocos2d::CCObject* sender)`
- `void togglePreviewShaders(cocos2d::CCObject* sender)`
- `void toggleRecordOrder(cocos2d::CCObject* sender)`
- `void toggleSelectFilter(cocos2d::CCObject* sender)`
- `void toggleShowObjectInfo(cocos2d::CCObject* sender)`
- `void uncheckAllPortals(cocos2d::CCObject* sender)`
- `void updateSongButton()`

**Members:**

- `bool m_saved`
- `CCMenuItemSpriteExtra* m_guidelinesOffButton`
- `CCMenuItemSpriteExtra* m_guidelinesOnButton`
- `LevelEditorLayer* m_editorLayer`
- `PAD`

### `EditorUI` : cocos2d::CCLayer, FLAlertLayerProtocol, ColorSelectDelegate, GJRotationControlDelegate, GJScaleControlDelegate, GJTransformControlDelegate, MusicDownloadDelegate, SetIDPopupDelegate

**Functions:**

- `EditorUI()`
- `~EditorUI()`
- `static EditorUI* create(LevelEditorLayer* editorLayer)`
- `static EditorUI* get()`
- `static int getRandomStartKey(int specialTemplate)`
- `static int getSmartObjectKey(int key, GJSmartDirection direction)`
- `static int smartTypeForKey(int key)`
- `virtual void draw()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual EditorUI* getUI()`
- `virtual void setIDPopupClosed(SetIDPopup* popup, int value)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void updateTransformControl()`
- `virtual void transformChangeBegin()`
- `virtual void transformChangeEnded()`
- `virtual cocos2d::CCNode* getTransformNode()`
- `virtual void transformScaleXChanged(float scaleX)`
- `virtual void transformScaleYChanged(float scaleY)`
- `virtual void transformScaleXYChanged(float scaleX, float scaleY)`
- `virtual void transformSkewXChanged(float skewX)`
- `virtual void transformSkewYChanged(float skewY)`
- `virtual void transformRotationXChanged(float rotationX)`
- `virtual void transformRotationYChanged(float rotationY)`
- `virtual void transformRotationChanged(float rotation)`
- `virtual void transformResetRotation()`
- `virtual void transformRestoreRotation()`
- `virtual void songStateChanged()`
- `virtual void colorSelectClosed(cocos2d::CCNode* popup)`
- `virtual void keyUp(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void scrollWheel(float y, float x)`
- `virtual void angleChangeBegin()`
- `virtual void angleChangeEnded()`
- `virtual void angleChanged(float rotation)`
- `virtual void updateScaleControl()`
- `virtual void anchorPointMoved(cocos2d::CCPoint anchorPoint)`
- `virtual void scaleChangeBegin()`
- `virtual void scaleChangeEnded()`
- `virtual void scaleXChanged(float scaleX, bool lock)`
- `virtual void scaleYChanged(float scaleY, bool lock)`
- `virtual void scaleXYChanged(float scaleX, float scaleY, bool lock)`
- `void activateRotationControl(cocos2d::CCObject* sender)`
- `void activateScaleControl(cocos2d::CCObject* sender)`
- `void activateTransformControl(cocos2d::CCObject* sender)`
- `void addObjectsToSmartTemplate(GJSmartTemplate* smartTemplate, cocos2d::CCArray* objects)`
- `void addSnapPosition(cocos2d::CCPoint position)`
- `void alignObjects(cocos2d::CCArray* objects, bool axisY)`
- `void applyOffset(GameObject* object)`
- `cocos2d::CCPoint applySpecialOffset(cocos2d::CCPoint position, GameObject* object, cocos2d::CCPoint offset)`
- `bool arrayContainsClass(cocos2d::CCArray* objects, int classType)`
- `void assignNewGroups(bool groupY)`
- `bool canAllowMultiActivate(GameObject* object, cocos2d::CCArray* objects)`
- `bool canSelectObject(GameObject* object)`
- `void centerCameraOnObject(GameObject* object)`
- `void changeSelectedObjects(cocos2d::CCArray* objects, bool ignoreFilter)`
- `cocos2d::CCPoint checkDiffAfterTransformAnchor(cocos2d::CCPoint diff, cocos2d::CCArray* objects)`
- `void checkLiveColorSelect()`
- `void clickOnPosition(cocos2d::CCPoint position)`
- `void closeLiveColorSelect()`
- `void closeLiveHSVSelect()`
- `void colorSelectClosed(cocos2d::ccColor3B color)`
- `void constrainGameLayerPosition()`
- `void constrainGameLayerPosition(float x, float y)`
- `int convertKeyBasedOnNeighbors(int smartKey, int objectID, cocos2d::CCPoint position, cocos2d::CCArray* objects)`
- `int convertToBaseKey(int objectID)`
- `gd::string copyObjects(cocos2d::CCArray* objects, bool copyColors, bool sort)`
- `gd::string copyObjectsDetailed(cocos2d::CCArray* objects)`
- `cocos2d::CCArray* createCustomItems()`
- `GameObject* createEdgeForObject(GameObject* object, int type)`
- `void createExtraObject(int id, cocos2d::CCPoint position, GameObject* object, cocos2d::CCArray* objects, int zOrder, int editorLayer)`
- `cocos2d::CCArray* createExtras(cocos2d::CCArray* objects)`
- `void createExtrasForObject(int id, GameObject* object, cocos2d::CCArray* objects)`
- `void createGlow()`
- `void createLoop()`
- `void createMoveMenu()`
- `void createNewKeyframeAnim()`
- `GameObject* createObject(int objectID, cocos2d::CCPoint position)`
- `cocos2d::CCArray* createOutlines(cocos2d::CCArray* objects)`
- `void createPrefab(GJSmartTemplate* smartTemplate, gd::string key, int id)`
- `cocos2d::CCArray* createRockBases(cocos2d::CCArray* objects)`
- `cocos2d::CCArray* createRockEdges(cocos2d::CCArray* objects)`
- `void createSmartObjectsFromTemplate(GJSmartTemplate* smartTemplate, cocos2d::CCArray* objects, bool useNearby, bool dontDelete, bool referenceOnly, bool dontPaste)`
- `void createSmartObjectsFromType(int type, cocos2d::CCArray* objects, bool extras, bool dontDelete)`
- `UndoObject* createUndoObject(UndoCommand command, bool addToList)`
- `void createUndoSelectObject(bool redo)`
- `void deactivateRotationControl()`
- `void deactivateScaleControl()`
- `void deactivateTransformControl()`
- `void deleteObject(GameObject* object, bool noUndo)`
- `void deleteSmartBlocksFromObjects(cocos2d::CCArray* objects)`
- `void deleteTypeFromObjects(int id, cocos2d::CCArray* objects)`
- `void deselectAll()`
- `void deselectObject()`
- `void deselectObject(GameObject* object)`
- `void deselectObjectsColor()`
- `void deselectTargetPortals()`
- `void disableButton(CreateMenuItem* button)`
- `void doCopyObjects(bool withColor)`
- `void doPasteInPlace(bool withColor)`
- `void doPasteObjects(bool withColor)`
- `void dynamicGroupUpdate(bool reGroup)`
- `int edgeForObject(int id, int type)`
- `bool editButton2Usable()`
- `bool editButtonUsable()`
- `void editColor()`
- `bool editColorButtonUsable()`
- `void editGroup(cocos2d::CCObject* sender)`
- `void editHSV()`
- `void editObject(cocos2d::CCObject* sender)`
- `void editObject2(cocos2d::CCObject* sender)`
- `void editObject3(cocos2d::CCObject* sender)`
- `void editObjectSpecial(int type)`
- `int editorLayerForArray(cocos2d::CCArray* objects, bool layer2)`
- `void enableButton(CreateMenuItem* button)`
- `void findAndSelectObject(int id, bool useUniqueID)`
- `void findSnapObject(cocos2d::CCArray* objects, float offset)`
- `void findSnapObject(cocos2d::CCPoint position, float offset)`
- `void findTriggerTest()`
- `void flipObjectsX(cocos2d::CCArray* objects)`
- `void flipObjectsY(cocos2d::CCArray* objects)`
- `CCMenuItemSpriteExtra* getButton(char const* text, int width, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu)`
- `CreateMenuItem* getCreateBtn(int id, int bg)`
- `CreateMenuItem* getCreateMenuItemButton(cocos2d::CCSprite* sprite, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale, int background, cocos2d::CCPoint offset)`
- `GameObject* getCycledObject(cocos2d::CCArray* objects, bool dontSkipSelected)`
- `void getEditColorTargets(ColorAction*& mainColor, ColorAction*& detailColor, EffectGameObject*& object)`
- `cocos2d::CCPoint getGridSnappedPos(cocos2d::CCPoint pos)`
- `cocos2d::CCPoint getGroupCenter(cocos2d::CCArray* objects, bool absolute)`
- `void getGroupInfo(GameObject* selectedObject, cocos2d::CCArray* selectedObjects, int& objectID, int& classType, int& objectType)`
- `cocos2d::CCPoint getLimitedPosition(cocos2d::CCPoint position)`
- `CCMenuItemSpriteExtra* getModeBtn(char const* frameName, int tag)`
- `cocos2d::CCNode* getNeighbor(int smartKey, cocos2d::CCPoint position, GJSmartDirection direction, cocos2d::CCArray* objects)`
- `cocos2d::CCPoint getRelativeOffset(GameObject* object)`
- `cocos2d::CCArray* getSelectedObjects()`
- `CCMenuItemSpriteExtra* getSimpleButton(gd::string frameName, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu)`
- `SmartGameObject* getSmartNeighbor(SmartGameObject* object, cocos2d::CCPoint position, GJSmartDirection direction, cocos2d::CCArray* objects)`
- `float getSnapAngle(GameObject* object, cocos2d::CCArray* objects)`
- `CCMenuItemSpriteExtra* getSpriteButton(char const* spriteFrameName, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale)`
- `CCMenuItemSpriteExtra* getSpriteButton(char const* spriteFrameName, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale, int buttonKind, cocos2d::CCPoint offset)`
- `CCMenuItemSpriteExtra* getSpriteButton(cocos2d::CCSprite* sprite, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale, int buttonKind, cocos2d::CCPoint offset)`
- `cocos2d::CCPoint getTouchPoint(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `GJTransformState& getTransformState()`
- `float getXMin(int offset)`
- `bool init(LevelEditorLayer* editorLayer)`
- `bool isLiveColorSelectTrigger(GameObject* object)`
- `bool isSpecialSnapObject(int id)`
- `bool liveEditColorUsable()`
- `CreateMenuItem* menuItemFromObjectString(gd::string str, int id)`
- `cocos2d::CCPoint moveForCommand(EditCommand command)`
- `void moveGamelayer(cocos2d::CCPoint offset)`
- `void moveObject(GameObject* object, cocos2d::CCPoint offset)`
- `void moveObjectCall(EditCommand command)`
- `void moveObjectCall(cocos2d::CCObject* sender)`
- `cocos2d::CCPoint offsetForKey(int id)`
- `void onAssignNewGroupID()`
- `void onColorFilter(cocos2d::CCObject* sender)`
- `void onCopy(cocos2d::CCObject* sender)`
- `void onCopyState(cocos2d::CCObject* sender)`
- `bool onCreate()`
- `void onCreateButton(cocos2d::CCObject* sender)`
- `void onCreateObject(int id)`
- `void onDelete(cocos2d::CCObject* sender)`
- `void onDeleteAll(cocos2d::CCObject* sender)`
- `void onDeleteCustomItem(cocos2d::CCObject* sender)`
- `void onDeleteInfo(cocos2d::CCObject* sender)`
- `void onDeleteSelected(cocos2d::CCObject* sender)`
- `void onDeleteSelectedType(cocos2d::CCObject* sender)`
- `void onDeleteStartPos(cocos2d::CCObject* sender)`
- `void onDeselectAll(cocos2d::CCObject* sender)`
- `void onDuplicate(cocos2d::CCObject* sender)`
- `void onEditColor(cocos2d::CCObject* sender)`
- `void onFindObject(cocos2d::CCObject* sender)`
- `void onGoToBaseLayer(cocos2d::CCObject* sender)`
- `void onGoToLayer(cocos2d::CCObject* sender)`
- `void onGroupDown(cocos2d::CCObject* sender)`
- `void onGroupIDFilter(cocos2d::CCObject* sender)`
- `void onGroupSticky(cocos2d::CCObject* sender)`
- `void onGroupUp(cocos2d::CCObject* sender)`
- `void onLockLayer(cocos2d::CCObject* sender)`
- `void onNewCustomItem(cocos2d::CCObject* sender)`
- `void onPaste(cocos2d::CCObject* sender)`
- `void onPasteColor(cocos2d::CCObject* sender)`
- `void onPasteInPlace(cocos2d::CCObject* sender)`
- `void onPasteState(cocos2d::CCObject* sender)`
- `void onPause(cocos2d::CCObject* sender)`
- `void onPlayback(cocos2d::CCObject* sender)`
- `void onPlaytest(cocos2d::CCObject* sender)`
- `void onResetSpecialFilter(cocos2d::CCObject* sender)`
- `void onSelectBuildTab(cocos2d::CCObject* sender)`
- `void onSettings(cocos2d::CCObject* sender)`
- `void onStickyToggle(cocos2d::CCObject* sender)`
- `void onStopPlaytest(cocos2d::CCObject* sender)`
- `void onTargetIDChange(int change)`
- `void onToggleGuide(EffectGameObject* object)`
- `void onToggleSelectedOrder(EffectGameObject* object)`
- `void onToggleTraceIn(GameObject* object)`
- `void onToggleTraceOut(EffectGameObject* object)`
- `void onUngroupSticky(cocos2d::CCObject* sender)`
- `void onUpdateDeleteFilter(cocos2d::CCObject* sender)`
- `void orderDownCustomItem(cocos2d::CCObject* sender)`
- `void orderUpCustomItem(cocos2d::CCObject* sender)`
- `cocos2d::CCArray* pasteObjects(gd::string str, bool withColor, bool noUndo)`
- `void playCircleAnim(cocos2d::CCPoint position, float radius, float duration)`
- `void playerTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `void playerTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `void playtestStopped()`
- `bool positionIsInSnapped(cocos2d::CCPoint position)`
- `cocos2d::CCPoint positionWithoutOffset(GameObject* object)`
- `void processSelectObjects(cocos2d::CCArray* objects)`
- `void processSmartObjectsFromType(int type, cocos2d::CCArray* objects, cocos2d::CCArray* objects2, cocos2d::CCArray* objects3, cocos2d::CCArray* objects4)`
- `void recreateButtonTabs()`
- `void redoLastAction(cocos2d::CCObject* sender)`
- `void reloadCustomItems()`
- `void removeOffset(GameObject* object)`
- `void replaceGroupID(GameObject* object, int oldID, int newID)`
- `void repositionObjectsToCenter(cocos2d::CCArray* objects, cocos2d::CCPoint position, bool absolute)`
- `void resetObjectEditorValues(cocos2d::CCArray* objects)`
- `void resetSelectedObjectsColor()`
- `void resetUI()`
- `void rotateObjects(cocos2d::CCArray* objects, float rotation, cocos2d::CCPoint pivotPoint)`
- `float rotationforCommand(EditCommand command)`
- `void scaleObjects(cocos2d::CCArray* objects, float scaleX, float scaleY, cocos2d::CCPoint pivotPoint, ObjectScaleType type, bool lockMove)`
- `void selectAll()`
- `void selectAllWithDirection(bool left)`
- `void selectBuildTab(int tab)`
- `void selectObject(GameObject* object, bool ignoreFilter)`
- `void selectObjects(cocos2d::CCArray* objects, bool ignoreFilter)`
- `void selectObjectsInRect(cocos2d::CCRect rect)`
- `void setupCreateMenu()`
- `void setupDeleteMenu()`
- `void setupEditMenu()`
- `void setupTransformControl()`
- `bool shouldDeleteObject(GameObject* object)`
- `bool shouldSnap(GameObject* object)`
- `void showDeleteConfirmation()`
- `void showLiveColorSelectForMode(int colorID)`
- `void showLiveColorSelectForModeSpecial(int colorID)`
- `void showMaxBasicError()`
- `void showMaxCoinError()`
- `void showMaxError()`
- `void showUI(bool show)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `cocos2d::CCSprite* spriteFromObjectString(gd::string str, bool absoluteCenter, bool useGroup, int objLimit, cocos2d::CCArray* objects, cocos2d::CCArray* group, GameObject* groupParent)`
- `void toggleDuplicateButton()`
- `void toggleEditObjectButton()`
- `void toggleEnableRotate(cocos2d::CCObject* sender)`
- `void toggleFreeMove(cocos2d::CCObject* sender)`
- `void toggleLockUI(bool lockUI)`
- `void toggleMode(cocos2d::CCObject* sender)`
- `void toggleObjectInfoLabel()`
- `void toggleSnap(cocos2d::CCObject* sender)`
- `void toggleSpecialEditButtons()`
- `void toggleSwipe(cocos2d::CCObject* sender)`
- `void transformObject(GameObject* object, EditCommand command, bool noOffset)`
- `void transformObjectCall(EditCommand command)`
- `void transformObjectCall(cocos2d::CCObject* sender)`
- `void transformObjects(cocos2d::CCArray* objs, cocos2d::CCPoint anchor, float scaleX, float scaleY, float rotateX, float rotateY, float warpX, float warpY)`
- `void transformObjectsActive()`
- `void transformObjectsReset()`
- `void triggerSwipeMode()`
- `void tryUpdateTimeMarkers()`
- `void undoLastAction(cocos2d::CCObject* object)`
- `void updateButtons()`
- `void updateCreateMenu(bool selectTab)`
- `void updateDeleteButtons()`
- `void updateDeleteMenu()`
- `void updateEditButtonColor(int tag, cocos2d::ccColor3B color)`
- `void updateEditColorButton()`
- `void updateEditMenu()`
- `void updateGridNodeSize()`
- `void updateGridNodeSize(int objectID)`
- `void updateGroupIDBtn2()`
- `void updateGroupIDLabel()`
- `void updateObjectInfoLabel()`
- `void updatePlaybackBtn()`
- `void updateSlider()`
- `void updateSpecialUIElements()`
- `void updateStickyControls()`
- `void updateZoom(float zoom)`
- `float valueFromXPos(float xPos)`
- `float xPosFromValue(float value)`
- `void zoomGameLayer(bool zoomingIn)`
- `void zoomIn(cocos2d::CCObject* sender)`
- `void zoomOut(cocos2d::CCObject* sender)`

**Members:**

- `gd::unordered_map<int, GameObjectEditorState> m_objectEditorStates`
- `GJTransformState m_transformState`
- `bool m_isPlayingMusic`
- `EditButtonBar* m_customTabBar`
- `bool m_alertShown`
- `cocos2d::CCArray* m_uiItems`
- `float m_gridSize`
- `int m_playerTouchID1`
- `int m_playerTouchID2`
- `bool m_playbackActive`
- `float m_playbackStartWarp`
- `float m_playbackStartTime`
- `UndoObject* m_undoObject`
- `bool m_spaceSwiping`
- `bool m_noSnapUndo`
- `bool m_editingObject`
- `bool m_increaseScale`
- `bool m_refreshPosition`
- `int m_rotationTouchID`
- `int m_scaleTouchID`
- `int m_touchID`
- `int m_transformTouchID`
- `cocos2d::CCLabelBMFont* m_objectInfoLabel`
- `GJRotationControl* m_rotationControl`
- `cocos2d::CCPoint m_pivotPoint`
- `bool m_canActivateControls`
- `GJScaleControl* m_scaleControl`
- `GJTransformControl* m_transformControl`
- `cocos2d::CCNode* m_transformNode`
- `cocos2d::CCNode* m_transformChild`
- `cocos2d::CCDictionary* m_editButtonDict`
- `EditButtonBar* m_createButtonBar`
- `EditButtonBar* m_editButtonBar`
- `Slider* m_positionSlider`
- `float m_unk308`
- `float m_constrainedHeight`
- `float m_toolbarHeight`
- `bool m_swipeEnabled`
- `bool m_swipeActive`
- `bool m_swipeSelected`
- `bool m_continuousSnap`
- `bool m_freeMoveEnabled`
- `bool m_snapObjectExists`
- `bool m_snapSelected`
- `bool m_stickyControlsEnabled`
- `bool m_linkControlsDisabled`
- `bool m_speedObjectsUpdated`
- `cocos2d::CCPoint m_createPosition`
- `cocos2d::CCArray* m_snapPositions`
- `cocos2d::CCPoint m_snapPosition`
- `cocos2d::CCArray* m_selectedObjects`
- `cocos2d::CCMenu* m_deleteMenu`
- `cocos2d::CCArray* m_customTabControls`
- `CCMenuItemSpriteExtra* m_deleteModeBtn`
- `CCMenuItemSpriteExtra* m_buildModeBtn`
- `CCMenuItemSpriteExtra* m_editModeBtn`
- `CCMenuItemSpriteExtra* m_swipeBtn`
- `CCMenuItemSpriteExtra* m_freeMoveBtn`
- `CCMenuItemSpriteExtra* m_deselectBtn`
- `CCMenuItemSpriteExtra* m_snapBtn`
- `CCMenuItemSpriteExtra* m_rotateBtn`
- `CCMenuItemSpriteExtra* m_playbackBtn`
- `CCMenuItemSpriteExtra* m_playtestBtn`
- `CCMenuItemSpriteExtra* m_playtestStopBtn`
- `CCMenuItemSpriteExtra* m_trashBtn`
- `CCMenuItemSpriteExtra* m_linkBtn`
- `CCMenuItemSpriteExtra* m_unlinkBtn`
- `CCMenuItemSpriteExtra* m_enableLinkBtn`
- `CCMenuItemSpriteExtra* m_undoBtn`
- `CCMenuItemSpriteExtra* m_redoBtn`
- `CCMenuItemSpriteExtra* m_editObjectBtn`
- `CCMenuItemSpriteExtra* m_editGroupBtn`
- `CCMenuItemSpriteExtra* m_editHSVBtn`
- `CCMenuItemSpriteExtra* m_editSpecialBtn`
- `cocos2d::CCObject* m_unk3F0`
- `CCMenuItemSpriteExtra* m_copyPasteBtn`
- `CCMenuItemSpriteExtra* m_copyBtn`
- `CCMenuItemSpriteExtra* m_pasteBtn`
- `CCMenuItemSpriteExtra* m_copyValuesBtn`
- `CCMenuItemSpriteExtra* m_pasteStateBtn`
- `CCMenuItemSpriteExtra* m_pasteColorBtn`
- `CCMenuItemSpriteExtra* m_goToLayerBtn`
- `cocos2d::CCArray* m_createButtonBars`
- `cocos2d::CCMenu* m_tabsMenu`
- `cocos2d::CCArray* m_tabsArray`
- `cocos2d::CCSprite* m_deleteAllSprite`
- `cocos2d::CCSprite* m_customDeleteSprite`
- `CCMenuItemSpriteExtra* m_deleteButton`
- `CCMenuItemSpriteExtra* m_deleteAllButton`
- `CCMenuItemSpriteExtra* m_deleteFilterNone`
- `CCMenuItemSpriteExtra* m_deleteFilterStatic`
- `CCMenuItemSpriteExtra* m_deleteFilterDetails`
- `CCMenuItemSpriteExtra* m_deleteFilterCustom`
- `cocos2d::CCLabelBMFont* m_currentLayerLabel`
- `CCMenuItemSpriteExtra* m_layerNextBtn`
- `CCMenuItemSpriteExtra* m_layerPrevBtn`
- `CCMenuItemSpriteExtra* m_goToBaseBtn`
- `ButtonSprite* m_deleteGroupSprite`
- `ButtonSprite* m_deleteColorSprite`
- `void* m_unk4b8`
- `void* m_unk4c0`
- `int m_selectedObjectIndex`
- `cocos2d::CCArray* m_createButtonArray`
- `cocos2d::CCArray* m_customObjectButtonArray`
- `cocos2d::CCArray* m_deleteObjects`
- `int m_selectedMode`
- `LevelEditorLayer* m_editorLayer`
- `cocos2d::CCPoint m_swipeStart`
- `cocos2d::CCPoint m_swipeEnd`
- `cocos2d::CCPoint m_swipePosition`
- `cocos2d::CCPoint m_lastTouchPoint`
- `cocos2d::CCPoint m_cameraTest`
- `cocos2d::CCPoint m_clickAtPosition`
- `GameObject* m_selectedObject`
- `GameObject* m_snapObject`
- `bool m_isDraggingCamera`
- `bool m_continueSwipe`
- `bool m_findSnap`
- `void* m_unk540`
- `int m_selectedTab`
- `int m_cycledObjectIndex`
- `ColorSelectLiveOverlay* m_colorOverlay`
- `HSVLiveOverlay* m_hsvOverlay`
- `double m_keyTime`
- `double m_keyTime2`
- `bool m_swipeModeTriggered`
- `cocos2d::CCSprite* m_layerLockSprite`
- `void* m_unk580`
- `bool m_pressedSpace`
- `float m_editorZoom`
- `bool m_isPaused`
- `bool m_reloadItems`

### `EffectGameObject` : EnhancedGameObject

**Functions:**

- `EffectGameObject()`
- `static EffectGameObject* create(char const* frame)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void firstSetup()`
- `virtual void customSetup()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void setRScaleX(float scaleX)`
- `virtual void setRScaleY(float scaleY)`
- `virtual void triggerActivated(float xPosition)`
- `virtual void restoreObject()`
- `virtual float spawnXPosition()`
- `virtual bool canReverse()`
- `virtual bool isSpecialSpawnObject()`
- `virtual bool canBeOrdered()`
- `virtual cocos2d::CCLabelBMFont* getObjectLabel()`
- `virtual void setObjectLabel(cocos2d::CCLabelBMFont* label)`
- `virtual void stateSensitiveOff(GJBaseGameLayer* layer)`
- `bool canSpawnTriggers()`
- `int getTargetColorIndex()`
- `bool hasSpawnTargetID(int id)`
- `bool init(char const* frame)`
- `void playTriggerEffect()`
- `void resetSpawnTrigger()`
- `void setTargetID(int id)`
- `void setTargetID2(int id)`
- `void triggerEffectFinished()`
- `void updateInteractiveHover(float offset)`
- `void updateSpecialColor()`
- `void updateSpeedModType()`

**Members:**

- `bool m_unknownBool`
- `cocos2d::ccColor3B m_triggerTargetColor`
- `float m_duration`
- `float m_opacity`
- `bool m_triggerEffectPlaying`
- `int m_targetGroupID`
- `int m_centerGroupID`
- `bool m_isTouchTriggered`
- `bool m_isSpawnTriggered`
- `bool m_hasCenterEffect`
- `float m_shakeStrength`
- `float m_shakeInterval`
- `bool m_tintGround`
- `bool m_usesPlayerColor1`
- `bool m_usesPlayerColor2`
- `bool m_usesBlending`
- `cocos2d::CCPoint m_moveOffset`
- `EasingType m_easingType`
- `float m_easingRate`
- `bool m_lockToPlayerX`
- `bool m_lockToPlayerY`
- `bool m_lockToCameraX`
- `bool m_lockToCameraY`
- `bool m_useMoveTarget`
- `MoveTargetType m_moveTargetMode`
- `float m_moveModX`
- `float m_moveModY`
- `bool m_smallStep`
- `bool m_isDirectionFollowSnap360`
- `int m_targetModCenterID`
- `float m_directionModeDistance`
- `bool m_isDynamicMode`
- `bool m_isSilent`
- `int m_specialTarget`
- `float m_rotationDegrees`
- `int m_times360`
- `bool m_lockObjectRotation`
- `int m_rotationTargetID`
- `float m_rotationOffset`
- `int m_dynamicModeEasing`
- `float m_followXMod`
- `float m_followYMod`
- `float m_followYSpeed`
- `float m_followYDelay`
- `int m_followYOffset`
- `float m_followYMaxSpeed`
- `float m_fadeInDuration`
- `float m_holdDuration`
- `float m_fadeOutDuration`
- `int m_pulseMode`
- `int m_pulseTargetType`
- `cocos2d::ccHSVValue m_hsvValue`
- `int m_copyColorID`
- `bool m_copyOpacity`
- `bool m_pulseMainOnly`
- `bool m_pulseDetailOnly`
- `bool m_pulseExclusive`
- `bool m_legacyHSV`
- `bool m_activateGroup`
- `bool m_touchHoldMode`
- `TouchTriggerType m_touchToggleMode`
- `TouchTriggerControl m_touchPlayerMode`
- `bool m_isDualMode`
- `int m_animationID`
- `float m_spawnXPosition`
- `int m_spawnOrder`
- `bool m_isMultiTriggered`
- `bool m_previewDisable`
- `bool m_spawnOrdered`
- `bool m_triggerOnExit`
- `int m_itemID2`
- `int m_controlID`
- `bool m_targetControlID`
- `bool m_isDynamicBlock`
- `int m_itemID`
- `bool m_targetPlayer1`
- `bool m_targetPlayer2`
- `bool m_followCPP`
- `bool m_subtractCount`
- `bool m_collectibleIsPickupItem`
- `bool m_collectibleIsToggleTrigger`
- `int m_collectibleParticleID`
- `int m_collectiblePoints`
- `bool m_hasNoAnimation`
- `void* m_unk698`
- `int m_forceModID`
- `bool m_rotateFollowP1`
- `bool m_rotateFollowP2`
- `float m_unk6a8`
- `float m_unk6ac`
- `float m_unk6b0`
- `bool m_unk6b4`
- `float m_gravityValue`
- `bool m_isSinglePTouch`
- `float m_zoomValue`
- `bool m_cameraIsFreeMode`
- `bool m_cameraEditCameraSettings`
- `float m_cameraEasingValue`
- `float m_cameraPaddingValue`
- `bool m_cameraDisableGridSnap`
- `bool m_endReversed`
- `float m_timeWarpTimeMod`
- `bool m_shouldPreview`
- `int m_ordValue`
- `int m_channelValue`
- `bool m_isReverse`
- `short m_speedModType`
- `cocos2d::CCPoint m_speedStart`
- `int m_secretCoinID`
- `bool m_unk6f4`
- `bool m_unk6f5`
- `cocos2d::CCPoint m_endPosition`
- `float m_spawnTriggerDelay`
- `float m_gravityMod`
- `bool m_unk708`
- `cocos2d::CCLabelBMFont* m_objectLabel`
- `bool m_ignoreGroupParent`
- `bool m_ignoreLinkedObjects`
- `bool m_channelChanged`
- `bool m_canSpawnTriggers`

### `EffectManagerState`

**Members:**

- `gd::vector<CAState> m_unkVecCAState`
- `gd::vector<PulseEffectAction> m_unkVecPulseEffectAction`
- `gd::unordered_map<int,gd::vector<PulseEffectAction>> m_unorderedMapInt_vectorPulseEffectAction`
- `gd::unordered_map<int,gd::vector<CountTriggerAction>> m_unorderedMapInt_vectorCountTriggerAction`
- `gd::unordered_set<int> m_unorderedSet_int1`
- `gd::map<int,int> m_mapInt_Int`
- `gd::unordered_map<int,OpacityEffectAction> m_unorderedMapInt_OpacityEffectAction`
- `gd::vector<TouchToggleAction> m_vectorTouchToggleAction`
- `gd::vector<CollisionTriggerAction> m_vectorCollisionTriggerAction`
- `gd::vector<ToggleTriggerAction> m_vectorToggleTriggerAction`
- `gd::vector<SpawnTriggerAction> m_vectorSpawnTriggerAction`
- `gd::unordered_map<int,int> m_itemCountMap`
- `gd::unordered_map<int,bool> m_unorderedMapInt_bool`
- `gd::vector<GroupCommandObject2> m_vectorGroupCommandObject2`
- `gd::unordered_map<int,std::pair<double,double>> m_unorderedMapInt_pair_double_double`
- `gd::unordered_set<int> m_unorderedSet_int2`
- `gd::unordered_map<int,TimerItem> m_timerItemMap`
- `gd::unordered_map<int,gd::vector<TimerTriggerAction>> m_unorderedMapInt_vectorTimerTriggerAction`

### `EndLevelLayer` : GJDropDownLayer

**Functions:**

- `EndLevelLayer()`
- `~EndLevelLayer()`
- `static EndLevelLayer* create(PlayLayer* playLayer)`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void customSetup()`
- `virtual void showLayer(bool instant)`
- `virtual void enterAnimFinished()`
- `virtual void keyUp(cocos2d::enumKeyCodes key, double timestamp)`
- `void coinEnterFinished(cocos2d::CCPoint position)`
- `void coinEnterFinishedO(cocos2d::CCObject* sender)`
- `void currencyEnterFinished()`
- `void diamondEnterFinished()`
- `gd::string getCoinString()`
- `const char* getEndText()`
- `void goEdit()`
- `bool init(PlayLayer* playLayer)`
- `void onEdit(cocos2d::CCObject* sender)`
- `void onEveryplay(cocos2d::CCObject* sender)`
- `void onHideLayer(cocos2d::CCObject* sender)`
- `void onLevelLeaderboard(cocos2d::CCObject* sender)`
- `void onMenu(cocos2d::CCObject* sender)`
- `void onReplay(cocos2d::CCObject* sender)`
- `void onRestartCheckpoint(cocos2d::CCObject* sender)`
- `void playCoinEffect(float duration)`
- `void playCurrencyEffect(float duration)`
- `void playDiamondEffect(float duration)`
- `void playEndEffect()`
- `void playStarEffect(float duration)`
- `void starEnterFinished()`
- `void tryShowBanner(float dt)`

**Members:**

- `PlayLayer* m_playLayer`
- `bool m_notLocal`
- `bool m_coinsVerified`
- `bool m_unknown3`
- `bool m_exiting`
- `bool m_animateCoins`
- `bool m_endEffectPlayed`
- `cocos2d::CCMenu* m_sideMenu`
- `cocos2d::CCArray* m_coinsToAnimate`
- `cocos2d::CCPoint m_starsPosition`
- `cocos2d::CCPoint m_orbsPosition`
- `cocos2d::CCPoint m_diamondsPosition`
- `int m_orbs`
- `int m_stars`
- `int m_moons`
- `int m_diamonds`
- `bool m_secretKey`
- `bool m_hidden`

### `EndPortalObject` : GameObject

**Functions:**

- `EndPortalObject()`
- `static EndPortalObject* create()`
- `virtual bool init()`
- `virtual void setPosition(cocos2d::CCPoint const& position)`
- `virtual void setVisible(bool visible)`
- `cocos2d::CCPoint getSpawnPos()`
- `void triggerObject(GJBaseGameLayer* layer)`
- `void updateColors(cocos2d::ccColor3B color)`
- `void updateEndPos(bool updateParticle)`

**Members:**

- `cocos2d::CCSprite* m_gradientBar`
- `bool m_flippedX`
- `bool m_startPosHeightRelated`

### `EndTriggerGameObject` : EffectGameObject

**Functions:**

- `EndTriggerGameObject()`
- `static EndTriggerGameObject* create()`
- `virtual bool init()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `bool m_noEffects`
- `bool m_noSFX`
- `bool m_instant`

### `EnhancedGameObject` : GameObject

**Functions:**

- `EnhancedGameObject()`
- `static EnhancedGameObject* create(char const* frame)`
- `virtual void customSetup()`
- `virtual void resetObject()`
- `virtual void deactivateObject(bool deactivate)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void triggerActivated(float xPosition)`
- `virtual void restoreObject()`
- `virtual void animationTriggered()`
- `virtual void activatedByPlayer(PlayerObject* player)`
- `virtual bool hasBeenActivatedByPlayer(PlayerObject* player)`
- `virtual bool hasBeenActivated()`
- `virtual void saveActiveColors()`
- `virtual bool canAllowMultiActivate()`
- `virtual bool getHasSyncedAnimation()`
- `virtual bool getHasRotateAction()`
- `virtual bool canMultiActivate(bool multiActivate)`
- `virtual void powerOnObject(int state)`
- `virtual void powerOffObject()`
- `virtual void stateSensitiveOff(GJBaseGameLayer* layer)`
- `virtual void updateSyncedAnimation(float totalTime, int frameIndex)`
- `virtual void updateAnimateOnTrigger(bool animate)`
- `void createRotateAction(float angle, int clockwiseDirection)`
- `bool init(char const* frame)`
- `void previewAnimateOnTrigger()`
- `void refreshRotateAction()`
- `void resetSyncedAnimation()`
- `void setupAnimationVariables()`
- `void triggerAnimation()`
- `void updateRotateAction(float dt)`
- `void updateState(int state)`
- `void updateUserCoin()`
- `void waitForAnimationTrigger()`

**Members:**

- `bool m_poweredOn`
- `int m_state`
- `int m_animationRandomizedStartValue`
- `float m_animationStart`
- `float m_unk540`
- `float m_unk544`
- `bool m_unk548`
- `float m_randomFrameTime`
- `bool m_visible`
- `bool m_shouldNotHideAnimFreeze`
- `bool m_usesSpecialAnimation`
- `float m_frameTime`
- `short m_frames`
- `bool m_hasCustomAnimation`
- `bool m_hasCustomRotation`
- `bool m_disableRotation`
- `float m_rotationSpeed`
- `float m_rotationAngle`
- `float m_rotationDelta`
- `float m_rotationAnimationSpeed`
- `bool m_animationRandomizedStart`
- `float m_animationSpeed`
- `bool m_animationShouldUseSpeed`
- `bool m_animateOnTrigger`
- `bool m_disableDelayedLoop`
- `bool m_disableAnimShine`
- `int m_singleFrame`
- `bool m_animationOffset`
- `bool m_animationTriggered`
- `int m_unkAnimationInt`
- `int m_maybeAnimationVariableXInt`
- `int m_maybeAnimationVariableYInt`
- `bool m_animateOnlyWhenActive`
- `bool m_isNoMultiActivate`
- `bool m_isMultiActivate`
- `bool m_activated`
- `bool m_activatedByPlayer1`
- `bool m_activatedByPlayer2`
- `bool m_hasUniqueCoin`

### `EnhancedTriggerObject` : EffectGameObject

**Functions:**

- `EnhancedTriggerObject()`
- `static EnhancedTriggerObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `int m_minXID`
- `int m_minYID`
- `int m_maxXID`
- `int m_maxYID`

### `EnterEffectInstance`

**Functions:**

- `EnterEffectInstance()`
- `EnterEffectInstance(EnterEffectObject* object, int targetID, int centerID, int unknown, int targetGroupIndex, int easeIndexCount, int controlID)`
- `void animateValue(int key, float value, float distance, float duration, int easingType, float easingRate, int easingBuffer)`
- `float getValue(int key)`
- `void loadTransitions(EnterEffectObject* object, float time)`
- `void loadValuesFromObject(EnterEffectObject* object)`
- `void setValue(int key, float value)`
- `void updateTransitions(float dt, GJBaseGameLayer* layer)`

**Members:**

- `gd::map<int,EnterEffectAnimValue> m_enterEffectAnimMap`
- `float m_length`
- `float m_lengthVariance`
- `float m_offset`
- `float m_offsetVariance`
- `float m_offsetY`
- `float m_offsetYVariance`
- `float m_modFront`
- `float m_modBack`
- `float m_deadzone`
- `float m_moveDistance`
- `float m_moveDistanceVariance`
- `float m_moveAngle`
- `float m_moveAngleVariance`
- `float m_moveX`
- `float m_moveXVariance`
- `float m_moveY`
- `float m_moveYVariance`
- `float m_relativeFade`
- `float m_scaleX`
- `float m_scaleXVariance`
- `float m_scaleY`
- `float m_scaleYVariance`
- `float m_rotation`
- `float m_rotationVariance`
- `float m_tint`
- `float m_unk074`
- `float m_toOpacity`
- `float m_fromOpacity`
- `cocos2d::ccHSVValue m_hsvValue`
- `float m_hue`
- `float m_saturation`
- `float m_value`
- `EnterEffectObject* m_gameObject`
- `bool m_reversed`
- `int m_targetID`
- `int m_centerID`
- `int m_unkFloat3`
- `int m_easeIndex`
- `bool m_paused`
- `bool m_paused2`
- `bool m_unkBool4`
- `int m_targetGroupIndex`
- `gd::vector<int> m_easeIndices`
- `int m_controlID`

### `EnterEffectObject` : EffectGameObject

**Functions:**

- `EnterEffectObject()`
- `static EnterEffectObject* create(char const* frame)`
- `virtual void customSetup()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`
- `void resetEnterAnimValues()`

**Members:**

- `int m_enterType`
- `int m_length`
- `int m_lengthVariance`
- `int m_offset`
- `int m_offsetVariance`
- `int m_offsetY`
- `int m_offsetYVariance`
- `int m_moveDistance`
- `int m_moveDistanceVariance`
- `float m_areaScaleX`
- `float m_areaScaleXVariance`
- `float m_areaScaleY`
- `float m_areaScaleYVariance`
- `int m_moveAngle`
- `int m_moveAngleVariance`
- `bool m_startAngle`
- `cocos2d::CCPoint m_anglePosition`
- `bool m_relative`
- `float m_relativeFade`
- `EasingType m_easingInType`
- `float m_easingInRate`
- `int m_easingInBuffer`
- `EasingType m_easingOutType`
- `float m_easingOutRate`
- `int m_easingOutBuffer`
- `int m_moveX`
- `int m_moveXVariance`
- `int m_moveY`
- `int m_moveYVariance`
- `int m_tintChannelID`
- `int m_property224`
- `int m_directionType`
- `bool m_xyMode`
- `bool m_easeOutEnabled`
- `float m_modFront`
- `float m_modBack`
- `float m_areaTint`
- `float m_property285`
- `int m_effectID`
- `float m_areaRotation`
- `float m_areaRotationVariance`
- `float m_toOpacity`
- `float m_fromOpacity`
- `bool m_inbound`
- `bool m_hsvEnabled`
- `float m_deadzone`
- `bool m_twoDirections`
- `bool m_dontEditAreaParent`
- `int m_priority`
- `int m_unk7d8`
- `int m_enterChannel`
- `bool m_useEffectID`
- `cocos2d::CCPoint m_unk7e4`
- `cocos2d::CCPoint m_unk7ec`
- `bool m_negativeTargetX`
- `int m_areaRange`
- `int m_unk7fc`

### `EventLinkTrigger` : EffectGameObject

**Functions:**

- `EventLinkTrigger()`
- `static EventLinkTrigger* create()`
- `virtual bool init()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `gd::set<int> m_eventIDs`
- `bool m_resetRemap`
- `int m_extraID`
- `int m_extraID2`

### `ExplodeItemNode` : cocos2d::CCNode

**Functions:**

- `static ExplodeItemNode* create(cocos2d::CCRenderTexture* texture)`
- `virtual void update(float dt)`
- `void createSprites(int countX, int countY, float xVel, float xVar, float yVel, float yVar, float dur, float durVar, cocos2d::ccColor4F startColor, cocos2d::ccColor4F endColor, bool noParticles)`
- `bool init(cocos2d::CCRenderTexture* texture)`

**Members:**

- `cocos2d::CCRenderTexture* m_renderTexture`
- `cocos2d::CCArray* m_sprites`
- `float m_unk1`
- `float m_floorHeight`
- `bool m_noGravity`

### `ExplodeItemSprite` : cocos2d::CCSprite

**Functions:**

- `ExplodeItemSprite()`
- `static ExplodeItemSprite* create()`
- `virtual bool init()`

**Members:**

- `float m_xVelocity`
- `float m_yVelocity`
- `float m_timeRemaining`
- `float m_fadeOutTime`
- `float m_rotVelocity`
- `cocos2d::CCParticleSystemQuad* m_particles`

### `ExtendedLayer` : cocos2d::CCLayer

**Functions:**

- `ExtendedLayer()`
- `static ExtendedLayer* create()`
- `virtual bool init()`
- `virtual void setPosition(cocos2d::CCPoint const& position)`

**Members:**

- `BoomScrollLayerDelegate* m_delegate`

### `FLAlertLayer` : cocos2d::CCLayerColor

**Functions:**

- `FLAlertLayer()`
- `~FLAlertLayer()`
- `static FLAlertLayer* create(char const* title, const gd::string& desc, char const* btn)`
- `static FLAlertLayer* create(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2)`
- `static FLAlertLayer* create(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width)`
- `static FLAlertLayer* create(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale)`
- `virtual void onEnter()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void show()`
- `void incrementForcePrio()`
- `bool init(int opacity)`
- `bool init(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale)`
- `void onBtn1(cocos2d::CCObject* sender)`
- `void onBtn2(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCMenu* m_buttonMenu`
- `FLAlertLayerProtocol* m_alertProtocol`
- `cocos2d::CCNode* m_scene`
- `bool m_reverseKeyBack`
- `cocos2d::ccColor3B m_color`
- `cocos2d::CCLayer* m_mainLayer`
- `int m_ZOrder`
- `bool m_noElasticity`
- `cocos2d::ccColor3B m_color2`
- `ButtonSprite* m_button1`
- `ButtonSprite* m_button2`
- `ScrollingLayer* m_scrollingLayer`
- `int m_controlConnected`
- `bool m_containsBorder`
- `bool m_noAction`
- `int m_joystickConnected`
- `bool m_forcePrioRegistered`

### `FLAlertLayerProtocol`

**Functions:**

- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`

### `FMODAudioEngine` : cocos2d::CCNode

**Functions:**

- `FMODAudioEngine()`
- `~FMODAudioEngine()`
- `static FMODAudioEngine* get()`
- `static float pitchForIdx(int index)`
- `static gd::string reverbToString(FMODReverbPreset preset)`
- `static FMODAudioEngine* sharedEngine()`
- `virtual void update(float dt)`
- `void activateQueuedMusic(int channel)`
- `FMOD::Channel* channelForChannelID(int id)`
- `FMOD::Channel* channelForUniqueID(int id)`
- `int channelIDForUniqueID(int id)`
- `void channelLinkSound(int id, FMODSound* sound)`
- `void channelStopped(FMOD::Channel* channel, bool remove)`
- `void channelUnlinkSound(int id)`
- `void clearAllAudio()`
- `int countActiveEffects()`
- `int countActiveMusic()`
- `FMOD::Sound* createStream(gd::string path)`
- `void disableMetering()`
- `void enableMetering()`
- `void fadeInBackgroundMusic(float value)`
- `void fadeInMusic(float duration, int channel)`
- `void fadeMusic(float duration, int channel, float startVolume, float endVolume)`
- `void fadeOutMusic(float duration, int channel)`
- `gd::string getActiveMusic(int id)`
- `FMOD::Channel* getActiveMusicChannel(int musicID)`
- `float getBackgroundMusicVolume()`
- `FMOD::ChannelGroup* getChannelGroup(int id, bool reverb)`
- `float getEffectsVolume()`
- `gd::string getFMODStatus(int unused)`
- `float getMeteringValue()`
- `int getMusicChannelID(int musicID)`
- `unsigned int getMusicLengthMS(int channel)`
- `float getMusicTime(int channel)`
- `unsigned int getMusicTimeMS(int channel)`
- `int getNextChannelID()`
- `gd::map<std::pair<int, int>, FMODSoundTween>& getTweenContainer(AudioTargetType type)`
- `bool isAnyPersistentPlaying()`
- `bool isChannelStopping(int channel)`
- `bool isEffectLoaded(gd::string path)`
- `bool isMusicPlaying(int musicID)`
- `bool isMusicPlaying(gd::string path, int musicID)`
- `bool isPersistentMatchPlaying(gd::string path, int musicID)`
- `bool isSoundReady(FMOD::Sound* sound)`
- `int lengthForSound(gd::string path)`
- `void loadAndPlayMusic(gd::string path, unsigned int time, int musicID)`
- `void loadAudioState(FMODAudioState& state)`
- `void loadMusic(gd::string path)`
- `void loadMusic(gd::string path, float speed, float unknown, float volume, bool shouldLoop, int musicID, int channelID, bool dontReset)`
- `void pauseAllAudio()`
- `void pauseAllEffects()`
- `void pauseAllMusic(bool force)`
- `void pauseEffect(unsigned int effect)`
- `void pauseMusic(int musicChannel)`
- `int playEffect(gd::string path)`
- `int playEffect(gd::string path, float speed, float unknown, float volume)`
- `int playEffectAdvanced(gd::string path, float speed, float unknown, float volume, float pitch, bool fastFourierTransform, bool reverb, int startMillis, int endMillis, int fadeIn, int fadeOut, bool loopEnabled, int effectID, bool override, bool noPreload, int channelID, int uniqueID, float minInterval, int sfxGroup)`
- `int playEffectAsync(gd::string path)`
- `void playMusic(gd::string path, bool shouldLoop, float fadeInTime, int channel)`
- `FMODSound* preloadEffect(gd::string path)`
- `FMOD::Sound* preloadEffectAsync(gd::string path)`
- `FMOD::Sound* preloadMusic(gd::string path, bool noRelease, int musicID)`
- `void printResult(FMOD_RESULT result)`
- `void queuedEffectFinishedLoading(gd::string path)`
- `int queuePlayEffect(gd::string audioFilename, float speed, float unknown, float volume, float pitch, bool fastFourierTransform, bool reverb, int start, int end, int fadeIn, int fadeOut, bool loop, int effectID, bool override, int uniqueID, float minInterval, int group)`
- `void queueStartMusic(gd::string audioFilename, float pitch, float unknown, float volume, bool loop, int start, int end, int fadeIn, int fadeOut, int musicID, bool, int channelID, bool noPrepare, bool dontReset)`
- `int registerChannel(FMOD::Channel* channel, int channelID, int effectID)`
- `void releaseRemovedSounds()`
- `void resumeAllAudio()`
- `void resumeAllEffects()`
- `void resumeAllMusic()`
- `void resumeAudio()`
- `void resumeEffect(unsigned int effect)`
- `void resumeMusic(int musicChannel)`
- `void saveAudioState(FMODAudioState& state)`
- `void setBackgroundMusicVolume(float volume)`
- `void setChannelPitch(int id, AudioTargetType type, float pitch)`
- `void setChannelVolume(int id, AudioTargetType type, float volume)`
- `void setChannelVolumeMod(int id, AudioTargetType type, float volumeMod)`
- `void setEffectsVolume(float volume)`
- `void setMusicTimeMS(unsigned int time, bool dontWait, int musicID)`
- `void setup()`
- `void setupAudioEngine()`
- `void start()`
- `void startMusic(int start, int end, int fadeIn, int fadeOut, bool loop, int musicID, bool noResume, bool dontReset)`
- `void stop()`
- `void stopAllEffects()`
- `void stopAllMusic(bool clear)`
- `float stopAndGetFade(FMOD::Channel* channel)`
- `void stopAndRemoveMusic(int id)`
- `void stopChannel(int id)`
- `void stopChannel(FMOD::Channel* channel, bool loop, float delay)`
- `void stopChannel(int id, AudioTargetType type, bool loop, float delay)`
- `void stopChannelTween(int id, AudioTargetType target, AudioModType mod)`
- `void stopChannelTweens(int id, AudioTargetType target)`
- `void stopMusic(int id)`
- `void stopMusicNotInSet(gd::unordered_set<int>& musicIDs)`
- `FMODSound* storeEffect(FMOD::Sound* sound, gd::string path)`
- `void swapMusicIndex(int musicID, int channelID)`
- `void testFunction(int unknown)`
- `void triggerQueuedMusic(FMODQueuedMusic music)`
- `void unloadAllEffects()`
- `void unloadEffect(gd::string path)`
- `void unregisterChannel(int id)`
- `void updateBackgroundFade()`
- `void updateChannel(int channel, AudioTargetType target, AudioModType mod, float duration, float value)`
- `void updateChannelTweens(float dt)`
- `void updateMetering()`
- `void updateQueuedEffects()`
- `void updateQueuedMusic()`
- `void updateReverb(FMODReverbPreset preset, bool force)`
- `void updateTemporaryEffects()`
- `FMOD_OPENSTATE waitUntilSoundReady(FMOD::Sound* sound)`

**Members:**

- `gd::unordered_map<int, FMODMusic> m_fmodMusic`
- `gd::unordered_map<gd::string, FMODSound> m_fmodSounds`
- `gd::unordered_set<gd::string> m_temporarySoundPaths`
- `float m_musicVolume`
- `float m_sfxVolume`
- `float m_backgroundMusicFade`
- `float m_musicFadeStart`
- `float m_pulse1`
- `float m_pulse2`
- `float m_pulse3`
- `int m_pulseCounter`
- `bool m_metering`
- `FMOD::ChannelGroup* m_backgroundMusicChannel`
- `FMOD::System* m_system`
- `FMOD::DSP* m_mainDSP`
- `FMOD::DSP* m_globalChannelDSP`
- `FMOD::ChannelGroup* m_globalChannel`
- `FMOD::ChannelGroup* m_reverbChannel`
- `FMOD_RESULT m_lastResult`
- `int m_sampleRate`
- `bool m_reducedQuality`
- `bool m_allAudioPaused`
- `int m_musicOffset`
- `bool m_stopped`
- `FMODAudioState m_audioState`
- `gd::vector<FMOD::Sound*> m_removedSounds`
- `gd::unordered_map<int, FMOD::DSP*> m_channelIDToDSP`
- `gd::unordered_map<int, FMOD::Channel*> m_channelIDToChannel`
- `gd::unordered_set<int> m_stoppedChannels`
- `FMODReverbPreset m_reverbPreset`
- `gd::unordered_map<int, int> m_channelIDToEffectID`
- `gd::unordered_map<int, int> m_effectIDToChannelID`
- `gd::unordered_map<int, gd::string> m_channelIDToSoundPath`
- `gd::vector<FMODQueuedEffect> m_queuedEffects`
- `gd::unordered_map<gd::string, FMOD::Sound*> m_soundPathToSound`
- `gd::unordered_map<int, FMOD::ChannelGroup*> m_globalChannelGroups`
- `gd::unordered_map<int, FMOD::ChannelGroup*> m_reverbChannelGroups`
- `bool m_showAudioVisualizer`
- `float m_musicVisualizerTime`
- `float m_musicVisualizerPeak`
- `float m_musicVisualizerVolume`
- `float m_sfxVisualizerTime`
- `float m_sfxVisualizerPeak`
- `float m_sfxVisualizerVolume`

### `FMODAudioState`

**Functions:**

- `FMODAudioState()`

**Members:**

- `float m_interval`
- `float m_elapsed`
- `gd::map<std::pair<int,int>,FMODSoundTween> m_tweensForEffectChannels`
- `gd::map<std::pair<int,int>,FMODSoundTween> m_tweensForEffectGroups`
- `gd::map<std::pair<int,int>,FMODSoundTween> m_tweensForMusicChannels`
- `gd::unordered_map<int,float> m_volumeForEffectChannels`
- `gd::unordered_map<int,float> m_volumeModForEffectChannels`
- `gd::unordered_map<int,float> m_pitchForEffectChannels`
- `gd::unordered_map<int,float> m_volumeForEffectGroups`
- `gd::unordered_map<int,float> m_volumeModForEffectGroups`
- `gd::unordered_map<int,float> m_pitchForEffectGroups`
- `gd::unordered_map<int,float> m_volumeForMusicChannels`
- `gd::unordered_map<int,float> m_volumeModForMusicChannels`
- `gd::unordered_map<int,float> m_pitchForMusicChannels`
- `gd::unordered_map<int,float> m_intervalForEffects`
- `gd::unordered_map<int,FMODQueuedMusic> m_queuedMusicForChannels1`
- `gd::unordered_map<int,FMODQueuedMusic> m_queuedMusicForChannels2`
- `gd::unordered_map<int,FMODSoundState> m_soundStateForChannels`
- `uint64_t m_unkUint64_1`

### `FMODLevelVisualizer` : cocos2d::CCNode

**Functions:**

- `static FMODLevelVisualizer* create()`
- `virtual bool init()`
- `void updateVisualizer(float volume, float peak, float time)`

**Members:**

- `float m_width`

### `FMODMusic`

**Members:**

- `int m_channelID`
- `FMOD::Sound* m_sound`
- `gd::string m_filePath`
- `bool m_ogg`
- `bool m_dontReset`

### `FMODQueuedEffect`

**Members:**

- `gd::string m_filePath`
- `float m_speed`
- `float m_unk024`
- `float m_volume`
- `float m_pitch`
- `bool m_fastFourierTransform`
- `bool m_reverb`
- `int m_start`
- `int m_end`
- `int m_fadeIn`
- `int m_fadeOut`
- `bool m_loop`
- `int m_effectID`
- `bool m_override`
- `bool m_unk04d`
- `int m_channelID`
- `FMOD::Sound* m_sound`
- `int m_uniqueID`
- `int m_minInterval`
- `int m_group`

### `FRequestProfilePage` : FLAlertLayer, FLAlertLayerProtocol, UploadActionDelegate, UploadPopupDelegate, FriendRequestDelegate

**Functions:**

- `static FRequestProfilePage* create(bool sent)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void loadFRequestsFinished(cocos2d::CCArray* scores, char const* key)`
- `virtual void loadFRequestsFailed(char const* key, GJErrorCode errorType)`
- `virtual void setupPageInfo(gd::string info, char const* key)`
- `virtual void forceReloadRequests(bool sent)`
- `void deleteSelected()`
- `bool init(bool sent)`
- `bool isCorrect(char const* key)`
- `void loadPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDeleteSelected(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onSentRequests(cocos2d::CCObject* sender)`
- `void onToggleAllObjects(cocos2d::CCObject* sender)`
- `void onUpdate(cocos2d::CCObject* sender)`
- `void setupCommentsBrowser(cocos2d::CCArray* scores)`
- `void untoggleAll()`
- `void updateLevelsLabel()`
- `void updatePageArrows()`

**Members:**

- `bool m_sent`
- `gd::string m_key`
- `cocos2d::CCLabelBMFont* m_pageLabel`
- `cocos2d::CCLabelBMFont* m_errorLabel`
- `GJCommentListLayer* m_listLayer`
- `LoadingCircle* m_circle`
- `UploadActionPopup* m_uploadPopup`
- `void* m_unk2e8`
- `CCMenuItemSpriteExtra* m_nextButton`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_refreshButton`
- `int m_itemCount`
- `int m_pageStartIdx`
- `int m_pageEndIdx`
- `int m_page`
- `bool m_toggledAll`

### `FileOperation`

**Functions:**

- `static gd::string getFilePath()`
- `static void readFile()`
- `static void saveFile()`

### `FileSaveManager` : GManager

**Functions:**

- `static FileSaveManager* sharedState()`
- `virtual bool init()`
- `virtual void firstLoad()`
- `cocos2d::CCDictionary* getStoreData()`
- `void loadDataFromFile(char const* filename)`

**Members:**

- `cocos2d::CCDictionary* m_storeData`

### `FindBPMLayer` : CreateGuidelinesLayer

**Functions:**

- `static FindBPMLayer* create(int songID)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void playMusic()`
- `virtual void registerTouch()`
- `virtual void onInfo(cocos2d::CCObject* sender)`
- `virtual void onRecord(cocos2d::CCObject* sender)`
- `virtual void recordingDidStop()`
- `void calculateBPM()`
- `bool init(int songID)`

**Members:**

- `int m_songID`
- `cocos2d::CCLabelBMFont* m_bpmLabel`
- `float m_startOffset`
- `int m_beats`
- `int m_beatsPerMinute`

### `FindObjectPopup` : SetIDPopup

**Functions:**

- `FindObjectPopup()`
- `static FindObjectPopup* create()`
- `virtual bool init()`
- `void onFindObjectID(cocos2d::CCObject* sender)`

**Members:**

- `bool m_unknownBool`

### `FollowRewardPage` : FLAlertLayer, FLAlertLayerProtocol, GameRateDelegate, RewardedVideoDelegate

**Functions:**

- `static FollowRewardPage* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void rewardedVideoFinished()`
- `virtual void updateRate()`
- `void onClose(cocos2d::CCObject* sender)`
- `void onRewardedVideo(cocos2d::CCObject* sender)`
- `void onSpecialItem(cocos2d::CCObject* sender)`
- `void switchToOpenedState(CCMenuItemSpriteExtra* button)`

**Members:**

- `cocos2d::CCArray* m_chests`
- `bool m_videoPlaying`

### `FontObject` : cocos2d::CCObject

**Functions:**

- `FontObject()`
- `static FontObject* createWithConfigFile(char const* font, float scale)`
- `int getFontWidth(int character)`
- `bool initWithConfigFile(char const* font, float scale)`
- `void parseConfigFile(char const* font, float scale)`

**Members:**

- `std::array<int, 300> m_fontWidths`

### `ForceBlockGameObject` : EffectGameObject

**Functions:**

- `ForceBlockGameObject()`
- `static ForceBlockGameObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `cocos2d::CCPoint calculateForceToTarget(GameObject* target)`
- `bool init(char const* frame)`

**Members:**

- `float m_force`
- `float m_minForce`
- `float m_maxForce`
- `bool m_relativeForce`
- `bool m_forceRange`
- `int m_forceID`

### `FriendRequestDelegate`

**Functions:**

- `virtual void loadFRequestsFinished(cocos2d::CCArray* scores, char const* key)`
- `virtual void loadFRequestsFailed(char const* key, GJErrorCode errorType)`
- `virtual void setupPageInfo(gd::string info, char const* key)`
- `virtual void forceReloadRequests(bool sent)`

### `FriendRequestPopup` : FLAlertLayer, UploadActionDelegate, UploadPopupDelegate, FLAlertLayerProtocol

**Functions:**

- `static FriendRequestPopup* create(GJFriendRequest* request)`
- `virtual void keyBackClicked()`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void blockUser()`
- `bool init(GJFriendRequest* request)`
- `void loadFromGJFriendRequest(GJFriendRequest* request)`
- `void onAccept(cocos2d::CCObject* sender)`
- `void onBlock(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onRemove(cocos2d::CCObject* sender)`

**Members:**

- `void* m_unk`
- `GJFriendRequest* m_request`
- `LoadingCircle* m_circle`
- `CCMenuItemSpriteExtra* m_closeBtn`
- `UploadActionPopup* m_popup`

### `FriendsProfilePage` : FLAlertLayer, FLAlertLayerProtocol, UploadActionDelegate, UploadPopupDelegate, UserListDelegate

**Functions:**

- `static FriendsProfilePage* create(UserListType type)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void getUserListFinished(cocos2d::CCArray* scores, UserListType type)`
- `virtual void getUserListFailed(UserListType type, GJErrorCode errorType)`
- `virtual void userListChanged(cocos2d::CCArray* scores, UserListType type)`
- `virtual void forceReloadList(UserListType type)`
- `bool init(UserListType type)`
- `void onBlocked(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onUpdate(cocos2d::CCObject* sender)`
- `void setupUsersBrowser(cocos2d::CCArray* users, UserListType type)`

**Members:**

- `UserListType m_type`
- `cocos2d::CCLabelBMFont* m_noInternet`
- `cocos2d::CCLabelBMFont* m_totalFriends`
- `GJCommentListLayer* m_listLayer`
- `LoadingCircle* m_circle`
- `void* m_unk532`
- `cocos2d::CCArray* m_users`
- `CCMenuItemSpriteExtra* m_refreshBtn`

### `GJAccountBackupDelegate`

**Functions:**

- `virtual void backupAccountFinished()`
- `virtual void backupAccountFailed(BackupAccountError errorType, int response)`

### `GJAccountDelegate`

**Functions:**

- `virtual void accountStatusChanged()`

### `GJAccountLoginDelegate`

**Functions:**

- `virtual void loginAccountFinished(int accountID, int userID)`
- `virtual void loginAccountFailed(AccountError errorType)`

### `GJAccountManager` : cocos2d::CCNode

**Functions:**

- `static GJAccountManager* get()`
- `static GJAccountManager* sharedState()`
- `virtual bool init()`
- `void addDLToActive(char const* tag)`
- `void addDLToActive(char const* tag, cocos2d::CCObject* object)`
- `bool backupAccount(gd::string url)`
- `void dataLoaded(DS_Dictionary* dict)`
- `void encodeDataTo(DS_Dictionary* dict)`
- `void firstSetup()`
- `bool getAccountBackupURL()`
- `bool getAccountSyncURL()`
- `cocos2d::CCObject* getDLObject(char const* tag)`
- `gd::string getShaPassword(gd::string password)`
- `void handleIt(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItND(cocos2d::CCNode* node, void* data)`
- `bool isDLActive(char const* tag)`
- `void linkToAccount(gd::string username, gd::string gjp2, int accountID, int userID)`
- `void loginAccount(gd::string username, gd::string gjp2)`
- `void onBackupAccountCompleted(gd::string response, gd::string tag)`
- `void onGetAccountBackupURLCompleted(gd::string response, gd::string tag)`
- `void onGetAccountSyncURLCompleted(gd::string response, gd::string tag)`
- `void onLoginAccountCompleted(gd::string response, gd::string tag)`
- `void onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onRegisterAccountCompleted(gd::string response, gd::string tag)`
- `void onSyncAccountCompleted(gd::string response, gd::string tag)`
- `void onUpdateAccountSettingsCompleted(gd::string response, gd::string tag)`
- `void ProcessHttpRequest(gd::string url, gd::string params, gd::string tag, GJHttpType type)`
- `void registerAccount(gd::string response, gd::string tag, gd::string data)`
- `void removeDLFromActive(char const* tag)`
- `bool syncAccount(gd::string url)`
- `void unlinkFromAccount()`
- `bool updateAccountSettings(int messageStatus, int friendRequestStatus, int commentStatus, gd::string youtube, gd::string twitter, gd::string twitch, gd::string instagram, gd::string tiktok, gd::string discord, gd::string custom)`

**Members:**

- `cocos2d::CCDictionary* m_activeDownloads`
- `gd::string m_username`
- `int m_accountID`
- `int m_unkInt1; // likely VRS for account ID but unimplemented`
- `int m_unkInt2; // likely VRS for account ID but unimplemented`
- `gd::string m_GJP2`
- `GJAccountRegisterDelegate* m_accountRegisterDelegate`
- `GJAccountLoginDelegate* m_accountLoginDelegate`
- `GJAccountDelegate* m_accountDelegate`
- `GJAccountBackupDelegate* m_backupDelegate`
- `GJAccountSyncDelegate* m_syncDelegate`
- `GJAccountSettingsDelegate* m_accountSettingsDelegate`
- `int m_gameManagerSize`
- `int m_localLevelsSize`
- `gd::string m_password`

### `GJAccountRegisterDelegate`

**Functions:**

- `virtual void registerAccountFinished()`
- `virtual void registerAccountFailed(AccountError errorType)`

### `GJAccountSettingsDelegate`

**Functions:**

- `virtual void updateSettingsFinished()`
- `virtual void updateSettingsFailed()`

### `GJAccountSettingsLayer` : FLAlertLayer, TextInputDelegate

**Functions:**

- `GJAccountSettingsLayer()`
- `~GJAccountSettingsLayer()`
- `static GJAccountSettingsLayer* create(int accountID)`
- `virtual void keyBackClicked()`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `void closeAccInputNodes(cocos2d::CCArray* nodes)`
- `CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position, float width, float scale)`
- `bool init(int accountID)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCommentSetting(cocos2d::CCObject* sender)`
- `void onFriendRequests(cocos2d::CCObject* sender)`
- `void onMessageSetting(cocos2d::CCObject* sender)`
- `void onUpdate(cocos2d::CCObject* sender)`
- `void updateScoreValues()`

**Members:**

- `int m_accountID`
- `int m_messageStatus`
- `int m_friendStatus`
- `int m_commentHistoryStatus`
- `cocos2d::CCArray* m_inputs`
- `gd::map<int, gd::string> m_links`
- `cocos2d::CCArray* m_messageSettings`
- `cocos2d::CCArray* m_friendRequestSettings`
- `cocos2d::CCArray* m_commentSettings`

### `GJAccountSyncDelegate`

**Functions:**

- `virtual void syncAccountFinished()`
- `virtual void syncAccountFailed(BackupAccountError errorType, int response)`

### `GJActionManager` : cocos2d::CCNode

**Functions:**

- `GJActionManager()`
- `~GJActionManager()`
- `static GJActionManager* create()`
- `virtual bool init()`
- `cocos2d::CCAction* getInternalAction(int id)`
- `void runInternalAction(cocos2d::CCAction* action, cocos2d::CCNode* target)`
- `void stopAllInternalActions()`
- `void stopInternalAction(int id)`
- `void updateInternalActions(float dt, bool remove)`

**Members:**

- `cocos2d::CCDictionary* m_internalActions`

### `GJAssetDownloadAction`

**Members:**

- `int m_id`
- `GJAssetType m_assetType`
- `int m_status`

### `GJBaseGameLayer` : cocos2d::CCLayer, TriggerEffectDelegate

**Functions:**

- `GJBaseGameLayer()`
- `~GJBaseGameLayer()`
- `static float convertToClosestDirection(float angle, float bound)`
- `static gd::string gameEventToString(GJGameEvent event)`
- `static GJBaseGameLayer* get()`
- `virtual void update(float dt)`
- `virtual bool init()`
- `virtual void visit()`
- `virtual void postUpdate(float dt)`
- `virtual void checkForEnd()`
- `virtual void testTime()`
- `virtual void updateVerifyDamage()`
- `virtual void updateAttemptTime(float attemptTime)`
- `virtual void updateVisibility(float dt)`
- `virtual void playerTookDamage(PlayerObject* player)`
- `virtual float opacityForObject(GameObject* object)`
- `virtual void addToSpeedObjects(EffectGameObject* object)`
- `virtual void objectsCollided(int blockAID, int blockBID)`
- `virtual void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2)`
- `virtual void toggleGroupTriggered(int group, bool activate, gd::vector<int> const& remapKeys, int triggerID, int controlID)`
- `[[missing(win, mac)]]`
- `virtual bool checkSpawnAbuse()`
- `virtual void spawnGroup(int group, bool ordered, double delay, gd::vector<int> const& remapKeys, int triggerID, int controlID)`
- `virtual void spawnObject(GameObject* object, double delay, gd::vector<int> const& remapKeys)`
- `virtual void activateEndTrigger(int targetID, bool reverse, bool lockPlayerY)`
- `virtual void activatePlatformerEndTrigger(EndTriggerGameObject* object, gd::vector<int> const& remapKeys)`
- `virtual void toggleGlitter(bool visible)`
- `virtual void destroyPlayer(PlayerObject* player, GameObject* object)`
- `virtual void updateDebugDraw()`
- `virtual void addToSection(GameObject* object)`
- `virtual void addToGroup(GameObject* object, int groupID, bool triggerGroup)`
- `virtual void removeFromGroup(GameObject* object, int groupID)`
- `virtual void updateObjectSection(GameObject* object)`
- `virtual void updateDisabledObjectsLastPos(cocos2d::CCArray* objects)`
- `virtual void toggleGroundVisibility(bool visible)`
- `virtual void toggleMGVisibility(bool visible)`
- `virtual void toggleHideAttempts(bool hide)`
- `virtual float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id)`
- `virtual cocos2d::CCPoint posForTime(float time)`
- `virtual void resetSPTriggered()`
- `virtual void updateScreenRotation(float rotation, bool add, bool convert, float duration, int easingType, float easingRate, int uniqueID, int controlID)`
- `virtual void reverseDirection(EffectGameObject* object)`
- `virtual void rotateGameplay(RotateGameplayGameObject* object)`
- `virtual void didRotateGameplay()`
- `virtual void updateTimeWarp(float timeWarp)`
- `virtual void applyTimeWarp(float timeWarp)`
- `virtual void playGravityEffect(bool flip)`
- `virtual void manualUpdateObjectColors(GameObject* object)`
- `virtual cocos2d::CCParticleSystemQuad* createCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int minimum, bool dontAdd)`
- `virtual cocos2d::CCParticleSystemQuad* claimCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int zLayer, int zOrder, int uiObject, bool dontAdd)`
- `virtual void unclaimCustomParticle(gd::string const& key, cocos2d::CCParticleSystemQuad* particle)`
- `virtual void activatedAudioTrigger(SFXTriggerGameObject* object)`
- `virtual void checkpointActivated(CheckpointGameObject* object)`
- `virtual void flipArt(bool flip)`
- `virtual void addKeyframe(KeyframeGameObject* object)`
- `virtual void updateTimeLabel(int seconds, int centiseconds, bool decimals)`
- `virtual void checkSnapshot()`
- `virtual void toggleProgressbar()`
- `virtual void toggleInfoLabel()`
- `virtual void removeAllCheckpoints()`
- `virtual void toggleMusicInPractice()`
- `virtual void processCheckpoints()`
- `virtual void resetLevel()`
- `void activateCustomRing(RingObject* object)`
- `void activatedAudioTrigger(SFXTriggerGameObject* object, float levelTime)`
- `void activateEventTrigger(EventLinkTrigger* object, gd::vector<int> const& remapKeys)`
- `void activateItemCompareTrigger(ItemTriggerGameObject* object, gd::vector<int> const& remapKeys)`
- `void activateItemEditTrigger(ItemTriggerGameObject* object)`
- `void activateObjectControlTrigger(ObjectControlGameObject* object)`
- `void activatePersistentItemTrigger(ItemTriggerGameObject* object)`
- `void activatePlayerControlTrigger(PlayerControlGameObject* object)`
- `void activateResetTrigger(EffectGameObject* object)`
- `void activateSFXEditTrigger(SFXTriggerGameObject* object)`
- `void activateSFXTrigger(SFXTriggerGameObject* object)`
- `void activateSongEditTrigger(SongTriggerGameObject* object)`
- `void activateSongTrigger(SongTriggerGameObject* object)`
- `void activateTimerTrigger(TimerTriggerGameObject* object, gd::vector<int> const& remapKeys)`
- `void addAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJAreaActionType type)`
- `void addCustomEnterEffect(EnterEffectObject* object, bool enter)`
- `bool addGuideArt(GameObject* object)`
- `void addObjectCounter(LabelGameObject* object)`
- `void addPickupTrigger(CountTriggerGameObject* object)`
- `void addPoints(int points)`
- `void addProximityVolumeEffect(int channelID, int targetType, SFXTriggerGameObject* object)`
- `void addRemapTargets(gd::set<int>& targets)`
- `void addToGroupParents(GameObject* object)`
- `void addToGroups(GameObject* object, bool duplicateTrigger)`
- `void addToObjectsToShow(GameObject* object)`
- `void addUIObject(GameObject* object)`
- `void animateInDualGroundNew(GameObject* object, float height, bool instant, float duration)`
- `void animateInGroundNew(bool unk1, float unk2, bool unk3)`
- `void animateOutGroundNew(bool instant)`
- `void animatePortalY(float fromY, float toY, float duration, float easingRate)`
- `void applyLevelSettings(GameObject* object)`
- `void applyRemap(EffectGameObject* object, gd::vector<int> const& remapKeys, gd::unordered_map<int, int>& remap)`
- `void applySFXEditTrigger(int channelID, int targetType, SFXTriggerGameObject* object)`
- `void applyShake(cocos2d::CCPoint& point)`
- `void assignNewStickyGroups(cocos2d::CCArray* objects)`
- `void asyncBGLoaded(int background)`
- `void asyncGLoaded(int ground)`
- `void asyncMGLoaded(int middleground)`
- `int atlasValue(int atlas)`
- `void bumpPlayer(PlayerObject* player, EffectGameObject* object)`
- `int buttonIDToButton(int id)`
- `bool buttonIsRelevant(PlayerButtonCommand const& button)`
- `void calculateColorGroups()`
- `void cameraMoveX(float value, float duration, float rate, bool unused)`
- `void cameraMoveY(float value, float duration, float rate, bool force)`
- `bool canBeActivatedByPlayer(PlayerObject* player, EffectGameObject* object)`
- `bool canProcessSFX(SFXTriggerState& state, gd::unordered_map<int, int>& stateIndices, gd::unordered_map<int, float>& times, gd::vector<SFXTriggerState>& states)`
- `bool canTouchObject(GameObject* object)`
- `void checkCameraLimitAfterTeleport(PlayerObject* player, float yOffset)`
- `bool checkCollision(int blockAID, int blockBID)`
- `void checkCollisionBlocks(EffectGameObject* object, gd::vector<EffectGameObject*>* blocks, int blockCount)`
- `int checkCollisions(PlayerObject* object, float dt, bool ignoreDamage)`
- `void checkRepellPlayer()`
- `void checkSpawnObjects()`
- `cocos2d::CCPoint claimMoveAction(int groupID, bool ignoreStaticGroups)`
- `cocos2d::CCParticleSystemQuad* claimParticle(gd::string key, int zLayer)`
- `void claimRotationAction(int targetID, int centerID, float& rotation, float& offset, bool ignoreStaticGroups, bool unused)`
- `void clearActivatedAudioTriggers()`
- `void clearPickedUpItems()`
- `void collectedObject(EffectGameObject* object)`
- `void collisionCheckObjects(PlayerObject* object, gd::vector<GameObject*>* objects, int objectCount, float dt)`
- `void controlAdvancedFollowCommand(AdvancedFollowTriggerObject* object, int controlID, GJActionCommand command)`
- `void controlAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJActionCommand command)`
- `void controlAreaEffectWithID(int uniqueID, int controlID, GJActionCommand command)`
- `void controlDynamicCommand(EffectGameObject* object, int controlID, gd::vector<DynamicObjectAction>& actions, GJActionCommand command)`
- `void controlDynamicMoveCommand(EffectGameObject* object, int controlID, GJActionCommand command)`
- `void controlDynamicRotateCommand(EffectGameObject* object, int controlID, GJActionCommand command)`
- `void controlEventLink(int uniqueID, int controlID, GJActionCommand command)`
- `void controlGradientTrigger(GradientTriggerObject* object, GJActionCommand command)`
- `void controlTriggersInGroup(int group, GJActionCommand command)`
- `void controlTriggersWithControlID(int controlID, GJActionCommand command)`
- `int countCollectedUserCoins()`
- `void createBackground(int background)`
- `void createGroundLayer(int ground, int line)`
- `void createMiddleground(int middleground)`
- `cocos2d::CCArray* createNewKeyframeAnim()`
- `cocos2d::CCParticleSystemQuad* createParticle(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType)`
- `void createPlayer()`
- `void createPlayerCollisionBlock()`
- `void createTextLayers()`
- `cocos2d::CCArray* damagingObjectsInRect(cocos2d::CCRect rect, bool enabledGroups)`
- `void destroyObject(GameObject* object)`
- `void enterDualMode(GameObject* object, bool unused)`
- `void exitStaticCamera(bool exitX, bool exitY, float time, int easingType, float easingRate, bool smoothVelocity, float smoothVelocityMod, bool exitInstant)`
- `void flipFinished()`
- `void flipGravity(PlayerObject* object, bool flip, bool noEffects)`
- `void flipObjects()`
- `void gameEventTriggered(GJGameEvent event, int material, int playerID)`
- `int generateEnterEasingBuffer(int easingType, float easingRate)`
- `void generateEnterEasingBuffers(EnterEffectObject* object)`
- `void generatePickupAnimRandVal(GameObject* object, float& randomValue1, float& randomValue2)`
- `void generateSpawnRemap()`
- `void generateTargetGroups()`
- `void generateVisibilityGroups()`
- `cocos2d::CCArray* getActiveOrderSpawnObjects()`
- `float getAreaObjectValue(EnterEffectInstance* instance, GameObject* object, cocos2d::CCPoint& position, bool& show)`
- `float getBumpMod(PlayerObject* player, int type)`
- `float getCameraEdgeValue(int type)`
- `gd::string getCapacityString()`
- `GameObject* getCenterGroupObject(int groupID, int defaultID)`
- `gd::vector<EnterEffectInstance>* getCustomEnterEffects(int id, bool enter)`
- `float getEasedAreaValue(GameObject* object, EnterEffectInstance* instance, float value, bool show, int index)`
- `int getEnterEasingKey(int easingType, float easingRate)`
- `float getEnterEasingValue(float value, int easingType, float easingRate, int easingBuffer)`
- `cocos2d::CCPoint getFollowSpeedVal(GameObject* object, int startSpeedRef, int startDirRef, float startDir, float startSpeed)`
- `float getGroundHeight(PlayerObject* player, int type)`
- `float getGroundHeightForMode(int type)`
- `cocos2d::CCArray* getGroup(int id)`
- `GameObject* getGroupParent(int groupId)`
- `gd::string getGroupParentsString(GameObject* object)`
- `double getItemValue(int type, int id)`
- `float getMaxPortalY()`
- `float getMinDistance(cocos2d::CCPoint position, cocos2d::CCArray* objects, float minNear, int mode)`
- `float getMinPortalY()`
- `double getModifiedDelta(float dt)`
- `cocos2d::CCPoint getMoveTargetDelta(EffectGameObject* object, bool mainObject)`
- `cocos2d::CCArray* getOptimizedGroup(int groupID)`
- `PlayerObject* getOtherPlayer(PlayerObject* player)`
- `gd::string getParticleKey(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType)`
- `gd::string getParticleKey2(gd::string key)`
- `int getPlayerButtonID(int button, bool player2)`
- `int getPlayTimerFullSeconds()`
- `int getPlayTimerMilli()`
- `TeleportPortalObject* getPortalTarget(TeleportPortalObject* object)`
- `cocos2d::CCPoint getPortalTargetPos(TeleportPortalObject* object, GameObject* target, PlayerObject* player)`
- `gd::string getRecordExtra()`
- `gd::string getRecordString(bool compress)`
- `void getRotateCommandTargets(EnhancedTriggerObject* object, GameObject*& centerObject, GameObject*& targetObject, GameObject*& rotateObject)`
- `cocos2d::CCPoint getSavedPosition(int groupID, float delay)`
- `float getScaledGroundHeight(float height)`
- `GameObject* getSingleGroupObject(int groupID)`
- `int getSpecialKey(int groupID, bool ignoreGroupParent, bool ignoreLinkedObjects)`
- `cocos2d::CCArray* getStaticGroup(int groupID)`
- `cocos2d::CCArray* getStickyGroup(int group)`
- `float getTargetFlyCameraY(GameObject* object)`
- `cocos2d::CCArray* getTargetGroup(int index, int uniqueID)`
- `cocos2d::CCArray* getTargetGroupOrigin(int index, int uniqueID)`
- `void gravBumpPlayer(PlayerObject* player, EffectGameObject* object)`
- `void groupStickyObjects(cocos2d::CCArray* objects)`
- `void handleButton(bool down, int button, bool isPlayer1)`
- `bool hasItem(int id)`
- `bool hasUniqueCoin(EffectGameObject* object)`
- `void increaseBatchNodeCapacity()`
- `[[missing(win, mac)]]`
- `bool isButtonAllowed(bool down, int button, bool isPlayer1)`
- `bool isFlipping()`
- `bool isPlayer2Button(int button)`
- `void lightningFlash(cocos2d::CCPoint to, cocos2d::ccColor3B color)`
- `void lightningFlash(cocos2d::CCPoint from, cocos2d::CCPoint to, cocos2d::ccColor3B color, float lineWidth, float duration, int displacement, bool flash, float opacity)`
- `void loadGroupParentsFromString(GameObject* object, gd::string groupList)`
- `void loadLevelSettings()`
- `void loadStartPosObject()`
- `void loadUpToPosition(float position, int order, int channel)`
- `int maxZOrderForShaderZ(int zLayer)`
- `int minZOrderForShaderZ(int zLayer)`
- `void modifyGroupPhysics(AdvancedFollowEditObject* object, cocos2d::CCArray* group)`
- `void modifyObjectPhysics(AdvancedFollowEditObject* object, GameObjectPhysics& physics)`
- `void moveAreaObject(GameObject* object, float dx, float dy)`
- `void moveCameraToPos(cocos2d::CCPoint pos)`
- `void moveObject(GameObject* object, double dx, double dy, bool lockPlayerY)`
- `void moveObjects(cocos2d::CCArray* objects, double dx, double dy, bool lockPlayerY)`
- `void moveObjectsSilent(int groupId, double dx, double dy)`
- `void moveObjectToStaticGroup(GameObject* object)`
- `bool objectIntersectsCircle(GameObject* object, GameObject* circle)`
- `GJGameEvent objectTypeToGameEvent(int type)`
- `void optimizeMoveGroups()`
- `void orderSpawnObjects()`
- `cocos2d::CCNode* parentForZLayer(int zLayer, bool blending, int parentMode, int uiObject)`
- `void pauseAudio()`
- `double performMathOperation(double operand1, double operand2, int operation)`
- `double performMathRounding(double value, int type)`
- `void pickupItem(EffectGameObject* object)`
- `void playAnimationCommand(int id, int groupID)`
- `bool playerCircleCollision(PlayerObject* player, GameObject* object)`
- `bool playerIntersectsCircle(PlayerObject* player, GameObject* object)`
- `void playerTouchedObject(PlayerObject* player, GameObject* object)`
- `void playerTouchedRing(PlayerObject* player, RingObject* object)`
- `void playerTouchedTrigger(PlayerObject* player, EffectGameObject* object)`
- `bool playerWasTouchingObject(PlayerObject* player, GameObject* object)`
- `void playerWillSwitchMode(PlayerObject* player, GameObject* object)`
- `void playExitDualEffect(PlayerObject* player)`
- `void playFlashEffect(float duration, int flashes, float unknown)`
- `void playKeyframeAnimation(KeyframeAnimTriggerObject* object, gd::vector<int> const& remapKeys)`
- `void playSpeedParticle(float timeMod)`
- `cocos2d::CCPoint positionForShaderTarget(int groupID)`
- `void positionUIObjects()`
- `void prepareSavePositionObjects()`
- `void prepareTransformParent(bool rotateNode)`
- `void preResumeGame()`
- `void preUpdateVisibility(float dt)`
- `void processActivatedAudioTriggers(float levelTime)`
- `void processAdvancedFollowAction(AdvancedFollowInstance& instance, bool started, float dt)`
- `void processAdvancedFollowActions(float dt)`
- `void processAreaActions(float dt, bool visibleFrame)`
- `void processAreaEffects(gd::vector<EnterEffectInstance>* effects, GJAreaActionType type, float dt, bool visibleFrame)`
- `void processAreaFadeGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups)`
- `void processAreaMoveGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset)`
- `void processAreaRotateGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset)`
- `void processAreaTintGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups)`
- `void processAreaTransformGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset)`
- `void processAreaVisualActions(float dt)`
- `GameObject* processCameraObject(GameObject* object, PlayerObject* player)`
- `void processCommands(float dt, bool isHalfTick, bool isLastTick)`
- `void processDynamicObjectActions(int type, float dt)`
- `void processFollowActions()`
- `void processItems()`
- `void processMoveActions()`
- `void processMoveActionsStep(float dt, bool visibleFrame)`
- `void processOptionsTrigger(GameOptionsTrigger* object)`
- `void processPlayerFollowActions(float dt)`
- `void processQueuedAudioTriggers()`
- `void processQueuedButtons(float dt, bool clearInputQueue)`
- `void processReplayCheckpoint(int id)`
- `void processRotationActions()`
- `void processSFXObjects()`
- `void processSFXState(SFXTriggerState* state1, SFXTriggerState* state2, int type, float levelTime)`
- `bool processSongState(int musicID, float spawnDelay, float levelTime, int songOffset, float volume, float speed, gd::vector<SongTriggerState>* states, SongTriggerGameObject* object)`
- `void processStateObjects()`
- `void processTransformActions(bool visibleFrame)`
- `void queueButton(int button, bool push, bool isPlayer2, double timestamp)`
- `void queueTimeWarp(float timeWarp)`
- `void reAddToStickyGroup(GameObject* object)`
- `void recordAction(int button, bool down, bool player2)`
- `bool rectIntersectsCircle(cocos2d::CCRect rect, cocos2d::CCPoint center, float radius)`
- `void refreshCounterLabels()`
- `void refreshKeyframeAnims()`
- `void regenerateEnterEasingBuffers()`
- `int registerSpawnRemap(gd::vector<ChanceObject>& spawnRemap)`
- `void registerStateObject(EffectGameObject* object)`
- `void removeBackground()`
- `void removeCustomEnterEffects(int id, bool enter)`
- `void removeFromGroupParents(GameObject* object)`
- `void removeFromGroups(GameObject* object)`
- `void removeFromStickyGroup(GameObject* object)`
- `void removeGroundLayer()`
- `void removeGroupParent(int groupID)`
- `void removeKeyframe(KeyframeGameObject* object)`
- `void removeMiddleground()`
- `void removeObjectFromSection(GameObject* object)`
- `void removePlayer2()`
- `void removeReleasedButtons()`
- `void removeTemporaryParticles()`
- `void reorderObjectSection(GameObject* object)`
- `void reparentObject(cocos2d::CCNode* node, cocos2d::CCNode* parent)`
- `void resetActiveEnterEffects()`
- `bool resetAreaObjectValues(GameObject* object, bool update)`
- `void resetAudio()`
- `void resetCamera()`
- `void resetGradientLayers()`
- `void resetGroupCounters(bool reset)`
- `void resetLevelVariables()`
- `void resetMoveOptimizedValue()`
- `void resetPlayer()`
- `void resetRecord(int steps, bool noFullReset)`
- `void resetRecordFull()`
- `void resetSongTriggerValues()`
- `void resetSpawnChannelIndex()`
- `void resetStaticCamera(bool resetX, bool resetY)`
- `void resetStoppedAreaObjects()`
- `void restoreAllUIObjects()`
- `void restoreDefaultGameplayOffsetX()`
- `void restoreDefaultGameplayOffsetY()`
- `void restoreRemap(EffectGameObject* object, gd::unordered_map<int, int>& remap)`
- `void resumeAudio()`
- `void rotateAreaObjects(GameObject* object, cocos2d::CCArray* objects, float rotation, bool reset)`
- `void rotateObject(GameObject* object, float rotation)`
- `void rotateObjects(cocos2d::CCArray* objects, float rotation, cocos2d::CCPoint position, cocos2d::CCPoint offset, bool finished, bool unused)`
- `void setGroupParent(GameObject* object, int groupID)`
- `void setStartPosObject(StartPosObject* startPos)`
- `void setupLayers()`
- `void setupLevelStart(LevelSettingsObject* settings)`
- `void setupReplay(gd::string inputs)`
- `void shakeCamera(float duration, float strength, float interval)`
- `bool shouldExitHackedLevel()`
- `bool shouldUseSubstepForButton(float dt)`
- `void sortAllGroupsX()`
- `void sortGroups()`
- `void sortSectionVector()`
- `void sortStickyGroups()`
- `void spawnGroupTriggered(int targetID, float delay, bool spawnOrdered, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void spawnObjectsInOrder(cocos2d::CCArray* objects, double delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `cocos2d::CCParticleSystemQuad* spawnParticle(char const* plist, int zOrder, cocos2d::tCCPositionType positionType, cocos2d::CCPoint position)`
- `void spawnParticleTrigger(SpawnParticleGameObject* object)`
- `void spawnParticleTrigger(int particleID, cocos2d::CCPoint position, float rotation, float scale)`
- `void spawnPlayer2()`
- `cocos2d::CCPoint speedForShaderTarget(int groupID)`
- `cocos2d::CCArray* staticObjectsInRect(cocos2d::CCRect rect, bool enabledGroups)`
- `void stopAllGroundActions()`
- `void stopCameraShake()`
- `void stopCustomEnterEffect(EnterEffectObject* object)`
- `void stopCustomEnterEffect(EnterEffectObject* object, bool enter)`
- `void stopSFXTrigger(SFXTriggerGameObject* object)`
- `void swapBackground(int background)`
- `void swapGround(int ground)`
- `void swapMiddleground(int middleground)`
- `void switchToFlyMode(PlayerObject* player, GameObject* object, bool noPortal, int type)`
- `void switchToRobotMode(PlayerObject* player, GameObject* object, bool noPortal)`
- `void switchToRollMode(PlayerObject* player, GameObject* object, bool noPortal)`
- `void switchToSpiderMode(PlayerObject* player, GameObject* object, bool noPortal)`
- `void syncBGTextures()`
- `void teleportPlayer(TeleportPortalObject* object, PlayerObject* player)`
- `void testInstantCountTrigger(int itemID, int compareCount, int groupID, bool activateGroup, int triggerMode, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void toggleAudioVisualizer(bool visible)`
- `void toggleDualMode(GameObject* object, bool dual, PlayerObject* player, bool noEffects)`
- `void toggleFlipped(bool flip, bool noEffects)`
- `void toggleGroup(int id, bool activate)`
- `void toggleLockPlayer(bool disable, bool player2)`
- `void togglePlayerStreakBlend(bool blend, bool force)`
- `void togglePlayerVisibility(bool visible)`
- `void togglePlayerVisibility(bool visible, bool player1)`
- `void transformAreaObjects(GameObject* object, cocos2d::CCArray* objects, float scaleX, float scaleY, bool reset)`
- `void triggerAdvancedFollowCommand(AdvancedFollowTriggerObject* object)`
- `void triggerAdvancedFollowEditCommand(AdvancedFollowEditObject* object)`
- `void triggerAreaEffect(EnterEffectObject* object)`
- `void triggerAreaEffectAnimation(EnterEffectObject* object)`
- `void triggerDynamicMoveCommand(EffectGameObject* object)`
- `void triggerDynamicRotateCommand(EnhancedTriggerObject* object)`
- `void triggerGradientCommand(GradientTriggerObject* object)`
- `void triggerGravityChange(EffectGameObject* object, int playerID)`
- `void triggerMoveCommand(EffectGameObject* object)`
- `void triggerRotateCommand(EnhancedTriggerObject* object)`
- `void triggerShaderCommand(ShaderGameObject* object)`
- `void triggerTransformCommand(TransformTriggerGameObject* object)`
- `GameObject* tryGetGroupParent(int groupID)`
- `GameObject* tryGetMainObject(int groupID)`
- `GameObject* tryGetObject(int groupID)`
- `void tryResumeAudio()`
- `void unclaimParticle(char const* key, cocos2d::CCParticleSystemQuad* particle)`
- `void ungroupStickyObjects(cocos2d::CCArray* objects)`
- `void unlinkAllEvents()`
- `void updateActiveEnterEffect(EnterEffectObject* object)`
- `void updateAllObjectSection()`
- `void updateAreaObjectLastValues(GameObject* object)`
- `void updateAudioVisualizer()`
- `void updateBGArtSpeed(float modX, float modY)`
- `void updateCamera(float dt)`
- `void updateCameraBGArt(cocos2d::CCPoint position, float zoom)`
- `void updateCameraEdge(int direction, int value)`
- `void updateCameraMode(EffectGameObject* obj, bool updateDual)`
- `void updateCameraOffsetX(float offsetX, float duration, int easingType, float easingRate, int uniqueID, int controlID)`
- `void updateCameraOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID)`
- `void updateCollisionBlocks()`
- `void updateCounters(int itemId, int value)`
- `void updateDualGround(PlayerObject* object, int mode, bool instant, float duration)`
- `void updateEnterEffects(float dt)`
- `void updateExtendedCollision(GameObject* object, bool extendedCollision)`
- `void updateExtraGameLayers()`
- `void updateGameplayOffsetX(int offsetX, bool staticOffset)`
- `void updateGameplayOffsetY(int offsetY, bool staticOffset)`
- `void updateGradientLayers()`
- `void updateGroundShadows()`
- `void updateGuideArt()`
- `void updateInternalCamOffsetX(float offsetX, float duration, float easingRate)`
- `void updateInternalCamOffsetY(float offsetY, float duration, float easingRate)`
- `void updateKeyframeOrder(int keyframeGroup)`
- `void updateLayerCapacity(gd::string capacityString)`
- `void updateLegacyLayerCapacity(int front, int frontBlend, int back, int backBlend)`
- `void updateLevelColors()`
- `void updateMaxGameplayY()`
- `void updateMGArtSpeed(float modX, float modY)`
- `void updateMGOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID)`
- `void updateOBB2(cocos2d::CCRect rect)`
- `void updateParticles(float dt)`
- `void updatePlatformerTime()`
- `void updatePlayerCollisionBlocks()`
- `void updateProximityVolumeEffects()`
- `void updateQueuedLabels()`
- `void updateReplay()`
- `void updateSavePositionObjects()`
- `void updateShaderLayer(float dt)`
- `void updateSpecialGroupData()`
- `void updateSpecialLabels()`
- `void updateStaticCameraPos(cocos2d::CCPoint pos, bool staticX, bool staticY, bool followOrSmoothEase, float time, int easingType, float easingRate)`
- `void updateStaticCameraPosToGroup(int centerID, bool updateX, bool updateY, bool followObject, float followEase, float duration, int easingType, float easingRate, bool smoothVelocity, float velocityMod)`
- `void updateTimeMod(float speed, bool players, bool noEffects)`
- `void updateTimerLabels()`
- `void updateZoom(float zoom, float duration, int easing, float rate, int uniqueID, int controlID)`
- `void visitWithColorFlash()`
- `float volumeForProximityEffect(SFXTriggerInstance& instance)`

**Members:**

- `PAD`
- `GJGameState m_gameState`
- `GJGameLevel* m_level`
- `PlaybackMode m_playbackMode`
- `bool m_lowDetailMode`
- `bool m_extraLDM`
- `bool m_ignoreDamage`
- `bool m_enable22Changes`
- `bool m_allowStaticRotate`
- `bool m_fixNegativeScale`
- `bool m_startingFromBeginning`
- `gd::vector<SFXTriggerGameObject*> m_activeSfxTriggers`
- `gd::vector<void*> m_unk8a0`
- `cocos2d::CCNode* m_hoverNode`
- `cocos2d::CCNode* m_areaTransformNode`
- `cocos2d::CCNode* m_areaSkewNode`
- `cocos2d::CCNode* m_areaScaleNode`
- `cocos2d::CCNode* m_areaRotateNode`
- `cocos2d::CCNode* m_areaTransformNode2`
- `OBB2D* m_obb2`
- `gd::vector<gd::unordered_map<int,int>> m_spawnRemapTriggers`
- `gd::unordered_map<int, cocos2d::CCPoint> m_uiObjectPositions`
- `android, ios {`
- `gd::unordered_set<int> m_allowedButtons`

### `GJBigSprite` : cocos2d::CCNode

**Functions:**

- `static GJBigSprite* create()`
- `virtual bool init()`
- `void finishedLoadingSpriteAsync(cocos2d::CCObject* obj)`
- `void loadSpriteAsync(gd::string filename, int index)`
- `void unloadAll()`
- `void unloadSprite(gd::string filename, int index)`
- `void updateSpriteVisibility()`

**Members:**

- `gd::vector<bool> m_spritesLoaded`
- `cocos2d::CCArray* m_spriteNodes`
- `float m_scaleX`
- `float m_scaleY`
- `bool m_loadSprites`
- `bool m_unloadingAll`

### `GJBigSpriteNode` : cocos2d::CCNode

**Functions:**

- `static GJBigSpriteNode* create()`
- `virtual bool init()`

**Members:**

- `gd::string m_spriteName`
- `cocos2d::CCSprite* m_sprite`
- `cocos2d::CCRect m_spriteRect`
- `bool m_spriteVisible`

### `GJChallengeDelegate`

**Functions:**

- `virtual void challengeStatusFinished()`
- `virtual void challengeStatusFailed()`

### `GJChallengeItem` : cocos2d::CCObject

**Functions:**

- `static GJChallengeItem* create()`
- `static GJChallengeItem* create(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName)`
- `static GJChallengeItem* createFromString(gd::string string)`
- `static GJChallengeItem* createWithCoder(DS_Dictionary* dsdict)`
- `virtual void encodeWithCoder(DS_Dictionary* dsdict)`
- `virtual bool canEncode()`
- `void dataLoaded(DS_Dictionary* dsdict)`
- `void incrementCount(int add)`
- `bool init(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName)`
- `void setCount(int value)`

**Members:**

- `GJChallengeType m_challengeType`
- `geode::SeedValueRSV m_count`
- `geode::SeedValueRSV m_reward`
- `geode::SeedValueRSV m_goal`
- `int m_timeLeft`
- `bool m_canClaim`
- `int m_position`
- `gd::string m_name`

### `GJChestSprite` : cocos2d::CCSprite

**Functions:**

- `static GJChestSprite* create(int chestType)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void setColor(cocos2d::ccColor3B const& color)`
- `bool init(int chestType)`
- `void switchToState(ChestSpriteState state, bool noGlow)`

**Members:**

- `int m_chestType`
- `ChestSpriteState m_spriteState`
- `bool m_dark`

### `GJColorSetupLayer` : FLAlertLayer, ColorSelectDelegate, FLAlertLayerProtocol

**Functions:**

- `static GJColorSetupLayer* create(LevelSettingsObject* object)`
- `virtual void keyBackClicked()`
- `virtual void colorSelectClosed(cocos2d::CCNode* popup)`
- `bool init(LevelSettingsObject* object)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onColor(cocos2d::CCObject* sender)`
- `void onPage(cocos2d::CCObject* sender)`
- `void showPage(int page)`
- `void updateSpriteColor(ColorChannelSprite* sprite, cocos2d::CCLabelBMFont* label, int id)`
- `void updateSpriteColors()`

**Members:**

- `LevelSettingsObject* m_settingsObject`
- `cocos2d::CCDictionary* m_unk290`
- `cocos2d::CCDictionary* m_unk298`
- `cocos2d::CCArray* m_colorLabels`
- `cocos2d::CCArray* m_colorSprites`
- `int m_page`
- `int m_colorsPerPage`
- `int m_totalPages`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `bool m_closeOnSelect`
- `ColorSetupDelegate* m_delegate`
- `int m_colorID`

### `GJComment` : cocos2d::CCNode

**Functions:**

- `GJComment()`
- `~GJComment()`
- `static GJComment* create()`
- `static GJComment* create(cocos2d::CCDictionary* dict)`
- `virtual bool init()`

**Members:**

- `gd::string m_commentString`
- `gd::string m_userName`
- `int m_commentID`
- `int m_userID`
- `int m_likeCount`
- `int m_levelID`
- `bool m_isSpam`
- `int m_accountID`
- `gd::string m_uploadDate`
- `bool m_commentDeleted`
- `int m_percentage`
- `int m_modBadge`
- `cocos2d::ccColor3B m_color`
- `bool m_hasLevelID`
- `bool m_unkMultiplayerBool`
- `bool m_canDelete`
- `GJUserScore* m_userScore`

### `GJCommentListLayer` : cocos2d::CCLayerColor

**Functions:**

- `static GJCommentListLayer* create(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder)`
- `bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder)`

**Members:**

- `BoomListView* m_list`

### `GJDailyLevelDelegate`

**Functions:**

- `virtual void dailyStatusFinished(GJTimedLevelType type)`
- `virtual void dailyStatusFailed(GJTimedLevelType type, GJErrorCode errorType)`

### `GJDifficultySprite` : cocos2d::CCSprite

**Functions:**

- `static GJDifficultySprite* create(int difficulty, GJDifficultyName name)`
- `static gd::string getDifficultyFrame(int difficulty, GJDifficultyName name)`
- `bool init(int difficulty, GJDifficultyName name)`
- `void updateDifficultyFrame(int difficulty, GJDifficultyName name)`
- `void updateFeatureState(GJFeatureState state)`
- `void updateFeatureStateFromLevel(GJGameLevel* level)`

**Members:**

- `GJFeatureState m_featureState`

### `GJDropDownLayer` : cocos2d::CCLayerColor

**Functions:**

- `GJDropDownLayer()`
- `~GJDropDownLayer()`
- `static GJDropDownLayer* create(const char* title)`
- `static GJDropDownLayer* create(const char* title, float height, bool noBack)`
- `virtual void draw()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void customSetup()`
- `virtual void enterLayer()`
- `virtual void exitLayer(cocos2d::CCObject* sender)`
- `virtual void showLayer(bool instant)`
- `virtual void hideLayer(bool instant)`
- `virtual void layerVisible()`
- `virtual void layerHidden()`
- `virtual void enterAnimFinished()`
- `virtual void disableUI()`
- `virtual void enableUI()`
- `bool init(char const* title)`
- `bool init(char const* title, float height, bool noBack)`

**Members:**

- `cocos2d::CCPoint m_endPosition`
- `cocos2d::CCPoint m_startPosition`
- `cocos2d::CCMenu* m_buttonMenu`
- `GJListLayer* m_listLayer`
- `cocos2d::CCLayer* m_mainLayer`
- `bool m_closeOnHide`
- `GJDropDownLayerDelegate* m_delegate`
- `bool m_fastMenu`

### `GJDropDownLayerDelegate`

**Functions:**

- `virtual void dropDownLayerWillClose(GJDropDownLayer* layer)`

### `GJEffectManager` : cocos2d::CCNode

**Functions:**

- `static GJEffectManager* create()`
- `static cocos2d::ccColor3B getMixedColor(cocos2d::ccColor3B color1, cocos2d::ccColor3B color2, float ratio)`
- `virtual bool init()`
- `cocos2d::ccColor3B activeColorForIndex(int index)`
- `float activeOpacityForIndex(int index)`
- `void addAllInheritedColorActions(cocos2d::CCArray* actions)`
- `void addCountToItem(int itemId, int value)`
- `void addMoveCalculation(CCMoveCNode* node, cocos2d::CCPoint offset, GameObject* object)`
- `void calculateBaseActiveColors()`
- `void calculateInheritedColor(int id, ColorAction* action)`
- `void calculateLightBGColor(cocos2d::ccColor3B color)`
- `bool checkCollision(int const& blockAID, int const& blockBID)`
- `void colorActionChanged(ColorAction* action)`
- `bool colorExists(int col)`
- `cocos2d::ccColor3B colorForEffect(cocos2d::ccColor3B color, cocos2d::ccHSVValue hsv)`
- `cocos2d::ccColor3B colorForGroupID(int id, cocos2d::ccColor3B const& color, bool mainColor)`
- `cocos2d::ccColor3B colorForIndex(int index)`
- `cocos2d::ccColor3B colorForPulseEffect(cocos2d::ccColor3B const& color, PulseEffectAction* action)`
- `void controlActionsForControlID(int id, GJActionCommand command)`
- `void controlActionsForTrigger(EffectGameObject* object, GJActionCommand command)`
- `int countForItem(int id)`
- `void createFollowCommand(float xMod, float yMod, float duration, int targetID, int centerID, int uniqueID, int controlID)`
- `GroupCommandObject2* createKeyframeCommand(int targetID, cocos2d::CCArray* group, GameObject* object, int uniqueID, int controlID, bool temporary, float posXMod, float posYMod, float rotMod, float scaleXMod, float scaleYMod, float timeMod, gd::vector<int> const& remapKeys)`
- `void createMoveCommand(cocos2d::CCPoint pt, int groupID, float duration, int easingType, float easingRate, bool lockPlayerX, bool lockPlayerY, bool lockCameraX, bool lockCameraY, float moveModX, float moveModY, int uniqueID, int controlID)`
- `void createPlayerFollowCommand(float delay, float speed, int offset, float maxSpeed, float duration, int targetID, int uniqueID, int controlID)`
- `void createRotateCommand(float offset, float duration, int targetID, int centerID, int easingType, float easingRate, bool lockRotation, bool player1, bool player2, int uniqueID, int controlID)`
- `void createTransformCommand(double scaleX, double scaleY, double property450, double property451, bool onlyMove, float duration, int targetID, int centerID, int easingType, float easingRate, bool, bool relativeRotation, int uniqueID, int controlID)`
- `cocos2d::CCArray* getAllColorActions()`
- `cocos2d::CCArray* getAllColorSprites()`
- `ColorAction* getColorAction(int index)`
- `ColorActionSprite* getColorSprite(int index)`
- `void getLoadedMoveOffset(gd::unordered_map<int, std::pair<double, double>>& offsets)`
- `CCMoveCNode* getMoveCommandNode(GroupCommandObject2* command)`
- `CCMoveCNode* getMoveCommandObject()`
- `OpacityEffectAction* getOpacityActionForGroup(int id)`
- `void getPersistentState(gd::unordered_map<int, int>& counts, gd::unordered_map<int, TimerItem>& items)`
- `gd::string getPersistentStateString()`
- `gd::string getSaveString()`
- `GroupCommandObject2* getTempGroupCommand()`
- `void handleObjectCollision(bool triggerOnExit, int blockAID, int blockBID)`
- `bool hasActiveDualTouch()`
- `bool hasBeenTriggered(int objectUniqueID, int playerUniqueID)`
- `bool hasPulseEffectForGroupID(int id)`
- `bool isGroupEnabled(int id)`
- `void itemWasUsed(int id)`
- `const char* keyForGroupIDColor(int id, cocos2d::ccColor3B const& color, bool mainColor)`
- `void loadFromState(EffectManagerState& state)`
- `void loadPersistentStateString(gd::string state)`
- `void objectsCollided(int blockAID, int blockBID)`
- `float opacityForIndex(int index)`
- `float opacityModForGroup(int id)`
- `void pauseTimer(int id)`
- `void playerButton(bool down, bool player1)`
- `void playerDied()`
- `void postCollisionCheck()`
- `void postMoveActions()`
- `void preCollisionCheck()`
- `void prepareMoveActions(float dt, bool intermediate)`
- `void processColors()`
- `void processCopyColorPulseActions()`
- `void processInheritedColors()`
- `void processMoveCalculations()`
- `void processPulseActions()`
- `void registerCollisionTrigger(int targetID, int blockAID, int blockBID, bool triggerOnExit, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void registerRotationCommand(GroupCommandObject2* object, bool clear)`
- `void removeAllPulseActions()`
- `void removeColorAction(int id)`
- `void removePersistentFromAllItems()`
- `void removePersistentFromAllTimers()`
- `void removeTriggeredID(int objectUniqueID, int playerUniqueID)`
- `void reset()`
- `void resetEffects()`
- `void resetMoveActions()`
- `void resetTempGroupCommands(bool noRemove)`
- `void resetToggledGroups()`
- `void resetTriggeredIDs()`
- `void resetUsedItemState()`
- `void resumeTimer(int id)`
- `void runCountTrigger(int id, int targetCount, bool multiActivate, int targetID, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void runDeathTrigger(int targetID, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `OpacityEffectAction* runOpacityActionOnGroup(int targetID, float duration, float opacity, int uniqueID, int controlID)`
- `PulseEffectAction* runPulseEffect(int targetID, bool targetGroup, float fadeInDuration, float holdDuration, float fadeOutDuration, PulseEffectType effectType, cocos2d::ccColor3B targetColor, cocos2d::ccHSVValue targetHSV, int copyID, bool mainOnly, bool detailOnly, bool exclusive, bool legacyHSV, int uniqueID, int controlID)`
- `void runTimerTrigger(int id, double targetTime, bool multiActivate, int targetID, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void runTouchTriggerCommand(int targetID, bool holdMode, TouchTriggerType touchType, TouchTriggerControl touchControl, bool dualMode, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void saveCompletedMove(int groupId, double dx, double dy)`
- `void saveToState(EffectManagerState& state)`
- `void setColorAction(ColorAction* action, int id)`
- `void setFollowing(int targetID, int targetPosID, bool following)`
- `void setupFromString(gd::string str)`
- `bool shouldBlend(int id)`
- `void spawnGroup(int targetID, float delay, bool spawnOrdered, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void spawnObject(GameObject* object, float delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void startTimer(int id, double startTime, double targetTime, bool stopTime, bool active, bool dontOverride, float timeMod, bool ignoreTimewarp, int targetID, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `void storeTriggeredID(int objectUniqueID, int playerUniqueID)`
- `double timeForItem(int id)`
- `bool timerExists(int id)`
- `void timerWasUsed(int id)`
- `void toggleGroup(int id, bool activate)`
- `void toggleItemPersistent(int id, bool persistent)`
- `void toggleTimerPersistent(int id, bool persistent)`
- `void transferPersistentItems()`
- `void traverseInheritanceChain(InheritanceNode* node)`
- `CCMoveCNode* tryGetMoveCommandNode(int id)`
- `void updateActiveOpacityEffects()`
- `void updateColorAction(ColorAction* action)`
- `void updateColorEffects(float dt)`
- `void updateColors(cocos2d::ccColor3B color1, cocos2d::ccColor3B color2)`
- `void updateCountForItem(int id, int count)`
- `void updateEffects(float dt)`
- `void updateOpacityAction(OpacityEffectAction* action)`
- `void updateOpacityEffects(float dt)`
- `void updatePulseEffects(float dt)`
- `void updateSpawnTriggers(float dt)`
- `void updateTimer(int id, double time)`
- `void updateTimers(float dt, float timeWarp)`
- `bool wasFollowing(int targetID, int targetPosID)`
- `bool wouldCreateLoop(InheritanceNode* node, int id)`

**Members:**

- `TriggerEffectDelegate* m_triggerEffectDelegate`
- `cocos2d::CCDictionary* m_unkObject148`
- `cocos2d::CCDictionary* m_unkDict150`
- `gd::vector<PulseEffectAction> m_pulseEffectVector`
- `gd::unordered_map<int, gd::vector<PulseEffectAction>> m_pulseEffectMap`
- `gd::unordered_map<int, OpacityEffectAction> m_opacityEffectMap`
- `gd::vector<TouchToggleAction> m_unkVector1e0`
- `gd::unordered_map<int, gd::vector<CountTriggerAction>> m_countTriggerActions`
- `gd::vector<CollisionTriggerAction> m_unkVector230`
- `gd::vector<ToggleTriggerAction> m_unkVector248`
- `cocos2d::CCDictionary* m_colorActionDict`
- `cocos2d::CCDictionary* m_unkDict268`
- `gd::vector<InheritanceNode*> m_unkVector270`
- `gd::unordered_map<int, bool> m_unkMap288`
- `gd::vector<ColorAction*> m_colorActionVector`
- `gd::vector<ColorActionSprite*> m_colorActionSpriteVector`
- `gd::vector<bool> m_unkVector2f0`
- `gd::unordered_map<int, int> m_itemCountMap`
- `gd::unordered_map<int, int> m_persistentItemCountMap`
- `gd::unordered_set<int> m_persistentTimerItemSet`
- `gd::unordered_set<int> m_unk3f0`
- `gd::unordered_set<int> m_unk430`
- `gd::unordered_map<int, TimerItem> m_timerItemMap`
- `gd::unordered_map<int, gd::vector<TimerTriggerAction>> m_unkMap3f8`
- `cocos2d::CCArray* m_unkArray430`
- `gd::vector<bool> m_unkVector438`
- `gd::unordered_set<int> m_unkMap460`
- `gd::set<std::pair<int, int>> m_unkMap498`
- `gd::unordered_set<int> m_unkMap4c8`
- `gd::vector<SpawnTriggerAction> m_spawnTriggerActions`
- `gd::vector<GroupCommandObject2*> m_unkVector518`
- `gd::vector<GroupCommandObject2*> m_unkVector530`
- `gd::vector<cocos2d::CCObject*> m_unkVector548`
- `gd::vector<GroupCommandObject2> m_unkVector560`
- `gd::unordered_map<int, std::pair<double, double>> m_unkMap578`
- `gd::vector<GroupCommandObject2*> m_unkVector5b0`
- `gd::unordered_map<int, gd::vector<GroupCommandObject2*>> m_unkMap5c8`
- `gd::vector<GroupCommandObject2*> m_unkVector600`
- `gd::unordered_map<int, CCMoveCNode*> m_unkMap618`
- `gd::unordered_map<int, CCMoveCNode*> m_unkMap650`
- `gd::unordered_map<int, CCMoveCNode*> m_unkMap688`
- `gd::vector<CCMoveCNode*> m_unkVector6c0`
- `gd::vector<CCMoveCNode*> m_unkVector6d8`
- `gd::vector<CCMoveCNode*> m_unkVector6f0`
- `gd::vector<DynamicMoveCalculation> m_unkVector708`
- `gd::map<std::pair<int, int>, gd::vector<GroupCommandObject2*>> m_unkMap770`
- `float m_unk780`
- `float m_unk784`
- `float m_unk788`
- `float m_unk78C`
- `float m_unk790`
- `float m_unk794`
- `bool m_unk798`

### `GJFlyGroundLayer` : GJGroundLayer

**Functions:**

- `static GJFlyGroundLayer* create()`
- `virtual bool init()`

### `GJFollowCommandLayer` : SetupTriggerPopup

**Functions:**

- `static GJFollowCommandLayer* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onUpdateGroupID(cocos2d::CCObject* sender)`
- `void onUpdateGroupID2(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void sliderXModChanged(cocos2d::CCObject* sender)`
- `void sliderYModChanged(cocos2d::CCObject* sender)`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateTargetGroupID()`
- `void updateTargetGroupID2()`
- `void updateTextInputLabel()`
- `void updateTextInputLabel2()`
- `void updateXMod()`
- `void updateXModLabel()`
- `void updateYMod()`
- `void updateYModLabel()`

**Members:**

- `CCTextInputNode* m_moveTimeInput`
- `Slider* m_moveTimeSlider`
- `float m_moveTime`
- `CCTextInputNode* m_xModInput`
- `CCTextInputNode* m_yModInput`
- `Slider* m_xModSlider`
- `Slider* m_yModSlider`
- `float m_xMod`
- `float m_yMod`
- `CCTextInputNode* m_targetIDInput`
- `int m_targetGroupID`
- `CCTextInputNode* m_followIDInput`
- `int m_followGroupID`

### `GJFriendRequest` : cocos2d::CCNode

**Functions:**

- `GJFriendRequest()`
- `static GJFriendRequest* create()`
- `static GJFriendRequest* create(cocos2d::CCDictionary* dict)`
- `virtual bool init()`

**Members:**

- `int m_requestID`
- `int m_accountID`
- `int m_unusedToAccountID`
- `gd::string m_message`
- `gd::string m_uploadDate`
- `bool m_isRead`

### `GJGameLevel` : cocos2d::CCNode

**Functions:**

- `GJGameLevel()`
- `~GJGameLevel()`
- `static GJGameLevel* create()`
- `static GJGameLevel* create(cocos2d::CCDictionary* dict, bool download)`
- `static GJGameLevel* createWithCoder(DS_Dictionary* dict)`
- `static int demonIconForDifficulty(DemonDifficultyType type)`
- `static int getLengthKey(int length, bool platformer)`
- `static gd::string lengthKeyToString(int key)`
- `virtual void encodeWithCoder(DS_Dictionary* dict)`
- `virtual bool canEncode()`
- `virtual bool init()`
- `bool areCoinsVerified()`
- `void copyLevelInfo(GJGameLevel* level)`
- `void dataLoaded(DS_Dictionary* dict)`
- `gd::string generateSettingsString()`
- `gd::string getAudioFileName()`
- `int getAverageDifficulty()`
- `char const* getCoinKey(int coinNumber)`
- `int getLastBuildPageForTab(int tab)`
- `GJGameLevel* getListSnapshot()`
- `int getNormalPercent()`
- `gd::string getSongName()`
- `gd::string getUnpackedLevelDescription()`
- `void handleStatsConflict(GJGameLevel* level)`
- `bool isPlatformer()`
- `void levelWasAltered()`
- `void levelWasSubmitted()`
- `void parseSettingsString(gd::string str)`
- `void saveNewScore(int value, int type, int ticks, int clicks, int coins, gd::string inputs, bool save)`
- `void savePercentage(int percent, bool isPracticeMode, int clicks, int attempts, bool isChkValid)`
- `void scoreStringToVector(gd::string& str, gd::vector<int>& vec)`
- `gd::string scoreVectorToString(gd::vector<int>& vec, int type)`
- `void setAccountID(int id)`
- `void setAttempts(int attempts)`
- `void setAttemptTime(int time)`
- `void setClicks(int clicks)`
- `void setCoinsVerified(int coinsVerified)`
- `void setDailyID(int id)`
- `void setDemon(int demon)`
- `void setJumps(int jumps)`
- `void setLastBuildPageForTab(int tab, int page)`
- `void setLevelID(int levelID)`
- `void setNewNormalPercent(int percent)`
- `void setNewNormalPercent2(int percent)`
- `void setNormalPercent(int percent)`
- `void setObjectCount(int count)`
- `void setOriginalLevel(int id)`
- `void setPassword(int password)`
- `void setStars(int stars)`
- `bool shouldCheatReset()`
- `void storeNewLocalScore(int value, int type)`
- `void unverifyCoins()`

**Members:**

- `cocos2d::CCDictionary* m_lastBuildSave`
- `geode::SeedValueRSV m_levelID`
- `gd::string m_levelName`
- `gd::string m_levelDesc`
- `gd::string m_levelString`
- `gd::string m_creatorName`
- `gd::string m_recordString`
- `gd::string m_uploadDate`
- `gd::string m_updateDate`
- `gd::string m_lockedEditorLayers`
- `gd::string m_savedCameraPositions`
- `cocos2d::CCPoint m_previewLock`
- `geode::SeedValueRSV m_userID`
- `geode::SeedValueRSV m_accountID`
- `GJDifficulty m_difficulty`
- `int m_audioTrack`
- `int m_songID`
- `int m_levelRev`
- `bool m_unlisted`
- `bool m_friendsOnly`
- `geode::SeedValueRSV m_objectCount`
- `int m_levelIndex`
- `int m_ratings`
- `int m_ratingsSum`
- `int m_downloads`
- `bool m_isEditable`
- `bool m_gauntletLevel`
- `bool m_gauntletLevel2`
- `int m_workingTime`
- `int m_workingTime2`
- `bool m_lowDetailMode`
- `bool m_lowDetailModeToggled`
- `bool m_disableShakeToggled`
- `bool m_selected`
- `bool m_localOrSaved`
- `bool m_disableShake`
- `geode::SeedValueRS m_isVerified`
- `bool m_isVerifiedRaw`
- `bool m_isUploaded`
- `bool m_hasBeenModified`
- `int m_levelVersion`
- `int m_gameVersion`
- `geode::SeedValueRSV m_attempts`
- `geode::SeedValueRSV m_jumps`
- `geode::SeedValueRSV m_clicks`
- `geode::SeedValueRSV m_attemptTime`
- `int m_chk`
- `bool m_isChkValid`
- `bool m_isCompletionLegitimate`
- `geode::SeedValueVSR m_normalPercent`
- `geode::SeedValueRSV m_orbCompletion`
- `geode::SeedValueRSV m_newNormalPercent2`
- `int m_practicePercent`
- `int m_likes`
- `int m_dislikes`
- `int m_levelLength`
- `int m_featured`
- `int m_isEpic`
- `bool m_levelFavorited`
- `int m_levelFolder`
- `geode::SeedValueRSV m_dailyID`
- `geode::SeedValueRSV m_demon`
- `int m_demonDifficulty`
- `geode::SeedValueRSV m_stars`
- `bool m_autoLevel`
- `int m_coins`
- `geode::SeedValueRSV m_coinsVerified`
- `geode::SeedValueRS m_password`
- `geode::SeedValueRSV m_originalLevel`
- `bool m_twoPlayerMode`
- `int m_failedPasswordAttempts`
- `geode::SeedValueRSV m_firstCoinVerified`
- `geode::SeedValueRSV m_secondCoinVerified`
- `geode::SeedValueRSV m_thirdCoinVerified`
- `int m_starsRequested`
- `bool m_showedSongWarning`
- `int m_starRatings`
- `int m_starRatingsSum`
- `int m_maxStarRatings`
- `int m_minStarRatings`
- `int m_demonVotes`
- `int m_rateStars`
- `bool m_rateFeature`
- `gd::string m_rateUser`
- `bool m_dontSave`
- `bool m_levelNotDownloaded`
- `int m_requiredCoins`
- `bool m_isUnlocked`
- `cocos2d::CCPoint m_lastCameraPos`
- `float m_lastEditorZoom`
- `int m_lastBuildTab`
- `int m_lastBuildPage`
- `int m_lastBuildGroupID`
- `GJLevelType m_levelType`
- `int m_M_ID`
- `gd::string m_tempName`
- `gd::string m_capacityString`
- `bool m_highObjectsEnabled`
- `bool m_unlimitedObjectsEnabled`
- `gd::string m_personalBests`
- `int m_timestamp`
- `int m_listPosition`
- `gd::string m_songIDs`
- `gd::string m_sfxIDs`
- `int m_songSize`
- `int m_bestTime`
- `int m_ticksTime`
- `int m_clicksTime`
- `int m_coinsTime`
- `gd::string m_inputsTime`
- `int m_bestPoints`
- `int m_ticksPoints`
- `int m_clicksPoints`
- `int m_coinsPoints`
- `gd::string m_inputsPoints`
- `int m_platformerSeed`
- `gd::string m_localBestTimes`
- `gd::string m_localBestPoints`
- `bool m_savedTime`
- `bool m_savedPoints`
- `android, ios {`
- `int m_cbsOverride; // 0 none, 1 enabled, 2 disabled`

### `GJGameLoadingLayer` : cocos2d::CCLayer

**Functions:**

- `GJGameLoadingLayer()`
- `static GJGameLoadingLayer* create(GJGameLevel* level, bool editor)`
- `static GJGameLoadingLayer* transitionToLoadingLayer(GJGameLevel* level, bool editor)`
- `virtual void onEnter()`
- `virtual void onEnterTransitionDidFinish()`
- `void gameLayerDidUnload()`
- `bool init(GJGameLevel* level, bool editor)`
- `void loadLevel()`

**Members:**

- `GJGameLevel* m_level`
- `bool m_editor`

### `GJGameState`

**Functions:**

- `void controlTweenAction(int uniqueID, int controlID, GJActionCommand command)`
- `GameObjectPhysics& getGameObjectPhysics(GameObject* object)`
- `void processStateTriggers()`
- `void stopTweenAction(int action)`
- `void tweenValue(float from, float to, int action, float duration, int easing, float rate, int uniqueID, int controlID)`
- `void updateTweenAction(float value, int action)`
- `void updateTweenActions(float tweenValue)`

**Members:**

- `float m_cameraZoom`
- `float m_targetCameraZoom`
- `cocos2d::CCPoint m_cameraOffset`
- `cocos2d::CCPoint m_unkPoint1`
- `cocos2d::CCPoint m_unkPoint2`
- `cocos2d::CCPoint m_unkPoint3`
- `cocos2d::CCPoint m_unkPoint4`
- `cocos2d::CCPoint m_unkPoint5`
- `cocos2d::CCPoint m_unkPoint6`
- `cocos2d::CCPoint m_unkPoint7`
- `cocos2d::CCPoint m_unkPoint8`
- `cocos2d::CCPoint m_unkPoint9`
- `cocos2d::CCPoint m_unkPoint10`
- `cocos2d::CCPoint m_unkPoint11`
- `cocos2d::CCPoint m_unkPoint12`
- `cocos2d::CCPoint m_unkPoint13`
- `cocos2d::CCPoint m_unkPoint14`
- `cocos2d::CCPoint m_unkPoint15`
- `cocos2d::CCPoint m_unkPoint16`
- `cocos2d::CCPoint m_unkPoint17`
- `cocos2d::CCPoint m_unkPoint18`
- `cocos2d::CCPoint m_unkPoint19`
- `cocos2d::CCPoint m_unkPoint20`
- `cocos2d::CCPoint m_unkPoint21`
- `cocos2d::CCPoint m_unkPoint22`
- `cocos2d::CCPoint m_unkPoint23`
- `cocos2d::CCPoint m_unkPoint24`
- `cocos2d::CCPoint m_unkPoint25`
- `cocos2d::CCPoint m_unkPoint26`
- `cocos2d::CCPoint m_unkPoint27`
- `cocos2d::CCPoint m_unkPoint28`
- `cocos2d::CCPoint m_unkPoint29`
- `bool m_unkBool1`
- `int m_unkInt1`
- `bool m_unkBool2`
- `int m_unkInt2`
- `bool m_unkBool3`
- `cocos2d::CCPoint m_unkPoint30`
- `float m_middleGroundOffsetY`
- `int m_unkInt3`
- `int m_unkInt4`
- `bool m_unkBool4`
- `bool m_unkBool5`
- `float m_unkFloat2`
- `float m_unkFloat3`
- `int m_unkInt5`
- `int m_unkInt6`
- `int m_unkInt7`
- `int m_unkInt8`
- `int m_unkInt9`
- `int m_unkInt10`
- `int m_unkInt11`
- `float m_unkFloat4`
- `float m_unkUint1`
- `float m_portalY`
- `bool m_unkBool6`
- `bool m_gravityRelated`
- `int m_unkInt12`
- `float m_unkInt13`
- `int m_unkInt14`
- `int m_unkInt15`
- `bool m_unkBool7`
- `bool m_unkBool8`
- `bool m_unkBool9`
- `float m_unkFloat5`
- `float m_unkFloat6`
- `float m_unkFloat7`
- `float m_unkFloat8`
- `float m_cameraAngle`
- `float m_targetCameraAngle`
- `bool m_playerStreakBlend`
- `float m_timeWarp`
- `float m_queuedTimeWarp`
- `float m_timeWarpRelated`
- `int m_currentChannel`
- `int m_rotateChannel`
- `gd::unordered_map<int, int> m_spawnChannelRelated0`
- `gd::unordered_map<int, bool> m_spawnChannelRelated1`
- `double m_totalTime`
- `double m_levelTime`
- `double m_unkDouble3`
- `unsigned int m_commandIndex`
- `float m_unkUint3`
- `unsigned int m_currentProgress`
- `int m_unkUint4`
- `int m_unkUint5`
- `int m_unkUint6`
- `int m_unkUint7`
- `int m_unkUint8; // i don't know`
- `GameObject* m_lastActivatedPortal1`
- `GameObject* m_lastActivatedPortal2`
- `cocos2d::CCPoint m_cameraPosition`
- `bool m_unkBool10`
- `float m_levelFlipping`
- `bool m_unkBool11`
- `bool m_unkBool12`
- `bool m_isDualMode`
- `float m_unkFloat9`
- `gd::unordered_map<int, GJValueTween> m_tweenActions`
- `int m_cameraEdgeValue0`
- `int m_cameraEdgeValue1`
- `int m_cameraEdgeValue2`
- `int m_cameraEdgeValue3`
- `gd::unordered_map<int, GameObjectPhysics> m_gameObjectPhysics`
- `gd::vector<float> m_unkVecFloat1`
- `float m_unkUint10`
- `int m_unkUint11`
- `int m_unkUint12`
- `cocos2d::CCPoint m_cameraStepDiff`
- `float m_unkFloat10`
- `float m_timeModRelated`
- `bool m_timeModRelated2`
- `gd::map<std::pair<int, int>, int> m_activatedObjectIDs`
- `float m_unkUint13`
- `cocos2d::CCPoint m_unkPoint32`
- `cocos2d::CCPoint m_cameraPosition2`
- `bool m_unkBool20`
- `bool m_unkBool21`
- `bool m_unkBool22`
- `float m_unkUint14`
- `bool m_unkBool26`
- `bool m_cameraShakeEnabled`
- `float m_cameraShakeFactor`
- `float m_unkUint15`
- `float m_unkUint16`
- `double m_unkUint64_1`
- `cocos2d::CCPoint m_unkPoint34`
- `unsigned int m_dualRelated`
- `gd::unordered_map<int, EnhancedGameObject*> m_stateObjects`
- `gd::map<std::pair<GJGameEvent, int>, gd::vector<EventTriggerInstance>> m_unkMapPairGJGameEventIntVectorEventTriggerInstance`
- `gd::map<std::pair<GJGameEvent, int>, int> m_unkMapPairGJGameEventIntInt`
- `gd::unordered_map<int, gd::vector<EnterEffectInstance>> m_enterEffectInstanceVectors`
- `gd::unordered_map<int, gd::vector<EnterEffectInstance>> m_exitEffectInstanceVectors`
- `gd::vector<int> m_enterChannelMap`
- `gd::vector<int> m_exitChannelMap`
- `gd::vector<EnterEffectInstance> m_moveEffectInstances`
- `gd::vector<EnterEffectInstance> m_rotateEffectInstances`
- `gd::vector<EnterEffectInstance> m_scaleEffectInstances`
- `gd::vector<EnterEffectInstance> m_fadeEffectInstances`
- `gd::vector<EnterEffectInstance> m_tintEffectInstances`
- `gd::unordered_set<int> m_unsortedAreaEffects`
- `bool m_unkBool27`
- `gd::vector<AdvancedFollowInstance> m_advanceFollowInstances`
- `gd::vector<DynamicObjectAction> m_dynamicMoveActions`
- `gd::vector<DynamicObjectAction> m_dynamicRotateActions`
- `bool m_unkBool28`
- `bool m_unkBool29`
- `float m_unkUint17`
- `gd::unordered_map<int, gd::vector<int>> m_unkUMap8`
- `gd::map<std::pair<int,int>, SFXTriggerInstance> m_proximityVolumeRelated`
- `gd::unordered_map<int, SongChannelState> m_songChannelStates`
- `gd::unordered_map<int, gd::vector<SongTriggerState>> m_songTriggerStateVectors`
- `gd::vector<SFXTriggerState> m_sfxTriggerStates`
- `bool m_unkBool30`
- `int m_background`
- `int m_ground`
- `int m_middleground`
- `bool m_unkBool31`
- `int m_points`
- `bool m_unkBool32`
- `unsigned int m_pauseCounter`
- `unsigned int m_pauseBufferTimer`

### `GJGarageLayer` : cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol, GameRateDelegate, ListButtonBarDelegate, DialogDelegate, CharacterColorDelegate, RewardedVideoDelegate

**Functions:**

- `GJGarageLayer()`
- `~GJGarageLayer()`
- `static gd::string achievementForUnlock(int id, UnlockType type)`
- `static gd::string descriptionForUnlock(int id, UnlockType type)`
- `static GJGarageLayer* node()`
- `static cocos2d::CCScene* scene()`
- `static gd::string titleForUnlock(int id, UnlockType type)`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void listButtonBarSwitchedPage(ListButtonBar* bar, int page)`
- `virtual void showUnlockPopup(int id, UnlockType type)`
- `virtual void updateRate()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void dialogClosed(DialogLayer* layer)`
- `virtual void playerColorChanged()`
- `virtual void rewardedVideoFinished()`
- `cocos2d::CCArray* getItems(IconType type)`
- `cocos2d::CCArray* getItems(int count, int page, IconType type, int current)`
- `gd::string getLockFrame(int id, UnlockType type)`
- `void onArrow(cocos2d::CCObject* sender)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNavigate(cocos2d::CCObject* sender)`
- `void onPaint(cocos2d::CCObject* sender)`
- `void onRewardedVideo(cocos2d::CCObject* sender)`
- `void onSelect(cocos2d::CCObject* sender)`
- `void onSelectTab(cocos2d::CCObject* sender)`
- `void onShards(cocos2d::CCObject* sender)`
- `void onShop(cocos2d::CCObject* sender)`
- `void onSpecial(cocos2d::CCObject* sender)`
- `void onToggleItem(cocos2d::CCObject* sender)`
- `void playRainbowEffect()`
- `void playShadowEffect()`
- `void selectTab(IconType type)`
- `void setupIconSelect()`
- `void setupPage(int page, IconType type)`
- `void setupSpecialPage()`
- `void showUnlockPopupNew(int id, UnlockType type)`
- `void toggleGlow()`
- `void updatePlayerColors()`
- `void updatePlayerName(char const* name)`

**Members:**

- `CCTextInputNode* m_usernameInput`
- `SimplePlayer* m_playerObject`
- `cocos2d::CCArray* m_tabButtons`
- `cocos2d::CCArray* m_pageButtons`
- `cocos2d::CCNode* m_unknown`
- `cocos2d::CCSprite* m_supporter`
- `bool m_hasClosed`
- `IconType m_iconType`
- `gd::map<IconType, int> m_iconPages`
- `cocos2d::CCSprite* m_cursor1`
- `cocos2d::CCSprite* m_cursor2`
- `CCMenuItemSpriteExtra* m_currentIcon`
- `ListButtonBar* m_iconSelection`
- `CCMenuItemSpriteExtra* m_leftArrow`
- `CCMenuItemSpriteExtra* m_rightArrow`
- `cocos2d::CCMenu* m_navDotMenu`
- `int m_iconID`
- `IconType m_selectedIconType`
- `bool m_videoPlaying`

### `GJGradientLayer` : cocos2d::CCLayerGradient

**Functions:**

- `GJGradientLayer()`
- `static GJGradientLayer* create()`
- `virtual bool init()`

**Members:**

- `int m_baseColor`
- `int m_detailColor`
- `cocos2d::CCPoint m_gradientPosition`
- `GradientTriggerObject* m_triggerObject`
- `bool m_noScale`
- `int m_blendingMode`
- `int m_blendingLayer`
- `int m_gradientID`

### `GJGroundLayer` : cocos2d::CCLayer

**Functions:**

- `static GJGroundLayer* create(int groundID, int lineType)`
- `virtual void draw()`
- `virtual void showGround()`
- `virtual void fadeInGround(float duration)`
- `virtual void fadeOutGround(float duration)`
- `void createLine(int lineType)`
- `void deactivateGround()`
- `void fadeInFinished()`
- `float getGroundY()`
- `void hideShadows()`
- `bool init(int groundID, int lineType)`
- `void loadGroundSprites(int count, bool ground1)`
- `void positionGround(float y)`
- `float scaleGround(float scale)`
- `void toggleVisible01(bool visible)`
- `void toggleVisible02(bool visible)`
- `void updateGround01Color(cocos2d::ccColor3B color)`
- `void updateGround02Color(cocos2d::ccColor3B color)`
- `void updateGroundPos(cocos2d::CCPoint pos)`
- `void updateGroundWidth(bool useThis)`
- `void updateLineBlend(bool blend)`
- `void updateShadows()`
- `void updateShadowXPos(float leftX, float rightX)`

**Members:**

- `cocos2d::CCSprite* m_ground1Sprite`
- `cocos2d::CCSprite* m_ground2Sprite`
- `float m_textureWidth`
- `cocos2d::CCSprite* m_lineSprite`
- `bool m_showGround`
- `bool m_blendLine`
- `float m_ground1Offset`
- `int m_lineType`
- `float m_groundWidth`
- `bool m_showGround1`
- `bool m_showGround2`
- `float m_unk1cc`
- `bool m_cameraRotated`

### `GJHttpResult` : cocos2d::CCNode

**Functions:**

- `GJHttpResult()`
- `static GJHttpResult* create(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `bool init(bool success, gd::string response, gd::string tag, GJHttpType type)`

**Members:**

- `bool m_success`
- `gd::string m_response`
- `gd::string m_requestTag`
- `GJHttpType m_httpType`

### `GJItemIcon` : cocos2d::CCSprite

**Functions:**

- `GJItemIcon()`
- `~GJItemIcon()`
- `static GJItemIcon* create(UnlockType type, int id, cocos2d::ccColor3B color1, cocos2d::ccColor3B color2, bool dark, bool unused, bool noLabel, cocos2d::ccColor3B unlockColor)`
- `static GJItemIcon* createBrowserItem(UnlockType unlockType, int itemID)`
- `static GJItemIcon* createStoreItem(UnlockType type, int id, bool dark, cocos2d::ccColor3B unlockColor)`
- `static float scaleForType(UnlockType type)`
- `static cocos2d::ccColor3B unlockedColorForType(int type)`
- `virtual void setOpacity(unsigned char opacity)`
- `void changeToLockedState(float scale)`
- `void darkenStoreItem(ShopType type)`
- `void darkenStoreItem(cocos2d::ccColor3B color)`
- `bool init(UnlockType type, int id, cocos2d::ccColor3B color1, cocos2d::ccColor3B color2, bool dark, bool unused, bool noLabel, cocos2d::ccColor3B unlockColor)`
- `void toggleEnabledState(bool enabled)`

**Members:**

- `cocos2d::CCSprite* m_player`
- `int m_iconRequestID`
- `cocos2d::CCSize m_playerSize`
- `bool m_isIcon`
- `int m_unlockID`
- `UnlockType m_unlockType`

### `GJLevelList` : cocos2d::CCNode

**Functions:**

- `GJLevelList()`
- `static GJLevelList* create()`
- `static GJLevelList* create(cocos2d::CCDictionary* dict)`
- `static GJLevelList* createWithCoder(DS_Dictionary* dict)`
- `static gd::string frameForListDifficulty(int diff, DifficultyIconType type)`
- `virtual void encodeWithCoder(DS_Dictionary* dict)`
- `virtual bool canEncode()`
- `virtual bool init()`
- `void addLevelToList(GJGameLevel* level)`
- `int completedLevels()`
- `void dataLoaded(DS_Dictionary* dict)`
- `void duplicateListLevels(GJLevelList* list)`
- `cocos2d::CCArray* getListLevelsArray(cocos2d::CCArray* levels)`
- `gd::string getUnpackedDescription()`
- `void handleStatsConflict(GJLevelList* list)`
- `bool hasMatchingLevels(GJLevelList* list)`
- `int orderForLevel(int id)`
- `void parseListLevels(gd::string str)`
- `void removeLevelFromList(int id)`
- `void reorderLevel(int levelID, int newPosition)`
- `void reorderLevelStep(int id, bool up)`
- `void showListInfo()`
- `int totalLevels()`
- `void updateLevelsString()`

**Members:**

- `gd::vector<int> m_levels`
- `int m_listID`
- `int m_listVersion`
- `int m_downloads`
- `int m_likes`
- `int m_difficulty`
- `int m_accountID`
- `int m_folder`
- `int m_listRevision`
- `int m_listOrder`
- `int m_original`
- `int m_diamonds`
- `int m_levelsToClaim`
- `bool m_isEditable`
- `bool m_unlisted`
- `bool m_friendsOnly`
- `bool m_uploaded`
- `bool m_favorite`
- `bool m_featured`
- `bool m_onlineLevelsLoaded`
- `bool m_modified`
- `gd::string m_creatorName`
- `gd::string m_listName`
- `gd::string m_unkString`
- `gd::string m_levelsString`
- `gd::string m_listDesc`
- `int m_uploadDate`
- `int m_updateDate`
- `cocos2d::CCDictionary* m_levelsDict`
- `GJLevelType m_listType`
- `int m_M_ID`

### `GJLevelScoreCell` : TableViewCell

**Functions:**

- `GJLevelScoreCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromScore(GJUserScore* score)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `GJUserScore* m_userScore`

### `GJListLayer` : cocos2d::CCLayerColor

**Functions:**

- `static GJListLayer* create(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, int type)`
- `bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, int type)`

**Members:**

- `BoomListView* m_listView`

### `GJLocalLevelScoreCell` : TableViewCell

**Functions:**

- `GJLocalLevelScoreCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromScore(GJLocalScore* score)`
- `void updateBGColor(int index)`

**Members:**

- `GJLocalScore* m_localScore`

### `GJLocalScore` : cocos2d::CCObject

**Functions:**

- `GJLocalScore()`
- `static GJLocalScore* create(int points, int type)`
- `bool init(int points, int type)`

**Members:**

- `int m_points`
- `LevelLeaderboardType m_type`
- `bool m_currentScore`

### `GJMGLayer` : cocos2d::CCLayer

**Functions:**

- `GJMGLayer()`
- `static GJMGLayer* create(int index)`
- `static float defaultYOffsetForBG2(int index)`
- `virtual void draw()`
- `virtual void showGround()`
- `void deactivateGround()`
- `bool init(int index)`
- `void loadGroundSprites(int count, bool ground1)`
- `float scaleGround(float scale)`
- `void toggleVisible01(bool visible)`
- `void toggleVisible02(bool visible)`
- `void updateGroundColor(cocos2d::ccColor3B color, bool ground1)`
- `void updateGroundOpacity(unsigned char opacity, bool ground1)`
- `void updateGroundPos(cocos2d::CCPoint pos)`
- `void updateGroundWidth(bool useThis)`
- `void updateMG01Blend(bool blend)`
- `void updateMG02Blend(bool blend)`

**Members:**

- `cocos2d::CCSprite* m_ground1Sprite`
- `cocos2d::CCSprite* m_ground2Sprite`
- `float m_textureWidth`
- `void* m_unk1b0`
- `bool m_showGround`
- `float m_groundWidth`
- `bool m_showGround1`
- `bool m_showGround2`
- `float m_unk1c4`
- `bool m_cameraRotated`
- `bool m_blendMG1`
- `bool m_blendMG2`
- `cocos2d::CCSpriteBatchNode* m_mg1BatchNode`
- `cocos2d::CCSpriteBatchNode* m_mg2BatchNode`
- `float m_groundScale`
- `float m_ground2Offset`

### `GJMPDelegate`

**Functions:**

- `virtual void joinLobbyFinished(int id)`
- `virtual void joinLobbyFailed(int id, GJMPErrorCode errorType)`
- `virtual void didUploadMPComment(int id)`
- `virtual void updateComments()`

### `GJMapObject` : cocos2d::CCNode

**Functions:**

- `static GJMapObject* create(cocos2d::CCNode* parent)`
- `static GJMapObject* createMonster(int objectID)`
- `bool init(cocos2d::CCNode* parent)`
- `void monsterIdle()`
- `void monsterJump()`
- `void moveFinished()`
- `void moveMonster()`
- `void moveMonster(cocos2d::CCPoint position, float offset)`
- `void playerJump()`
- `void setObjectOrigin(cocos2d::CCPoint position, float offset)`
- `void startMonsterJumpLoop()`
- `void startPlayerJumpLoop()`
- `void touchMonster()`
- `void updateShadow(float scaleX, float scaleY, cocos2d::CCPoint position)`

**Members:**

- `float m_jumpStopTime`
- `cocos2d::CCNode* m_mainNode`
- `cocos2d::CCSprite* m_shadowSprite`
- `cocos2d::CCPoint m_objectOrigin`
- `float m_objectOffset`
- `bool m_monsterIdle`
- `bool m_monsterMoving`
- `float m_moveStopTime`
- `int m_monstersTouched`

### `GJMapPack` : cocos2d::CCNode

**Functions:**

- `GJMapPack()`
- `~GJMapPack()`
- `static GJMapPack* create()`
- `static GJMapPack* create(cocos2d::CCDictionary* dict)`
- `virtual bool init()`
- `int completedMaps()`
- `bool hasCompletedMapPack()`
- `void parsePackColors(gd::string textColorStr, gd::string barColorStr)`
- `void parsePackLevels(gd::string levelsStr)`
- `int totalMaps()`

**Members:**

- `cocos2d::CCArray* m_levels`
- `int m_packID`
- `GJDifficulty m_difficulty`
- `int m_stars`
- `int m_coins`
- `gd::string m_packName`
- `gd::string m_levelStrings`
- `cocos2d::ccColor3B m_textColour`
- `cocos2d::ccColor3B m_barColour`
- `int m_MId`
- `bool m_isGauntlet`

### `GJMessageCell` : TableViewCell, FLAlertLayerProtocol, UploadPopupDelegate, UploadActionDelegate

**Functions:**

- `GJMessageCell(char const* identifier, float width, float height)`
- `~GJMessageCell()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `void loadFromMessage(GJUserMessage* message)`
- `void markAsRead()`
- `void onDeleteMessage(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `void onViewMessage(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`
- `void updateToggle()`

**Members:**

- `GJUserMessage* m_message`
- `UploadActionPopup* m_popup`
- `CCMenuItemToggler* m_toggler`

### `GJMessagePopup` : FLAlertLayer, UploadActionDelegate, UploadPopupDelegate, FLAlertLayerProtocol, DownloadMessageDelegate

**Functions:**

- `static GJMessagePopup* create(GJUserMessage* message)`
- `virtual void keyBackClicked()`
- `virtual void downloadMessageFinished(GJUserMessage* message)`
- `virtual void downloadMessageFailed(int id)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void blockUser()`
- `bool init(GJUserMessage* message)`
- `void loadFromGJMessage(GJUserMessage* message)`
- `void onBlock(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onRemove(cocos2d::CCObject* sender)`
- `void onReply(cocos2d::CCObject* sender)`

**Members:**

- `bool m_actionSuccess`
- `cocos2d::CCLabelBMFont* m_errorLabel`
- `GJUserMessage* m_message`
- `LoadingCircle* m_loadingCircle`
- `CCMenuItemSpriteExtra* m_closeButton`
- `UploadActionPopup* m_uploadPopup`

### `GJMoreGamesLayer` : GJDropDownLayer

**Functions:**

- `static GJMoreGamesLayer* create()`
- `virtual void customSetup()`
- `cocos2d::CCArray* getMoreGamesList()`

**Members:**

- `cocos2d::CCArray* m_moreGamesList`

### `GJMultiplayerManager` : cocos2d::CCNode

**Functions:**

- `static GJMultiplayerManager* sharedState()`
- `virtual bool init()`
- `void addComment(gd::string str, int lobbyID)`
- `void addDLToActive(char const* tag)`
- `void addDLToActive(char const* tag, cocos2d::CCObject* obj)`
- `void createAndAddComment(gd::string text, int lobbyID)`
- `void dataLoaded(DS_Dictionary* dict)`
- `void encodeDataTo(DS_Dictionary* dict)`
- `bool exitLobby(int id)`
- `void firstSetup()`
- `gd::string getBasePostString()`
- `cocos2d::CCObject* getDLObject(char const* tag)`
- `int getLastCommentIDForGame(int id)`
- `void handleIt(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItND(cocos2d::CCNode* node, void* data)`
- `bool isDLActive(char const* tag)`
- `bool joinLobby(int id)`
- `void onExitLobbyCompleted(gd::string response, gd::string tag)`
- `void onJoinLobbyCompleted(gd::string response, gd::string tag)`
- `void onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onUploadCommentCompleted(gd::string response, gd::string tag)`
- `void ProcessHttpRequest(gd::string url, gd::string params, gd::string tag, GJHttpType type)`
- `void removeDLFromActive(char const* tag)`
- `bool uploadComment(gd::string text, int lobbyID)`

**Members:**

- `cocos2d::CCDictionary* m_activeDownloads`
- `cocos2d::CCDictionary* m_lobbyScores`
- `cocos2d::CCDictionary* m_scoreArrays`
- `cocos2d::CCDictionary* m_lobbyComments`
- `GJMPDelegate* m_mpDelegate`
- `UploadActionDelegate* m_uploadDelegate`

### `GJObjectDecoder` : cocos2d::CCNode, ObjectDecoderDelegate

**Functions:**

- `static GJObjectDecoder* sharedDecoder()`
- `virtual bool init()`
- `virtual cocos2d::CCObject* getDecodedObject(int type, DS_Dictionary* dict)`

### `GJOnlineRewardDelegate`

**Functions:**

- `virtual void onlineRewardStatusFinished(gd::string key)`
- `virtual void onlineRewardStatusFailed()`

### `GJOptionsLayer` : SetupTriggerPopup

**Functions:**

- `GJOptionsLayer()`
- `~GJOptionsLayer()`
- `static GJOptionsLayer* create(int background)`
- `virtual void setupOptions()`
- `virtual void didToggleGV(gd::string variable)`
- `virtual void didToggle(int toggle)`
- `void addGVToggle(char const* title, char const* variable, char const* description)`
- `void addToggle(char const* title, int id, bool initial, char const* description)`
- `void addToggleInternal(char const* title, int id, bool initial, char const* description)`
- `int countForPage(int page)`
- `[[missing(win, mac)]]`
- `CCMenuItemToggler* getToggleButton(int id)`
- `void goToPage(int page)`
- `void incrementCountForPage(int page)`
- `const char* infoKey(int index)`
- `bool init(int background)`
- `cocos2d::CCLayer* layerForPage(int page)`
- `const char* layerKey(int page)`
- `cocos2d::CCPoint nextPosition(int page)`
- `const char* objectKey(int page)`
- `cocos2d::CCArray* objectsForPage(int page)`
- `void offsetToNextPage()`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `const char* pageKey(int page)`

**Members:**

- `float m_gap`
- `int m_page`
- `int m_togglesPerPage`
- `int m_toggleCount`
- `int m_maxPage`
- `float m_maxLabelScale`
- `float m_maxLabelWidth`
- `cocos2d::CCDictionary* m_values`
- `cocos2d::CCDictionary* m_variables`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `float m_offset`
- `android, ios {`
- `gd::unordered_map<int, CCMenuItemToggler*> m_toggleButtons`

### `GJPFollowCommandLayer` : SetupTriggerPopup

**Functions:**

- `static GJPFollowCommandLayer* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onUpdateGroupID(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void sliderXModChanged(cocos2d::CCObject* sender)`
- `void sliderYModChanged(cocos2d::CCObject* sender)`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateMaxSpeed()`
- `void updateMaxSpeedLabel()`
- `void updateOffsetLabel()`
- `void updatePlayerOffset()`
- `void updateTargetGroupID()`
- `void updateTextInputLabel()`
- `void updateXMod()`
- `void updateXModLabel()`
- `void updateYMod()`
- `void updateYModLabel()`

**Members:**

- `CCTextInputNode* m_moveTimeInput`
- `Slider* m_moveTimeSlider`
- `float m_moveTime`
- `CCTextInputNode* m_speedInput`
- `CCTextInputNode* m_delayInput`
- `CCTextInputNode* m_offsetInput`
- `CCTextInputNode* m_maxSpeedInput`
- `Slider* m_speedSlider`
- `Slider* m_delaySlider`
- `float m_delay`
- `float m_speed`
- `int m_offset`
- `float m_maxSpeed`
- `CCTextInputNode* m_targetIDInput`
- `int m_targetGroupID`

### `GJPathPage` : FLAlertLayer, FLAlertLayerProtocol, GJPurchaseDelegate

**Functions:**

- `static GJPathPage* create(int path, GJPathsLayer* layer)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void didPurchaseItem(GJStoreItem* item)`
- `bool init(int path, GJPathsLayer* layer)`
- `void onActivatePath(cocos2d::CCObject* sender)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onIconInfo(cocos2d::CCObject* sender)`
- `void onUnlock(cocos2d::CCObject* sender)`
- `void playUnlockAnimation()`
- `void showCantAffordMessage(GJStoreItem* item)`
- `void unlockAnimationFinished()`
- `void unlockAnimationStep2()`
- `void unlockAnimationStep3()`

**Members:**

- `GJPathsLayer* m_pathsLayer`
- `int m_pathNumber`
- `bool m_animationPlaying`
- `int m_dialogIndex`

### `GJPathRewardPopup` : FLAlertLayer

**Functions:**

- `GJPathRewardPopup()`
- `static GJPathRewardPopup* create(int path)`
- `virtual void keyBackClicked()`
- `void closePopup()`
- `bool init(int path)`
- `void onClaim(cocos2d::CCObject* sender)`

**Members:**

- `int m_pathNumber`

### `GJPathSprite` : CCSpriteCOpacity

**Functions:**

- `static GJPathSprite* create(int path)`
- `void addRankLabel(int path)`
- `void addShardSprite()`
- `void changeToLockedArt()`
- `bool init(int path)`
- `void updateState()`

**Members:**

- `int m_pathNumber`

### `GJPathsLayer` : FLAlertLayer, FLAlertLayerProtocol

**Functions:**

- `static GJPathsLayer* create()`
- `static gd::string nameForPath(int path)`
- `virtual bool init()`
- `virtual void onExit()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `void darkenButtons(bool darken)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onPath(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCSprite* m_closeSprite`
- `bool m_exiting`

### `GJPromoPopup` : FLAlertLayer

**Functions:**

- `GJPromoPopup()`
- `static GJPromoPopup* create(gd::string filename)`
- `virtual void onExit()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `bool init(gd::string filename)`
- `void onClose(cocos2d::CCObject* sender)`

**Members:**

- `gd::string m_promoFrame`

### `GJPurchaseDelegate`

**Functions:**

- `virtual void didPurchaseItem(GJStoreItem* item)`

### `GJRateLevelLayer` : SetupTriggerPopup, UploadPopupDelegate, UploadActionDelegate, LevelRateInfoDelegate, FLAlertLayerProtocol

**Functions:**

- `GJRateLevelLayer()`
- `~GJRateLevelLayer()`
- `static GJRateLevelLayer* create(GJGameLevel* level)`
- `virtual void keyBackClicked()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onCustomButton(cocos2d::CCObject* sender)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void rateInfoFinished(int id, gd::string info)`
- `virtual void rateInfoFailed(int id, int response)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void createStatPillar(int width, int height, int count, cocos2d::ccColor3B innerColor, cocos2d::ccColor3B outerColor, cocos2d::CCPoint position, gd::string text)`
- `CCMenuItemSpriteExtra* getStarsButton(int stars, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale)`
- `bool init(GJGameLevel* level)`
- `void onFeature(cocos2d::CCObject* sender)`
- `void onRate(cocos2d::CCObject* sender)`
- `void onToggleCoins(cocos2d::CCObject* sender)`
- `void selectRating(cocos2d::CCObject* sender)`
- `void setupRateInfo(gd::string info)`

**Members:**

- `GJGameLevel* m_level`
- `bool m_uploadFinished`
- `CCMenuItemSpriteExtra* m_submitButton`
- `cocos2d::CCArray* m_starButtons`
- `int m_stars`
- `bool m_coinsToggled`
- `cocos2d::CCSprite* m_coinSprite`
- `UploadActionPopup* m_uploadPopup`
- `GJDifficultySprite* m_difficultySprite`
- `GJFeatureState m_featureState`
- `LoadingCircle* m_loadingCircle`
- `cocos2d::CCPoint m_center`

### `GJRequestCell` : TableViewCell, FLAlertLayerProtocol, UploadPopupDelegate, UploadActionDelegate

**Functions:**

- `GJRequestCell(char const* identifier, float width, float height)`
- `~GJRequestCell()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `void loadFromScore(GJUserScore* score)`
- `void markAsRead()`
- `void onDeleteRequest(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `void onViewFriendRequest(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`
- `void updateToggle()`

**Members:**

- `GJUserScore* m_score`
- `UploadActionPopup* m_popup`
- `CCMenuItemToggler* m_toggler`

### `GJRewardDelegate`

**Functions:**

- `virtual void rewardsStatusFinished(int type)`
- `virtual void rewardsStatusFailed()`

### `GJRewardItem` : cocos2d::CCObject

**Functions:**

- `static GJRewardItem* create()`
- `static GJRewardItem* create(int chestID, int timeRemaining, gd::string rewardStr)`
- `static GJRewardItem* createSpecial(GJRewardType rewardType, int orbs, int diamonds, SpecialRewardItem specialType1, int specialCount1, SpecialRewardItem specialType2, int specialCount2, int unlockType, int itemID)`
- `static GJRewardItem* createWithCoder(DS_Dictionary* dict)`
- `static GJRewardItem* createWithObject(GJRewardType type, GJRewardObject* object)`
- `static GJRewardItem* createWithObjects(GJRewardType type, cocos2d::CCArray* objects)`
- `static SpecialRewardItem getNextShardType(SpecialRewardItem type)`
- `static SpecialRewardItem getRandomNonMaxShardType()`
- `static SpecialRewardItem getRandomShardType()`
- `static bool isShardType(SpecialRewardItem type)`
- `static gd::string rewardItemToStat(SpecialRewardItem rewardItem)`
- `virtual void encodeWithCoder(DS_Dictionary* dict)`
- `virtual bool canEncode()`
- `void dataLoaded(DS_Dictionary* dict)`
- `int getRewardCount(SpecialRewardItem type)`
- `GJRewardObject* getRewardObjectForType(SpecialRewardItem type)`
- `bool init(int chestID, int timeRemaining, gd::string rewardStr)`

**Members:**

- `int m_chestID`
- `int m_timeRemaining`
- `GJRewardType m_rewardType`
- `cocos2d::CCArray* m_rewardObjects`
- `bool m_unk`

### `GJRewardObject` : cocos2d::CCObject

**Functions:**

- `static GJRewardObject* create()`
- `static GJRewardObject* create(SpecialRewardItem type, int total, int itemID)`
- `static GJRewardObject* createItemUnlock(UnlockType type, int id)`
- `static GJRewardObject* createWithCoder(DS_Dictionary* dict)`
- `virtual void encodeWithCoder(DS_Dictionary* dict)`
- `virtual bool canEncode()`
- `void dataLoaded(DS_Dictionary* dict)`
- `bool init(SpecialRewardItem specialRewardItem, int total, int itemID)`
- `bool isSpecialType()`

**Members:**

- `SpecialRewardItem m_specialRewardItem`
- `UnlockType m_unlockType`
- `int m_itemID`
- `int m_total`

### `GJRobotSprite` : CCAnimatedSprite

**Functions:**

- `static GJRobotSprite* create(int frame)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void hideSecondary()`
- `void hideGlow()`
- `bool init(int frame)`
- `bool init(int frame, gd::string animName)`
- `void showGlow()`
- `void updateColor01(cocos2d::ccColor3B color)`
- `void updateColor02(cocos2d::ccColor3B color)`
- `void updateColors()`
- `void updateFrame(int frame)`
- `void updateGlowColor(cocos2d::ccColor3B color, bool simple)`

**Members:**

- `cocos2d::CCArray* m_unkArray`
- `bool m_hasExtra`
- `cocos2d::ccColor3B m_color`
- `cocos2d::ccColor3B m_secondColor`
- `cocos2d::CCArray* m_secondArray`
- `cocos2d::CCSprite* m_glowSprite`
- `cocos2d::CCSprite* m_extraSprite`
- `IconType m_iconType`
- `int m_iconRequestID`
- `CCSpritePart* m_headSprite`
- `CCSpritePart* m_footSprite`

### `GJRotateCommandLayer` : SetupTriggerPopup

**Functions:**

- `static GJRotateCommandLayer* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void valuePopupClosed(ConfigureValuePopup* popup, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onEasing(cocos2d::CCObject* sender)`
- `void onEasingRate(cocos2d::CCObject* sender)`
- `void onFollowRotation(cocos2d::CCObject* sender)`
- `void onLockRotation(cocos2d::CCObject* sender)`
- `void onUpdateGroupID(cocos2d::CCObject* sender)`
- `void onUpdateGroupID2(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void sliderDegreesChanged(cocos2d::CCObject* sender)`
- `void sliderTimesChanged(cocos2d::CCObject* sender)`
- `void toggleEasingRateVisibility()`
- `void updateCommandDegrees()`
- `void updateCommandTimes()`
- `void updateDegreesLabel()`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateEasingLabel()`
- `void updateEasingRateLabel()`
- `void updateMoveCommandEasing()`
- `void updateMoveCommandEasingRate()`
- `void updateTargetGroupID()`
- `void updateTargetGroupID2()`
- `void updateTextInputLabel()`
- `void updateTextInputLabel2()`
- `void updateTimesLabel()`

**Members:**

- `CCTextInputNode* m_moveTimeInput`
- `Slider* m_moveTimeSlider`
- `float m_moveTime`
- `cocos2d::CCLabelBMFont* m_rotateEasingLabel`
- `EasingType m_rotateEasingType`
- `float m_rotateEasingRate`
- `CCMenuItemSpriteExtra* m_rotateEasingRateButton`
- `cocos2d::CCLabelBMFont* m_rotateEasingRateLabel`
- `CCTextInputNode* m_degreesInput`
- `CCTextInputNode* m_timesInput`
- `Slider* m_degreesSlider`
- `Slider* m_timesSlider`
- `float m_degrees`
- `int m_times360`
- `CCTextInputNode* m_targetIDInput`
- `bool m_disableTextChanged`
- `int m_targetGroupID`
- `CCTextInputNode* m_centerIDInput`
- `int m_centerGroupID`
- `bool m_lockObjectRotation`
- `bool m_followP1`
- `bool m_followP2`
- `CCMenuItemToggler* m_followP1Toggler`
- `CCMenuItemToggler* m_followP2Toggler`

### `GJRotationControl` : cocos2d::CCLayer

**Functions:**

- `GJRotationControl()`
- `static GJRotationControl* create()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `void finishTouch()`
- `void setAngle(float angle)`
- `void updateSliderPosition(cocos2d::CCPoint position)`

**Members:**

- `cocos2d::CCPoint m_cursorDifference`
- `cocos2d::CCPoint m_controlPosition`
- `cocos2d::CCSprite* m_controlSprite`
- `float m_startingRotation`
- `float m_currentRotation`
- `int m_touchID`
- `GJRotationControlDelegate* m_delegate`

### `GJRotationControlDelegate`

**Functions:**

- `virtual void angleChanged(float angle)`
- `virtual void angleChangeBegin()`
- `virtual void angleChangeEnded()`

### `GJScaleControl` : cocos2d::CCLayer

**Functions:**

- `GJScaleControl()`
- `static GJScaleControl* create()`
- `virtual bool init()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `void finishTouch()`
- `void loadValues(GameObject* object, cocos2d::CCArray* objects, gd::unordered_map<int, GameObjectEditorState>& editorStates)`
- `void onToggleLockScale(cocos2d::CCObject* sender)`
- `float scaleFromValue(float value)`
- `float skewFromValue(float value)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateLabelX(float value)`
- `void updateLabelXY(float value)`
- `void updateLabelY(float value)`
- `float valueFromScale(float scale)`
- `float valueFromSkew(float value)`

**Members:**

- `Slider* m_sliderX`
- `Slider* m_sliderY`
- `Slider* m_sliderXY`
- `int m_touchID`
- `float m_valueX`
- `float m_valueY`
- `int m_unkSize4`
- `float m_changedValueX`
- `float m_changedValueY`
- `bool m_scale1Lock`
- `ScaleButtonType m_scaleButtonType`
- `cocos2d::CCLabelBMFont* m_scaleXLabel`
- `cocos2d::CCLabelBMFont* m_scaleYLabel`
- `cocos2d::CCLabelBMFont* m_scaleLabel`
- `GJScaleControlDelegate* m_delegate`
- `float m_upperBound`
- `float m_lowerBound`
- `int m_senderTag`
- `CCMenuItemSpriteExtra* m_scaleLockButton`
- `bool m_scaleLocked`

### `GJScaleControlDelegate`

**Functions:**

- `virtual void scaleXChanged(float scaleX, bool lock)`
- `virtual void scaleYChanged(float scaleY, bool lock)`
- `virtual void scaleXYChanged(float scaleX, float scaleY, bool lock)`
- `virtual void scaleChangeBegin()`
- `virtual void scaleChangeEnded()`
- `virtual void updateScaleControl()`
- `virtual void anchorPointMoved(cocos2d::CCPoint newAnchor)`

### `GJScoreCell` : TableViewCell, FLAlertLayerProtocol

**Functions:**

- `GJScoreCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void loadFromScore(GJUserScore* score)`
- `void onBan(cocos2d::CCObject* sender)`
- `void onCheck(cocos2d::CCObject* sender)`
- `void onMoreLevels(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `GJUserScore* m_score`

### `GJSearchObject` : cocos2d::CCNode

**Functions:**

- `static GJSearchObject* create(SearchType searchType)`
- `static GJSearchObject* create(SearchType searchType, gd::string searchQuery)`
- `static GJSearchObject* create(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode)`
- `static GJSearchObject* createFromKey(char const* key)`
- `static char const* getSearchKey(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode)`
- `char const* getKey()`
- `char const* getNextPageKey()`
- `GJSearchObject* getNextPageObject()`
- `GJSearchObject* getPageObject(int page)`
- `GJSearchObject* getPrevPageObject()`
- `bool init(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode)`
- `bool isLevelSearchObject()`

**Members:**

- `SearchType m_searchType`
- `gd::string m_searchQuery`
- `gd::string m_difficulty`
- `gd::string m_length`
- `int m_page`
- `bool m_starFilter`
- `bool m_noStarFilter`
- `int m_total`
- `bool m_uncompletedFilter`
- `bool m_completedFilter`
- `bool m_featuredFilter`
- `bool m_originalFilter`
- `bool m_twoPlayerFilter`
- `bool m_coinsFilter`
- `bool m_epicFilter`
- `bool m_legendaryFilter`
- `bool m_mythicFilter`
- `GJDifficulty m_demonFilter`
- `int m_folder`
- `int m_songID`
- `bool m_customSongFilter`
- `bool m_songFilter`
- `bool m_searchIsOverlay`
- `int m_searchMode`

### `GJShaderState`

**Functions:**

- `GJShaderState()`
- `void reset()`
- `void stopTweenAction(int action)`
- `void timesyncShaderAction(int action)`
- `void timesyncShaderActions()`
- `void tweenValue(float fromValue, float toValue, int action, float duration, int easingType, float easingRate)`
- `void updateTweenAction(float value, int actionID)`
- `void updateTweenActions(float tweenValue)`

**Members:**

- `gd::unordered_map<int, GJValueTween> m_tweenActions`
- `gd::unordered_map<int, double> m_tweenTimes`
- `double m_time`
- `double m_prevTime`
- `double m_startTime`
- `float m_textureScaleX`
- `float m_textureScaleY`
- `cocos2d::ccColor3B m_blurRefColor`
- `float m_blurIntensity`
- `int m_blurRefChannel`
- `bool m_blurOnlyEmpty`
- `float m_shockWaveStartTime`
- `float m_shockWaveTime`
- `float m_shockWaveTimeOffset`
- `float m_shockWaveSpeed`
- `float m_shockWaveThickness`
- `float m_shockWaveStrength`
- `float m_shockWaveWidth`
- `float m_shockWaveFadeIn`
- `float m_shockWaveFadeOut`
- `bool m_shockWaveInvert`
- `float m_shockWaveInner`
- `float m_shockWaveOuter`
- `int m_shockWaveTargetID`
- `bool m_shockWaveTarget`
- `bool m_shockWaveCenterMoving`
- `bool m_shockWaveRelative`
- `float m_shockWaveMaxSize`
- `cocos2d::CCPoint m_shockWaveScreenOffset`
- `bool m_shockWaveCenterDirty`
- `cocos2d::CCPoint m_shockWaveCenter`
- `double m_shockLineStartTime`
- `float m_shockLineTime`
- `float m_shockLineTimeOffset`
- `float m_shockLineSpeed`
- `bool m_shockLineAxis`
- `bool m_shockLineDirection`
- `bool m_shockLineDual`
- `bool m_shockLineInvert`
- `float m_shockLineScreenOffset`
- `float m_shockLineStrength`
- `float m_shockLineWidth`
- `float m_shockLineFadeIn`
- `float m_shockLineFadeOut`
- `float m_shockLineThickness`
- `int m_shockLineTargetID`
- `bool m_shockLineTarget`
- `bool m_shockLineCenterMoving`
- `bool m_shockLineRelative`
- `float m_shockLineMaxSize`
- `cocos2d::CCPoint m_shockLineScreenOffset2`
- `bool m_shockLineCenterDirty`
- `cocos2d::CCPoint m_shockLineCenter`
- `float m_glitchStrength`
- `float m_glitchSpeed`
- `float m_glitchSliceHeight`
- `float m_glitchMaxSliceXOff`
- `float m_glitchMaxColXOff`
- `float m_glitchMaxColYOff`
- `bool m_glitchRelative`
- `float m_chromaticTargetX`
- `float m_chromaticTargetY`
- `bool m_chromaticRelative`
- `float m_cGStartTime`
- `float m_cGTime`
- `float m_cGSpeed`
- `float m_cGRGBOffset`
- `float m_cGStrength`
- `float m_cGSegmentHeight`
- `float m_cGLineThickness`
- `float m_cGLineStrength`
- `bool m_cGEnable`
- `bool m_cGActive`
- `bool m_cGRelative`
- `bool m_cGRelativePos`
- `float m_pixelateTargetX`
- `float m_pixelateTargetY`
- `bool m_pixelateSnapGrid`
- `bool m_pixelatePixelating`
- `bool m_pixelateRelative`
- `bool m_pixelateHardEdges`
- `float m_lensCircleSize`
- `float m_lensCircleFade`
- `float m_lensCircleStrength`
- `int m_lensCircleTargetID`
- `int m_lensCircleTintChannel`
- `bool m_lensCircleRelative`
- `bool m_lensCircleAdditive`
- `cocos2d::ccColor3B m_lensCircleTint`
- `cocos2d::CCPoint m_lensCircleCenter`
- `cocos2d::CCPoint m_lensCircleScreenOffset`
- `float m_radialBlurSize`
- `float m_radialBlurFade`
- `bool m_radialBlurTarget`
- `int m_radialBlurTargetID`
- `cocos2d::CCPoint m_radialBlurCenter`
- `cocos2d::CCPoint m_radialBlurScreenOffset`
- `float m_motionBlurTargetX`
- `float m_motionBlurTargetY`
- `float m_motionBlurSpeedX`
- `float m_motionBlurSpeedY`
- `float m_motionBlurFollowEaseX`
- `float m_motionBlurFollowEaseY`
- `int m_motionBlurTargetIDX`
- `int m_motionBlurTargetIDY`
- `bool m_motionBlurDual`
- `bool m_motionBlurRelative`
- `float m_bulgeValue`
- `bool m_bulgeRelative`
- `int m_bulgeTargetID`
- `float m_bulgeRadius`
- `cocos2d::CCPoint m_bulgeCenter`
- `cocos2d::CCPoint m_bulgeScreenOffset`
- `float m_pinchTargetX`
- `float m_pinchTargetY`
- `bool m_pinchTargetEnabledX`
- `bool m_pinchTargetEnabledY`
- `int m_pinchTargetIDX`
- `int m_pinchTargetIDY`
- `cocos2d::CCPoint m_pinchCenter`
- `cocos2d::CCPoint m_pinchScreenOffset`
- `bool m_pinchRelative`
- `float m_pinchRadius`
- `cocos2d::CCPoint m_pinchModifier`
- `float m_grayscaleValue`
- `bool m_grayscaleUseLum`
- `int m_grayscaleTintChannel`
- `cocos2d::ccColor3B m_grayscaleTint`
- `float m_sepiaValue`
- `float m_invertColorEditRGB`
- `float m_invertColorR`
- `float m_invertColorG`
- `float m_invertColorB`
- `bool m_invertColorClampRGB`
- `float m_hueShiftDegrees`
- `float m_colorChangeCR`
- `float m_colorChangeCG`
- `float m_colorChangeCB`
- `float m_colorChangeBR`
- `float m_colorChangeBG`
- `float m_colorChangeBB`
- `float m_splitTargetRows`
- `float m_splitTargetCols`
- `bool m_splitActive`
- `int m_minBlendingLayer`
- `int m_maxBlendingLayer`
- `bool m_zLayerDirty`
- `bool m_noPlayerParticles`
- `bool m_usesShaders`

### `GJShopLayer` : cocos2d::CCLayer, GJPurchaseDelegate, DialogDelegate, RewardedVideoDelegate

**Functions:**

- `GJShopLayer()`
- `~GJShopLayer()`
- `static GJShopLayer* create(ShopType type)`
- `static cocos2d::CCScene* scene(ShopType type)`
- `virtual void onExit()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void didPurchaseItem(GJStoreItem* item)`
- `virtual void rewardedVideoFinished()`
- `virtual void dialogClosed(DialogLayer* layer)`
- `void exitVideoAdItems()`
- `bool init(ShopType type)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onCommunityCredits(cocos2d::CCObject* sender)`
- `void onPlushies(cocos2d::CCObject* sender)`
- `void onSelectItem(cocos2d::CCObject* sender)`
- `void onVideoAd(cocos2d::CCObject* sender)`
- `void showCantAffordMessage(GJStoreItem* item)`
- `void showReactMessage()`
- `void updateCurrencyCounter()`

**Members:**

- `bool m_closing`
- `CCCounterLabel* m_currencyLabel`
- `cocos2d::CCDictionary* m_shopItems`
- `ShopType m_type`
- `gd::string m_sheetName`
- `cocos2d::CCNode* m_unkNode1`
- `cocos2d::CCNode* m_unkNode2`
- `bool m_videoPlaying`
- `bool m_unkBool`
- `AnimatedShopKeeper* m_shopKeeper`
- `int m_zolgurothDialogIndex`
- `int m_affordDialogIndex`

### `GJSmartBlockPreview` : cocos2d::CCNode

**Functions:**

- `static GJSmartBlockPreview* create(gd::string key)`
- `void addChance(int count, int total)`
- `void addCount(int count)`
- `void addPreview(gd::string key, gd::string data, LevelEditorLayer* layer)`
- `cocos2d::CCArray* addTemplateGuide(SmartPrefabResult result, float opacity)`
- `void addTemplateGuide(gd::string key, int type)`
- `void createInfoLabel()`
- `bool init(gd::string key)`
- `void toggleSelectItem(bool selected)`

**Members:**

- `gd::string m_prefabKey`
- `cocos2d::CCLabelBMFont* m_infoLabel`
- `cocos2d::CCSprite* m_selectSprite`
- `bool m_selected`

### `GJSmartBlockPreviewSprite` : cocos2d::CCNode

**Functions:**

- `GJSmartBlockPreviewSprite()`
- `static GJSmartBlockPreviewSprite* create()`
- `virtual bool init()`
- `virtual void visit()`

### `GJSmartPrefab` : cocos2d::CCObject

**Functions:**

- `static GJSmartPrefab* create()`
- `static GJSmartPrefab* createWithCoder(DS_Dictionary* dict)`
- `virtual void encodeWithCoder(DS_Dictionary* dict)`
- `virtual bool canEncode()`
- `void dataLoaded(DS_Dictionary* dict)`
- `bool init()`

**Members:**

- `gd::string m_prefabKey`
- `gd::string m_prefabData`
- `int m_prefabID`
- `int m_prefabChance`

### `GJSmartTemplate` : cocos2d::CCObject

**Functions:**

- `static void applyTransformationsForType(SmartBlockType type, cocos2d::CCSprite* sprite)`
- `static GJSmartTemplate* create()`
- `static GJSmartTemplate* createWithCoder(DS_Dictionary* dict)`
- `static SmartBlockType flipBlockType(SmartBlockType type, bool flipX, bool flipY)`
- `static SmartBlockType flipBlockTypeX(SmartBlockType type)`
- `static SmartBlockType flipBlockTypeY(SmartBlockType type)`
- `static gd::string flipKey(gd::string key, bool flipX, bool flipY)`
- `static cocos2d::CCDictionary* generateRemapDict()`
- `static gd::string getSimplifiedKey(gd::string key)`
- `static SmartBlockType getSimplifiedType(SmartBlockType type, bool& changed)`
- `static gd::string getVerySimplifiedKey(gd::string key)`
- `static gd::string keyFromNeighbors(SmartBlockType type, SmartBlockType left, SmartBlockType right, SmartBlockType top, SmartBlockType bottom, SmartBlockType topLeft, SmartBlockType topRight, SmartBlockType bottomLeft, SmartBlockType bottomRight)`
- `static gd::string keyFromNeighbors(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight)`
- `static gd::string keyFromNeighborsOld(bool left, bool right, bool top, bool bottom, bool topLeft, bool topRight, bool bottomLeft, bool bottomRight)`
- `static cocos2d::CCPoint offsetForDir(GJSmartDirection direction, int key)`
- `static cocos2d::CCPoint offsetForObject(SmartGameObject* object)`
- `static cocos2d::CCPoint offsetForType(SmartBlockType type)`
- `static SmartBlockType rotateBlockType(SmartBlockType type, int degrees)`
- `static SmartBlockType rotateBlockType90(SmartBlockType type)`
- `static gd::string rotateKey(gd::string key, int degrees)`
- `static bool shouldDiscardObject(SmartBlockType type, GJSmartDirection direction)`
- `static SmartBlockType smartObjectToType(SmartGameObject* object, cocos2d::CCPoint point)`
- `static int smartTypeToObjectKey(SmartBlockType type)`
- `virtual void encodeWithCoder(DS_Dictionary* dict)`
- `virtual bool canEncode()`
- `void dataLoaded(DS_Dictionary* dict)`
- `gd::string getNoCornerKey(gd::string key)`
- `GJSmartPrefab* getPrefab(gd::string key, bool flipX, bool flipY)`
- `GJSmartPrefab* getPrefab(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight)`
- `cocos2d::CCArray* getPrefabs(gd::string key)`
- `GJSmartPrefab* getPrefabWithID(gd::string key, int id)`
- `GJSmartPrefab* getRandomPrefab(gd::string key)`
- `void getTemplateState(gd::vector<SmartPrefabResult>& results)`
- `int getTotalChanceForPrefab(gd::string key)`
- `bool init()`
- `bool isUnrequired(gd::string key)`
- `gd::string logTemplateStatus(bool unused)`
- `void removePrefab(gd::string prefabKey, int prefabID)`
- `void resetScannedPrefabs()`
- `void savePrefab(gd::string key, gd::string data)`
- `void saveRemap(gd::string key)`
- `void saveRemapToDict(gd::string key, gd::string remap, cocos2d::CCDictionary* dict)`
- `SmartPrefabResult scanForPrefab(gd::string key)`

**Members:**

- `cocos2d::CCDictionary* m_prefabArrays`
- `cocos2d::CCDictionary* m_remapDict1`
- `cocos2d::CCDictionary* m_remapDict2`
- `cocos2d::CCDictionary* m_remapDict3`
- `cocos2d::CCDictionary* m_remapDict4`
- `cocos2d::CCDictionary* m_remapDict5`
- `cocos2d::CCDictionary* m_remapDict6`
- `gd::map<gd::string, SmartPrefabResult> m_prefabResults`
- `bool m_allowFlipX`
- `bool m_allowFlipY`
- `bool m_allowRotation`
- `bool m_ignoreCorners`
- `gd::string m_templateName`
- `gd::string m_unk0a8`
- `int m_nameIndex`
- `int m_prefabIndex`

### `GJSongBrowser` : GJDropDownLayer, FLAlertLayerProtocol, TableViewCellDelegate

**Functions:**

- `static GJSongBrowser* create()`
- `virtual bool init()`
- `virtual void customSetup()`
- `virtual void exitLayer(cocos2d::CCObject* sender)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `virtual int getSelectedCellIdx()`
- `void loadPage(int page)`
- `void onDeleteAll(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void setupPageInfo(int itemCount, int pageStartIdx, int pageEndIdx)`
- `void setupSongBrowser(cocos2d::CCArray* songs)`

**Members:**

- `int m_page`
- `int m_songID`
- `bool m_selected`
- `CCMenuItemSpriteExtra* m_rightArrow`
- `CCMenuItemSpriteExtra* m_leftArrow`
- `cocos2d::CCLabelBMFont* m_countText`
- `cocos2d::CCPoint m_unk298`
- `cocos2d::CCArray* m_downloadedSongs`
- `CustomListView* m_listView`

### `GJSpecialColorSelect` : FLAlertLayer

**Functions:**

- `static GJSpecialColorSelect* create(int id, GJSpecialColorSelectDelegate* delegate, ColorSelectType type)`
- `static const char* textForColorIdx(int index)`
- `virtual void keyBackClicked()`
- `ButtonSprite* getButtonByTag(int tag)`
- `void highlightSelected(ButtonSprite* sprite)`
- `bool init(int id, GJSpecialColorSelectDelegate* delegate, ColorSelectType type)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSelectColor(cocos2d::CCObject* sender)`

**Members:**

- `GJSpecialColorSelectDelegate* m_delegate`
- `int m_colorID`
- `cocos2d::CCArray* m_buttonSprites`

### `GJSpecialColorSelectDelegate`

**Functions:**

- `virtual void colorSelectClosed(GJSpecialColorSelect* select, int id)`

### `GJSpiderSprite` : GJRobotSprite

**Functions:**

- `static GJSpiderSprite* create(int frame)`
- `bool init(int frame)`

### `GJSpriteColor`

**Functions:**

- `GJSpriteColor()`
- `int getColorMode()`

**Members:**

- `int m_colorID`
- `int m_defaultColorID`
- `float m_opacity`
- `float m_baseOpacity`
- `cocos2d::ccHSVValue m_hsv`
- `bool m_usesHSV`
- `bool m_usesCustomBlend`
- `cocos2d::ccColor3B m_customColor`

### `GJStoreItem` : cocos2d::CCNode

**Functions:**

- `GJStoreItem()`
- `static GJStoreItem* create(int index, int typeID, int unlockType, int price, ShopType shopType)`
- `gd::string getCurrencyKey()`
- `bool init(int index, int typeID, int unlockType, int price, ShopType shopType)`

**Members:**

- `geode::SeedValueRSV m_index`
- `geode::SeedValueRSV m_typeID`
- `geode::SeedValueRSV m_unlockType`
- `geode::SeedValueRSV m_price`
- `ShopType m_shopType`

### `GJTransformControl` : cocos2d::CCLayer

**Functions:**

- `GJTransformControl()`
- `~GJTransformControl()`
- `static GJTransformControl* create()`
- `virtual bool init()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `void applyRotation(float rotation)`
- `void calculateRotationOffset()`
- `void finishTouch()`
- `void loadFromState(GJTransformState& state)`
- `void loadValues(GameObject* object, cocos2d::CCArray* objects, gd::unordered_map<int, GameObjectEditorState>& states)`
- `void logCurrentZeroPos()`
- `void onToggleLockScale(cocos2d::CCObject* sender)`
- `void refreshControl()`
- `void saveToState(GJTransformState& state)`
- `void scaleButtons(float scale)`
- `cocos2d::CCSprite* spriteByTag(int tag)`
- `void updateAnchorSprite(cocos2d::CCPoint position)`
- `void updateButtons(bool transform, bool skew)`
- `void updateMinMaxPositions()`

**Members:**

- `cocos2d::CCNode* m_mainNodeParent`
- `cocos2d::CCNode* m_mainNode`
- `cocos2d::CCArray* m_objects`
- `int m_touchID`
- `short m_transformButtonType`
- `GJTransformControlDelegate* m_delegate`
- `cocos2d::CCPoint m_cursorDifference`
- `cocos2d::CCPoint m_topRight`
- `cocos2d::CCPoint m_bottomLeft`
- `cocos2d::CCPoint m_topRightPosition`
- `cocos2d::CCPoint m_bottomLeftPosition`
- `cocos2d::CCPoint m_topRightOrigin`
- `cocos2d::CCPoint m_bottomLeftOrigin`
- `cocos2d::CCArray* m_warpSprites`
- `cocos2d::CCPoint m_rotatePosition`
- `CCMenuItemSpriteExtra* m_warpLockButton`
- `float m_scaleX`
- `float m_scaleY`
- `bool m_warpLocked`
- `float m_rotationX`
- `float m_rotationY`
- `float m_rotation`
- `float m_buttonScale`

### `GJTransformControlDelegate`

**Functions:**

- `virtual void transformScaleXChanged(float scaleX)`
- `virtual void transformScaleYChanged(float scaleY)`
- `virtual void transformScaleXYChanged(float scaleX, float scaleY)`
- `virtual void transformRotationXChanged(float rotationX)`
- `virtual void transformRotationYChanged(float rotationY)`
- `virtual void transformRotationChanged(float rotation)`
- `virtual void transformResetRotation()`
- `virtual void transformRestoreRotation()`
- `virtual void transformSkewXChanged(float skewX)`
- `virtual void transformSkewYChanged(float skewY)`
- `virtual void transformChangeBegin()`
- `virtual void transformChangeEnded()`
- `virtual void updateTransformControl()`
- `virtual void anchorPointMoved(cocos2d::CCPoint anchorPoint)`
- `virtual cocos2d::CCNode* getTransformNode()`
- `virtual EditorUI* getUI()`

### `GJUINode` : cocos2d::CCNode

**Functions:**

- `static GJUINode* create(UIButtonConfig& config)`
- `virtual void draw()`
- `int activeRangeTouchTest(cocos2d::CCPoint position)`
- `int activeTouchTest(cocos2d::CCPoint position)`
- `float getButtonScale()`
- `uint8_t getOpacity()`
- `void highlightButton(int button)`
- `bool init(UIButtonConfig& config)`
- `void loadFromConfig(UIButtonConfig& config)`
- `void resetState()`
- `void saveToConfig(UIButtonConfig& config)`
- `void setOpacity(unsigned char opacity)`
- `void toggleHighlight(int button, bool highlight)`
- `void toggleModeB(bool modeB)`
- `void touchEnded()`
- `int touchTest(cocos2d::CCPoint position)`
- `void updateButtonFrames()`
- `void updateButtonPositions()`
- `void updateButtonScale(float scale)`
- `void updateDeadzone(int deadzone)`
- `void updateDragRadius(float radius)`
- `void updateHeight(float height)`
- `void updateRangePos(cocos2d::CCPoint position)`
- `void updateSize(float width, float height)`
- `void updateWidth(float width)`

**Members:**

- `cocos2d::CCSprite* m_firstSprite`
- `cocos2d::CCSprite* m_secondSprite`
- `cocos2d::CCRect m_rect`
- `int m_touchID`
- `cocos2d::CCPoint m_touchDelta`
- `cocos2d::CCPoint m_touchPosition`
- `float m_radius`
- `float m_deadzone`
- `bool m_drawLines`
- `bool m_modeB`
- `bool m_snap`
- `bool m_swiping`
- `bool m_moving`
- `bool m_player2`
- `bool m_oneButton`
- `bool m_split`
- `PlayerButton m_currentButton`

### `GJUnlockableItem` : cocos2d::CCObject

**Functions:**

- `GJUnlockableItem()`
- `static GJUnlockableItem* create()`
- `bool init()`

### `GJUserCell` : TableViewCell, FLAlertLayerProtocol, UploadPopupDelegate, UploadActionDelegate

**Functions:**

- `GJUserCell(char const* identifier, float width, float height)`
- `~GJUserCell()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `void loadFromScore(GJUserScore* score)`
- `void onCancelFriendRequest(cocos2d::CCObject* sender)`
- `void onRemoveFriend(cocos2d::CCObject* sender)`
- `void onSendMessage(cocos2d::CCObject* sender)`
- `void onUnblockUser(cocos2d::CCObject* sender)`
- `void onViewFriendRequest(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `GJUserScore* m_userScore`
- `UploadActionPopup* m_uploadPopup`

### `GJUserMessage` : cocos2d::CCNode

**Functions:**

- `GJUserMessage()`
- `static GJUserMessage* create()`
- `static GJUserMessage* create(cocos2d::CCDictionary* dict)`
- `virtual bool init()`

**Members:**

- `int m_messageID`
- `int m_accountID`
- `int m_userID`
- `gd::string m_title`
- `gd::string m_content`
- `gd::string m_username`
- `gd::string m_uploadDate`
- `bool m_read`
- `bool m_outgoing`
- `bool m_toggled`

### `GJUserScore` : cocos2d::CCNode

**Functions:**

- `GJUserScore()`
- `static GJUserScore* create()`
- `static GJUserScore* create(cocos2d::CCDictionary* dict)`
- `virtual bool init()`
- `bool isCurrentUser()`
- `void mergeWithScore(GJUserScore* score)`

**Members:**

- `gd::string m_userName`
- `gd::string m_userUDID`
- `int m_scoreType`
- `int m_userID`
- `int m_accountID`
- `int m_stars`
- `int m_moons`
- `int m_diamonds`
- `int m_demons`
- `int m_playerRank`
- `int m_creatorPoints`
- `int m_secretCoins`
- `int m_userCoins`
- `int m_iconID`
- `int m_color1`
- `int m_color2`
- `int m_color3`
- `int m_special`
- `IconType m_iconType`
- `int m_messageState`
- `int m_friendStatus`
- `int m_commentHistoryStatus`
- `gd::string m_youtubeURL`
- `gd::string m_twitterURL`
- `gd::string m_twitchURL`
- `gd::string m_discordUsername`
- `gd::string m_instagramURL`
- `gd::string m_tiktokURL`
- `gd::string m_customString`
- `int m_playerCube`
- `int m_playerShip`
- `int m_playerBall`
- `int m_playerUfo`
- `int m_playerWave`
- `int m_playerRobot`
- `int m_playerSpider`
- `int m_playerSwing`
- `int m_playerJetpack`
- `int m_playerStreak`
- `bool m_glowEnabled`
- `int m_playerExplosion`
- `int m_modBadge`
- `int m_globalRank`
- `int m_friendReqStatus`
- `int m_newMsgCount`
- `int m_friendReqCount`
- `int m_newFriendCount`
- `bool m_newFriendRequest`
- `bool m_toggled`
- `gd::string m_unkString`
- `double m_lobbyJoinTime`
- `gd::string m_demonInfo`
- `gd::string m_starsInfo`
- `gd::string m_platformerInfo`
- `int m_levelMode`
- `LevelLeaderboardMode m_leaderboardMode`
- `LeaderboardStat m_leaderboardStat`

### `GJValueTween`

**Functions:**

- `void step(float delta)`

**Members:**

- `float m_fromValue`
- `float m_toValue`
- `float m_duration`
- `float m_deltaTime`
- `float m_currentValue`
- `int m_easingType`
- `float m_easingRate`
- `bool m_finished`
- `bool m_disabled`
- `int m_uniqueID`
- `int m_controlID`

### `GJWorldNode` : cocos2d::CCNode

**Functions:**

- `static GJWorldNode* create(int type, WorldSelectLayer* layer)`
- `float addDotsToLevel(int levelID, bool animate)`
- `cocos2d::CCPoint dotPositionForLevel(int levelID, int index)`
- `bool init(int type, WorldSelectLayer* layer)`
- `void onLevel(cocos2d::CCObject* sender)`
- `void playStep1()`
- `void playStep2()`
- `void playStep3()`
- `cocos2d::CCPoint positionForLevelButton(int levelID)`
- `void unlockActiveItem()`

**Members:**

- `cocos2d::CCArray* m_activeObjects`
- `CCMenuItemSpriteExtra* m_activeButton`
- `GJGameLevel* m_level`
- `WorldSelectLayer* m_selectLayer`
- `bool m_unlocked`
- `cocos2d::CCPoint m_levelPosition`
- `cocos2d::ccColor3B m_particleColor`
- `int m_islandType`
- `bool m_islandUnlocked`
- `cocos2d::CCSprite* m_arrowSprite`

### `GJWriteMessagePopup` : FLAlertLayer, TextInputDelegate, UploadMessageDelegate, UploadPopupDelegate, FLAlertLayerProtocol

**Functions:**

- `static GJWriteMessagePopup* create(int accountID, int messageID)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void uploadMessageFinished(int accountID)`
- `virtual void uploadMessageFailed(int accountID)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `void closeMessagePopup(bool fullExit)`
- `bool init(int accountID, int messageID)`
- `void onClearBody(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSend(cocos2d::CCObject* sender)`
- `void updateBody(gd::string body)`
- `void updateCharCountLabel(int type)`
- `void updateSubject(gd::string subject)`
- `void updateText(gd::string text, int type)`

**Members:**

- `int m_unk298`
- `int m_messageID`
- `int m_accountID`
- `CCTextInputNode* m_messageInput`
- `CCTextInputNode* m_subjectInput`
- `gd::string m_messageText`
- `gd::string m_subjectText`
- `cocos2d::CCLabelBMFont* m_messageCountLabel`
- `cocos2d::CCLabelBMFont* m_subjectCountLabel`
- `UploadActionPopup* m_uploadPopup`
- `bool m_uploadSuccess`

### `GManager` : cocos2d::CCNode

**Functions:**

- `GManager()`
- `virtual bool init()`
- `virtual void setup()`
- `virtual void encodeDataTo(DS_Dictionary* dict)`
- `virtual void dataLoaded(DS_Dictionary* dict)`
- `virtual void firstLoad()`
- `gd::string getCompressedSaveString()`
- `gd::string getSaveString()`
- `void load()`
- `void loadDataFromFile(gd::string const& filename)`
- `void loadFromCompressedString(gd::string& str)`
- `void loadFromString(gd::string& str)`
- `void save()`
- `void saveData(DS_Dictionary* dict, gd::string filename)`
- `void saveGMTo(gd::string filename)`
- `bool tryLoadData(DS_Dictionary* dict, gd::string const& filename)`

**Members:**

- `gd::string m_fileName`
- `bool m_setup`
- `bool m_saved`
- `bool m_quickSave`

### `GameCell` : TableViewCell

**Functions:**

- `GameCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromString(gd::string str)`
- `void onTouch(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `void* m_unk230`
- `gd::string m_gameLink`

### `GameEffectsManager` : cocos2d::CCNode

**Functions:**

- `static GameEffectsManager* create(PlayLayer* playLayer)`
- `void addParticleEffect(cocos2d::CCParticleSystemQuad* particle, int unused)`
- `bool init(PlayLayer* playLayer)`
- `void scaleParticle(cocos2d::CCParticleSystemQuad* particle, float scale)`

**Members:**

- `PlayLayer* m_playLayer`

### `GameLevelManager` : cocos2d::CCNode

**Functions:**

- `static GameLevelManager* get()`
- `static cocos2d::CCDictionary* responseToDict(gd::string response, bool colon)`
- `static GameLevelManager* sharedState()`
- `virtual bool init()`
- `bool acceptFriendRequest(int accountID, int requestID)`
- `int accountIDForUserID(int userID)`
- `void addDLToActive(char const* key)`
- `bool areGauntletsLoaded()`
- `void banUser(int accountID)`
- `bool blockUser(int accountID)`
- `void cleanupDailyLevels()`
- `cocos2d::CCArray* createAndGetAccountComments(gd::string str, int accountID)`
- `cocos2d::CCArray* createAndGetCommentsFull(gd::string str, int parentID, bool account)`
- `cocos2d::CCArray* createAndGetLevelComments(gd::string str, int levelID)`
- `cocos2d::CCArray* createAndGetLevelLists(gd::string str)`
- `cocos2d::CCArray* createAndGetLevels(gd::string str)`
- `cocos2d::CCArray* createAndGetMapPacks(gd::string str)`
- `cocos2d::CCArray* createAndGetScores(gd::string str, GJScoreType type)`
- `GJGameLevel* createNewLevel()`
- `GJLevelList* createNewLevelList()`
- `gd::string createPageInfo(int total, int start, int count)`
- `GJSmartTemplate* createSmartTemplate()`
- `void dataLoaded(DS_Dictionary* dict)`
- `void deleteAccountComment(int id, int accountID)`
- `void deleteComment(int id, CommentType type, int parentID)`
- `bool deleteFriendRequests(int accountID, cocos2d::CCArray* accounts, bool sent)`
- `void deleteLevel(GJGameLevel* level)`
- `void deleteLevelComment(int id, int levelID)`
- `void deleteLevelList(GJLevelList* list)`
- `bool deleteSentFriendRequest(int accountID)`
- `void deleteServerLevel(int id)`
- `void deleteServerLevelList(int id)`
- `void deleteSmartTemplate(GJSmartTemplate* smartTemplate)`
- `bool deleteUserMessages(GJUserMessage* message, cocos2d::CCArray* messages, bool isSender)`
- `void downloadLevel(int id, bool gauntletLevel, int dailyID)`
- `void downloadUserMessage(int id, bool sent)`
- `void encodeDataTo(DS_Dictionary* dict)`
- `void firstSetup()`
- `void followUser(int id)`
- `GJFriendRequest* friendRequestFromAccountID(int id)`
- `void friendRequestWasRemoved(int accountID, bool sent)`
- `const char* getAccountCommentKey(int accountID, int page)`
- `void getAccountComments(int accountID, int page, int total)`
- `int getActiveDailyID(GJTimedLevelType type)`
- `GJSmartTemplate* getActiveSmartTemplate()`
- `cocos2d::CCArray* getAllSmartTemplates()`
- `cocos2d::CCDictionary* getAllUsedSongIDs()`
- `gd::string getBasePostString()`
- `bool getBoolForKey(char const* key)`
- `gd::string getCommentKey(int ID, int page, int mode, CommentKeyType keytype)`
- `int getCompletedDailyLevels()`
- `int getCompletedEventLevels(int minStars, int maxStars)`
- `int getCompletedGauntletDemons()`
- `int getCompletedGauntletLevels()`
- `cocos2d::CCArray* getCompletedLevels(bool useOrbCompletion)`
- `int getCompletedWeeklyLevels()`
- `int getDailyID(GJTimedLevelType type)`
- `int getDailyTimer(GJTimedLevelType type)`
- `const char* getDeleteCommentKey(int parentID, int id, int type)`
- `const char* getDeleteMessageKey(int id, bool sent)`
- `gd::string getDemonLevelsString()`
- `const char* getDescKey(int levelID)`
- `gd::string getDifficultyStr(bool isNA, bool isEasy, bool isNormal, bool isHard, bool isHarder, bool isInsane, bool isDemon, bool isAuto)`
- `const char* getDiffKey(int diff)`
- `bool getDiffVal(int diff)`
- `gd::string getFolderName(int id, bool local)`
- `const char* getFriendRequestKey(bool sent, int page)`
- `void getFriendRequests(bool sent, int page, int total)`
- `const char* getGauntletKey(int id)`
- `void getGauntletLevels(int id)`
- `void getGauntlets()`
- `gd::string getGauntletSearchKey(int id)`
- `bool getGJChallenges()`
- `bool getGJDailyLevelState(GJTimedLevelType type)`
- `bool getGJRewards(int type)`
- `bool getGJSecretReward(gd::string key)`
- `void getGJUserInfo(int id)`
- `int getHighestLevelOrder()`
- `int getIntForKey(char const* key)`
- `gd::string getLeaderboardKey(LeaderboardType type, LeaderboardStat stat)`
- `void getLeaderboardScores(LeaderboardType type, LeaderboardStat stat)`
- `gd::string getLengthStr(bool isTiny, bool isShort, bool isMedium, bool isLong, bool isXL, bool isPlat)`
- `const char* getLenKey(int len)`
- `bool getLenVal(int len)`
- `void getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype)`
- `const char* getLevelDownloadKey(int levelID, bool isGauntlet, int dailyID)`
- `const char* getLevelKey(int levelID)`
- `void getLevelLeaderboard(GJGameLevel* level, LevelLeaderboardType type, LevelLeaderboardMode mode)`
- `const char* getLevelLeaderboardKey(int levelID, LevelLeaderboardType type, LevelLeaderboardMode mode)`
- `const char* getLevelListKey(int listID)`
- `void getLevelLists(GJSearchObject* object)`
- `void getLevelRateInfo(int id)`
- `void getLevelSaveData()`
- `const char* getLikeAccountItemKey(LikeItemType type, int id, bool liked, int parentID)`
- `const char* getLikeItemKey(LikeItemType type, int id, bool liked, int parentID)`
- `GJGameLevel* getLocalLevel(int uniqueID)`
- `GJGameLevel* getLocalLevelByName(gd::string name)`
- `GJLevelList* getLocalLevelList(int uniqueID)`
- `int getLowestLevelOrder()`
- `GJGameLevel* getMainLevel(int levelID, bool dontGetLevelString)`
- `const char* getMapPackKey(int pack)`
- `void getMapPacks(GJSearchObject* object)`
- `const char* getMessageKey(int id)`
- `const char* getMessagesKey(bool sent, int page)`
- `void getNews()`
- `int getNextFreeTemplateID()`
- `gd::string getNextLevelName(gd::string name)`
- `void getOnlineLevels(GJSearchObject* object)`
- `const char* getPageInfo(char const* key)`
- `const char* getPostCommentKey(int parentID)`
- `const char* getRateStarsKey(int levelID)`
- `const char* getReportKey(int levelID)`
- `GJGameLevel* getSavedDailyLevel(int dailyID)`
- `GJGameLevel* getSavedDailyLevelFromLevelID(int id)`
- `GJMapPack* getSavedGauntlet(int id)`
- `GJGameLevel* getSavedGauntletLevel(int id)`
- `GJGameLevel* getSavedLevel(GJGameLevel* level)`
- `GJGameLevel* getSavedLevel(int id)`
- `GJLevelList* getSavedLevelList(int listID)`
- `cocos2d::CCArray* getSavedLevelLists(int folder)`
- `cocos2d::CCArray* getSavedLevels(bool favorite, int folder)`
- `GJMapPack* getSavedMapPack(int id)`
- `cocos2d::CCScene* getSearchScene(char const* key)`
- `int getSplitIntFromKey(char const* key, int index)`
- `gd::string getStarLevelsString()`
- `cocos2d::CCArray* getStoredLevelComments(char const* key)`
- `cocos2d::CCArray* getStoredOnlineLevels(char const* key)`
- `cocos2d::CCArray* getStoredUserList(UserListType type)`
- `GJUserMessage* getStoredUserMessage(int id)`
- `GJUserMessage* getStoredUserMessageReply(int id)`
- `int getTimeLeft(char const* key, float length)`
- `void getTopArtists(int page, int total)`
- `const char* getTopArtistsKey(int page)`
- `const char* getUploadMessageKey(int accountID)`
- `const char* getUserInfoKey(int id)`
- `void getUserList(UserListType type)`
- `void getUserMessages(bool sent, int page, int total)`
- `void getUsers(GJSearchObject* object)`
- `void gotoLevelPage(GJGameLevel* level)`
- `void handleIt(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItND(cocos2d::CCNode* node, void* data)`
- `bool hasDailyStateBeenLoaded(GJTimedLevelType type)`
- `bool hasDownloadedLevel(int id)`
- `bool hasDownloadedList(int id)`
- `bool hasLikedAccountItem(LikeItemType type, int id, bool liked, int parentID)`
- `bool hasLikedItem(LikeItemType type, int id, bool liked, int parentID)`
- `bool hasLikedItemFullCheck(LikeItemType type, int id, bool liked, int parentID)`
- `bool hasRatedDemon(int id)`
- `bool hasRatedLevelStars(int id)`
- `bool hasReportedLevel(int id)`
- `void invalidateMessages(bool sent, bool reload)`
- `void invalidateRequests(bool sent, bool reload)`
- `void invalidateUserList(UserListType type, bool reload)`
- `bool isDLActive(char const* tag)`
- `bool isFollowingUser(int id)`
- `bool isTimeValid(char const* key, float length)`
- `bool isUpdateValid(int id)`
- `int itemIDFromLikeKey(char const* key)`
- `bool keyHasTimer(char const* key)`
- `int levelIDFromCommentKey(char const* key)`
- `int levelIDFromPostCommentKey(char const* key)`
- `int likeFromLikeKey(char const* key)`
- `void likeItem(LikeItemType type, int id, bool liked, int parentID)`
- `void limitSavedLevels()`
- `void makeTimeStamp(char const* key)`
- `void markItemAsLiked(LikeItemType type, int id, bool liked, int parentID)`
- `void markLevelAsDownloaded(int id)`
- `void markLevelAsRatedDemon(int id)`
- `void markLevelAsRatedStars(int id)`
- `void markLevelAsReported(int id)`
- `void markListAsDownloaded(int id)`
- `void messageWasRemoved(int id, bool sent)`
- `void onAcceptFriendRequestCompleted(gd::string response, gd::string tag)`
- `void onBanUserCompleted(gd::string response, gd::string tag)`
- `void onBlockUserCompleted(gd::string response, gd::string tag)`
- `void onDeleteCommentCompleted(gd::string response, gd::string tag)`
- `void onDeleteFriendRequestCompleted(gd::string response, gd::string tag)`
- `void onDeleteServerLevelCompleted(gd::string response, gd::string tag)`
- `void onDeleteServerLevelListCompleted(gd::string response, gd::string tag)`
- `void onDeleteUserMessagesCompleted(gd::string response, gd::string tag)`
- `void onDownloadLevelCompleted(gd::string response, gd::string tag)`
- `void onDownloadUserMessageCompleted(gd::string response, gd::string tag)`
- `void onGetAccountCommentsCompleted(gd::string response, gd::string tag)`
- `void onGetFriendRequestsCompleted(gd::string response, gd::string tag)`
- `void onGetGauntletsCompleted(gd::string response, gd::string tag)`
- `void onGetGJChallengesCompleted(gd::string response, gd::string tag)`
- `void onGetGJDailyLevelStateCompleted(gd::string response, gd::string tag)`
- `void onGetGJRewardsCompleted(gd::string response, gd::string tag)`
- `void onGetGJSecretRewardCompleted(gd::string response, gd::string tag)`
- `void onGetGJUserInfoCompleted(gd::string response, gd::string tag)`
- `void onGetLeaderboardScoresCompleted(gd::string response, gd::string tag)`
- `void onGetLevelCommentsCompleted(gd::string response, gd::string tag)`
- `void onGetLevelLeaderboardCompleted(gd::string response, gd::string tag)`
- `void onGetLevelListsCompleted(gd::string response, gd::string tag)`
- `void onGetLevelRateInfoCompleted(gd::string response, gd::string tag)`
- `void onGetLevelSaveDataCompleted(gd::string response, gd::string tag)`
- `void onGetMapPacksCompleted(gd::string response, gd::string tag)`
- `void onGetNewsCompleted(gd::string response, gd::string tag)`
- `void onGetOnlineLevelsCompleted(gd::string response, gd::string tag)`
- `void onGetTopArtistsCompleted(gd::string response, gd::string tag)`
- `void onGetUserListCompleted(gd::string response, gd::string tag)`
- `void onGetUserMessagesCompleted(gd::string response, gd::string tag)`
- `void onGetUsersCompleted(gd::string response, gd::string tag)`
- `void onLikeItemCompleted(gd::string response, gd::string tag)`
- `void onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onRateDemonCompleted(gd::string response, gd::string tag)`
- `void onRateLevelAdminCompleted(gd::string response, gd::string tag)`
- `void onRateStarsCompleted(gd::string response, gd::string tag)`
- `void onReadFriendRequestCompleted(gd::string response, gd::string tag)`
- `void onRemoveFriendCompleted(gd::string response, gd::string tag)`
- `void onReportLevelCompleted(gd::string response, gd::string tag)`
- `void onRequestUserAccessCompleted(gd::string response, gd::string tag)`
- `void onRestoreItemsCompleted(gd::string response, gd::string tag)`
- `void onSetLevelFeaturedCompleted(gd::string response, gd::string tag)`
- `void onSetLevelStarsCompleted(gd::string response, gd::string tag)`
- `void onSubmitUserInfoCompleted(gd::string response, gd::string tag)`
- `void onSuggestLevelStarsCompleted(gd::string response, gd::string tag)`
- `void onUnblockUserCompleted(gd::string response, gd::string tag)`
- `void onUpdateDescriptionCompleted(gd::string response, gd::string tag)`
- `void onUpdateLevelCompleted(gd::string response, gd::string tag)`
- `void onUpdateUserScoreCompleted(gd::string response, gd::string tag)`
- `void onUploadCommentCompleted(gd::string response, gd::string tag)`
- `void onUploadFriendRequestCompleted(gd::string response, gd::string tag)`
- `void onUploadLevelCompleted(gd::string response, gd::string tag)`
- `void onUploadLevelListCompleted(gd::string response, gd::string tag)`
- `void onUploadUserMessageCompleted(gd::string response, gd::string tag)`
- `int pageFromCommentKey(char const* key)`
- `void parseRestoreData(gd::string str)`
- `void performNetworkTest()`
- `void ProcessHttpRequest(gd::string endpoint, gd::string params, gd::string tag, GJHttpType httpType)`
- `void processOnDownloadLevelCompleted(gd::string response, gd::string tag, bool update)`
- `void purgeUnusedLevels()`
- `bool rateDemon(int id, int diff, bool moderator)`
- `bool rateLevelAdmin(int id, int stars, int feature, int rank, bool coins, bool updateRank)`
- `void rateStars(int id, int diff)`
- `void readFriendRequest(int id)`
- `void removeDelimiterChars(gd::string str, bool colon)`
- `void removeDLFromActive(char const* key)`
- `bool removeFriend(int accountID)`
- `void removeLevelDownloadedKeysFromDict(cocos2d::CCDictionary* dict)`
- `void removeUserFromList(int id, UserListType type)`
- `void reportLevel(int id)`
- `bool requestUserAccess()`
- `void resetAccountComments(int accountID)`
- `void resetAllTimers()`
- `void resetCommentTimersForAccountID(int id)`
- `void resetCommentTimersForLevelID(int id, CommentKeyType type)`
- `void resetDailyLevelState(GJTimedLevelType type)`
- `void resetGauntlets()`
- `void resetStoredUserInfo(int id)`
- `void resetStoredUserList(UserListType type)`
- `void resetTimerForKey(char const* key)`
- `void restoreItems()`
- `void saveFetchedLevelLists(cocos2d::CCArray* lists)`
- `void saveFetchedLevels(cocos2d::CCArray* levels)`
- `void saveFetchedMapPacks(cocos2d::CCArray* packs)`
- `void saveGauntlet(GJMapPack* gauntlet)`
- `void saveLevel(GJGameLevel* level)`
- `void saveLevelList(GJLevelList* list)`
- `void saveLocalScore(int id, int value, int type)`
- `void saveMapPack(GJMapPack* pack)`
- `void setActiveSmartTemplate(GJSmartTemplate* smartTemplate)`
- `void setBoolForKey(bool value, char const* key)`
- `void setDiffVal(int diff, bool value)`
- `void setFolderName(int id, gd::string name, bool local)`
- `void setIntForKey(int value, char const* key)`
- `void setLenVal(int diff, bool value)`
- `void setLevelFeatured(int id, int rank, bool epic)`
- `bool setLevelStars(int id, int stars, bool coins)`
- `int specialFromLikeKey(char const* key)`
- `void storeCommentsResult(cocos2d::CCArray* comments, gd::string pageInfo, char const* key)`
- `void storeDailyLevelState(int id, int remaining, GJTimedLevelType type)`
- `void storeFriendRequest(GJFriendRequest* request)`
- `void storeSearchResult(cocos2d::CCArray* levels, gd::string pageInfo, char const* searchKey)`
- `void storeUserInfo(GJUserScore* score)`
- `void storeUserMessage(GJUserMessage* message)`
- `void storeUserMessageReply(int id, GJUserMessage* message)`
- `void storeUserName(int userID, int accountID, gd::string userName)`
- `void storeUserNames(gd::string usernameString)`
- `void submitUserInfo()`
- `void suggestLevelStars(int id, int stars, int feature)`
- `gd::string tryGetUsername(int accountID)`
- `CommentType typeFromCommentKey(char const* key)`
- `LikeItemType typeFromLikeKey(char const* key)`
- `bool unblockUser(int id)`
- `void unfollowUser(int id)`
- `bool unrateLevelAdmin(int id)`
- `bool updateDescription(int id, gd::string description)`
- `void updateLevel(GJGameLevel* level)`
- `void updateLevelOrders()`
- `bool updateLevelRankAdmin(int id, int rank)`
- `void updateLevelRewards(GJGameLevel* level)`
- `void updateSavedLevelList(GJLevelList* list)`
- `void updateUsernames()`
- `void updateUserScore()`
- `void uploadAccountComment(gd::string content)`
- `void uploadComment(gd::string content, CommentType type, int levelID, int percent)`
- `bool uploadFriendRequest(int accountID, gd::string content)`
- `void uploadLevel(GJGameLevel* level)`
- `void uploadLevelComment(int levelID, gd::string content, int percent)`
- `void uploadLevelList(GJLevelList* list)`
- `void uploadUserMessage(int accountID, gd::string subject, gd::string content)`
- `int userIDForAccountID(int id)`
- `GJUserScore* userInfoForAccountID(int id)`
- `gd::string userNameForUserID(int id)`
- `bool verifyContainerOnlyHasLevels(cocos2d::CCDictionary* dict)`
- `void verifyLevelState(GJGameLevel* level)`
- `gd::string writeSpecialFilters(GJSearchObject* object)`

**Members:**

- `gd::set<gd::string> m_queuedLists`
- `cocos2d::CCDictionary* m_mainLevels`
- `cocos2d::CCDictionary* m_searchFilters`
- `cocos2d::CCDictionary* m_onlineLevels`
- `cocos2d::CCDictionary* m_storedLevelData`
- `cocos2d::CCDictionary* m_followedCreators`
- `cocos2d::CCDictionary* m_favoriteLists`
- `cocos2d::CCDictionary* m_downloadedLevels`
- `cocos2d::CCDictionary* m_likedLevels`
- `cocos2d::CCDictionary* m_ratedLevels`
- `cocos2d::CCDictionary* m_ratedDemons`
- `cocos2d::CCDictionary* m_reportedLevels`
- `cocos2d::CCDictionary* m_onlineFolders`
- `cocos2d::CCDictionary* m_localLevelsFolders`
- `cocos2d::CCDictionary* m_dailyLevels`
- `int m_dailyTimeLeft`
- `int m_dailyID`
- `int m_activeDailyID`
- `int m_weeklyTimeLeft`
- `int m_weeklyID`
- `int m_activeWeeklyID`
- `int m_eventTimeLeft`
- `int m_eventID`
- `int m_activeEventID`
- `cocos2d::CCDictionary* m_gauntletLevels`
- `gd::map<gd::string, bool> m_availableFilters`
- `cocos2d::CCDictionary* m_timerDict`
- `cocos2d::CCDictionary* m_knownUsers`
- `cocos2d::CCDictionary* m_accountIDtoUserIDDict`
- `cocos2d::CCDictionary* m_userIDtoAccountIDDict`
- `cocos2d::CCDictionary* m_storedLevels`
- `cocos2d::CCDictionary* m_pageInfo`
- `cocos2d::CCDictionary* m_unkDict20`
- `cocos2d::CCDictionary* m_savedPacks`
- `cocos2d::CCDictionary* m_savedGauntlets`
- `cocos2d::CCDictionary* m_downloadObjects`
- `cocos2d::CCDictionary* m_friendReqAndUserBlocks`
- `cocos2d::CCDictionary* m_storedUserInfo`
- `cocos2d::CCDictionary* m_friendRequests`
- `cocos2d::CCDictionary* m_userMessages`
- `cocos2d::CCDictionary* m_userReplies`
- `cocos2d::CCDictionary* m_localLeaderboardLevels`
- `gd::string m_searchKey`
- `gd::string m_mapPackKey`
- `LeaderboardType m_leaderboardType`
- `LeaderboardStat m_leaderboardStat`
- `bool m_returnToLocalLevels`
- `LevelManagerDelegate* m_levelManagerDelegate`
- `LevelDownloadDelegate* m_levelDownloadDelegate`
- `LevelCommentDelegate* m_levelCommentDelegate`
- `CommentUploadDelegate* m_commentUploadDelegate`
- `LevelUploadDelegate* m_levelUploadDelegate`
- `ListUploadDelegate* m_listUploadDelegate`
- `LevelUpdateDelegate* m_levelUpdateDelegate`
- `LeaderboardManagerDelegate* m_leaderboardManagerDelegate`
- `LevelDeleteDelegate* m_levelDeleteDelegate`
- `LevelListDeleteDelegate* m_levelListDeleteDelegate`
- `UserInfoDelegate* m_userInfoDelegate`
- `UploadActionDelegate* m_uploadActionDelegate`
- `UserListDelegate* m_userListDelegate`
- `FriendRequestDelegate* m_friendRequestDelegate`
- `MessageListDelegate* m_messageListDelegate`
- `DownloadMessageDelegate* m_downloadMessageDelegate`
- `UploadMessageDelegate* m_uploadMessageDelegate`
- `GJRewardDelegate* m_GJRewardDelegate`
- `GJOnlineRewardDelegate* m_GJOnlineRewardDelegate`
- `GJChallengeDelegate* m_GJChallengeDelegate`
- `GJDailyLevelDelegate* m_GJDailyLevelDelegate`
- `OnlineListDelegate* m_onlineListDelegate`
- `LevelRateInfoDelegate* m_levelRateInfoDelegate`
- `SearchType m_searchType`
- `int m_mapPack`
- `gd::string m_tempSave`
- `cocos2d::CCString* m_trueString`
- `cocos2d::CCArray* m_smartTemplates`
- `GJSmartTemplate* m_smartTemplate`
- `bool m_testedNetwork`

### `GameLevelOptionsLayer` : GJOptionsLayer

**Functions:**

- `static GameLevelOptionsLayer* create(GJGameLevel* level)`
- `virtual void setupOptions()`
- `virtual void didToggle(int tag)`
- `bool init(GJGameLevel* level)`

**Members:**

- `GJGameLevel* m_level`

### `GameManager` : GManager

**Functions:**

- `static GameManager* get()`
- `static GameManager* sharedState()`
- `virtual void update(float dt)`
- `virtual bool init()`
- `virtual void encodeDataTo(DS_Dictionary* dict)`
- `virtual void dataLoaded(DS_Dictionary* dict)`
- `virtual void firstLoad()`
- `void accountStatusChanged()`
- `int activeIconForType(IconType type)`
- `void addCustomAnimationFrame(int objectID, int frameIndex, gd::string mainFrame, gd::string detailFrame)`
- `void addDuplicateLastFrame(int objectID)`
- `void addGameAnimation(int objectID, int frames, float frameTime, gd::string mainAnimFrame, gd::string detailAnimFrame, int defaultFrame)`
- `void addIconDelegate(cocos2d::CCObject* delegate, int key)`
- `void addNewCustomObject(gd::string str)`
- `void addToGJLog(cocos2d::CCString* str)`
- `void applicationDidEnterBackground()`
- `void applicationWillEnterForeground()`
- `void calculateBaseKeyForIcons()`
- `bool canShowRewardedVideo()`
- `void checkSteamAchievementUnlock()`
- `void checkUsedIcons()`
- `void claimItemsResponse(gd::string str)`
- `void clearGJLog()`
- `cocos2d::ccColor3B colorForIdx(int index)`
- `int colorForPos(int pos)`
- `gd::string colorKey(int id, UnlockType type)`
- `void completedAchievement(gd::string key)`
- `int countForType(IconType type)`
- `int defaultFrameForAnimation(int objectID)`
- `void didExitPlayscene()`
- `void doQuickSave()`
- `gd::string dpadConfigToString(UIButtonConfig& config)`
- `void eventUnlockFeature(char const* key)`
- `void fadeInMenuMusic()`
- `void fadeInMusic(gd::string path)`
- `void finishedLoadingBGAsync(cocos2d::CCObject* obj)`
- `void finishedLoadingGAsync(int index)`
- `void finishedLoadingGAsync1(cocos2d::CCObject* obj)`
- `void finishedLoadingGAsync2(cocos2d::CCObject* obj)`
- `void finishedLoadingIconAsync(cocos2d::CCObject* obj)`
- `void finishedLoadingMGAsync(int index)`
- `void finishedLoadingMGAsync1(cocos2d::CCObject* obj)`
- `void finishedLoadingMGAsync2(cocos2d::CCObject* obj)`
- `void followTwitch()`
- `void followTwitter()`
- `int framesForAnimation(int objectID)`
- `float frameTimeForAnimation(int objectID)`
- `int generateSecretNumber()`
- `const char* getBGTexture(int index)`
- `LevelEditorLayer* getEditorLayer()`
- `const char* getFontFile(int index)`
- `const char* getFontTexture(int index)`
- `GJBaseGameLayer* getGameLayer()`
- `bool getGameVariable(char const* key)`
- `bool getGameVariableDefault(const char* key, bool defaultValue)`
- `const char* getGTexture(int index)`
- `int getIconRequestID()`
- `int getIntGameVariable(char const* key)`
- `int getIntGameVariableDefault(const char* key, int defaultValue)`
- `gd::string getMenuMusicFile()`
- `const char* getMGTexture(int index)`
- `int getNextUniqueObjectKey()`
- `int getNextUsedKey(int index, bool up)`
- `cocos2d::CCArray* getOrderedCustomObjectKeys()`
- `int getPlayerBall()`
- `int getPlayerBird()`
- `int getPlayerColor()`
- `int getPlayerColor2()`
- `int getPlayerDart()`
- `int getPlayerDeathEffect()`
- `int getPlayerFrame()`
- `bool getPlayerGlow()`
- `int getPlayerGlowColor()`
- `int getPlayerJetpack()`
- `int getPlayerRobot()`
- `int getPlayerShip()`
- `int getPlayerShipFire()`
- `int getPlayerSpider()`
- `int getPlayerStreak()`
- `int getPlayerSwing()`
- `PlayLayer* getPlayLayer()`
- `gd::string getPracticeMusicFile()`
- `bool getUGV(char const* key)`
- `void getUnlockForAchievement(gd::string key, int& id, UnlockType& type)`
- `bool groundHasSecondaryColor(int index)`
- `void iconAndTypeForKey(int key, int& id, int& type)`
- `gd::string iconKey(int id, IconType type)`
- `UnlockType iconTypeToUnlockType(IconType type)`
- `bool isColorUnlocked(int id, UnlockType type)`
- `bool isIconLoaded(int id, int type)`
- `bool isIconUnlocked(int id, IconType type)`
- `void itemPurchased(char const* key)`
- `void joinDiscord()`
- `void joinReddit()`
- `int keyForIcon(int id, int type)`
- `bool levelIsPremium(int unk1, int unk2)`
- `void likeFacebook()`
- `void loadBackground(int index)`
- `void loadBackgroundAsync(int index)`
- `void loadDeathEffect(int id)`
- `void loadDpadFromString(UIButtonConfig& config, gd::string str)`
- `void loadDPadLayout(int index, bool dual)`
- `void loadFont(int index)`
- `void loadGround(int index)`
- `void loadGroundAsync(int index)`
- `cocos2d::CCTexture2D* loadIcon(int id, int type, int requestID)`
- `void loadIconAsync(int id, int type, int requestID, cocos2d::CCObject* delegate)`
- `void loadMiddleground(int index)`
- `void loadMiddlegroundAsync(int index)`
- `void loadVideoSettings()`
- `void lockColor(int id, UnlockType type)`
- `void lockIcon(int id, IconType type)`
- `void logLoadedIconInfo()`
- `void openEditorGuide()`
- `void playMenuMusic()`
- `int playSFXTrigger(SFXTriggerGameObject* object)`
- `void prepareDPadSettings()`
- `void printGJLog()`
- `void queueReloadMenu()`
- `void rateGame()`
- `void recountUserStats(gd::string str)`
- `void reloadAll(bool switchingModes, bool toFullscreen, bool unused)`
- `void reloadAll(bool switchingModes, bool toFullscreen, bool borderless, bool fix, bool unused)`
- `void reloadAllStep2()`
- `void reloadAllStep3()`
- `void reloadAllStep4()`
- `void reloadAllStep5()`
- `void reloadMenu()`
- `void removeCustomObject(int key)`
- `void removeIconDelegate(int requestID)`
- `int reorderKey(int index, bool up)`
- `void reportAchievementWithID(char const* key, int percent, bool dontNotify)`
- `void reportPercentageForLevel(int levelID, int percentage, bool isPlatformer)`
- `void resetAchievement(gd::string key)`
- `void resetAdTimer()`
- `void resetAllIcons()`
- `void resetCoinUnlocks()`
- `void resetDPadSettings(bool dual)`
- `cocos2d::CCSize resolutionForKey(int key)`
- `void resumeAudio()`
- `void resumeAudioDelayed()`
- `void returnToLastScene(GJGameLevel* level)`
- `void rewardedVideoAdFinished(int unused)`
- `void rewardedVideoHidden()`
- `void rewardedVideoHiddenDelayed()`
- `bool safePopScene()`
- `void saveAdTimer()`
- `void saveDPadLayout(int index, bool dual)`
- `void setGameVariable(char const* key, bool value)`
- `void setHasRatingPower(int hasRP)`
- `void setIntGameVariable(char const* key, int value)`
- `void setPlayerBall(int id)`
- `void setPlayerBird(int id)`
- `void setPlayerColor(int id)`
- `void setPlayerColor2(int id)`
- `void setPlayerColor3(int id)`
- `void setPlayerDart(int id)`
- `void setPlayerDeathEffect(int id)`
- `void setPlayerFrame(int id)`
- `void setPlayerGlow(bool v)`
- `void setPlayerJetpack(int id)`
- `void setPlayerRobot(int id)`
- `void setPlayerShip(int id)`
- `void setPlayerShipStreak(int id)`
- `void setPlayerSpider(int id)`
- `void setPlayerStreak(int id)`
- `void setPlayerSwing(int id)`
- `void setPlayerUserID(int id)`
- `void setUGV(char const* key, bool value)`
- `void setupGameAnimations()`
- `gd::string sheetNameForIcon(int id, int type)`
- `void shortenAdTimer(float time)`
- `bool shouldShowInterstitial(int unk1, int unk2, int unk3)`
- `bool showInterstitial()`
- `bool showInterstitialForced()`
- `bool showMainMenuAd()`
- `void startUpdate()`
- `gd::string stringForCustomObject(int customObjectID)`
- `void subYouTube()`
- `void switchCustomObjects(int key1, int key2)`
- `void switchScreenMode(bool fullscreen, bool borderless, bool fix, bool unused)`
- `void syncPlatformAchievements()`
- `bool toggleGameVariable(char const* key)`
- `void tryCacheAd()`
- `void tryShowInterstitial(int unk1, int unk2, int unk3)`
- `void unloadBackground()`
- `void unloadIcon(int id, int type, int requestID)`
- `void unloadIcons(int requestID)`
- `void unlockColor(int id, UnlockType type)`
- `void unlockedPremium()`
- `void unlockIcon(int id, IconType type)`
- `IconType unlockTypeToIconType(int type)`
- `void updateCustomFPS()`
- `void updateMusic()`
- `void verifyAchievementUnlocks()`
- `void verifyCoinUnlocks()`
- `void verifyStarUnlocks()`
- `void verifySyncedCoins()`
- `void videoAdHidden()`
- `void videoAdShowed()`

**Members:**

- `cocos2d::CCDictionary* m_mainFramesForAnimation`
- `cocos2d::CCDictionary* m_detailFramesForAnimation`
- `cocos2d::CCDictionary* m_frameTimeForAnimation`
- `cocos2d::CCDictionary* m_framesForAnimation`
- `cocos2d::CCDictionary* m_defaultFrames`
- `bool m_switchModes`
- `bool m_toFullscreen`
- `bool m_reloading`
- `bool m_fix`
- `bool m_reloadTextures`
- `bool m_unkBool2`
- `bool m_vsyncEnabled`
- `cocos2d::CCDictionary* m_valueKeeper`
- `cocos2d::CCDictionary* m_unlockValueKeeper`
- `cocos2d::CCDictionary* m_customObjectDict`
- `double m_adTimer`
- `double m_adCache`
- `bool m_unkBool3`
- `int m_unkSize4_1`
- `double m_unkDouble2`
- `int m_unkSize4_2`
- `int m_unkSize4_3`
- `bool m_loaded`
- `bool m_googlePlaySignedIn`
- `gd::string m_editorClipboard`
- `int m_copiedObjectCount`
- `PlayLayer* m_playLayer`
- `LevelEditorLayer* m_levelEditorLayer`
- `GJBaseGameLayer* m_gameLayer`
- `LevelSelectLayer* m_levelSelectLayer`
- `MenuLayer* m_menuLayer`
- `bool m_inMenuLayer`
- `void* m_premiumPopup`
- `bool m_firstSetup`
- `bool m_showedMenu`
- `bool m_unknownBool4`
- `bool m_unknownBool5`
- `gd::string m_playerUDID`
- `gd::string m_playerName`
- `bool m_scoreValid`
- `geode::SeedValueRSV m_playerUserID`
- `float m_bgVolume`
- `float m_sfxVolume`
- `float m_timeOffset`
- `bool m_ratedGame`
- `bool m_clickedFacebook`
- `bool m_clickedTwitter`
- `bool m_clickedYouTube`
- `bool m_clickedTwitch`
- `bool m_clickedDiscord`
- `bool m_clickedReddit`
- `double m_socialsDuration`
- `bool m_musicPaused`
- `bool m_isParticleObject`
- `bool m_editorEnabled`
- `int m_sceneEnum`
- `bool m_searchObjectBool`
- `geode::SeedValueRSV m_playerFrame`
- `geode::SeedValueRSV m_playerShip`
- `geode::SeedValueRSV m_playerBall`
- `geode::SeedValueRSV m_playerBird`
- `geode::SeedValueRSV m_playerDart`
- `geode::SeedValueRSV m_playerRobot`
- `geode::SeedValueRSV m_playerSpider`
- `geode::SeedValueRSV m_playerSwing`
- `geode::SeedValueRSV m_playerColor`
- `geode::SeedValueRSV m_playerColor2`
- `geode::SeedValueRSV m_playerGlowColor`
- `geode::SeedValueRSV m_playerStreak`
- `geode::SeedValueRSV m_playerShipFire`
- `geode::SeedValueRSV m_playerDeathEffect`
- `geode::SeedValueRSV m_playerJetpack`
- `geode::SeedValueRS m_chk`
- `geode::SeedValueSR m_secretNumber`
- `bool m_playerGlow`
- `IconType m_playerIconType`
- `bool m_everyPlaySetup`
- `bool m_showSongMarkers`
- `bool m_showBPMMarkers`
- `bool m_recordGameplay`
- `bool m_showProgressBar`
- `bool m_performanceMode`
- `bool m_addGlow`
- `bool m_clickedGarage`
- `bool m_clickedEditor`
- `bool m_clickedName`
- `bool m_clickedPractice`
- `bool m_showedEditorGuide`
- `bool m_showedRateDiffDialog`
- `bool m_showedRateStarDialog`
- `bool m_showedLowDetailDialog`
- `GameRateDelegate* m_gameRateDelegate1`
- `GameRateDelegate* m_gameRateDelegate2`
- `cocos2d::ccColor3B m_copiedColor`
- `int m_currentLevelID`
- `int m_currentColorChannel`
- `int m_currentGroupID`
- `int m_loadedBgID`
- `int m_loadedGroundID`
- `int m_loadedMG`
- `int m_loadedFont`
- `int m_loadedDeathEffect`
- `bool m_loadingBG`
- `bool m_loadingG`
- `bool m_loadingG1`
- `bool m_finishedLoadingG1`
- `bool m_finishedLoadingG2`
- `bool m_finishedLoadingMG1`
- `bool m_finishedLoadingMG2`
- `int m_sessionAttempts`
- `int m_sessionAttempts2`
- `int m_sessionNormalAttempts`
- `int m_bootups`
- `bool m_hasRatedGame`
- `bool m_unkBool6`
- `bool m_shouldLoadUnlockValueKeeper`
- `bool m_unkBool7`
- `bool m_unkBool8`
- `geode::SeedValueRSV m_hasRP`
- `bool m_hasDRP`
- `bool m_canGetLevelSaveData`
- `int m_resolution`
- `int m_texQuality`
- `bool m_somethingInMenuLayer`
- `DailyLevelPage* m_dailyLevelPage`
- `bool m_ropeGarageEnter`
- `int m_currentGauntlet`
- `int m_unkSize4_13`
- `bool m_unkBool10`
- `int m_unkSize4_14`
- `bool m_disableThumbstick`
- `float m_customFPSTarget`
- `bool m_loadingLevel`
- `int m_customMenuSongID`
- `int m_customPracticeSongID`
- `gd::map<int, int> m_iconLoadCounts`
- `gd::map<int, gd::map<int, int>> m_iconRequests`
- `gd::map<int, bool> m_isIconBeingLoaded`
- `gd::vector<int> m_keyStartForIcon`
- `gd::map<int, gd::vector<cocos2d::CCObject*>> m_iconDelegates`
- `int m_iconRequestID`
- `cocos2d::CCArray* m_gjLog`
- `RewardedVideoDelegate* m_rewardedVideoDelegate`
- `SearchType m_localSearchType`
- `SearchType m_savedSearchType`
- `int m_levelSearchType`
- `UIButtonConfig m_dpad1`
- `UIButtonConfig m_dpad2`
- `UIButtonConfig m_dpad3`
- `UIButtonConfig m_dpad4`
- `UIButtonConfig m_dpad5`
- `gd::string m_dpadLayout1`
- `gd::string m_dpadLayout2`
- `gd::string m_dpadLayout3`
- `gd::string m_dpadLayoutDual1`
- `gd::string m_dpadLayoutDual2`
- `gd::string m_dpadLayoutDual3`
- `int m_leaderboardLevelID`
- `int m_leaderboardLevelTime`
- `int m_leaderboardLevelPoints`
- `bool m_shouldResetShader`
- `cocos2d::CCPoint m_practicePos`
- `float m_practiceOpacity`
- `int m_unk664`

### `GameObject` : CCSpritePlus

**Functions:**

- `GameObject()`
- `~GameObject()`
- `static GameObject* createWithFrame(char const* name)`
- `static GameObject* createWithKey(int key)`
- `static bool isBasicEnterEffect(int id)`
- `static GameObject* objectFromVector(gd::vector<gd::string>& propValues, gd::vector<void*>& propIsPresent, GJBaseGameLayer* gameLayer, bool lowDetail)`
- `static void resetMID()`
- `virtual void update(float dt)`
- `virtual void setScaleX(float scaleX)`
- `virtual void setScaleY(float scaleY)`
- `virtual void setScale(float scale)`
- `virtual void setPosition(cocos2d::CCPoint const& position)`
- `virtual void setVisible(bool visible)`
- `virtual void setRotation(float rotation)`
- `virtual void setRotationX(float rotationX)`
- `virtual void setRotationY(float rotationY)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual bool initWithTexture(cocos2d::CCTexture2D* texture)`
- `virtual void setChildColor(cocos2d::ccColor3B const& color)`
- `virtual void setFlipX(bool flipX)`
- `virtual void setFlipY(bool flipY)`
- `virtual void firstSetup()`
- `virtual void customSetup()`
- `virtual void setupCustomSprites(gd::string frameName)`
- `virtual void addMainSpriteToParent(bool reorder)`
- `virtual void resetObject()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void activateObject()`
- `virtual void deactivateObject(bool deactivate)`
- `virtual void transferObjectRect(cocos2d::CCRect& rect)`
- `virtual cocos2d::CCRect const& getObjectRect()`
- `virtual cocos2d::CCRect getObjectRect(float width, float height)`
- `virtual cocos2d::CCRect const& getObjectRect2(float width, float height)`
- `virtual cocos2d::CCRect const& getObjectTextureRect()`
- `virtual cocos2d::CCPoint getRealPosition()`
- `virtual void setStartPos(cocos2d::CCPoint position)`
- `virtual void updateStartValues()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void claimParticle()`
- `virtual void unclaimParticle()`
- `virtual void particleWasActivated()`
- `virtual bool isFlipX()`
- `virtual bool isFlipY()`
- `virtual void setRScaleX(float scaleX)`
- `virtual void setRScaleY(float scaleY)`
- `virtual void setRScale(float scale)`
- `virtual float getRScaleX()`
- `virtual float getRScaleY()`
- `virtual void setRRotation(float rotation)`
- `virtual void triggerActivated(float xPosition)`
- `virtual void setObjectColor(cocos2d::ccColor3B const& color)`
- `virtual void setGlowColor(cocos2d::ccColor3B const& color)`
- `virtual void restoreObject()`
- `virtual void animationTriggered()`
- `virtual void selectObject(cocos2d::ccColor3B color)`
- `virtual void activatedByPlayer(PlayerObject* player)`
- `virtual bool hasBeenActivatedByPlayer(PlayerObject* player)`
- `virtual bool hasBeenActivated()`
- `virtual OBB2D* getOrientedBox()`
- `virtual void updateOrientedBox()`
- `virtual float getObjectRotation()`
- `virtual void updateMainColor(cocos2d::ccColor3B const& color)`
- `virtual void updateSecondaryColor(cocos2d::ccColor3B const& color)`
- `virtual int addToGroup(int id)`
- `virtual void removeFromGroup(int id)`
- `virtual void saveActiveColors()`
- `virtual float spawnXPosition()`
- `virtual bool canAllowMultiActivate()`
- `virtual void blendModeChanged()`
- `virtual void updateParticleColor(cocos2d::ccColor3B const& color)`
- `virtual void updateParticleOpacity(unsigned char opacity)`
- `virtual void updateMainParticleOpacity(unsigned char opacity)`
- `virtual void updateSecondaryParticleOpacity(unsigned char opacity)`
- `virtual bool canReverse()`
- `virtual bool isSpecialSpawnObject()`
- `virtual bool canBeOrdered()`
- `virtual cocos2d::CCLabelBMFont* getObjectLabel()`
- `virtual void setObjectLabel(cocos2d::CCLabelBMFont* label)`
- `virtual bool shouldDrawEditorHitbox()`
- `virtual bool getHasSyncedAnimation()`
- `virtual bool getHasRotateAction()`
- `virtual bool canMultiActivate(bool multiActivate)`
- `virtual void updateTextKerning(int kerning)`
- `virtual int getTextKerning()`
- `virtual bool getObjectRectDirty() const`
- `virtual void setObjectRectDirty(bool dirty)`
- `virtual bool getOrientedRectDirty() const`
- `virtual void setOrientedRectDirty(bool dirty)`
- `virtual GameObjectType getType() const`
- `virtual void setType(GameObjectType type)`
- `virtual cocos2d::CCPoint getStartPos() const`
- `void addColorSprite(gd::string frame)`
- `void addColorSpriteToParent(bool reorder)`
- `void addColorSpriteToSelf()`
- `cocos2d::CCSprite* addCustomBlackChild(gd::string frame, float opacity, bool color)`
- `cocos2d::CCSprite* addCustomChild(gd::string frame, cocos2d::CCPoint offset, int zOrder)`
- `cocos2d::CCSprite* addCustomColorChild(gd::string frame)`
- `void addEmptyGlow()`
- `void addGlow(gd::string frame)`
- `cocos2d::CCSprite* addInternalChild(cocos2d::CCSprite* parent, gd::string frame, cocos2d::CCPoint offset, int zOrder)`
- `cocos2d::CCSprite* addInternalCustomColorChild(gd::string frame, cocos2d::CCPoint offset, int zOrder)`
- `cocos2d::CCSprite* addInternalGlowChild(gd::string frame, cocos2d::CCPoint offset)`
- `void addNewSlope01(bool dontDraw)`
- `void addNewSlope01Glow(bool dontDraw)`
- `void addNewSlope02(bool dontDraw)`
- `void addNewSlope02Glow(bool dontDraw)`
- `void addRotation(float rotation)`
- `void addRotation(float rotationX, float rotationY)`
- `void addToColorGroup(int group)`
- `void addToCustomScaleX(float scale)`
- `void addToCustomScaleY(float scale)`
- `void addToOpacityGroup(int group)`
- `void addToTempOffset(double offsetX, double offsetY)`
- `void assignUniqueID()`
- `bool belongsToGroup(int group)`
- `void calculateOrientedBox()`
- `bool canChangeCustomColor()`
- `bool canChangeMainColor()`
- `bool canChangeSecondaryColor()`
- `bool canRotateFree()`
- `const cocos2d::ccColor3B& colorForMode(int id, bool mainColor)`
- `void commonInteractiveSetup()`
- `void commonSetup()`
- `void copyGroups(GameObject* object)`
- `cocos2d::CCParticleSystemQuad* createAndAddParticle(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType)`
- `void createColorGroupContainer(int size)`
- `void createGlow(gd::string frame)`
- `void createGroupContainer(int size)`
- `void createOpacityGroupContainer(int size)`
- `void createSpriteColor(int type)`
- `void deselectObject()`
- `void destroyObject()`
- `void determineSlopeDirection()`
- `bool didScaleXChange()`
- `bool didScaleYChange()`
- `void dirtifyObjectPos()`
- `void dirtifyObjectRect()`
- `void disableObject()`
- `bool dontCountTowardsLimit()`
- `void duplicateAttributes(GameObject* object)`
- `void duplicateColorMode(GameObject* object)`
- `void duplicateValues(GameObject* object)`
- `cocos2d::ccColor3B editorColorForCustomMode(int id)`
- `cocos2d::ccColor3B editorColorForMode(int id)`
- `void fastRotateObject(float rotation)`
- `cocos2d::ccColor3B const& getActiveColorForMode(int id, bool mainColor)`
- `const char* getBallFrame(int index)`
- `cocos2d::CCRect getBoundingRect()`
- `cocos2d::CCPoint const& getBoxOffset()`
- `gd::string getColorFrame(gd::string frame)`
- `int getColorIndex()`
- `gd::string getColorKey(bool isMainColor, bool colorGroups)`
- `ZLayer getCustomZLayer()`
- `gd::string getGlowFrame(gd::string frame)`
- `bool getGroupDisabled()`
- `int getGroupID(int index)`
- `gd::string getGroupString()`
- `cocos2d::CCPoint const& getLastPosition()`
- `GJSpriteColor* getMainColor()`
- `int getMainColorMode()`
- `int getObjectDirection()`
- `float getObjectRadius()`
- `cocos2d::CCRect* getObjectRectPointer()`
- `ZLayer getObjectZLayer()`
- `int getObjectZOrder()`
- `cocos2d::CCRect getOuterObjectRect()`
- `int getParentMode()`
- `GJSpriteColor* getRelativeSpriteColor(int type)`
- `cocos2d::CCPoint getScalePosDelta()`
- `GJSpriteColor* getSecondaryColor()`
- `int getSecondaryColorMode()`
- `float getSlopeAngle()`
- `cocos2d::CCPoint getUnmodifiedPosition()`
- `cocos2d::ccColor3B const& groupColor(cocos2d::ccColor3B const& color, bool mainColor)`
- `float groupOpacityMod()`
- `void groupWasDisabled()`
- `void groupWasEnabled()`
- `bool hasSecondaryColor()`
- `bool ignoreEditorDuration()`
- `bool ignoreEnter()`
- `bool ignoreFade()`
- `bool init(char const* frame)`
- `bool isBasicTrigger()`
- `bool isColorObject()`
- `bool isColorTrigger()`
- `bool isConfigurablePortal()`
- `bool isEditorSpawnableTrigger()`
- `bool isFacingDown()`
- `bool isFacingLeft()`
- `bool isSettingsObject()`
- `bool isSpawnableTrigger()`
- `bool isSpecialObject()`
- `bool isSpeedObject()`
- `bool isStoppableTrigger()`
- `bool isTrigger()`
- `void loadGroupsFromString(gd::string groupList)`
- `void makeInvisible()`
- `void makeVisible()`
- `float opacityModForMode(int id, bool mainColor)`
- `cocos2d::CCNode* parentForZLayer(int zLayer, bool blending, int parentMode)`
- `gd::string perspectiveColorFrame(char const* prefix, int index)`
- `gd::string perspectiveFrame(char const* prefix, int index)`
- `void playDestroyObjectAnim(GJBaseGameLayer* layer)`
- `void playPickupAnimation(cocos2d::CCSprite* target, float offset, float duration, float randomValue1, float randomValue2)`
- `void playPickupAnimation(cocos2d::CCSprite* target, float xOffset, float yOffset, float controlYOffset1, float controlYOffset2, float endYOffset, float duration, float fadeDelay, float fadeDuration, bool rotate, float randomValue1, float randomValue2)`
- `void playShineEffect()`
- `void quickUpdatePosition()`
- `void quickUpdatePosition2()`
- `void removeColorSprite()`
- `void removeGlow()`
- `void reorderColorSprite()`
- `void resetColorGroups()`
- `void resetGroupDisabled()`
- `void resetGroups()`
- `void resetMainColorMode()`
- `void resetMoveOffset()`
- `void resetRScaleForced()`
- `void resetSecondaryColorMode()`
- `void setAreaOpacity(float step, float value, int index)`
- `void setCustomZLayer(int zLayer)`
- `void setDefaultMainColorMode(int id)`
- `void setDefaultSecondaryColorMode(int id)`
- `void setGlowOpacity(unsigned char opacity)`
- `void setLastPosition(cocos2d::CCPoint const& position)`
- `void setMainColorMode(int id)`
- `void setSecondaryColorMode(int id)`
- `void setupColorSprite(int id, bool mainColor)`
- `void setupPixelScale()`
- `void setupSpriteSize()`
- `bool shouldBlendColor(GJSpriteColor* color, bool mainColor)`
- `bool shouldLockX()`
- `bool shouldNotHideAnimFreeze()`
- `bool shouldShowPickupEffects()`
- `bool slopeFloorTop()`
- `bool slopeWallLeft()`
- `double slopeYPos(GameObject* object)`
- `double slopeYPos(cocos2d::CCRect rect)`
- `double slopeYPos(float x)`
- `void spawnDefaultPickupParticle(GJBaseGameLayer* layer)`
- `void updateBlendMode()`
- `void updateCustomColorType(short type)`
- `void updateCustomScaleX(float scaleX)`
- `void updateCustomScaleY(float scaleY)`
- `void updateHSVState()`
- `void updateIsOriented()`
- `void updateMainColor()`
- `void updateMainColorOnly()`
- `void updateMainOpacity()`
- `void updateObjectEditorColor()`
- `void updateSecondaryColor()`
- `void updateSecondaryColorOnly()`
- `void updateSecondaryOpacity()`
- `void updateStartPos()`
- `void updateUnmodifiedPositions()`
- `bool usesFreezeAnimation()`
- `bool usesSpecialAnimation()`

**Members:**

- `int m_someOtherIndex`
- `int m_innerSectionIndex`
- `int m_outerSectionIndex`
- `int m_middleSectionIndex`
- `bool m_hasExtendedCollision`
- `cocos2d::ccColor3B m_groupColor`
- `bool m_isColorSpriteBlack`
- `bool m_isObjectBlack`
- `float m_blackChildOpacity`
- `bool m_blackChildOpacityLocked`
- `bool m_editorEnabled`
- `bool m_isGroupDisabled`
- `bool m_isGroupDisabledTemp`
- `bool m_unk28c`
- `int m_activeMainColorID`
- `int m_activeDetailColorID`
- `bool m_baseUsesHSV`
- `bool m_detailUsesHSV`
- `float m_positionXOffset`
- `float m_positionYOffset`
- `float m_rotationXOffset`
- `float m_unk2A8`
- `float m_rotationYOffset`
- `float m_unk2B0`
- `float m_scaleXOffset`
- `float m_scaleYOffset`
- `float m_unk2BC`
- `float m_unk2C0`
- `bool m_tempOffsetXRelated`
- `bool m_isFlipX`
- `bool m_isFlipY`
- `cocos2d::CCPoint m_customBoxOffset`
- `bool m_boxOffsetCalculated`
- `cocos2d::CCPoint m_boxOffset`
- `OBB2D* m_orientedBox`
- `bool m_shouldUseOuterOb`
- `cocos2d::CCSprite* m_glowSprite`
- `bool m_isRingPoweredOn`
- `float m_width`
- `float m_height`
- `bool m_addToNodeContainer`
- `bool m_isActivated`
- `bool m_isDisabled2`
- `cocos2d::CCParticleSystemQuad* m_particle`
- `gd::string m_particleString`
- `bool m_hasParticles`
- `bool m_particleUseObjectColor`
- `bool m_hasColorSprite`
- `cocos2d::CCPoint m_particleOffset`
- `bool m_isParticleSpriteLocked`
- `cocos2d::CCRect m_textureRect`
- `bool m_isDirty`
- `bool m_isObjectPosDirty`
- `bool m_isUnmodifiedPosDirty`
- `float m_fadeMargin`
- `cocos2d::CCRect m_objectRect`
- `bool m_isObjectRectDirty`
- `bool m_isOrientedBoxDirty`
- `bool m_colorSpriteLocked`
- `bool m_unk353`
- `bool m_canRotateFree`
- `bool m_isMirroredByScale`
- `int m_linkedGroup`
- `int m_unk35C`
- `short m_colorType`
- `short m_childColorType`
- `bool m_shouldBlendBase`
- `bool m_shouldBlendDetail`
- `bool m_hasCustomChild`
- `bool m_unk367`
- `cocos2d::CCSprite* m_colorSprite`
- `bool m_unk370`
- `float m_objectRadius`
- `bool m_isRotationAligned`
- `float m_spriteWidthScale`
- `float m_spriteHeightScale`
- `int m_uniqueID`
- `GameObjectType m_objectType`
- `GameObjectType m_savedObjectType`
- `int m_unk390`
- `float m_unmodifiedPositionX`
- `float m_unmodifiedPositionY`
- `double m_positionX`
- `double m_positionY`
- `cocos2d::CCPoint m_startPosition`
- `bool m_usesAudioScale`
- `bool m_hasNoAudioScale`
- `bool m_isDisabled`
- `float m_startRotationX`
- `float m_startRotationY`
- `float m_startScaleX`
- `float m_startScaleY`
- `float m_customScaleX`
- `float m_customScaleY`
- `bool m_startFlipX`
- `bool m_startFlipY`
- `bool m_unk3ee`
- `bool m_isInvisible`
- `int m_unk3D8`
- `short m_varianceIndex`
- `bool m_unk3DE`
- `short m_enterType`
- `short m_exitType`
- `short m_enterChannel`
- `short m_objectMaterial`
- `bool m_unk3E8`
- `short m_parentMode`
- `bool m_hasNoGlow`
- `int m_targetColor`
- `int m_objectID`
- `bool m_unk3F8`
- `bool m_intrinsicDontFade`
- `bool m_ignoreEnter`
- `bool m_ignoreFade`
- `bool m_isSolidColorBlock`
- `bool m_unk3FD`
- `bool m_customSpriteColor`
- `short m_customColorType`
- `bool m_isDontEnter`
- `bool m_isDontFade`
- `bool m_hasNoEffects`
- `bool m_hasNoParticles`
- `int m_defaultZOrder`
- `bool m_unk40C`
- `bool m_colorZLayerRelated`
- `bool m_customAudioScale`
- `float m_minAudioScale`
- `float m_maxAudioScale`
- `bool m_particleLocked`
- `int m_property53`
- `bool m_isInvisibleBlock`
- `bool m_customGlowColor`
- `bool m_glowColorIsLBG`
- `bool m_cantColorGlow`
- `float m_opacityMod`
- `bool m_slopeUphill`
- `int m_slopeDirection`
- `bool m_slopeIsHazard`
- `float m_opacityMod2`
- `GJSpriteColor* m_baseColor`
- `GJSpriteColor* m_detailColor`
- `bool m_baseOrDetailBlending`
- `ZLayer m_defaultZLayer`
- `bool m_zFixedZLayer`
- `ZLayer m_zLayer`
- `int m_zOrder`
- `bool m_wasSelected`
- `bool m_isSelected`
- `float m_unk460`
- `cocos2d::CCPoint m_unk464`
- `bool m_updateParents`
- `bool m_updateEditorColor`
- `bool m_hasGroupParent`
- `bool m_hasAreaParent`
- `float m_scaleX`
- `float m_scaleY`
- `std::array<short, 10>* m_groups`
- `short m_groupCount`
- `bool m_hasGroupParentsString`
- `std::array<short, 10>* m_colorGroups`
- `short m_colorGroupCount`
- `std::array<short, 10>* m_opacityGroups`
- `short m_opacityGroupCount`
- `short m_editorLayer`
- `short m_editorLayer2`
- `int m_enabledGroupsCounter`
- `bool m_updateCustomContentSize`
- `bool m_hasContentSize`
- `bool m_isNoTouch`
- `cocos2d::CCSize m_lastSize`
- `cocos2d::CCPoint m_lastPosition`
- `int m_unk4C0`
- `int m_unk4C4`
- `int m_unk4C8`
- `int m_unk4CC`
- `GameObjectClassType m_classType`
- `bool m_isTrigger`
- `bool m_isSpawnOrderTrigger`
- `bool m_isColorTrigger`
- `bool m_dontIgnoreDuration`
- `bool m_canBeControlled`
- `bool m_activateTriggerInEditor`
- `bool m_isStartPos`
- `bool m_isHighDetail`
- `ColorActionSprite* m_mainActionSprite`
- `ColorActionSprite* m_detailActionSprite`
- `GJEffectManager* m_goEffectManager`
- `bool m_unk4F8`
- `bool m_isDecoration`
- `bool m_isDecoration2`
- `bool m_unk4fb`
- `bool m_maybeNotColorable`
- `bool m_isPassable`
- `bool m_isHide`
- `bool m_isNonStickX`
- `bool m_isNonStickY`
- `bool m_isIceBlock`
- `bool m_isGripSlope`
- `bool m_isScaleStick`
- `bool m_isExtraSticky`
- `bool m_isDontBoostY`
- `bool m_isDontBoostX`
- `bool m_unk507`
- `bool m_unk508`
- `float m_unk50C`
- `float m_pixelScaleX`
- `float m_pixelScaleY`
- `int m_mainColorKeyIndex`
- `int m_detailColorKeyIndex`
- `uint8_t m_areaOpacityRelated`
- `float m_areaOpacityValue`
- `int m_areaOpacityIndex`
- `int m_unk52C`
- `bool m_unk530`
- `bool m_isUIObject`
- `bool m_greenDebugDraw`

### `GameObjectCopy` : cocos2d::CCObject

**Functions:**

- `static GameObjectCopy* create(GameObject* object)`
- `bool init(GameObject* object)`
- `void resetObject()`

**Members:**

- `GameObject* m_object`
- `cocos2d::CCPoint m_position`
- `float m_rotationX`
- `float m_rotationY`
- `bool m_isFlipX`
- `bool m_isFlipY`
- `float m_customScaleX`
- `float m_customScaleY`

### `GameObjectEditorState`

**Functions:**

- `void loadValues(GameObject* obj)`

**Members:**

- `cocos2d::CCPoint m_position`
- `float m_scaleX`
- `float m_scaleY`
- `float m_rotationX`
- `float m_rotationY`

### `GameOptionsLayer` : GJOptionsLayer

**Functions:**

- `GameOptionsLayer()`
- `static GameOptionsLayer* create(GJBaseGameLayer* baseGameLayer)`
- `virtual void setupOptions()`
- `virtual void didToggle(int tag)`
- `bool init(GJBaseGameLayer* baseGameLayer)`
- `void onPracticeMusicSync(cocos2d::CCObject* sender)`
- `void onUIOptions(cocos2d::CCObject* sender)`
- `void onUIPOptions(cocos2d::CCObject* sender)`
- `void showPracticeMusicSyncUnlockInfo()`

**Members:**

- `GJBaseGameLayer* m_baseGameLayer`
- `int m_practiceDialogIndex`

### `GameOptionsTrigger` : EffectGameObject

**Functions:**

- `GameOptionsTrigger()`
- `static GameOptionsTrigger* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `GameOptionsSetting m_streakAdditive`
- `GameOptionsSetting m_unlinkDualGravity`
- `GameOptionsSetting m_hideGround`
- `GameOptionsSetting m_hideP1`
- `GameOptionsSetting m_hideP2`
- `GameOptionsSetting m_disableP1Controls`
- `GameOptionsSetting m_disableP2Controls`
- `GameOptionsSetting m_hideMG`
- `GameOptionsSetting m_hideAttempts`
- `GameOptionsSetting m_editRespawnTime`
- `float m_respawnTime`
- `GameOptionsSetting m_audioOnDeath`
- `GameOptionsSetting m_noDeathSFX`
- `GameOptionsSetting m_boostSlide`

### `GameRateDelegate`

**Functions:**

- `virtual void updateRate()`

### `GameStatsManager` : cocos2d::CCNode

**Functions:**

- `static GameStatsManager* get()`
- `static GameStatsManager* sharedState()`
- `virtual bool init()`
- `int accountIDForIcon(int id, UnlockType type)`
- `void addSimpleSpecialChestReward(gd::string key, UnlockType type, int id, bool unused)`
- `void addSpecialRewardDescription(gd::string key, gd::string description)`
- `void addStoreItem(int index, int id, int unlockType, int price, ShopType shopType)`
- `bool areChallengesLoaded()`
- `bool areRewardsLoaded()`
- `void awardCurrencyForLevel(GJGameLevel* level)`
- `void awardDiamondsForLevel(GJGameLevel* level)`
- `void awardOldSpecialStats()`
- `bool awardSecretKey()`
- `bool canItemBeUnlocked(int id, UnlockType type)`
- `void checkAchievement(char const* statKey)`
- `void checkCoinAchievement(GJGameLevel* level)`
- `void checkCoinsForLevel(GJGameLevel* level)`
- `bool claimListReward(GJLevelList* list)`
- `void collectReward(GJRewardType type, GJRewardItem* item)`
- `void collectVideoReward(int orbs)`
- `void completedChallenge(GJChallengeItem* item)`
- `GJRewardItem* completedDailyLevel(GJGameLevel* level)`
- `void completedDemonLevel(GJGameLevel* level)`
- `void completedLevel(GJGameLevel* level)`
- `void completedMapPack(GJMapPack* pack)`
- `void completedStarLevel(GJGameLevel* level)`
- `int countSecretChests(GJRewardType rewardType)`
- `int countUnlockedSecretChests(GJRewardType rewardType)`
- `GJRewardItem* createReward(GJRewardType type, int id, gd::string str)`
- `void createSecretChestItems()`
- `void createSecretChestRewards()`
- `void createSpecialChestItems()`
- `void createStoreItems()`
- `void dataLoaded(DS_Dictionary* dict)`
- `void encodeDataTo(DS_Dictionary* dict)`
- `void firstSetup()`
- `void generateItemUnlockableData()`
- `int getAwardedCurrencyForLevel(GJGameLevel* level)`
- `int getAwardedDiamondsForLevel(GJGameLevel* level)`
- `int getBaseCurrency(int stars, bool mainLevel, int levelID)`
- `int getBaseCurrencyForLevel(GJGameLevel* level)`
- `int getBaseDiamonds(int stars)`
- `int getBonusDiamonds(int stars)`
- `GJChallengeItem* getChallenge(int id)`
- `gd::string getChallengeKey(GJChallengeItem* chal)`
- `int getCollectedCoinsForLevel(GJGameLevel* level)`
- `cocos2d::CCArray* getCompletedMapPacks()`
- `gd::string getCurrencyKey(GJGameLevel* level)`
- `gd::string getDailyLevelKey(int dailyID)`
- `const char* getDemonLevelKey(GJGameLevel* level)`
- `gd::string getEventRewardKey(int id)`
- `gd::string getGauntletRewardKey(int id)`
- `gd::string getItemKey(int id, int type)`
- `int getItemUnlockState(int itemID, UnlockType unlockType)`
- `int getItemUnlockStateLite(int id, UnlockType type)`
- `gd::string getLevelKey(GJGameLevel* level)`
- `gd::string getLevelKey(int levelID, bool isOnline, bool isDaily, bool isGauntlet, bool isEvent)`
- `gd::string getListRewardKey(GJLevelList* list)`
- `const char* getMapPackKey(int id)`
- `int getNextGoldChestID()`
- `gd::string getNextVideoAdReward()`
- `gd::string getPathRewardKey(int id)`
- `GJChallengeItem* getQueuedChallenge(int id)`
- `GJRewardItem* getRewardForSecretChest(int id)`
- `GJRewardItem* getRewardForSpecialChest(gd::string key)`
- `GJRewardItem* getRewardItem(GJRewardType type)`
- `gd::string getRewardKey(GJRewardType type, int id)`
- `GJChallengeItem* getSecondaryQueuedChallenge(int id)`
- `int getSecretChestForItem(int id, UnlockType type)`
- `const char* getSecretCoinKey(char const* key)`
- `gd::string getSecretOnlineRewardKey(int id)`
- `cocos2d::CCString* getSpecialChestKeyForItem(int id, UnlockType type)`
- `gd::string getSpecialRewardDescription(gd::string key, bool unused)`
- `gd::string getSpecialUnlockDescription(int id, UnlockType type, bool unused)`
- `char const* getStarLevelKey(GJGameLevel* level)`
- `int getStat(char const* key)`
- `int getStatFromKey(StatKey key)`
- `GJStoreItem* getStoreItem(int index)`
- `GJStoreItem* getStoreItem(int id, int type)`
- `int getTotalCollectedCurrency()`
- `int getTotalCollectedDiamonds()`
- `bool hasClaimedListReward(GJLevelList* list)`
- `bool hasCompletedChallenge(GJChallengeItem* item)`
- `bool hasCompletedDailyLevel(int dailyID)`
- `bool hasCompletedDemonLevel(GJGameLevel* level)`
- `bool hasCompletedGauntletLevel(int id)`
- `bool hasCompletedLevel(GJGameLevel* level)`
- `bool hasCompletedMainLevel(int levelID)`
- `bool hasCompletedMapPack(int id)`
- `bool hasCompletedOnlineLevel(int id)`
- `bool hasCompletedStarLevel(GJGameLevel* level)`
- `bool hasPendingUserCoin(char const* key)`
- `bool hasRewardBeenCollected(GJRewardType type, int id)`
- `bool hasSecretCoin(char const* key)`
- `bool hasUserCoin(char const* key)`
- `void incrementActivePath(int amount)`
- `void incrementChallenge(GJChallengeType type, int amount)`
- `void incrementStat(char const* key)`
- `void incrementStat(char const* key, int amount)`
- `bool isGauntletChestUnlocked(int id)`
- `bool isGauntletUnlocked(int id)`
- `bool isItemEnabled(UnlockType type, int id)`
- `bool isItemUnlocked(UnlockType type, int id)`
- `bool isPathChestUnlocked(int path)`
- `bool isPathUnlocked(StatKey key)`
- `bool isSecretChestUnlocked(int id)`
- `bool isSecretCoin(gd::string key)`
- `bool isSecretCoinValid(gd::string key)`
- `bool isSpecialChestLiteUnlockable(gd::string key)`
- `bool isSpecialChestUnlocked(gd::string key)`
- `bool isStoreItemUnlocked(int index)`
- `int keyCostForSecretChest(int id)`
- `void linkSpecialChestUnlocks(GJRewardItem* item, gd::string key)`
- `void logCoins()`
- `void markLevelAsCompletedAndClaimed(GJGameLevel* level)`
- `void postLoadGameStats()`
- `void preProcessReward(GJRewardItem* item)`
- `void preSaveGameStats()`
- `void processChallengeQueue(int position)`
- `void processOnlineChests()`
- `bool purchaseItem(int index)`
- `void recountSpecialStats()`
- `void recountUserCoins(bool force)`
- `void registerRewardsFromItem(GJRewardItem* item)`
- `void removeChallenge(int position)`
- `void removeErrorFromSpecialChests()`
- `void removeQueuedChallenge(int position)`
- `void removeQueuedSecondaryChallenge(int position)`
- `void resetChallengeTimer()`
- `void resetPreSync()`
- `void resetSpecialChest(gd::string key)`
- `void resetSpecialStatAchievements()`
- `void resetUserCoins()`
- `void restorePostSync()`
- `void setAwardedBonusKeys(int keys)`
- `void setStarsForMapPack(int id, int stars)`
- `void setStat(char const* key, int value)`
- `void setStatIfHigher(char const* key, int value)`
- `void setupIconCredits()`
- `ShopType shopTypeForItemID(int index)`
- `bool shouldAwardSecretKey()`
- `int starsForMapPack(int id)`
- `void storeChallenge(int position, GJChallengeItem* challenge)`
- `void storeChallengeTime(int remaining)`
- `void storeEventChest(int eventID, GJRewardItem* item)`
- `void storeOnlineChest(gd::string key, GJRewardItem* item)`
- `void storePendingUserCoin(char const* key)`
- `void storeQueuedChallenge(int position, GJChallengeItem* challenge)`
- `void storeRewardState(GJRewardType type, int id, int remaining, gd::string str)`
- `void storeSecondaryQueuedChallenge(int position, GJChallengeItem* challenge)`
- `void storeSecretCoin(char const* key)`
- `void storeUserCoin(char const* key)`
- `void tempClear()`
- `void toggleEnableItem(UnlockType type, int id, bool enabled)`
- `void tryFixPathBug()`
- `void trySelectActivePath()`
- `void uncompleteLevel(GJGameLevel* level)`
- `void unlockGauntlet(int id)`
- `GJRewardItem* unlockGauntletChest(int id)`
- `GJRewardItem* unlockGoldChest(int id)`
- `GJRewardItem* unlockOnlineChest(gd::string key)`
- `GJRewardItem* unlockPathChest(int id)`
- `GJRewardItem* unlockSecretChest(int id)`
- `GJRewardItem* unlockSpecialChest(gd::string key)`
- `void updateActivePath(StatKey key)`
- `gd::string usernameForAccountID(int id)`
- `void verifyPathAchievements()`
- `void verifyUserCoins()`

**Members:**

- `bool m_usePlayerStatsCCDictionary`
- `cocos2d::CCString* m_trueString`
- `cocos2d::CCDictionary* m_allStoreItems`
- `cocos2d::CCDictionary* m_storeItems`
- `cocos2d::CCDictionary* m_allTreasureRoomChests`
- `cocos2d::CCDictionary* m_allTreasureRoomChestItems`
- `cocos2d::CCDictionary* m_allSpecialChests`
- `cocos2d::CCDictionary* m_allSpecialChestItems`
- `gd::unordered_map<gd::string, gd::string> m_specialRewardDescriptions`
- `gd::unordered_map<gd::string, gd::string> m_createSpecialChestItemsMap`
- `cocos2d::CCDictionary* m_specialChestsLite`
- `cocos2d::CCArray* m_storeItemArray`
- `cocos2d::CCDictionary* m_rewardItems`
- `cocos2d::CCDictionary* m_dailyChests`
- `cocos2d::CCDictionary* m_worldAdvertChests`
- `cocos2d::CCDictionary* m_activeChallenges`
- `cocos2d::CCDictionary* m_upcomingChallenges`
- `double m_challengeTime`
- `cocos2d::CCDictionary* m_playerStats`
- `gd::unordered_map<int, int> m_playerStatsRandMap`
- `gd::unordered_map<int, int> m_playerStatsSeedMap`
- `cocos2d::CCDictionary* m_completedLevels`
- `cocos2d::CCDictionary* m_verifiedUserCoins`
- `cocos2d::CCDictionary* m_pendingUserCoins`
- `cocos2d::CCDictionary* m_purchasedItems`
- `cocos2d::CCDictionary* m_onlineCurrencyScores`
- `cocos2d::CCDictionary* m_mainCurrencyScores`
- `cocos2d::CCDictionary* m_gauntletCurrencyScores`
- `cocos2d::CCDictionary* m_timelyCurrencyScores`
- `cocos2d::CCDictionary* m_onlineStars`
- `cocos2d::CCDictionary* m_timelyStars`
- `cocos2d::CCDictionary* m_gauntletDiamondScores`
- `cocos2d::CCDictionary* m_timelyDiamondScores`
- `cocos2d::CCDictionary* m_unusedCurrencyAwardDict`
- `cocos2d::CCDictionary* m_challengeDiamonds`
- `cocos2d::CCDictionary* m_completedMappacks`
- `cocos2d::CCDictionary* m_completedLists`
- `cocos2d::CCDictionary* m_weeklyChest`
- `cocos2d::CCDictionary* m_eventChest`
- `cocos2d::CCDictionary* m_treasureRoomChests`
- `geode::SeedValueRSV m_bonusKey`
- `cocos2d::CCDictionary* m_miscChests`
- `cocos2d::CCDictionary* m_enabledItems`
- `cocos2d::CCDictionary* m_wraithChests`
- `bool m_skipIncrementChallenge`
- `cocos2d::CCDictionary* m_unlockedGauntlets`
- `cocos2d::CCDictionary* m_unkDict`
- `cocos2d::CCDictionary* m_unlockedItems`
- `gd::map<std::pair<int, UnlockType>, int> m_accountIDForIcon`
- `gd::map<int, gd::string> m_usernameForAccountID`
- `gd::set<std::pair<UnlockType, int>> m_wraithIcons`
- `bool m_pathBugFixed`
- `bool m_tryFixPathBug`
- `int m_activePath`

### `GameToolbox`

**Functions:**

- `static void addBackButton(cocos2d::CCLayer* parent, cocos2d::CCMenuItem* menuItem)`
- `static void addRThumbScrollButton(cocos2d::CCLayer* parent)`
- `static void alignItemsHorisontally(cocos2d::CCArray* items, float gap, cocos2d::CCPoint position, bool skipSize)`
- `static void alignItemsVertically(cocos2d::CCArray* items, float gap, cocos2d::CCPoint position)`
- `static float bounceTime(float time)`
- `static cocos2d::ccColor3B colorToSepia(cocos2d::ccColor3B color, float factor)`
- `static void contentScaleClipRect(cocos2d::CCRect& rect)`
- `static gd::string createHashString(gd::string const& str, int length)`
- `static CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, cocos2d::CCArray* container)`
- `static CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, float buttonScale, float maxLabelScale, float maxLabelWidth, cocos2d::CCPoint labelOffset, char const* font, bool labelTop, int labelTag, cocos2d::CCArray* container)`
- `static bool doWeHaveInternet()`
- `static gd::string easeToText(int easingType)`
- `static uint64_t fast_rand()`
- `static float fast_rand_0_1()`
- `static float fast_rand_minus1_1()`
- `static void fast_srand(uint64_t seed)`
- `static gd::string gen_random(int length)`
- `static cocos2d::CCSequence* getDropActionWDelay(float delay, float duration, float scale, cocos2d::CCNode* target, cocos2d::SEL_CallFunc selector)`
- `static cocos2d::CCSequence* getDropActionWEnd(float delay, float duration, float scale, cocos2d::CCAction* action, float actionDelay)`
- `static cocos2d::CCActionInterval* getEasedAction(cocos2d::CCActionInterval* action, int easingType, float easingRate)`
- `static float getEasedValue(float value, int easingType, float easingRate)`
- `static uint64_t getfast_srand()`
- `static int getInvertedEasing(int easingType)`
- `static cocos2d::CCDictionary* getLargestMergedIntDicts(cocos2d::CCDictionary* dict1, cocos2d::CCDictionary* dict2)`
- `static cocos2d::ccHSVValue getMultipliedHSV(cocos2d::ccHSVValue const& value, float factor)`
- `static cocos2d::CCPoint getRelativeOffset(GameObject* object, cocos2d::CCPoint offset)`
- `static gd::string getResponse(cocos2d::extension::CCHttpResponse* response)`
- `static gd::string getTimeString(int seconds, bool noSeconds)`
- `static cocos2d::ccHSVValue hsvFromString(gd::string const& str, char const* delim)`
- `static gd::string intToShortString(int value)`
- `static gd::string intToString(int value)`
- `static bool isIOS()`
- `static bool isRateEasing(int easingType)`
- `static void mergeDictsSaveLargestInt(cocos2d::CCDictionary* toDict, cocos2d::CCDictionary* fromDict)`
- `static void mergeDictsSkipConflict(cocos2d::CCDictionary* toDict, cocos2d::CCDictionary* fromDict)`
- `static gd::string msToTimeString(int milliseconds, int formattingMode)`
- `static cocos2d::ccColor3B multipliedColorValue(cocos2d::ccColor3B minColor, cocos2d::ccColor3B maxColor, float factor)`
- `static void openAppPage()`
- `static void openRateURL(gd::string str1, gd::string str2)`
- `static cocos2d::CCParticleSystemQuad* particleFromString(gd::string const& str, cocos2d::CCParticleSystemQuad* system, bool dontUpdate)`
- `static cocos2d::CCParticleSystemQuad* particleFromStruct(cocos2d::ParticleStruct const& particleStruct, cocos2d::CCParticleSystemQuad* system, bool dontUpdate)`
- `static void particleStringToStruct(gd::string const& str, cocos2d::ParticleStruct& particleStruct)`
- `static gd::string pointsToString(int points)`
- `static void postClipVisit()`
- `static void preVisitWithClippingRect(cocos2d::CCNode* node, cocos2d::CCRect rect)`
- `static void preVisitWithClipRect(cocos2d::CCRect rect)`
- `static gd::string saveParticleToString(cocos2d::CCParticleSystemQuad* system)`
- `static bool saveStringToFile(gd::string const& path, gd::string const& content)`
- `static gd::string stringFromHSV(cocos2d::ccHSVValue value, char const* separator)`
- `static cocos2d::CCDictionary* stringSetupToDict(gd::string const& str, char const* separator)`
- `static void stringSetupToMap(gd::string const& str, char const* separator, gd::map<gd::string, gd::string>& setup)`
- `static cocos2d::ccColor3B strongColor(cocos2d::ccColor3B color)`
- `static gd::string timestampToHumanReadable(time_t timestamp)`
- `static cocos2d::ccColor3B transformColor(cocos2d::ccColor3B const& color, cocos2d::ccHSVValue hsv)`
- `static cocos2d::ccColor3B transformColor(cocos2d::ccColor3B const& color, float h, float s, float v)`

### `GauntletLayer` : cocos2d::CCLayer, LevelManagerDelegate

**Functions:**

- `GauntletLayer()`
- `~GauntletLayer()`
- `static GauntletLayer* create(GauntletType type)`
- `static cocos2d::CCScene* scene(GauntletType type)`
- `virtual void keyBackClicked()`
- `virtual void loadLevelsFinished(cocos2d::CCArray* levels, char const* key, int type)`
- `virtual void loadLevelsFailed(char const* key, int type)`
- `bool init(GauntletType type)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onLevel(cocos2d::CCObject* sender)`
- `void setupGauntlet(cocos2d::CCArray* levels)`
- `void unlockActiveItem()`

**Members:**

- `cocos2d::CCArray* m_levels`
- `LoadingCircle* m_loadingCircle`
- `GauntletType m_gauntletType`
- `cocos2d::CCSprite* m_backgroundSprite`
- `void* m_unkPtr`
- `CCMenuItemSpriteExtra* m_activeItemButton`
- `cocos2d::CCArray* m_activeObjects`
- `TextArea* m_tryAgainText`

### `GauntletNode` : cocos2d::CCNode

**Functions:**

- `GauntletNode()`
- `static GauntletNode* create(GJMapPack* gauntlet)`
- `static gd::string frameForType(GauntletType type)`
- `static gd::string nameForType(GauntletType type)`
- `void generateNode()`
- `bool init(GJMapPack* gauntlet)`
- `void onClaimReward()`
- `void onUnlock()`
- `void showUnlockAnimation()`

**Members:**

- `cocos2d::CCNode* m_gauntletInfoNode`
- `cocos2d::CCNode* m_rewardNode`
- `cocos2d::ccColor3B m_labelColor`
- `cocos2d::ccColor3B m_backgroundColor`
- `GJMapPack* m_gauntlet`
- `bool m_locked`

### `GauntletSelectLayer` : cocos2d::CCLayer, BoomScrollLayerDelegate, LevelManagerDelegate, RewardedVideoDelegate

**Functions:**

- `GauntletSelectLayer()`
- `~GauntletSelectLayer()`
- `static GauntletSelectLayer* create(int unused)`
- `static cocos2d::CCScene* scene(int unused)`
- `virtual void onExit()`
- `virtual void keyBackClicked()`
- `virtual void rewardedVideoFinished()`
- `virtual void scrollLayerWillScrollToPage(BoomScrollLayer* layer, int page)`
- `virtual void scrollLayerScrolledToPage(BoomScrollLayer* layer, int page)`
- `virtual void loadLevelsFinished(cocos2d::CCArray* gauntlets, char const* key, int type)`
- `virtual void loadLevelsFailed(char const* key, int type)`
- `void goToPage(int page, bool instant)`
- `bool init(int unused)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNext(cocos2d::CCObject* sender)`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onPrev(cocos2d::CCObject* sender)`
- `void onRefresh(cocos2d::CCObject* sender)`
- `void playUnlockAnimation()`
- `void setupGauntlets()`
- `void showUnlockGauntlet()`
- `void unblockPlay()`
- `void unlockAnimationFinished()`
- `void unlockAnimationStep2()`
- `void unlockAnimationStep3()`
- `void updateArrows()`

**Members:**

- `cocos2d::CCSprite* m_backgroundSprite`
- `BoomScrollLayer* m_scrollLayer`
- `CCMenuItemSpriteExtra* m_leftButton`
- `CCMenuItemSpriteExtra* m_rightButton`
- `CCMenuItemSpriteExtra* m_refreshButton`
- `bool m_exiting`
- `bool m_playing`
- `TextArea* m_tryAgainText`
- `LoadingCircle* m_loadingCircle`
- `cocos2d::CCDictionary* m_gauntlets`
- `bool m_playBlocked`
- `int m_gauntletID`
- `bool m_videoPlaying`
- `bool m_locked`

### `GauntletSprite` : cocos2d::CCNode

**Functions:**

- `GauntletSprite()`
- `static GauntletSprite* create(GauntletType type, bool locked)`
- `void addLockedSprite()`
- `void addNormalSprite()`
- `cocos2d::ccColor3B colorForType(GauntletType type)`
- `bool init(GauntletType type, bool locked)`
- `float luminanceForType(GauntletType type)`
- `void toggleLockedSprite(bool locked)`

**Members:**

- `GauntletType m_gauntletType`

### `GhostTrailEffect` : cocos2d::CCNode

**Functions:**

- `static GhostTrailEffect* create()`
- `virtual bool init()`
- `virtual void draw()`
- `void doBlendAdditive()`
- `void runWithTarget(cocos2d::CCSprite* sprite, float snapshotInterval, float fadeInterval, float duration, float ghostScale, bool scaleTwice)`
- `void stopTrail()`
- `void trailSnapshot(float dt)`

**Members:**

- `float m_snapshotInterval`
- `float m_fadeInterval`
- `float m_ghostScale`
- `bool m_scaleTwice`
- `float m_playerScale`
- `cocos2d::ccBlendFunc m_blendFunc`
- `cocos2d::CCSprite* m_iconSprite`
- `PlayerObject* m_playerObject`
- `cocos2d::CCLayer* m_objectLayer`
- `float m_opacity`
- `void* m_delegate`
- `cocos2d::ccColor3B m_color`
- `cocos2d::CCPoint m_position`
- `bool m_unk194`

### `GooglePlayDelegate`

**Functions:**

- `virtual void googlePlaySignedIn()`

### `GooglePlayManager` : cocos2d::CCNode

**Functions:**

- `static GooglePlayManager* sharedState()`
- `virtual bool init()`
- `void googlePlaySignedIn()`

**Members:**

- `GooglePlayDelegate* m_delegate1`
- `GooglePlayDelegate* m_delegate2`

### `GradientTriggerObject` : EffectGameObject

**Functions:**

- `GradientTriggerObject()`
- `static GradientTriggerObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `int m_blendingLayer`
- `int m_blendingMode`
- `int m_gradientID`
- `int m_upBottomLeftID`
- `int m_downBottomRightID`
- `int m_leftTopLeftID`
- `int m_rightTopRightID`
- `bool m_vertexMode`
- `bool m_disable`
- `bool m_disableAll`
- `float m_previewOpacity`

### `GraphicsReloadLayer` : cocos2d::CCLayer

**Functions:**

- `GraphicsReloadLayer()`
- `static GraphicsReloadLayer* create(cocos2d::TextureQuality quality, cocos2d::CCSize resolution, bool fullscreen, bool borderless, bool fix, bool changedResolution)`
- `static cocos2d::CCScene* scene(cocos2d::TextureQuality quality, cocos2d::CCSize resolution, bool fullscreen, bool borderless, bool fix, bool changedResolution)`
- `bool init(cocos2d::TextureQuality quality, cocos2d::CCSize resolution, bool fullscreen, bool borderless, bool fix, bool changedResolution)`
- `void performReload()`

**Members:**

- `cocos2d::TextureQuality m_quality`
- `cocos2d::CCSize m_resolution`
- `bool m_fullscreen`
- `bool m_borderless`
- `bool m_fix`
- `bool m_changedResolution`

### `GravityEffectSprite` : cocos2d::CCSprite

**Functions:**

- `GravityEffectSprite()`
- `static GravityEffectSprite* create()`
- `virtual bool init()`
- `virtual void draw()`
- `void updateSpritesColor(cocos2d::ccColor3B color)`

### `GroupCommandObject2`

**Functions:**

- `GroupCommandObject2()`
- `void reset()`
- `void resetDelta(bool intermediate)`
- `void runFollowCommand(double xMod, double yMod, double duration)`
- `void runMoveCommand(cocos2d::CCPoint offset, double duration, int easingType, double easingRate, bool lockPlayerX, bool lockPlayerY, bool lockCameraX, bool lockCameraY, double moveModX, double moveModY)`
- `void runPlayerFollowCommand(double delay, double speed, int offset, double maxSpeed, double duration)`
- `void runRotateCommand(double offset, double duration, int easingType, double easingRate, bool lockRotation, int targetType)`
- `void runTransformCommand(double duration, int easingType, double easingRate)`
- `void step(float dt)`
- `void stepTransformCommand(float dt, bool intermediate, bool skipStep)`
- `void updateAction(int type, float value)`
- `void updateEffectAction(float value, int type)`

**Members:**

- `int m_groupCommandUniqueID`
- `cocos2d::CCPoint m_moveOffset`
- `EasingType m_easingType`
- `double m_easingRate`
- `double m_duration`
- `double m_deltaTime`
- `int m_targetGroupID`
- `int m_centerGroupID`
- `double m_currentXOffset`
- `double m_currentYOffset`
- `double m_deltaX`
- `double m_deltaY`
- `double m_oldDeltaX`
- `double m_oldDeltaY`
- `double m_lockedCurrentXOffset`
- `double m_lockedCurrentYOffset`
- `bool m_finished`
- `bool m_disabled`
- `bool m_finishRelated`
- `bool m_lockToPlayerX`
- `bool m_lockToPlayerY`
- `bool m_lockToCameraX`
- `bool m_lockToCameraY`
- `bool m_lockedInX`
- `bool m_lockedInY`
- `double m_moveModX`
- `double m_moveModY`
- `double m_currentRotateOrTransformValue`
- `double m_currentRotateOrTransformDelta`
- `double m_someInterpValue1RelatedOne`
- `double m_someInterpValue2RelatedOne`
- `double m_rotationOffset`
- `bool m_lockObjectRotation`
- `int m_targetPlayer`
- `double m_followXMod`
- `double m_followYMod`
- `int m_commandType`
- `double m_someInterpValue1`
- `double m_someInterpValue2`
- `double m_keyframeRelated`
- `double m_targetScaleX`
- `double m_targetScaleY`
- `double m_transformTriggerProperty450`
- `double m_transformTriggerProperty451`
- `double m_someInterpValue1RelatedZero`
- `double m_someInterpValue2RelatedZero`
- `bool m_onlyMove`
- `bool m_transformRelatedFalse`
- `bool m_relativeRotation`
- `double m_someInterpValue1Related`
- `double m_someInterpValue2Related`
- `double m_followYSpeed`
- `double m_followYDelay`
- `int m_followYOffset`
- `double m_followYMaxSpeed`
- `int m_triggerUniqueID`
- `int m_controlID`
- `double m_deltaX_3`
- `double m_deltaY_3`
- `double m_oldDeltaX_3`
- `double m_oldDeltaY_3`
- `double m_Delta_3_Related`
- `double m_unkDoubleMaybeUnused`
- `int m_actionType1`
- `int m_actionType2`
- `double m_actionValue1`
- `double m_actionValue2`
- `bool m_someInterpValue1RelatedFalse`
- `float m_deltaTimeInFloat`
- `bool m_alreadyUpdated`
- `bool m_doUpdate`
- `gd::vector<KeyframeObject> m_keyframes`
- `cocos2d::CCPoint m_splineRelated`
- `GameObject* m_gameObject`
- `float m_gameObjectRotation`
- `gd::vector<int> m_remapKeys`
- `bool m_someInterpValue2RelatedTrue`
- `int m_unkInt204`

### `HSVLiveOverlay` : FLAlertLayer, HSVWidgetDelegate

**Functions:**

- `HSVLiveOverlay()`
- `~HSVLiveOverlay()`
- `static HSVLiveOverlay* create(GameObject* object, cocos2d::CCArray* objects)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void hsvChanged(ConfigureHSVWidget* widget)`
- `void closeColorSelect(cocos2d::CCObject* sender)`
- `void createHSVWidget(int tab)`
- `void determineStartValues()`
- `bool init(GameObject* object, cocos2d::CCArray* objects)`
- `void onSelectTab(cocos2d::CCObject* sender)`
- `void toggleControls(bool visible)`

**Members:**

- `GameObject* m_object`
- `cocos2d::CCArray* m_objects`
- `cocos2d::CCArray* m_controls`
- `cocos2d::CCArray* m_unkArray`
- `ColorSelectDelegate* m_delegate`
- `int m_activeTab`
- `ConfigureHSVWidget* m_widget`
- `bool m_unkBool1`
- `bool m_unkBool2`
- `bool m_unkBool3`

### `HSVWidgetDelegate`

**Functions:**

- `virtual void hsvPopupClosed(HSVWidgetPopup* popup, cocos2d::ccHSVValue value)`
- `virtual void hsvChanged(ConfigureHSVWidget* widget)`

### `HSVWidgetPopup` : FLAlertLayer

**Functions:**

- `static HSVWidgetPopup* create(cocos2d::ccHSVValue hsv, HSVWidgetDelegate* delegate, gd::string title)`
- `virtual void keyBackClicked()`
- `bool init(cocos2d::ccHSVValue hsv, HSVWidgetDelegate* delegate, gd::string title)`
- `void onClose(cocos2d::CCObject* sender)`

**Members:**

- `ConfigureHSVWidget* m_widget`
- `HSVWidgetDelegate* m_delegate`

### `HardStreak` : cocos2d::CCDrawNode

**Functions:**

- `static HardStreak* create()`
- `virtual bool init()`
- `void addPoint(cocos2d::CCPoint point)`
- `void clearAboveXPos(float x)`
- `void clearBehindXPos(float x)`
- `HardStreak* createDuplicate()`
- `void firstSetup()`
- `double normalizeAngle(double angle)`
- `cocos2d::CCPoint quadCornerOffset(cocos2d::CCPoint start, cocos2d::CCPoint end, float width)`
- `void reset()`
- `void resumeStroke()`
- `void scheduleAutoUpdate()`
- `void stopStroke()`
- `callback void updateStroke(float dt)`

**Members:**

- `cocos2d::CCArray* m_pointArray`
- `cocos2d::CCPoint m_currentPoint`
- `float m_waveSize`
- `float m_pulseSize`
- `bool m_isSolid`
- `bool m_isFlipped`
- `bool m_drawStreak`

### `InfoAlertButton` : CCMenuItemSpriteExtra

**Functions:**

- `static InfoAlertButton* create(gd::string title, gd::string desc, float spriteScale)`
- `virtual void activate()`
- `bool init(gd::string title, gd::string desc, float spriteScale)`

**Members:**

- `gd::string m_title`
- `gd::string m_description`
- `float m_textScale`
- `bool m_scroll`

### `InfoLayer` : FLAlertLayer, LevelCommentDelegate, CommentUploadDelegate, FLAlertLayerProtocol

**Functions:**

- `static InfoLayer* create(GJGameLevel* level, GJUserScore* score, GJLevelList* list)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void loadCommentsFinished(cocos2d::CCArray* comments, char const* key)`
- `virtual void loadCommentsFailed(char const* key)`
- `virtual void setupPageInfo(gd::string info, char const* key)`
- `virtual void commentUploadFinished(int parentID)`
- `virtual void commentUploadFailed(int parentID, CommentError errorType)`
- `virtual void updateUserScoreFinished()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void confirmReport(cocos2d::CCObject* sender)`
- `int getAccountID()`
- `int getID()`
- `int getRealID()`
- `CCMenuItemSpriteExtra* getSpriteButton(char const* frame, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale, cocos2d::CCPoint position)`
- `bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list)`
- `bool isCorrect(char const* key)`
- `void loadPage(int page, bool noSetup)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onComment(cocos2d::CCObject* sender)`
- `void onCopyLevelID(cocos2d::CCObject* sender)`
- `void onGetComments(cocos2d::CCObject* sender)`
- `void onLevelInfo(cocos2d::CCObject* sender)`
- `void onMore(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onOriginal(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onRefreshComments(cocos2d::CCObject* sender)`
- `void onSimilar(cocos2d::CCObject* sender)`
- `void reloadWindow()`
- `void setupCommentsBrowser(cocos2d::CCArray* comments)`
- `void setupLevelInfo()`
- `void toggleCommentMode(cocos2d::CCObject* sender)`
- `void toggleExtendedMode(cocos2d::CCObject* sender)`
- `void toggleSmallCommentMode(cocos2d::CCObject* sender)`
- `void updateCommentModeButtons()`
- `void updateLevelsLabel()`

**Members:**

- `GJGameLevel* m_level`
- `GJUserScore* m_score`
- `GJLevelList* m_levelList`
- `gd::string m_commentKey`
- `LoadingCircle* m_loadingCircle`
- `cocos2d::CCLabelBMFont* m_pageLabel`
- `cocos2d::CCLabelBMFont* m_noComments`
- `GJCommentListLayer* m_list`
- `CCMenuItemSpriteExtra* m_rightArrow`
- `CCMenuItemSpriteExtra* m_leftArrow`
- `CCMenuItemSpriteExtra* m_likeBtn`
- `CCMenuItemSpriteExtra* m_timeBtn`
- `CCMenuItemSpriteExtra* m_reportBtn`
- `CCMenuItemSpriteExtra* m_commentsBtn`
- `CCMenuItemSpriteExtra* m_refreshCommentsBtn`
- `int m_itemCount`
- `int m_pageStartIdx`
- `int m_pageEndIdx`
- `int m_page`
- `bool m_canUpdateUserScore`
- `CommentKeyType m_mode`

### `InheritanceNode` : cocos2d::CCObject

**Functions:**

- `InheritanceNode()`
- `static InheritanceNode* create(int colorID, InheritanceNode* node)`
- `bool init(int colorID, InheritanceNode* node)`

**Members:**

- `int m_colorID`
- `InheritanceNode* m_inheritanceNode`
- `ColorAction* m_colorAction`
- `bool m_unk050`
- `bool m_unk051`

### `ItemInfoPopup` : FLAlertLayer

**Functions:**

- `static ItemInfoPopup* create(int id, UnlockType type)`
- `static gd::string nameForUnlockType(int id, UnlockType type)`
- `virtual void keyBackClicked()`
- `bool init(int id, UnlockType type)`
- `bool isUnlockedByDefault(int id, UnlockType type)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCredit(cocos2d::CCObject* sender)`

**Members:**

- `int m_itemID`
- `UnlockType m_unlockType`
- `int m_accountID`

### `ItemTriggerGameObject` : EffectGameObject

**Functions:**

- `ItemTriggerGameObject()`
- `static ItemTriggerGameObject* create(char const* frame)`
- `virtual void customSetup()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `int m_item1Mode`
- `int m_item2Mode`
- `int m_targetItemMode`
- `float m_mod1`
- `float m_mod2`
- `int m_resultType1`
- `int m_resultType2`
- `int m_resultType3`
- `float m_tolerance`
- `int m_roundType1`
- `int m_roundType2`
- `int m_signType1`
- `int m_signType2`
- `bool m_persistent`
- `bool m_targetAll`
- `bool m_reset`
- `bool m_timer`

### `KeybindingsLayer` : FLAlertLayer

**Functions:**

- `static KeybindingsLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `cocos2d::CCLabelBMFont* addKeyPair(char const* action, char const* key)`
- `int countForPage(int page)`
- `void goToPage(int page)`
- `void incrementCountForPage(int page)`
- `const char* infoKey(int index)`
- `cocos2d::CCLayer* layerForPage(int page)`
- `const char* layerKey(int page)`
- `cocos2d::CCPoint nextPosition(int page)`
- `const char* objectKey(int page)`
- `cocos2d::CCArray* objectsForPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `const char* pageKey(int page)`

**Members:**

- `int m_page`
- `int m_keyCount`
- `int m_maxPage`
- `cocos2d::CCDictionary* m_values`
- `cocos2d::CCDictionary* m_variables`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`

### `KeybindingsManager` : cocos2d::CCNode

**Functions:**

- `static KeybindingsManager* sharedState()`
- `virtual bool init()`
- `bool commandForKey(cocos2d::enumKeyCodes key, GJKeyGroup group, bool control, bool alt, bool shift)`
- `bool commandForKeyMods(cocos2d::enumKeyCodes key, GJKeyGroup group)`
- `bool commandForKeyNoMods(cocos2d::enumKeyCodes key, GJKeyGroup group)`
- `cocos2d::CCDictionary* commandToKeyForGroup(GJKeyGroup group)`
- `void dataLoaded(DS_Dictionary* dict)`
- `void encodeDataTo(DS_Dictionary* dict)`
- `void firstSetup()`
- `GJKeyGroup groupForCommand(GJKeyCommand command)`
- `cocos2d::enumKeyCodes keyForCommand(GJKeyCommand command)`
- `cocos2d::CCDictionary* keyToCommandForGroup(GJKeyGroup group)`

**Members:**

- `cocos2d::CCDictionary* m_keyToCommandDict`
- `cocos2d::CCDictionary* m_commandToKeyDict`

### `KeyframeAnimTriggerObject` : EffectGameObject

**Functions:**

- `KeyframeAnimTriggerObject()`
- `static KeyframeAnimTriggerObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `float m_timeMod`
- `float m_positionXMod`
- `float m_positionYMod`
- `float m_rotationMod`
- `float m_scaleXMod`
- `float m_scaleYMod`

### `KeyframeGameObject` : EffectGameObject

**Functions:**

- `KeyframeGameObject()`
- `~KeyframeGameObject()`
- `static KeyframeGameObject* create()`
- `virtual bool init()`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `void updateShadowObjects(GJBaseGameLayer* layer, EditorUI* ui)`

**Members:**

- `cocos2d::CCArray* m_shadowObjects`
- `cocos2d::CCSprite* m_previewSprite`
- `int m_keyframeGroup`
- `int m_keyframeIndex`
- `bool m_referenceOnly`
- `bool m_proximity`
- `bool m_curve`
- `bool m_closeLoop`
- `int m_timeMode`
- `float m_unk760`
- `float m_spawnDelay`
- `bool m_previewArt`
- `bool m_keyframeActive`
- `bool m_autoLayer`
- `int m_direction`
- `int m_revolutions`
- `float m_lineOpacity`

### `KeyframeObject`

**Functions:**

- `void setupSpline(gd::vector<KeyframeObject*>& objects)`

**Members:**

- `double m_unk000`
- `int m_unk008`
- `float m_unk00c`
- `bool m_unk010`
- `int m_unk014`
- `float m_unk018`
- `bool m_unk01c`
- `bool m_unk01d`
- `bool m_unk01e`
- `tk_spline m_spline1`
- `tk_spline m_spline2`
- `double m_unk170`
- `double m_unk178`
- `int m_unk180`
- `int m_unk184`
- `cocos2d::CCPoint m_unk188`
- `cocos2d::CCPoint m_unk190`
- `double m_unk198`
- `double m_unk1a0`
- `double m_unk1a8`
- `double m_unk1b0`
- `float m_unk1b8`

### `LabelGameObject` : EffectGameObject

**Functions:**

- `LabelGameObject()`
- `static LabelGameObject* create()`
- `virtual bool init()`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void setupCustomSprites(gd::string frameName)`
- `virtual void addMainSpriteToParent(bool reorder)`
- `virtual void resetObject()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void setObjectColor(cocos2d::ccColor3B const& color)`
- `virtual void updateTextKerning(int kerning)`
- `virtual int getTextKerning()`
- `void createLabel(gd::string text)`
- `void queueUpdateLabel(gd::string text)`
- `void removeLabel()`
- `void unlockLabelColor()`
- `void updateLabel(float value)`
- `void updateLabel(gd::string text)`
- `void updateLabelAlign(int alignment)`
- `void updateLabelIfDirty()`
- `void updatePreviewLabel()`

**Members:**

- `cocos2d::CCLabelBMFont* m_label`
- `bool m_labelDirty`
- `gd::string m_labelString`
- `bool m_labelColorLocked`
- `int m_alignment`
- `bool m_showSecondsOnly`
- `int m_shownSpecial`
- `bool m_isTimeCounter`
- `int m_kerning`
- `bool m_updateLabel`

### `LeaderboardManagerDelegate`

**Functions:**

- `virtual void updateUserScoreFinished()`
- `virtual void updateUserScoreFailed()`
- `virtual void loadLeaderboardFinished(cocos2d::CCArray* scores, char const* key)`
- `virtual void loadLeaderboardFailed(char const* key)`

### `LeaderboardsLayer` : cocos2d::CCLayer, LeaderboardManagerDelegate, FLAlertLayerProtocol

**Functions:**

- `LeaderboardsLayer()`
- `~LeaderboardsLayer()`
- `static LeaderboardsLayer* create(LeaderboardType type, LeaderboardStat stat)`
- `static cocos2d::CCScene* scene(LeaderboardType type, LeaderboardStat stat)`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void updateUserScoreFinished()`
- `virtual void updateUserScoreFailed()`
- `virtual void loadLeaderboardFinished(cocos2d::CCArray* scores, char const* key)`
- `virtual void loadLeaderboardFailed(char const* key)`
- `bool init(LeaderboardType type, LeaderboardStat stat)`
- `bool isCorrect(gd::string key)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onCreators(cocos2d::CCObject* sender)`
- `void onGlobal(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onStat(cocos2d::CCObject* sender)`
- `void onTop(cocos2d::CCObject* sender)`
- `void onWeek(cocos2d::CCObject* sender)`
- `void refreshTabs()`
- `void selectLeaderboard(LeaderboardType type, LeaderboardStat stat)`
- `void setupLevelBrowser(cocos2d::CCArray* scores)`
- `void setupTabs()`
- `void toggleTabButtons()`

**Members:**

- `GJListLayer* m_list`
- `cocos2d::CCArray* m_userScores`
- `LeaderboardType m_type`
- `LeaderboardStat m_stat`
- `CCMenuItemToggler* m_topBtn`
- `CCMenuItemToggler* m_globalBtn`
- `CCMenuItemToggler* m_creatorsBtn`
- `CCMenuItemToggler* m_friendsBtn`
- `LoadingCircle* m_circle`
- `TextArea* m_noInternet`
- `cocos2d::CCArray* m_tabs`
- `cocos2d::CCArray* m_modeButtons`

### `LevelAreaInnerLayer` : cocos2d::CCLayer, DialogDelegate

**Functions:**

- `LevelAreaInnerLayer()`
- `static LevelAreaInnerLayer* create(bool returning)`
- `static cocos2d::CCScene* scene(bool returning)`
- `virtual void keyBackClicked()`
- `virtual void dialogClosed(DialogLayer* layer)`
- `virtual void onExit()`
- `bool init(bool returning)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onDoor(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNextFloor(cocos2d::CCObject* sender)`
- `void onOnlineVault(cocos2d::CCObject* sender)`
- `bool playStep1()`
- `void showFloor1CompleteDialog()`
- `void tryResumeTowerMusic()`
- `void tryShowAd()`

**Members:**

- `CCMenuItemSpriteExtra* m_nextFloorButton`
- `bool m_enteringLevel`
- `int m_levelID`
- `bool m_exiting`

### `LevelAreaLayer` : cocos2d::CCLayer, DialogDelegate

**Functions:**

- `LevelAreaLayer()`
- `~LevelAreaLayer()`
- `static void addTorch(cocos2d::CCNode* parent, cocos2d::CCPoint position, int fireType, float scale, int zOrder, bool noTorch, int colorType, cocos2d::CCArray* nodes)`
- `static LevelAreaLayer* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void dialogClosed(DialogLayer* layer)`
- `virtual void onExit()`
- `void addGodRay(float startOpacity, float midOpacity, float endOpacity, float fadeDuration, float scaleY, cocos2d::CCPoint position)`
- `void fadeInsideTower()`
- `void onBack(cocos2d::CCObject* sender)`
- `void onClickDoor(cocos2d::CCObject* sender)`
- `bool onEnterTower()`
- `void showDialog()`

**Members:**

- `cocos2d::CCSprite* m_towerSprite`
- `cocos2d::CCArray* m_godRays`
- `bool m_enteringTower`
- `bool m_exiting`

### `LevelBrowserLayer` : cocos2d::CCLayerColor, LevelManagerDelegate, FLAlertLayerProtocol, SetIDPopupDelegate, SetTextPopupDelegate, TableViewCellDelegate, ShareCommentDelegate

**Functions:**

- `LevelBrowserLayer()`
- `~LevelBrowserLayer()`
- `static LevelBrowserLayer* create(GJSearchObject* object)`
- `static cocos2d::CCScene* scene(GJSearchObject* object)`
- `virtual void onEnter()`
- `virtual void onEnterTransitionDidFinish()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void loadLevelsFinished(cocos2d::CCArray* levels, char const* key, int type)`
- `virtual void loadLevelsFailed(char const* key, int type)`
- `virtual void setupPageInfo(gd::string info, char const* key)`
- `virtual void onBack(cocos2d::CCObject* sender)`
- `virtual void shareCommentClosed(gd::string text, ShareCommentLayer* layer)`
- `virtual void setTextPopupClosed(SetTextPopup* popup, gd::string text)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void setIDPopupClosed(SetIDPopup* popup, int value)`
- `virtual cocos2d::CCArray* updateResultArray(cocos2d::CCArray* results)`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `void createNewLevel(cocos2d::CCObject* sender)`
- `void createNewList(cocos2d::CCObject* sender)`
- `void createNewSmartTemplate(cocos2d::CCObject* sender)`
- `void deleteSelected()`
- `void exitLayer(cocos2d::CCObject* sender)`
- `cocos2d::CCArray* getItemsMatchingSearch(cocos2d::CCArray* items, gd::string query, GJSearchObject* object)`
- `gd::string getSearchTitle()`
- `bool init(GJSearchObject* object)`
- `bool isCorrect(char const* key)`
- `void loadPage(GJSearchObject* object)`
- `void onClearSearch(cocos2d::CCObject* sender)`
- `void onDeleteAll(cocos2d::CCObject* sender)`
- `void onDeleteSelected(cocos2d::CCObject* sender)`
- `void onFavorites(cocos2d::CCObject* sender)`
- `void onGoToFolder(cocos2d::CCObject* sender)`
- `void onGoToLastPage(cocos2d::CCObject* sender)`
- `void onGoToPage(cocos2d::CCObject* sender)`
- `void onHelp(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onLocalMode(cocos2d::CCObject* sender)`
- `void onMyOnlineLevels(cocos2d::CCObject* sender)`
- `void onNew(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onRefresh(cocos2d::CCObject* sender)`
- `void onRemoveAllFavorites(cocos2d::CCObject* sender)`
- `void onSaved(cocos2d::CCObject* sender)`
- `void onSavedMode(cocos2d::CCObject* sender)`
- `void onSearch(cocos2d::CCObject* sender)`
- `void onToggleAllObjects(cocos2d::CCObject* sender)`
- `void reloadAllObjects()`
- `void setSearchObject(GJSearchObject* object)`
- `void setupLevelBrowser(cocos2d::CCArray* items)`
- `void show()`
- `void updateLevelsLabel()`
- `void updatePageLabel()`

**Members:**

- `bool m_unk`
- `bool m_allSelected`
- `TextArea* m_noInternet`
- `GJListLayer* m_list`
- `CCMenuItemSpriteExtra* m_rightArrow`
- `CCMenuItemSpriteExtra* m_leftArrow`
- `CCMenuItemSpriteExtra* m_lastBtn`
- `CCMenuItemSpriteExtra* m_cancelSearchBtn`
- `CCMenuItemSpriteExtra* m_refreshBtn`
- `cocos2d::CCArray* m_levels`
- `GJSearchObject* m_searchObject`
- `cocos2d::CCLabelBMFont* m_countText`
- `cocos2d::CCLabelBMFont* m_pageText`
- `CCMenuItemSpriteExtra* m_pageBtn`
- `cocos2d::CCLabelBMFont* m_folderText`
- `CCMenuItemSpriteExtra* m_folderBtn`
- `CCMenuItemToggler* m_allObjectsToggler`
- `int m_itemCount`
- `int m_pageStartIdx`
- `int m_pageEndIdx`
- `LoadingCircle* m_circle`
- `int m_lastPage`
- `bool m_isOverlay`
- `cocos2d::CCScene* m_scene`
- `int m_zOffset`
- `bool m_unk2`
- `int m_listHeight`
- `float m_unkFloat`
- `float m_unkFloat2`
- `TableViewCellDelegate* m_delegate`
- `bool m_cached`

### `LevelCell` : TableViewCell

**Functions:**

- `LevelCell(char const* identifier, float width, float height)`
- `static LevelCell* create(float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadCustomLevelCell()`
- `void loadFromLevel(GJGameLevel* level)`
- `void loadLocalLevelCell()`
- `void onClick(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`
- `void updateCellMode(int mode)`
- `void updateToggle()`

**Members:**

- `CCMenuItemSpriteExtra* m_button`
- `GJGameLevel* m_level`
- `bool m_cellDrawn`
- `CCMenuItemToggler* m_toggler`
- `cocos2d::CCPoint m_point`
- `cocos2d::CCMenu* m_mainMenu`
- `bool m_compactView`
- `int m_cellMode`

### `LevelCommentDelegate`

**Functions:**

- `virtual void loadCommentsFinished(cocos2d::CCArray* comments, char const* key)`
- `virtual void loadCommentsFailed(char const* key)`
- `virtual void updateUserScoreFinished()`
- `virtual void setupPageInfo(gd::string info, char const* key)`

### `LevelDeleteDelegate`

**Functions:**

- `virtual void levelDeleteFinished(int id)`
- `virtual void levelDeleteFailed(int id)`

### `LevelDownloadDelegate`

**Functions:**

- `virtual void levelDownloadFinished(GJGameLevel* level)`
- `virtual void levelDownloadFailed(int response)`

### `LevelEditorLayer` : GJBaseGameLayer, LevelSettingsDelegate

**Functions:**

- `LevelEditorLayer()`
- `static LevelEditorLayer* create(GJGameLevel* level, bool noUI)`
- `static LevelEditorLayer* get()`
- `static cocos2d::CCScene* scene(GJGameLevel* level, bool noUI)`
- `static void updateObjectLabel(GameObject* object)`
- `virtual void draw()`
- `virtual void postUpdate(float dt)`
- `virtual void updateVisibility(float dt)`
- `virtual void playerTookDamage(PlayerObject* player)`
- `virtual void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2)`
- `virtual void updateDebugDraw()`
- `virtual void addToGroup(GameObject* object, int groupID, bool triggerGroup)`
- `virtual void removeFromGroup(GameObject* object, int groupID)`
- `virtual void updateObjectSection(GameObject* object)`
- `virtual void updateDisabledObjectsLastPos(cocos2d::CCArray* objects)`
- `virtual float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id)`
- `virtual cocos2d::CCPoint posForTime(float time)`
- `virtual void resetSPTriggered()`
- `virtual void didRotateGameplay()`
- `virtual void manualUpdateObjectColors(GameObject* object)`
- `virtual cocos2d::CCParticleSystemQuad* claimCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int zLayer, int zOrder, int uiObject, bool dontAdd)`
- `virtual void unclaimCustomParticle(gd::string const& key, cocos2d::CCParticleSystemQuad* particle)`
- `virtual void activatedAudioTrigger(SFXTriggerGameObject* object)`
- `virtual void checkpointActivated(CheckpointGameObject* object)`
- `virtual void addKeyframe(KeyframeGameObject* object)`
- `virtual void levelSettingsUpdated()`
- `bool activateTriggerEffect(EffectGameObject* object, float currentTime, float playTime, float boundTime, bool active)`
- `void addDelayedSpawn(EffectGameObject* object, float delay)`
- `void addExclusionList(const gd::unordered_set<int>& excludes, gd::unordered_set<int>& groups)`
- `GameObject* addObjectFromVector(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `void addObjectsAtPosition(cocos2d::CCPoint position, cocos2d::CCArray* objects, cocos2d::CCArray* result)`
- `void addObjectsInRect(cocos2d::CCRect rect, bool ignoreGroups, cocos2d::CCArray* objects, cocos2d::CCArray* result)`
- `void addObjectToGroup(GameObject* object, int group)`
- `void addPlayer2Point(cocos2d::CCPoint point, bool newGroup)`
- `void addPlayerCollisionBlock()`
- `void addPlayerPoint(cocos2d::CCPoint point)`
- `void addSpecial(GameObject* object)`
- `void addToRedoList(UndoObject* object)`
- `void addTouchPoint(cocos2d::CCPoint point)`
- `void addToUndoList(UndoObject* object, bool keepRedo)`
- `void addTriggersWithGroupID(gd::unordered_set<int>& sourceIDs, cocos2d::CCArray* triggers, gd::unordered_map<int, int>& remap, int objectID)`
- `void addTriggersWithTargetGroupID(gd::unordered_set<int>& sourceIDs, gd::unordered_set<int>& targetIDs, cocos2d::CCArray* triggers, gd::unordered_map<int, int>& remap, int objectID)`
- `void applyAttributeState(GameObject* dest, GameObject* src)`
- `void applyGroupState(GameObject* dest, GameObject* src)`
- `void breakApartTextObject(TextGameObject* object)`
- `bool canPasteState()`
- `void clearPlayerPoints()`
- `void clearTouchPoints()`
- `void copyObjectState(GameObject* object)`
- `void copyParticleState(ParticleGameObject* object)`
- `GameObject* createObject(int key, cocos2d::CCPoint position, bool noUndo)`
- `void createObjectsFromSetup(gd::string& setup)`
- `cocos2d::CCArray* createObjectsFromString(gd::string const& str, bool noUndo, bool noLimit)`
- `void dirtifyTriggers()`
- `cocos2d::CCArray* duplicateKeyframeAnimation(int keyframeGroup)`
- `void fastUpdateDisabledGroups()`
- `GameObject* findGameObject(int uniqueID)`
- `StartPosObject* findStartPosObject()`
- `void forceShowSelectedObjects(bool show)`
- `void fullUpdateDisabledGroups()`
- `cocos2d::CCArray* getAllObjects()`
- `DelayedSpawnNode* getDelayedSpawnNode()`
- `cocos2d::CCPoint getGridPos(cocos2d::CCPoint position)`
- `float getLastObjectX()`
- `gd::string getLevelString()`
- `gd::string getLockedLayers()`
- `int getNextColorChannel()`
- `int getNextFreeAreaEffectID(const gd::unordered_set<int>& exclude)`
- `int getNextFreeBlockID(const gd::unordered_set<int>& exclude)`
- `int getNextFreeEditorLayer(const gd::unordered_set<int>& exclude)`
- `int getNextFreeEnterChannel(const gd::unordered_set<int>& exclude)`
- `int getNextFreeGradientID(const gd::unordered_set<int>& exclude)`
- `int getNextFreeGroupID(const gd::unordered_set<int>& exclude)`
- `int getNextFreeItemID(const gd::unordered_set<int>& exclude)`
- `int getNextFreeOrderChannel(const gd::unordered_set<int>& exclude)`
- `int getNextFreeSFXGroupID(const gd::unordered_set<int>& exclude)`
- `int getNextFreeSFXID(const gd::unordered_set<int>& exclude)`
- `cocos2d::CCRect getObjectRect(GameObject* object, bool forceSize, bool dontCalculate)`
- `cocos2d::CCPoint getRelativeOffset(GameObject* object)`
- `cocos2d::CCPoint getSavedEditorPosition(int index)`
- `gd::string getSavedEditorPositions()`
- `int getSectionCount()`
- `int getSelectedEditorOrder()`
- `cocos2d::CCPoint getSelectedEffectPos()`
- `int getSelectedOrderChannel()`
- `gd::string getSFXIDs()`
- `gd::string getSongIDs(bool& multipleSongs)`
- `cocos2d::CCArray* getTriggerGroup(int id)`
- `void handleAction(bool undo, cocos2d::CCArray* undoObjects)`
- `bool hasAction(bool redo)`
- `bool init(GJGameLevel* level, bool noUI)`
- `bool isLayerLocked(int layer)`
- `GameObject* objectAtPosition(cocos2d::CCPoint position)`
- `void objectMoved(GameObject* object)`
- `cocos2d::CCArray* objectsAtPosition(cocos2d::CCPoint position)`
- `cocos2d::CCArray* objectsInRect(cocos2d::CCRect rect, bool ignoreGroups)`
- `void onPausePlaytest()`
- `void onPlaytest()`
- `void onResumePlaytest()`
- `void onStopPlaytest()`
- `void pasteAttributeState(GameObject* object, cocos2d::CCArray* objects)`
- `void pasteColorState(GameObject* object, cocos2d::CCArray* objects)`
- `void pasteGroupState(GameObject* object, cocos2d::CCArray* objects)`
- `void pasteParticleState(ParticleGameObject* object, cocos2d::CCArray* objects)`
- `void processLoadedMoveActions()`
- `void quickUpdateAllPositions()`
- `void recreateGroups()`
- `void redoLastAction()`
- `void refreshSpecial(GameObject* object)`
- `void removeAllObjects()`
- `void removeAllObjectsOfType(int objectID)`
- `void removeObject(GameObject* object, bool noUndo)`
- `void removePlayerCollisionBlock()`
- `void removeSpecial(GameObject* object)`
- `void resetDelayedSpawnNodes()`
- `void resetEffectTriggerOptim(GameObject* object, cocos2d::CCArray* objects)`
- `void resetMovingObjects()`
- `void resetObjectVector()`
- `void resetPlayback()`
- `void resetToggledGroups()`
- `void resetToggledGroupsAndObjects()`
- `void resetUnusedColorChannels()`
- `void reverseKeyframeAnimationOrder(int keyframeGroup)`
- `void reverseObjectChanged(EffectGameObject* object)`
- `float rotationForSlopeNearObject(GameObject* object)`
- `ColorAction* runColorEffect(EffectGameObject* object, int colorID, float delay, float interval, bool instant)`
- `void saveEditorPosition(cocos2d::CCPoint& position, int index)`
- `void setObjectCount(int count)`
- `bool shouldBlend(int colorID)`
- `void sortBatchnodeChildren(float unused)`
- `void spawnGroupPreview(int groupID, float xPos, float delay, float currentTime, float playTime, float boundTime, bool ordered, bool active)`
- `void stopPlayback()`
- `void stopTriggersInGroup(int id, float delay)`
- `void timeObjectChanged()`
- `void toggleBackground(bool visible)`
- `void toggleGrid(bool visible)`
- `void toggleGround(bool enable)`
- `void toggleGroupPreview(int id, bool enable)`
- `void toggleLockActiveLayer()`
- `void transferDefaultColors(GJEffectManager* src, GJEffectManager* dest)`
- `void triggerFollowCommand(EffectGameObject* object)`
- `void triggerPlayerFollowCommand(EffectGameObject* object)`
- `void triggerRotateCommand(EffectGameObject* object)`
- `bool tryUpdateSpeedObject(EffectGameObject* object, bool noPreview)`
- `bool typeExistsAtPosition(int objectID, cocos2d::CCPoint position, bool flipX, bool flipY, float rotation)`
- `void undoLastAction()`
- `void unlockAllLayers()`
- `void updateAnimateOnTriggerObjects(bool animate)`
- `void updateArt(float dt)`
- `void updateBlendValues()`
- `void updateEditor(float dt)`
- `void updateEditorMode()`
- `void updateGameObjects()`
- `void updateGridLayer()`
- `void updateGridLayerParent()`
- `void updateKeyframeObjects()`
- `void updateKeyframeVisibility(bool visible)`
- `void updateLevelFont(int index)`
- `void updateObjectColors(cocos2d::CCArray* gameObjects)`
- `void updateOptions()`
- `void updatePreviewAnim()`
- `void updatePreviewParticle(ParticleGameObject* object)`
- `void updatePreviewParticles()`
- `void updateToggledGroups()`
- `bool validGroup(GameObject* object, bool checkLockedLayers)`

**Members:**

- `bool m_drawTriggerBoxes`
- `bool m_showGrid`
- `bool m_hideGridOnPlay`
- `bool m_drawEffectLines`
- `bool m_showGround`
- `bool m_showDurationLines`
- `bool m_increaseMaxUndoRedo`
- `bool m_hideBackground`
- `bool m_gv0120`
- `bool m_layerLockingEnabled`
- `bool m_playtestOrderChanged`
- `bool m_previewParticles`
- `bool m_previewAnimations`
- `bool m_previewShaders`
- `bool m_hideParticleIcons`
- `bool m_alwaysHideParticleIcons`
- `bool m_playTestSmoothFix`
- `bool m_hasHighDetail`
- `bool m_unk36ca`
- `int m_unk36cc`
- `bool m_collisionBlocksAdded`
- `int m_unk36d4`
- `cocos2d::CCArray* m_durationObjects`
- `cocos2d::CCArray* m_pulseTriggers`
- `cocos2d::CCArray* m_colorTriggers`
- `cocos2d::CCArray* m_alphaTriggers`
- `cocos2d::CCArray* m_spawnTriggers`
- `cocos2d::CCArray* m_moveTriggers`
- `cocos2d::CCArray* m_cameraGuideTriggers`
- `cocos2d::CCArray* m_particleObjects`
- `cocos2d::CCArray* m_keyframeObjects`
- `cocos2d::CCDictionary* m_unk3720`
- `cocos2d::CCArray* m_playtestTriggers`
- `GameObject* m_copyStateObject`
- `ParticleGameObject* m_particleObject`
- `cocos2d::CCDictionary* m_unk3740`
- `cocos2d::CCArray* m_unk3748`
- `bool m_keepEditorLayer`
- `bool m_unk3751`
- `geode::SeedValueRSV m_coinCount`
- `bool m_triggersChanged`
- `bool m_colorTriggersChanged`
- `bool m_pulseTriggersChanged`
- `bool m_alphaTriggersChanged`
- `bool m_spawnTriggersChanged`
- `cocos2d::CCArray* m_spawnOrderObjects`
- `bool m_spawnOrderObjectsChanged`
- `bool m_sortSpawnNodes`
- `cocos2d::CCDictionary* m_unk3778`
- `cocos2d::CCDictionary* m_unk3780`
- `bool m_initializing`
- `short m_currentLayer`
- `float m_playtestZoom`
- `OBB2D* m_currentOBB2D`
- `float m_playtestTimeWarp`
- `float m_playtestCameraZoom`
- `cocos2d::CCSprite* m_playtestDeathSprite`
- `float m_trailTimer`
- `bool m_soloMode`
- `bool m_nonSquareRotation`
- `EditorUI* m_editorUI`
- `cocos2d::CCArray* m_undoObjects`
- `cocos2d::CCArray* m_redoObjects`
- `geode::SeedValueRSV m_objectCount`
- `DrawGridLayer* m_drawGridLayer`
- `bool m_updateColorSprites`
- `bool m_previewMode`
- `bool m_alwaysPreviewMode`
- `gd::string m_levelString`
- `gd::vector<GameObject*> m_objectVector`
- `gd::vector<GameObject*> m_loadedMoveObjects`
- `cocos2d::CCDictionary* m_triggerGroupsDict`
- `gd::vector<cocos2d::CCArray*> m_triggerGroups`
- `gd::vector<cocos2d::CCPoint> m_playerPoints`
- `gd::vector<gd::vector<cocos2d::CCPoint>> m_player2Points`
- `gd::vector<cocos2d::CCPoint> m_touchPoints`
- `gd::vector<bool> m_sortedGroups`
- `gd::vector<bool> m_toggledGroups`
- `gd::vector<bool> m_lockedLayers`
- `gd::vector<cocos2d::CCPoint> m_savedPositions`
- `cocos2d::CCPoint m_previewPosition`
- `gd::vector<bool> m_blendingColors`
- `gd::vector<bool> m_blendingColors2`
- `gd::vector<unsigned char> m_toggledGroupStates`
- `gd::vector<float> m_spawnGroupDelays`
- `double m_sessionTime`
- `bool m_removingAll`
- `EffectGameObject* m_playbackObject`
- `EffectGameObject* m_traceInObject`
- `EffectGameObject* m_traceOutObject`
- `int m_playbackOrder`
- `int m_duplicateKeyframeGroup`
- `gd::vector<DelayedSpawnNode*> m_delayedSpawnNodes`
- `gd::vector<DelayedSpawnNode*> m_delayedSpawnNodes2`
- `gd::unordered_map<int, int> m_unk3ae0`
- `bool m_playbackActive`
- `bool m_activateAudioTriggers`
- `bool m_unk3b22`
- `int m_unk3b24`
- `int m_unk3b28`
- `int m_unk3b2c`
- `gd::vector<int> m_unk3b30`
- `gd::vector<int> m_unk3b48`

### `LevelFeatureLayer` : FLAlertLayer

**Functions:**

- `static LevelFeatureLayer* create(int levelID)`
- `virtual void keyBackClicked()`
- `bool init(int levelID)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDown(cocos2d::CCObject* sender)`
- `void onDown2(cocos2d::CCObject* sender)`
- `void onRemoveValues(cocos2d::CCObject* sender)`
- `void onSetEpicOnly(cocos2d::CCObject* sender)`
- `void onSetFeatured(cocos2d::CCObject* sender)`
- `void onToggleEpic(cocos2d::CCObject* sender)`
- `void onUp(cocos2d::CCObject* sender)`
- `void onUp2(cocos2d::CCObject* sender)`
- `void updateStars()`

**Members:**

- `cocos2d::CCLabelBMFont* m_featureLabel`
- `int m_levelID`
- `int m_featurePosition`
- `bool m_epicOnly`
- `cocos2d::CCSprite* m_epicSprite`

### `LevelInfoLayer` : cocos2d::CCLayer, LevelDownloadDelegate, LevelUpdateDelegate, RateLevelDelegate, LikeItemDelegate, FLAlertLayerProtocol, LevelDeleteDelegate, NumberInputDelegate, SetIDPopupDelegate, TableViewCellDelegate

**Functions:**

- `LevelInfoLayer()`
- `~LevelInfoLayer()`
- `static LevelInfoLayer* create(GJGameLevel* level, bool challenge)`
- `static cocos2d::CCScene* scene(GJGameLevel* level, bool challenge)`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void numberInputClosed(NumberInputLayer* layer)`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `virtual void levelDownloadFinished(GJGameLevel* level)`
- `virtual void levelDownloadFailed(int response)`
- `virtual void levelUpdateFinished(GJGameLevel* level, UpdateResponse response)`
- `virtual void levelUpdateFailed(int response)`
- `virtual void levelDeleteFinished(int id)`
- `virtual void levelDeleteFailed(int id)`
- `virtual void rateLevelClosed()`
- `virtual void likedItem(LikeItemType type, int id, bool liked)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void setIDPopupClosed(SetIDPopup* popup, int value)`
- `virtual void onEnterTransitionDidFinish()`
- `void confirmClone(cocos2d::CCObject* sender)`
- `void confirmDelete(cocos2d::CCObject* sender)`
- `void confirmMoveToBottom(cocos2d::CCObject* sender)`
- `void confirmMoveToTop(cocos2d::CCObject* sender)`
- `void confirmOwnerDelete(cocos2d::CCObject* sender)`
- `void downloadLevel()`
- `void incrementDislikes()`
- `void incrementLikes()`
- `bool init(GJGameLevel* level, bool challenge)`
- `void loadLevelStep()`
- `void onAddToList(cocos2d::CCObject* sender)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onClone(cocos2d::CCObject* sender)`
- `void onDelete(cocos2d::CCObject* sender)`
- `void onFavorite(cocos2d::CCObject* sender)`
- `void onGarage(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onLevelInfo(cocos2d::CCObject* sender)`
- `void onLevelLeaderboard(cocos2d::CCObject* sender)`
- `void onLevelOptions(cocos2d::CCObject* sender)`
- `void onLike(cocos2d::CCObject* sender)`
- `void onOwnerDelete(cocos2d::CCObject* sender)`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onPlayReplay(cocos2d::CCObject* sender)`
- `void onRate(cocos2d::CCObject* sender)`
- `void onRateDemon(cocos2d::CCObject* sender)`
- `void onRateStars(cocos2d::CCObject* sender)`
- `void onRateStarsMod(cocos2d::CCObject* sender)`
- `void onSetFolder(cocos2d::CCObject* sender)`
- `void onUpdate(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void playStep2()`
- `void playStep3()`
- `void playStep4()`
- `void setupLevelInfo()`
- `void setupPlatformerStats()`
- `void setupProgressBars()`
- `bool shouldDownloadLevel()`
- `void showSongWarning()`
- `void showUpdateAlert(UpdateResponse type)`
- `void tryCloneLevel(cocos2d::CCObject* sender)`
- `void tryShowAd()`
- `void updateLabelValues()`
- `void updateSideButtons()`

**Members:**

- `bool m_isBusy`
- `cocos2d::CCMenu* m_playBtnMenu`
- `GJGameLevel* m_level`
- `cocos2d::CCArray* m_coins`
- `CCMenuItemSpriteExtra* m_likeBtn`
- `CCMenuItemSpriteExtra* m_starRateBtn`
- `CCMenuItemSpriteExtra* m_demonRateBtn`
- `void* m_unk2`
- `cocos2d::CCLabelBMFont* m_lengthLabel`
- `cocos2d::CCLabelBMFont* m_exactLengthLabel`
- `cocos2d::CCLabelBMFont* m_downloadsLabel`
- `cocos2d::CCLabelBMFont* m_likesLabel`
- `cocos2d::CCLabelBMFont* m_orbsLabel`
- `cocos2d::CCLabelBMFont* m_folderLabel`
- `CCMenuItemSpriteExtra* m_cloneBtn`
- `void* m_unk3`
- `cocos2d::CCSprite* m_likesIcon`
- `cocos2d::CCSprite* m_orbsIcon`
- `GJLevelType m_levelType`
- `bool m_noUpdateAlert`
- `bool m_enterTransitionFinished`
- `LoadingCircle* m_circle`
- `GJDifficultySprite* m_difficultySprite`
- `cocos2d::CCSprite* m_starsIcon`
- `cocos2d::CCLabelBMFont* m_starsLabel`
- `cocos2d::CCArray* m_icons`
- `float m_iconOffset`
- `cocos2d::CCPoint m_basePosition`
- `float m_baseStarsY`
- `bool m_challenge`
- `cocos2d::CCScene* m_playScene`
- `cocos2d::CCSprite* m_playSprite`
- `cocos2d::CCProgressTimer* m_progressTimer`
- `CustomSongWidget* m_songWidget`

### `LevelLeaderboard` : FLAlertLayer, LeaderboardManagerDelegate, FLAlertLayerProtocol

**Functions:**

- `static LevelLeaderboard* create(GJGameLevel* level, LevelLeaderboardType type, LevelLeaderboardMode mode)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void loadLeaderboardFinished(cocos2d::CCArray* scores, char const* key)`
- `virtual void loadLeaderboardFailed(char const* key)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void updateUserScoreFinished()`
- `virtual void updateUserScoreFailed()`
- `void deleteLocalScores()`
- `cocos2d::CCArray* getLocalScores()`
- `CCMenuItemSpriteExtra* getSpriteButton(gd::string frame, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale, cocos2d::CCPoint position, int button)`
- `bool init(GJGameLevel* level, LevelLeaderboardType type, LevelLeaderboardMode mode)`
- `bool isCorrect(char const* key)`
- `void loadScores()`
- `void onChangeMode(cocos2d::CCObject* sender)`
- `void onChangeType(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDeleteLocalScores(cocos2d::CCObject* sender)`
- `void onUpdate(cocos2d::CCObject* sender)`
- `void reloadLeaderboard(LevelLeaderboardType type, LevelLeaderboardMode mode)`
- `void setupLeaderboard(cocos2d::CCArray* scores)`

**Members:**

- `GJGameLevel* m_level`
- `LevelLeaderboardType m_type`
- `LevelLeaderboardMode m_mode`
- `cocos2d::CCArray* m_scores`
- `GJCommentListLayer* m_list`
- `LoadingCircle* m_circle`
- `TextArea* m_noInternet`
- `CCMenuItemSpriteExtra* m_refreshBtn`
- `CCMenuItemSpriteExtra* m_timeBtn`
- `CCMenuItemSpriteExtra* m_pointsBtn`

### `LevelListCell` : TableViewCell

**Functions:**

- `LevelListCell(char const* identifier, float width, float height)`
- `~LevelListCell()`
- `static LevelListCell* create(float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromList(GJLevelList* list)`
- `void onClick(cocos2d::CCObject* sender)`
- `void onListInfo(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `GJLevelList* m_levelList`
- `bool m_addingLevel`

### `LevelListDeleteDelegate`

**Functions:**

- `virtual void levelListDeleteFinished(int id)`
- `virtual void levelListDeleteFailed(int id)`

### `LevelListLayer` : LevelBrowserLayer, TextInputDelegate, SelectListIconDelegate, LikeItemDelegate, LevelListDeleteDelegate

**Functions:**

- `LevelListLayer()`
- `~LevelListLayer()`
- `static LevelListLayer* create(GJLevelList* list)`
- `static cocos2d::CCScene* scene(GJLevelList* list)`
- `virtual void onEnter()`
- `virtual void onExit()`
- `virtual void loadLevelsFinished(cocos2d::CCArray* levels, char const* key, int type)`
- `virtual void loadLevelsFailed(char const* key, int type)`
- `virtual void onBack(cocos2d::CCObject* sender)`
- `virtual void shareCommentClosed(gd::string text, ShareCommentLayer* layer)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void setIDPopupClosed(SetIDPopup* popup, int value)`
- `virtual cocos2d::CCArray* updateResultArray(cocos2d::CCArray* results)`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `virtual void likedItem(LikeItemType type, int id, bool liked)`
- `virtual void iconSelectClosed(SelectListIconLayer* layer)`
- `virtual void levelListDeleteFinished(int id)`
- `virtual void levelListDeleteFailed(int id)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void cloneList()`
- `void confirmClone(cocos2d::CCObject* sender)`
- `void confirmDelete(cocos2d::CCObject* sender)`
- `void confirmOwnerDelete(cocos2d::CCObject* sender)`
- `bool init(GJLevelList* list)`
- `void onClaimReward(cocos2d::CCObject* sender)`
- `void onDelete()`
- `void onDescription(cocos2d::CCObject* sender)`
- `void onFavorite(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onLike(cocos2d::CCObject* sender)`
- `void onListInfo(cocos2d::CCObject* sender)`
- `void onRefreshLevelList(cocos2d::CCObject* sender)`
- `void onSelectIcon(cocos2d::CCObject* sender)`
- `void onShare(cocos2d::CCObject* sender)`
- `void onToggleEditMode(cocos2d::CCObject* sender)`
- `void onViewProfile(cocos2d::CCObject* sender)`
- `void ownerDelete()`
- `void updateEditMode()`
- `void updateSideButtons()`
- `void updateStatsArt()`
- `void verifyListName()`

**Members:**

- `cocos2d::CCMenu* m_buttonMenu`
- `gd::string m_searchKey1`
- `GJLevelList* m_levelList`
- `gd::string m_searchKey2`
- `CCMenuItemSpriteExtra* m_likeButton`
- `bool m_exiting`
- `CCTextInputNode* m_titleInput`
- `int m_editMode`
- `cocos2d::CCArray* m_objects`
- `cocos2d::CCSprite* m_diffSprite`
- `cocos2d::CCSprite* m_featureSprite`
- `cocos2d::CCPoint m_rewardPosition`
- `bool m_exited`

### `LevelManagerDelegate`

**Functions:**

- `virtual void loadLevelsFinished(cocos2d::CCArray* levels, char const* key)`
- `virtual void loadLevelsFailed(char const* key)`
- `virtual void loadLevelsFinished(cocos2d::CCArray* levels, char const* key, int type)`
- `virtual void loadLevelsFailed(char const* key, int type)`
- `virtual void setupPageInfo(gd::string info, char const* key)`

### `LevelOptionsLayer` : GJOptionsLayer

**Functions:**

- `LevelOptionsLayer()`
- `static LevelOptionsLayer* create(LevelSettingsObject* object)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float getValue(int tag)`
- `virtual void setupOptions()`
- `virtual void didToggle(int tag)`
- `bool init(LevelSettingsObject* object)`
- `void onSettings(cocos2d::CCObject* sender)`

**Members:**

- `LevelSettingsObject* m_settingsObject`

### `LevelOptionsLayer2` : LevelOptionsLayer

**Functions:**

- `LevelOptionsLayer2()`
- `static LevelOptionsLayer2* create(LevelSettingsObject* object)`
- `virtual void setupOptions()`
- `bool init(LevelSettingsObject* object)`

### `LevelPage` : cocos2d::CCLayer, DialogDelegate

**Functions:**

- `LevelPage()`
- `~LevelPage()`
- `static LevelPage* create(GJGameLevel* level)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void dialogClosed(DialogLayer* layer)`
- `void addSecretCoin()`
- `void addSecretDoor()`
- `bool init(GJGameLevel* level)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onMoreGames(cocos2d::CCObject* sender)`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onSecretDoor(cocos2d::CCObject* sender)`
- `void onTheTower(cocos2d::CCObject* sender)`
- `void playCoinEffect()`
- `void playStep2()`
- `void playStep3()`
- `void updateDynamicPage(GJGameLevel* level)`

**Members:**

- `bool m_isBusy`
- `GJGameLevel* m_level`
- `cocos2d::CCMenu* m_levelMenu`
- `cocos2d::extension::CCScale9Sprite* m_levelDisplay`
- `cocos2d::CCLabelBMFont* m_normalProgressLabel`
- `cocos2d::CCLabelBMFont* m_practiceProgressLabel`
- `cocos2d::CCLabelBMFont* m_nameLabel`
- `cocos2d::CCLabelBMFont* m_starsLabel`
- `float m_progressWidth`
- `cocos2d::CCSprite* m_normalProgressBar`
- `cocos2d::CCSprite* m_practiceProgressBar`
- `cocos2d::CCSprite* m_difficultySprite`
- `cocos2d::CCSprite* m_starsSprite`
- `cocos2d::CCSize m_levelDisplaySize`
- `cocos2d::CCArray* m_coins`
- `cocos2d::CCArray* m_dynamicObjects`
- `cocos2d::CCArray* m_levelObjects`
- `cocos2d::CCArray* m_progressObjects`
- `GameObject* m_coinObject`
- `cocos2d::CCSprite* m_secretDoor`

### `LevelRateInfoDelegate`

**Functions:**

- `virtual void rateInfoFinished(int id, gd::string info)`
- `virtual void rateInfoFailed(int id, int response)`

### `LevelSearchLayer` : cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol, DemonFilterDelegate

**Functions:**

- `LevelSearchLayer()`
- `~LevelSearchLayer()`
- `static LevelSearchLayer* create(int type)`
- `static cocos2d::CCScene* scene(int type)`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void demonFilterSelectClosed(int filter)`
- `bool checkDiff(int diff)`
- `bool checkTime(int time)`
- `void clearFilters()`
- `void confirmClearFilters(cocos2d::CCObject* sender)`
- `char const* getDiffKey(int diff)`
- `gd::string getLevelLenKey()`
- `gd::string getSearchDiffKey()`
- `GJSearchObject* getSearchObject(SearchType type, gd::string query)`
- `char const* getTimeKey(int time)`
- `bool init(int type)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onClearFreeSearch(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onFollowed(cocos2d::CCObject* sender)`
- `void onFriends(cocos2d::CCObject* sender)`
- `void onLatestStars(cocos2d::CCObject* sender)`
- `void onMagic(cocos2d::CCObject* sender)`
- `void onMoreOptions(cocos2d::CCObject* sender)`
- `void onMostDownloaded(cocos2d::CCObject* sender)`
- `void onMostLikes(cocos2d::CCObject* sender)`
- `void onMostRecent(cocos2d::CCObject* sender)`
- `[[missing(win, mac)]]`
- `void onPasteClipboard(cocos2d::CCObject* sender)`
- `void onSearch(cocos2d::CCObject* sender)`
- `void onSearchMode(cocos2d::CCObject* sender)`
- `void onSearchUser(cocos2d::CCObject* sender)`
- `void onSpecialDemon(cocos2d::CCObject* sender)`
- `void onStarAward(cocos2d::CCObject* sender)`
- `void onSuggested(cocos2d::CCObject* sender)`
- `void onTrending(cocos2d::CCObject* sender)`
- `void toggleDifficulty(cocos2d::CCObject* sender)`
- `void toggleDifficultyNum(int diff, bool enabled)`
- `void toggleStar(cocos2d::CCObject* sender)`
- `void toggleTime(cocos2d::CCObject* sender)`
- `void toggleTimeNum(int time, bool enabled)`
- `void updateSearchLabel(char const* label)`

**Members:**

- `int m_type`
- `CCTextInputNode* m_searchInput`
- `cocos2d::CCSprite* m_starsSprite`
- `cocos2d::CCArray* m_difficultySprites`
- `cocos2d::CCArray* m_lengthSprites`
- `cocos2d::CCDictionary* m_difficultyDict`
- `cocos2d::CCSprite* m_lastDifficultySprite`
- `CCMenuItemSpriteExtra* m_demonTypeButton`

### `LevelSelectLayer` : cocos2d::CCLayer, BoomScrollLayerDelegate, DynamicScrollDelegate

**Functions:**

- `LevelSelectLayer()`
- `static LevelSelectLayer* create(int page)`
- `static cocos2d::CCScene* scene(int page)`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void updatePageWithObject(cocos2d::CCObject* layer, cocos2d::CCObject* object)`
- `virtual void scrollLayerMoved(cocos2d::CCPoint position)`
- `cocos2d::ccColor3B colorForPage(int page)`
- `cocos2d::ccColor3B getColorValue(int page1, int page2, float progress)`
- `bool init(int page)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onDownload(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNext(cocos2d::CCObject* sender)`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onPrev(cocos2d::CCObject* sender)`
- `void tryShowAd()`

**Members:**

- `float m_width`
- `cocos2d::CCSprite* m_backgroundSprite`
- `GJGroundLayer* m_groundLayer`
- `BoomScrollLayer* m_scrollLayer`
- `int m_unknown`
- `int m_scrolls`
- `bool m_masterDetectiveUnlocked`

### `LevelSettingsDelegate`

**Functions:**

- `virtual void levelSettingsUpdated()`

### `LevelSettingsLayer` : FLAlertLayer, ColorSelectDelegate, SelectArtDelegate, SelectSettingDelegate, FLAlertLayerProtocol, CustomSongLayerDelegate, TextInputDelegate

**Functions:**

- `static LevelSettingsLayer* create(LevelSettingsObject* object, LevelEditorLayer* layer)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void colorSelectClosed(cocos2d::CCNode* popup)`
- `virtual void selectArtClosed(SelectArtLayer* layer)`
- `virtual void selectSettingClosed(SelectSettingLayer* layer)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `bool init(LevelSettingsObject* object, LevelEditorLayer* layer)`
- `void onBGArt(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCol(cocos2d::CCObject* sender)`
- `void onDisable(cocos2d::CCObject* sender)`
- `void onFGArt(cocos2d::CCObject* sender)`
- `void onGameplayMode(cocos2d::CCObject* sender)`
- `void onGArt(cocos2d::CCObject* sender)`
- `void onLiveEdit(cocos2d::CCObject* sender)`
- `void onMode(cocos2d::CCObject* sender)`
- `void onOptionToggle(cocos2d::CCObject* sender)`
- `void onSelectFont(cocos2d::CCObject* sender)`
- `void onSelectMode(cocos2d::CCObject* sender)`
- `void onSelectSpeed(cocos2d::CCObject* sender)`
- `void onSettings(cocos2d::CCObject* sender)`
- `void onShowPicker(cocos2d::CCObject* sender)`
- `void onSpeed(cocos2d::CCObject* sender)`
- `void showPicker(ColorAction* action)`
- `void updateColorSprite(ColorChannelSprite* sprite)`
- `void updateColorSprites()`
- `void updateGameplayModeButtons()`

**Members:**

- `SongSelectNode* m_songSelectNode`
- `Speed m_speed`
- `ColorChannelSprite* m_bgColorSprite`
- `ColorChannelSprite* m_gColorSprite`
- `ColorChannelSprite* m_g2ColorSprite`
- `ColorChannelSprite* m_lineColorSprite`
- `ColorChannelSprite* m_mgColorSprite`
- `ColorChannelSprite* m_mg2ColorSprite`
- `cocos2d::CCSprite* m_moreColorsSprite`
- `cocos2d::CCSprite* m_backgroundSprite`
- `cocos2d::CCSprite* m_groundSprite`
- `cocos2d::CCSprite* m_middlegroundSprite`
- `cocos2d::CCSprite* m_speedSprite`
- `cocos2d::CCSprite* m_modeSprite`
- `LevelSettingsObject* m_settingsObject`
- `void* m_unkPtr`
- `cocos2d::CCArray* m_modeToggles`
- `cocos2d::CCArray* m_speedButtons`
- `LevelSettingsDelegate* m_delegate`
- `LevelEditorLayer* m_editorLayer`
- `CCTextInputNode* m_orderInput`
- `CCTextInputNode* m_channelInput`
- `CCMenuItemSpriteExtra* m_classicButton`
- `CCMenuItemSpriteExtra* m_platformerButton`
- `bool m_disableInput`

### `LevelSettingsObject` : cocos2d::CCNode

**Functions:**

- `static LevelSettingsObject* create()`
- `static LevelSettingsObject* objectFromDict(cocos2d::CCDictionary* dict)`
- `static LevelSettingsObject* objectFromString(gd::string const& str)`
- `virtual bool init()`
- `gd::string getSaveString()`
- `void setupColorsFromLegacyMode(cocos2d::CCDictionary* dict)`
- `bool shouldUseYSection()`

**Members:**

- `GJEffectManager* m_effectManager`
- `int m_startMode`
- `Speed m_startSpeed`
- `bool m_startMini`
- `bool m_startDual`
- `bool m_mirrorMode`
- `bool m_rotateGameplay`
- `bool m_twoPlayerMode`
- `bool m_platformerMode`
- `float m_songOffset`
- `bool m_fadeIn`
- `bool m_fadeOut`
- `bool m_dontReset`
- `int m_backgroundIndex`
- `int m_groundIndex`
- `int m_fontIndex`
- `int m_middleGroundIndex`
- `bool m_startsWithStartPos`
- `bool m_isFlipped`
- `bool m_reverseGameplay`
- `bool m_disableStartPos`
- `int m_targetOrder`
- `int m_targetChannel`
- `GJGameLevel* m_level`
- `gd::string m_guidelineString`
- `bool m_guidelinesUpdated`
- `int m_colorPage`
- `int m_groundLineIndex`
- `bool m_propertykA23`
- `bool m_propertykA24`
- `bool m_noTimePenalty`
- `int m_propertykA44`
- `int m_nextFreeID`
- `bool m_resetCamera`
- `int m_spawnGroup`
- `bool m_allowMultiRotation`
- `bool m_enablePlayerSqueeze`
- `bool m_fixGravityBug`
- `bool m_fixNegativeScale`
- `bool m_fixRobotJump`
- `bool m_dynamicLevelHeight`
- `bool m_sortGroups`
- `bool m_fixRadiusCollision`
- `bool m_enable22Changes`
- `bool m_allowStaticRotate`
- `bool m_reverseSync`
- `bool m_decreaseBoostSlide`

### `LevelTools`

**Functions:**

- `static int artistForAudio(int id)`
- `static gd::string base64DecodeString(gd::string str)`
- `static gd::string base64EncodeString(gd::string str)`
- `static cocos2d::CCDictionary* createStarPackDict()`
- `static gd::string fbURLForArtist(int id)`
- `static int getAudioBPM(int id)`
- `static gd::string getAudioFileName(int id)`
- `static gd::string getAudioString(int id)`
- `static gd::string getAudioTitle(int id)`
- `static bool getLastGameplayReversed()`
- `static bool getLastGameplayRotated()`
- `static float getLastTimewarp()`
- `static GJGameLevel* getLevel(int id, bool noString)`
- `static gd::unordered_set<int> getLevelList()`
- `static SongInfoObject* getSongObject(int id)`
- `static void moveTriggerObjectsToArray(cocos2d::CCArray* objects, cocos2d::CCDictionary* objectsDict, int index)`
- `static gd::string nameForArtist(int id)`
- `static gd::string ngURLForArtist(int id)`
- `static float offsetBPMForTrack(int id)`
- `static cocos2d::CCPoint posForTime(float time, cocos2d::CCArray* objects, int speed, bool platformer, int& rotateChannel)`
- `static cocos2d::CCPoint posForTimeInternal(float time, cocos2d::CCArray* objects, int speed, bool platformer, bool ignoreMinorAxis, bool ignoreWarp, int& rotateChannel, int unused)`
- `static void sortChannelOrderObjects(cocos2d::CCArray* objects, cocos2d::CCDictionary* objectsDict, bool moveObjects)`
- `static void sortSpeedObjects(cocos2d::CCArray* objects, GJBaseGameLayer* layer)`
- `static float timeForPos(cocos2d::CCPoint position, cocos2d::CCArray* objects, int speed, int order, int channel, bool songTriggers, bool platformer, bool ignoreWarp, bool ignoreRotate, int id)`
- `static void toggleDebugLogging(bool enabled)`
- `static gd::string urlForAudio(int id)`
- `static float valueForSpeedMod(int speed)`
- `static bool verifyLevelIntegrity(gd::string str, int id)`
- `static gd::string ytURLForArtist(int id)`

### `LevelUpdateDelegate`

**Functions:**

- `virtual void levelUpdateFinished(GJGameLevel* level, UpdateResponse response)`
- `virtual void levelUpdateFailed(int response)`

### `LevelUploadDelegate`

**Functions:**

- `virtual void levelUploadFinished(GJGameLevel* level)`
- `virtual void levelUploadFailed(GJGameLevel* level)`

### `LikeItemDelegate`

**Functions:**

- `virtual void likedItem(LikeItemType type, int id, bool liked)`

### `LikeItemLayer` : FLAlertLayer

**Functions:**

- `LikeItemLayer()`
- `static LikeItemLayer* create(LikeItemType type, int id, int parentID)`
- `virtual void keyBackClicked()`
- `bool init(LikeItemType type, int id, int parentID)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDislike(cocos2d::CCObject* sender)`
- `void onLike(cocos2d::CCObject* sender)`
- `void triggerLike(bool isLiked)`

**Members:**

- `LikeItemType m_itemType`
- `int m_itemID`
- `int m_commentSourceID`
- `LikeItemDelegate* m_likeDelegate`

### `ListButtonBar` : cocos2d::CCNode

**Functions:**

- `static ListButtonBar* create(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset, float arrowOffset, int arrowType)`
- `int getPage()`
- `void goToPage(int page)`
- `bool init(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset, float arrowOffset, int arrowType)`
- `void onLeft(cocos2d::CCObject* sender)`
- `void onRight(cocos2d::CCObject* sender)`

**Members:**

- `BoomScrollLayer* m_scrollLayer`
- `cocos2d::CCArray* m_pages`
- `ListButtonBarDelegate* m_delegate`
- `bool m_useMoveAnimation`

### `ListButtonBarDelegate`

**Functions:**

- `virtual void listButtonBarSwitchedPage(ListButtonBar* bar, int page)`

### `ListButtonPage` : cocos2d::CCLayer

**Functions:**

- `static ListButtonPage* create(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset)`
- `bool init(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset)`

### `ListCell` : TableViewCell

**Functions:**

- `ListCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromObject(cocos2d::CCObject* object, int id, int page, int index)`
- `void updateBGColor(int index)`

**Members:**

- `int m_unk230`

### `ListUploadDelegate`

**Functions:**

- `virtual void listUploadFinished(GJLevelList* list)`
- `virtual void listUploadFailed(GJLevelList* list, int response)`

### `LoadingCircle` : cocos2d::CCLayerColor

**Functions:**

- `LoadingCircle()`
- `static LoadingCircle* create()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `void fadeAndRemove()`
- `void setFade(bool fade)`
- `void setParentLayer(cocos2d::CCLayer* layer)`
- `void show()`

**Members:**

- `cocos2d::CCSprite* m_sprite`
- `cocos2d::CCLayer* m_parentLayer`
- `bool m_fade`

### `LoadingCircleSprite` : cocos2d::CCSprite

**Functions:**

- `static LoadingCircleSprite* create(float spinSpeed)`
- `cocos2d::CCAction* fadeInCircle(bool resetOpacity, float duration, float opacity)`
- `void hideCircle()`
- `bool init(float spinSpeed)`

### `LoadingLayer` : cocos2d::CCLayer

**Functions:**

- `LoadingLayer()`
- `~LoadingLayer()`
- `static LoadingLayer* create(bool refresh)`
- `static cocos2d::CCScene* scene(bool refresh)`
- `const char* getLoadingString()`
- `bool init(bool refresh)`
- `void loadAssets()`
- `void loadingFinished()`
- `void updateProgress(int progress)`

**Members:**

- `bool m_unknown`
- `bool m_unknown2`
- `int m_loadStep`
- `cocos2d::CCLabelBMFont* m_caption`
- `TextArea* m_textArea`
- `cocos2d::CCSprite* m_sliderBar`
- `float m_sliderGrooveXPos`
- `float m_sliderGrooveHeight`
- `bool m_fromRefresh`

### `LocalLevelManager` : GManager

**Functions:**

- `static LocalLevelManager* get()`
- `static LocalLevelManager* sharedState()`
- `virtual bool init()`
- `virtual void encodeDataTo(DS_Dictionary* dict)`
- `virtual void dataLoaded(DS_Dictionary* dict)`
- `virtual void firstLoad()`
- `cocos2d::CCDictionary* getAllLevelsInDict()`
- `cocos2d::CCArray* getAllLevelsWithName(gd::string name)`
- `cocos2d::CCArray* getCreatedLevels(int folder)`
- `cocos2d::CCArray* getCreatedLists(int folder)`
- `cocos2d::CCDictionary* getLevelsInNameGroups()`
- `gd::string getMainLevelString(int id)`
- `void markLevelsAsUnmodified()`
- `void moveLevelToTop(GJGameLevel* level)`
- `void reorderLevels()`
- `void reorderLists()`
- `void tryLoadMainLevelString(int id)`
- `int updateLevelOrder()`
- `void updateLevelRevision()`
- `int updateListOrder()`

**Members:**

- `cocos2d::CCArray* m_localLevels`
- `cocos2d::CCArray* m_localLists`
- `gd::unordered_map<int, gd::string> m_mainLevels`

### `MPLobbyLayer` : cocos2d::CCLayer, GJMPDelegate, UploadPopupDelegate, UploadActionDelegate, FLAlertLayerProtocol, TextInputDelegate

**Functions:**

- `static MPLobbyLayer* create(int type)`
- `static cocos2d::CCScene* scene(int type)`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void joinLobbyFinished(int id)`
- `virtual void joinLobbyFailed(int id, GJMPErrorCode errorType)`
- `virtual void updateComments()`
- `virtual void didUploadMPComment(int id)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void keyUp(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `bool init(int type)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onBtn1(cocos2d::CCObject* sender)`
- `void onBtn2(cocos2d::CCObject* sender)`
- `void onBtn3(cocos2d::CCObject* sender)`
- `void onComment(cocos2d::CCObject* sender)`
- `void onUpdateLobby()`
- `void postComment()`
- `void tryExitLobby()`
- `void updateLobby(float delay)`

**Members:**

- `int m_lobbyID`
- `cocos2d::CCLabelBMFont* m_lobbyLabel`
- `UploadActionPopup* m_uploadPopup`
- `GJCommentListLayer* m_listLayer`
- `CCTextInputNode* m_commentInput`
- `float m_lobbyDelay`
- `bool m_awaitingLobby`
- `bool m_lobbyJoined`

### `MapPackCell` : TableViewCell

**Functions:**

- `MapPackCell(char const* identifier, float width, float height)`
- `~MapPackCell()`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromMapPack(GJMapPack* pack)`
- `void onClaimReward(cocos2d::CCObject* sender)`
- `void onClick(cocos2d::CCObject* sender)`
- `void playCompleteEffect()`
- `void reloadCell()`
- `void updateBGColor(int index)`

**Members:**

- `GJMapPack* m_mapPack`
- `CCMenuItemSpriteExtra* m_viewButton`
- `CCMenuItemSpriteExtra* m_rewardButton`
- `cocos2d::CCArray* m_rewardLabels`
- `cocos2d::CCArray* m_rewardSprites`

### `MapSelectLayer` : cocos2d::CCLayer

**Functions:**

- `static MapSelectLayer* create()`
- `static cocos2d::CCScene* scene()`
- `virtual void update(float dt)`
- `virtual bool init()`
- `virtual void onExit()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void scrollWheel(float y, float x)`
- `bool checkTouchMonster(cocos2d::CCPoint position)`
- `GJMapObject* createObjectAtPoint(cocos2d::CCPoint position)`
- `cocos2d::CCPoint getConstrainedMapPos(cocos2d::CCPoint position)`
- `void onBack(cocos2d::CCObject* sender)`

**Members:**

- `GJBigSprite* m_bigSprite`
- `SimplePlayer* m_player`
- `cocos2d::CCNode* m_mainLayer`
- `bool m_unloadTexturesOnExit`
- `bool m_backPressed`
- `bool m_blockExit`
- `bool m_inTouch`
- `double m_lastTouchTime`
- `bool m_editMode`
- `cocos2d::CCPoint m_lastTouchPos`
- `cocos2d::CCPoint m_mapPos`
- `cocos2d::CCArray* m_monsters`
- `LevelEditorLayer* m_editorLayer`

### `MenuGameLayer` : cocos2d::CCLayer

**Functions:**

- `MenuGameLayer()`
- `static MenuGameLayer* create()`
- `virtual void update(float dt)`
- `virtual bool init()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `void destroyPlayer()`
- `cocos2d::ccColor3B getBGColor(int index)`
- `void resetPlayer()`
- `void tryJump(float dt)`
- `void updateColor(float dt)`
- `void updateColors()`

**Members:**

- `bool m_videoOptionsOpen`
- `float m_deltaCount`
- `bool m_isDestroyingPlayer`
- `int m_initCount`
- `cocos2d::CCPoint m_realBackgroundPosition`
- `PlayerObject* m_playerObject`
- `cocos2d::CCSprite* m_backgroundSprite`
- `GJGroundLayer* m_groundLayer`
- `float m_backgroundWrapPosition`

### `MenuLayer` : cocos2d::CCLayer, FLAlertLayerProtocol, GooglePlayDelegate

**Functions:**

- `static MenuLayer* get()`
- `static cocos2d::CCScene* scene(bool isVideoOptionsOpen)`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void googlePlaySignedIn()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void endGame()`
- `void firstNetworkTest()`
- `void onAchievements(cocos2d::CCObject* sender)`
- `void onCreator(cocos2d::CCObject* sender)`
- `void onDaily(cocos2d::CCObject* sender)`
- `void onDiscord(cocos2d::CCObject* sender)`
- `void onEveryplay(cocos2d::CCObject* sender)`
- `void onFacebook(cocos2d::CCObject* sender)`
- `void onFreeLevels(cocos2d::CCObject* sender)`
- `void onFullVersion(cocos2d::CCObject* sender)`
- `void onGameCenter(cocos2d::CCObject* sender)`
- `void onGarage(cocos2d::CCObject* sender)`
- `void onGooglePlayGames(cocos2d::CCObject* sender)`
- `void onMoreGames(cocos2d::CCObject* sender)`
- `void onMyProfile(cocos2d::CCObject* sender)`
- `void onNewgrounds(cocos2d::CCObject* sender)`
- `void onOptions(cocos2d::CCObject* sender)`
- `void onOptionsInstant()`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onQuit(cocos2d::CCObject* sender)`
- `void onRobTop(cocos2d::CCObject* sender)`
- `void onStats(cocos2d::CCObject* sender)`
- `void onTrailer(cocos2d::CCObject* sender)`
- `void onTwitch(cocos2d::CCObject* sender)`
- `void onTwitter(cocos2d::CCObject* sender)`
- `void onYouTube(cocos2d::CCObject* sender)`
- `void openOptions(bool videoOptions)`
- `void showGCQuestion()`
- `void showMeltdownPromo()`
- `void showTOS()`
- `void syncPlatformAchievements(float dt)`
- `void tryShowAd(float dt)`
- `void updateUserProfileButton()`
- `void videoOptionsClosed()`
- `void videoOptionsOpened()`
- `void willClose()`

**Members:**

- `bool m_showingTOS`
- `cocos2d::CCSprite* m_gpSprite`
- `cocos2d::CCSprite* m_viewProfileSprite`
- `cocos2d::CCLabelBMFont* m_profileLabel`
- `CCMenuItemSpriteExtra* m_profileButton`
- `void* m_unknown`
- `MenuGameLayer* m_menuGameLayer`

### `MessageListDelegate`

**Functions:**

- `virtual void loadMessagesFinished(cocos2d::CCArray* messages, char const* key)`
- `virtual void loadMessagesFailed(char const* key, GJErrorCode errorType)`
- `virtual void forceReloadMessages(bool sent)`
- `virtual void setupPageInfo(gd::string info, char const* key)`

### `MessagesProfilePage` : FLAlertLayer, FLAlertLayerProtocol, UploadActionDelegate, UploadPopupDelegate, MessageListDelegate

**Functions:**

- `static MessagesProfilePage* create(bool sent)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void loadMessagesFinished(cocos2d::CCArray* messages, char const* key)`
- `virtual void loadMessagesFailed(char const* key, GJErrorCode errorType)`
- `virtual void forceReloadMessages(bool sent)`
- `virtual void setupPageInfo(gd::string info, char const* key)`
- `void deleteSelected()`
- `bool init(bool sent)`
- `bool isCorrect(char const* key)`
- `void loadPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDeleteSelected(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onSentMessages(cocos2d::CCObject* sender)`
- `void onToggleAllObjects(cocos2d::CCObject* sender)`
- `void onUpdate(cocos2d::CCObject* sender)`
- `void setupCommentsBrowser(cocos2d::CCArray* messages)`
- `void untoggleAll()`
- `void updateLevelsLabel()`
- `void updatePageArrows()`

**Members:**

- `bool m_sentMessages`
- `gd::string m_messageKey`
- `cocos2d::CCLabelBMFont* m_levelsLabel`
- `cocos2d::CCLabelBMFont* m_errorLabel`
- `GJCommentListLayer* m_listLayer`
- `LoadingCircle* m_loadingCircle`
- `UploadActionPopup* m_actionPopup`
- `void* m_unkPtr`
- `CCMenuItemSpriteExtra* m_nextButton`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_refreshButton`
- `CCMenuItemToggler* m_toggleAllToggler`
- `int m_itemCount`
- `int m_pageStartIdx`
- `int m_pageEndIdx`
- `int m_page`
- `bool m_toggledAll`

### `MoreOptionsLayer` : FLAlertLayer, TextInputDelegate, GooglePlayDelegate, GJDropDownLayerDelegate

**Functions:**

- `MoreOptionsLayer()`
- `~MoreOptionsLayer()`
- `static MoreOptionsLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `virtual void googlePlaySignedIn()`
- `virtual void dropDownLayerWillClose(GJDropDownLayer* layer)`
- `void addToggle(char const* label, char const* key, char const* description)`
- `int countForPage(int page)`
- `void goToPage(int page)`
- `void incrementCountForPage(int page)`
- `const char* infoKey(int index)`
- `cocos2d::CCLayer* layerForPage(int page)`
- `const char* layerKey(int page)`
- `cocos2d::CCPoint nextPosition(int page)`
- `const char* objectKey(int page)`
- `cocos2d::CCArray* objectsForPage(int page)`
- `void offsetToNextPage()`
- `void onClose(cocos2d::CCObject* sender)`
- `void onFMODDebug(cocos2d::CCObject* sender)`
- `void onGPSignIn(cocos2d::CCObject* sender)`
- `void onGPSignOut(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onKeybindings(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onParental(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onSongBrowser(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `const char* pageKey(int page)`
- `void toggleGP()`

**Members:**

- `int m_page`
- `int m_toggleCount`
- `int m_pageCount`
- `cocos2d::CCDictionary* m_variables`
- `cocos2d::CCDictionary* m_objects`
- `CCMenuItemSpriteExtra* m_leftBtn`
- `CCMenuItemSpriteExtra* m_rightBtn`
- `CCTextInputNode* m_offsetInput`
- `CCMenuItemSpriteExtra* m_gpSignInBtn`
- `CCMenuItemSpriteExtra* m_gpSignOutBtn`
- `cocos2d::CCLabelBMFont* m_categoryLabel`

### `MoreSearchLayer` : FLAlertLayer, TextInputDelegate

**Functions:**

- `MoreSearchLayer()`
- `~MoreSearchLayer()`
- `static MoreSearchLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `void audioNext(cocos2d::CCObject* sender)`
- `void audioPrevious(cocos2d::CCObject* sender)`
- `CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler callback, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCoins(cocos2d::CCObject* sender)`
- `void onCompleted(cocos2d::CCObject* sender)`
- `void onEpic(cocos2d::CCObject* sender)`
- `void onFeatured(cocos2d::CCObject* sender)`
- `void onFollowed(cocos2d::CCObject* sender)`
- `void onFriends(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onLegendary(cocos2d::CCObject* sender)`
- `void onMythic(cocos2d::CCObject* sender)`
- `void onNoStar(cocos2d::CCObject* sender)`
- `void onOriginal(cocos2d::CCObject* sender)`
- `void onSongFilter(cocos2d::CCObject* sender)`
- `void onSongMode(cocos2d::CCObject* sender)`
- `void onTwoPlayer(cocos2d::CCObject* sender)`
- `void onUncompleted(cocos2d::CCObject* sender)`
- `void selectSong(int songID)`
- `void toggleSongNodes(bool custom, bool disable)`
- `void updateAudioLabel()`

**Members:**

- `cocos2d::CCLabelBMFont* m_audioTrackName`
- `CCMenuItemSpriteExtra* m_songLeftBtn`
- `CCMenuItemSpriteExtra* m_songRightBtn`
- `CCMenuItemSpriteExtra* m_normalBtn`
- `CCMenuItemSpriteExtra* m_customBtn`
- `CCTextInputNode* m_enterSongID`
- `cocos2d::CCArray* m_commonSongNodes`
- `cocos2d::CCArray* m_normalSongNodes`
- `cocos2d::CCArray* m_customSongNodes`

### `MoreVideoOptionsLayer` : FLAlertLayer, TextInputDelegate

**Functions:**

- `MoreVideoOptionsLayer()`
- `~MoreVideoOptionsLayer()`
- `static MoreVideoOptionsLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void addToggle(char const* label, char const* key, char const* description)`
- `int countForPage(int page)`
- `void goToPage(int page)`
- `void incrementCountForPage(int page)`
- `const char* infoKey(int index)`
- `cocos2d::CCLayer* layerForPage(int page)`
- `const char* layerKey(int page)`
- `cocos2d::CCPoint nextPosition(int page)`
- `const char* objectKey(int page)`
- `cocos2d::CCArray* objectsForPage(int page)`
- `void onApplyFPS(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `const char* pageKey(int page)`
- `void updateFPSButtons()`

**Members:**

- `int m_page`
- `int m_toggleCount`
- `int m_pageCount`
- `cocos2d::CCDictionary* m_values`
- `cocos2d::CCDictionary* m_variables`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `CCTextInputNode* m_fpsInput`
- `cocos2d::CCArray* m_fpsNodes`

### `MultiTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static MultiTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `MultilineBitmapFont` : cocos2d::CCSprite

**Functions:**

- `MultilineBitmapFont()`
- `~MultilineBitmapFont()`
- `static MultilineBitmapFont* createWithFont(char const* font, gd::string text, float scale, float width, cocos2d::CCPoint anchor, int height, bool disableColor)`
- `virtual void setOpacity(unsigned char opacity)`
- `bool initWithFont(char const* font, gd::string text, float scale, float width, cocos2d::CCPoint anchor, int height, bool disableColor)`
- `void moveSpecialDescriptors(int index, int size)`
- `gd::string readColorInfo(gd::string text)`
- `gd::string stringWithMaxWidth(gd::string text, float width, float scale)`

**Members:**

- `std::array<int, 300> m_fontWidths`
- `cocos2d::CCArray* m_specialDescriptors`
- `cocos2d::CCArray* m_characters`
- `cocos2d::CCArray* m_lines`
- `int m_unkInt`
- `bool m_unkBool`
- `void* m_unkPtr`
- `int m_height`
- `int m_width`
- `cocos2d::CCPoint m_position`
- `float m_maxWidth`
- `bool m_disableColor`

### `MultiplayerLayer` : cocos2d::CCLayer

**Functions:**

- `static MultiplayerLayer* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void onBack(cocos2d::CCObject* sender)`
- `void onBtn1(cocos2d::CCObject* sender)`
- `void onBtn2(cocos2d::CCObject* sender)`

### `MusicArtistObject` : cocos2d::CCObject

**Functions:**

- `static MusicArtistObject* create(int id, gd::string name, gd::string url, gd::string youtube)`
- `bool init(int id, gd::string name, gd::string url, gd::string youtube)`

**Members:**

- `int m_artistID`
- `gd::string m_artistName`
- `gd::string m_artistURL`
- `gd::string m_artistYouTube`

### `MusicBrowser` : FLAlertLayer, MusicDownloadDelegate, TableViewCellDelegate, SetTextPopupDelegate, FLAlertLayerProtocol, SliderDelegate

**Functions:**

- `static MusicBrowser* create(int songID, GJSongType songType)`
- `virtual void update(float dt)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void musicActionFinished(GJMusicAction action)`
- `virtual void musicActionFailed(GJMusicAction action)`
- `virtual void sliderEnded(Slider* slider)`
- `virtual void setTextPopupClosed(SetTextPopup* popup, gd::string text)`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `virtual int getSelectedCellIdx()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `bool init(int songID, GJSongType songType)`
- `void onArtistFilters(cocos2d::CCObject* sender)`
- `void onClearSearch(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onPage(cocos2d::CCObject* sender)`
- `void onPlaybackControl(cocos2d::CCObject* sender)`
- `void onSearch(cocos2d::CCObject* sender)`
- `void onTagFilters(cocos2d::CCObject* sender)`
- `void onUpdateLibrary(cocos2d::CCObject* sender)`
- `void setupList(MusicSearchResult* result)`
- `void setupMusicBrowser()`
- `void setupSongControls()`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void trySetupMusicBrowser()`
- `void updatePageLabel()`

**Members:**

- `GJSongType m_songType`
- `MusicSearchResult* m_searchResult`
- `GJCommentListLayer* m_listLayer`
- `cocos2d::CCLabelBMFont* m_infoLabel`
- `cocos2d::CCLabelBMFont* m_pageLabel`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `CCMenuItemSpriteExtra* m_refreshButton`
- `CCMenuItemSpriteExtra* m_clearSearchButton`
- `CCMenuItemSpriteExtra* m_tagFilterButton`
- `CCMenuItemSpriteExtra* m_artistFilterButton`
- `LoadingCircleSprite* m_circleSprite`
- `int m_songID`
- `int m_libraryVersion`
- `bool m_gettingURL`
- `bool m_selectedCell`
- `MusicBrowserDelegate* m_delegate`
- `Slider* m_playSlider`
- `cocos2d::CCLabelBMFont* m_playLabel`
- `CCMenuItemSpriteExtra* m_playButton`
- `bool m_autoUpdating`

### `MusicBrowserDelegate`

**Functions:**

- `virtual void musicBrowserClosed(MusicBrowser* browser)`

### `MusicDelegateHandler` : cocos2d::CCNode

**Functions:**

- `MusicDelegateHandler()`
- `static MusicDelegateHandler* create(MusicDownloadDelegate* delegate)`
- `bool init(MusicDownloadDelegate* delegate)`

**Members:**

- `MusicDownloadDelegate* m_delegate`

### `MusicDownloadDelegate`

**Functions:**

- `virtual void loadSongInfoFinished(SongInfoObject* object)`
- `virtual void loadSongInfoFailed(int id, GJSongError errorType)`
- `virtual void downloadSongStarted(int id)`
- `virtual void downloadSongFinished(int id)`
- `virtual void downloadSongFailed(int id, GJSongError errorType)`
- `virtual void songStateChanged()`
- `virtual void downloadSFXFinished(int id)`
- `virtual void downloadSFXFailed(int id, GJSongError errorType)`
- `virtual void musicActionFinished(GJMusicAction action)`
- `virtual void musicActionFailed(GJMusicAction action)`

### `MusicDownloadManager` : cocos2d::CCNode, PlatformDownloadDelegate

**Functions:**

- `static MusicDownloadManager* sharedState()`
- `virtual bool init()`
- `void addDLToActive(char const* tag)`
- `void addDLToActive(char const* tag, cocos2d::CCObject* obj)`
- `void addMusicDownloadDelegate(MusicDownloadDelegate* delegate)`
- `SongInfoObject* addSongObjectFromString(gd::string str)`
- `void clearSong(int songID)`
- `void clearUnusedSongs()`
- `cocos2d::CCDictionary* createArtistsInfo(gd::string str)`
- `void createSongsInfo(gd::string songsStr, gd::string artistsStr)`
- `void dataLoaded(DS_Dictionary* dict)`
- `void deleteSFX(int id)`
- `void deleteSong(int id)`
- `void downloadCustomSong(int id)`
- `void downloadMusicLibrary()`
- `void downloadSFX(int id)`
- `void downloadSFXFailed(int id, GJSongError errorCode)`
- `void downloadSFXFinished(int id)`
- `void downloadSFXLibrary()`
- `void downloadSong(int id)`
- `void downloadSongFailed(int id, GJSongError errorCode)`
- `void downloadSongFinished(int id)`
- `void downloadSongStarted(int id)`
- `void encodeDataTo(DS_Dictionary* dict)`
- `cocos2d::CCArray* filterMusicByArtistID(int id, cocos2d::CCArray* songs)`
- `cocos2d::CCArray* filterMusicByTag(int id, cocos2d::CCArray* songs)`
- `void firstSetup()`
- `gd::string generateCustomContentURL(gd::string path)`
- `void generateResourceAssetList()`
- `cocos2d::CCArray* getAllMusicArtists(OptionsObjectDelegate* delegate)`
- `cocos2d::CCArray* getAllMusicObjects(GJSongType type)`
- `cocos2d::CCArray* getAllMusicTags(OptionsObjectDelegate* delegate)`
- `cocos2d::CCArray* getAllSFXObjects(bool onlySFX)`
- `cocos2d::CCArray* getAllSongs()`
- `void getCustomContentURL()`
- `cocos2d::CCObject* getDLObject(char const* id)`
- `cocos2d::CCArray* getDownloadedSongs()`
- `int getDownloadProgress(int id)`
- `MusicArtistObject* getMusicArtistForID(int id)`
- `SongInfoObject* getMusicObject(int id)`
- `char const* getSFXDownloadKey(int id)`
- `int getSFXDownloadProgress(int id)`
- `SFXFolderObject* getSFXFolderObjectForID(int id)`
- `gd::string getSFXFolderPathForID(int id, bool nextFolder)`
- `SFXInfoObject* getSFXObject(int id)`
- `char const* getSongDownloadKey(int id)`
- `void getSongInfo(int id, bool download)`
- `char const* getSongInfoKey(int id)`
- `SongInfoObject* getSongInfoObject(int id)`
- `int getSongPriority()`
- `void handleIt(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type)`
- `void handleItND(cocos2d::CCNode* node, void* data)`
- `void incrementPriorityForSong(int id)`
- `bool isDLActive(char const* tag)`
- `bool isMusicLibraryLoaded()`
- `bool isResourceSFX(int id)`
- `bool isResourceSong(int id)`
- `bool isRunningActionForSongID(int id)`
- `bool isSFXDownloaded(int id)`
- `bool isSFXLibraryLoaded()`
- `bool isSongDownloaded(int id)`
- `void limitDownloadedSongs()`
- `void loadSongInfoFailed(int id, GJSongError errorCode)`
- `void loadSongInfoFinished(SongInfoObject* object)`
- `void musicActionFailed(GJMusicAction action)`
- `void musicActionFinished(GJMusicAction action)`
- `gd::string nameForTagID(int id)`
- `void onDownloadMusicLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onDownloadSFXCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onDownloadSFXLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onDownloadSongCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onGetCustomContentURLCompleted(gd::string response, gd::string tag)`
- `void onGetSongInfoCompleted(gd::string response, gd::string tag)`
- `void onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onTryUpdateMusicLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void onTryUpdateSFXLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response)`
- `void parseMusicLibrary()`
- `void parseSFXLibrary()`
- `gd::string pathForSFX(int id)`
- `gd::string pathForSFXFolder(int id)`
- `gd::string pathForSong(int id)`
- `gd::string pathForSongFolder(int id)`
- `cocos2d::extension::CCHttpRequest* ProcessHttpGetRequest(gd::string url, gd::string tag, cocos2d::extension::SEL_HttpResponse selector, int connectTimeout, int readTimeout)`
- `callback void ProcessHttpRequest(gd::string url, gd::string params, gd::string tag, GJHttpType type)`
- `void removeDLFromActive(char const* tag)`
- `void removeMusicDownloadDelegate(MusicDownloadDelegate* delegate)`
- `cocos2d::CCDictionary* responseToDict(gd::string response, char const* delimiter)`
- `void showTOS(FLAlertLayerProtocol* delegate)`
- `void songStateChanged()`
- `void stopDownload(int id)`
- `void storeMusicObject(SongInfoObject* object)`
- `void storeSFXInfoObject(SFXInfoObject* object)`
- `void tryLoadLibraries()`
- `void tryUpdateMusicLibrary()`
- `void tryUpdateSFXLibrary()`

**Members:**

- `cocos2d::CCDictionary* m_activeDownloads`
- `cocos2d::CCArray* m_musicDownloadDelegates`
- `cocos2d::CCDictionary* m_songObjects`
- `cocos2d::CCDictionary* m_MDLM003`
- `int m_songPriority`
- `gd::string m_customContentURL`
- `cocos2d::CCDictionary* m_sfxObjects`
- `cocos2d::CCArray* m_sfxArtists`
- `int m_sfxLibraryVersion`
- `int m_sfxObjectCount`
- `bool m_requestedSfxLibraryDownloaded`
- `cocos2d::CCDictionary* m_musicObjects`
- `cocos2d::CCDictionary* m_musicArtists`
- `gd::map<int, gd::string> m_musicTags`
- `int m_musicLibraryVersion`
- `int m_musicObjectCount`
- `int m_ncsSongCount`
- `bool m_downloadingMusicLibrary`
- `bool m_triedToLoadLibraries`
- `bool m_unkBool`
- `gd::unordered_set<int> m_resourceSfxUnorderedSet`
- `gd::unordered_set<int> m_resourceSongUnorderedSet`

### `MusicSearchResult` : cocos2d::CCObject, OptionsObjectDelegate

**Functions:**

- `MusicSearchResult()`
- `~MusicSearchResult()`
- `static MusicSearchResult* create(GJSongType songType)`
- `virtual void updateObjects(AudioSortType type)`
- `virtual void stateChanged(OptionsObject* object)`
- `cocos2d::CCArray* applyArtistFilters(cocos2d::CCArray* objects)`
- `cocos2d::CCArray* applyTagFilters(cocos2d::CCArray* objects)`
- `void createArtistFilterObjects()`
- `void createTagFilterObjects()`
- `cocos2d::CCArray* getFilesMatchingSearch(cocos2d::CCArray* objects, gd::string query)`
- `bool init(GJSongType songType)`
- `void updateFutureCount(cocos2d::CCArray* objects, cocos2d::CCArray* allObjects)`
- `void updateObjects()`

**Members:**

- `cocos2d::CCArray* m_filterObjects`
- `cocos2d::CCArray* m_tagFilterObjects`
- `cocos2d::CCArray* m_artistFilterObjects`
- `int m_startIndex`
- `int m_audioType`
- `gd::string m_searchQuery`
- `AudioSortType m_sortType`
- `bool m_tagFilter`
- `bool m_artistFilter`
- `GJSongType m_songType`

### `NCSInfoLayer` : FLAlertLayer, FLAlertLayerProtocol

**Functions:**

- `NCSInfoLayer()`
- `static NCSInfoLayer* create(CustomSongLayer* layer)`
- `virtual void keyBackClicked()`
- `bool init(CustomSongLayer* layer)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onLibrary(cocos2d::CCObject* sender)`
- `void onNCS(cocos2d::CCObject* sender)`
- `void onNCSIO(cocos2d::CCObject* sender)`
- `void onNCSUsage(cocos2d::CCObject* sender)`

**Members:**

- `CustomSongLayer* m_songLayer`

### `NewgroundsInfoLayer` : FLAlertLayer, FLAlertLayerProtocol

**Functions:**

- `NewgroundsInfoLayer()`
- `static NewgroundsInfoLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `void onArtists(cocos2d::CCObject* sender)`
- `void onChanges(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onGuidelines(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNewgrounds(cocos2d::CCObject* sender)`
- `void onSupporter(cocos2d::CCObject* sender)`

### `NodePoint` : cocos2d::CCObject

**Functions:**

- `NodePoint()`
- `static NodePoint* create(cocos2d::CCPoint point)`
- `bool init(cocos2d::CCPoint point)`

**Members:**

- `cocos2d::CCPoint m_point`

### `NumberInputDelegate`

**Functions:**

- `virtual void numberInputClosed(NumberInputLayer* layer)`

### `NumberInputLayer` : FLAlertLayer

**Functions:**

- `NumberInputLayer()`
- `static NumberInputLayer* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `void deleteLast()`
- `void inputNumber(int num)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDone(cocos2d::CCObject* sender)`
- `void onNumber(cocos2d::CCObject* sender)`
- `void updateNumberState()`

**Members:**

- `cocos2d::CCLabelBMFont* m_inputLabel`
- `CCMenuItemSpriteExtra* m_okButton`
- `int m_minimum`
- `int m_maximum`
- `gd::string m_inputString`
- `NumberInputDelegate* m_delegate`

### `OBB2D` : cocos2d::CCNode

**Functions:**

- `static OBB2D* create(cocos2d::CCPoint center, float width, float height, float rotationAngle)`
- `void calculateWithCenter(cocos2d::CCPoint center, float width, float height, float rotationAngle)`
- `void computeAxes()`
- `cocos2d::CCRect getBoundingRect()`
- `bool init(cocos2d::CCPoint center, float width, float height, float rotationAngle)`
- `void orderCorners()`
- `bool overlaps(OBB2D* other)`
- `bool overlaps1Way(OBB2D* other)`

**Members:**

- `std::array<cocos2d::CCPoint, 4> m_corners`
- `std::array<cocos2d::CCPoint, 4> m_positions`
- `std::array<cocos2d::CCPoint, 4> m_edges`
- `std::array<double, 2> m_projections`
- `cocos2d::CCPoint m_center`

### `ObjectControlGameObject` : EffectGameObject

**Functions:**

- `ObjectControlGameObject()`
- `static ObjectControlGameObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

### `ObjectManager` : cocos2d::CCNode

**Functions:**

- `static ObjectManager* instance()`
- `static cocos2d::CCDictionary* replaceAllOccurencesOfString(cocos2d::CCString* target, cocos2d::CCString* replacement, cocos2d::CCDictionary* dict)`
- `virtual bool init()`
- `bool animLoaded(char const* anim)`
- `cocos2d::CCDictionary* getDefinition(char const* definitionKey)`
- `cocos2d::CCDictionary* getGlobalAnimCopy(char const* anim)`
- `void loadCopiedAnimations()`
- `void loadCopiedSets()`
- `void purgeObjectManager()`
- `void setLoaded(char const* objectName)`
- `void setup()`

**Members:**

- `cocos2d::CCDictionary* m_objectDefinitions`
- `cocos2d::CCDictionary* m_loadedAnimations`

### `ObjectToolbox` : cocos2d::CCNode

**Functions:**

- `static ObjectToolbox* sharedState()`
- `virtual bool init()`
- `cocos2d::CCArray* allKeys()`
- `float gridNodeSizeForKey(int key)`
- `const char* intKeyToFrame(int key)`
- `const char* perspectiveBlockFrame(int key)`

**Members:**

- `gd::map<int, gd::string> m_allKeys`

### `OnlineListDelegate`

**Functions:**

- `virtual void loadListFinished(cocos2d::CCArray* objects, char const* key)`
- `virtual void loadListFailed(char const* key)`
- `virtual void setupPageInfo(gd::string info, char const* key)`

### `OpacityEffectAction`

**Functions:**

- `void step(float delta)`

**Members:**

- `float m_duration`
- `float m_fromValue`
- `float m_toValue`
- `bool m_finished`
- `bool m_disabled`
- `float m_deltaTime`
- `int m_targetGroupID`
- `float m_currentValue`
- `int m_triggerUniqueID`
- `int m_controlID`
- `float m_deltaTimeRelated`
- `float m_durationRelated`

### `OptionsCell` : TableViewCell

**Functions:**

- `OptionsCell(char const* identifier, float width, float height)`
- `void loadFromObject(OptionsObject* object)`
- `void onToggleOption(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `OptionsObject* m_optionsObject`

### `OptionsLayer` : GJDropDownLayer, FLAlertLayerProtocol

**Functions:**

- `OptionsLayer()`
- `static OptionsLayer* create()`
- `virtual void customSetup()`
- `virtual void layerHidden()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `CCMenuItemToggler* createToggleButton(gd::string text, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `void exitLayer()`
- `void musicSliderChanged(cocos2d::CCObject* sender)`
- `void onAccount(cocos2d::CCObject* sender)`
- `void onHelp(cocos2d::CCObject* sender)`
- `void onMenuMusic(cocos2d::CCObject* sender)`
- `void onOptions(cocos2d::CCObject* sender)`
- `void onProgressBar(cocos2d::CCObject* sender)`
- `void onRate(cocos2d::CCObject* sender)`
- `void onRecordReplays(cocos2d::CCObject* sender)`
- `void onSecretVault(cocos2d::CCObject* sender)`
- `void onSoundtracks(cocos2d::CCObject* sender)`
- `void onSupport(cocos2d::CCObject* sender)`
- `void onVideo(cocos2d::CCObject* sender)`
- `void sfxSliderChanged(cocos2d::CCObject* sender)`
- `void tryEnableRecord()`

**Members:**

- `cocos2d::CCMenu* m_optionsMenu`
- `void* m_unknown`
- `int m_layerChoice`
- `bool m_recordReplays`
- `Slider* m_musicSlider`
- `Slider* m_sfxSlider`
- `int m_lastVaultDialog`

### `OptionsObject` : cocos2d::CCObject

**Functions:**

- `static OptionsObject* create(int id, bool enabled, gd::string name, OptionsObjectDelegate* delegate)`
- `bool init(int id, bool enabled, gd::string name, OptionsObjectDelegate* delegate)`
- `void toggleState()`

**Members:**

- `int m_optionID`
- `bool m_enabled`
- `gd::string m_name`
- `OptionsObjectDelegate* m_delegate`
- `int m_count`

### `OptionsObjectDelegate`

**Functions:**

- `virtual void stateChanged(OptionsObject* object)`

### `OptionsScrollLayer` : FLAlertLayer, TableViewCellDelegate

**Functions:**

- `static OptionsScrollLayer* create(cocos2d::CCArray* objects, bool recreate, int minimum)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `cocos2d::CCArray* getRelevantObjects(cocos2d::CCArray* objects)`
- `bool init(cocos2d::CCArray* objects, bool recreate, int minimum)`
- `void onClose(cocos2d::CCObject* sender)`
- `void setupList(cocos2d::CCArray* objects)`

**Members:**

- `cocos2d::CCArray* m_optionObjects`
- `GJCommentListLayer* m_listLayer`
- `bool m_recreateList`
- `int m_minCount`

### `ParentalOptionsLayer` : FLAlertLayer

**Functions:**

- `ParentalOptionsLayer()`
- `~ParentalOptionsLayer()`
- `static ParentalOptionsLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void addToggle(char const* label, char const* variable, char const* info)`
- `int countForPage(int page)`
- `void goToPage(int page)`
- `void incrementCountForPage(int page)`
- `const char* infoKey(int index)`
- `cocos2d::CCLayer* layerForPage(int page)`
- `const char* layerKey(int page)`
- `cocos2d::CCPoint nextPosition(int page)`
- `const char* objectKey(int page)`
- `cocos2d::CCArray* objectsForPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onToggle(cocos2d::CCObject* sender)`
- `const char* pageKey(int page)`

**Members:**

- `int m_page`
- `int m_toggleCount`
- `int m_maxPage`
- `cocos2d::CCDictionary* m_values`
- `cocos2d::CCDictionary* m_variables`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`

### `ParticleGameObject` : EnhancedGameObject

**Functions:**

- `ParticleGameObject()`
- `static ParticleGameObject* create()`
- `virtual bool init()`
- `virtual void setScaleX(float scaleX)`
- `virtual void setScaleY(float scaleY)`
- `virtual void setScale(float scale)`
- `virtual void setRotation(float rotation)`
- `virtual void setRotationX(float rotationX)`
- `virtual void setRotationY(float rotationY)`
- `virtual void setChildColor(cocos2d::ccColor3B const& color)`
- `virtual void customSetup()`
- `virtual void addMainSpriteToParent(bool reorder)`
- `virtual void resetObject()`
- `virtual void deactivateObject(bool deactivate)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void claimParticle()`
- `virtual void unclaimParticle()`
- `virtual void particleWasActivated()`
- `virtual void setObjectColor(cocos2d::ccColor3B const& color)`
- `virtual void blendModeChanged()`
- `virtual void updateParticleColor(cocos2d::ccColor3B const& color)`
- `virtual void updateParticleOpacity(unsigned char opacity)`
- `virtual void updateMainParticleOpacity(unsigned char opacity)`
- `virtual void updateSecondaryParticleOpacity(unsigned char opacity)`
- `virtual void updateSyncedAnimation(float totalTime, int frameIndex)`
- `virtual void updateAnimateOnTrigger(bool animate)`
- `void applyParticleSettings(cocos2d::CCParticleSystemQuad* particle)`
- `void createAndAddCustomParticle()`
- `void createParticlePreviewArt()`
- `void setParticleString(gd::string str)`
- `void updateParticle()`
- `void updateParticleAngle(float angle, cocos2d::CCParticleSystemQuad* particle)`
- `void updateParticlePreviewArtOpacity(float opacity)`
- `void updateParticleScale(float scale)`
- `void updateParticleStruct()`

**Members:**

- `gd::string m_particleData`
- `bool m_updatedParticleData`
- `cocos2d::ParticleStruct m_particleStruct`
- `bool m_hasUniformObjectColor`
- `int m_popupPage`
- `bool m_shouldQuickStart`
- `float m_respawnResult`
- `bool m_startingRespawn`
- `bool m_notPreviewing`

### `ParticlePreviewLayer` : cocos2d::CCLayerColor

**Functions:**

- `ParticlePreviewLayer()`
- `static ParticlePreviewLayer* create(cocos2d::CCParticleSystemQuad* particleSystem)`
- `virtual void draw()`
- `virtual void visit()`
- `bool init(cocos2d::CCParticleSystemQuad* particleSystem)`
- `void postVisit()`
- `void preVisitWithClippingRect(cocos2d::CCRect rect)`

**Members:**

- `int m_particleMode`
- `int m_drawMode`
- `cocos2d::CCParticleSystemQuad* m_particleSystem`
- `bool m_gravityMode`

### `PauseLayer` : CCBlockLayer, FLAlertLayerProtocol

**Functions:**

- `PauseLayer()`
- `static PauseLayer* create(bool unfocused)`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void customSetup()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void keyUp(cocos2d::enumKeyCodes key, double timestamp)`
- `void createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position)`
- `void goEdit()`
- `bool init(bool unfocused)`
- `void musicSliderChanged(cocos2d::CCObject* sender)`
- `void onEdit(cocos2d::CCObject* sender)`
- `void onHelp(cocos2d::CCObject* sender)`
- `void onNormalMode(cocos2d::CCObject* sender)`
- `void onPracticeMode(cocos2d::CCObject* sender)`
- `void onQuit(cocos2d::CCObject* sender)`
- `void onRecordReplays(cocos2d::CCObject* sender)`
- `void onReplay(cocos2d::CCObject* sender)`
- `void onRestart(cocos2d::CCObject* sender)`
- `void onRestartFull(cocos2d::CCObject* sender)`
- `void onResume(cocos2d::CCObject* sender)`
- `void onSettings(cocos2d::CCObject* sender)`
- `void onTime(cocos2d::CCObject* sender)`
- `void onTryEdit(cocos2d::CCObject* sender)`
- `void setupProgressBars()`
- `void sfxSliderChanged(cocos2d::CCObject* sender)`
- `void tryQuit(cocos2d::CCObject* sender)`
- `void tryShowBanner(float dt)`

**Members:**

- `bool m_unfocused`
- `bool m_tryingQuit`

### `PlatformDownloadDelegate`

**Functions:**

- `virtual void downloadFinished(char const* key)`
- `virtual void downloadFailed(char const* key)`

### `PlatformToolbox`

**Functions:**

- `static void activateGameCenter()`
- `static bool copyToClipboard(gd::string str)`
- `static bool doesFileExist(gd::string path)`
- `static void downloadAndSavePromoImage(gd::string url, gd::string path)`
- `static void gameDidSave()`
- `[[missing(win, mac)]]`
- `static gd::string getClipboardString()`
- `static float getDeviceRefreshRate()`
- `static cocos2d::CCSize getDisplaySize()`
- `static gd::string getRawPath(char const* path)`
- `static gd::string getUniqueUserID()`
- `static gd::string getUserID()`
- `static void hideCursor()`
- `static bool isControllerConnected()`
- `static bool isHD()`
- `static bool isLocalPlayerAuthenticated()`
- `static bool isLowMemoryDevice()`
- `static bool isNetworkAvailable()`
- `static bool isSignedInGooglePlay()`
- `static void loadAndDecryptFileToString(char const* dirPath, char const* fileName, gd::string& str)`
- `static void logEvent(char const* event)`
- `static void onGameLaunch()`
- `static void onNativePause()`
- `static void onNativeResume()`
- `static void onToggleKeyboard()`
- `static void openAppPage()`
- `static void platformShutdown()`
- `static void refreshWindow()`
- `static void reportAchievementWithID(char const* key, int percent)`
- `static void reportLoadingFinished()`
- `static void resizeWindow(float width, float height)`
- `static void saveAndEncryptStringToFile(gd::string& str, char const* fileName, char const* dirPath)`
- `static void sendMail(char const* title, char const* content, char const* address)`
- `static void setBlockBackButton(bool block)`
- `static void setKeyboardState(bool state)`
- `static bool shouldResumeSound()`
- `static void showAchievements()`
- `static void showCursor()`
- `static void signInGooglePlay()`
- `static void signOutGooglePlay()`
- `static cocos2d::CCSprite* spriteFromSavedFile(gd::string path)`
- `static void toggleCallGLFinish(bool enable)`
- `static void toggleCPUSleepMode(bool enable)`
- `static void toggleForceTimer(bool enable)`
- `static void toggleFullScreen(bool fullscreen, bool borderless, bool fix)`
- `static void toggleLockCursor(bool isLocked)`
- `static void toggleMouseControl(bool enable)`
- `static void toggleSmoothFix(bool enable)`
- `static void toggleVerticalSync(bool enable)`
- `static void tryShowRateDialog(gd::string gameName)`
- `static void updateMouseControl()`
- `static void updateWindowedSize(float width, float height)`

### `PlayLayer` : GJBaseGameLayer, CCCircleWaveDelegate, CurrencyRewardDelegate, DialogDelegate

**Functions:**

- `PlayLayer()`
- `~PlayLayer()`
- `static PlayLayer* create(GJGameLevel* level, bool useReplay, bool dontCreateObjects)`
- `static PlayLayer* get()`
- `static cocos2d::CCScene* scene(GJGameLevel* level, bool useReplay, bool dontCreateObjects)`
- `virtual void onEnterTransitionDidFinish()`
- `virtual void onExit()`
- `virtual void postUpdate(float dt)`
- `virtual void checkForEnd()`
- `virtual void testTime()`
- `virtual void updateVerifyDamage()`
- `virtual void updateAttemptTime(float attemptTime)`
- `virtual void updateVisibility(float dt)`
- `virtual float opacityForObject(GameObject* object)`
- `virtual void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2)`
- `virtual void activateEndTrigger(int targetID, bool reverse, bool lockPlayerY)`
- `virtual void activatePlatformerEndTrigger(EndTriggerGameObject* object, gd::vector<int> const& remapKeys)`
- `virtual void toggleGlitter(bool visible)`
- `virtual void destroyPlayer(PlayerObject* player, GameObject* object)`
- `virtual void toggleGroundVisibility(bool visible)`
- `virtual void toggleMGVisibility(bool visible)`
- `virtual void toggleHideAttempts(bool hide)`
- `virtual float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id)`
- `virtual cocos2d::CCPoint posForTime(float time)`
- `virtual void resetSPTriggered()`
- `virtual void updateTimeWarp(float timeWarp)`
- `virtual void playGravityEffect(bool flip)`
- `virtual void manualUpdateObjectColors(GameObject* object)`
- `virtual void checkpointActivated(CheckpointGameObject* object)`
- `virtual void flipArt(bool flip)`
- `virtual void updateTimeLabel(int seconds, int centiseconds, bool decimals)`
- `virtual void checkSnapshot()`
- `virtual void toggleProgressbar()`
- `virtual void toggleInfoLabel()`
- `virtual void removeAllCheckpoints()`
- `virtual void toggleMusicInPractice()`
- `virtual void processCheckpoints()`
- `virtual void resetLevel()`
- `virtual void currencyWillExit(CurrencyRewardLayer* layer)`
- `virtual void circleWaveWillBeRemoved(CCCircleWave* circleWave)`
- `virtual void dialogClosed(DialogLayer* layer)`
- `void addCircle(CCCircleWave* cw)`
- `void addObject(GameObject* object)`
- `void addToGroupOld(GameObject* object)`
- `void applyCustomEnterEffect(GameObject* object, bool isRight)`
- `void applyEnterEffect(GameObject* object, int enterType, bool isRight)`
- `bool canPauseGame()`
- `CheckpointObject* checkpointWithID(int id)`
- `void colorObject(int id, cocos2d::ccColor3B color)`
- `void commitJumps()`
- `void compareStateSnapshot()`
- `CheckpointObject* createCheckpoint()`
- `void createObjectsFromSetupFinished()`
- `void delayedFullReset()`
- `void delayedResetLevel()`
- `void fullReset()`
- `float getCurrentPercent()`
- `int getCurrentPercentInt()`
- `cocos2d::CCPoint getEndPosition()`
- `CheckpointObject* getLastCheckpoint()`
- `float getRelativeMod(cocos2d::CCPoint position, float right, float left, float offset)`
- `float getRelativeModNew(cocos2d::CCPoint position, float mod, float offset, bool unused, bool isRight)`
- `double getTempMilliTime()`
- `void gravityEffectFinished()`
- `void incrementJumps()`
- `bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects)`
- `bool isGameplayActive()`
- `void levelComplete()`
- `void loadActiveSaveObjects(gd::vector<SavedActiveObjectState>& activeObjects, gd::vector<SavedSpecialObjectState>& specialObjects)`
- `void loadDefaultColors()`
- `void loadDynamicSaveObjects(gd::vector<SavedObjectStateRef>& dynamicObjects)`
- `void loadFromCheckpoint(CheckpointObject* object)`
- `CheckpointObject* loadLastCheckpoint()`
- `CheckpointObject* markCheckpoint()`
- `void onQuit()`
- `void optimizeColorGroups()`
- `void optimizeOpacityGroups()`
- `void pauseGame(bool unfocused)`
- `void playEndAnimationToPos(cocos2d::CCPoint position)`
- `void playPlatformerEndAnimationToPos(cocos2d::CCPoint position, bool instant)`
- `void playReplay(gd::string inputs)`
- `void prepareCreateObjectsFromSetup(gd::string& levelString)`
- `void prepareMusic(bool dontWait)`
- `void processCreateObjectsFromSetup()`
- `void processLoadedMoveActions()`
- `void queueCheckpoint()`
- `void removeAllObjects()`
- `void removeCheckpoint(bool first)`
- `void removeFromGroupOld(GameObject* object)`
- `void resetLevelFromStart()`
- `void resume()`
- `void resumeAndRestart(bool fromStart)`
- `void saveActiveSaveObjects(gd::vector<SavedActiveObjectState>& activeObjects, gd::vector<SavedSpecialObjectState>& specialObjects)`
- `void saveDynamicSaveObjects(gd::vector<SavedObjectStateRef>& dynamicObjects)`
- `void scanActiveSaveObjects()`
- `void scanDynamicSaveObjects()`
- `void screenFlipObject(GameObject* object)`
- `void setupHasCompleted()`
- `bool shouldBlend(int colorID)`
- `bool shouldDebugDraw()`
- `void showCompleteEffect()`
- `void showCompleteText()`
- `void showEndLayer()`
- `void showHint()`
- `void showNewBest(bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle)`
- `void showRetryLayer()`
- `void showTwoPlayerGuide()`
- `void spawnCircle()`
- `void spawnFirework()`
- `void startGame()`
- `void startGameDelayed()`
- `void startMusic()`
- `void startRecording()`
- `void startRecordingDelayed()`
- `void stopRecording()`
- `void storeCheckpoint(CheckpointObject* checkpoint)`
- `void takeStateSnapshot()`
- `void toggleBGEffectVisibility(bool enabled)`
- `void toggleDebugDraw()`
- `void toggleGhostEffect(int type)`
- `void toggleIgnoreDamage(bool value)`
- `void togglePracticeMode(bool practiceMode)`
- `void tryStartRecord()`
- `void updateAttempts()`
- `void updateDebugDrawSettings()`
- `void updateEffectPositions()`
- `void updateInfoLabel()`
- `void updateInvisibleBlock(GameObject* object, float rightFadeBound, float leftFadeBound, float rightFadeWidth, float leftFadeWidth, cocos2d::ccColor3B const& lbgColor)`
- `void updateProgressbar()`
- `void updateScreenRotation(int rotation, bool add, bool convert, float duration, int easingType, float easingRate, int uniqueID, int controlID)`
- `void updateTestModeLabel()`

**Members:**

- `int m_unk36c8`
- `bool m_unk36cc`
- `bool m_unk36cd`
- `bool m_unk36ce`
- `bool m_unk36cf`
- `bool m_damageVerified`
- `gd::vector<gd::string> m_objectStrings`
- `cocos2d::CCArray* m_coinArray`
- `bool m_passedIntegrity`
- `int m_objectsCreated`
- `gd::vector<GameObject*> m_dynamicSaveObjects`
- `gd::vector<GameObject*> m_activeSaveObjects1`
- `gd::vector<GameObject*> m_activeSaveObjects2`
- `gd::vector<SavedObjectStateRef> m_dynamicSaveObjects2`
- `int m_unk3768`
- `bool m_platformerRestart`
- `bool m_unk376d`
- `bool m_isIgnoreDamageEnabled`
- `cocos2d::CCLabelBMFont* m_statusLabel`
- `float m_unk3778`
- `int m_unk377c`
- `float m_unk3780`
- `float m_unk3784`
- `int m_unk3788`
- `int m_unk378c`
- `bool m_endChecked`
- `float m_endXPosition`
- `CheckpointObject* m_currentCheckpoint`
- `cocos2d::CCArray* m_checkpointArray`
- `cocos2d::CCArray* m_speedObjects`
- `bool m_unk37b0`
- `bool m_unk37b1`
- `cocos2d::CCPoint m_enterEffectPosition`
- `cocos2d::CCArray* m_unk37c0`
- `bool m_isSilent`
- `int m_unk37cc`
- `cocos2d::CCArray* m_circleWaveArray`
- `cocos2d::CCArray* m_collectibles`
- `bool m_unk37e0`
- `int m_pulseRodIndex`
- `float m_maxObjectX`
- `cocos2d::CCLabelBMFont* m_attemptLabel`
- `cocos2d::CCLabelBMFont* m_percentageLabel`
- `bool m_decimalPercentage`
- `bool m_hintShown`
- `cocos2d::CCSprite* m_progressBar`
- `cocos2d::CCSprite* m_progressFill`
- `float m_progressWidth`
- `float m_progressHeight`
- `int m_totalGravityEffects`
- `int m_activeGravityEffects`
- `int m_gravityEffectIndex`
- `cocos2d::CCArray* m_gravityEffects`
- `bool m_doNot`
- `float m_unk383c`
- `bool m_skipAudioStep`
- `gd::unordered_set<int> m_blendingColors`
- `int m_jumps`
- `bool m_hasJumped`
- `int m_uncommittedJumps`
- `bool m_showLeaderboardPercentage`
- `bool m_hasCompletedLevel`
- `bool m_inResetDelay`
- `int m_lastAttemptPercent`
- `bool m_endLayerStars`
- `int m_orbs`
- `int m_diamonds`
- `bool m_secretKey`
- `bool m_recordingStopped`
- `double m_unk38b0`
- `double m_unk38b8`
- `double m_unk38c0`
- `bool m_unk38c8`
- `float m_unk38cc`
- `int m_unk38d0`
- `double m_attemptTime`
- `double m_bestAttemptTime`
- `double m_pauseTime`
- `double m_currentTime`
- `double m_pauseDelta`
- `float m_unk3900`
- `bool m_glitterEnabled`
- `bool m_bgEffectDisabled`
- `bool m_unk3906`
- `bool m_isPaused`
- `bool m_disableGravityEffect`
- `cocos2d::CCLabelBMFont* m_infoLabel`
- `cocos2d::CCPoint m_unk3918`
- `cocos2d::CCPoint m_unk3920`
- `cocos2d::CCDictionary* m_colorKeyDict`
- `gd::vector<cocos2d::ccColor3B> m_keyColors`
- `gd::vector<float> m_keyOpacities`
- `DynamicBitset m_keyPulses`
- `int m_nextColorKey`
- `bool m_tryPlaceCheckpoint`
- `CheckpointGameObject* m_activatedCheckpoint`
- `bool m_musicPrepared`
- `cocos2d::CCPoint m_endPosition`
- `EndTriggerGameObject* m_platformerEndTrigger`

### `PlayerButtonCommand`

**Members:**

- `PlayerButton m_button`
- `bool m_isPush`
- `bool m_isPlayer2`
- `int m_step`
- `double m_timestamp`

### `PlayerCheckpoint` : cocos2d::CCNode

**Functions:**

- `PlayerCheckpoint()`
- `static PlayerCheckpoint* create()`
- `virtual bool init()`

**Members:**

- `cocos2d::CCPoint m_position`
- `cocos2d::CCPoint m_lastPosition`
- `double m_yVelocityUnrounded`
- `bool m_isUpsideDown`
- `bool m_isSideways`
- `bool m_isShip`
- `bool m_isBall`
- `bool m_isBird`
- `bool m_isSwing`
- `bool m_isDart`
- `bool m_isRobot`
- `bool m_isSpider`
- `bool m_isOnGround`
- `GhostType m_ghostType`
- `bool m_isMini`
- `float m_playerSpeed`
- `bool m_isHidden`
- `bool m_isGoingLeft`
- `double m_maybeReverseSpeed`
- `bool m_jumpBuffered`
- `bool m_isDashing`
- `float m_dashStartTimeold`
- `double m_dashX`
- `double m_dashY`
- `double m_dashAngle`
- `double m_dashStartTime`
- `DashRingObject* m_dashRing`
- `bool m_platformerCheckpoint`
- `double m_lastFlipTime`
- `float m_gravityMod`
- `GameObject* m_objectSnappedTo`
- `double m_snapDistance`
- `double m_accelerationOrSpeed`
- `bool m_decreaseBoostSlide`
- `int m_followRelated`
- `gd::vector<float> m_playerFollowFloats`
- `float m_unk838`
- `bool m_isOnSlope`
- `bool m_wasOnSlope`
- `float m_slopeVelocity`
- `float m_rotation`
- `bool m_wasTeleported`
- `bool m_fixGravityBug`
- `bool m_reverseSync`
- `double m_yVelocityBeforeSlope`
- `double m_slopeStartTime`
- `bool m_justPlacedStreak`
- `int m_lastCollisionBottom`
- `int m_lastCollisionTop`
- `int m_lastCollisionLeft`
- `int m_lastCollisionRight`
- `int m_unk50C`
- `int m_unk510`
- `GameObject* m_currentSlope2`
- `GameObject* m_preLastGroundObject`
- `float m_slopeAngle`
- `bool m_slopeSlidingMaybeRotated`
- `bool m_quickCheckpointMode`
- `GameObject* m_collidedObject`
- `GameObject* m_lastGroundObject`
- `GameObject* m_collidingWithLeft`
- `GameObject* m_collidingWithRight`
- `double m_scaleXRelated2`
- `double m_groundYVelocity`
- `double m_yVelocityRelated`
- `double m_scaleXRelated3`
- `android, ios {`
- `bool m_collidingBetweenSteps`

### `PlayerControlGameObject` : EffectGameObject

**Functions:**

- `PlayerControlGameObject()`
- `static PlayerControlGameObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `bool m_stopJump`
- `bool m_stopMove`
- `bool m_stopRotation`
- `bool m_stopSlide`

### `PlayerFireBoostSprite` : cocos2d::CCSprite

**Functions:**

- `static PlayerFireBoostSprite* create()`
- `virtual bool init()`
- `void animateFireIn()`
- `void animateFireOut()`
- `void loopFireAnimation()`

**Members:**

- `float m_size`

### `PlayerObject` : GameObject, AnimatedSpriteDelegate

**Functions:**

- `PlayerObject()`
- `~PlayerObject()`
- `static PlayerObject* create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)`
- `virtual void update(float dt)`
- `virtual void setScaleX(float scale)`
- `virtual void setScaleY(float scale)`
- `virtual void setScale(float scale)`
- `virtual void setPosition(cocos2d::CCPoint const& position)`
- `virtual void setVisible(bool visible)`
- `virtual void setRotation(float rotation)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void setColor(cocos2d::ccColor3B const& color)`
- `virtual void setFlipX(bool flipX)`
- `virtual void setFlipY(bool flipY)`
- `virtual void resetObject()`
- `virtual cocos2d::CCPoint getRealPosition()`
- `virtual OBB2D* getOrientedBox()`
- `virtual float getObjectRotation()`
- `virtual void animationFinished(char const* key)`
- `void activateStreak()`
- `void addAllParticles()`
- `void addToTouchedRings(RingObject* object)`
- `void addToYVelocity(double yVelocity, int type)`
- `void animatePlatformerJump(float scale)`
- `void boostPlayer(float yVelocity)`
- `void bumpPlayer(float bumpMod, int objectType, bool noEffects, GameObject* object)`
- `bool buttonDown(PlayerButton button)`
- `bool canStickToGround()`
- `void checkSnapJumpToObject(GameObject* object)`
- `bool collidedWithObject(float dt, GameObject* object)`
- `bool collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck)`
- `bool collidedWithObjectInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck)`
- `void collidedWithSlope(float dt, GameObject* object, bool skipPre)`
- `void collidedWithSlopeInternal(float dt, GameObject* object, bool forced)`
- `float convertToClosestRotation(float rotation)`
- `void copyAttributes(PlayerObject* player)`
- `void createFadeOutDartStreak()`
- `void createRobot(int frame)`
- `void createSpider(int frame)`
- `void deactivateParticle()`
- `void deactivateStreak(bool stop)`
- `bool destroyFromHitHead()`
- `void didHitHead()`
- `void disableCustomGlowColor()`
- `void disablePlayerControls()`
- `void disableSwingFire()`
- `void doReversePlayer(bool reverse)`
- `void enableCustomGlowColor(cocos2d::ccColor3B const& color)`
- `void enablePlayerControls()`
- `void exitPlatformerAnimateJump()`
- `void fadeOutStreak2(float duration)`
- `void flashPlayer(float flashDuration, float flashDelay, cocos2d::ccColor3B mainColor, cocos2d::ccColor3B secondColor)`
- `void flipGravity(bool flip, bool noEffects)`
- `int flipMod()`
- `void gameEventTriggered(int gameEvent, int material)`
- `GameObjectType getActiveMode()`
- `double getCurrentXVelocity()`
- `float getModifiedSlopeYVel()`
- `float getOldPosition(float dt)`
- `cocos2d::ccColor3B getSecondColor()`
- `double getYVelocity()`
- `void gravityDown()`
- `void gravityUp()`
- `void handlePlayerCommand(int command)`
- `bool handleRotatedCollisionInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope)`
- `bool handleRotatedObjectCollision(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck)`
- `void handleRotatedSlopeCollision(float dt, GameObject* object, bool skipPre)`
- `void hardFlipGravity()`
- `void hitGround(GameObject* object, bool notFlipped)`
- `void hitGroundNoJump(GameObject* object, bool notFlipped)`
- `void incrementJumps()`
- `bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)`
- `bool isBoostValid(float yVelocity)`
- `bool isFlying()`
- `bool isInBasicMode()`
- `bool isInNormalMode()`
- `bool isSafeFlip(float flipTime)`
- `bool isSafeHeadTest()`
- `bool isSafeMode(float changeTime)`
- `bool isSafeSpiderFlip(float flipTime)`
- `void levelFlipFinished()`
- `bool levelFlipping()`
- `void levelWillFlip()`
- `void limitDashRotation(float& rotation)`
- `void loadFromCheckpoint(PlayerCheckpoint* object)`
- `void lockPlayer()`
- `void logValues()`
- `void modeDidChange()`
- `void performSlideCheck()`
- `void placeStreakPoint()`
- `void playBumpEffect(int objectType, GameObject* player)`
- `void playBurstEffect()`
- `void playCompleteEffect(bool noEffects, bool instant)`
- `void playDeathEffect()`
- `void playDynamicSpiderRun()`
- `void playerDestroyed(bool noEffects)`
- `bool playerIsFalling(float yVelocity)`
- `bool playerIsFallingBugged()`
- `bool playerIsMovingUp()`
- `void playerTeleported()`
- `void playingEndEffect()`
- `void playSpawnEffect()`
- `void playSpiderDashEffect(cocos2d::CCPoint from, cocos2d::CCPoint to)`
- `void postCollision(float dt, bool betweenSteps)`
- `void preCollision()`
- `bool preSlopeCollision(float dt, GameObject* object)`
- `void propellPlayer(float yVelocity, bool noEffects, int objectType)`
- `bool pushButton(PlayerButton button)`
- `void pushDown()`
- `void pushPlayer(float yVelocity)`
- `void redirectDash(float rotation)`
- `void redirectPlayerForce(float rotation, float modifier, float minimum, float maximum)`
- `void releaseAllButtons()`
- `bool releaseButton(PlayerButton button)`
- `void removeAllParticles()`
- `void removePendingCheckpoint()`
- `void removePlacedCheckpoint()`
- `void resetAllParticles()`
- `void resetCollisionLog(bool full)`
- `void resetCollisionValues()`
- `void resetPlayerIcon()`
- `void resetStateVariables()`
- `void resetStreak()`
- `void resetTouchedRings(bool removeAll)`
- `int reverseMod()`
- `void reversePlayer(EffectGameObject* object)`
- `void ringJump(RingObject* object, bool skipCheck)`
- `void rotateGameplay(int moveDirection, int groundDirection, bool editVelocity, float velocityModX, float velocityModY, bool overrideVelocity, bool dontSlide)`
- `void rotateGameplayObject(GameObject* object)`
- `void rotateGameplayOnly(bool sideways)`
- `void rotatePreSlopeObjects()`
- `void runBallRotation(float speed)`
- `void runBallRotation2()`
- `void runNormalRotation()`
- `void runNormalRotation(bool notNormalMode, float speed)`
- `void runRotateAction(bool ground, int type)`
- `void saveToCheckpoint(PlayerCheckpoint* checkpoint)`
- `void setSecondColor(cocos2d::ccColor3B const& color)`
- `void setupStreak()`
- `void setYVelocity(double velocity, int type)`
- `void spawnCircle()`
- `void spawnCircle2()`
- `void spawnDualCircle()`
- `void spawnFromPlayer(PlayerObject* player, bool flip)`
- `void spawnPortalCircle(cocos2d::ccColor3B color, float startRadius)`
- `void spawnScaleCircle()`
- `void specialGroundHit()`
- `void speedDown()`
- `void speedUp()`
- `void spiderTestJump(bool dynamic)`
- `void spiderTestJumpInternal(bool dynamic)`
- `void spiderTestJumpX(bool dynamic)`
- `void spiderTestJumpY(bool dynamic)`
- `void startDashing(DashRingObject* object)`
- `void stopBurstEffect()`
- `void stopDashing()`
- `void stopParticles()`
- `void stopPlatformerJumpAnimation()`
- `void stopRotation(bool ground, int type)`
- `void stopStreak2()`
- `void storeCollision(PlayerCollisionDirection direction, int id)`
- `bool switchedDirTo(PlayerButton button)`
- `void switchedToMode(GameObjectType type)`
- `bool testForMoving(float dt, GameObject* object)`
- `void toggleBirdMode(bool enable, bool noEffects)`
- `void toggleDartMode(bool enable, bool noEffects)`
- `void toggleFlyMode(bool enable, bool noEffects)`
- `void toggleGhostEffect(GhostType type)`
- `void togglePlatformerMode(bool val)`
- `void togglePlayerScale(bool enable, bool noEffects)`
- `void toggleRobotMode(bool enable, bool noEffects)`
- `void toggleRollMode(bool enable, bool noEffects)`
- `void toggleSpiderMode(bool enable, bool noEffects)`
- `void toggleSwingMode(bool enable, bool noEffects)`
- `void toggleVisibility(bool visible)`
- `void touchedObject(GameObject* object)`
- `void tryPlaceCheckpoint()`
- `void unrotateGameplayObject(GameObject* object)`
- `void unrotatePreSlopeObjects()`
- `void updateCheckpointMode(bool enable)`
- `void updateCheckpointTest()`
- `void updateCollide(PlayerCollisionDirection direction, GameObject* object)`
- `void updateCollideBottom(float y, GameObject* object)`
- `void updateCollideLeft(float x, GameObject* object)`
- `void updateCollideRight(float x, GameObject* object)`
- `void updateCollideTop(float y, GameObject* object)`
- `void updateDashAnimation()`
- `void updateDashArt()`
- `void updateEffects(float param)`
- `void updateGlowColor()`
- `void updateInternalActions(float dt)`
- `void updateJump(float dt)`
- `void updateJumpVariables()`
- `void updateLastGroundObject(GameObject* object)`
- `void updateMove(float dt)`
- `void updatePlayerArt()`
- `void updatePlayerBirdFrame(int frame)`
- `void updatePlayerDartFrame(int frame)`
- `void updatePlayerForce(cocos2d::CCPoint velocity, bool additive)`
- `void updatePlayerFrame(int frame)`
- `void updatePlayerGlow()`
- `void updatePlayerJetpackFrame(int frame)`
- `void updatePlayerRobotFrame(int frame)`
- `void updatePlayerRollFrame(int frame)`
- `void updatePlayerScale()`
- `void updatePlayerShipFrame(int frame)`
- `void updatePlayerSpiderFrame(int frame)`
- `void updatePlayerSpriteExtra(gd::string frameName)`
- `void updatePlayerSwingFrame(int frame)`
- `void updateRobotAnimationSpeed()`
- `void updateRotation(float dt)`
- `void updateRotation(float dt, float rotation)`
- `void updateShipRotation(float dt)`
- `void updateShipSpriteExtra(gd::string frameName)`
- `void updateSlopeRotation(float dt)`
- `void updateSlopeYVelocity(float yVelocity)`
- `void updateSpecial(float dt)`
- `void updateStateVariables()`
- `void updateStaticForce(float rotation, float staticForce, bool additive)`
- `void updateStreakBlend(bool blend)`
- `void updateStreaks(float dt)`
- `void updateSwingFire()`
- `void updateTimeMod(float speed, bool noEffects)`
- `bool usingWallLimitedMode()`
- `void yStartDown()`
- `void yStartUp()`
- `bool isVanillaPlayer()`
- `bool isPlayer1()`
- `bool isPlayer2()`

**Members:**

- `cocos2d::CCNode* m_mainLayer`
- `bool m_wasTeleported`
- `bool m_fixGravityBug`
- `bool m_reverseSync`
- `double m_yVelocityBeforeSlope`
- `double m_dashX`
- `double m_dashY`
- `double m_dashAngle`
- `double m_dashStartTime`
- `DashRingObject* m_dashRing`
- `double m_slopeStartTime`
- `bool m_justPlacedStreak`
- `GameObject* m_maybeLastGroundObject`
- `cocos2d::CCDictionary* m_collisionLogTop`
- `cocos2d::CCDictionary* m_collisionLogBottom`
- `cocos2d::CCDictionary* m_collisionLogLeft`
- `cocos2d::CCDictionary* m_collisionLogRight`
- `int m_lastCollisionBottom`
- `int m_lastCollisionTop`
- `int m_lastCollisionLeft`
- `int m_lastCollisionRight`
- `int m_unk50C`
- `int m_unk510`
- `GameObject* m_currentSlope2`
- `GameObject* m_preLastGroundObject`
- `float m_slopeAngle`
- `bool m_slopeSlidingMaybeRotated`
- `bool m_quickCheckpointMode`
- `GameObject* m_collidedObject`
- `GameObject* m_lastGroundObject`
- `GameObject* m_collidingWithLeft`
- `GameObject* m_collidingWithRight`
- `int m_maybeSavedPlayerFrame`
- `double m_scaleXRelated2`
- `double m_groundYVelocity`
- `double m_yVelocityRelated`
- `double m_scaleXRelated3`
- `android, ios {`
- `bool m_collidingBetweenSteps`

### `PointNode` : cocos2d::CCObject

**Functions:**

- `PointNode()`
- `static PointNode* create(cocos2d::CCPoint point)`
- `bool init(cocos2d::CCPoint point)`

**Members:**

- `cocos2d::CCPoint m_point`

### `PriceLabel` : cocos2d::CCNode

**Functions:**

- `static PriceLabel* create(int price)`
- `bool init(int price)`
- `void setColor(cocos2d::ccColor3B color)`
- `void setOpacity(float opacity)`
- `void setPrice(int price)`

**Members:**

- `cocos2d::CCLabelBMFont* m_priceLabel`
- `cocos2d::CCSprite* m_coinSprite`

### `ProfilePage` : FLAlertLayer, FLAlertLayerProtocol, LevelCommentDelegate, CommentUploadDelegate, UserInfoDelegate, UploadActionDelegate, UploadPopupDelegate, LeaderboardManagerDelegate

**Functions:**

- `static ProfilePage* create(int accountID, bool ownProfile)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void updateUserScoreFinished()`
- `virtual void updateUserScoreFailed()`
- `virtual void getUserInfoFinished(GJUserScore* score)`
- `virtual void getUserInfoFailed(int id)`
- `virtual void userInfoChanged(GJUserScore* score)`
- `virtual void loadCommentsFinished(cocos2d::CCArray* comments, char const* key)`
- `virtual void loadCommentsFailed(char const* key)`
- `virtual void setupPageInfo(gd::string info, char const* key)`
- `virtual void commentUploadFinished(int parentID)`
- `virtual void commentUploadFailed(int parentID, CommentError errorType)`
- `virtual void commentDeleteFailed(int id, int parentID)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `void blockUser()`
- `bool init(int accountID, bool ownProfile)`
- `bool isCorrect(char const* key)`
- `bool isOnWatchlist(int id)`
- `void loadPage(int page)`
- `void loadPageFromUserInfo(GJUserScore* score)`
- `void onBlockUser(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onComment(cocos2d::CCObject* sender)`
- `void onCommentHistory(cocos2d::CCObject* sender)`
- `void onCopyName(cocos2d::CCObject* sender)`
- `void onFollow(cocos2d::CCObject* sender)`
- `void onFriend(cocos2d::CCObject* sender)`
- `void onFriends(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onMessages(cocos2d::CCObject* sender)`
- `void onMyLevels(cocos2d::CCObject* sender)`
- `void onMyLists(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void onRequests(cocos2d::CCObject* sender)`
- `void onSendMessage(cocos2d::CCObject* sender)`
- `void onSettings(cocos2d::CCObject* sender)`
- `void onSocialPage(cocos2d::CCObject* sender)`
- `void onStatInfo(cocos2d::CCObject* sender)`
- `void onUpdate(cocos2d::CCObject* sender)`
- `void setupComments()`
- `void setupCommentsBrowser(cocos2d::CCArray* comments)`
- `void showNoAccountError()`
- `void toggleMainPageVisibility(bool visible)`
- `void toggleShip(cocos2d::CCObject* sender)`
- `void updateLevelsLabel()`
- `void updatePageArrows()`

**Members:**

- `GJUserScore* m_score`
- `int m_accountID`
- `bool m_ownProfile`
- `gd::string m_profileKey`
- `cocos2d::CCLabelBMFont* m_somethingWentWrong`
- `cocos2d::CCLabelBMFont* m_usernameLabel`
- `GJCommentListLayer* m_list`
- `CCMenuItemSpriteExtra* m_rightArrow`
- `CCMenuItemSpriteExtra* m_leftArrow`
- `CCMenuItemSpriteExtra* m_followBtn`
- `bool m_unk`
- `cocos2d::CCArray* m_buttons`
- `cocos2d::CCArray* m_arrayWithUsernameLabel`
- `int m_itemCount`
- `int m_pageStartIdx`
- `int m_pageEndIdx`
- `int m_page`
- `LoadingCircle* m_circle`
- `UploadActionPopup* m_popupDelegate`
- `CCMenuItemSpriteExtra* m_refreshBtn`
- `int m_unk2`

### `PromoInterstitial` : FLAlertLayer

**Functions:**

- `static PromoInterstitial* create(bool fullVersion)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `bool init(bool fullVersion)`
- `void onClick(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void setup()`

**Members:**

- `bool m_fullVersion`
- `cocos2d::CCMenu* m_closeMenu`
- `bool m_promoTouched`
- `gd::string m_marketLink`
- `bool m_showAdBanner`

### `PulseEffectAction`

**Functions:**

- `bool isFinished()`
- `void step(float delta)`
- `float valueForDelta(float currentTime, float fadeInTime, float holdTime, float fadeOutTime)`

**Members:**

- `bool m_disabled`
- `float m_fadeInTime`
- `float m_holdTime`
- `float m_fadeOutTime`
- `float m_deltaTime`
- `int m_targetGroupID`
- `float m_currentValue`
- `cocos2d::ccColor3B m_color`
- `PulseEffectType m_pulseEffectType`
- `cocos2d::ccHSVValue m_hsv`
- `int m_colorIndex`
- `bool m_mainOnly`
- `bool m_detailOnly`
- `bool m_isDynamicHsv`
- `int m_triggerUniqueID`
- `int m_controlID`
- `float m_startTime`

### `PurchaseItemPopup` : FLAlertLayer

**Functions:**

- `static PurchaseItemPopup* create(GJStoreItem* item)`
- `virtual void keyBackClicked()`
- `bool init(GJStoreItem* item)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onPurchase(cocos2d::CCObject* sender)`

**Members:**

- `GJStoreItem* m_storeItem`
- `GJPurchaseDelegate* m_delegate`

### `RandTriggerGameObject` : ChanceTriggerGameObject

**Functions:**

- `RandTriggerGameObject()`
- `static RandTriggerGameObject* create()`
- `virtual bool init()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `int getRandomGroupID()`
- `int getTotalChance()`

### `RateDemonLayer` : FLAlertLayer, UploadPopupDelegate, UploadActionDelegate

**Functions:**

- `RateDemonLayer()`
- `~RateDemonLayer()`
- `static RateDemonLayer* create(int levelID)`
- `virtual void keyBackClicked()`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `bool init(int levelID)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onRate(cocos2d::CCObject* sender)`
- `void selectRating(cocos2d::CCObject* sender)`

**Members:**

- `bool m_uploadFinished`
- `CCMenuItemSpriteExtra* m_submitButton`
- `cocos2d::CCArray* m_demons`
- `void* m_unkPtr`
- `int m_levelID`
- `int m_demonRate`
- `bool m_moderator`
- `UploadActionPopup* m_popup`
- `RateLevelDelegate* m_delegate`

### `RateLevelDelegate`

**Functions:**

- `virtual void rateLevelClosed()`

### `RateLevelLayer` : FLAlertLayer

**Functions:**

- `RateLevelLayer()`
- `~RateLevelLayer()`
- `static RateLevelLayer* create(int levelID)`
- `virtual void keyBackClicked()`
- `bool init(int levelID)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onRate(cocos2d::CCObject* sender)`
- `void selectRating(cocos2d::CCObject* sender)`

**Members:**

- `CCMenuItemSpriteExtra* m_submitButton`
- `cocos2d::CCArray* m_difficulties`
- `int m_levelID`
- `int m_levelRate`
- `RateLevelDelegate* m_delegate`

### `RateStarsLayer` : FLAlertLayer, UploadPopupDelegate, UploadActionDelegate

**Functions:**

- `static RateStarsLayer* create(int levelID, bool platformer, bool moderator)`
- `virtual void keyBackClicked()`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `CCMenuItemSpriteExtra* getStarsButton(int stars, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale)`
- `bool init(int levelID, bool platformer, bool moderator)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onFeature(cocos2d::CCObject* sender)`
- `void onRate(cocos2d::CCObject* sender)`
- `void onToggleCoins(cocos2d::CCObject* sender)`
- `void selectRating(cocos2d::CCObject* sender)`

**Members:**

- `bool m_uploadFinished`
- `bool m_moderator`
- `CCMenuItemSpriteExtra* m_submitButton`
- `cocos2d::CCArray* m_buttons`
- `int m_levelID`
- `int m_starsRate`
- `bool m_coinsToggled`
- `cocos2d::CCSprite* m_coinSprite`
- `UploadActionPopup* m_popup`
- `GJDifficultySprite* m_difficultySprite`
- `int m_featureState`
- `RateLevelDelegate* m_delegate`

### `RetryLevelLayer` : GJDropDownLayer, RewardedVideoDelegate

**Functions:**

- `RetryLevelLayer()`
- `~RetryLevelLayer()`
- `static RetryLevelLayer* create()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void customSetup()`
- `virtual void showLayer(bool instant)`
- `virtual void enterAnimFinished()`
- `virtual void rewardedVideoFinished()`
- `virtual bool shouldOffsetRewardCurrency()`
- `virtual void keyUp(cocos2d::enumKeyCodes key, double timestamp)`
- `const char* getEndText()`
- `void onEveryplay(cocos2d::CCObject* sender)`
- `void onFullVersion(cocos2d::CCObject* sender)`
- `void onMenu(cocos2d::CCObject* sender)`
- `void onReplay(cocos2d::CCObject* sender)`
- `void onRewardedVideo(cocos2d::CCObject* sender)`
- `void setupLastProgress()`

**Members:**

- `cocos2d::CCMenu* m_mainMenu`
- `bool m_exitingMenu`
- `bool m_unk1e9`

### `RewardUnlockLayer` : FLAlertLayer, CurrencyRewardDelegate

**Functions:**

- `static RewardUnlockLayer* create(int type, RewardsPage* page)`
- `virtual void keyBackClicked()`
- `virtual void currencyWillExit(CurrencyRewardLayer* layer)`
- `void connectionTimeout()`
- `bool init(int type, RewardsPage* page)`
- `void labelEnterFinishedO(cocos2d::CCObject* object)`
- `void onClose(cocos2d::CCObject* sender)`
- `void playDropSound()`
- `void playLabelEffect(int count, int type, cocos2d::CCSprite* sprite, cocos2d::CCPoint position, float delay)`
- `void playRewardEffect()`
- `bool readyToCollect(GJRewardItem* item)`
- `void showCloseButton()`
- `bool showCollectReward(GJRewardItem* item)`
- `void step2()`
- `void step3()`

**Members:**

- `cocos2d::CCArray* m_backgroundObjects`
- `RewardsPage* m_rewardsPage`
- `GJChestSprite* m_chestSprite`
- `int m_chestType`
- `bool m_rewardCollected`
- `bool m_animationPlayed`
- `GJRewardItem* m_rewardItem`
- `cocos2d::CCLabelBMFont* m_wrongLabel`
- `CCMenuItemSpriteExtra* m_closeBtn`
- `CCMenuItemSpriteExtra* m_rewardBtn`
- `float m_unkFloat`

### `RewardedVideoDelegate`

**Functions:**

- `virtual void rewardedVideoFinished()`
- `virtual bool shouldOffsetRewardCurrency()`

### `RewardsPage` : FLAlertLayer, FLAlertLayerProtocol, GJRewardDelegate

**Functions:**

- `RewardsPage()`
- `~RewardsPage()`
- `static RewardsPage* create()`
- `static char const* getRewardFrame(int type, int state)`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void rewardsStatusFinished(int type)`
- `virtual void rewardsStatusFailed()`
- `void onClose(cocos2d::CCObject* sender)`
- `void onFreeStuff(cocos2d::CCObject* sender)`
- `void onReward(cocos2d::CCObject* sender)`
- `void tryGetRewards()`
- `void unlockLayerClosed(RewardUnlockLayer* layer)`
- `callback void updateTimers(float dt)`

**Members:**

- `cocos2d::CCLabelBMFont* m_leftLabel`
- `cocos2d::CCLabelBMFont* m_rightLabel`
- `CCMenuItemSpriteExtra* m_leftChest`
- `CCMenuItemSpriteExtra* m_rightChest`
- `bool m_leftOpen`
- `bool m_rightOpen`
- `RewardUnlockLayer* m_openLayer`

### `RingObject` : EffectGameObject

**Functions:**

- `RingObject()`
- `static RingObject* create(char const* frame)`
- `virtual void setScale(float scale)`
- `virtual void setRotation(float rotation)`
- `virtual void resetObject()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void setRScale(float scale)`
- `virtual void triggerActivated(float xPosition)`
- `virtual bool shouldDrawEditorHitbox()`
- `virtual void powerOnObject(int state)`
- `bool init(char const* frame)`
- `void spawnCircle()`

**Members:**

- `bool m_claimTouch`
- `bool m_isSpawnOnly`

### `RotateGameplayGameObject` : EffectGameObject

**Functions:**

- `RotateGameplayGameObject()`
- `static RotateGameplayGameObject* create()`
- `virtual bool init()`
- `virtual void updateStartValues()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `void updateGameplayRotation()`

**Members:**

- `int m_moveDirection`
- `int m_groundDirection`
- `bool m_editVelocity`
- `bool m_overrideVelocity`
- `float m_velocityModX`
- `float m_velocityModY`
- `bool m_changeChannel`
- `bool m_channelOnly`
- `int m_targetChannelID`
- `bool m_instantOffset`
- `bool m_dontSlide`

### `SFXBrowser` : FLAlertLayer, MusicDownloadDelegate, TableViewCellDelegate, SetTextPopupDelegate, SelectSFXSortDelegate

**Functions:**

- `SFXBrowser()`
- `~SFXBrowser()`
- `static SFXBrowser* create(int id)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void musicActionFinished(GJMusicAction action)`
- `virtual void musicActionFailed(GJMusicAction action)`
- `virtual void sortSelectClosed(SelectSFXSortLayer* layer)`
- `virtual void setTextPopupClosed(SetTextPopup* popup, gd::string text)`
- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `virtual int getSelectedCellIdx()`
- `virtual bool shouldSnapToSelected()`
- `bool init(int id)`
- `void onClearSearch(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCredits(cocos2d::CCObject* sender)`
- `void onExitFolder(cocos2d::CCObject* sender)`
- `void onPage(cocos2d::CCObject* sender)`
- `void onSearch(cocos2d::CCObject* sender)`
- `void onSorting(cocos2d::CCObject* sender)`
- `void onToggleCompactMode(cocos2d::CCObject* sender)`
- `void onUpdateLibrary(cocos2d::CCObject* sender)`
- `void setupList(SFXSearchResult* result)`
- `void setupSFXBrowser()`
- `void trySetupSFXBrowser()`
- `void updatePageLabel()`

**Members:**

- `SFXSearchResult* m_searchResult`
- `cocos2d::CCArray* m_sfxObjects`
- `GJCommentListLayer* m_listLayer`
- `cocos2d::CCLabelBMFont* m_nameLabel`
- `cocos2d::CCLabelBMFont* m_pathLabel`
- `cocos2d::CCLabelBMFont* m_infoLabel`
- `cocos2d::CCLabelBMFont* m_pageLabel`
- `cocos2d::CCLabelBMFont* m_searchLabel`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `CCMenuItemSpriteExtra* m_backButton`
- `CCMenuItemSpriteExtra* m_refreshButton`
- `CCMenuItemSpriteExtra* m_clearSearchButton`
- `LoadingCircleSprite* m_circleSprite`
- `int m_sfxID`
- `int m_libraryVersion`
- `int m_cellAmount`
- `bool m_gettingURL`
- `bool m_selectedCell`
- `bool m_snapToSelected`
- `bool m_compactMode`
- `AudioSortType m_sortType`
- `SFXBrowserDelegate* m_delegate`
- `bool m_autoUpdating`

### `SFXBrowserDelegate`

**Functions:**

- `virtual void sfxBrowserClosed(SFXBrowser* browser)`

### `SFXFolderObject` : SFXInfoObject

**Functions:**

- `SFXFolderObject()`
- `~SFXFolderObject()`
- `static SFXFolderObject* create(int id, gd::string name, int folderID)`
- `bool init(int id, gd::string name, int folderID)`

**Members:**

- `cocos2d::CCArray* m_sfxObjects`

### `SFXInfoObject` : cocos2d::CCObject

**Functions:**

- `SFXInfoObject()`
- `static SFXInfoObject* create(int id, gd::string name, int folderID, int size, int duration)`
- `gd::string getLowerCaseName()`
- `bool init(int id, gd::string name, int folderID, int size, int duration)`

**Members:**

- `int m_sfxID`
- `int m_folderID`
- `int m_size`
- `int m_duration`
- `bool m_folder`
- `bool m_unk049`
- `gd::string m_name`

### `SFXSearchResult` : MusicSearchResult

**Functions:**

- `static SFXSearchResult* create(int folderID)`
- `virtual void updateObjects(AudioSortType type)`
- `SFXFolderObject* getActiveFolder()`
- `int getSelectedPage(int id, int count)`
- `bool init(int folderID)`
- `void setActiveFolder(SFXFolderObject* folder)`

**Members:**

- `int m_folderID`
- `SFXFolderObject* m_folderObject`

### `SFXTriggerGameObject` : EffectGameObject

**Functions:**

- `SFXTriggerGameObject()`
- `static SFXTriggerGameObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `int getSFXRefID()`
- `int getUniqueSFXID()`
- `bool init(char const* frame)`

**Members:**

- `gd::string m_soundPath`
- `int m_soundID`
- `float m_pitch`
- `int m_speed`
- `int m_pitchIndex`
- `float m_volume`
- `int m_start`
- `int m_fadeIn`
- `int m_end`
- `int m_fadeOut`
- `bool m_reverb`
- `bool m_fastFourierTransform`
- `bool m_loop`
- `bool m_stopLoop`
- `bool m_dontReset`
- `bool m_unique`
- `bool m_override`
- `int m_sfxUniqueID`
- `float m_volumeNear`
- `float m_volumeMedium`
- `float m_volumeFar`
- `int m_minDistNear`
- `int m_minDistMedium`
- `int m_minDistFar`
- `int m_proximityMode`
- `bool m_cameraDistance`
- `bool m_preload`
- `bool m_ignoreVolumeTest`
- `float m_minInterval`
- `int m_sfxGroup`
- `bool m_stop`
- `bool m_changeSpeed`
- `bool m_changeVolume`
- `int m_groupID`
- `int m_unk788`
- `FMODReverbPreset m_reverbPreset`
- `bool m_reverbEnabled`
- `float m_soundDuration`
- `bool m_applyDisabled`
- `int m_speedVariance`
- `int m_pitchVariance`
- `float m_volumeVariance`
- `bool m_pitchSteps`

### `ScrollingLayer` : cocos2d::CCLayerColor

**Functions:**

- `ScrollingLayer()`
- `static ScrollingLayer* create(cocos2d::CCSize size, cocos2d::CCPoint position, float factor)`
- `virtual void draw()`
- `virtual void visit()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `cocos2d::CCRect getViewRect()`
- `bool init(cocos2d::CCSize size, cocos2d::CCPoint position, float factor)`
- `void setStartOffset(cocos2d::CCPoint offset)`

**Members:**

- `cocos2d::CCPoint m_position`
- `cocos2d::CCSize m_size`
- `cocos2d::CCPoint m_touchStartPosition`
- `cocos2d::CCPoint m_touchPosition`
- `cocos2d::CCPoint m_startOffset`
- `float m_scrollFactor`
- `int m_touchID`
- `cocos2d::CCLayer* m_contentLayer`
- `cocos2d::CCLayer* m_parentLayer`

### `SearchButton` : cocos2d::CCSprite

**Functions:**

- `static SearchButton* create(char const* background, char const* label, float scale, char const* icon)`
- `bool init(char const* background, char const* label, float scale, char const* icon)`

**Members:**

- `cocos2d::CCLabelBMFont* m_label`
- `cocos2d::CCSprite* m_icon`

### `SearchSFXPopup` : SetTextPopup

**Functions:**

- `SearchSFXPopup()`
- `static SearchSFXPopup* create(gd::string query)`
- `bool init(gd::string query)`
- `void onSearchFolders(cocos2d::CCObject* sender)`

### `SecretGame01Layer` : cocos2d::CCLayer

**Functions:**

- `static SecretGame01Layer* create()`
- `virtual void update(float dt)`
- `virtual bool init()`
- `void didSelectCorrectObject(CCMenuItemSpriteExtra* button)`
- `void gameStep01()`
- `void gameStep02()`
- `int getCountForDifficulty(int difficulty)`
- `gd::string getFrameForDifficulty(int difficulty)`
- `int getRowsForDifficulty(int difficulty)`
- `int getTimeForDifficulty(int difficulty)`
- `void onSelectButton(cocos2d::CCObject* sender)`
- `void resetGame()`
- `void resetGameTimer()`
- `void scaleOutGame(bool won)`
- `void showGameOver()`
- `void showGameWon()`

**Members:**

- `cocos2d::CCArray* m_gameObjects`
- `cocos2d::CCArray* m_requiredObjects`
- `cocos2d::CCMenu* m_mainMenu`
- `int m_selectedObject`
- `int m_gameDifficulty`
- `bool m_gameActive`
- `float m_timeElapsed`
- `float m_gameTime`
- `cocos2d::CCSprite* m_timeBarSprite`

### `SecretLayer` : cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol

**Functions:**

- `SecretLayer()`
- `~SecretLayer()`
- `static SecretLayer* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `gd::string getBasicMessage()`
- `gd::string getMessage()`
- `gd::string getThreadMessage()`
- `cocos2d::CCNode* nodeWithTag(int tag)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onSubmit(cocos2d::CCObject* sender)`
- `void playCoinEffect()`
- `void selectAThread()`
- `void updateMessageLabel(gd::string text)`
- `void updateSearchLabel(char const* text)`

**Members:**

- `int m_basicMessageIndex`
- `int m_selectedThread`
- `int m_threadMessageIndex`
- `int m_basicMessageCount`
- `int m_doomedIndex`
- `CCTextInputNode* m_searchInput`
- `cocos2d::CCLabelBMFont* m_messageLabel`
- `CCMenuItemSpriteExtra* m_submitButton`
- `cocos2d::CCDictionary* m_messageThreads`
- `int m_threadTag`

### `SecretLayer2` : cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol, DialogDelegate

**Functions:**

- `SecretLayer2()`
- `~SecretLayer2()`
- `static SecretLayer2* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void onExit()`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void dialogClosed(DialogLayer* layer)`
- `gd::string getBasicMessage()`
- `gd::string getErrorMessage()`
- `gd::string getMessage()`
- `gd::string getThreadMessage()`
- `cocos2d::CCNode* nodeWithTag(int tag)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onDoor(cocos2d::CCObject* sender)`
- `void onSecretLevel(cocos2d::CCObject* sender)`
- `void onSubmit(cocos2d::CCObject* sender)`
- `void playCoinEffect()`
- `void selectAThread()`
- `void showCompletedLevel()`
- `void showSecretLevel()`
- `void updateMessageLabel(gd::string text)`
- `void updateSearchLabel(char const* text)`

**Members:**

- `int m_threadTag`
- `int m_basicMessageIndex`
- `int m_selectedThread`
- `int m_threadMessageIndex`
- `int m_basicMessageCount`
- `int m_errorMessageIndex`
- `CCTextInputNode* m_searchInput`
- `cocos2d::CCLabelBMFont* m_messageLabel`
- `CCMenuItemSpriteExtra* m_submitButton`
- `cocos2d::CCDictionary* m_messageThreads`
- `bool m_exiting`
- `int m_doorDialogIndex`
- `CCMenuItemSpriteExtra* m_secretLevelButton`
- `cocos2d::CCArray* m_secretLevelLabels`
- `CCMenuItemSpriteExtra* m_secretDoorButton`

### `SecretLayer3` : cocos2d::CCLayer, DialogDelegate

**Functions:**

- `SecretLayer3()`
- `~SecretLayer3()`
- `static SecretLayer3* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void onExit()`
- `virtual void keyBackClicked()`
- `virtual void dialogClosed(DialogLayer* layer)`
- `void animateEyes()`
- `void firstInteractionStep1()`
- `void firstInteractionStep2()`
- `void firstInteractionStep3()`
- `void firstInteractionStep4()`
- `void onBack(cocos2d::CCObject* sender)`
- `void onChest01(cocos2d::CCObject* sender)`
- `void onChest02(cocos2d::CCObject* sender)`
- `void onClick(cocos2d::CCObject* sender)`
- `void revealStep1()`
- `void revealStep2()`
- `void revealStep3()`
- `void revealStep4()`
- `void revealStep5()`
- `void showUnlockDialog()`

**Members:**

- `DungeonBarsSprite* m_dungeonBars`
- `bool m_lockInput`
- `cocos2d::CCArray* m_locksArray`
- `cocos2d::CCSprite* m_demonEyes`
- `cocos2d::CCSprite* m_demonBody`
- `CCMenuItemSpriteExtra* m_secretChest`

### `SecretLayer4` : cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol, DialogDelegate

**Functions:**

- `SecretLayer4()`
- `~SecretLayer4()`
- `static SecretLayer4* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void onExit()`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void dialogClosed(DialogLayer* layer)`
- `gd::string getBasicMessage()`
- `gd::string getErrorMessage()`
- `gd::string getMessage()`
- `gd::string getThreadMessage()`
- `cocos2d::CCNode* nodeWithTag(int tag)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onChest01(cocos2d::CCObject* sender)`
- `void onSubmit(cocos2d::CCObject* sender)`
- `void playCoinEffect()`
- `void selectAThread()`
- `void showDialog(int index)`
- `void showFirstDialog()`
- `void updateMessageLabel(gd::string text)`
- `void updateSearchLabel(char const* text)`

**Members:**

- `int m_threadTag`
- `int m_basicMessageIndex`
- `int m_selectedThread`
- `int m_threadMessageIndex`
- `int m_basicMessageCount`
- `int m_errorMessageIndex`
- `CCTextInputNode* m_searchInput`
- `cocos2d::CCLabelBMFont* m_messageLabel`
- `CCMenuItemSpriteExtra* m_submitButton`
- `cocos2d::CCDictionary* m_messageThreads`
- `bool m_exiting`

### `SecretLayer5` : cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol, DialogDelegate, GJOnlineRewardDelegate

**Functions:**

- `SecretLayer5()`
- `~SecretLayer5()`
- `static SecretLayer5* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void onExit()`
- `virtual void updateTweenActionInt(float value, int tag)`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void dialogClosed(DialogLayer* layer)`
- `virtual void onlineRewardStatusFinished(gd::string key)`
- `virtual void onlineRewardStatusFailed()`
- `void animateHead()`
- `void claimOnlineReward()`
- `void fadeInMessage()`
- `void fadeInSubmitMessage()`
- `void fadeOutMessage()`
- `void finishLoadingState()`
- `gd::string getMessage()`
- `void handleSecretResponse()`
- `void hideTextInput()`
- `void incrementChatIdx()`
- `cocos2d::CCNode* nodeWithTag(int tag)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onSubmit(cocos2d::CCObject* sender)`
- `void playWinSFX()`
- `void showDialog(int index)`
- `void showFailAnimation()`
- `void showFirstDialog()`
- `void showSuccessAnimation()`
- `void showTextInput()`
- `void unlockUI()`
- `void updateMessageLabel(gd::string text)`
- `void updateSearchLabel(char const* text)`

**Members:**

- `int m_threadTag`
- `int m_basicMessageIndex`
- `int m_selectedThread`
- `int m_threadMessageIndex`
- `int m_basicMessageCount`
- `int m_errorMessageIndex`
- `CCTextInputNode* m_textInput`
- `cocos2d::CCLabelBMFont* m_messageLabel`
- `CCMenuItemSpriteExtra* m_wraithButton`
- `bool m_exiting`
- `void* m_unk1f0`
- `cocos2d::CCArray* m_torchFires`
- `bool m_loading`
- `int m_rewardStatus; // 0 invalid, 1 valid, 2 claimed`
- `gd::string m_chestID`
- `bool m_uiLocked`
- `CCSpriteWithHue* m_wraithSprite`
- `CCSpriteGrayscale* m_wraithGraySprite`
- `cocos2d::CCSprite* m_eyesSprite`
- `cocos2d::CCSprite* m_background`
- `cocos2d::CCSprite* m_lockSprite`
- `gd::vector<int> m_soundEffects`
- `int m_chatIndex`
- `cocos2d::extension::CCScale9Sprite* m_inputBackground`
- `LoadingCircleSprite* m_circleSprite`
- `TextArea* m_messageArea`

### `SecretLayer6` : cocos2d::CCLayer

**Functions:**

- `static SecretLayer6* create()`
- `static cocos2d::CCScene* scene()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void onBack(cocos2d::CCObject* sender)`
- `void startGame01()`

**Members:**

- `SecretGame01Layer* m_gameLayer`

### `SecretNumberLayer` : cocos2d::CCLayer

**Functions:**

- `static SecretNumberLayer* create()`
- `virtual bool init()`
- `void playNumberEffect(int secretNumber)`

### `SecretRewardsLayer` : cocos2d::CCLayer, DialogDelegate, BoomScrollLayerDelegate

**Functions:**

- `SecretRewardsLayer()`
- `~SecretRewardsLayer()`
- `static SecretRewardsLayer* create(bool fromShop)`
- `static cocos2d::CCScene* scene(bool fromShop)`
- `virtual void onExit()`
- `virtual void keyBackClicked()`
- `virtual void dialogClosed(DialogLayer* layer)`
- `virtual void scrollLayerMoved(cocos2d::CCPoint position)`
- `void createSecondaryLayer(int chestType)`
- `void fadeInMusic()`
- `void fadeInOutMusic()`
- `cocos2d::CCArray* generateChestItems(int chestType)`
- `cocos2d::ccColor3B getPageColor(int page)`
- `void goToPage(int page)`
- `bool init(bool fromShop)`
- `void moveToMainLayer(cocos2d::CCObject* sender)`
- `void moveToSecondaryLayer(int page)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onChestType(cocos2d::CCObject* sender)`
- `void onGoldChest(cocos2d::CCObject* sender)`
- `void onSelectItem(cocos2d::CCObject* sender)`
- `void onShop(cocos2d::CCObject* sender)`
- `void onSpecialItem(cocos2d::CCObject* sender)`
- `void onSwitchPage(cocos2d::CCObject* sender)`
- `void showDialog01()`
- `void showDialog03()`
- `void showDialogDiamond()`
- `void showDialogMechanic()`
- `void showLockedChest()`
- `void showShop(int shop)`
- `void switchToOpenedState(CCMenuItemSpriteExtra* button)`
- `void updateBackButton()`
- `void updateUnlockedGoldLabel()`
- `void updateUnlockedLabel()`

**Members:**

- `cocos2d::CCLayer* m_mainLayer`
- `cocos2d::CCLayer* m_secondaryLayer`
- `cocos2d::CCLabelBMFont* m_chestLabel`
- `cocos2d::CCLabelBMFont* m_chestCounter`
- `cocos2d::CCSprite* m_goldPriceSprite`
- `cocos2d::CCDictionary* m_chestCounters`
- `cocos2d::CCLabelBMFont* m_keysLabel`
- `cocos2d::CCLabelBMFont* m_goldKeysLabel`
- `cocos2d::CCSprite* m_keySprite`
- `cocos2d::CCSprite* m_goldKeySprite`
- `void* m_unknown`
- `CCMenuItemSpriteExtra* m_leftButton`
- `CCMenuItemSpriteExtra* m_rightButton`
- `cocos2d::CCSprite* m_backSprite`
- `int m_unkSize4_1`
- `int m_unkSize4_2`
- `BoomScrollLayer* m_mainScrollLayer`
- `BoomScrollLayer* m_secondaryScrollLayer`
- `cocos2d::CCSprite* m_backgroundSprite`
- `int m_scratchDialogIndex`
- `int m_potborDialogIndex`
- `int m_diamondDialogIndex`
- `int m_mechanicDialogIndex`
- `bool m_inMainLayer`
- `GJRewardType m_rewardType`
- `int m_lockedDialogIndex`

### `SelectArtDelegate`

**Functions:**

- `virtual void selectArtClosed(SelectArtLayer* layer)`

### `SelectArtLayer` : FLAlertLayer

**Functions:**

- `static SelectArtLayer* create(SelectArtType type, int index)`
- `virtual void keyBackClicked()`
- `bool init(SelectArtType type, int index)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSelectCustom(cocos2d::CCObject* sender)`
- `void selectArt(cocos2d::CCObject* sender)`
- `void updateSelectedCustom(int idx)`

**Members:**

- `cocos2d::CCArray* m_artSprites`
- `cocos2d::CCArray* m_lineSprites`
- `int m_art`
- `int m_line`
- `SelectArtType m_type`
- `SelectArtDelegate* m_delegate`

### `SelectEventLayer` : SetupTriggerPopup

**Functions:**

- `SelectEventLayer()`
- `~SelectEventLayer()`
- `static SelectEventLayer* create(SetupEventLinkPopup* popup, gd::set<int>& eventIDs)`
- `virtual void keyBackClicked()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `void addToggle(int id, gd::string info)`
- `bool init(SetupEventLinkPopup* popup, gd::set<int>& eventIDs)`
- `cocos2d::CCPoint nextPosition()`
- `void onInfo(cocos2d::CCObject* sender)`

**Members:**

- `SetupEventLinkPopup* m_eventLinkPopup`
- `bool m_eventsChanged`
- `int m_unk3b4`
- `int m_toggleCount`
- `int m_maxPage`
- `gd::map<int, gd::string> m_eventInfos`
- `gd::set<int> m_eventIDs`

### `SelectFontLayer` : FLAlertLayer

**Functions:**

- `SelectFontLayer()`
- `~SelectFontLayer()`
- `static SelectFontLayer* create(LevelEditorLayer* editorLayer)`
- `virtual void keyBackClicked()`
- `bool init(LevelEditorLayer* layer)`
- `void onChangeFont(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void updateFontLabel()`

**Members:**

- `int m_font`
- `LevelEditorLayer* m_editorLayer`
- `cocos2d::CCLabelBMFont* m_fontLabel`

### `SelectListIconDelegate`

**Functions:**

- `virtual void iconSelectClosed(SelectListIconLayer* layer)`

### `SelectListIconLayer` : FLAlertLayer

**Functions:**

- `SelectListIconLayer()`
- `~SelectListIconLayer()`
- `static SelectListIconLayer* create(int difficulty)`
- `virtual void keyBackClicked()`
- `bool init(int difficulty)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSelect(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCArray* m_difficulties`
- `int m_currentDifficulty`
- `SelectListIconDelegate* m_delegate`

### `SelectPremadeDelegate`

**Functions:**

- `virtual void selectPremadeClosed(SelectPremadeLayer* layer, int type)`

### `SelectPremadeLayer` : FLAlertLayer

**Functions:**

- `SelectPremadeLayer()`
- `static SelectPremadeLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSelectPremade(cocos2d::CCObject* sender)`

**Members:**

- `SelectPremadeDelegate* m_delegate`

### `SelectSFXSortDelegate`

**Functions:**

- `virtual void sortSelectClosed(SelectSFXSortLayer* layer)`

### `SelectSFXSortLayer` : FLAlertLayer

**Functions:**

- `SelectSFXSortLayer()`
- `static SelectSFXSortLayer* create(AudioSortType sortType)`
- `virtual void keyBackClicked()`
- `bool init(AudioSortType sortType)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSelect(cocos2d::CCObject* sender)`

**Members:**

- `AudioSortType m_sortType`
- `SelectSFXSortDelegate* m_delegate`

### `SelectSettingDelegate`

**Functions:**

- `virtual void selectSettingClosed(SelectSettingLayer* layer)`

### `SelectSettingLayer` : FLAlertLayer

**Functions:**

- `static SelectSettingLayer* create(SelectSettingType type, int value)`
- `static gd::string frameForItem(SelectSettingType type, int index)`
- `static gd::string frameForValue(SelectSettingType type, int value)`
- `static int idxToValue(SelectSettingType type, int idx)`
- `static int valueToIdx(SelectSettingType type, int value)`
- `virtual void keyBackClicked()`
- `gd::string getSelectedFrame()`
- `int getSelectedValue()`
- `bool init(SelectSettingType type, int value)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSelect(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCArray* m_settingSprites`
- `int m_settingID`
- `SelectSettingType m_type`
- `SelectSettingDelegate* m_delegate`

### `SequenceTriggerGameObject` : ChanceTriggerGameObject

**Functions:**

- `SequenceTriggerGameObject()`
- `static SequenceTriggerGameObject* create()`
- `virtual bool init()`
- `virtual void resetObject()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `void addCount(int index, int count)`
- `void addTarget(int groupID, int count)`
- `void deleteTarget(int index)`
- `bool reorderTarget(int index, bool left)`
- `void updateSequenceTotalCount()`

**Members:**

- `SequenceTriggerState m_sequenceState`
- `float m_minInt`
- `int m_sequenceMode`
- `int m_resetMode`
- `float m_reset`
- `int m_sequenceTotalCount`
- `bool m_uniqueRemap`

### `SetColorIDPopup` : SetIDPopup, GJSpecialColorSelectDelegate

**Functions:**

- `SetColorIDPopup()`
- `static SetColorIDPopup* create(int id)`
- `virtual void colorSelectClosed(GJSpecialColorSelect* select, int id)`
- `bool init(int id)`
- `void onSelectSpecialColor(cocos2d::CCObject* sender)`

### `SetFolderPopup` : SetIDPopup, SetTextPopupDelegate

**Functions:**

- `static SetFolderPopup* create(int value, bool isCreated, gd::string title)`
- `virtual void valueChanged()`
- `virtual void setTextPopupClosed(SetTextPopup* popup, gd::string text)`
- `bool init(int value, bool isCreated, gd::string title)`
- `void onSetFolderName(cocos2d::CCObject* sender)`

**Members:**

- `bool m_isCreated`
- `cocos2d::CCLabelBMFont* m_titleLabel`

### `SetGroupIDLayer` : FLAlertLayer, TextInputDelegate, ConfigureValuePopupDelegate

**Functions:**

- `SetGroupIDLayer()`
- `~SetGroupIDLayer()`
- `static SetGroupIDLayer* create(GameObject* object, cocos2d::CCArray* objects)`
- `virtual void keyBackClicked()`
- `virtual void valuePopupClosed(ConfigureValuePopup* popup, float value)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void addGroupID(int id)`
- `void callRemoveFromGroup(float dt)`
- `CCTextInputNode* createTextInput(cocos2d::CCPoint position, int tag, int length, gd::string placeholder, float width, int arrow)`
- `void determineStartValues()`
- `bool init(GameObject* obj, cocos2d::CCArray* objs)`
- `void onAddGroup(cocos2d::CCObject* sender)`
- `void onAddGroupParent(cocos2d::CCObject* sender)`
- `void onAnim(cocos2d::CCObject* sender)`
- `void onArrow(int tag, int increment)`
- `void onArrowLeft(cocos2d::CCObject* sender)`
- `void onArrowRight(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCopy(cocos2d::CCObject* sender)`
- `void onExtra(cocos2d::CCObject* sender)`
- `void onExtra2(cocos2d::CCObject* sender)`
- `void onGroupIDOptions(cocos2d::CCObject* sender)`
- `void onNextFreeEditorLayer1(cocos2d::CCObject* sender)`
- `void onNextFreeEditorLayer2(cocos2d::CCObject* sender)`
- `void onNextFreeOrderChannel(cocos2d::CCObject* sender)`
- `void onNextGroupID1(cocos2d::CCObject* sender)`
- `void onPaste(cocos2d::CCObject* sender)`
- `void onRemoveFromGroup(cocos2d::CCObject* sender)`
- `void onSmoothEase(cocos2d::CCObject* sender)`
- `void onToggleGuide(cocos2d::CCObject* sender)`
- `void onToggleSelectedOrder(cocos2d::CCObject* sender)`
- `void onToggleTraceIn(cocos2d::CCObject* sender)`
- `void onToggleTraceOut(cocos2d::CCObject* sender)`
- `void onZLayer(cocos2d::CCObject* sender)`
- `void onZLayerShift(cocos2d::CCObject* sender)`
- `void removeGroupID(int id)`
- `void updateEditorLabel()`
- `void updateEditorLabel2()`
- `void updateEditorLayerID()`
- `void updateEditorLayerID2()`
- `void updateEditorOrder()`
- `void updateEditorOrderLabel()`
- `void updateGroupIDButtons()`
- `void updateGroupIDLabel()`
- `void updateOrderChannel()`
- `void updateOrderChannelLabel()`
- `void updateZLayerButtons()`
- `void updateZOrder()`
- `void updateZOrderLabel()`

**Members:**

- `GameObject* m_targetObject`
- `cocos2d::CCArray* m_targetObjects`
- `cocos2d::CCArray* m_zLayerButtons`
- `cocos2d::CCArray* m_groupIDObjects`
- `CCTextInputNode* m_editorLayerInput`
- `CCTextInputNode* m_editorLayer2Input`
- `CCTextInputNode* m_zOrderInput`
- `CCTextInputNode* m_groupIDInput`
- `CCTextInputNode* m_orderInput`
- `CCTextInputNode* m_channelInput`
- `bool m_showChannelOrder`
- `int m_channelValue`
- `bool m_channelUpdated`
- `int m_groupIDValue`
- `int m_editorLayerValue`
- `int m_editorLayer2Value`
- `int m_zOrderValue`
- `ZLayer m_zLayerValue`
- `int m_orderValue`
- `bool m_channelOrderEdited`
- `bool m_editorLayerEdited`
- `bool m_removeGroupsLock`
- `int m_groupToRemove`
- `bool m_addedGroup`
- `bool m_reverseChanged`
- `bool m_hasTargetObjects`
- `bool m_unk2ff`
- `bool m_unk300`
- `int m_nextFreeID`
- `cocos2d::CCDictionary* m_parentGroups`

### `SetIDPopup` : FLAlertLayer, TextInputDelegate

**Functions:**

- `SetIDPopup()`
- `~SetIDPopup()`
- `static SetIDPopup* create(int current, int begin, int end, gd::string title, gd::string button, bool resetButton, int defaultValue, float offset, bool numberInput, bool arrows)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void valueChanged()`
- `bool init(int current, int begin, int end, gd::string title, gd::string button, bool resetButton, int defaultValue, float offset, bool numberInput, bool arrows)`
- `void onCancel(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onItemIDArrow(cocos2d::CCObject* sender)`
- `void onResetValue(cocos2d::CCObject* sender)`
- `void updateTextInputLabel()`

**Members:**

- `CCTextInputNode* m_inputNode`
- `int m_value`
- `bool m_disableDelegate`
- `bool m_cancelled`
- `int m_minimum`
- `int m_maximum`
- `int m_default`
- `SetIDPopupDelegate* m_delegate`

### `SetIDPopupDelegate`

**Functions:**

- `virtual void setIDPopupClosed(SetIDPopup* popup, int value)`

### `SetItemIDLayer` : SetupTriggerPopup

**Functions:**

- `SetItemIDLayer()`
- `static SetItemIDLayer* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void updateEditorLabel()`

### `SetLevelOrderPopup` : SetIDPopup

**Functions:**

- `SetLevelOrderPopup()`
- `static SetLevelOrderPopup* create(int levelID, int order, int amount)`
- `bool init(int levelID, int order, int amount)`
- `void onOrderButton(cocos2d::CCObject* sender)`

**Members:**

- `int m_levelID`

### `SetTargetIDLayer` : SetupTriggerPopup

**Functions:**

- `static SetTargetIDLayer* create(EffectGameObject* object, cocos2d::CCArray* objects, gd::string title, gd::string label, int minimum, int maximum, int objectID)`
- `virtual void determineStartValues()`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects, gd::string title, gd::string label, int minimum, int maximum, int objectID)`

**Members:**

- `int m_objectID`
- `int m_minimumID`
- `int m_maximumID`

### `SetTextPopup` : FLAlertLayer, TextInputDelegate

**Functions:**

- `SetTextPopup()`
- `~SetTextPopup()`
- `static SetTextPopup* create(gd::string value, gd::string placeholder, int maxLength, gd::string title, gd::string okBtnText, bool showResetBtn, float offset)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(gd::string value, gd::string placeholder, int maxLength, gd::string title, gd::string okBtnText, bool showResetBtn, float offset)`
- `void onCancel(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onResetValue(cocos2d::CCObject* sender)`
- `void updateTextInputLabel()`

**Members:**

- `CCTextInputNode* m_input`
- `bool m_disableDelegate`
- `bool m_cancelled`
- `gd::string m_value`
- `SetTextPopupDelegate* m_delegate`

### `SetTextPopupDelegate`

**Functions:**

- `virtual void setTextPopupClosed(SetTextPopup* popup, gd::string text)`

### `SetupAdvFollowEditPhysicsPopup` : SetupTriggerPopup

**Functions:**

- `static SetupAdvFollowEditPhysicsPopup* create(AdvancedFollowEditObject* object, cocos2d::CCArray* objects)`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects)`

### `SetupAdvFollowPopup` : SetupTriggerPopup, SelectPremadeDelegate

**Functions:**

- `static SetupAdvFollowPopup* create(AdvancedFollowTriggerObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void updateDefaultTriggerValues()`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `virtual void selectPremadeClosed(SelectPremadeLayer* layer, int type)`
- `bool init(AdvancedFollowTriggerObject* object, cocos2d::CCArray* objects)`
- `void onMode(cocos2d::CCObject* sender)`
- `void onPremade(cocos2d::CCObject* sender)`
- `void updateMode(int mode)`

### `SetupAdvFollowRetargetPopup` : SetupTriggerPopup

**Functions:**

- `static SetupAdvFollowRetargetPopup* create(AdvancedFollowEditObject* object, cocos2d::CCArray* objects)`
- `virtual void updateDefaultTriggerValues()`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects)`

### `SetupAnimSettingsPopup` : SetupTriggerPopup

**Functions:**

- `static SetupAnimSettingsPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void updateAnimSettings()`

### `SetupAnimationPopup` : SetupTriggerPopup

**Functions:**

- `static SetupAnimationPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onAnimationIDArrow(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void updateAnimationID()`
- `void updateAnimationTextInputLabel()`
- `void updateTargetID()`
- `void updateTextInputLabel()`

**Members:**

- `CCTextInputNode* m_targetIDInput`
- `CCTextInputNode* m_animationIDInput`
- `int m_targetID`
- `int m_animationID`

### `SetupAreaAnimTriggerPopup` : SetupAreaTintTriggerPopup

**Functions:**

- `SetupAreaAnimTriggerPopup()`
- `static SetupAreaAnimTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects, int id)`
- `virtual void updateDefaultTriggerValues()`
- `virtual void valueDidChange(int tag, float value)`
- `void createValueControlAdvancedAnim(int property, gd::string label, cocos2d::CCPoint position, float scale, bool noSlider, InputValueType valueType, int length, bool arrows, float min, float max, int page, int group, GJInputStyle inputStyle)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id)`
- `void onDeactivateAnimValue(cocos2d::CCObject* sender)`
- `void updateTargetIDLabel()`

### `SetupAreaFadeTriggerPopup` : SetupAreaMoveTriggerPopup

**Functions:**

- `SetupAreaFadeTriggerPopup()`
- `static SetupAreaFadeTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects)`

### `SetupAreaMoveTriggerPopup` : SetupTriggerPopup

**Functions:**

- `SetupAreaMoveTriggerPopup()`
- `~SetupAreaMoveTriggerPopup()`
- `static SetupAreaMoveTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `virtual void updateInputValue(int tag, float& value)`
- `virtual void updateDefaultTriggerValues()`
- `virtual void updateInputNode(int tag, float value)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float triggerValueFromSliderValue(int tag, float value)`
- `virtual float triggerSliderValueFromValue(int tag, float value)`
- `void addAreaDefaultControls(int objectID)`
- `void getModeValues(int mode, int& direction, bool& inbound, bool& twoDirections)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `void onMode(cocos2d::CCObject* sender)`
- `void onNextFreeEffectID(cocos2d::CCObject* sender)`
- `void onSpecialTarget(cocos2d::CCObject* sender)`
- `void updateEnterTargetIDState()`

**Members:**

- `cocos2d::CCArray* m_modeButtons`
- `cocos2d::CCArray* m_targetButtons`

### `SetupAreaRotateTriggerPopup` : SetupAreaMoveTriggerPopup

**Functions:**

- `SetupAreaRotateTriggerPopup()`
- `static SetupAreaRotateTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects)`

### `SetupAreaTintTriggerPopup` : SetupAreaMoveTriggerPopup, HSVWidgetDelegate

**Functions:**

- `SetupAreaTintTriggerPopup()`
- `static SetupAreaTintTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void hsvPopupClosed(HSVWidgetPopup* popup, cocos2d::ccHSVValue value)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `void onHSV(cocos2d::CCObject* sender)`
- `void updateHSVButton()`

**Members:**

- `CCMenuItemSpriteExtra* m_hsvButton`
- `cocos2d::ccHSVValue m_hsvValue`
- `bool m_hsvChanged`

### `SetupAreaTransformTriggerPopup` : SetupAreaMoveTriggerPopup

**Functions:**

- `SetupAreaTransformTriggerPopup()`
- `static SetupAreaTransformTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects)`

### `SetupAreaTriggerPopup` : SetupAreaMoveTriggerPopup

**Functions:**

- `SetupAreaTriggerPopup()`
- `static SetupAreaTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects)`

### `SetupArtSwitchPopup` : SetupTriggerPopup, SelectArtDelegate

**Functions:**

- `static SetupArtSwitchPopup* create(ArtTriggerGameObject* object, cocos2d::CCArray* objects, int id)`
- `virtual void selectArtClosed(SelectArtLayer* layer)`
- `bool init(ArtTriggerGameObject* object, cocos2d::CCArray* objects, int id)`
- `void onArt(cocos2d::CCObject* sender)`

**Members:**

- `SelectArtType m_artType`
- `cocos2d::CCSprite* m_artSprite`

### `SetupAudioLineGuidePopup` : SetupTriggerPopup, SelectSettingDelegate

**Functions:**

- `SetupAudioLineGuidePopup()`
- `static SetupAudioLineGuidePopup* create(AudioLineGuideGameObject* object, cocos2d::CCArray* objects)`
- `virtual void selectSettingClosed(SelectSettingLayer* layer)`
- `bool init(AudioLineGuideGameObject* object, cocos2d::CCArray* objects)`
- `void onSpeed(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCSprite* m_speedSprite`

### `SetupAudioTriggerPopup` : SetupTriggerPopup

**Functions:**

- `virtual void valueDidChange(int tag, float value)`
- `void addProxVolControls(int page)`
- `void addTimeControls(int page, float yOffset)`
- `void onProxMode(cocos2d::CCObject* sender)`
- `void updateSpecialGroup()`

**Members:**

- `cocos2d::CCArray* m_proximityButtons`

### `SetupBGSpeedTrigger` : SetupTriggerPopup

**Functions:**

- `static SetupBGSpeedTrigger* create(EffectGameObject* object, cocos2d::CCArray* objects, int id)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects, int id)`

### `SetupCameraEdgePopup` : SetupTriggerPopup

**Functions:**

- `static SetupCameraEdgePopup* create(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onCameraEdge(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void onUnlockEdge(cocos2d::CCObject* sender)`
- `void updateTargetID()`
- `void updateTextInputLabel()`

**Members:**

- `CCTextInputNode* m_targetIDInput`
- `int m_targetID`
- `int m_edgeDirection`
- `cocos2d::CCArray* m_directionToggles`

### `SetupCameraGuidePopup` : SetupTriggerPopup

**Functions:**

- `static SetupCameraGuidePopup* create(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`
- `bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`

### `SetupCameraModePopup` : SetupTriggerPopup

**Functions:**

- `static SetupCameraModePopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onEditCameraSettings(cocos2d::CCObject* sender)`
- `void onUnboundMode(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateCameraEasing()`
- `void updateCameraEasingLabel()`
- `void updateCameraPadding()`
- `void updateCameraPaddingLabel()`
- `void updateItemVisibility()`

**Members:**

- `cocos2d::CCArray* m_freeModeObjects`
- `cocos2d::CCArray* m_cameraSettingsObjects`
- `Slider* m_cameraEasingSlider`
- `cocos2d::CCLabelBMFont* m_cameraEasingLabel`
- `int m_cameraEasing`
- `Slider* m_cameraPaddingSlider`
- `cocos2d::CCLabelBMFont* m_cameraPaddingLabel`
- `float m_cameraPadding`
- `bool m_freeMode`
- `bool m_cameraSettingsEnabled`
- `bool m_cameraModeObjects`

### `SetupCameraOffsetTrigger` : SetupTriggerPopup

**Functions:**

- `static SetupCameraOffsetTrigger* create(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void valuePopupClosed(ConfigureValuePopup* popup, float value)`
- `bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onEasing(cocos2d::CCObject* sender)`
- `void onEasingRate(cocos2d::CCObject* sender)`
- `void onTargetMode(cocos2d::CCObject* sender)`
- `int posFromSliderValue(float value)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `float sliderValueFromPos(int pos)`
- `void sliderXChanged(cocos2d::CCObject* sender)`
- `void sliderYChanged(cocos2d::CCObject* sender)`
- `void toggleEasingRateVisibility()`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateEasingLabel()`
- `void updateEasingRateLabel()`
- `void updateMoveCommandEasing()`
- `void updateMoveCommandEasingRate()`
- `void updateMoveCommandPosX()`
- `void updateMoveCommandPosY()`
- `void updateValueXLabel()`
- `void updateValueYLabel()`

**Members:**

- `CCTextInputNode* m_moveTimeInput`
- `Slider* m_moveTimeSlider`
- `float m_moveTime`
- `cocos2d::CCLabelBMFont* m_cameraEasingLabel`
- `EasingType m_cameraEasingType`
- `float m_cameraEasingRate`
- `CCMenuItemSpriteExtra* m_cameraEasingRateButton`
- `cocos2d::CCLabelBMFont* m_cameraEasingRateLabel`
- `CCTextInputNode* m_offsetXInput`
- `CCTextInputNode* m_offsetYInput`
- `Slider* m_offsetXSlider`
- `Slider* m_offsetYSlider`
- `int m_offsetX`
- `int m_offsetY`
- `int m_targetMode`
- `CCMenuItemToggler* m_xOnlyToggler`
- `CCMenuItemToggler* m_yOnlyToggler`

### `SetupCameraRotatePopup` : SetupTriggerPopup

**Functions:**

- `static SetupCameraRotatePopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void valuePopupClosed(ConfigureValuePopup* popup, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onEasing(cocos2d::CCObject* sender)`
- `void onEasingRate(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void sliderDegreesChanged(cocos2d::CCObject* sender)`
- `void toggleEasingRateVisibility()`
- `void updateCommandDegrees()`
- `void updateDegreesLabel()`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateEasingLabel()`
- `void updateEasingRateLabel()`
- `void updateMoveCommandEasing()`
- `void updateMoveCommandEasingRate()`

**Members:**

- `CCTextInputNode* m_moveTimeInput`
- `Slider* m_moveTimeSlider`
- `float m_moveTime`
- `cocos2d::CCLabelBMFont* m_cameraEasingLabel`
- `EasingType m_cameraEasingType`
- `float m_cameraEasingRate`
- `CCMenuItemSpriteExtra* m_cameraEasingRateButton`
- `cocos2d::CCLabelBMFont* m_cameraEasingRateLabel`
- `CCTextInputNode* m_degreesInput`
- `Slider* m_degreesSlider`
- `float m_degrees`

### `SetupCameraRotatePopup2` : SetupTriggerPopup

**Functions:**

- `static SetupCameraRotatePopup2* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupCheckpointPopup` : SetupTriggerPopup

**Functions:**

- `SetupCheckpointPopup()`
- `static SetupCheckpointPopup* create(CheckpointGameObject* object, cocos2d::CCArray* objects)`
- `bool init(CheckpointGameObject* object, cocos2d::CCArray* objects)`

### `SetupCoinLayer` : SetupTriggerPopup

**Functions:**

- `SetupCoinLayer()`
- `static SetupCoinLayer* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupCollisionStateTriggerPopup` : SetupInstantCollisionTriggerPopup

**Functions:**

- `SetupCollisionStateTriggerPopup()`
- `static SetupCollisionStateTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupCollisionTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupCollisionTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onActivateOnExit(cocos2d::CCObject* sender)`
- `void onEnableGroup(cocos2d::CCObject* sender)`
- `void onItemID2Arrow(cocos2d::CCObject* sender)`
- `void onItemIDArrow(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void onTargetP1(cocos2d::CCObject* sender)`
- `void onTargetP2(cocos2d::CCObject* sender)`
- `void onTargetPP(cocos2d::CCObject* sender)`
- `void updateItemID()`
- `void updateItemID2()`
- `void updateItemID2InputLabel()`
- `void updateItemIDInputLabel()`
- `void updateTargetID()`
- `void updateTargetIDInputLabel()`

**Members:**

- `CCTextInputNode* m_blockAInput`
- `CCTextInputNode* m_blockBInput`
- `CCTextInputNode* m_targetIDInput`
- `int m_blockAID`
- `int m_blockBID`
- `int m_targetID`
- `bool m_activateGroup`
- `bool m_triggerOnExit`
- `bool m_targetP1`
- `bool m_targetP2`
- `bool m_targetPP`

### `SetupCountTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupCountTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onEnableGroup(cocos2d::CCObject* sender)`
- `void onItemIDArrow(cocos2d::CCObject* sender)`
- `void onMultiActivate(cocos2d::CCObject* sender)`
- `void onTargetCountArrow(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void updateCountTextInputLabel()`
- `void updateItemID()`
- `void updateItemIDInputLabel()`
- `void updateTargetCount()`
- `void updateTargetID()`
- `void updateTargetIDInputLabel()`

**Members:**

- `CCTextInputNode* m_itemIDInput`
- `CCTextInputNode* m_targetIDInput`
- `CCTextInputNode* m_targetCountInput`
- `int m_itemID`
- `int m_targetID`
- `int m_targetCount`
- `bool m_activateGroup`
- `bool m_multiActivate`

### `SetupDashRingPopup` : SetupTriggerPopup

**Functions:**

- `SetupDashRingPopup()`
- `static SetupDashRingPopup* create(DashRingObject* object, cocos2d::CCArray* objects)`
- `bool init(DashRingObject* object, cocos2d::CCArray* objects)`

### `SetupEndPopup` : SetupTriggerPopup

**Functions:**

- `static SetupEndPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onLockY(cocos2d::CCObject* sender)`
- `void onMultiActivate(cocos2d::CCObject* sender)`
- `void onReversed(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void updateTargetID()`
- `void updateTextInputLabel()`

**Members:**

- `CCTextInputNode* m_groupIDInput`
- `bool m_reversed`
- `bool m_lockY`
- `int m_groupID`
- `bool m_multiActivate`

### `SetupEnterEffectPopup` : SetupTriggerPopup, HSVWidgetDelegate

**Functions:**

- `SetupEnterEffectPopup()`
- `static SetupEnterEffectPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects, int id)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void updateInputValue(int tag, float& value)`
- `virtual void updateInputNode(int tag, float value)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float triggerValueFromSliderValue(int tag, float value)`
- `virtual float triggerSliderValueFromValue(int tag, float value)`
- `virtual void hsvPopupClosed(HSVWidgetPopup* popup, cocos2d::ccHSVValue value)`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id)`
- `void onEnterType(cocos2d::CCObject* sender)`
- `void onHSV(cocos2d::CCObject* sender)`
- `void onNextFreeEnterChannel(cocos2d::CCObject* sender)`
- `void onNextFreeEnterEffectID(cocos2d::CCObject* sender)`
- `void updateHSVButton()`

**Members:**

- `int m_objectID`
- `CCMenuItemToggler* m_enterOnlyToggler`
- `CCMenuItemToggler* m_exitOnlyToggler`
- `int m_enterType`
- `CCMenuItemSpriteExtra* m_hsvButton`
- `cocos2d::ccHSVValue m_hsvValue`
- `bool m_hsvChanged`

### `SetupEnterTriggerPopup` : SetupTriggerPopup

**Functions:**

- `SetupEnterTriggerPopup()`
- `static SetupEnterTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `bool init(EnterEffectObject* object, cocos2d::CCArray* objects)`
- `void onEnterType(cocos2d::CCObject* sender)`

**Members:**

- `CCMenuItemToggler* m_enterOnlyToggler`
- `CCMenuItemToggler* m_exitOnlyToggler`
- `int m_enterType`

### `SetupEventLinkPopup` : SetupTriggerPopup

**Functions:**

- `static SetupEventLinkPopup* create(EventLinkTrigger* object, cocos2d::CCArray* objects)`
- `bool init(EventLinkTrigger* object, cocos2d::CCArray* objects)`
- `void onSelectEvent(cocos2d::CCObject* sender)`
- `void updateEventIDs(gd::set<int>& eventIDs)`

### `SetupForceBlockPopup` : SetupTriggerPopup

**Functions:**

- `static SetupForceBlockPopup* create(ForceBlockGameObject* object, cocos2d::CCArray* objects)`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(ForceBlockGameObject* object, cocos2d::CCArray* objects)`

### `SetupGameplayOffsetPopup` : SetupTriggerPopup

**Functions:**

- `SetupGameplayOffsetPopup()`
- `static SetupGameplayOffsetPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void updateInputValue(int tag, float& value)`
- `virtual void updateInputNode(int tag, float value)`
- `virtual float triggerValueFromSliderValue(int tag, float value)`
- `virtual float triggerSliderValueFromValue(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onDefaultValues(cocos2d::CCObject* sender)`

### `SetupGradientPopup` : SetupTriggerPopup

**Functions:**

- `SetupGradientPopup()`
- `~SetupGradientPopup()`
- `static SetupGradientPopup* create(GradientTriggerObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onPlusButton(cocos2d::CCObject* sender)`
- `virtual void updateToggleItem(int value, bool toggled)`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(GradientTriggerObject* object, cocos2d::CCArray* objects)`
- `void onBlending(cocos2d::CCObject* sender)`
- `void onZLayer(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateBlending()`
- `void updateBlendingLabel()`
- `void updateGradientLabels(bool vertex)`
- `void updateZLayerButtons()`

**Members:**

- `cocos2d::CCLabelBMFont* m_blendingLabel`
- `int m_blendingMode`
- `cocos2d::CCArray* m_layerButtons`
- `int m_blendingLayer`
- `cocos2d::CCArray* m_gradientLabels`

### `SetupGravityModPopup` : FLAlertLayer, TextInputDelegate

**Functions:**

- `static SetupGravityModPopup* create(EffectGameObject* object, cocos2d::CCArray* objects, bool gravityTrigger)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void determineStartValues()`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool gravityTrigger)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onItemIDArrow(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateItemID()`
- `void updateTextInputLabel()`
- `void updateValue()`
- `void updateValueLabel()`

**Members:**

- `EffectGameObject* m_gameObject`
- `cocos2d::CCArray* m_gameObjects`
- `cocos2d::CCLabelBMFont* m_gravityModLabel`
- `Slider* m_gravityModSlider`
- `float m_gravityMod`
- `bool m_gravityTrigger`
- `float m_minValue`
- `float m_maxValue`
- `CCTextInputNode* m_itemIDInput`
- `int m_itemID`
- `bool m_disableDelegate`

### `SetupGravityTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupGravityTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupInstantCollisionTriggerPopup` : SetupTriggerPopup

**Functions:**

- `SetupInstantCollisionTriggerPopup()`
- `static SetupInstantCollisionTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void updateDefaultTriggerValues()`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void updateSpecialNodes()`

### `SetupInstantCountPopup` : SetupTriggerPopup

**Functions:**

- `static SetupInstantCountPopup* create(CountTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(CountTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onCountType(cocos2d::CCObject* sender)`
- `void onEnableGroup(cocos2d::CCObject* sender)`
- `void onTargetCountArrow(cocos2d::CCObject* sender)`
- `void onTargetID2Arrow(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void updateCountTextInputLabel()`
- `void updateItemID()`
- `void updateItemIDInputLabel()`
- `void updateTargetCount()`
- `void updateTargetID()`
- `void updateTargetIDInputLabel()`

**Members:**

- `CCTextInputNode* m_itemIDInput`
- `CCTextInputNode* m_targetIDInput`
- `CCTextInputNode* m_targetCountInput`
- `int m_itemID`
- `int m_targetID`
- `int m_targetCount`
- `bool m_activateGroup`
- `int m_mode`
- `CCMenuItemToggler* m_equalsToggler`
- `CCMenuItemToggler* m_largerToggler`
- `CCMenuItemToggler* m_smallerToggler`

### `SetupInteractObjectPopup` : SetupTriggerPopup

**Functions:**

- `static SetupInteractObjectPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onPlusButton(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void updateItems()`

### `SetupItemCompareTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupItemCompareTriggerPopup* create(ItemTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onOpButton(cocos2d::CCObject* sender)`
- `void updateFormulaLabel()`
- `void updateOpButton(CCMenuItemSpriteExtra* button, int key, int objectID)`

**Members:**

- `cocos2d::CCLabelBMFont* m_formulaLabel`

### `SetupItemEditTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupItemEditTriggerPopup* create(ItemTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onOpButton(cocos2d::CCObject* sender)`
- `void updateFormulaLabel()`
- `void updateOpButton(CCMenuItemSpriteExtra* button, int key, int objectID)`

**Members:**

- `cocos2d::CCLabelBMFont* m_formulaLabel`

### `SetupKeyframeAnimPopup` : SetupTriggerPopup

**Functions:**

- `static SetupKeyframeAnimPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupKeyframePopup` : SetupTriggerPopup

**Functions:**

- `static SetupKeyframePopup* create(KeyframeGameObject* object, cocos2d::CCArray* objects, LevelEditorLayer* layer)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onCustomButton(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(KeyframeGameObject* object, cocos2d::CCArray* objects, LevelEditorLayer* layer)`
- `void onTimeMode(cocos2d::CCObject* sender)`
- `void refreshPreviewArt()`
- `void updateTimeModeButtons()`

**Members:**

- `cocos2d::CCArray* m_timeModeToggles`
- `LevelEditorLayer* m_editorLayer`
- `bool m_groupIDChanged`

### `SetupMGTrigger` : SetupTriggerPopup

**Functions:**

- `static SetupMGTrigger* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void valuePopupClosed(ConfigureValuePopup* popup, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onEasing(cocos2d::CCObject* sender)`
- `void onEasingRate(cocos2d::CCObject* sender)`
- `int posFromSliderValue(float value)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `float sliderValueFromPos(int pos)`
- `void sliderYChanged(cocos2d::CCObject* sender)`
- `void toggleEasingRateVisibility()`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateEasingLabel()`
- `void updateEasingRateLabel()`
- `void updateMoveCommandEasing()`
- `void updateMoveCommandEasingRate()`
- `void updateMoveCommandPosY()`
- `void updateValueYLabel()`

**Members:**

- `CCTextInputNode* m_moveTimeInput`
- `Slider* m_moveTimeSlider`
- `float m_moveTime`
- `cocos2d::CCLabelBMFont* m_mgEasingLabel`
- `EasingType m_mgEasingType`
- `float m_mgEasingRate`
- `CCMenuItemSpriteExtra* m_mgEasingRateButton`
- `cocos2d::CCLabelBMFont* m_mgEasingRateLabel`
- `CCTextInputNode* m_offsetYInput`
- `Slider* m_offsetYSlider`
- `int m_offsetY`

### `SetupMoveCommandPopup` : SetupTriggerPopup

**Functions:**

- `static SetupMoveCommandPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void updateInputValue(int tag, float& value)`
- `virtual void updateInputNode(int tag, float value)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float triggerValueFromSliderValue(int tag, float value)`
- `virtual float triggerSliderValueFromValue(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void updateControlVisibility()`

**Members:**

- `bool m_smallStep`

### `SetupObjectControlPopup` : SetupTriggerPopup

**Functions:**

- `static SetupObjectControlPopup* create(ObjectControlGameObject* object, cocos2d::CCArray* objects)`
- `bool init(ObjectControlGameObject* object, cocos2d::CCArray* objects)`

### `SetupObjectOptions2Popup` : SetupTriggerPopup

**Functions:**

- `SetupObjectOptions2Popup()`
- `static SetupObjectOptions2Popup* create(GameObject* object, cocos2d::CCArray* objects)`
- `virtual void onPlusButton(cocos2d::CCObject* sender)`
- `bool init(GameObject* object, cocos2d::CCArray* objects)`

### `SetupObjectOptionsPopup` : FLAlertLayer, TextInputDelegate

**Functions:**

- `SetupObjectOptionsPopup()`
- `~SetupObjectOptionsPopup()`
- `static SetupObjectOptionsPopup* create(GameObject* object, cocos2d::CCArray* objects, SetGroupIDLayer* layer)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `bool init(GameObject* object, cocos2d::CCArray* objects, SetGroupIDLayer* layer)`
- `void onAlwaysHide(cocos2d::CCObject* sender)`
- `void onApplyScaleStick(cocos2d::CCObject* sender)`
- `void onCenterEffect(cocos2d::CCObject* sender)`
- `void onDisableGlow(cocos2d::CCObject* sender)`
- `void onDisableObject(cocos2d::CCObject* sender)`
- `void onDontBoost(cocos2d::CCObject* sender)`
- `void onDontBoostX(cocos2d::CCObject* sender)`
- `void onDontEnter(cocos2d::CCObject* sender)`
- `void onDontFade(cocos2d::CCObject* sender)`
- `void onExtendedCollision(cocos2d::CCObject* sender)`
- `void onExtraSticky(cocos2d::CCObject* sender)`
- `void onGripSlope(cocos2d::CCObject* sender)`
- `void onHideEffects(cocos2d::CCObject* sender)`
- `void onHighDetail(cocos2d::CCObject* sender)`
- `void onIceBlock(cocos2d::CCObject* sender)`
- `void onNoAudioScale(cocos2d::CCObject* sender)`
- `void onNonStickX(cocos2d::CCObject* sender)`
- `void onNonStickY(cocos2d::CCObject* sender)`
- `void onNoParticle(cocos2d::CCObject* sender)`
- `void onPassable(cocos2d::CCObject* sender)`
- `void onReverse(cocos2d::CCObject* sender)`
- `void onSinglePlayerTouch(cocos2d::CCObject* sender)`
- `void onToggleAreaParent(cocos2d::CCObject* sender)`
- `void onToggleGroupParent(cocos2d::CCObject* sender)`

**Members:**

- `GameObject* m_gameObject`
- `cocos2d::CCArray* m_gameObjects`
- `bool m_iceBlock`
- `bool m_dontFade`
- `bool m_dontEnter`
- `bool m_noEffects`
- `bool m_noParticle`
- `bool m_noTouch`
- `bool m_passable`
- `bool m_hide`
- `bool m_nonStickX`
- `bool m_nonStickY`
- `bool m_extraSticky`
- `bool m_dontBoostY`
- `bool m_dontBoostX`
- `bool m_noAudioScale`
- `bool m_scaleStick`
- `bool m_highDetail`
- `bool m_groupParent`
- `bool m_areaParent`
- `bool m_gripSlope`
- `bool m_noGlow`
- `bool m_reverse`
- `bool m_extendedCollision`
- `bool m_unk2a6`
- `SetGroupIDLayer* m_groupIDLayer`
- `bool m_effectObject`
- `bool m_singlePlayerTouch`
- `bool m_centerEffect`

### `SetupObjectTogglePopup` : SetupTriggerPopup

**Functions:**

- `static SetupObjectTogglePopup* create(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer)`

### `SetupOpacityPopup` : SetupTriggerPopup

**Functions:**

- `static SetupOpacityPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateOpacity()`
- `void updateOpacityLabel()`
- `void updateTargetID()`
- `void updateTextInputLabel()`

**Members:**

- `CCTextInputNode* m_groupIDInput`
- `CCTextInputNode* m_fadeTimeInput`
- `cocos2d::CCLabelBMFont* m_opacityLabel`
- `Slider* m_fadeTimeSlider`
- `Slider* m_opacitySlider`
- `float m_opacity`
- `float m_fadeTime`
- `int m_groupID`

### `SetupOptionsTriggerPopup` : SetupTriggerPopup

**Functions:**

- `SetupOptionsTriggerPopup()`
- `static SetupOptionsTriggerPopup* create(GameOptionsTrigger* object, cocos2d::CCArray* objects)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `void addOption(int property, gd::string label)`
- `bool init(GameOptionsTrigger* object, cocos2d::CCArray* objects)`

**Members:**

- `cocos2d::CCPoint m_togglePosition`
- `int m_togglePage`

### `SetupPersistentItemTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupPersistentItemTriggerPopup* create(ItemTriggerGameObject* object, cocos2d::CCArray* objects)`
- `bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects)`

### `SetupPickupTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupPickupTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onPlusButton(cocos2d::CCObject* sender)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void updateState()`

### `SetupPlatformerEndPopup` : SetupTriggerPopup

**Functions:**

- `static SetupPlatformerEndPopup* create(EndTriggerGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EndTriggerGameObject* object, cocos2d::CCArray* objects)`

### `SetupPlayerControlPopup` : SetupTriggerPopup

**Functions:**

- `static SetupPlayerControlPopup* create(PlayerControlGameObject* object, cocos2d::CCArray* objects)`
- `bool init(PlayerControlGameObject* object, cocos2d::CCArray* objects)`

### `SetupPortalPopup` : FLAlertLayer, TextInputDelegate

**Functions:**

- `static SetupPortalPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void keyBackClicked()`
- `void determineStartValues()`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onEditCameraSettings(cocos2d::CCObject* sender)`
- `void onUnboundMode(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateCameraEasing()`
- `void updateCameraEasingLabel()`
- `void updateCameraPadding()`
- `void updateCameraPaddingLabel()`
- `void updateItemVisibility()`

**Members:**

- `EffectGameObject* m_gameObject`
- `cocos2d::CCArray* m_gameObjects`
- `cocos2d::CCArray* m_freeModeObjects`
- `cocos2d::CCArray* m_cameraSettingsObjects`
- `Slider* m_cameraEasingSlider`
- `cocos2d::CCLabelBMFont* m_cameraEasingLabel`
- `int m_cameraEasing`
- `Slider* m_cameraPaddingSlider`
- `cocos2d::CCLabelBMFont* m_cameraPaddingLabel`
- `float m_cameraPadding`
- `bool m_freeMode`
- `bool m_cameraSettingsEnabled`
- `bool m_disableDelegate`

### `SetupPulsePopup` : SetupTriggerPopup, cocos2d::extension::ColorPickerDelegate, GJSpecialColorSelectDelegate

**Functions:**

- `static SetupPulsePopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void show()`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void colorValueChanged(cocos2d::ccColor3B color)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void colorSelectClosed(GJSpecialColorSelect* select, int id)`
- `cocos2d::ccColor3B getColorValue()`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onCopy(cocos2d::CCObject* sender)`
- `void onExclusive(cocos2d::CCObject* sender)`
- `void onGroupMainOnly(cocos2d::CCObject* sender)`
- `void onGroupSecondaryOnly(cocos2d::CCObject* sender)`
- `void onHSVLegacyMode(cocos2d::CCObject* sender)`
- `void onPaste(cocos2d::CCObject* sender)`
- `void onSelectPulseMode(cocos2d::CCObject* sender)`
- `void onSelectSpecialColor(cocos2d::CCObject* sender)`
- `void onSelectSpecialTargetID(cocos2d::CCObject* sender)`
- `void onSelectTargetMode(cocos2d::CCObject* sender)`
- `void onUpdateCopyColor(cocos2d::CCObject* sender)`
- `void onUpdateCustomColor(cocos2d::CCObject* sender)`
- `void selectColor(cocos2d::ccColor3B color)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateColorLabels()`
- `void updateColorValue()`
- `void updateCopyColor()`
- `void updateCopyColorTextInputLabel()`
- `void updateFadeInLabel(bool decimals)`
- `void updateFadeInTime()`
- `void updateFadeOutLabel(bool decimals)`
- `void updateFadeOutTime()`
- `void updateGroupMainOnly()`
- `void updateGroupSecondaryOnly()`
- `void updateHoldLabel(bool decimals)`
- `void updateHoldTime()`
- `void updateHSVValue()`
- `void updatePulseMode()`
- `void updatePulseTargetType()`
- `void updateTargetID()`
- `void updateTextInputLabel()`

**Members:**

- `cocos2d::extension::CCControlColourPicker* m_colorPicker`
- `bool m_unk3c0`
- `cocos2d::CCArray* m_colorObjects`
- `cocos2d::CCArray* m_hsvObjects`
- `Slider* m_fadeInSlider`
- `Slider* m_holdSlider`
- `Slider* m_fadeOutSlider`
- `CCMenuItemSpriteExtra* m_channelButton`
- `CCMenuItemSpriteExtra* m_groupButton`
- `cocos2d::CCLabelBMFont* m_idLabel`
- `cocos2d::ccColor3B m_originalColor`
- `cocos2d::CCSprite* m_currentColorSprite`
- `cocos2d::CCSprite* m_originalColorSprite`
- `cocos2d::ccColor3B m_currentColor`
- `CCMenuItemSpriteExtra* m_colorButton`
- `CCMenuItemSpriteExtra* m_hsvButton`
- `ConfigureHSVWidget* m_hsvWidget`
- `CCMenuItemSpriteExtra* m_specialColorButton`
- `CCTextInputNode* m_fadeInInput`
- `CCTextInputNode* m_holdInput`
- `CCTextInputNode* m_fadeOutInput`
- `CCTextInputNode* m_idInput`
- `CCTextInputNode* m_colorIDInput`
- `CCMenuItemToggler* m_mainOnlyToggler`
- `CCMenuItemToggler* m_secondaryOnlyToggler`
- `CCMenuItemToggler* m_staticHSVToggler`
- `cocos2d::CCLabelBMFont* m_mainOnlyLabel`
- `cocos2d::CCLabelBMFont* m_secondaryOnlyLabel`
- `cocos2d::CCLabelBMFont* m_staticHSVLabel`
- `bool m_groupMainOnly`
- `bool m_groupSecondaryOnly`
- `bool m_staticHSV`
- `int m_targetGroupID`
- `int m_copyColorID`
- `bool m_colorInitializing`
- `float m_fadeInTime`
- `float m_holdTime`
- `float m_fadeOutTime`
- `int m_pulseMode`
- `int m_pulseTargetType`
- `bool m_modesInitializing`
- `bool m_pulseExclusive`
- `cocos2d::ccHSVValue m_hsv`
- `CCTextInputNode* m_rInput`
- `CCTextInputNode* m_gInput`
- `CCTextInputNode* m_bInput`
- `CCTextInputNode* m_hexInput`

### `SetupRandAdvTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupRandAdvTriggerPopup* create(RandTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `void addChance(int id, int chance)`
- `void addChanceToObject(RandTriggerGameObject* object, int id, int chance)`
- `void callRemoveFromGroup(float dt)`
- `bool init(RandTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onAddChance(cocos2d::CCObject* sender)`
- `void onRemoveFromGroup(cocos2d::CCObject* sender)`
- `void removeGroupID(int id)`
- `void removeGroupIDFromObject(RandTriggerGameObject* object, int id)`
- `void updateGroupIDButtons()`

**Members:**

- `bool m_performedAction`
- `cocos2d::CCArray* m_groupButtons`
- `CCTextInputNode* m_groupIDInput`
- `CCTextInputNode* m_chanceInput`
- `int m_groupToRemove`
- `bool m_removingGroup`

### `SetupRandTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupRandTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onTargetID2Arrow(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateChance()`
- `void updateChanceLabel(bool decimals)`
- `void updateTargetID()`
- `void updateTargetID2()`
- `void updateTextInputLabel()`
- `void updateTextInputLabel2()`

**Members:**

- `CCTextInputNode* m_chanceInput`
- `Slider* m_chanceSlider`
- `float m_chancePercent`
- `CCTextInputNode* m_groupID1Input`
- `CCTextInputNode* m_groupID2Input`
- `int m_groupID1`
- `int m_groupID2`

### `SetupResetTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupResetTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupReverbPopup` : SetupTriggerPopup

**Functions:**

- `SetupReverbPopup()`
- `static SetupReverbPopup* create(SFXTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onReverb(cocos2d::CCObject* sender)`
- `void updateReverbLabel()`

**Members:**

- `cocos2d::CCLabelBMFont* m_reverbLabel`

### `SetupRotateCommandPopup` : SetupTriggerPopup

**Functions:**

- `static SetupRotateCommandPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void updateInputNode(int tag, float value)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float triggerValueFromSliderValue(int tag, float value)`
- `virtual float triggerSliderValueFromValue(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onInfiniteDuration(cocos2d::CCObject* sender)`
- `void updateControlVisibility()`

### `SetupRotateGameplayPopup` : SetupTriggerPopup

**Functions:**

- `SetupRotateGameplayPopup()`
- `static SetupRotateGameplayPopup* create(RotateGameplayGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onPlusButton(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(RotateGameplayGameObject* object, cocos2d::CCArray* objects)`

### `SetupRotatePopup` : SetupTriggerPopup

**Functions:**

- `static SetupRotatePopup* create(EnhancedGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(EnhancedGameObject* object, cocos2d::CCArray* objects)`

### `SetupSFXEditPopup` : SetupAudioTriggerPopup

**Functions:**

- `static SetupSFXEditPopup* create(SFXTriggerGameObject* object, cocos2d::CCArray* objects, bool songTrigger)`
- `bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects, bool songTrigger)`

### `SetupSFXPopup` : SetupAudioTriggerPopup, CustomSFXDelegate, SFXBrowserDelegate

**Functions:**

- `static SetupSFXPopup* create(SFXTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void pageChanged()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onPlusButton(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void sfxObjectSelected(SFXInfoObject* object)`
- `virtual int getActiveSFXID()`
- `virtual bool overridePlaySFX(SFXInfoObject* object)`
- `virtual void sfxBrowserClosed(SFXBrowser* browser)`
- `void createSFXWidget()`
- `bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void onBrowseSFX(cocos2d::CCObject* sender)`
- `void updateLength()`

**Members:**

- `int m_sfxID`
- `CustomSFXWidget* m_sfxWidget`
- `int m_sfxLength`

### `SetupSequenceTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupSequenceTriggerPopup* create(SequenceTriggerGameObject* object)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(SequenceTriggerGameObject* object)`
- `void onAddChance(cocos2d::CCObject* sender)`
- `void onChangeOrder(cocos2d::CCObject* sender)`
- `void onDeleteSelected(cocos2d::CCObject* sender)`
- `void onSelect(cocos2d::CCObject* sender)`
- `void updateGroupIDButtons()`

**Members:**

- `CCMenuItemSpriteExtra* m_selectedButton`
- `bool m_unk3b0`
- `bool m_unk3b1`
- `cocos2d::CCArray* m_groupButtons`
- `int m_unk3c0`
- `bool m_unk3c4`

### `SetupShaderEffectPopup` : SetupTriggerPopup

**Functions:**

- `SetupShaderEffectPopup()`
- `~SetupShaderEffectPopup()`
- `static SetupShaderEffectPopup* create(EffectGameObject* object, cocos2d::CCArray* objects, int id)`
- `virtual void toggleGroup(int group, bool visible)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void updateDefaultTriggerValues()`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects, int id)`
- `void onResetColors(cocos2d::CCObject* sender)`
- `void onZLayer(cocos2d::CCObject* sender)`
- `void setupBulge()`
- `void setupChromatic()`
- `void setupChromaticGlitch()`
- `void setupColorChange()`
- `void setupGlitch()`
- `void setupGrayscale()`
- `void setupHueShift()`
- `void setupInvertColor()`
- `void setupLensCircle()`
- `void setupMotionBlur()`
- `void setupPinch()`
- `void setupPixelate()`
- `void setupRadialBlur()`
- `void setupSepia()`
- `void setupShaderTrigger()`
- `void setupShockLine()`
- `void setupShockWave()`
- `void setupSplitScreen()`
- `void updateZLayerButtons()`
- `gd::string zLayerToString(int zLayer)`

**Members:**

- `cocos2d::CCArray* m_zLayerSprites`
- `int m_zLayerMin`
- `int m_zLayerMax`
- `bool m_changeMin`
- `int m_objectID`

### `SetupShakePopup` : SetupTriggerPopup

**Functions:**

- `static SetupShakePopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateDuration()`
- `void updateDurLabel(bool decimals)`
- `void updateInterval()`
- `void updateIntervalLabel(bool decimals)`
- `void updateShake()`
- `void updateShakeLabel(bool decimals)`

**Members:**

- `CCTextInputNode* m_durationInput`
- `Slider* m_durationSlider`
- `float m_duration`
- `CCTextInputNode* m_strengthInput`
- `Slider* m_strengthSlider`
- `float m_strength`
- `CCTextInputNode* m_intervalInput`
- `Slider* m_intervalSlider`
- `float m_interval`

### `SetupSmartBlockLayer` : FLAlertLayer, TextInputDelegate, SelectArtDelegate

**Functions:**

- `static SetupSmartBlockLayer* create(SmartGameObject* object, cocos2d::CCArray* objects)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void selectArtClosed(SelectArtLayer* layer)`
- `void determineStartValues()`
- `bool init(SmartGameObject* object, cocos2d::CCArray* objects)`
- `void onAllowFlipping(cocos2d::CCObject* sender)`
- `void onAllowRotation(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onCreate(cocos2d::CCObject* sender)`
- `void onCreateAll(cocos2d::CCObject* sender)`
- `void onCreateTemplate(cocos2d::CCObject* sender)`
- `void onDontDelete(cocos2d::CCObject* sender)`
- `void onIgnoreCorners(cocos2d::CCObject* sender)`
- `void onNearbyReference(cocos2d::CCObject* sender)`
- `void onPasteTemplate(cocos2d::CCObject* sender)`
- `void onReferenceOnly(cocos2d::CCObject* sender)`
- `void onSelectPremade(cocos2d::CCObject* sender)`
- `void onSelectTemplate(cocos2d::CCObject* sender)`

**Members:**

- `bool m_referenceOnly`
- `bool m_allowRotation`
- `bool m_allowFlipX`
- `bool m_allowFlipY`
- `bool m_useNearby`
- `bool m_dontDelete`
- `bool m_ignoreCorners`
- `int m_specialTemplate`
- `SmartGameObject* m_gameObject`
- `cocos2d::CCArray* m_gameObjects`

### `SetupSmartTemplateLayer` : FLAlertLayer, TextInputDelegate, FLAlertLayerProtocol

**Functions:**

- `static SetupSmartTemplateLayer* create(GJSmartTemplate* smartTemplate)`
- `virtual void keyBackClicked()`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(GJSmartTemplate* smartTemplate)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onClick(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`

**Members:**

- `GJSmartTemplate* m_smartTemplate`
- `CCTextInputNode* m_nameInput`
- `cocos2d::CCNode* m_unk298`

### `SetupSongTriggerPopup` : SetupAudioTriggerPopup, MusicDownloadDelegate, SongPlaybackDelegate

**Functions:**

- `static SetupSongTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void pageChanged()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void onPlayback(SongInfoObject* object)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onResetSongTime(cocos2d::CCObject* sender)`
- `void onSavePlaybackPos(cocos2d::CCObject* sender)`
- `void updateApplyPrepare(bool hideAll)`
- `void updateLength()`
- `void updateSongTimeSlider()`

**Members:**

- `SongSelectNode* m_selectNode`

### `SetupSpawnParticlePopup` : SetupTriggerPopup

**Functions:**

- `static SetupSpawnParticlePopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupSpawnPopup` : SetupTriggerPopup

**Functions:**

- `static SetupSpawnPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `void addRemap(int oldID, int newID)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onAddRemap(cocos2d::CCObject* sender)`
- `void onDeleteRemap(cocos2d::CCObject* sender)`
- `void onPasteRemap(cocos2d::CCObject* sender)`
- `void onSelectRemap(cocos2d::CCObject* sender)`
- `void queueUpdateButtons()`
- `void updateRemapButtons(float dt)`

**Members:**

- `bool m_isBusy`
- `cocos2d::CCArray* m_remapButtons`
- `gd::vector<int> m_remapGroups`
- `int m_remapOriginalID`
- `int m_remapNewID`

### `SetupStaticCameraPopup` : SetupTriggerPopup

**Functions:**

- `static SetupStaticCameraPopup* create(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects)`
- `void updateState()`

### `SetupStopTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupStopTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `SetupTeleportPopup` : SetupTriggerPopup

**Functions:**

- `static SetupTeleportPopup* create(TeleportPortalObject* object, cocos2d::CCArray* objects, int id, bool platformer)`
- `virtual void determineStartValues()`
- `virtual void updateDefaultTriggerValues()`
- `virtual void valueDidChange(int tag, float value)`
- `bool init(TeleportPortalObject* object, cocos2d::CCArray* objects, int id, bool platformer)`
- `void onTeleportGravity(cocos2d::CCObject* sender)`
- `void updateTeleportGravityState(int state)`

**Members:**

- `cocos2d::CCArray* m_teleportGravityToggles`

### `SetupTimeWarpPopup` : SetupTriggerPopup

**Functions:**

- `static SetupTimeWarpPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void sliderChanged(cocos2d::CCObject* sender)`
- `void updateTimeWarp()`
- `void updateTimeWarpLabel()`

**Members:**

- `cocos2d::CCLabelBMFont* m_timeWarpLabel`
- `Slider* m_timeWarpSlider`
- `float m_timeWarpMod`

### `SetupTimerControlTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupTimerControlTriggerPopup* create(TimerTriggerGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects)`

### `SetupTimerEventTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupTimerEventTriggerPopup* create(TimerTriggerGameObject* object, cocos2d::CCArray* objects)`
- `bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects)`

### `SetupTimerTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupTimerTriggerPopup* create(TimerTriggerGameObject* object, cocos2d::CCArray* objects)`
- `bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects)`

### `SetupTouchTogglePopup` : SetupTriggerPopup

**Functions:**

- `static SetupTouchTogglePopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textChanged(CCTextInputNode* node)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`
- `void onControlMode(cocos2d::CCObject* sender)`
- `void onDualTouchMode(cocos2d::CCObject* sender)`
- `void onHoldMode(cocos2d::CCObject* sender)`
- `void onTargetIDArrow(cocos2d::CCObject* sender)`
- `void onTouchMode(cocos2d::CCObject* sender)`
- `void updateTargetID()`
- `void updateTextInputLabel()`

**Members:**

- `CCTextInputNode* m_groupIDInput`
- `int m_groupID`
- `bool m_holdMode`
- `int m_toggleMode`
- `int m_playerMode`
- `CCMenuItemToggler* m_toggleOnToggler`
- `CCMenuItemToggler* m_toggleOffToggler`
- `bool m_dualMode`
- `CCMenuItemToggler* m_p1OnlyToggler`
- `CCMenuItemToggler* m_p2OnlyToggler`

### `SetupTransformPopup` : SetupTriggerPopup

**Functions:**

- `static SetupTransformPopup* create(TransformTriggerGameObject* object, cocos2d::CCArray* objects)`
- `bool init(TransformTriggerGameObject* object, cocos2d::CCArray* objects)`

### `SetupTriggerPopup` : FLAlertLayer, TextInputDelegate, ConfigureValuePopupDelegate, SliderDelegate

**Functions:**

- `SetupTriggerPopup()`
- `~SetupTriggerPopup()`
- `static SetupTriggerPopup* create(float width, float height)`
- `static SetupTriggerPopup* create(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void pageChanged()`
- `virtual void toggleGroup(int group, bool visible)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `virtual void updateInputValue(int tag, float& value)`
- `virtual void sliderBegan(Slider* slider)`
- `virtual void sliderEnded(Slider* slider)`
- `virtual void onPlusButton(cocos2d::CCObject* sender)`
- `virtual void onCustomButton(cocos2d::CCObject* sender)`
- `virtual void updateDefaultTriggerValues()`
- `virtual void updateInputNode(int tag, float value)`
- `virtual void updateToggleItem(int value, bool toggled)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float getValue(int tag)`
- `virtual float triggerValueFromSliderValue(int tag, float value)`
- `virtual float triggerSliderValueFromValue(int tag, float value)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `virtual void valuePopupClosed(ConfigureValuePopup* popup, float value)`
- `void addCloseButton(gd::string text)`
- `void addCustomButton(int tag, ButtonSprite* sprite, cocos2d::CCPoint position, int page, int group)`
- `void addHelpButton(gd::string title, gd::string desc, float scale)`
- `void addInfoLabel(gd::string text, float scale, cocos2d::CCPoint position, int page, int group)`
- `void addObjectsToGroup(cocos2d::CCArray* objects, int group)`
- `void addObjectsToPage(cocos2d::CCArray* objects, int page)`
- `void addObjectToGroup(cocos2d::CCObject* object, int group)`
- `void addObjectToPage(cocos2d::CCObject* object, int page)`
- `void addTitle(gd::string title)`
- `void closeInputNodes()`
- `void createCustomButton(int tag, gd::string text, gd::string frame, cocos2d::CCPoint position, float buttonScale, float labelScale, bool vertical, int page, int group)`
- `void createCustomEasingControls(gd::string text, cocos2d::CCPoint position, float scale, int typeProperty, int rateProperty, int page, int group)`
- `cocos2d::CCArray* createCustomToggleValueControl(int property, bool toggled, bool notClickable, gd::string text, cocos2d::CCPoint position, bool vertical, int page, int group)`
- `void createEasingControls(cocos2d::CCPoint position, float scale, int page, int group)`
- `void createMultiTriggerItems(cocos2d::CCPoint touchPos, cocos2d::CCPoint spawnPos, cocos2d::CCPoint multiPos)`
- `void createMultiTriggerItemsCorner()`
- `void createMultiTriggerItemsDefault()`
- `void createMultiTriggerItemsDefaultHorizontal()`
- `void createMultiTriggerItemsDefaultVertical()`
- `void createPageButtons(float offset, int arrow)`
- `CCMenuItemSpriteExtra* createPlusButton(int tag, cocos2d::CCPoint position, float scale, gd::string frame, int page, int group)`
- `CCMenuItemToggler* createToggleButton(gd::string text, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCPoint position)`
- `cocos2d::CCArray* createToggleValueControl(int property, gd::string label, cocos2d::CCPoint position, bool vertical, int page, int group, float scale)`
- `cocos2d::CCArray* createToggleValueControlAdvanced(int property, gd::string label, cocos2d::CCPoint position, bool vertical, int page, int group, float buttonScale, float labelScale, float labelWidth, cocos2d::CCPoint offset)`
- `void createValueControl(int property, gd::string label, cocos2d::CCPoint position, float scale, float sliderMin, float sliderMax)`
- `cocos2d::CCArray* createValueControlAdvanced(int property, gd::string label, cocos2d::CCPoint position, float scale, bool noSlider, InputValueType valueType, int length, bool arrows, float sliderMin, float sliderMax, int page, int group, GJInputStyle inputStyle, int decimalPlaces, bool allowDisable)`
- `void createValueControlWArrows(int property, gd::string label, cocos2d::CCPoint position, float scale)`
- `cocos2d::CCArray* getGroupContainer(int group)`
- `float getMaxSliderValue(int property)`
- `float getMinSliderValue(int property)`
- `cocos2d::CCArray* getObjects()`
- `cocos2d::CCArray* getPageContainer(int page)`
- `float getTriggerValue(int property, GameObject* object)`
- `float getTruncatedValue(float value, int decimals)`
- `float getTruncatedValueByTag(int tag, float value)`
- `void goToPage(int page, bool hideAll)`
- `void hideAll()`
- `bool init(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background)`
- `void onCustomEaseArrow(int property, bool up)`
- `void onCustomEaseArrowDown(cocos2d::CCObject* sender)`
- `void onCustomEaseArrowUp(cocos2d::CCObject* sender)`
- `void onCustomEaseRate(cocos2d::CCObject* sender)`
- `void onDisableValue(cocos2d::CCObject* sender)`
- `void onEase(cocos2d::CCObject* sender)`
- `void onEaseRate(cocos2d::CCObject* sender)`
- `void onMultiTrigger(cocos2d::CCObject* sender)`
- `void onPage(cocos2d::CCObject* sender)`
- `void onSpawnedByTrigger(cocos2d::CCObject* sender)`
- `void onToggleTriggerValue(cocos2d::CCObject* sender)`
- `void onTouchTriggered(cocos2d::CCObject* sender)`
- `void postSetup()`
- `void preSetup()`
- `void refreshGroupVisibility()`
- `void removeObjectFromGroup(cocos2d::CCObject* object, int group)`
- `void removeObjectFromPage(cocos2d::CCObject* object, int page)`
- `void resetDisabledValues()`
- `void setMaxSliderValue(float value, int property)`
- `void setMinSliderValue(float value, int property)`
- `bool shouldLimitValue(int property)`
- `void toggleBG(bool visible)`
- `void toggleCustomEaseRateVisibility(int property, int tag)`
- `void toggleDisableButtons(bool visible)`
- `void toggleEaseRateVisibility()`
- `void toggleLimitValue(int property, bool limit)`
- `void togglePageArrows(bool visible)`
- `void triggerArrowChanged(int property, bool isRight)`
- `void triggerArrowLeft(cocos2d::CCObject* sender)`
- `void triggerArrowRight(cocos2d::CCObject* sender)`
- `void triggerSliderChanged(cocos2d::CCObject* sender)`
- `void updateCustomEaseLabel(int property, int easingType)`
- `void updateCustomEaseRateLabel(int property, float easingRate)`
- `void updateCustomToggleTrigger(int tag, bool toggled)`
- `void updateEaseLabel()`
- `void updateEaseRateLabel()`
- `void updateEditorLabel()`
- `void updateInputNodeLabel(int property, gd::string text)`
- `void updateLabel(int property, gd::string text)`
- `void updateMultiTriggerBtn()`
- `void updateSlider(int property)`
- `void updateSlider(int property, float value)`
- `void updateSpawnedByTrigger()`
- `void updateTouchTriggered()`
- `void updateValue(int property, float value)`
- `void updateValueControls(int property, float value)`
- `void valueChanged(int property, float value)`

**Members:**

- `EffectGameObject* m_gameObject`
- `cocos2d::CCArray* m_gameObjects`
- `bool m_touchTriggered`
- `bool m_spawnTriggered`
- `CCMenuItemToggler* m_touchToggle`
- `CCMenuItemToggler* m_spawnToggle`
- `cocos2d::CCArray* m_multiTriggerContainer`
- `bool m_multiTriggered`
- `float m_width`
- `float m_height`
- `bool m_disableTextDelegate`
- `cocos2d::CCDictionary* m_valueToggles`
- `cocos2d::CCDictionary* m_inputNodes`
- `cocos2d::CCDictionary* m_valueControls`
- `cocos2d::CCDictionary* m_customValueToggles`
- `cocos2d::CCDictionary* m_disableButtons`
- `cocos2d::CCLabelBMFont* m_easingLabel`
- `cocos2d::CCLabelBMFont* m_easingRateLabel`
- `CCMenuItemSpriteExtra* m_easingRateButton`
- `EasingType m_easingType`
- `float m_easingRate`
- `cocos2d::CCDictionary* m_inputLabels`
- `cocos2d::CCDictionary* m_triggerValues`
- `cocos2d::CCDictionary* m_minSliderValues`
- `cocos2d::CCDictionary* m_maxSliderValues`
- `gd::map<int, bool> m_shouldLimitValues`
- `bool m_disableSliderDelegate`
- `bool m_effectObjects`
- `cocos2d::CCArray* m_pageContainers`
- `int m_page`
- `float m_easingControlScale`
- `cocos2d::CCArray* m_groupContainers`
- `cocos2d::CCDictionary* m_customEasingTags`
- `cocos2d::CCDictionary* m_customEasingLabels`
- `cocos2d::CCDictionary* m_customEasingButtons`
- `cocos2d::CCDictionary* m_customEasingScales`
- `cocos2d::CCDictionary* m_disabledEasingButtons`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `bool m_hideAll`

### `SetupZoomTriggerPopup` : SetupTriggerPopup

**Functions:**

- `static SetupZoomTriggerPopup* create(EffectGameObject* object, cocos2d::CCArray* objects)`
- `virtual void determineStartValues()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `bool init(EffectGameObject* object, cocos2d::CCArray* objects)`

### `ShaderGameObject` : EffectGameObject

**Functions:**

- `ShaderGameObject()`
- `static ShaderGameObject* create(char const* frame)`
- `virtual void customSetup()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `float m_speed`
- `float m_strength`
- `float m_outer`
- `float m_timeOff`
- `float m_waveWidth`
- `float m_targetX`
- `float m_targetY`
- `float m_fadeIn`
- `float m_fadeOut`
- `float m_screenOffsetX`
- `float m_screenOffsetY`
- `bool m_invert`
- `float m_inner`
- `float m_maxSize`
- `bool m_flip`
- `bool m_rotate`
- `bool m_dual`
- `bool m_useX`
- `bool m_useY`
- `bool m_snapGrid`
- `bool m_hardEdges`
- `bool m_disableAll`
- `int m_zLayerMin`
- `int m_zLayerMax`
- `bool m_animate`
- `bool m_relative`
- `bool m_editorDisabled`

### `ShaderLayer` : cocos2d::CCLayer

**Functions:**

- `ShaderLayer()`
- `~ShaderLayer()`
- `static ShaderLayer* create()`
- `virtual bool init()`
- `virtual void update(float dt)`
- `virtual void visit()`
- `cocos2d::CCPoint objectPosToShaderPos(cocos2d::CCPoint position)`
- `void performCalculations()`
- `void preBulgeShader()`
- `void preChromaticGlitchShader()`
- `void preChromaticShader()`
- `void preColorChangeShader()`
- `void preCommonShader()`
- `void preGlitchShader()`
- `void preGrayscaleShader()`
- `void preHueShiftShader()`
- `void preInvertColorShader()`
- `void preLensCircleShader()`
- `void preMotionBlurShader()`
- `cocos2d::CCPoint prepareTargetContainer()`
- `void prePinchShader()`
- `void prePixelateShader()`
- `void preRadialBlurShader()`
- `void preSepiaShader()`
- `void preShockLineShader()`
- `void preShockWaveShader()`
- `void preSplitScreenShader()`
- `bool resetAllShaders()`
- `void resetTargetContainer()`
- `void setupBulgeShader()`
- `void setupChromaticGlitchUniforms()`
- `void setupChromaticUniforms()`
- `void setupColorChangeShader()`
- `void setupCommonUniforms()`
- `void setupGlitchUniforms()`
- `void setupGrayscaleShader()`
- `void setupHueShiftShader()`
- `void setupInvertColorShader()`
- `void setupLensCircleShader()`
- `void setupMotionBlurShader()`
- `void setupPinchShader()`
- `void setupRadialBlurShader()`
- `void setupSepiaShader()`
- `void setupShader(bool reset)`
- `void setupShockLineUniforms()`
- `void setupShockWaveUniforms()`
- `void setupSplitScreenShader()`
- `void toggleAntiAlias(bool antiAlias)`
- `void triggerBulge(float fadeTime, float bulge, float screenOffsetX, float screenOffsetY, float radius, int targetID, int easingType, float easingRate, bool relative)`
- `void triggerChromaticGlitch(bool enable, float duration, float speed, float strength, float rgbOffset, float lineThickness, float lineStrength, float segmentHeight, int easingType, float easingRate, bool relative, bool relativePos)`
- `void triggerChromaticX(float fadeTime, float targetX, int easingType, float easingRate, bool relative)`
- `void triggerChromaticY(float fadeTime, float targetY, int easingType, float easingRate, bool relative)`
- `void triggerColorChange(float fadeTime, float cr, float cg, float cb, float br, float bg, float bb, int easingType, float easingRate)`
- `void triggerGlitch(float fadeTime, float strength, float speed, float sliceHeight, float maxSliceXOff, float maxColXOff, float maxColYOff, bool relative)`
- `void triggerGrayscale(float fadeTime, float target, bool useLuminance, int tintChannel, int easingType, float easingRate)`
- `void triggerHueShift(float fadeTime, float degrees, int easingType, float easingRate)`
- `void triggerInvertColor(float fadeTime, float target, float r, float g, float b, bool editRGB, bool tweenRGB, bool clampRGB, int easingType, float easingRate)`
- `void triggerLensCircle(float fadeTime, float size, float fade, float strength, int targetID, int tintChannel, float screenOffsetX, float screenOffsetY, int easingType, float easingRate, bool relative)`
- `void triggerMotionBlurX(float fadeTime, float targetX, float intensity, float fade, int targetID, float followEase, bool dualDir, int refChannel, int easingType, float easingRate, bool relative, bool emptyOnly)`
- `void triggerMotionBlurY(float fadeTime, float targetY, float intensity, float fade, int targetID, float followEase, bool dualDir, int refChannel, int easingType, float easingRate, bool relative, bool emptyOnly)`
- `void triggerPinchX(float fadeTime, float targetX, float screenOffsetX, float radius, float modifier, bool target, int targetID, int easingType, float easingRate, bool relative)`
- `void triggerPinchY(float fadeTime, float targetY, float screenOffsetY, float radius, float modifier, bool target, int targetID, int easingType, float easingRate, bool relative)`
- `void triggerPixelateX(float fadeTime, float targetX, bool snapGrid, bool hardEdges, int easingType, float easingRate, bool relative)`
- `void triggerPixelateY(float fadeTime, float targetY, bool snapGrid, bool hardEdges, int easingType, float easingRate, bool relative)`
- `void triggerRadialBlur(float fadeTime, float size, float intensity, float fade, int refChannel, float screenOffsetX, float screenOffsetY, bool target, int targetID, int easingType, float easingRate, bool emptyOnly)`
- `void triggerSepia(float fadeTime, float target, int easingType, float easingRate)`
- `void triggerShockLine(float speed, float thickness, bool rotate, bool flip, bool dual, bool invert, float strength, float waveWidth, float fadeIn, float fadeOut, float timeOffset, float screenOffset, int targetID, bool target, bool follow, bool relative, float maxSize, bool animate, float fadeTime, int easingType, float easingRate)`
- `void triggerShockWave(float speed, float thickness, float strength, float waveWidth, float fadeIn, float fadeOut, float timeOffset, bool invert, float inner, float screenOffsetX, float screenOffsetY, int targetID, bool target, bool follow, bool relative, float outer, float maxSize, bool animate, float fadeTime, int easingType, float easingRate)`
- `void triggerSplitScreenCols(float fadeTime, float targetX, int easingType, float easingRate)`
- `void triggerSplitScreenRows(float fadeTime, float targetY, int easingType, float easingRate)`
- `void tweenValue(float fromValue, float toValue, int action, float duration, int easingType, float easingRate)`
- `void tweenValueAuto(float value, int action, float duration, int easingType, float easingRate)`
- `void updateEffectOffsets(cocos2d::CCPoint center)`
- `void updateMotionBlurSpeedX(float x, float dt)`
- `void updateMotionBlurSpeedY(float y, float dt)`
- `void updateShockLineCenter(cocos2d::CCPoint center)`
- `void updateShockWaveCenter(cocos2d::CCPoint center)`
- `bool updateZLayer(int minLayer, int maxLayer, bool noParticles)`

**Members:**

- `GJShaderState m_state`
- `bool m_timesyncShaderActions`
- `cocos2d::CCGLProgram* m_shader`
- `cocos2d::CCRenderTexture* m_renderTexture`
- `cocos2d::CCSprite* m_sprite`
- `bool m_antiAlias`
- `bool m_configuredAntiAlias`
- `void* m_unk3d4`
- `GJBaseGameLayer* m_gameLayer`
- `cocos2d::CCPoint m_savedCameraPosition`
- `float m_savedCameraRotation`
- `float m_shockWaveTimeMult`
- `float m_scaleFactor`
- `float m_aspectRatio`
- `cocos2d::CCSize m_screenSize`
- `cocos2d::CCSize m_textureContentSize`
- `cocos2d::CCSize m_targetTextureSize`
- `cocos2d::CCSize m_targetTextureSizeExtra`
- `int m_textureScaleUniform`
- `int m_textureScaleInvUniform`
- `int m_screenAspectUniform`
- `int m_screenAspectINVUniform`
- `int m_shaderPositionUniform`
- `int m_blurRefColorUniform`
- `int m_blurUseRefUniform`
- `int m_blurIntensityUniform`
- `int m_blurOnlyEmptyUniform`
- `int m_shockWaveTimeUniform`
- `int m_shockWaveTime1Uniform`
- `int m_shockWaveTime2Uniform`
- `int m_shockWaveTime3Uniform`
- `int m_shockWaveTime4Uniform`
- `int m_shockWaveStrengthUniform`
- `int m_shockWaveWavesUniform`
- `int m_shockWaveCenterUniform`
- `int m_shockWaveInvertUniform`
- `int m_shockWaveMinSizeUniform`
- `int m_shockWaveMaxSizeUniform`
- `int m_shockWaveMaxDistValUniform`
- `float m_shockWaveTime1`
- `float m_shockWaveTime2`
- `float m_shockWaveTime3`
- `float m_shockWaveTime4`
- `float m_shockWaveMaxDistVal`
- `float m_shockWaveMinSize`
- `float m_shockWaveMaxSize`
- `bool m_shockWaveUnk46c`
- `int m_shockLineTimeUniform`
- `int m_shockLineTime1Uniform`
- `int m_shockLineTime2Uniform`
- `int m_shockLineTime3Uniform`
- `int m_shockLineTime4Uniform`
- `int m_shockLineAxisUniform`
- `int m_shockLineDirectionUniform`
- `int m_shockLineDualUniform`
- `int m_shockLineWavesUniform`
- `int m_shockLineStrengthUniform`
- `int m_shockLineCenterUniform`
- `int m_shockLineMaxDistValUniform`
- `float m_shockLineTime1`
- `float m_shockLineTime2`
- `float m_shockLineTime3`
- `float m_shockLineTime4`
- `float m_shockLineMaxDistVal`
- `int m_unk4b4`
- `int m_unk4b8`
- `int m_unk4bc`
- `int m_glitchBotUniform`
- `int m_glitchTopUniform`
- `int m_glitchXOffsetUniform`
- `int m_glitchColOffsetUniform`
- `int m_glitchRndUniform`
- `int m_chromaticXOffUniform`
- `int m_chromaticYOffUniform`
- `int m_cGRGBOffsetUniform`
- `int m_cGYOffsetUniform`
- `int m_cGTimeUniform`
- `int m_cGStrengthUniform`
- `int m_cGHeightUniform`
- `int m_cGLineThickUniform`
- `int m_cGLineStrengthUniform`
- `int m_lensCircleOriginUniform`
- `int m_lensCircleStartUniform`
- `int m_lensCircleEndUniform`
- `int m_lensCircleStrengthUniform`
- `int m_lensCircleTintUniform`
- `int m_lensCircleAdditiveUniform`
- `int m_radialBlurCenterUniform`
- `int m_radialBlurValueUniform`
- `int m_blurFadeUniform`
- `int m_motionBlurValueUniform`
- `int m_motionBlurMultUniform`
- `int m_motionBlurDualUniform`
- `int m_bulgeValueUniform`
- `int m_bulgeValue2Uniform`
- `int m_bulgeOriginUniform`
- `int m_bulgeRadiusUniform`
- `int m_pinchValueUniform`
- `int m_pinchCenterPosUniform`
- `int m_pinchCalcUniform`
- `int m_pinchRadiusUniform`
- `int m_grayscaleValueUniform`
- `int m_grayscaleTintUniform`
- `int m_grayscaleUseLumUniform`
- `int m_sepiaValueUniform`
- `int m_invertColorValueUniform`
- `int m_hueShiftCosAUniform`
- `int m_hueShiftSinAUniform`
- `int m_colorChangeCUniform`
- `int m_colorChangeBUniform`
- `int m_rowmodUniform`
- `int m_colmodUniform`
- `int m_rowmodCalcUniform`
- `int m_colmodCalcUniform`
- `int m_splitXStartUniform`
- `int m_splitXRangeUniform`
- `int m_splitXRangeMultUniform`
- `int m_splitYStartUniform`
- `int m_splitYRangeUniform`
- `int m_splitYRangeMultUniform`

### `ShardsPage` : FLAlertLayer

**Functions:**

- `ShardsPage()`
- `~ShardsPage()`
- `static ShardsPage* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `void FLAlert_Clicked(FLAlertLayer* alert, bool btn2)`
- `void goToPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onIconInfo(cocos2d::CCObject* sender)`
- `void onSwitchPage(cocos2d::CCObject* sender)`

**Members:**

- `cocos2d::CCDictionary* m_pages`
- `CCMenuItemSpriteExtra* m_prevButton`
- `CCMenuItemSpriteExtra* m_nextButton`
- `cocos2d::CCSprite* m_tierSprite`
- `int m_page`

### `ShareCommentDelegate`

**Functions:**

- `virtual void shareCommentClosed(gd::string text, ShareCommentLayer* layer)`

### `ShareCommentLayer` : FLAlertLayer, TextInputDelegate, UploadActionDelegate, UploadPopupDelegate

**Functions:**

- `static ShareCommentLayer* create(gd::string title, int charLimit, CommentType type, int ID, gd::string desc)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `bool init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc)`
- `void onClear(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onPercent(cocos2d::CCObject* sender)`
- `void onShare(cocos2d::CCObject* sender)`
- `void updateCharCountLabel()`
- `void updateDescText(gd::string desc)`
- `void updatePercentLabel()`

**Members:**

- `int m_charLimit`
- `int m_itemID`
- `CommentType m_commentType`
- `CCTextInputNode* m_commentInput`
- `gd::string m_descText`
- `gd::string m_placeholderText`
- `cocos2d::CCLabelBMFont* m_charCountLabel`
- `cocos2d::CCLabelBMFont* m_percentLabel`
- `UploadActionPopup* m_uploadPopup`
- `bool m_uploadSuccess`
- `bool m_percentEnabled`
- `int m_percent`
- `ShareCommentDelegate* m_delegate`

### `ShareLevelLayer` : FLAlertLayer

**Functions:**

- `ShareLevelLayer()`
- `~ShareLevelLayer()`
- `static ShareLevelLayer* create(GJGameLevel* level)`
- `virtual void keyBackClicked()`
- `CCMenuItemSpriteExtra* getStarsButton(int btnID, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale)`
- `bool init(GJGameLevel* level)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onSettings(cocos2d::CCObject* sender)`
- `void onShare(cocos2d::CCObject* sender)`
- `void selectRating(cocos2d::CCObject* sender)`
- `void setupStars()`

**Members:**

- `GJGameLevel* m_level`
- `int m_starsRequested`
- `cocos2d::CCArray* m_starButtons`
- `cocos2d::CCSprite* m_difficultySprite`

### `ShareLevelSettingsLayer` : FLAlertLayer, NumberInputDelegate

**Functions:**

- `ShareLevelSettingsLayer()`
- `static ShareLevelSettingsLayer* create(GJGameLevel* level)`
- `virtual void keyBackClicked()`
- `bool init(GJGameLevel* level)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onUnlisted(cocos2d::CCObject* sender)`
- `void onUnlistedFriendsOnly(cocos2d::CCObject* sender)`
- `void updateSettingsState()`

**Members:**

- `cocos2d::CCLabelBMFont* m_passwordLabel`
- `GJGameLevel* m_level`
- `CCMenuItemToggler* m_friendsOnlyToggler`
- `cocos2d::CCLabelBMFont* m_friendsOnlyLabel`

### `ShareListLayer` : FLAlertLayer

**Functions:**

- `ShareListLayer()`
- `~ShareListLayer()`
- `static ShareListLayer* create(GJLevelList* list)`
- `virtual void keyBackClicked()`
- `bool init(GJLevelList* list)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onShare(cocos2d::CCObject* sender)`
- `void onUnlisted(cocos2d::CCObject* sender)`
- `void updateUnlistedF()`

**Members:**

- `GJLevelList* m_list`
- `CCMenuItemToggler* m_friendsOnlyToggler`
- `cocos2d::CCLabelBMFont* m_friendsOnlyLabel`

### `SimpleObject` : cocos2d::CCObject

**Functions:**

- `SimpleObject()`
- `static SimpleObject* create()`
- `bool init()`

**Members:**

- `cocos2d::ccColor3B m_color`

### `SimplePlayer` : cocos2d::CCSprite

**Functions:**

- `SimplePlayer()`
- `~SimplePlayer()`
- `static SimplePlayer* create(int id)`
- `virtual void setOpacity(unsigned char opacity)`
- `virtual void setColor(cocos2d::ccColor3B const& color)`
- `void asyncLoadIcon(int id, IconType type)`
- `void createRobotSprite(int frame)`
- `void createSpiderSprite(int frame)`
- `void disableCustomGlowColor()`
- `void disableGlowOutline()`
- `void enableCustomGlowColor(cocos2d::ccColor3B const& color)`
- `void hideAll()`
- `void hideSecondary()`
- `void iconFinishedLoading(int id, IconType type)`
- `bool init(int id)`
- `void setColors(cocos2d::ccColor3B const& color1, cocos2d::ccColor3B const& color2)`
- `void setFrames(char const* firstFrame, char const* secondFrame, char const* ufoFrame, char const* glowFrame, char const* extraFrame)`
- `void setGlowOutline(cocos2d::ccColor3B color)`
- `void setSecondColor(cocos2d::ccColor3B const& color)`
- `void tryEnableCustomGlowColor(int id)`
- `void updateColors()`
- `void updatePlayerFrame(int id, IconType type)`

**Members:**

- `cocos2d::CCSprite* m_firstLayer`
- `cocos2d::CCSprite* m_secondLayer`
- `cocos2d::CCSprite* m_birdDome`
- `cocos2d::CCSprite* m_outlineSprite`
- `cocos2d::CCSprite* m_detailSprite`
- `GJRobotSprite* m_robotSprite`
- `GJSpiderSprite* m_spiderSprite`
- `int m_unknown`
- `bool m_hasGlowOutline`
- `int m_iconRequestID`
- `bool m_hasCustomGlowColor`
- `cocos2d::ccColor3B m_glowColor`
- `bool m_iconLoaded`

### `SlideInLayer` : cocos2d::CCLayerColor

**Functions:**

- `static SlideInLayer* create()`
- `virtual bool init()`
- `virtual void draw()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void customSetup()`
- `virtual void enterLayer()`
- `virtual void exitLayer(cocos2d::CCObject* sender)`
- `virtual void showLayer(bool instant)`
- `virtual void hideLayer(bool instant)`
- `virtual void layerVisible()`
- `virtual void layerHidden()`
- `virtual void enterAnimFinished()`
- `virtual void disableUI()`
- `virtual void enableUI()`

**Members:**

- `cocos2d::CCLayer* m_mainLayer`
- `cocos2d::CCMenu* m_buttonMenu`
- `cocos2d::CCSprite* m_exitSprite`
- `CCMenuItemSpriteExtra* m_exitButton`
- `cocos2d::CCPoint m_endPosition`
- `cocos2d::CCPoint m_startPosition`
- `void* m_delegate`
- `bool m_closeOnHide`

### `Slider` : cocos2d::CCLayer

**Functions:**

- `static Slider* create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler)`
- `static Slider* create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, float scale)`
- `static Slider* create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, char const* bar, char const* groove, char const* thumb, char const* thumbSel, float scale)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `void disableSlider()`
- `void disableTouch()`
- `void enableSlider()`
- `bool getLiveDragging()`
- `SliderThumb* getThumb()`
- `float getValue()`
- `void hideGroove(bool visibility)`
- `bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, char const* bar, char const* groove, char const* thumb, char const* thumbSel, float scale)`
- `void setBarVisibility(bool visibility)`
- `void setLiveDragging(bool activateThumb)`
- `void setMaxOffset(float offset)`
- `void setRotated(bool rotated)`
- `void setValue(float val)`
- `void sliderBegan()`
- `void sliderEnded()`
- `void updateBar()`

**Members:**

- `SliderTouchLogic* m_touchLogic`
- `cocos2d::CCSprite* m_sliderBar`
- `cocos2d::CCSprite* m_groove`
- `float m_width`
- `float m_height`
- `SliderDelegate* m_delegate`
- `bool m_enabled`

### `SliderDelegate`

**Functions:**

- `virtual void sliderBegan(Slider* slider)`
- `virtual void sliderEnded(Slider* slider)`

### `SliderThumb` : cocos2d::CCMenuItemImage

**Functions:**

- `SliderThumb()`
- `static SliderThumb* create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* normalFrame, char const* selectedFrame)`
- `float getValue()`
- `bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* normalFrame, char const* selectedFrame)`
- `void setMaxOffset(float offset)`
- `void setRotated(bool rotated)`
- `void setValue(float value)`

**Members:**

- `float m_length`
- `bool m_vertical`

### `SliderTouchLogic` : cocos2d::CCMenu

**Functions:**

- `SliderTouchLogic()`
- `static SliderTouchLogic* create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* thumb, char const* thumbSel, float scale)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* thumb, char const* thumbSel, float scale)`
- `void setMaxOffset(float offset)`
- `void setRotated(bool rotated)`

**Members:**

- `float m_unknownUnused`
- `float m_length`
- `SliderThumb* m_thumb`
- `Slider* m_slider`
- `bool m_activateThumb`
- `cocos2d::CCPoint m_position`
- `bool m_rotated`

### `SmartGameObject` : GameObject

**Functions:**

- `SmartGameObject()`
- `static SmartGameObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`
- `void updateSmartFrame()`

**Members:**

- `bool m_referenceOnly`
- `gd::string m_baseFrame`
- `gd::string m_smartFrame`

### `SmartTemplateCell` : TableViewCell

**Functions:**

- `SmartTemplateCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromObject(GJSmartTemplate* smartTemplate)`
- `void onClick(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `GJSmartTemplate* m_smartTemplate`

### `SongCell` : TableViewCell

**Functions:**

- `SongCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromObject(SongObject* object)`
- `void onClick(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `SongObject* m_songObject`

### `SongInfoLayer` : FLAlertLayer

**Functions:**

- `static SongInfoLayer* create(int artistID)`
- `static SongInfoLayer* create(gd::string songName, gd::string artistName, gd::string songURL, gd::string newgroundsURL, gd::string youtubeURL, gd::string facebookURL, int songID, gd::string songTags, int nongType)`
- `virtual void keyBackClicked()`
- `bool init(gd::string songName, gd::string artistName, gd::string songURL, gd::string newgroundsURL, gd::string youtubeURL, gd::string facebookURL, int songID, gd::string songTags, int nongType)`
- `void onBPM(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onDownload(cocos2d::CCObject* sender)`
- `void onFB(cocos2d::CCObject* sender)`
- `void onMenuMusic(cocos2d::CCObject* sender)`
- `void onNG(cocos2d::CCObject* sender)`
- `void onPracticeMusic(cocos2d::CCObject* sender)`
- `void onYT(cocos2d::CCObject* sender)`
- `void showCustomMusicUnlockInfo()`

**Members:**

- `gd::string m_downloadLink`
- `gd::string m_newgroundsLink`
- `gd::string m_youtubeLink`
- `gd::string m_facebookLink`
- `int m_songID`
- `int m_musicCustomizerMessageIndex`

### `SongInfoObject` : cocos2d::CCNode

**Functions:**

- `static SongInfoObject* create(cocos2d::CCDictionary* dict)`
- `static SongInfoObject* create(int songID)`
- `static SongInfoObject* create(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, gd::string unknown, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority)`
- `static SongInfoObject* createWithCoder(DS_Dictionary* dict)`
- `virtual void encodeWithCoder(DS_Dictionary* dict)`
- `virtual bool canEncode()`
- `void addTags(gd::string tags)`
- `bool containsTag(int tag)`
- `void copyValues(SongInfoObject* object)`
- `gd::string getArtistNames(int unused)`
- `int getExtraArtistCount()`
- `gd::string getTagsString(bool shortTags)`
- `bool init(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, gd::string unknown, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority)`
- `void updateArtists(gd::string artists)`

**Members:**

- `int m_songID`
- `gd::string m_songName`
- `gd::string m_artistName`
- `gd::string m_youtubeVideo`
- `gd::string m_youtubeChannel`
- `gd::string m_songUrl`
- `gd::string m_unkString`
- `int m_artistID`
- `float m_fileSize`
- `int m_nongType`
- `gd::string m_extraArtists`
- `bool m_unloaded`
- `bool m_verified`
- `bool m_isBlocked`
- `int m_priority`
- `int m_unkInt`
- `int m_BPM`
- `bool m_isNew`
- `int m_libraryOrder`
- `int m_songOrder`
- `gd::string m_extraArtistNames`
- `gd::unordered_set<int> m_artistIDs`
- `gd::set<int> m_tags`
- `gd::string m_longTagsString`
- `gd::string m_shortTagsString`

### `SongObject` : cocos2d::CCObject

**Functions:**

- `SongObject()`
- `static SongObject* create(int audioID)`
- `bool init(int audioID)`

**Members:**

- `int m_audioID`

### `SongOptionsLayer` : FLAlertLayer

**Functions:**

- `SongOptionsLayer()`
- `static SongOptionsLayer* create(CustomSongDelegate* delegate)`
- `virtual void keyBackClicked()`
- `bool init(CustomSongDelegate* delegate)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onFadeIn(cocos2d::CCObject* sender)`
- `void onFadeOut(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onPlayback(cocos2d::CCObject* sender)`
- `void onSongPersistent(cocos2d::CCObject* sender)`
- `void updatePlaybackBtn()`

**Members:**

- `CustomSongDelegate* m_delegate`
- `CCTextInputNode* m_offsetInput`
- `CCMenuItemSpriteExtra* m_playbackButton`

### `SongPlaybackDelegate`

**Functions:**

- `virtual void onPlayback(SongInfoObject* object)`

### `SongSelectNode` : cocos2d::CCNode, FLAlertLayerProtocol, CustomSongLayerDelegate, CustomSongDelegate

**Functions:**

- `static SongSelectNode* create(int id, bool customSong, LevelSettingsObject* settings, SongSelectType selectType, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCMenu* menu, bool noLabel)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `virtual void customSongLayerClosed()`
- `virtual void songIDChanged(int id)`
- `virtual int getActiveSongID()`
- `virtual gd::string getSongFileName()`
- `virtual LevelSettingsObject* getLevelSettings()`
- `void audioNext(cocos2d::CCObject* sender)`
- `void audioPrevious(cocos2d::CCObject* sender)`
- `bool init(int id, bool customSong, LevelSettingsObject* settings, SongSelectType selectType, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCMenu* menu, bool noLabel)`
- `void onOpenCustomSong(cocos2d::CCObject* sender)`
- `void onSongMode(cocos2d::CCObject* sender)`
- `void onSongMode(int songMode)`
- `void selectSong(int id)`
- `void showCustomSongSelect()`
- `void updateAudioLabel()`
- `void updateWidgetVisibility()`

**Members:**

- `int m_selectedSongID`
- `bool m_isCustomSong`
- `bool m_songChanged`
- `cocos2d::CCLabelBMFont* m_audioLabel`
- `cocos2d::CCArray* m_selectSongObjects`
- `cocos2d::CCArray* m_normalSongObjects`
- `cocos2d::CCArray* m_changeSongObjects`
- `CCMenuItemSpriteExtra* m_normalButton`
- `CCMenuItemSpriteExtra* m_customButton`
- `CCMenuItemSpriteExtra* m_selectButton`
- `CCMenuItemSpriteExtra* m_changeButton`
- `CustomSongWidget* m_songWidget`
- `LevelSettingsObject* m_settingsObject`

### `SongTriggerGameObject` : SFXTriggerGameObject

**Functions:**

- `SongTriggerGameObject()`
- `static SongTriggerGameObject* create(char const* frame)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `bool m_unk7a9`
- `bool m_prep`
- `bool m_loadPrep`
- `int m_songChannel`

### `SongsLayer` : GJDropDownLayer

**Functions:**

- `static SongsLayer* create()`
- `virtual void customSetup()`

### `SpawnParticleGameObject` : EffectGameObject

**Functions:**

- `SpawnParticleGameObject()`
- `static SpawnParticleGameObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `cocos2d::CCPoint m_offset`
- `cocos2d::CCPoint m_offsetVariance`
- `bool m_matchRotation`
- `float m_rotation`
- `float m_rotationVariance`
- `float m_scale`
- `float m_scaleVariance`

### `SpawnTriggerAction`

**Functions:**

- `SpawnTriggerAction()`
- `SpawnTriggerAction(GameObject* object, float delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `SpawnTriggerAction(int targetID, float delay, bool spawnOrdered, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`
- `bool isFinished()`
- `void step(float dt)`

**Members:**

- `bool m_finished`
- `bool m_disabled`
- `double m_duration`
- `double m_deltaTime`
- `int m_targetGroupID`
- `int m_triggerUniqueID`
- `int m_controlID`
- `bool m_spawnOrdered`
- `GameObject* m_gameObject`
- `gd::vector<int> m_remapKeys`

### `SpawnTriggerGameObject` : EffectGameObject

**Functions:**

- `SpawnTriggerGameObject()`
- `static SpawnTriggerGameObject* create()`
- `virtual bool init()`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `void addRemap(int oldID, int newID)`
- `void changeRemap(int oldID, int newID, bool reverse)`
- `ChanceObject* getRemapWithSource(int id)`
- `ChanceObject* getRemapWithTarget(int id)`
- `void removeRemap(int oldID, int newID)`
- `void updateRemapKeys(gd::vector<int> const& remapKeys)`

**Members:**

- `gd::vector<ChanceObject> m_remapObjects`
- `int m_remapKey`
- `gd::vector<int> m_remapKeys`
- `double m_currentDelay`
- `float m_spawnDelay`
- `float m_delayRange`
- `bool m_resetRemap`

### `SpecialAnimGameObject` : EnhancedGameObject

**Functions:**

- `SpecialAnimGameObject()`
- `static SpecialAnimGameObject* create(char const* frame)`
- `virtual void resetObject()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void updateMainColor(cocos2d::ccColor3B const& color)`
- `virtual void updateSecondaryColor(cocos2d::ccColor3B const& color)`
- `virtual void updateSyncedAnimation(float totalTime, int frameIndex)`
- `bool init(char const* frame)`

**Members:**

- `bool m_skipMainColorUpdate`
- `bool m_skipSecondaryColorUpdate`

### `SpriteAnimationManager` : cocos2d::CCNode

**Functions:**

- `SpriteAnimationManager()`
- `~SpriteAnimationManager()`
- `static void createAnimations(gd::string definition)`
- `static SpriteAnimationManager* createWithOwner(CCAnimatedSprite* sprite, gd::string definition)`
- `void animationFinished()`
- `void callAnimationFinished()`
- `void doCleanup()`
- `void executeAnimation(gd::string animation)`
- `void finishAnimation(gd::string animation)`
- `spriteMode getAnimType(gd::string animation)`
- `int getPrio(gd::string animation)`
- `bool initWithOwner(CCAnimatedSprite* sprite, gd::string definition)`
- `void loadAnimations(gd::string definition)`
- `void offsetCurrentAnimation(float dt)`
- `void overridePrio()`
- `void playSound(gd::string sound)`
- `void playSoundForAnimation(gd::string animation)`
- `void queueAnimation(gd::string animation)`
- `void resetAnimState()`
- `void runAnimation(gd::string animation)`
- `void runQueuedAnimation()`
- `void stopAnimations()`
- `void storeAnimation(cocos2d::CCAnimate* action, cocos2d::CCAnimate* frames, gd::string name, int priority, spriteMode type, cocos2d::CCSpriteFrame* first)`
- `void storeSoundForAnimation(cocos2d::CCString* sound, gd::string animation, float delay)`
- `void switchToFirstFrameOfAnimation(gd::string animation)`
- `void updateAnimationSpeed(float speed)`

**Members:**

- `CCAnimatedSprite* m_sprite`
- `cocos2d::CCDictionary* m_priorityDict`
- `cocos2d::CCDictionary* m_typeDict`
- `cocos2d::CCDictionary* m_soundDict`
- `gd::string m_queuedAnimation`
- `float m_speed`
- `cocos2d::CCDictionary* m_animateDict`
- `cocos2d::CCDictionary* m_frameDict`
- `gd::string m_currentAnimation`
- `gd::string m_nextAnimation`

### `SpriteDescription` : cocos2d::CCObject

**Functions:**

- `SpriteDescription()`
- `~SpriteDescription()`
- `static SpriteDescription* createDescription(DS_Dictionary* dict)`
- `static SpriteDescription* createDescription(cocos2d::CCDictionary* dict)`
- `bool initDescription(DS_Dictionary* dict)`
- `bool initDescription(cocos2d::CCDictionary* dict)`

**Members:**

- `cocos2d::CCPoint m_position`
- `cocos2d::CCPoint m_scale`
- `cocos2d::CCPoint m_flipped`
- `float m_rotation`
- `int m_zValue`
- `int m_tag`
- `bool m_usesCustomTag`
- `cocos2d::CCSpriteFrame* m_texture`

### `SpritePartDelegate`

**Functions:**

- `virtual void displayFrameChanged(cocos2d::CCObject* sprite, gd::string frameName)`

### `StarInfoPopup` : FLAlertLayer

**Functions:**

- `static StarInfoPopup* create(int autos, int easies, int normals, int hards, int harders, int insanes, int dailies, int gauntlets, int maps, bool platformer)`
- `static StarInfoPopup* createFromString(gd::string str)`
- `static StarInfoPopup* createFromStringMoons(gd::string str)`
- `virtual void keyBackClicked()`
- `bool init(int autos, int easies, int normals, int hards, int harders, int insanes, int dailies, int gauntlets, int maps, bool platformer)`
- `void onClose(cocos2d::CCObject* sender)`

### `StartPosObject` : EffectGameObject

**Functions:**

- `StartPosObject()`
- `~StartPosObject()`
- `static StartPosObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `void loadSettingsFromString(gd::string objectString)`
- `void setSettings(LevelSettingsObject* settings)`

**Members:**

- `LevelSettingsObject* m_startSettings`

### `StatsCell` : TableViewCell

**Functions:**

- `StatsCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `const char* getTitleFromKey(char const* key)`
- `void loadFromObject(StatsObject* object)`
- `void updateBGColor(int index)`

### `StatsLayer` : GJDropDownLayer

**Functions:**

- `StatsLayer()`
- `static StatsLayer* create()`
- `virtual void customSetup()`

### `StatsObject` : cocos2d::CCObject

**Functions:**

- `static StatsObject* create(char const* key, int value)`
- `bool init(char const* key, int value)`

**Members:**

- `const char* m_key`
- `int m_value`

### `SupportLayer` : GJDropDownLayer, FLAlertLayerProtocol, UploadActionDelegate, UploadPopupDelegate

**Functions:**

- `SupportLayer()`
- `~SupportLayer()`
- `static SupportLayer* create()`
- `virtual void customSetup()`
- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`
- `virtual void onClosePopup(UploadActionPopup* popup)`
- `virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2)`
- `CCMenuItemToggler* createToggleButton(gd::string text, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCArray* nodes)`
- `void exitLayer()`
- `void onCocos2d(cocos2d::CCObject* sender)`
- `void onEmail(cocos2d::CCObject* sender)`
- `void onGetReward(cocos2d::CCObject* sender)`
- `void onLinks(cocos2d::CCObject* sender)`
- `void onLowDetail(cocos2d::CCObject* sender)`
- `void onPrivacy(cocos2d::CCObject* sender)`
- `void onRequestAccess(cocos2d::CCObject* sender)`
- `void onRobTop(cocos2d::CCObject* sender)`
- `void onSFX(cocos2d::CCObject* sender)`
- `void onTOS(cocos2d::CCObject* sender)`
- `void sendSupportMail()`

**Members:**

- `UploadActionPopup* m_uploadPopup`

### `TOSPopup` : FLAlertLayer

**Functions:**

- `TOSPopup()`
- `static TOSPopup* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void onClose(cocos2d::CCObject* sender)`
- `void onPrivacy(cocos2d::CCObject* sender)`
- `void onTOS(cocos2d::CCObject* sender)`

### `TableView` : CCScrollLayerExt, CCScrollLayerExtDelegate

**Functions:**

- `TableView(cocos2d::CCRect rect)`
- `~TableView()`
- `static TableView* create(TableViewDelegate* tvd, TableViewDataSource* tvds, TableViewCellDelegate* tvcd, cocos2d::CCRect rect)`
- `virtual void onEnter()`
- `virtual void onExit()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void scrollWheel(float y, float x)`
- `virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt* layer)`
- `virtual void scrollViewDidEndDecelerating(CCScrollLayerExt* layer)`
- `virtual void scrollViewTouchMoving(CCScrollLayerExt* layer)`
- `virtual void scrollViewDidEndMoving(CCScrollLayerExt* layer)`
- `void cancelAndStoleTouch(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `TableViewCell* cellForRowAtIndexPath(CCIndexPath& path)`
- `TableViewCell* cellForTouch(cocos2d::CCTouch* touch)`
- `int checkBoundaryOfCell(TableViewCell* cell)`
- `int checkBoundaryOfCell(cocos2d::CCPoint& position, float height)`
- `void checkBoundaryOfContent(float dt)`
- `void checkFirstCell(TableViewCell* cell)`
- `void checkLastCell(TableViewCell* cell)`
- `void claimTouch(cocos2d::CCTouch* touch)`
- `void deleteTableViewCell(TableViewCell* cell)`
- `bool dequeueReusableCellWithIdentifier(char const* identifier)`
- `void initTableViewCells()`
- `bool isDuplicateIndexPath(CCIndexPath& path)`
- `bool isDuplicateInVisibleCellArray(CCIndexPath* path)`
- `void reloadData()`
- `bool removeIndexPathFromPathAddedArray(CCIndexPath& path)`
- `void scrollToIndexPath(CCIndexPath& path)`
- `void touchFinish(cocos2d::CCTouch* touch)`

**Members:**

- `bool m_scheduled`
- `cocos2d::CCTouch* m_beginTouch`
- `cocos2d::CCPoint m_beginLocation`
- `cocos2d::CCPoint m_lastCellPos`
- `cocos2d::CCPoint m_checkLocation`
- `TableViewCell* m_touchedCell`
- `bool m_touchMoved`
- `bool m_isTouch`
- `cocos2d::CCArray* m_cellArray`
- `cocos2d::CCArray* m_cellRemovedArray`
- `cocos2d::CCArray* m_indexPathArray`
- `TableViewDelegate* m_tableDelegate`
- `TableViewDataSource* m_dataSource`
- `TableViewCellDelegate* m_cellDelegate`
- `bool m_unused2`
- `void* m_unused3`
- `int m_unused4`
- `float m_touchLastY`
- `bool m_cancellingTouches`
- `bool m_idk2`

### `TableViewCell` : cocos2d::CCLayer

**Functions:**

- `TableViewCell(char const* identifier, float width, float height)`
- `~TableViewCell()`
- `void updateVisibility()`

**Members:**

- `void* m_unknown`
- `TableView* m_tableView`
- `CCIndexPath m_indexPath`
- `void* m_unknown2`
- `gd::string m_cellIdentifier`
- `float m_width`
- `float m_height`
- `cocos2d::CCLayerColor* m_backgroundLayer`
- `cocos2d::CCLayer* m_mainLayer`
- `BoomListType m_listType`

### `TableViewCellDelegate`

**Functions:**

- `virtual bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent)`
- `virtual int getSelectedCellIdx()`
- `virtual bool shouldSnapToSelected()`
- `virtual int getCellDelegateType()`

### `TableViewDataSource`

**Functions:**

- `virtual int numberOfRowsInSection(unsigned int section, TableView* tableView)`
- `virtual unsigned int numberOfSectionsInTableView(TableView* tableView)`
- `virtual void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView* tableView, TableViewCellEditingStyle style, CCIndexPath& indexPath)`
- `virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView)`

### `TableViewDelegate`

**Functions:**

- `virtual void willTweenToIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView)`
- `virtual void didEndTweenToIndexPath(CCIndexPath& indexPath, TableView* tableView)`
- `virtual void TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView)`
- `virtual void TableViewDidDisplayCellForRowAtIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView)`
- `virtual void TableViewWillReloadCellForRowAtIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView)`
- `virtual float cellHeightForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView)`
- `virtual void didSelectRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView)`

### `TeleportPortalObject` : RingObject

**Functions:**

- `TeleportPortalObject()`
- `static TeleportPortalObject* create(char const* frame, bool trigger)`
- `virtual void setPosition(cocos2d::CCPoint const& position)`
- `virtual void setRotation(float rotation)`
- `virtual void setStartPos(cocos2d::CCPoint position)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual int addToGroup(int id)`
- `virtual void removeFromGroup(int id)`
- `virtual void setRotation2(float rotation)`
- `virtual void addToGroup2(int id)`
- `virtual void removeFromGroup2(int id)`
- `float getTeleportXOff(cocos2d::CCNode* parent)`
- `bool init(char const* frame, bool trigger)`
- `void setPositionOverride(cocos2d::CCPoint position)`
- `void setStartPosOverride(cocos2d::CCPoint position)`

**Members:**

- `TeleportPortalObject* m_orangePortal`
- `bool m_isYellowPortal`
- `float m_teleportYOffset`
- `bool m_teleportEase`
- `bool m_staticForceEnabled`
- `float m_staticForce`
- `bool m_redirectForceEnabled`
- `float m_redirectForceMod`
- `float m_redirectForceMin`
- `float m_redirectForceMax`
- `bool m_saveOffset`
- `bool m_ignoreX`
- `bool m_ignoreY`
- `int m_gravityMode`
- `bool m_staticForceAdditive`
- `bool m_instantCamera`
- `bool m_snapGround`
- `bool m_redirectDash`
- `cocos2d::CCPoint m_teleportPosition`

### `TextAlertPopup` : cocos2d::CCNode

**Functions:**

- `static TextAlertPopup* create(gd::string text, float delay, float scale, int opacity, gd::string font)`
- `bool init(gd::string text, float delay, float scale, int opacity, gd::string font)`
- `void setAlertPosition(cocos2d::CCPoint windowOffset, cocos2d::CCPoint pointOffset)`
- `void setLabelColor(cocos2d::ccColor3B color)`

**Members:**

- `float m_width`
- `float m_height`
- `cocos2d::CCLabelBMFont* m_label`

### `TextArea` : cocos2d::CCSprite

**Functions:**

- `static TextArea* create(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor)`
- `virtual void update(float dt)`
- `virtual void draw()`
- `virtual void setOpacity(unsigned char opacity)`
- `void colorAllCharactersTo(cocos2d::ccColor3B color)`
- `void colorAllLabels(cocos2d::ccColor3B color)`
- `float fadeIn(float duration, bool unused)`
- `float fadeInCharacters(float duration, float charDuration, bool fadeOut, TextFadeInStyle style)`
- `void fadeOut(float duration)`
- `void fadeOutAndRemove()`
- `void finishFade()`
- `void hideAll()`
- `bool init(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor)`
- `void setIgnoreColorCode(bool ignore)`
- `void setString(gd::string text)`
- `void showAll()`
- `void stopAllCharacterActions()`

**Members:**

- `bool m_disableColor`
- `MultilineBitmapFont* m_label`
- `float m_width`
- `float m_unknown`
- `gd::string m_fontFile`
- `float m_height`
- `bool m_unkBool`
- `cocos2d::CCPoint m_anchorPoint`
- `bool m_allShown`
- `float m_scale`
- `int m_rectHeight`
- `int m_rectWidth`
- `float m_maxWidth`
- `cocos2d::CCPoint m_unkPoint`
- `TextAreaDelegate* m_delegate`
- `cocos2d::CCDictionary* m_shakeCharacters`
- `float m_shakeElapsed`

### `TextAreaDelegate`

**Functions:**

- `virtual void fadeInTextFinished(TextArea* textArea)`

### `TextGameObject` : GameObject

**Functions:**

- `TextGameObject()`
- `static TextGameObject* create(cocos2d::CCTexture2D* texture)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `virtual void updateTextKerning(int kerning)`
- `virtual int getTextKerning()`
- `bool init(cocos2d::CCTexture2D* texture)`
- `void updateTextObject(gd::string text, bool defaultFont)`

**Members:**

- `gd::string m_text`
- `int m_kerning`

### `TextInputDelegate`

**Functions:**

- `virtual void textChanged(CCTextInputNode* node)`
- `virtual void textInputOpened(CCTextInputNode* node)`
- `virtual void textInputClosed(CCTextInputNode* node)`
- `virtual void textInputShouldOffset(CCTextInputNode* node, float yOffset)`
- `virtual void textInputReturn(CCTextInputNode* node)`
- `virtual bool allowTextInput(CCTextInputNode* node)`
- `virtual void enterPressed(CCTextInputNode* node)`

### `TextStyleSection` : cocos2d::CCObject

**Functions:**

- `static TextStyleSection* create(int start, int end, TextStyleType type)`
- `static TextStyleSection* createColoredSection(cocos2d::ccColor3B color, int start, int end)`
- `static TextStyleSection* createDelaySection(int start, float delay)`
- `static TextStyleSection* createInstantSection(int start, int end, float duration)`
- `static TextStyleSection* createShakeSection(int start, int end, int intensity, int perSecond)`
- `bool init(int start, int end, TextStyleType type)`

**Members:**

- `TextStyleType m_styleType`
- `int m_startIndex`
- `int m_endIndex`
- `cocos2d::ccColor3B m_color`
- `float m_instantTime`
- `float m_delay`
- `int m_shakeIntensity`
- `int m_shakesPerSecond`

### `TimerTriggerAction`

**Functions:**

- `TimerTriggerAction()`
- `TimerTriggerAction(int targetID, float targetTime, bool multiActivate, int itemID, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`

**Members:**

- `bool m_disabled`
- `float m_time`
- `float m_targetTime`
- `int m_targetGroupID`
- `int m_triggerUniqueID`
- `int m_controlID`
- `int m_itemID`
- `bool m_multiActivate`
- `gd::vector<int> m_remapKeys`

### `TimerTriggerGameObject` : EffectGameObject

**Functions:**

- `TimerTriggerGameObject()`
- `static TimerTriggerGameObject* create(char const* frame)`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `double m_startTime`
- `double m_targetTime`
- `bool m_stopTimeEnabled`
- `bool m_dontOverride`
- `bool m_ignoreTimeWarp`
- `float m_timeMod`
- `bool m_startPaused`
- `bool m_multiActivate`
- `int m_controlType`

### `ToggleTriggerAction`

**Functions:**

- `ToggleTriggerAction()`
- `ToggleTriggerAction(int targetID, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`

**Members:**

- `bool m_disabled`
- `int m_targetGroupID`
- `bool m_activateGroup`
- `int m_triggerUniqueID`
- `int m_controlID`
- `gd::vector<int> m_remapKeys`

### `TopArtistsLayer` : FLAlertLayer, OnlineListDelegate

**Functions:**

- `TopArtistsLayer()`
- `~TopArtistsLayer()`
- `static TopArtistsLayer* create()`
- `virtual bool init()`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void loadListFinished(cocos2d::CCArray* objects, char const* key)`
- `virtual void loadListFailed(char const* key)`
- `virtual void setupPageInfo(gd::string info, char const* key)`
- `bool isCorrect(char const* key)`
- `void loadPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onNextPage(cocos2d::CCObject* sender)`
- `void onPrevPage(cocos2d::CCObject* sender)`
- `void setupLeaderboard(cocos2d::CCArray* artists)`
- `void updateLevelsLabel()`

**Members:**

- `cocos2d::CCArray* m_topArtists`
- `GJCommentListLayer* m_listLayer`
- `LoadingCircle* m_loadingCircle`
- `CCMenuItemSpriteExtra* m_nextButton`
- `CCMenuItemSpriteExtra* m_prevButton`
- `void* m_unkPtr`
- `cocos2d::CCLabelBMFont* m_pageInfoLabel`
- `int m_itemCount`
- `int m_pageStartIdx`
- `int m_pageEndIdx`
- `int m_unkSize4`
- `int m_page`

### `TouchToggleAction`

**Functions:**

- `TouchToggleAction()`
- `TouchToggleAction(int targetID, bool holdMode, TouchTriggerType touchType, TouchTriggerControl touchControl, bool dualMode, gd::vector<int> const& remapKeys, int uniqueID, int controlID)`

**Members:**

- `bool m_disabled`
- `int m_targetGroupID`
- `bool m_holdMode`
- `TouchTriggerType m_touchTriggerType`
- `TouchTriggerControl m_touchTriggerControl`
- `int m_triggerUniqueID`
- `int m_controlID`
- `bool m_dualMode`
- `gd::vector<int> m_remapKeys`

### `TransformTriggerGameObject` : EffectGameObject

**Functions:**

- `TransformTriggerGameObject()`
- `static TransformTriggerGameObject* create(char const* frame)`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`

**Members:**

- `float m_objectScaleX`
- `float m_objectScaleY`
- `float m_property450`
- `float m_property451`
- `bool m_onlyMove`
- `bool m_divideX`
- `bool m_divideY`
- `bool m_relativeRotation`
- `bool m_relativeScale`

### `TriggerControlGameObject` : EffectGameObject

**Functions:**

- `TriggerControlGameObject()`
- `static TriggerControlGameObject* create(char const* frame)`
- `virtual void triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys)`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`
- `bool init(char const* frame)`
- `void updateTriggerControlFrame()`

**Members:**

- `gd::string m_triggerControlFrame`
- `GJActionCommand m_customTriggerValue`

### `TriggerEffectDelegate`

**Functions:**

- `virtual void toggleGroupTriggered(int group, bool activate, gd::vector<int> const& remapKeys, int triggerID, int controlID)`
- `virtual void spawnGroup(int group, bool ordered, double delay, gd::vector<int> const& remapKeys, int triggerID, int controlID)`
- `virtual void spawnObject(GameObject* object, double delay, gd::vector<int> const& remapKeys)`
- `[[missing(win, mac)]]`
- `virtual bool checkSpawnAbuse()`

### `TutorialLayer` : FLAlertLayer

**Functions:**

- `static TutorialLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `void loadPage(int page)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onNext(cocos2d::CCObject* sender)`
- `void removeTutorialTexture()`

**Members:**

- `cocos2d::CCLayer* m_tutorialLayer`
- `int m_page`
- `CCMenuItemSpriteExtra* m_nextButton`
- `CCMenuItemSpriteExtra* m_exitButton`

### `TutorialPopup` : FLAlertLayer

**Functions:**

- `static TutorialPopup* create(gd::string frame)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `void animateMenu()`
- `void closeTutorial(cocos2d::CCObject* sender)`
- `bool init(gd::string frame)`
- `void registerForCallback(cocos2d::SEL_MenuHandler selector, cocos2d::CCNode* target)`

**Members:**

- `gd::string m_currentSprite`
- `bool m_callbackRegistered`
- `cocos2d::SEL_MenuHandler m_callbackSelector`
- `cocos2d::CCNode* m_targetNode`
- `CCMenuItemSpriteExtra* m_closeButton`

### `UIButtonConfig`

**Functions:**

- `void reset()`
- `void resetOneBtn()`

**Members:**

- `int m_width`
- `int m_height`
- `float m_deadzone`
- `float m_scale`
- `int m_opacity`
- `float m_radius`
- `bool m_modeB`
- `bool m_snap`
- `cocos2d::CCPoint m_position`
- `bool m_oneButton`
- `bool m_player2`
- `bool m_split`

### `UILayer` : cocos2d::CCLayerColor

**Functions:**

- `UILayer()`
- `~UILayer()`
- `static UILayer* create(GJBaseGameLayer* layer)`
- `static UILayer* get()`
- `virtual void draw()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void keyBackClicked()`
- `virtual void keyDown(cocos2d::enumKeyCodes key, double timestamp)`
- `virtual void keyUp(cocos2d::enumKeyCodes key, double timestamp)`
- `void disableMenu()`
- `void doPause()`
- `void editorPlaytest(bool visible)`
- `void enableEditorMode()`
- `void enableMenu()`
- `void handleKeypress(cocos2d::enumKeyCodes key, bool down, double timestamp)`
- `bool init(GJBaseGameLayer* layer)`
- `bool isJumpButtonPressed()`
- `bool isJumpButtonPressed(bool player1)`
- `void onCheck(cocos2d::CCObject* sender)`
- `void onDeleteCheck(cocos2d::CCObject* sender)`
- `void onPause(cocos2d::CCObject* sender)`
- `bool processUINodesTouch(GJUITouchEvent event, cocos2d::CCTouch* touch)`
- `bool processUINodeTouch(GJUITouchEvent event, int touchID, cocos2d::CCPoint position, GJUINode* node, double timestamp)`
- `void refreshDpad()`
- `void resetAllButtons()`
- `void resetUINodeState()`
- `void toggleCheckpointsMenu(bool visible)`
- `void toggleMenuVisibility(bool visible)`
- `void togglePlatformerMode(bool platformer)`
- `void updateCheckState()`
- `void updateDualMode(bool dual)`
- `void updateUINodeVisibility(bool visible)`

**Members:**

- `void* m_stupidDelegate`
- `void* m_pUnknown1`
- `cocos2d::CCMenu* m_checkpointMenu`
- `CCMenuItemSpriteExtra* m_pauseBtn`
- `bool m_bUnknown2`
- `bool m_bUnknown3`
- `bool m_p1Jumping`
- `bool m_p2Jumping`
- `bool m_checkpointBtnDown`
- `int m_p1TouchId`
- `int m_p2TouchId`
- `float m_clkTimer`
- `bool m_inPlatformer`
- `GJBaseGameLayer* m_gameLayer`
- `bool m_initialized`
- `cocos2d::CCArray* m_uiNodes`
- `bool m_dualMode`
- `bool m_dpadType`
- `bool m_editorMode`
- `cocos2d::CCArray* m_controllerButtons`

### `UIObjectSettingsPopup` : SetupTriggerPopup

**Functions:**

- `static UIObjectSettingsPopup* create(UISettingsGameObject* object, cocos2d::CCArray* objects)`
- `virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender)`
- `bool init(UISettingsGameObject* object, cocos2d::CCArray* objects)`

### `UIOptionsLayer` : SetupTriggerPopup

**Functions:**

- `static UIOptionsLayer* create(bool dual)`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float getValue(int tag)`
- `GJUINode* getNode(int type)`
- `bool init(bool dual)`
- `void onReset(cocos2d::CCObject* sender)`
- `void onSaveLoad(cocos2d::CCObject* sender)`
- `void toggleUIGroup(int group)`

**Members:**

- `bool m_dual`
- `GJUINode* m_uiNode1`
- `GJUINode* m_uiNode2`
- `GJUINode* m_uiNode3`
- `GJUINode* m_uiNode4`
- `cocos2d::CCLabelBMFont* m_nameLabel`
- `int m_activeUIGroup`

### `UIPOptionsLayer` : SetupTriggerPopup

**Functions:**

- `UIPOptionsLayer()`
- `static UIPOptionsLayer* create()`
- `virtual bool init()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)`
- `virtual void registerWithTouchDispatcher()`
- `virtual void onClose(cocos2d::CCObject* sender)`
- `virtual void valueDidChange(int tag, float value)`
- `virtual float getValue(int tag)`
- `cocos2d::CCRect getTouchRect()`
- `void onReset(cocos2d::CCObject* sender)`

**Members:**

- `int m_touchID`
- `cocos2d::CCNode* m_practiceNode`
- `cocos2d::CCPoint m_touchPosition`
- `cocos2d::CCPoint m_touchDelta`

### `UISaveLoadLayer` : SetupTriggerPopup

**Functions:**

- `UISaveLoadLayer()`
- `static UISaveLoadLayer* create(UIOptionsLayer* layer)`
- `bool init(UIOptionsLayer* layer)`
- `void onLoad(cocos2d::CCObject* sender)`
- `void onSave(cocos2d::CCObject* sender)`

**Members:**

- `UIOptionsLayer* m_optionsLayer`

### `UISettingsGameObject` : EffectGameObject

**Functions:**

- `UISettingsGameObject()`
- `static UISettingsGameObject* create()`
- `virtual bool init()`
- `virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists)`
- `virtual gd::string getSaveString(GJBaseGameLayer* layer)`

**Members:**

- `int m_xRef`
- `int m_yRef`
- `bool m_xRelative`
- `bool m_yRelative`

### `URLCell` : TableViewCell

**Functions:**

- `URLCell(char const* identifier, float width, float height)`
- `virtual bool init()`
- `virtual void draw()`
- `void loadFromObject(CCURLObject* object)`
- `void onURL(cocos2d::CCObject* sender)`
- `void updateBGColor(int index)`

**Members:**

- `CCURLObject* m_urlObject`

### `URLViewLayer` : GJDropDownLayer

**Functions:**

- `static URLViewLayer* create(gd::string title, cocos2d::CCArray* objects)`
- `bool init(gd::string title, cocos2d::CCArray* objects)`

**Members:**

- `cocos2d::CCArray* m_urlObjects`

### `UndoObject` : cocos2d::CCObject

**Functions:**

- `UndoObject()`
- `~UndoObject()`
- `static UndoObject* create(GameObject* object, UndoCommand command)`
- `static UndoObject* createWithArray(cocos2d::CCArray* array, UndoCommand command)`
- `static UndoObject* createWithTransformObjects(cocos2d::CCArray* objects, UndoCommand command)`
- `bool init(GameObject* object, UndoCommand command)`
- `bool init(cocos2d::CCArray* array, UndoCommand command)`
- `bool initWithTransformObjects(cocos2d::CCArray* objects, UndoCommand command)`
- `void setObjects(cocos2d::CCArray* objects)`

**Members:**

- `GameObjectCopy* m_objectCopy`
- `UndoCommand m_command`
- `cocos2d::CCArray* m_objects`
- `bool m_redo`
- `bool m_undoTransform`
- `GJTransformState m_transformState`

### `UpdateAccountSettingsPopup` : FLAlertLayer, GJAccountSettingsDelegate

**Functions:**

- `UpdateAccountSettingsPopup()`
- `~UpdateAccountSettingsPopup()`
- `static UpdateAccountSettingsPopup* create(GJAccountSettingsLayer* settingsLayer, int messageStatus, int friendStatus, int commentStatus, gd::string youtubeURL, gd::string twitterURL, gd::string twitchURL, gd::string instagramURL, gd::string tiktokURL, gd::string discordUsername, gd::string customString)`
- `virtual void keyBackClicked()`
- `virtual void updateSettingsFinished()`
- `virtual void updateSettingsFailed()`
- `bool init(GJAccountSettingsLayer* settingsLayer, int messageStatus, int friendStatus, int commentStatus, gd::string youtubeURL, gd::string twitterURL, gd::string twitchURL, gd::string instagramURL, gd::string tiktokURL, gd::string discordUsername, gd::string customString)`
- `void onClose(cocos2d::CCObject* sender)`

**Members:**

- `bool m_updateSuccess`
- `GJAccountSettingsLayer* m_settingsLayer`
- `TextArea* m_textArea`
- `LoadingCircle* m_loadingCircle`
- `CCMenuItemSpriteExtra* m_closeButton`

### `UploadActionDelegate`

**Functions:**

- `virtual void uploadActionFinished(int id, int response)`
- `virtual void uploadActionFailed(int id, int response)`

### `UploadActionPopup` : FLAlertLayer

**Functions:**

- `static UploadActionPopup* create(UploadPopupDelegate* delegate, gd::string str)`
- `virtual void keyBackClicked()`
- `void closePopup()`
- `bool init(UploadPopupDelegate* delegate, gd::string str)`
- `void onClose(cocos2d::CCObject* sender)`
- `void showFailMessage(gd::string message)`
- `void showSuccessMessage(gd::string message)`

**Members:**

- `UploadPopupDelegate* m_delegate`
- `TextArea* m_textArea`
- `LoadingCircle* m_loadingCircle`
- `CCMenuItemSpriteExtra* m_closeButton`
- `bool m_succeeded`

### `UploadListPopup` : FLAlertLayer, ListUploadDelegate

**Functions:**

- `UploadListPopup()`
- `~UploadListPopup()`
- `static UploadListPopup* create(GJLevelList* list)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void listUploadFinished(GJLevelList* list)`
- `virtual void listUploadFailed(GJLevelList* list, int response)`
- `bool init(GJLevelList* list)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onReturnToList(cocos2d::CCObject* sender)`

**Members:**

- `GJLevelList* m_levelList`
- `TextArea* m_textArea`
- `LoadingCircle* m_loadingCircle`
- `CCMenuItemSpriteExtra* m_backButton`

### `UploadMessageDelegate`

**Functions:**

- `virtual void uploadMessageFinished(int accountID)`
- `virtual void uploadMessageFailed(int accountID)`

### `UploadPopup` : FLAlertLayer, LevelUploadDelegate

**Functions:**

- `UploadPopup()`
- `~UploadPopup()`
- `static UploadPopup* create(GJGameLevel* level)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `virtual void levelUploadFinished(GJGameLevel* level)`
- `virtual void levelUploadFailed(GJGameLevel* level)`
- `bool init(GJGameLevel* level)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onReturnToLevel(cocos2d::CCObject* sender)`

**Members:**

- `GJGameLevel* m_level`
- `TextArea* m_textArea`
- `LoadingCircle* m_loadingCircle`
- `CCMenuItemSpriteExtra* m_backButton`

### `UploadPopupDelegate`

**Functions:**

- `virtual void onClosePopup(UploadActionPopup* popup)`

### `UserInfoDelegate`

**Functions:**

- `virtual void getUserInfoFinished(GJUserScore* score)`
- `virtual void getUserInfoFailed(int id)`
- `virtual void userInfoChanged(GJUserScore* score)`

### `UserListDelegate`

**Functions:**

- `virtual void getUserListFinished(cocos2d::CCArray* scores, UserListType type)`
- `virtual void getUserListFailed(UserListType type, GJErrorCode errorType)`
- `virtual void userListChanged(cocos2d::CCArray* scores, UserListType type)`
- `virtual void forceReloadList(UserListType type)`

### `VideoOptionsLayer` : FLAlertLayer

**Functions:**

- `static VideoOptionsLayer* create()`
- `virtual bool init()`
- `virtual void keyBackClicked()`
- `CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position, float scale, float width, bool center, cocos2d::CCArray* nodes)`
- `void onAdvanced(cocos2d::CCObject* sender)`
- `void onApply(cocos2d::CCObject* sender)`
- `void onBorderless(cocos2d::CCObject* sender)`
- `void onBorderlessFix(cocos2d::CCObject* sender)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onFullscreen(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onResolutionNext(cocos2d::CCObject* sender)`
- `void onResolutionPrev(cocos2d::CCObject* sender)`
- `void onTextureQualityNext(cocos2d::CCObject* sender)`
- `void onTextureQualityPrev(cocos2d::CCObject* sender)`
- `void reloadMenu()`
- `void toggleResolution()`
- `void updateResolution(int resolution)`
- `void updateTextureQuality(int quality)`

**Members:**

- `CCMenuItemSpriteExtra* m_prevResolutionBtn`
- `CCMenuItemSpriteExtra* m_nextResolutionBtn`
- `cocos2d::CCLabelBMFont* m_windowedResolutionLabel`
- `cocos2d::CCLabelBMFont* m_selectedResolutionLabel`
- `cocos2d::CCLabelBMFont* m_qualityLabel`
- `int m_textureQuality`
- `cocos2d::CCArray* m_availableResolutions`
- `CCMenuItemToggler* m_borderlessToggle`
- `cocos2d::CCLabelBMFont* m_borderlessLabel`
- `CCMenuItemToggler* m_fixToggle`
- `cocos2d::CCLabelBMFont* m_fixLabel`
- `bool m_fullscreen`
- `bool m_borderless`
- `bool m_fix`
- `int m_currentResolution`

### `WorldLevelPage` : FLAlertLayer

**Functions:**

- `static WorldLevelPage* create(GJGameLevel* level, GJWorldNode* node)`
- `virtual void keyBackClicked()`
- `virtual void show()`
- `bool init(GJGameLevel* level, GJWorldNode* node)`
- `void onClose(cocos2d::CCObject* sender)`
- `void onInfo(cocos2d::CCObject* sender)`
- `void onPlay(cocos2d::CCObject* sender)`
- `void onSong(cocos2d::CCObject* sender)`

**Members:**

- `GJWorldNode* m_worldNode`
- `GJGameLevel* m_level`

### `WorldSelectLayer` : cocos2d::CCLayer, BoomScrollLayerDelegate

**Functions:**

- `static WorldSelectLayer* create(int page)`
- `static cocos2d::CCScene* scene(int page)`
- `virtual void onExit()`
- `virtual void keyBackClicked()`
- `virtual void scrollLayerWillScrollToPage(BoomScrollLayer* layer, int page)`
- `virtual void scrollLayerScrolledToPage(BoomScrollLayer* layer, int page)`
- `virtual void scrollLayerMoved(cocos2d::CCPoint position)`
- `void animateInActiveIsland()`
- `cocos2d::ccColor3B colorForPage(int page)`
- `cocos2d::ccColor3B getColorValue(int page1, int page2, float progress)`
- `void goToPage(int page, bool instant)`
- `bool init(int page)`
- `void onBack(cocos2d::CCObject* sender)`
- `void onFreeLevels(cocos2d::CCObject* sender)`
- `void onGarage(cocos2d::CCObject* sender)`
- `void onNext(cocos2d::CCObject* sender)`
- `void onPrev(cocos2d::CCObject* sender)`
- `void setupWorlds()`
- `void showCompleteDialog()`
- `void tryShowAd()`
- `void unblockButtons()`
- `void updateArrows()`

**Members:**

- `cocos2d::CCSprite* m_background`
- `BoomScrollLayer* m_scrollLayer`
- `CCMenuItemSpriteExtra* m_arrowLeft`
- `CCMenuItemSpriteExtra* m_arrowRight`
- `bool m_cleanupSprites`
- `bool m_enteringLevel`
- `GJWorldNode* m_worldNode`
- `bool m_buttonsLocked`

## Cocos2d (5 classes)

### `CCContentManager` : cocos2d::CCObject

**Functions:**

- `static CCContentManager* sharedManager()`
- `cocos2d::CCDictionary* addDict(char const*, bool)`
- `cocos2d::CCDictionary* addDictDS(char const*)`
- `void clearCache()`
- `bool init()`

### `DS_Dictionary`

**Functions:**

- `DS_Dictionary()`
- `static void copyFile(char const*, char const*)`
- `void addBoolValuesToMapForKey(gd::map<gd::string, bool>&, char const*, bool)`
- `void addBoolValuesToMapForKeySpecial(gd::map<gd::string, bool>&, char const*, bool)`
- `void checkCompatibility()`
- `gd::string cleanStringWhiteSpace(gd::string const&)`
- `cocos2d::CCObject* decodeObjectForKey(char const*, bool, int)`
- `gd::vector<gd::string> getAllKeys()`
- `cocos2d::CCArray* getArrayForKey(char const*, bool)`
- `bool getBoolForKey(char const*)`
- `cocos2d::CCDictionary* getDictForKey(char const*, bool)`
- `float getFloatForKey(char const*)`
- `unsigned int getIndexOfKey(char const*)`
- `unsigned int getIndexOfKeyWithClosestAlphaNumericalMatch(char const*)`
- `int getIntegerForKey(char const*)`
- `gd::string getKey(unsigned int)`
- `unsigned int getNumKeys()`
- `cocos2d::CCObject* getObjectForKey(char const*)`
- `gd::vector<cocos2d::CCRect> getRectArrayForKey(char const*)`
- `cocos2d::CCRect getRectForKey(char const*)`
- `gd::vector<gd::string> getStringArrayForKey(char const*)`
- `gd::string getStringForKey(char const*)`
- `gd::vector<cocos2d::CCPoint> getVec2ArrayForKey(char const*)`
- `cocos2d::CCPoint getVec2ForKey(char const*)`
- `bool loadRootSubDictFromCompressedFile(char const*)`
- `bool loadRootSubDictFromFile(char const*)`
- `bool loadRootSubDictFromString(gd::string const&)`
- `bool rectFromString(gd::string const&, cocos2d::CCRect&)`
- `void removeAllKeys()`
- `void removeKey(char const*)`
- `void removeKey(unsigned int)`
- `bool saveRootSubDictToCompressedFile(char const*)`
- `bool saveRootSubDictToFile(char const*)`
- `gd::string saveRootSubDictToString()`
- `void setArrayForKey(char const*, cocos2d::CCArray*)`
- `void setBoolForKey(char const*, bool)`
- `void setBoolForKey(char const*, bool, bool)`
- `void setBoolMapForKey(char const*, gd::map<gd::string, bool>&)`
- `void setDictForKey(char const*, cocos2d::CCDictionary*)`
- `void setFloatForKey(char const*, float)`
- `void setFloatForKey(char const*, float, bool)`
- `void setIntegerForKey(char const*, int)`
- `void setIntegerForKey(char const*, int, bool)`
- `void setObjectForKey(char const*, cocos2d::CCObject*)`
- `void setRectArrayForKey(char const*, gd::vector<cocos2d::CCRect> const&)`
- `void setRectArrayForKey(char const*, gd::vector<cocos2d::CCRect> const&, bool)`
- `void setRectForKey(char const*, cocos2d::CCRect const&)`
- `void setRectForKey(char const*, cocos2d::CCRect const&, bool)`
- `void setStringArrayForKey(char const*, gd::vector<gd::string> const&)`
- `void setStringArrayForKey(char const*, gd::vector<gd::string> const&, bool)`
- `void setStringForKey(char const*, gd::string const&)`
- `void setStringForKey(char const*, gd::string const&, bool)`
- `void setSubDictForKey(char const*)`
- `void setSubDictForKey(char const*, bool, bool)`
- `void setVec2ArrayForKey(char const*, gd::vector<cocos2d::CCPoint> const&)`
- `void setVec2ArrayForKey(char const*, gd::vector<cocos2d::CCPoint> const&, bool)`
- `void setVec2ForKey(char const*, cocos2d::CCPoint const&)`
- `void setVec2ForKey(char const*, cocos2d::CCPoint const&, bool)`
- `void split(gd::string const&, char const*, gd::vector<gd::string>&)`
- `bool splitWithForm(gd::string const&, gd::vector<gd::string>&)`
- `void stepBackToRootSubDict()`
- `bool stepIntoSubDictWithKey(char const*)`
- `void stepOutOfSubDict()`
- `bool vec2FromString(gd::string const&, cocos2d::CCPoint&)`

### `ObjectDecoder` : cocos2d::CCNode

**Functions:**

- `static ObjectDecoder* sharedDecoder()`
- `virtual bool init()`
- `cocos2d::CCObject* getDecodedObject(int, DS_Dictionary*)`

### `cocos2d` : :ZipUtils

**Functions:**

- `static gd::string base64DecodeEnc(gd::string const&, gd::string)`
- `static gd::string base64EncodeEnc(gd::string const&, gd::string)`
- `static gd::string base64URLDecode(gd::string const&)`
- `static gd::string base64URLEncode(gd::string const&)`
- `static int ccDeflateMemory(unsigned char* data, unsigned int size, unsigned char** out)`
- `static gd::string compressString(gd::string const& data, bool encrypt, int encryptionKey)`
- `static gd::string decompressString(gd::string const& data, bool encrypt, int encryptionKey)`
- `static gd::string decompressString2(unsigned char* data, bool encrypt, int size, int encryptionKey)`
- `static gd::string encryptDecrypt(gd::string const& data, int encryptionKey)`
- `static gd::string encryptDecryptWKey(gd::string const&, gd::string)`
- `static unsigned char hexToChar(gd::string const&)`
- `static gd::string urlDecode(gd::string const&)`

### `pugi` : :xml_node

**Functions:**

- `xml_node()`
- `~xml_node()`

## Extras (29 classes)

### `AdvancedFollowInstance`

**Functions:**

- `AdvancedFollowInstance() {`

### `CAState`

**Members:**

- `cocos2d::ccColor3B m_fromColor`
- `cocos2d::ccColor3B m_toColor`
- `cocos2d::ccColor3B m_color`
- `bool m_paused`
- `bool m_blending`
- `bool m_copyOpacity`
- `bool m_legacyHSV`
- `int m_playerColor`
- `int m_colorID`
- `int m_copyID`
- `int m_uniqueID`
- `float m_duration`
- `float m_fromOpacity`
- `float m_toOpacity`
- `float m_deltaTime`
- `float m_currentOpacity`
- `cocos2d::ccHSVValue m_copyHSV`

### `ChanceObject`

**Functions:**

- `ChanceObject() {`

### `DynamicMoveCalculation`

**Members:**

- `CCMoveCNode* m_moveNode`
- `cocos2d::CCPoint m_offset`
- `GameObject* m_gameObject`

### `DynamicObjectAction`

**Functions:**

- `DynamicObjectAction() {`

### `EnterEffectAnimValue`

**Members:**

- `int m_key`
- `float m_value`
- `float m_distance`
- `float m_duration`
- `float m_elapsed`
- `EasingType m_easingType`
- `float m_easingRate`
- `int m_easingBuffer`

### `EventTriggerInstance`

**Members:**

- `int m_targetID`
- `int m_uniqueID`
- `int m_controlID`
- `bool m_inactive`
- `gd::vector<int> m_remapKeys`

### `FMODQueuedMusic`

**Members:**

- `gd::string m_filePath`
- `float m_pitch`
- `float m_unkFloat2`
- `float m_volume`
- `int m_start`
- `int m_end`
- `int m_fadeIn`
- `int m_fadeOut`
- `bool m_loop`
- `int m_musicID`
- `bool m_stopMusic`
- `int m_channelID`
- `bool m_noPrepare`
- `int m_queuedStatus`
- `FMOD::Sound* m_sound`
- `bool m_dontReset`

### `FMODSound`

**Members:**

- `FMOD::Sound* m_sound`
- `gd::string m_filePath`
- `int m_length`
- `int m_playCount`
- `int m_playIndex`
- `bool m_preloaded`

### `FMODSoundState`

**Members:**

- `gd::string m_filePath`
- `float m_speed`
- `float m_unkFloat1`
- `float m_volume`
- `bool m_shouldLoop`
- `int m_channelID`
- `SoundStateContainer m_soundStateContainer`
- `int m_uniqueID`
- `int m_sfxGroup`
- `float m_pitch`
- `bool m_fastFourierTransform`
- `bool m_reverb`
- `int m_effectID`
- `bool m_isMusic`
- `int m_musicID`
- `bool m_unkBool2`

### `FMODSoundTween`

**Members:**

- `float m_interval`
- `float m_duration`
- `float m_start`
- `float m_end`
- `float m_value`
- `bool m_finished`

### `GJPointDouble`

**Members:**

- `double m_x`
- `double m_y`

### `GJTransformState`

**Functions:**

- `GJTransformState() {`

**Members:**

- `m_scaleX = 1.f`
- `m_scaleY = 1.f`
- `m_angleX = 0.f`
- `m_angleY = 0.f`
- `m_skewX = 0.f`
- `m_skewY = 0.f`
- `m_transformRotation = 0.f`
- `m_transformReset = false`
- `m_transformRotationX = 0.f`
- `m_transformRotationY = 0.f`
- `m_transformScaleX = 1.f`
- `m_transformScaleY = 1.f`

### `GameObjectPhysics`

**Members:**

- `GameObject* m_gameObject`
- `cocos2d::CCPoint m_unkPoint1`
- `cocos2d::CCPoint m_unkPoint2`
- `float m_unkFloat1`
- `float m_unkFloat2`
- `int m_unkInt1`
- `int m_unkInt2`
- `int m_unkInt3`

### `RecordButtonCommand`

**Members:**

- `PlayerButton m_button`
- `bool m_isPush`
- `bool m_isPlayer2`
- `int m_step`
- `int m_unk00c`

### `RecordCheckpoint`

**Members:**

- `int m_index`
- `int m_step`
- `uint64_t m_seed`
- `int m_attempts`
- `int m_ticks`
- `uint64_t m_time`
- `int m_clicks`
- `int m_points`
- `gd::string m_inputs`

### `SFXStateContainer`

**Members:**

- `double m_unkDouble1`
- `double m_unkDouble2`
- `float m_unkFloat1`
- `float m_unkFloat2`
- `bool m_unkBool`

### `SFXTriggerInstance`

**Members:**

- `int m_groupID1`
- `int m_groupID2`
- `int m_controlID`
- `SFXTriggerGameObject* m_sfxTriggerGameObject`

### `SFXTriggerState`

**Members:**

- `SFXTriggerGameObject* m_sfxTriggerGameObject`
- `int m_unkInt1`
- `double m_unkDouble1`
- `double m_unkDouble2`
- `double m_unkDouble3`
- `double m_unkDouble4`
- `float m_unkFloat1`
- `float m_unkFloat2`
- `float m_unkFloat3`
- `float m_unkFloat4`
- `int m_unkInt2`
- `bool m_processed`
- `bool m_unkBool1`
- `std::array<SFXStateContainer, 3> m_sfxStateContainers`

### `SavedActiveObjectState`

**Members:**

- `GameObject* m_gameObject`
- `bool m_activatedByPlayer1`
- `bool m_activatedByPlayer2`

### `SavedObjectStateRef`

**Members:**

- `GameObject* m_gameObject`
- `double m_positionX`
- `double m_positionY`
- `float m_rotationXOffset`
- `float m_rotationYOffset`
- `float m_addToCustomScaleX`
- `float m_addToCustomScaleY`
- `float m_unkFloat3`
- `float m_unkFloat4`

### `SavedSpecialObjectState`

**Members:**

- `GameObject* m_gameObject`
- `int m_animationID`

### `SequenceTriggerState`

**Members:**

- `gd::unordered_map<int, float> m_sequenceTimes`
- `gd::unordered_map<int, int> m_sequenceIndices`

### `SmartPrefabResult`

**Members:**

- `GJSmartPrefab* m_smartPrefab`
- `gd::string m_binaryKey`
- `gd::string m_prefabKey`
- `int m_prefabCount`
- `bool m_unrequired`
- `int m_rotation`
- `bool m_flipX`
- `bool m_flipY`
- `bool m_ignoreCorners`

### `SongChannelState`

**Members:**

- `SongTriggerGameObject* m_songTriggerGameObject1`
- `double m_unkDouble1`
- `SongTriggerGameObject* m_songTriggerGameObject2`
- `double m_unkDouble2`

### `SongTriggerState`

**Members:**

- `SongTriggerGameObject* m_songTriggerGameObject`
- `double m_unkDouble`

### `SoundStateContainer`

**Members:**

- `int m_fadePointCount`
- `std::array<float, 4> m_fadePointVolumes`
- `std::array<uint64_t, 4> m_fadePointOffsets`
- `uint64_t m_currentOffset`
- `int m_loopStartMs`
- `int m_loopEndMs`
- `int m_currentMs`
- `uint64_t m_playStartOffset`
- `uint64_t m_playEndOffset`
- `int m_usePlayOffsets`

### `TimerItem`

**Members:**

- `int m_itemID`
- `double m_time`
- `bool m_active`
- `float m_timeMod`
- `bool m_ignoreTimeWarp`
- `double m_targetTime`
- `bool m_stopTimeEnabled`
- `int m_targetGroupID`
- `int m_triggerUniqueID`
- `int m_controlID`
- `gd::vector<int> m_remapKeys`
- `bool m_disabled`

### `tk_spline`

**Members:**

- `gd::vector<double> m_x`
- `gd::vector<double> m_y`
- `gd::vector<double> m_b`
- `gd::vector<double> m_c`
- `gd::vector<double> m_d`
- `double m_c0`
- `int m_type`
- `int m_left`
- `int m_right`
- `double m_leftValue`
- `double m_rightValue`
- `bool m_madeMonotonic`

## FMOD (1 classes)

### `FMOD` : :System

**Functions:**

- `FMOD_RESULT getChannel(int, FMOD::Channel**)`
- `FMOD_RESULT getVersion(unsigned int*)`
- `FMOD_RESULT loadPlugin(char const*, unsigned int*, unsigned int)`
- `FMOD_RESULT recordStop(int)`
- `FMOD_RESULT createSound(char const*, unsigned int, FMOD_CREATESOUNDEXINFO*, FMOD::Sound**)`
- `FMOD_RESULT getCPUUsage(FMOD_CPU_USAGE*)`
- `FMOD_RESULT getUserData(void**)`
- `FMOD_RESULT isRecording(int, bool*)`
- `FMOD_RESULT mixerResume()`
- `FMOD_RESULT recordStart(int, FMOD::Sound*, bool)`
- `FMOD_RESULT registerDSP(FMOD_DSP_DESCRIPTION const*, unsigned int*)`
- `FMOD_RESULT setCallback(FMOD_SYSTEM_CALLBACK, unsigned int)`
- `FMOD_RESULT setUserData(void*)`
- `FMOD_RESULT createStream(char const*, unsigned int, FMOD_CREATESOUNDEXINFO*, FMOD::Sound**)`
- `FMOD_RESULT getFileUsage(long long*, long long*, long long*)`
- `FMOD_RESULT loadGeometry(void const*, int, FMOD::Geometry**)`
- `FMOD_RESULT mixerSuspend()`
- `FMOD_RESULT unloadPlugin(unsigned int)`
- `FMOD_RESULT get3DSettings(float*, float*, float*)`
- `FMOD_RESULT getDriverInfo(int, char*, int, FMOD_GUID*, int*, FMOD_SPEAKERMODE*, int*)`
- `FMOD_RESULT getNumDrivers(int*)`
- `FMOD_RESULT getNumPlugins(FMOD_PLUGINTYPE, int*)`
- `FMOD_RESULT getPluginInfo(unsigned int, FMOD_PLUGINTYPE*, char*, int, unsigned int*)`
- `FMOD_RESULT registerCodec(FMOD_CODEC_DESCRIPTION*, unsigned int*, unsigned int)`
- `FMOD_RESULT set3DSettings(float, float, float)`
- `FMOD_RESULT setFileSystem(FMOD_FILE_OPEN_CALLBACK, FMOD_FILE_CLOSE_CALLBACK, FMOD_FILE_READ_CALLBACK, FMOD_FILE_SEEK_CALLBACK, FMOD_FILE_ASYNCREAD_CALLBACK, FMOD_FILE_ASYNCCANCEL_CALLBACK, int)`
- `FMOD_RESULT setPluginPath(char const*)`
- `FMOD_RESULT createGeometry(int, int, FMOD::Geometry**)`
- `FMOD_RESULT createReverb3D(FMOD::Reverb3D**)`
- `FMOD_RESULT registerOutput(FMOD_OUTPUT_DESCRIPTION const*, unsigned int*)`
- `FMOD_RESULT createDSPByType(FMOD_DSP_TYPE, FMOD::DSP**)`
- `FMOD_RESULT getNestedPlugin(unsigned int, int, unsigned int*)`
- `FMOD_RESULT getNetworkProxy(char*, int)`
- `FMOD_RESULT getOutputHandle(void**)`
- `FMOD_RESULT getPluginHandle(FMOD_PLUGINTYPE, int, unsigned int*)`
- `FMOD_RESULT setNetworkProxy(char const*)`
- `FMOD_RESULT attachFileSystem(FMOD_FILE_OPEN_CALLBACK, FMOD_FILE_CLOSE_CALLBACK, FMOD_FILE_READ_CALLBACK, FMOD_FILE_SEEK_CALLBACK)`
- `FMOD_RESULT createSoundGroup(char const*, FMOD::SoundGroup**)`
- `FMOD_RESULT getDSPBufferSize(unsigned int*, int*)`
- `FMOD_RESULT getDSPInfoByType(FMOD_DSP_TYPE, FMOD_DSP_DESCRIPTION const**)`
- `FMOD_RESULT setDSPBufferSize(unsigned int, int)`
- `FMOD_RESULT createDSPByPlugin(unsigned int, FMOD::DSP**)`
- `FMOD_RESULT get3DNumListeners(int*)`
- `FMOD_RESULT getNetworkTimeout(int*)`
- `FMOD_RESULT getOutputByPlugin(unsigned int*)`
- `FMOD_RESULT getRecordPosition(int, unsigned int*)`
- `FMOD_RESULT getSoftwareFormat(int*, FMOD_SPEAKERMODE*, int*)`
- `FMOD_RESULT set3DNumListeners(int)`
- `FMOD_RESULT setNetworkTimeout(int)`
- `FMOD_RESULT setOutputByPlugin(unsigned int)`
- `FMOD_RESULT setSoftwareFormat(int, FMOD_SPEAKERMODE, int)`
- `FMOD_RESULT createChannelGroup(char const*, FMOD::ChannelGroup**)`
- `FMOD_RESULT getChannelsPlaying(int*, int*)`
- `FMOD_RESULT getDSPInfoByPlugin(unsigned int, FMOD_DSP_DESCRIPTION const**)`
- `FMOD_RESULT getSpeakerPosition(FMOD_SPEAKER, float*, float*, bool*)`
- `FMOD_RESULT setSpeakerPosition(FMOD_SPEAKER, float, float, bool)`
- `FMOD_RESULT getAdvancedSettings(FMOD_ADVANCEDSETTINGS*)`
- `FMOD_RESULT getDefaultMixMatrix(FMOD_SPEAKERMODE, FMOD_SPEAKERMODE, float*, int)`
- `FMOD_RESULT getGeometrySettings(float*)`
- `FMOD_RESULT getMasterSoundGroup(FMOD::SoundGroup**)`
- `FMOD_RESULT getNumNestedPlugins(unsigned int, int*)`
- `FMOD_RESULT getRecordDriverInfo(int, char*, int, FMOD_GUID*, int*, FMOD_SPEAKERMODE*, int*, unsigned int*)`
- `FMOD_RESULT getRecordNumDrivers(int*, int*)`
- `FMOD_RESULT getReverbProperties(int, FMOD_REVERB_PROPERTIES*)`
- `FMOD_RESULT getSoftwareChannels(int*)`
- `FMOD_RESULT getStreamBufferSize(unsigned int*, unsigned int*)`
- `FMOD_RESULT setAdvancedSettings(FMOD_ADVANCEDSETTINGS*)`
- `FMOD_RESULT setGeometrySettings(float)`
- `FMOD_RESULT setReverbProperties(int, FMOD_REVERB_PROPERTIES const*)`
- `FMOD_RESULT setSoftwareChannels(int)`
- `FMOD_RESULT setStreamBufferSize(unsigned int, unsigned int)`
- `FMOD_RESULT getGeometryOcclusion(FMOD_VECTOR const*, FMOD_VECTOR const*, float*, float*)`
- `FMOD_RESULT set3DRolloffCallback(FMOD_3D_ROLLOFF_CALLBACK)`
- `FMOD_RESULT getMasterChannelGroup(FMOD::ChannelGroup**)`
- `FMOD_RESULT getSpeakerModeChannels(FMOD_SPEAKERMODE, int*)`
- `FMOD_RESULT get3DListenerAttributes(int, FMOD_VECTOR*, FMOD_VECTOR*, FMOD_VECTOR*, FMOD_VECTOR*)`
- `FMOD_RESULT set3DListenerAttributes(int, FMOD_VECTOR const*, FMOD_VECTOR const*, FMOD_VECTOR const*, FMOD_VECTOR const*)`
- `FMOD_RESULT attachChannelGroupToPort(FMOD_PORT_TYPE, unsigned long long, FMOD::ChannelGroup*, bool)`
- `FMOD_RESULT detachChannelGroupFromPort(FMOD::ChannelGroup*)`
- `FMOD_RESULT init(int, unsigned int, void*)`
- `FMOD_RESULT close()`
- `FMOD_RESULT update()`
- `FMOD_RESULT lockDSP()`
- `FMOD_RESULT playDSP(FMOD::DSP*, FMOD::ChannelGroup*, bool, FMOD::Channel**)`
- `FMOD_RESULT release()`
- `FMOD_RESULT createDSP(FMOD_DSP_DESCRIPTION const*, FMOD::DSP**)`
- `FMOD_RESULT getDriver(int*)`
- `FMOD_RESULT getOutput(FMOD_OUTPUTTYPE*)`
- `FMOD_RESULT playSound(FMOD::Sound*, FMOD::ChannelGroup*, bool, FMOD::Channel**)`
- `FMOD_RESULT setDriver(int)`
- `FMOD_RESULT setOutput(FMOD_OUTPUTTYPE)`
- `FMOD_RESULT unlockDSP()`

## Geode SDK (83 classes)

### `AnchorLayout` : public Layout

**Functions:**

- `static AnchorLayout* create()`
- `void apply(cocos2d::CCNode* on) override`
- `cocos2d::CCSize getSizeHint(cocos2d::CCNode* on) const override`
- `static cocos2d::CCPoint getAnchoredPosition(cocos2d::CCNode* in, Anchor anchor, cocos2d::CCPoint const& offset)`
- `static AnchorLayout* create()`
- `void apply(cocos2d::CCNode* on) override`
- `cocos2d::CCSize getSizeHint(cocos2d::CCNode* on) const override`
- `static cocos2d::CCPoint getAnchoredPosition(cocos2d::CCNode* in, Anchor anchor, cocos2d::CCPoint const& offset)`

### `AxisLayout` : public Layout

**Functions:**

- `static AxisLayout* create(Axis axis = Axis::Row)`
- `virtual ~AxisLayout()`
- `void apply(cocos2d::CCNode* on) override`
- `cocos2d::CCSize getSizeHint(cocos2d::CCNode* on) const override`
- `Axis getAxis() const`
- `AxisAlignment getAxisAlignment() const`
- `AxisAlignment getCrossAxisAlignment() const`
- `AxisAlignment getCrossAxisLineAlignment() const`
- `float getGap() const`
- `bool getAxisReverse() const`
- `bool getCrossAxisReverse() const`
- `bool getAutoScale() const`
- `bool getGrowCrossAxis() const`
- `bool getCrossAxisOverflow() const`
- `std::optional<float> getAutoGrowAxis() const`
- `float getDefaultMinScale() const`
- `float getDefaultMaxScale() const`
- `Padding getPadding() const`
- `AxisLayout* setAxis(Axis axis)`
- `AxisLayout* setAxisAlignment(AxisAlignment align)`
- `AxisLayout* setCrossAxisAlignment(AxisAlignment align)`
- `AxisLayout* setCrossAxisLineAlignment(AxisAlignment align)`
- `AxisLayout* setGap(float gap)`
- `AxisLayout* setAxisReverse(bool reverse)`
- `AxisLayout* setCrossAxisReverse(bool reverse)`
- `AxisLayout* setAutoScale(bool enable)`
- `AxisLayout* setGrowCrossAxis(bool expand)`
- `AxisLayout* setCrossAxisOverflow(bool allow)`
- `AxisLayout* setAutoGrowAxis(std::optional<float> allowAndMinLength)`
- `AxisLayout* setDefaultScaleLimits(float min, float max)`
- `AxisLayout* ignoreInvisibleChildren(bool ignore = true)`
- `bool isIgnoreInvisibleChildren() const`
- `AxisLayout* setPadding(Padding const& padding)`

### `BaseFilter`

**Functions:**

- `virtual ~BaseFilter() noexcept = default`
- `virtual size_t hash() const noexcept = 0`
- `virtual BaseFilter* clone() const noexcept = 0`
- `virtual OpaquePortBase* getPort() const noexcept = 0`
- `virtual ~BaseFilter() noexcept = default`
- `virtual size_t hash() const noexcept = 0`
- `virtual BaseFilter* clone() const noexcept = 0`
- `virtual OpaquePortBase* getPort() const noexcept = 0`

### `BaseSeedValue`

**Functions:**

- `public: BaseSeedValue() = default`

### `BasedButtonSprite` : public cocos2d::CCSprite

**Functions:**

- `static BasedButtonSprite* create( cocos2d::CCNode* ontop, BaseType type, int size, int color )`
- `void setTopOffset(cocos2d::CCPoint const& offset)`
- `void setTopRelativeScale(float scale)`
- `cocos2d::CCNode* getTopNode() const`

### `BasicObserver`

**Functions:**

- `public: BasicObserver() noexcept = default`
- `if constexpr (ThreadSafe)`
- `std::lock_guard<std::mutex> guard(other.mutex)`
- `std::lock_guard<std::mutex> guard2(mutex)`
- `std::lock_guard<std::mutex> guard(mutex)`
- `if constexpr (ThreadSafe)`
- `std::lock_guard<std::mutex> guard(other.mutex)`
- `std::lock_guard<std::mutex> guard2(mutex)`
- `std::lock_guard<std::mutex> guard(mutex)`

### `BasicStringBuffer`

**Functions:**

- `ViewType view() const`
- `StringType str() const`
- `CharType* c_str()`
- `CharType* data()`
- `void append(CharType c)`
- `void append(ViewType fmtStr)`
- `void append(T value)`
- `void append(fmt::format_string<Args...> fmtStr, Args&&... args)`
- `void terminate()`
- `size_t size() const`
- `ViewType view() const`
- `StringType str() const`
- `CharType* c_str()`
- `CharType* data()`
- `void append(CharType c)`
- `void append(ViewType fmtStr)`
- `void append(T value)`
- `void append(fmt::format_string<Args...> fmtStr, Args&&... args)`
- `void terminate()`
- `size_t size() const`

### `BasicZStringView`

**Functions:**

- `if constexpr (std::is_same_v<C, char>)`
- `else if constexpr (std::is_same_v<C, wchar_t>)`
- `else if constexpr (std::is_same_v<C, char8_t>)`
- `else if constexpr (std::is_same_v<C, char16_t>)`
- `else if constexpr (std::is_same_v<C, char32_t>)`
- `endif BasicZStringView(BasicZStringView const& other) = default`
- `C const* c_str() const`
- `C const* data() const`
- `std::basic_string_view<C> view() const`
- `size_t size() const`
- `return _size()`
- `size_t length() const`
- `return _size()`
- `bool empty() const`
- `auto begin() const`
- `auto end() const`
- `if constexpr (std::is_same_v<C, char>)`
- `else if constexpr (std::is_same_v<C, wchar_t>)`
- `else if constexpr (std::is_same_v<C, char8_t>)`
- `else if constexpr (std::is_same_v<C, char16_t>)`
- `else if constexpr (std::is_same_v<C, char32_t>)`
- `endif BasicZStringView(BasicZStringView const& other) = default`
- `C const* c_str() const`
- `C const* data() const`
- `std::basic_string_view<C> view() const`
- `size_t size() const`
- `return _size()`
- `size_t length() const`
- `return _size()`
- `bool empty() const`
- `auto begin() const`
- `auto end() const`

### `Border` : public cocos2d::CCLayerColor

**Functions:**

- `static Border* create(cocos2d::CCNode* node, const cocos2d::ccColor4B& backgroundColor, const cocos2d::CCSize& size =`
- `void setPadding(const cocos2d::CCPoint& padding)`
- `void setPadding(float x, float y)`
- `void setPadding(float padding)`
- `Padding getPadding()`
- `void setPaddingX(float x)`
- `float getPaddingX()`
- `void setPaddingY(float y)`
- `float getPaddingY()`
- `void setPaddingTop(float top)`
- `float getPaddingTop()`
- `void setPaddingRight(float right)`
- `float getPaddingRight()`
- `void setPaddingBottom(float bottom)`
- `float getPaddingBottom()`
- `void setPaddingLeft(float left)`
- `float getPaddingLeft()`
- `void setBackgroundColor(const cocos2d::ccColor4B& color)`
- `cocos2d::ccColor4B getBackgroundColor()`
- `void setNode(CCNode* node)`
- `CCNode* getNode()`
- `void setSize(const cocos2d::CCSize& size)`
- `static Border* create(cocos2d::CCNode* node, const cocos2d::ccColor4B& backgroundColor, const cocos2d::CCSize& size =`
- `void setPadding(const cocos2d::CCPoint& padding)`
- `void setPadding(float x, float y)`
- `void setPadding(float padding)`
- `Padding getPadding()`
- `void setPaddingX(float x)`
- `float getPaddingX()`
- `void setPaddingY(float y)`
- `float getPaddingY()`
- `void setPaddingTop(float top)`
- `float getPaddingTop()`
- `void setPaddingRight(float right)`
- `float getPaddingRight()`
- `void setPaddingBottom(float bottom)`
- `float getPaddingBottom()`
- `void setPaddingLeft(float left)`
- `float getPaddingLeft()`
- `void setBackgroundColor(const cocos2d::ccColor4B& color)`
- `cocos2d::ccColor4B getBackgroundColor()`
- `void setNode(CCNode* node)`
- `CCNode* getNode()`
- `void setSize(const cocos2d::CCSize& size)`

### `BreakLine` : public cocos2d::CCNode

**Functions:**

- `static BreakLine* create( float width, float height = 1.f, cocos2d::ccColor4F color = )`
- `cocos2d::ccColor4F getColor()`

### `Button` : public cocos2d::CCNodeRGBA, public cocos2d::CCTouchDelegate

**Functions:**

- `static Button* create(ButtonCallback activateCallback = nullptr)`
- `static Button* createWithNode(cocos2d::CCNode* node, ButtonCallback activateCallback = nullptr)`
- `static Button* createWithSprite(geode::ZStringView fileName, ButtonCallback activateCallback = nullptr)`
- `static Button* createWithSpriteFrameName(geode::ZStringView frameName, ButtonCallback activateCallback = nullptr)`
- `static Button* createWithLabel(geode::ZStringView text, geode::ZStringView font, ButtonCallback activateCallback = nullptr)`
- `cocos2d::CCNode* getDisplayNode()`
- `void setAnimationType(AnimationType type)`
- `AnimationType getAnimationType()`
- `void setClickAnimation(cocos2d::CCActionInterval* action)`
- `void setReleaseAnimation(cocos2d::CCActionInterval* action)`
- `void setActivateCallback(ButtonCallback callback)`
- `void setSelectCallback(ButtonCallback callback)`
- `void setUnselectCallback(ButtonCallback callback)`
- `void setTouchPriority(int priority)`
- `int getTouchPriority()`
- `void setTouchMultiplier(float multipler)`
- `float getTouchMultiplier()`
- `void setScaleMultiplier(float multiplier)`
- `float getScaleMultiplier()`
- `void setMoveOffset(cocos2d::CCPoint const& offset)`
- `cocos2d::CCPoint getMoveOffset()`
- `void setSelectedDuration(float duration)`
- `float getSelectedDuration()`
- `void setUnselectedDuration(float duration)`
- `float getUnselectedDuration()`
- `virtual void setEnabled(bool enabled)`
- `virtual bool isEnabled()`
- `virtual bool isSelected()`
- `virtual void onEnter() override`
- `virtual void onExit() override`
- `virtual void selected()`
- `virtual void unselected()`
- `virtual void activate()`
- `virtual void registerWithTouchDispatcher()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `static Button* create(ButtonCallback activateCallback = nullptr)`
- `static Button* createWithNode(cocos2d::CCNode* node, ButtonCallback activateCallback = nullptr)`
- `static Button* createWithSprite(geode::ZStringView fileName, ButtonCallback activateCallback = nullptr)`
- `static Button* createWithSpriteFrameName(geode::ZStringView frameName, ButtonCallback activateCallback = nullptr)`
- `static Button* createWithLabel(geode::ZStringView text, geode::ZStringView font, ButtonCallback activateCallback = nullptr)`
- `cocos2d::CCNode* getDisplayNode()`
- `void setAnimationType(AnimationType type)`
- `AnimationType getAnimationType()`
- `void setClickAnimation(cocos2d::CCActionInterval* action)`
- `void setReleaseAnimation(cocos2d::CCActionInterval* action)`
- `void setActivateCallback(ButtonCallback callback)`
- `void setSelectCallback(ButtonCallback callback)`
- `void setUnselectCallback(ButtonCallback callback)`
- `void setTouchPriority(int priority)`
- `int getTouchPriority()`
- `void setTouchMultiplier(float multipler)`
- `float getTouchMultiplier()`
- `void setScaleMultiplier(float multiplier)`
- `float getScaleMultiplier()`
- `void setMoveOffset(cocos2d::CCPoint const& offset)`
- `cocos2d::CCPoint getMoveOffset()`
- `void setSelectedDuration(float duration)`
- `float getSelectedDuration()`
- `void setUnselectedDuration(float duration)`
- `float getUnselectedDuration()`
- `virtual void setEnabled(bool enabled)`
- `virtual bool isEnabled()`
- `virtual bool isSelected()`
- `virtual void onEnter() override`
- `virtual void onExit() override`
- `virtual void selected()`
- `virtual void unselected()`
- `virtual void activate()`
- `virtual void registerWithTouchDispatcher()`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`

### `CCArrayExt`

**Functions:**

- `noexcept : m_arr(a.m_arr)`
- `T** begin() const`
- `T** end() const`
- `auto rbegin() const`
- `auto rend() const`
- `size_t size() const`
- `void push_back(T* item)`
- `T* pop_back()`
- `cocos2d::CCArray* inner()`
- `Cont<Elem> to() const`
- `auto toVector() const`
- `bool empty() const`
- `T* front() const`
- `T* back() const`

### `CallFuncExtImpl` : public cocos2d::CCActionInstant

**Functions:**

- `static CallFuncExtImpl* create(const F& func)`
- `new CallFuncExtImpl(func)`
- `static CallFuncExtImpl* create(F&& func)`
- `static CallFuncExtImpl* create(const F& func)`
- `new CallFuncExtImpl(func)`
- `static CallFuncExtImpl* create(F&& func)`

### `Channel` : public ChannelControl

**Functions:**

- `FMOD_RESULT F_API setFrequency (float frequency)`
- `FMOD_RESULT F_API getFrequency (float *frequency)`
- `FMOD_RESULT F_API setPriority (int priority)`
- `FMOD_RESULT F_API getPriority (int *priority)`
- `FMOD_RESULT F_API setPosition (unsigned int position, FMOD_TIMEUNIT postype)`
- `FMOD_RESULT F_API getPosition (unsigned int *position, FMOD_TIMEUNIT postype)`
- `FMOD_RESULT F_API setChannelGroup (ChannelGroup *channelgroup)`
- `FMOD_RESULT F_API getChannelGroup (ChannelGroup **channelgroup)`
- `FMOD_RESULT F_API setLoopCount (int loopcount)`
- `FMOD_RESULT F_API getLoopCount (int *loopcount)`
- `FMOD_RESULT F_API setLoopPoints (unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype)`
- `FMOD_RESULT F_API getLoopPoints (unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype)`
- `FMOD_RESULT F_API isVirtual (bool *isvirtual)`
- `FMOD_RESULT F_API getCurrentSound (Sound **sound)`
- `FMOD_RESULT F_API getIndex (int *index)`

### `ChannelControl`

**Functions:**

- `FMOD_RESULT F_API getSystemObject (System **system)`
- `FMOD_RESULT F_API stop ()`
- `FMOD_RESULT F_API setPaused (bool paused)`
- `FMOD_RESULT F_API getPaused (bool *paused)`
- `FMOD_RESULT F_API setVolume (float volume)`
- `FMOD_RESULT F_API getVolume (float *volume)`
- `FMOD_RESULT F_API setVolumeRamp (bool ramp)`
- `FMOD_RESULT F_API getVolumeRamp (bool *ramp)`
- `FMOD_RESULT F_API getAudibility (float *audibility)`
- `FMOD_RESULT F_API setPitch (float pitch)`
- `FMOD_RESULT F_API getPitch (float *pitch)`
- `FMOD_RESULT F_API setMute (bool mute)`
- `FMOD_RESULT F_API getMute (bool *mute)`
- `FMOD_RESULT F_API setReverbProperties (int instance, float wet)`
- `FMOD_RESULT F_API getReverbProperties (int instance, float *wet)`
- `FMOD_RESULT F_API setLowPassGain (float gain)`
- `FMOD_RESULT F_API getLowPassGain (float *gain)`
- `FMOD_RESULT F_API setMode (FMOD_MODE mode)`
- `FMOD_RESULT F_API getMode (FMOD_MODE *mode)`
- `FMOD_RESULT F_API setCallback (FMOD_CHANNELCONTROL_CALLBACK callback)`
- `FMOD_RESULT F_API isPlaying (bool *isplaying)`
- `FMOD_RESULT F_API setPan (float pan)`
- `FMOD_RESULT F_API setMixLevelsOutput (float frontleft, float frontright, float center, float lfe, float surroundleft, float surroundright, float backleft, float backright)`
- `FMOD_RESULT F_API setMixLevelsInput (float *levels, int numlevels)`
- `FMOD_RESULT F_API setMixMatrix (float *matrix, int outchannels, int inchannels, int inchannel_hop = 0)`
- `FMOD_RESULT F_API getMixMatrix (float *matrix, int *outchannels, int *inchannels, int inchannel_hop = 0)`
- `FMOD_RESULT F_API getDSPClock (unsigned long long *dspclock, unsigned long long *parentclock)`
- `FMOD_RESULT F_API setDelay (unsigned long long dspclock_start, unsigned long long dspclock_end, bool stopchannels = true)`
- `FMOD_RESULT F_API getDelay (unsigned long long *dspclock_start, unsigned long long *dspclock_end, bool *stopchannels = 0)`
- `FMOD_RESULT F_API addFadePoint (unsigned long long dspclock, float volume)`
- `FMOD_RESULT F_API setFadePointRamp (unsigned long long dspclock, float volume)`
- `FMOD_RESULT F_API removeFadePoints (unsigned long long dspclock_start, unsigned long long dspclock_end)`
- `FMOD_RESULT F_API getFadePoints (unsigned int *numpoints, unsigned long long *point_dspclock, float *point_volume)`
- `FMOD_RESULT F_API getDSP (int index, DSP **dsp)`
- `FMOD_RESULT F_API addDSP (int index, DSP *dsp)`
- `FMOD_RESULT F_API removeDSP (DSP *dsp)`
- `FMOD_RESULT F_API getNumDSPs (int *numdsps)`
- `FMOD_RESULT F_API setDSPIndex (DSP *dsp, int index)`
- `FMOD_RESULT F_API getDSPIndex (DSP *dsp, int *index)`
- `FMOD_RESULT F_API set3DAttributes (const FMOD_VECTOR *pos, const FMOD_VECTOR *vel)`
- `FMOD_RESULT F_API get3DAttributes (FMOD_VECTOR *pos, FMOD_VECTOR *vel)`
- `FMOD_RESULT F_API set3DMinMaxDistance (float mindistance, float maxdistance)`
- `FMOD_RESULT F_API get3DMinMaxDistance (float *mindistance, float *maxdistance)`
- `FMOD_RESULT F_API set3DConeSettings (float insideconeangle, float outsideconeangle, float outsidevolume)`
- `FMOD_RESULT F_API get3DConeSettings (float *insideconeangle, float *outsideconeangle, float *outsidevolume)`
- `FMOD_RESULT F_API set3DConeOrientation (FMOD_VECTOR *orientation)`
- `FMOD_RESULT F_API get3DConeOrientation (FMOD_VECTOR *orientation)`
- `FMOD_RESULT F_API set3DCustomRolloff (FMOD_VECTOR *points, int numpoints)`
- `FMOD_RESULT F_API get3DCustomRolloff (FMOD_VECTOR **points, int *numpoints)`
- `FMOD_RESULT F_API set3DOcclusion (float directocclusion, float reverbocclusion)`
- `FMOD_RESULT F_API get3DOcclusion (float *directocclusion, float *reverbocclusion)`
- `FMOD_RESULT F_API set3DSpread (float angle)`
- `FMOD_RESULT F_API get3DSpread (float *angle)`
- `FMOD_RESULT F_API set3DLevel (float level)`
- `FMOD_RESULT F_API get3DLevel (float *level)`
- `FMOD_RESULT F_API set3DDopplerLevel (float level)`
- `FMOD_RESULT F_API get3DDopplerLevel (float *level)`
- `FMOD_RESULT F_API set3DDistanceFilter (bool custom, float customLevel, float centerFreq)`
- `FMOD_RESULT F_API get3DDistanceFilter (bool *custom, float *customLevel, float *centerFreq)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`

### `ChannelGroup` : public ChannelControl

**Functions:**

- `FMOD_RESULT F_API release ()`
- `FMOD_RESULT F_API addGroup (ChannelGroup *group, bool propagatedspclock = true, DSPConnection **connection = 0)`
- `FMOD_RESULT F_API getNumGroups (int *numgroups)`
- `FMOD_RESULT F_API getGroup (int index, ChannelGroup **group)`
- `FMOD_RESULT F_API getParentGroup (ChannelGroup **group)`
- `FMOD_RESULT F_API getName (char *name, int namelen)`
- `FMOD_RESULT F_API getNumChannels (int *numchannels)`
- `FMOD_RESULT F_API getChannel (int index, Channel **channel)`

### `ColorPickPopup` : public Popup,
        public cocos2d::extension::ColorPickerDelegate,
        public TextInputDelegate

**Functions:**

- `static ColorPickPopup* create(bool isRGBA)`
- `static ColorPickPopup* create(cocos2d::ccColor3B const& color)`
- `static ColorPickPopup* create(cocos2d::ccColor4B const& color)`
- `void setColorTarget(cocos2d::CCSprite* spr)`

### `DSP`

**Functions:**

- `FMOD_RESULT F_API release ()`
- `FMOD_RESULT F_API getSystemObject (System **system)`
- `FMOD_RESULT F_API addInput (DSP *input, DSPConnection **connection = 0, FMOD_DSPCONNECTION_TYPE type = FMOD_DSPCONNECTION_TYPE_STANDARD)`
- `FMOD_RESULT F_API disconnectFrom (DSP *target, DSPConnection *connection = 0)`
- `FMOD_RESULT F_API disconnectAll (bool inputs, bool outputs)`
- `FMOD_RESULT F_API getNumInputs (int *numinputs)`
- `FMOD_RESULT F_API getNumOutputs (int *numoutputs)`
- `FMOD_RESULT F_API getInput (int index, DSP **input, DSPConnection **inputconnection)`
- `FMOD_RESULT F_API getOutput (int index, DSP **output, DSPConnection **outputconnection)`
- `FMOD_RESULT F_API setActive (bool active)`
- `FMOD_RESULT F_API getActive (bool *active)`
- `FMOD_RESULT F_API setBypass (bool bypass)`
- `FMOD_RESULT F_API getBypass (bool *bypass)`
- `FMOD_RESULT F_API setWetDryMix (float prewet, float postwet, float dry)`
- `FMOD_RESULT F_API getWetDryMix (float *prewet, float *postwet, float *dry)`
- `FMOD_RESULT F_API setChannelFormat (FMOD_CHANNELMASK channelmask, int numchannels, FMOD_SPEAKERMODE source_speakermode)`
- `FMOD_RESULT F_API getChannelFormat (FMOD_CHANNELMASK *channelmask, int *numchannels, FMOD_SPEAKERMODE *source_speakermode)`
- `FMOD_RESULT F_API getOutputChannelFormat (FMOD_CHANNELMASK inmask, int inchannels, FMOD_SPEAKERMODE inspeakermode, FMOD_CHANNELMASK *outmask, int *outchannels, FMOD_SPEAKERMODE *outspeakermode)`
- `FMOD_RESULT F_API reset ()`
- `FMOD_RESULT F_API setCallback (FMOD_DSP_CALLBACK callback)`
- `FMOD_RESULT F_API setParameterFloat (int index, float value)`
- `FMOD_RESULT F_API setParameterInt (int index, int value)`
- `FMOD_RESULT F_API setParameterBool (int index, bool value)`
- `FMOD_RESULT F_API setParameterData (int index, void *data, unsigned int length)`
- `FMOD_RESULT F_API getParameterFloat (int index, float *value, char *valuestr, int valuestrlen)`
- `FMOD_RESULT F_API getParameterInt (int index, int *value, char *valuestr, int valuestrlen)`
- `FMOD_RESULT F_API getParameterBool (int index, bool *value, char *valuestr, int valuestrlen)`
- `FMOD_RESULT F_API getParameterData (int index, void **data, unsigned int *length, char *valuestr, int valuestrlen)`
- `FMOD_RESULT F_API getNumParameters (int *numparams)`
- `FMOD_RESULT F_API getParameterInfo (int index, FMOD_DSP_PARAMETER_DESC **desc)`
- `FMOD_RESULT F_API getDataParameterIndex (int datatype, int *index)`
- `FMOD_RESULT F_API showConfigDialog (void *hwnd, bool show)`
- `FMOD_RESULT F_API getInfo (char *name, unsigned int *version, int *channels, int *configwidth, int *configheight)`
- `FMOD_RESULT F_API getType (FMOD_DSP_TYPE *type)`
- `FMOD_RESULT F_API getIdle (bool *idle)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`
- `FMOD_RESULT F_API setMeteringEnabled (bool inputEnabled, bool outputEnabled)`
- `FMOD_RESULT F_API getMeteringEnabled (bool *inputEnabled, bool *outputEnabled)`
- `FMOD_RESULT F_API getMeteringInfo (FMOD_DSP_METERING_INFO *inputInfo, FMOD_DSP_METERING_INFO *outputInfo)`
- `FMOD_RESULT F_API getCPUUsage (unsigned int *exclusive, unsigned int *inclusive)`

### `DSPConnection`

**Functions:**

- `FMOD_RESULT F_API getInput (DSP **input)`
- `FMOD_RESULT F_API getOutput (DSP **output)`
- `FMOD_RESULT F_API setMix (float volume)`
- `FMOD_RESULT F_API getMix (float *volume)`
- `FMOD_RESULT F_API setMixMatrix (float *matrix, int outchannels, int inchannels, int inchannel_hop = 0)`
- `FMOD_RESULT F_API getMixMatrix (float *matrix, int *outchannels, int *inchannels, int inchannel_hop = 0)`
- `FMOD_RESULT F_API getType (FMOD_DSPCONNECTION_TYPE *type)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`

### `EventCenter`

**Functions:**

- `GEODE_DLL static EventCenter* get()`
- `ListenerHandle addReceiver(BaseFilter const* filter, Callable func, Callable2 migratePort) noexcept`
- `return ListenerHandle()`
- `return ListenerHandle()`
- `size_t getReceiverCount(BaseFilter const* filter, Callable func, Callable2 migratePort) noexcept`
- `size_t removeReceiver(BaseFilter const* filter, Callable func, Callable2 migratePort) noexcept`
- `GEODE_DLL static EventCenter* get()`
- `ListenerHandle addReceiver(BaseFilter const* filter, Callable func, Callable2 migratePort) noexcept`
- `return ListenerHandle()`
- `return ListenerHandle()`
- `size_t getReceiverCount(BaseFilter const* filter, Callable func, Callable2 migratePort) noexcept`
- `size_t removeReceiver(BaseFilter const* filter, Callable func, Callable2 migratePort) noexcept`

### `EventCenterGlobal`

**Functions:**

- `static EventCenterGlobal* get()`
- `bool send(BaseFilter const* filter, SendFuncType func, MigrateFuncType migratePort) noexcept`
- `ListenerHandle addReceiver(BaseFilter const* filter, AddFuncType func, MigrateFuncType migratePort) noexcept`
- `size_t getReceiverCount(BaseFilter const* filter, SizeFuncType func, MigrateFuncType migratePort) noexcept`
- `size_t removeReceiver(BaseFilter const* filter, RemoveFuncType func, MigrateFuncType migratePort) noexcept`

### `EventCenterThreadLocal`

**Functions:**

- `static EventCenterThreadLocal* get()`
- `bool send(BaseFilter const* filter, SendFuncType func, MigrateFuncType migratePort) noexcept`
- `ListenerHandle addReceiver(BaseFilter const* filter, AddFuncType func, MigrateFuncType migratePort) noexcept`
- `size_t getReceiverCount(BaseFilter const* filter, SizeFuncType func, MigrateFuncType migratePort) noexcept`
- `size_t removeReceiver(BaseFilter const* filter, RemoveFuncType func, MigrateFuncType migratePort) noexcept`

### `EventListenerNode` : public cocos2d::CCNode

**Functions:**

- `static EventListenerNode* create(ListenerHandle&& handle)`
- `static EventListenerNode* create(Event event, Callback&& callback, int priority)`

### `FieldContainer`

**Functions:**

- `operator delete(m_containedFields[i])`
- `void* getField(size_t index)`
- `operator new(size)`
- `static FieldContainer* from(cocos2d::CCNode* node, char const* forClass)`

### `FieldIntermediate`

**Functions:**

- `public: FieldIntermediate() = default`
- `static void fieldConstructor(void* offsetField)`
- `static void fieldDestructor(void* offsetField)`
- `auto self()`
- `static void fieldConstructor(void* offsetField)`
- `static void fieldDestructor(void* offsetField)`
- `auto self()`

### `Generator`

**Functions:**

- `void seed(uint64_t seed)`
- `result_type next()`
- `T generate()`
- `if constexpr (std::is_same_v<T, bool>)`
- `else if constexpr (std::is_integral_v<T>)`
- `else if constexpr (std::is_floating_point_v<T>)`
- `Out generate(T min_, Y max_)`
- `if constexpr (std::is_integral_v<Out>)`
- `std::uniform_int_distribution<Out> dist(min_, max_ - 1)`
- `return dist(*this)`
- `else if constexpr (std::is_floating_point_v<Out>)`
- `std::uniform_real_distribution<Out> dist(min_, max_)`
- `return dist(*this)`
- `static constexpr result_type min()`
- `static constexpr result_type max()`
- `void seed(uint64_t seed)`
- `result_type next()`
- `T generate()`
- `if constexpr (std::is_same_v<T, bool>)`
- `else if constexpr (std::is_integral_v<T>)`
- `else if constexpr (std::is_floating_point_v<T>)`
- `Out generate(T min_, Y max_)`
- `if constexpr (std::is_integral_v<Out>)`
- `std::uniform_int_distribution<Out> dist(min_, max_ - 1)`
- `return dist(*this)`
- `else if constexpr (std::is_floating_point_v<Out>)`
- `std::uniform_real_distribution<Out> dist(min_, max_)`
- `return dist(*this)`
- `static constexpr result_type min()`
- `static constexpr result_type max()`

### `GenericContentLayer` : public CCContentLayer

**Functions:**

- `static GenericContentLayer* create(float width, float height)`
- `void setPosition(cocos2d::CCPoint const& pos) override`
- `static GenericContentLayer* create(float width, float height)`
- `void setPosition(cocos2d::CCPoint const& pos) override`

### `GenericListCell` : public TableViewCell

**Functions:**

- `static GenericListCell* create(char const* key, cocos2d::CCSize size)`
- `void updateBGColor(int index)`
- `void setPrimaryColor(cocos2d::ccColor3B color)`
- `void setSecondaryColor(cocos2d::ccColor3B color)`
- `void setOpacity(GLubyte opacity)`
- `void setBorderColor(cocos2d::ccColor4B color)`

### `Geometry`

**Functions:**

- `FMOD_RESULT F_API release ()`
- `FMOD_RESULT F_API addPolygon (float directocclusion, float reverbocclusion, bool doublesided, int numvertices, const FMOD_VECTOR *vertices, int *polygonindex)`
- `FMOD_RESULT F_API getNumPolygons (int *numpolygons)`
- `FMOD_RESULT F_API getMaxPolygons (int *maxpolygons, int *maxvertices)`
- `FMOD_RESULT F_API getPolygonNumVertices (int index, int *numvertices)`
- `FMOD_RESULT F_API setPolygonVertex (int index, int vertexindex, const FMOD_VECTOR *vertex)`
- `FMOD_RESULT F_API getPolygonVertex (int index, int vertexindex, FMOD_VECTOR *vertex)`
- `FMOD_RESULT F_API setPolygonAttributes (int index, float directocclusion, float reverbocclusion, bool doublesided)`
- `FMOD_RESULT F_API getPolygonAttributes (int index, float *directocclusion, float *reverbocclusion, bool *doublesided)`
- `FMOD_RESULT F_API setActive (bool active)`
- `FMOD_RESULT F_API getActive (bool *active)`
- `FMOD_RESULT F_API setRotation (const FMOD_VECTOR *forward, const FMOD_VECTOR *up)`
- `FMOD_RESULT F_API getRotation (FMOD_VECTOR *forward, FMOD_VECTOR *up)`
- `FMOD_RESULT F_API setPosition (const FMOD_VECTOR *position)`
- `FMOD_RESULT F_API getPosition (FMOD_VECTOR *position)`
- `FMOD_RESULT F_API setScale (const FMOD_VECTOR *scale)`
- `FMOD_RESULT F_API getScale (FMOD_VECTOR *scale)`
- `FMOD_RESULT F_API save (void *data, int *datasize)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`

### `IconButtonSprite` : public cocos2d::CCSprite, public cocos2d::CCLabelProtocol

**Functions:**

- `static IconButtonSprite* create( char const* bg, cocos2d::CCNode* icon, char const* text, char const* font )`
- `static IconButtonSprite* createWithSpriteFrameName( char const* bg, cocos2d::CCNode* icon, char const* text, char const* font )`
- `void setBG(char const* bg, bool isFrame)`
- `void setIcon(cocos2d::CCNode* icon)`
- `cocos2d::CCNode* getIcon() const`
- `void setString(char const* label) override`
- `char const* getString() override`
- `void setColor(cocos2d::ccColor3B const& color) override`
- `void setOpacity(GLubyte opacity) override`
- `NineSlice* getBg()`
- `cocos2d::CCLabelBMFont* getLabel()`
- `cocos2d::CCNode* getIcon()`

### `LambdaCallback` : public cocos2d::CCObject

**Functions:**

- `void execute(cocos2d::CCNode* node)`
- `void execute(cocos2d::CCNode* node)`

### `Layout` : public cocos2d::CCObject

**Functions:**

- `virtual void apply(cocos2d::CCNode* on) = 0`
- `virtual cocos2d::CCSize getSizeHint(cocos2d::CCNode* on) const = 0`
- `virtual ~Layout() = default`
- `virtual void apply(cocos2d::CCNode* on) = 0`
- `virtual cocos2d::CCSize getSizeHint(cocos2d::CCNode* on) const = 0`
- `virtual ~Layout() = default`

### `LayoutOptions` : public cocos2d::CCObject

**Functions:**

- `virtual ~LayoutOptions() = default`
- `virtual ~LayoutOptions() = default`

### `LazySprite` : public cocos2d::CCSprite

**Functions:**

- `static LazySprite* create(cocos2d::CCSize size, bool loadingCircle = true)`
- `void loadFromUrl(std::string url, Format format = Format::kFmtUnKnown, bool ignoreCache = false)`
- `void loadFromFile(std::filesystem::path const& path, Format format = Format::kFmtUnKnown, bool ignoreCache = false)`
- `void loadFromData(std::vector<uint8_t> data, Format format = Format::kFmtUnKnown)`
- `void loadFromData(std::span<uint8_t const> data, Format format = Format::kFmtUnKnown)`
- `void loadFromData(uint8_t const* ptr, size_t size, Format format = Format::kFmtUnKnown)`
- `void setLoadCallback(Callback callback)`
- `void setAutoResize(bool value)`
- `bool isLoaded()`
- `bool isLoading()`
- `void cancelLoad()`
- `virtual bool initWithTexture(cocos2d::CCTexture2D* pTexture, const cocos2d::CCRect& rect, bool rotated) override`
- `virtual bool initWithSpriteFrame(cocos2d::CCSpriteFrame* pSpriteFrame) override`
- `virtual bool initWithSpriteFrameName(const char* pszSpriteFrameName) override`
- `virtual bool initWithFile(const char* pszFilename, const cocos2d::CCRect& rect) override`
- `static LazySprite* create(cocos2d::CCSize size, bool loadingCircle = true)`
- `void loadFromUrl(std::string url, Format format = Format::kFmtUnKnown, bool ignoreCache = false)`
- `void loadFromFile(std::filesystem::path const& path, Format format = Format::kFmtUnKnown, bool ignoreCache = false)`
- `void loadFromData(std::vector<uint8_t> data, Format format = Format::kFmtUnKnown)`
- `void loadFromData(std::span<uint8_t const> data, Format format = Format::kFmtUnKnown)`
- `void loadFromData(uint8_t const* ptr, size_t size, Format format = Format::kFmtUnKnown)`
- `void setLoadCallback(Callback callback)`
- `void setAutoResize(bool value)`
- `bool isLoaded()`
- `bool isLoading()`
- `void cancelLoad()`
- `virtual bool initWithTexture(cocos2d::CCTexture2D* pTexture, const cocos2d::CCRect& rect, bool rotated) override`
- `virtual bool initWithSpriteFrame(cocos2d::CCSpriteFrame* pSpriteFrame) override`
- `virtual bool initWithSpriteFrameName(const char* pszSpriteFrameName) override`
- `virtual bool initWithFile(const char* pszFilename, const cocos2d::CCRect& rect) override`

### `ListBorders` : public cocos2d::CCNode

**Functions:**

- `static ListBorders* create()`
- `void setSpriteFrames(char const* topAndBottom, char const* sides, float horizontalPadding = 7.5f)`
- `void setSprites( NineSlice* top, NineSlice* bottom, cocos2d::CCSprite* left, cocos2d::CCSprite* right, float topPadding = 7.5f, float bottomPadding = 7.5f )`
- `void setContentSize(cocos2d::CCSize const& size) override`
- `NineSlice* getTop()`
- `NineSlice* getBottom()`
- `cocos2d::CCSprite* getLeft()`
- `cocos2d::CCSprite* getRight()`
- `float getTopPadding()`
- `float getBottomPadding()`

### `ListView` : public CustomListView

**Functions:**

- `static ListView* create( cocos2d::CCArray* items, float itemHeight = 40.f, float width = 358.f, float height = 220.f )`
- `void setPrimaryCellColor(cocos2d::ccColor3B color)`
- `void setSecondaryCellColor(cocos2d::ccColor3B color)`
- `void setCellOpacity(GLubyte opacity)`
- `void setCellBorderColor(cocos2d::ccColor4B color)`

### `MDTextArea` : public cocos2d::CCLayer,
        public cocos2d::CCLabelProtocol,
        public FLAlertLayerProtocol

**Functions:**

- `static MDTextArea* create(std::string str, cocos2d::CCSize const& size)`
- `static MDTextArea* create(std::string str, cocos2d::CCSize const& size, bool compatibilityMode)`
- `void updateLabel()`
- `void setString(char const* text) override`
- `char const* getString() override`
- `CCScrollLayerExt* getScrollLayer() const`

### `Modify` : public Base

**Functions:**

- `static void onModify(auto& self)`

### `ModifyBase`

**Functions:**

- `Result<Hook*> getHook(std::string_view name)`
- `return Err("Hook not in this modify")`
- `Result<> setHookPriority(std::string_view name, int32_t priority = Priority::Normal)`
- `return Ok()`
- `Result<> setHookPriorityPre(std::string_view name, int32_t priority = Priority::Normal)`
- `Result<> setHookPriorityPost(std::string_view name, int32_t priority = Priority::Normal)`
- `Result<> setHookPriorityAfter(std::string_view name, Mod* mod)`
- `return Ok()`
- `static void setHookPriorityAfter(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityAfter(std::string_view name, std::string_view after)`
- `return Err("Mod not found")`
- `static Result<> setHookPriorityAfter(Hook* hook, std::string_view after)`
- `return Err("Mod not found")`
- `return Ok()`
- `Result<> setHookPriorityBefore(std::string_view name, Mod* mod)`
- `return Ok()`
- `static void setHookPriorityBefore(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityBefore(std::string_view name, std::string_view before)`
- `return Err("Mod not found")`
- `static Result<> setHookPriorityBefore(Hook* hook, std::string_view before)`
- `return Err("Mod not found")`
- `return Ok()`
- `Result<> setHookPriorityAfterPre(std::string_view name, std::string_view after)`
- `Result<> setHookPriorityAfterPre(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityAfterPre(Hook* hook, std::string_view after)`
- `return setHookPriorityAfter(hook, after)`
- `static void setHookPriorityAfterPre(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityBeforePre(std::string_view name, std::string_view before)`
- `Result<> setHookPriorityBeforePre(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityBeforePre(Hook* hook, std::string_view before)`
- `return setHookPriorityBefore(hook, before)`
- `static void setHookPriorityBeforePre(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityAfterPost(std::string_view name, std::string_view after)`
- `Result<> setHookPriorityAfterPost(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityAfterPost(Hook* hook, std::string_view after)`
- `return setHookPriorityBefore(hook, after)`
- `static void setHookPriorityAfterPost(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityBeforePost(std::string_view name, std::string_view before)`
- `Result<> setHookPriorityBeforePost(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityBeforePost(Hook* hook, std::string_view before)`
- `return setHookPriorityAfter(hook, before)`
- `static void setHookPriorityBeforePost(Hook* hook, Mod* mod)`
- `virtual void apply()`
- `Result<Hook*> getHook(std::string_view name)`
- `return Err("Hook not in this modify")`
- `Result<> setHookPriority(std::string_view name, int32_t priority = Priority::Normal)`
- `return Ok()`
- `Result<> setHookPriorityPre(std::string_view name, int32_t priority = Priority::Normal)`
- `Result<> setHookPriorityPost(std::string_view name, int32_t priority = Priority::Normal)`
- `Result<> setHookPriorityAfter(std::string_view name, Mod* mod)`
- `return Ok()`
- `static void setHookPriorityAfter(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityAfter(std::string_view name, std::string_view after)`
- `return Err("Mod not found")`
- `static Result<> setHookPriorityAfter(Hook* hook, std::string_view after)`
- `return Err("Mod not found")`
- `return Ok()`
- `Result<> setHookPriorityBefore(std::string_view name, Mod* mod)`
- `return Ok()`
- `static void setHookPriorityBefore(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityBefore(std::string_view name, std::string_view before)`
- `return Err("Mod not found")`
- `static Result<> setHookPriorityBefore(Hook* hook, std::string_view before)`
- `return Err("Mod not found")`
- `return Ok()`
- `Result<> setHookPriorityAfterPre(std::string_view name, std::string_view after)`
- `Result<> setHookPriorityAfterPre(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityAfterPre(Hook* hook, std::string_view after)`
- `return setHookPriorityAfter(hook, after)`
- `static void setHookPriorityAfterPre(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityBeforePre(std::string_view name, std::string_view before)`
- `Result<> setHookPriorityBeforePre(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityBeforePre(Hook* hook, std::string_view before)`
- `return setHookPriorityBefore(hook, before)`
- `static void setHookPriorityBeforePre(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityAfterPost(std::string_view name, std::string_view after)`
- `Result<> setHookPriorityAfterPost(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityAfterPost(Hook* hook, std::string_view after)`
- `return setHookPriorityBefore(hook, after)`
- `static void setHookPriorityAfterPost(Hook* hook, Mod* mod)`
- `Result<> setHookPriorityBeforePost(std::string_view name, std::string_view before)`
- `Result<> setHookPriorityBeforePost(std::string_view name, Mod* mod)`
- `static Result<> setHookPriorityBeforePost(Hook* hook, std::string_view before)`
- `return setHookPriorityAfter(hook, before)`
- `static void setHookPriorityBeforePost(Hook* hook, Mod* mod)`
- `virtual void apply()`

### `ModifyDerive`

**Functions:**

- `public: ModifyDerive()`

### `NineSlice` : public cocos2d::CCNodeRGBA

**Functions:**

- `static NineSlice* create(geode::ZStringView file, cocos2d::CCRect const& rect =`
- `static NineSlice* createWithSpriteFrameName(geode::ZStringView spriteFrameName, Insets const& insets =`
- `static NineSlice* createWithSpriteFrame(cocos2d::CCSpriteFrame* spriteFrame, Insets const& insets =`
- `void setScaleMultiplier(float scaleMultiplier)`
- `float getScaleMultiplier()`
- `void setRepeatCenter(bool repeat)`
- `bool getRepeatCenter() const`
- `void setInsets(Insets const& insets)`
- `Insets getInsets() const`
- `void setInsetTop(float top)`
- `void setInsetRight(float right)`
- `void setInsetBottom(float bottom)`
- `void setInsetLeft(float left)`
- `float getInsetTop() const`
- `float getInsetRight() const`
- `float getInsetBottom() const`
- `float getInsetLeft() const`
- `cocos2d::CCSprite* getTopLeft()`
- `cocos2d::CCSprite* getTopRight()`
- `cocos2d::CCSprite* getBottomLeft()`
- `cocos2d::CCSprite* getBottomRight()`
- `cocos2d::CCSprite* getTop()`
- `cocos2d::CCSprite* getBottom()`
- `cocos2d::CCSprite* getLeft()`
- `cocos2d::CCSprite* getRight()`
- `cocos2d::CCSprite* getCenter()`
- `cocos2d::CCSpriteBatchNode* getBatchNode()`
- `virtual void addChild(cocos2d::CCNode* child, int zOrder, int tag) override`
- `virtual void removeChild(cocos2d::CCNode* child, bool cleanup) override`
- `virtual cocos2d::CCArray* getChildren() override`
- `virtual unsigned int getChildrenCount() const override`
- `virtual void setContentSize(cocos2d::CCSize const& size) override`
- `virtual void visit() override`
- `virtual void setColor(cocos2d::ccColor3B const& color) override`
- `virtual void setOpacity(GLubyte opacity) override`
- `virtual void setOpacityModifyRGB(bool var) override`
- `virtual void updateDisplayedOpacity(GLubyte parentOpacity) override`
- `virtual void updateDisplayedColor(cocos2d::ccColor3B const& parentColor) override`
- `static NineSlice* create(geode::ZStringView file, cocos2d::CCRect const& rect =`
- `static NineSlice* createWithSpriteFrameName(geode::ZStringView spriteFrameName, Insets const& insets =`
- `static NineSlice* createWithSpriteFrame(cocos2d::CCSpriteFrame* spriteFrame, Insets const& insets =`
- `void setScaleMultiplier(float scaleMultiplier)`
- `float getScaleMultiplier()`
- `void setRepeatCenter(bool repeat)`
- `bool getRepeatCenter() const`
- `void setInsets(Insets const& insets)`
- `Insets getInsets() const`
- `void setInsetTop(float top)`
- `void setInsetRight(float right)`
- `void setInsetBottom(float bottom)`
- `void setInsetLeft(float left)`
- `float getInsetTop() const`
- `float getInsetRight() const`
- `float getInsetBottom() const`
- `float getInsetLeft() const`
- `cocos2d::CCSprite* getTopLeft()`
- `cocos2d::CCSprite* getTopRight()`
- `cocos2d::CCSprite* getBottomLeft()`
- `cocos2d::CCSprite* getBottomRight()`
- `cocos2d::CCSprite* getTop()`
- `cocos2d::CCSprite* getBottom()`
- `cocos2d::CCSprite* getLeft()`
- `cocos2d::CCSprite* getRight()`
- `cocos2d::CCSprite* getCenter()`
- `cocos2d::CCSpriteBatchNode* getBatchNode()`
- `virtual void addChild(cocos2d::CCNode* child, int zOrder, int tag) override`
- `virtual void removeChild(cocos2d::CCNode* child, bool cleanup) override`
- `virtual cocos2d::CCArray* getChildren() override`
- `virtual unsigned int getChildrenCount() const override`
- `virtual void setContentSize(cocos2d::CCSize const& size) override`
- `virtual void visit() override`
- `virtual void setColor(cocos2d::ccColor3B const& color) override`
- `virtual void setOpacity(GLubyte opacity) override`
- `virtual void setOpacityModifyRGB(bool var) override`
- `virtual void updateDisplayedOpacity(GLubyte parentOpacity) override`
- `virtual void updateDisplayedColor(cocos2d::ccColor3B const& parentColor) override`

### `Notification` : public cocos2d::CCNodeRGBA

**Functions:**

- `static Notification* create( ZStringView text, NotificationIcon icon = NotificationIcon::None, float time = NOTIFICATION_DEFAULT_TIME )`
- `static Notification* create( ZStringView text, cocos2d::CCNode* icon, float time = NOTIFICATION_DEFAULT_TIME )`
- `void setString(ZStringView text)`
- `void setIcon(NotificationIcon icon)`
- `void setIcon(cocos2d::CCNode* icon)`
- `cocos2d::CCNode* getIcon()`
- `void setTime(float time)`
- `float getTime()`
- `bool isShowing()`
- `void show()`
- `void hide()`
- `void cancel()`

### `ObjWrapper` : public cocos2d::CCObject

**Functions:**

- `static ObjWrapper* create(T&& value)`
- `static ObjWrapper* create(T const& value)`
- `return new ObjWrapper(value)`
- `T& getValue()`
- `void setValue(T&& value)`

### `ObserverContext`

**Functions:**

- `void clearSignals() const noexcept`
- `static ObserverContext* top() noexcept`
- `void registerSignal(std::shared_ptr<SignalInternal> sig) noexcept`

### `OpaqueEventPort` : public OpaquePortBase

**Functions:**

- `size_t getReceiverCount() const noexcept`
- `size_t removeReceiver(ReceiverHandle handle) noexcept`

### `OpaqueEventPortV2` : public OpaqueEventPort<PortTemplate, PArgs...>

**Functions:**

- `public: OpaqueEventPortV2()`
- `void migrateFromV1(OpaqueEventPort<PortTemplate, PArgs...>* oldPort) noexcept`
- `void migrateFromV1(OpaqueEventPort<PortTemplate, PArgs...>* oldPort) noexcept`

### `OpaqueEventPortV3` : public OpaqueEventPortV2<PortTemplate, PArgs...>

**Functions:**

- `public: OpaqueEventPortV3()`
- `void migrateFromV2(OpaqueEventPortV2<PortTemplate, PArgs...>* oldPort) noexcept`
- `void migrateFromV2(OpaqueEventPortV2<PortTemplate, PArgs...>* oldPort) noexcept`

### `OpaquePortBase`

**Functions:**

- `virtual ~OpaquePortBase() noexcept = default`
- `virtual ~OpaquePortBase() noexcept = default`

### `PlatformID`

**Functions:**

- `constexpr PlatformID(Type t)`
- `constexpr operator int() const`
- `static GEODE_DLL PlatformID from(std::string_view str)`
- `static GEODE_DLL bool coveredBy(std::string_view str, PlatformID t)`
- `static GEODE_DLL std::string_view toString(Type lp)`
- `static GEODE_DLL std::string_view toShortString(Type lp, bool ignoreArch = false)`
- `requires requires(T t)`
- `constexpr static PlatformID from(T t)`
- `requires requires(Type t)`
- `constexpr T to() const`
- `constexpr PlatformID(Type t)`
- `constexpr operator int() const`
- `static GEODE_DLL PlatformID from(std::string_view str)`
- `static GEODE_DLL bool coveredBy(std::string_view str, PlatformID t)`
- `static GEODE_DLL std::string_view toString(Type lp)`
- `static GEODE_DLL std::string_view toShortString(Type lp, bool ignoreArch = false)`
- `requires requires(T t)`
- `constexpr static PlatformID from(T t)`
- `requires requires(Type t)`
- `constexpr T to() const`

### `Port`

**Functions:**

- `void migrateFromV1(Port&& other) noexcept`
- `void migrateFromV2(Port&& other) noexcept`
- `ReceiverHandle addReceiver(Callable receiver, int priority = 0) noexcept`
- `size_t removeReceiver(ReceiverHandle handle) noexcept`
- `size_t getReceiverCount() const noexcept`

### `Reverb3D`

**Functions:**

- `FMOD_RESULT F_API release ()`
- `FMOD_RESULT F_API set3DAttributes (const FMOD_VECTOR *position, float mindistance, float maxdistance)`
- `FMOD_RESULT F_API get3DAttributes (FMOD_VECTOR *position, float *mindistance,float *maxdistance)`
- `FMOD_RESULT F_API setProperties (const FMOD_REVERB_PROPERTIES *properties)`
- `FMOD_RESULT F_API getProperties (FMOD_REVERB_PROPERTIES *properties)`
- `FMOD_RESULT F_API setActive (bool active)`
- `FMOD_RESULT F_API getActive (bool *active)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`

### `RichTextArea` : public SimpleTextArea, public cocos2d::CCTouchDelegate

**Functions:**

- `static RichTextArea* create(std::string text, std::string font = "chatFont.fnt", float scale = 1.0f)`
- `static RichTextArea* create(std::string text, std::string font, float scale, float width)`
- `std::string getRawText()`
- `void registerRichTextKey(std::shared_ptr<RichTextKeyBase> key)`
- `static RichTextArea* create(std::string text, std::string font = "chatFont.fnt", float scale = 1.0f)`
- `static RichTextArea* create(std::string text, std::string font, float scale, float width)`
- `std::string getRawText()`
- `void registerRichTextKey(std::shared_ptr<RichTextKeyBase> key)`

### `RichTextKeyBase`

**Functions:**

- `virtual ~RichTextKeyBase() = default`
- `virtual Result<std::shared_ptr<RichTextKeyInstanceBase>> createInstance(std::string const& value, bool cancellation) = 0`
- `virtual std::string getKey() const = 0`
- `virtual ~RichTextKeyBase() = default`
- `virtual Result<std::shared_ptr<RichTextKeyInstanceBase>> createInstance(std::string const& value, bool cancellation) = 0`
- `virtual std::string getKey() const = 0`

### `RichTextKeyInstanceBase`

**Functions:**

- `virtual ~RichTextKeyInstanceBase() = default`
- `virtual void applyChangesToSprite(cocos2d::CCFontSprite* spr, int localIndex, int index) = 0`
- `virtual std::string getKey() const = 0`
- `virtual bool isCancellation() const = 0`
- `virtual std::string runStrAddition() = 0`
- `virtual bool isButton() const = 0`
- `virtual void callButton(bool keyDown, cocos2d::CCFontSprite* spr, std::set<cocos2d::CCFontSprite*> const& word) = 0`
- `virtual ~RichTextKeyInstanceBase() = default`
- `virtual void applyChangesToSprite(cocos2d::CCFontSprite* spr, int localIndex, int index) = 0`
- `virtual std::string getKey() const = 0`
- `virtual bool isCancellation() const = 0`
- `virtual std::string runStrAddition() = 0`
- `virtual bool isButton() const = 0`
- `virtual void callButton(bool keyDown, cocos2d::CCFontSprite* spr, std::set<cocos2d::CCFontSprite*> const& word) = 0`

### `ScrollLayer` : public CCScrollLayerExt

**Functions:**

- `static ScrollLayer* create( cocos2d::CCRect const& rect, bool scrollWheelEnabled = true, bool vertical = true )`
- `static ScrollLayer* create( cocos2d::CCSize const& size, bool scrollWheelEnabled = true, bool vertical = true )`
- `void scrollWheel(float y, float) override`
- `void enableScrollWheel(bool enable = true)`
- `void scrollToTop()`
- `void setCancelTouchLimit(float limit)`
- `float getCancelTouchLimit() const`
- `void setStealingTouches(bool steal)`
- `bool isStealingTouches() const`
- `static Layout* createDefaultListLayout(float gap = 2.5f)`

### `Scrollbar` : public cocos2d::CCLayer

**Functions:**

- `bool isTouching()`
- `CCScrollLayerExt* getTarget()`
- `NineSlice* getTrack()`
- `NineSlice* getThumb()`
- `void setTarget(CCScrollLayerExt* list)`
- `void setTrack(NineSlice* track)`
- `void setThumb(NineSlice* thumb)`
- `static Scrollbar* create(CCScrollLayerExt* list)`

### `SeedValueRS` : public BaseSeedValue

**Functions:**

- `int value()`
- `operator int()`

### `SeedValueSR` : public BaseSeedValue

**Functions:**

- `int value()`
- `operator int()`

### `SelectList` : public cocos2d::CCMenu

**Functions:**

- `new SelectList()`
- `void setItems(std::span<T> list)`

### `SettingBaseValueV3` : public SettingV3

**Functions:**

- `T getDefaultValue() const`
- `T getValue() const`
- `void setValue(V value)`
- `virtual Result<> isValid(V value) const`
- `return Ok()`
- `bool isDefaultValue() const override`
- `void reset() override`
- `bool load(matjson::Value const& json) override`
- `bool save(matjson::Value& json) const override`

### `SettingNodeV3` : public cocos2d::CCNode

**Functions:**

- `void commit()`
- `void resetToDefault()`
- `virtual bool hasUncommittedChanges() const = 0`
- `virtual bool hasNonDefaultValue() const = 0`
- `void updateState2(cocos2d::CCNode* invoker)`
- `void setDefaultBGColor(cocos2d::ccColor4B color)`
- `cocos2d::CCLabelBMFont* getNameLabel() const`
- `CCMenuItemSpriteExtra* getDescriptionButton() const`
- `cocos2d::CCLabelBMFont* getStatusLabel() const`
- `cocos2d::CCMenu* getNameMenu() const`
- `cocos2d::CCMenu* getButtonMenu() const`
- `cocos2d::CCLayerColor* getBG() const`
- `void overrideDescription(std::optional<ZStringView> description)`
- `void setContentSize(cocos2d::CCSize const& size) override`
- `std::shared_ptr<SettingV3> getSetting() const`

### `SettingV3` : public std::enable_shared_from_this<SettingV3>

**Functions:**

- `virtual ~SettingV3()`
- `std::string getKey() const`
- `std::string getModID() const`
- `Mod* getMod() const`
- `std::optional<std::string> getName() const`
- `std::string getDisplayName() const`
- `std::optional<std::string> getDescription() const`
- `std::optional<std::string> getEnableIf() const`
- `bool shouldEnable() const`
- `std::optional<std::string> getEnableIfDescription() const`
- `bool requiresRestart() const`
- `PlatformID getPlatforms() const`
- `virtual bool load(matjson::Value const& json) = 0`
- `virtual bool save(matjson::Value& json) const = 0`
- `virtual SettingNodeV3* createNode(float width) = 0`
- `virtual bool isDefaultValue() const = 0`
- `virtual void reset() = 0`

### `SettingValueNodeV3` : public SettingNodeV3

**Functions:**

- `typename S::ValueType getValue() const`
- `void setValue(typename S::ValueAssignType value, cocos2d::CCNode* invoker)`
- `std::shared_ptr<S> getSetting() const`

### `SharedButtonHandler`

**Functions:**

- `static SharedButtonHandler* get()`
- `static bool containsTouch(Button* button, cocos2d::CCTouch* touch)`
- `void registerButton(Button* button)`
- `void unregisterButton(Button* button)`
- `void passMoveToButtons(Button* button, cocos2d::CCTouch* touch)`
- `void passActivateToButtons()`
- `void passCancelledToButtons()`
- `void setActiveButton(Button* button)`
- `static SharedButtonHandler* get()`
- `static bool containsTouch(Button* button, cocos2d::CCTouch* touch)`
- `void registerButton(Button* button)`
- `void unregisterButton(Button* button)`
- `void passMoveToButtons(Button* button, cocos2d::CCTouch* touch)`
- `void passActivateToButtons()`
- `void passCancelledToButtons()`
- `void setActiveButton(Button* button)`

### `Signal`

**Functions:**

- `noexcept : value(v)`
- `void removePortReceiver(ReceiverHandle handle) noexcept override`
- `ReceiverHandle addPortReceiver(ObserverContext obs) noexcept override`
- `noexcept : impl(sig.impl)`
- `void rebind(Signal sig) noexcept`
- `void set(Type val) noexcept`
- `if constexpr (ThreadSafe)`
- `std::lock_guard lk(impl->mutex)`
- `std::conditional_t<ThreadSafe, Type, Type const&> get_internal() const noexcept`
- `LockType lk(impl->mutex)`
- `std::conditional_t<ThreadSafe, Type, Type const&> get() noexcept`
- `LockType lk(impl->mutex)`
- `return get()`
- `return get()`
- `Signal const& operator assign(Type value) noexcept`
- `LockType lk(impl->mutex)`
- `noexcept : impl(sig.impl)`
- `void rebind(Signal sig) noexcept`
- `void set(Type val) noexcept`
- `if constexpr (ThreadSafe)`
- `std::lock_guard lk(impl->mutex)`
- `std::conditional_t<ThreadSafe, Type, Type const&> get_internal() const noexcept`
- `LockType lk(impl->mutex)`
- `std::conditional_t<ThreadSafe, Type, Type const&> get() noexcept`
- `LockType lk(impl->mutex)`
- `return get()`
- `return get()`
- `Signal const& operator assign(Type value) noexcept`
- `LockType lk(impl->mutex)`

### `SimpleAxisLayout` : public Layout

**Functions:**

- `static SimpleAxisLayout* create(Axis axis)`
- `virtual ~SimpleAxisLayout()`
- `void apply(cocos2d::CCNode* on) override`
- `cocos2d::CCSize getSizeHint(cocos2d::CCNode* on) const override`
- `SimpleAxisLayout* setAxis(Axis axis)`
- `SimpleAxisLayout* setMainAxisScaling(AxisScaling scaling)`
- `SimpleAxisLayout* setCrossAxisScaling(AxisScaling scaling)`
- `SimpleAxisLayout* setMainAxisAlignment(MainAxisAlignment alignment)`
- `SimpleAxisLayout* setCrossAxisAlignment(CrossAxisAlignment alignment)`
- `SimpleAxisLayout* setMainAxisDirection(AxisDirection direction)`
- `SimpleAxisLayout* setCrossAxisDirection(AxisDirection direction)`
- `SimpleAxisLayout* setGap(float gap)`
- `SimpleAxisLayout* setMinRelativeScale(std::optional<float> scale)`
- `SimpleAxisLayout* setMaxRelativeScale(std::optional<float> scale)`
- `SimpleAxisLayout* ignoreInvisibleChildren(bool ignore = true)`
- `bool isIgnoreInvisibleChildren() const`
- `SimpleAxisLayout* setPadding(Padding const& padding)`
- `Axis getAxis() const`
- `AxisScaling getMainAxisScaling() const`
- `AxisScaling getCrossAxisScaling() const`
- `MainAxisAlignment getMainAxisAlignment() const`
- `CrossAxisAlignment getCrossAxisAlignment() const`
- `AxisDirection getMainAxisDirection() const`
- `AxisDirection getCrossAxisDirection() const`
- `float getGap() const`
- `std::optional<float> getMinRelativeScale() const`
- `std::optional<float> getMaxRelativeScale() const`
- `Padding getPadding() const`

### `SimpleAxisLayoutOptions` : public LayoutOptions

**Functions:**

- `static SimpleAxisLayoutOptions* create()`
- `virtual ~SimpleAxisLayoutOptions()`
- `SimpleAxisLayoutOptions* setMinRelativeScale(std::optional<float> scale)`
- `SimpleAxisLayoutOptions* setMaxRelativeScale(std::optional<float> scale)`
- `SimpleAxisLayoutOptions* setScalingPriority(ScalingPriority priority)`
- `std::optional<float> getMinRelativeScale() const`
- `std::optional<float> getMaxRelativeScale() const`
- `ScalingPriority getScalingPriority() const`

### `SimpleTextArea` : public cocos2d::CCNode

**Functions:**

- `static SimpleTextArea* create(std::string text, std::string font = "chatFont.fnt", float scale = 1.0f)`
- `static SimpleTextArea* create(std::string text, std::string font, float scale, float width)`
- `void setFont(std::string font)`
- `std::string getFont()`
- `void setColor(const cocos2d::ccColor4B& color)`
- `cocos2d::ccColor4B getColor()`
- `void setAlignment(cocos2d::CCTextAlignment alignment)`
- `cocos2d::CCTextAlignment getAlignment()`
- `void setWrappingMode(WrappingMode mode)`
- `WrappingMode getWrappingMode()`
- `void setText(std::string text)`
- `std::string getText()`
- `void setMaxLines(size_t maxLines)`
- `size_t getMaxLines()`
- `void setWidth(float width)`
- `float getWidth()`
- `void setScale(float scale) override`
- `float getScale() override`
- `void setLinePadding(float padding)`
- `float getLinePadding()`
- `std::vector<cocos2d::CCLabelBMFont*> getLines()`
- `float getHeight()`
- `float getLineHeight()`
- `static SimpleTextArea* create(std::string text, std::string font = "chatFont.fnt", float scale = 1.0f)`
- `static SimpleTextArea* create(std::string text, std::string font, float scale, float width)`
- `void setFont(std::string font)`
- `std::string getFont()`
- `void setColor(const cocos2d::ccColor4B& color)`
- `cocos2d::ccColor4B getColor()`
- `void setAlignment(cocos2d::CCTextAlignment alignment)`
- `cocos2d::CCTextAlignment getAlignment()`
- `void setWrappingMode(WrappingMode mode)`
- `WrappingMode getWrappingMode()`
- `void setText(std::string text)`
- `std::string getText()`
- `void setMaxLines(size_t maxLines)`
- `size_t getMaxLines()`
- `void setWidth(float width)`
- `float getWidth()`
- `void setScale(float scale) override`
- `float getScale() override`
- `void setLinePadding(float padding)`
- `float getLinePadding()`
- `std::vector<cocos2d::CCLabelBMFont*> getLines()`
- `float getHeight()`
- `float getLineHeight()`

### `SliderNode` : public cocos2d::CCNodeRGBA, public cocos2d::CCTouchDelegate

**Functions:**

- `static SliderNode* createCustom(cocos2d::CCSprite* thumb, cocos2d::CCSprite* thumbSelected, geode::NineSlice* groove, ZStringView bar, SliderCallback callback, cocos2d::CCSize const& barOffset =`
- `static SliderNode* create(SliderCallback callback, bool alt = false)`
- `void setSlideCallback(SliderCallback callback)`
- `void setClickCallback(SliderCallback callback)`
- `void setReleaseCallback(SliderCallback callback)`
- `void setMin(float min)`
- `float getMin()`
- `void setMax(float max)`
- `float getMax()`
- `void setEnabled(bool enabled)`
- `bool isEnabled()`
- `void setValue(float value)`
- `float getValue()`
- `void setPercent(float percent)`
- `float getPercent()`
- `void setSnapStep(float snapStep)`
- `float getSnapStep()`
- `void linkTextInput(geode::TextInput* input, unsigned int precision)`
- `void unlinkTextInput()`
- `void setTextInputPrecision(unsigned int precision)`
- `unsigned int getTextInputPrecision()`
- `geode::TextInput* getLinkedTextInput()`
- `void linkLabel(cocos2d::CCLabelBMFont* label, unsigned int precision)`
- `void unlinkLabel()`
- `void setLabelPrecision(unsigned int precision)`
- `unsigned int getLabelPrecision()`
- `cocos2d::CCLabelBMFont* getLinkedLabel()`
- `void setReadOnly(bool readOnly)`
- `bool isReadOnly()`
- `void setSliderBypass(bool enabled)`
- `bool hasSliderBypass()`
- `cocos2d::CCNodeRGBA* getThumb()`
- `geode::NineSlice* getGroove()`
- `cocos2d::CCSprite* getBar()`
- `void setTouchPriority(int priority)`
- `int getTouchPriority()`
- `virtual void setContentSize(cocos2d::CCSize const& size) override`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void onEnter() override`
- `virtual void onExit() override`
- `virtual void registerWithTouchDispatcher()`
- `static SliderNode* createCustom(cocos2d::CCSprite* thumb, cocos2d::CCSprite* thumbSelected, geode::NineSlice* groove, ZStringView bar, SliderCallback callback, cocos2d::CCSize const& barOffset =`
- `static SliderNode* create(SliderCallback callback, bool alt = false)`
- `void setSlideCallback(SliderCallback callback)`
- `void setClickCallback(SliderCallback callback)`
- `void setReleaseCallback(SliderCallback callback)`
- `void setMin(float min)`
- `float getMin()`
- `void setMax(float max)`
- `float getMax()`
- `void setEnabled(bool enabled)`
- `bool isEnabled()`
- `void setValue(float value)`
- `float getValue()`
- `void setPercent(float percent)`
- `float getPercent()`
- `void setSnapStep(float snapStep)`
- `float getSnapStep()`
- `void linkTextInput(geode::TextInput* input, unsigned int precision)`
- `void unlinkTextInput()`
- `void setTextInputPrecision(unsigned int precision)`
- `unsigned int getTextInputPrecision()`
- `geode::TextInput* getLinkedTextInput()`
- `void linkLabel(cocos2d::CCLabelBMFont* label, unsigned int precision)`
- `void unlinkLabel()`
- `void setLabelPrecision(unsigned int precision)`
- `unsigned int getLabelPrecision()`
- `cocos2d::CCLabelBMFont* getLinkedLabel()`
- `void setReadOnly(bool readOnly)`
- `bool isReadOnly()`
- `void setSliderBypass(bool enabled)`
- `bool hasSliderBypass()`
- `cocos2d::CCNodeRGBA* getThumb()`
- `geode::NineSlice* getGroove()`
- `cocos2d::CCSprite* getBar()`
- `void setTouchPriority(int priority)`
- `int getTouchPriority()`
- `virtual void setContentSize(cocos2d::CCSize const& size) override`
- `virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override`
- `virtual void onEnter() override`
- `virtual void onExit() override`
- `virtual void registerWithTouchDispatcher()`

### `Sound`

**Functions:**

- `FMOD_RESULT F_API release ()`
- `FMOD_RESULT F_API getSystemObject (System **system)`
- `FMOD_RESULT F_API lock (unsigned int offset, unsigned int length, void **ptr1, void **ptr2, unsigned int *len1, unsigned int *len2)`
- `FMOD_RESULT F_API unlock (void *ptr1, void *ptr2, unsigned int len1, unsigned int len2)`
- `FMOD_RESULT F_API setDefaults (float frequency, int priority)`
- `FMOD_RESULT F_API getDefaults (float *frequency, int *priority)`
- `FMOD_RESULT F_API set3DMinMaxDistance (float min, float max)`
- `FMOD_RESULT F_API get3DMinMaxDistance (float *min, float *max)`
- `FMOD_RESULT F_API set3DConeSettings (float insideconeangle, float outsideconeangle, float outsidevolume)`
- `FMOD_RESULT F_API get3DConeSettings (float *insideconeangle, float *outsideconeangle, float *outsidevolume)`
- `FMOD_RESULT F_API set3DCustomRolloff (FMOD_VECTOR *points, int numpoints)`
- `FMOD_RESULT F_API get3DCustomRolloff (FMOD_VECTOR **points, int *numpoints)`
- `FMOD_RESULT F_API getSubSound (int index, Sound **subsound)`
- `FMOD_RESULT F_API getSubSoundParent (Sound **parentsound)`
- `FMOD_RESULT F_API getName (char *name, int namelen)`
- `FMOD_RESULT F_API getLength (unsigned int *length, FMOD_TIMEUNIT lengthtype)`
- `FMOD_RESULT F_API getFormat (FMOD_SOUND_TYPE *type, FMOD_SOUND_FORMAT *format, int *channels, int *bits)`
- `FMOD_RESULT F_API getNumSubSounds (int *numsubsounds)`
- `FMOD_RESULT F_API getNumTags (int *numtags, int *numtagsupdated)`
- `FMOD_RESULT F_API getTag (const char *name, int index, FMOD_TAG *tag)`
- `FMOD_RESULT F_API getOpenState (FMOD_OPENSTATE *openstate, unsigned int *percentbuffered, bool *starving, bool *diskbusy)`
- `FMOD_RESULT F_API readData (void *buffer, unsigned int length, unsigned int *read)`
- `FMOD_RESULT F_API seekData (unsigned int pcm)`
- `FMOD_RESULT F_API setSoundGroup (SoundGroup *soundgroup)`
- `FMOD_RESULT F_API getSoundGroup (SoundGroup **soundgroup)`
- `FMOD_RESULT F_API getNumSyncPoints (int *numsyncpoints)`
- `FMOD_RESULT F_API getSyncPoint (int index, FMOD_SYNCPOINT **point)`
- `FMOD_RESULT F_API getSyncPointInfo (FMOD_SYNCPOINT *point, char *name, int namelen, unsigned int *offset, FMOD_TIMEUNIT offsettype)`
- `FMOD_RESULT F_API addSyncPoint (unsigned int offset, FMOD_TIMEUNIT offsettype, const char *name, FMOD_SYNCPOINT **point)`
- `FMOD_RESULT F_API deleteSyncPoint (FMOD_SYNCPOINT *point)`
- `FMOD_RESULT F_API setMode (FMOD_MODE mode)`
- `FMOD_RESULT F_API getMode (FMOD_MODE *mode)`
- `FMOD_RESULT F_API setLoopCount (int loopcount)`
- `FMOD_RESULT F_API getLoopCount (int *loopcount)`
- `FMOD_RESULT F_API setLoopPoints (unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype)`
- `FMOD_RESULT F_API getLoopPoints (unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype)`
- `FMOD_RESULT F_API getMusicNumChannels (int *numchannels)`
- `FMOD_RESULT F_API setMusicChannelVolume (int channel, float volume)`
- `FMOD_RESULT F_API getMusicChannelVolume (int channel, float *volume)`
- `FMOD_RESULT F_API setMusicSpeed (float speed)`
- `FMOD_RESULT F_API getMusicSpeed (float *speed)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`

### `SoundGroup`

**Functions:**

- `FMOD_RESULT F_API release ()`
- `FMOD_RESULT F_API getSystemObject (System **system)`
- `FMOD_RESULT F_API setMaxAudible (int maxaudible)`
- `FMOD_RESULT F_API getMaxAudible (int *maxaudible)`
- `FMOD_RESULT F_API setMaxAudibleBehavior (FMOD_SOUNDGROUP_BEHAVIOR behavior)`
- `FMOD_RESULT F_API getMaxAudibleBehavior (FMOD_SOUNDGROUP_BEHAVIOR *behavior)`
- `FMOD_RESULT F_API setMuteFadeSpeed (float speed)`
- `FMOD_RESULT F_API getMuteFadeSpeed (float *speed)`
- `FMOD_RESULT F_API setVolume (float volume)`
- `FMOD_RESULT F_API getVolume (float *volume)`
- `FMOD_RESULT F_API stop ()`
- `FMOD_RESULT F_API getName (char *name, int namelen)`
- `FMOD_RESULT F_API getNumSounds (int *numsounds)`
- `FMOD_RESULT F_API getSound (int index, Sound **sound)`
- `FMOD_RESULT F_API getNumPlaying (int *numplaying)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`

### `SpacerNode` : public cocos2d::CCNode

**Functions:**

- `static SpacerNode* create(size_t grow = 1)`
- `void setGrow(size_t grow)`
- `size_t getGrow() const`

### `SpacerNodeChild` : public SpacerNode

**Functions:**

- `static SpacerNodeChild* create(cocos2d::CCNode* child, size_t grow = 1)`
- `void setContentSize(cocos2d::CCSize const& size) override`

### `System`

**Functions:**

- `FMOD_RESULT F_API release ()`
- `FMOD_RESULT F_API setOutput (FMOD_OUTPUTTYPE output)`
- `FMOD_RESULT F_API getOutput (FMOD_OUTPUTTYPE *output)`
- `FMOD_RESULT F_API getNumDrivers (int *numdrivers)`
- `FMOD_RESULT F_API getDriverInfo (int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels)`
- `FMOD_RESULT F_API setDriver (int driver)`
- `FMOD_RESULT F_API getDriver (int *driver)`
- `FMOD_RESULT F_API setSoftwareChannels (int numsoftwarechannels)`
- `FMOD_RESULT F_API getSoftwareChannels (int *numsoftwarechannels)`
- `FMOD_RESULT F_API setSoftwareFormat (int samplerate, FMOD_SPEAKERMODE speakermode, int numrawspeakers)`
- `FMOD_RESULT F_API getSoftwareFormat (int *samplerate, FMOD_SPEAKERMODE *speakermode, int *numrawspeakers)`
- `FMOD_RESULT F_API setDSPBufferSize (unsigned int bufferlength, int numbuffers)`
- `FMOD_RESULT F_API getDSPBufferSize (unsigned int *bufferlength, int *numbuffers)`
- `FMOD_RESULT F_API setFileSystem (FMOD_FILE_OPEN_CALLBACK useropen, FMOD_FILE_CLOSE_CALLBACK userclose, FMOD_FILE_READ_CALLBACK userread, FMOD_FILE_SEEK_CALLBACK userseek, FMOD_FILE_ASYNCREAD_CALLBACK userasyncread, FMOD_FILE_ASYNCCANCEL_CALLBACK userasynccancel, int blockalign)`
- `FMOD_RESULT F_API attachFileSystem (FMOD_FILE_OPEN_CALLBACK useropen, FMOD_FILE_CLOSE_CALLBACK userclose, FMOD_FILE_READ_CALLBACK userread, FMOD_FILE_SEEK_CALLBACK userseek)`
- `FMOD_RESULT F_API setAdvancedSettings (FMOD_ADVANCEDSETTINGS *settings)`
- `FMOD_RESULT F_API getAdvancedSettings (FMOD_ADVANCEDSETTINGS *settings)`
- `FMOD_RESULT F_API setCallback (FMOD_SYSTEM_CALLBACK callback, FMOD_SYSTEM_CALLBACK_TYPE callbackmask = FMOD_SYSTEM_CALLBACK_ALL)`
- `FMOD_RESULT F_API setPluginPath (const char *path)`
- `FMOD_RESULT F_API loadPlugin (const char *filename, unsigned int *handle, unsigned int priority = 0)`
- `FMOD_RESULT F_API unloadPlugin (unsigned int handle)`
- `FMOD_RESULT F_API getNumNestedPlugins (unsigned int handle, int *count)`
- `FMOD_RESULT F_API getNestedPlugin (unsigned int handle, int index, unsigned int *nestedhandle)`
- `FMOD_RESULT F_API getNumPlugins (FMOD_PLUGINTYPE plugintype, int *numplugins)`
- `FMOD_RESULT F_API getPluginHandle (FMOD_PLUGINTYPE plugintype, int index, unsigned int *handle)`
- `FMOD_RESULT F_API getPluginInfo (unsigned int handle, FMOD_PLUGINTYPE *plugintype, char *name, int namelen, unsigned int *version)`
- `FMOD_RESULT F_API setOutputByPlugin (unsigned int handle)`
- `FMOD_RESULT F_API getOutputByPlugin (unsigned int *handle)`
- `FMOD_RESULT F_API createDSPByPlugin (unsigned int handle, DSP **dsp)`
- `FMOD_RESULT F_API getDSPInfoByPlugin (unsigned int handle, const FMOD_DSP_DESCRIPTION **description)`
- `FMOD_RESULT F_API registerCodec (FMOD_CODEC_DESCRIPTION *description, unsigned int *handle, unsigned int priority = 0)`
- `FMOD_RESULT F_API registerDSP (const FMOD_DSP_DESCRIPTION *description, unsigned int *handle)`
- `FMOD_RESULT F_API registerOutput (const FMOD_OUTPUT_DESCRIPTION *description, unsigned int *handle)`
- `FMOD_RESULT F_API init (int maxchannels, FMOD_INITFLAGS flags, void *extradriverdata)`
- `FMOD_RESULT F_API close ()`
- `FMOD_RESULT F_API update ()`
- `FMOD_RESULT F_API setSpeakerPosition (FMOD_SPEAKER speaker, float x, float y, bool active)`
- `FMOD_RESULT F_API getSpeakerPosition (FMOD_SPEAKER speaker, float *x, float *y, bool *active)`
- `FMOD_RESULT F_API setStreamBufferSize (unsigned int filebuffersize, FMOD_TIMEUNIT filebuffersizetype)`
- `FMOD_RESULT F_API getStreamBufferSize (unsigned int *filebuffersize, FMOD_TIMEUNIT *filebuffersizetype)`
- `FMOD_RESULT F_API set3DSettings (float dopplerscale, float distancefactor, float rolloffscale)`
- `FMOD_RESULT F_API get3DSettings (float *dopplerscale, float *distancefactor, float *rolloffscale)`
- `FMOD_RESULT F_API set3DNumListeners (int numlisteners)`
- `FMOD_RESULT F_API get3DNumListeners (int *numlisteners)`
- `FMOD_RESULT F_API set3DListenerAttributes (int listener, const FMOD_VECTOR *pos, const FMOD_VECTOR *vel, const FMOD_VECTOR *forward, const FMOD_VECTOR *up)`
- `FMOD_RESULT F_API get3DListenerAttributes (int listener, FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *forward, FMOD_VECTOR *up)`
- `FMOD_RESULT F_API set3DRolloffCallback (FMOD_3D_ROLLOFF_CALLBACK callback)`
- `FMOD_RESULT F_API mixerSuspend ()`
- `FMOD_RESULT F_API mixerResume ()`
- `FMOD_RESULT F_API getDefaultMixMatrix (FMOD_SPEAKERMODE sourcespeakermode, FMOD_SPEAKERMODE targetspeakermode, float *matrix, int matrixhop)`
- `FMOD_RESULT F_API getSpeakerModeChannels (FMOD_SPEAKERMODE mode, int *channels)`
- `FMOD_RESULT F_API getVersion (unsigned int *version)`
- `FMOD_RESULT F_API getOutputHandle (void **handle)`
- `FMOD_RESULT F_API getChannelsPlaying (int *channels, int *realchannels = 0)`
- `FMOD_RESULT F_API getCPUUsage (FMOD_CPU_USAGE *usage)`
- `FMOD_RESULT F_API getFileUsage (long long *sampleBytesRead, long long *streamBytesRead, long long *otherBytesRead)`
- `FMOD_RESULT F_API createSound (const char *name_or_data, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO *exinfo, Sound **sound)`
- `FMOD_RESULT F_API createStream (const char *name_or_data, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO *exinfo, Sound **sound)`
- `FMOD_RESULT F_API createDSP (const FMOD_DSP_DESCRIPTION *description, DSP **dsp)`
- `FMOD_RESULT F_API createDSPByType (FMOD_DSP_TYPE type, DSP **dsp)`
- `FMOD_RESULT F_API createChannelGroup (const char *name, ChannelGroup **channelgroup)`
- `FMOD_RESULT F_API createSoundGroup (const char *name, SoundGroup **soundgroup)`
- `FMOD_RESULT F_API createReverb3D (Reverb3D **reverb)`
- `FMOD_RESULT F_API playSound (Sound *sound, ChannelGroup *channelgroup, bool paused, Channel **channel)`
- `FMOD_RESULT F_API playDSP (DSP *dsp, ChannelGroup *channelgroup, bool paused, Channel **channel)`
- `FMOD_RESULT F_API getChannel (int channelid, Channel **channel)`
- `FMOD_RESULT F_API getDSPInfoByType (FMOD_DSP_TYPE type, const FMOD_DSP_DESCRIPTION **description)`
- `FMOD_RESULT F_API getMasterChannelGroup (ChannelGroup **channelgroup)`
- `FMOD_RESULT F_API getMasterSoundGroup (SoundGroup **soundgroup)`
- `FMOD_RESULT F_API attachChannelGroupToPort (FMOD_PORT_TYPE portType, FMOD_PORT_INDEX portIndex, ChannelGroup *channelgroup, bool passThru = false)`
- `FMOD_RESULT F_API detachChannelGroupFromPort (ChannelGroup *channelgroup)`
- `FMOD_RESULT F_API setReverbProperties (int instance, const FMOD_REVERB_PROPERTIES *prop)`
- `FMOD_RESULT F_API getReverbProperties (int instance, FMOD_REVERB_PROPERTIES *prop)`
- `FMOD_RESULT F_API lockDSP ()`
- `FMOD_RESULT F_API unlockDSP ()`
- `FMOD_RESULT F_API getRecordNumDrivers (int *numdrivers, int *numconnected)`
- `FMOD_RESULT F_API getRecordDriverInfo (int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels, FMOD_DRIVER_STATE *state)`
- `FMOD_RESULT F_API getRecordPosition (int id, unsigned int *position)`
- `FMOD_RESULT F_API recordStart (int id, Sound *sound, bool loop)`
- `FMOD_RESULT F_API recordStop (int id)`
- `FMOD_RESULT F_API isRecording (int id, bool *recording)`
- `FMOD_RESULT F_API createGeometry (int maxpolygons, int maxvertices, Geometry **geometry)`
- `FMOD_RESULT F_API setGeometrySettings (float maxworldsize)`
- `FMOD_RESULT F_API getGeometrySettings (float *maxworldsize)`
- `FMOD_RESULT F_API loadGeometry (const void *data, int datasize, Geometry **geometry)`
- `FMOD_RESULT F_API getGeometryOcclusion (const FMOD_VECTOR *listener, const FMOD_VECTOR *source, float *direct, float *reverb)`
- `FMOD_RESULT F_API setNetworkProxy (const char *proxy)`
- `FMOD_RESULT F_API getNetworkProxy (char *proxy, int proxylen)`
- `FMOD_RESULT F_API setNetworkTimeout (int timeout)`
- `FMOD_RESULT F_API getNetworkTimeout (int *timeout)`
- `FMOD_RESULT F_API setUserData (void *userdata)`
- `FMOD_RESULT F_API getUserData (void **userdata)`

### `TaskHolder`

**Functions:**

- `void spawn(F&& future, Cb&& cb)`
- `void spawn(std::string name, F&& future, Cb&& cb)`
- `if constexpr (std::is_void_v<Ret>)`
- `void cancel()`
- `void setName(std::string name)`
- `bool isPending() const`
- `void spawn(F&& future, Cb&& cb)`
- `void spawn(std::string name, F&& future, Cb&& cb)`
- `if constexpr (std::is_void_v<Ret>)`
- `void cancel()`
- `void setName(std::string name)`
- `bool isPending() const`

### `TextDecorationWrapper` : public cocos2d::CCNodeRGBA, public cocos2d::CCLabelProtocol

**Functions:**

- `static TextDecorationWrapper* create( TextRenderer::Label const& label, int decoration, cocos2d::ccColor3B const& color, GLubyte opacity )`
- `static TextDecorationWrapper* wrap( TextRenderer::Label const& label, int decoration, cocos2d::ccColor3B const& color, GLubyte opacity )`
- `void setColor(cocos2d::ccColor3B const& color) override`
- `void setOpacity(GLubyte opacity) override`
- `void updateDisplayedColor(cocos2d::ccColor3B const& color) override`
- `void updateDisplayedOpacity(GLubyte opacity) override`
- `void setString(char const* text) override`
- `char const* getString() override`

### `TextInput` : public cocos2d::CCNode, public TextInputDelegate

**Functions:**

- `static TextInput* create(float width, ZStringView placeholder, ZStringView font = "bigFont.fnt")`
- `void setPlaceholder(gd::string placeholder)`
- `void setLabel(ZStringView label)`
- `void setFilter(gd::string allowedChars)`
- `void setCommonFilter(CommonFilter filter)`
- `void setMaxCharCount(size_t length)`
- `void setPasswordMode(bool enable)`
- `void setWidth(float width)`
- `void setDelegate(TextInputDelegate* delegate, std::optional<int> tag = std::nullopt)`
- `void setCallbackEnabled(bool enabled)`
- `void setEnabled(bool enabled)`
- `void setTextAlign(TextInputAlign align)`
- `void hideBG()`
- `void setString(gd::string str, bool triggerCallback = false)`
- `gd::string getString() const`
- `bool isCallbackEnabled() const`
- `void focus()`
- `void defocus()`
- `CCTextInputNode* getInputNode() const`
- `NineSlice* getBGSprite() const`

### `TextLinkedButtonWrapper` : public cocos2d::CCMenuItemSprite,
        public cocos2d::CCLabelProtocol

**Functions:**

- `static TextLinkedButtonWrapper* create( TextRenderer::Label const& label, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler handler )`
- `static TextLinkedButtonWrapper* wrap( TextRenderer::Label const& label, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler handler )`
- `void link(TextLinkedButtonWrapper* other)`
- `void selectedWithoutPropagation(bool selected)`
- `void selected() override`
- `void unselected() override`
- `void setColor(cocos2d::ccColor3B const& color) override`
- `void setOpacity(GLubyte opacity) override`
- `void updateDisplayedColor(cocos2d::ccColor3B const& color) override`
- `void updateDisplayedOpacity(GLubyte opacity) override`
- `void setString(char const* text) override`
- `char const* getString() override`

### `Timer`

**Functions:**

- `void reset()`
- `clock_point time() const`
- `int64_t elapsed() const`
- `std::string elapsedAsString() const`
- `if constexpr (std::is_same<Duration, std::chrono::milliseconds>::value)`
- `else if constexpr (std::is_same<Duration, std::chrono::microseconds>::value)`
- `else if constexpr (std::is_same<Duration, std::chrono::nanoseconds>::value)`

### `string`

**Functions:**

- `public: string()`
- `void clear()`
- `char& at(size_t pos)`
- `char const& at(size_t pos) const`
- `char* data()`
- `char const* data() const`
- `char const* c_str() const`
- `size_t size() const`
- `size_t capacity() const`
- `bool empty() const`
- `void clear()`
- `char& at(size_t pos)`
- `char const& at(size_t pos) const`
- `char* data()`
- `char const* data() const`
- `char const* c_str() const`
- `size_t size() const`
- `size_t capacity() const`
- `bool empty() const`

### `vector`

**Functions:**

- `void clear()`
- `T& front()`
- `void clear()`
- `T& front()`

### `xml_named_node_iterator`

**Functions:**

- `endif xml_named_node_iterator()`
- `endif xml_named_node_iterator()`

### `xml_object_range`

**Functions:**

- `It begin() const`
- `It end() const`
- `It begin() const`
- `It end() const`
