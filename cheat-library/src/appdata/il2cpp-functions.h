// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2017.4.15 - 2017.4.40

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************
using namespace app;


// Map hooks
DO_APP_FUNC(0x013815E0, void, InLevelMapPageContext_OnMarkClicked, (InLevelMapPageContext* __this, MonoMapMark* mark, MethodInfo* method));
DO_APP_FUNC(0x01390800, void, InLevelMapPageContext_OnMapClicked, (InLevelMapPageContext* __this, Vector2 screenPos, MethodInfo* method));
DO_APP_FUNC(0x0158AD40, bool, MapModule_IsAreaUnlock, (MBHLOBDPKEC* __this, uint32_t sceneID, uint32_t areaID, MethodInfo* method));
DO_APP_FUNC(0x05036C50, uint16_t, SimpleSafeUInt16_get_Value, (void* __this, LAFKDOLNGNA rawValue, MethodInfo* method));
DO_APP_FUNC(0x03427B90, uint32_t, SimpleSafeUInt32_get_Value, (void* __this, app::SimpleSafeUInt32 rawValue, MethodInfo* method));

// Map utility
DO_APP_FUNC(0x04339D30, Rect, MonoInLevelMapPage_get_mapRect, (MonoInLevelMapPage* __this, MethodInfo* method));
DO_APP_FUNC(0x04339D00, Transform*, MonoInLevelMapPage_get_mapBackground, (MonoInLevelMapPage* __this, MethodInfo* method));


// Teleport hooks
DO_APP_FUNC(0x03253B80, void, GameManager_Update, (GameManager* __this, MethodInfo* method));
DO_APP_FUNC(0x017F49E0, void, LoadingManager_SceneGoto, (LoadingManager* __this, PlayerEnterSceneNotify* notify, MethodInfo* method));
DO_APP_FUNC(0x017F1310, void, LoadingManager_PerformPlayerTransmit, (LoadingManager* __this, Vector3 targetPos, EnterType__Enum enterType, uint32_t token, CMHGHBNDBMG_ECPNDLCPDIE__Enum transType, uint32_t BDFOCMLADLB, MethodInfo* method));
DO_APP_FUNC(0x017F21F0, void, LoadingManager_RequestSceneTransToPoint, (LoadingManager* __this, uint32_t sceneId, uint32_t pointId, void* finishCallBackInForceDrag, MethodInfo* method));
DO_APP_FUNC(0x017F4FE0, bool, LoadingManager_NeedTransByServer, (LoadingManager* __this, uint32_t sceneId, Vector3 position, MethodInfo* method));
DO_APP_FUNC(0x07758D10, Vector3, LocalEntityInfoData_GetTargetPos, (LocalEntityInfoData* __this, MethodInfo* method));


// Unlimited stamina
DO_APP_FUNC(0x04BDB410, void, LevelSyncCombatPlugin_RequestSceneEntityMoveReq, (BKFGGJFIIKC* __this, uint32_t entityId, MotionInfo* syncInfo, bool isReliable, uint32_t HAOCOEMOMBG, MethodInfo* method));
DO_APP_FUNC(0x0186C290, void, DataItem_HandleNormalProp, (DataItem* __this, uint32_t type, int64_t value, DataPropOp__Enum state, MethodInfo* method));


// God mode
DO_APP_FUNC(0x049428D0, void, VCHumanoidMove_NotifyLandVelocity, (VCHumanoidMove* __this, Vector3 velocity, float reachMaxDownVelocityTime, MethodInfo* method));
DO_APP_FUNC(0x015E1C90, bool, Miscs_CheckTargetAttackable, (void* __this, BaseEntity* attackerEntity, /* CBIKBDBKLEG */ BaseEntity* targetEntity, MethodInfo* method));
// DO_APP_FUNC(0x02ADE320, void, LCBaseCombat_FireBeingHitEvent, (LCBaseCombat* __this, uint32_t attackeeRuntimeID, AttackResult* attackResult, MethodInfo* method));


// Cooldown cheats
DO_APP_FUNC(0x024D5450, bool, HumanoidMoveFSM_CheckSprintCooldown, (/* HumanoidMoveFSM */void* __this, MethodInfo* method));
DO_APP_FUNC(0x02548810, bool, LCAvatarCombat_IsEnergyMax, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x0254A170, void, LCAvatarCombat_ChangeEnergy_1, (LCAvatarCombat* __this, ElementType__Enum type, float value, DataPropOp__Enum state, MethodInfo* method));
DO_APP_FUNC(0x0254D660, bool, LCAvatarCombat_OnSkillStart, (LCAvatarCombat* __this, uint32_t skillID, float cdMultipler, MethodInfo* method));
DO_APP_FUNC(0x02546C10, bool, LCAvatarCombat_IsSkillInCD_1, (LCAvatarCombat* __this, LCAvatarCombat_OMIIMOJOHIP* skillInfo, MethodInfo* method));

DO_APP_FUNC(0x0112A110, void, ActorAbilityPlugin_AddDynamicFloatWithRange, (void* __this, String* key, float value, float min, float max, bool forceDoAtRemote, MethodInfo* method));

// Rapid fire
DO_APP_FUNC(0x0318B070, void, LCBaseCombat_DoHitEntity, (LCBaseCombat* __this, uint32_t targetID, AttackResult* attackResult, bool ignoreCheckCanBeHitInMP, MethodInfo* method));
DO_APP_FUNC(0x029B4870, void, Formula_CalcAttackResult, (void* __this, CombatProperty* attackCombatProperty, CombatProperty* defenseCombatProperty, AttackResult* attackResult, BaseEntity* attackerEntity, BaseEntity* attackeeEntity, MethodInfo* method));


// World cheats
DO_APP_FUNC(0x01A56020, void, VCMonsterAIController_TryDoSkill, (/* VCMonsterAIController */ void* __this, uint32_t skillID, MethodInfo* method)); // Manual
DO_APP_FUNC(0x0426A900, void, LCSelectPickup_AddInteeBtnByID, (void* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x0426BDA0, bool, LCSelectPickup_IsInPosition, (void* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x0426C350, bool, LCSelectPickup_IsOutPosition, (void* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x03D31930, void, ItemModule_PickItem, (ItemModule* __this, uint32_t entityID, MethodInfo* method));
DO_APP_FUNC(0x017B0A10, void, LevelSceneElementViewPlugin_Tick, (LevelSceneElementViewPlugin* __this, float inDeltaTime, MethodInfo* method));

// Time functions
DO_APP_FUNC(0x073D35A0, float, Time_get_timeScale, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x073D3940, void, Time_set_timeScale, (void* __this, float value, MethodInfo* method));

// Dialog skipping
DO_APP_FUNC(0x0204A380, bool, TalkDialogContext_get_canClick, (TalkDialogContext* __this, MethodInfo* method)); // delete
DO_APP_FUNC(0x02052990, bool, TalkDialogContext_get_canAutoClick, (TalkDialogContext* __this, MethodInfo* method));
DO_APP_FUNC(0x0204E820, void, TalkDialogContext_OnDialogSelectItem, (TalkDialogContext* __this, Notify* notify, MethodInfo* method));
DO_APP_FUNC(0x0419D8A0, void, InLevelCutScenePageContext_OnFreeClick, (InLevelCutScenePageContext* __this, MethodInfo* method)); // manual
DO_APP_FUNC(0x0419F270, void, InLevelCutScenePageContext_UpdateView, (InLevelCutScenePageContext* __this, MethodInfo* method)); // manual (find by InLevelCutScenePageContext_ShowSkipBtn)
DO_APP_FUNC(0x0419BF40, void, InLevelCutScenePageContext_ClearView, (InLevelCutScenePageContext* __this, MethodInfo* method));


// Protection bypass
DO_APP_FUNC(0x07435920, Byte__Array*, Application_RecordUserData, (void* __this, int32_t nType, MethodInfo* method));


// Networking
DO_APP_FUNC(0x02B572B0, int32_t, KcpNative_kcp_client_send_packet, (void* __this, void* kcp_client, KcpPacket_1* packet, MethodInfo* method));
DO_APP_FUNC(0x02FDCB30, bool, KcpClient_TryDequeueEvent, (void* __this, ClientKcpEvent* evt, MethodInfo* method));
DO_APP_FUNC(0x02663FA0, void, Packet_XorEncrypt, (void* __this, Byte__Array** bytes, int32_t length, MethodInfo* method));


// Lua functions
DO_APP_FUNC(0x04B1C0C0, Byte__Array*, LuaManager_LoadCustomLuaFile, (LuaManager* __this, String** filePath, bool* recycleBytes, MethodInfo* method));
DO_APP_FUNC(0x06018660, void, Lua_xlua_pushasciistring, (void* __this, void* L, String* str, MethodInfo* method));
DO_APP_FUNC(0x047ADA50, void, LuaShellManager_DoString, (void* __this, Byte__Array* byteArray, MethodInfo* method));
DO_APP_FUNC(0x0600E890, void*, LuaEnv_DoString, (void* __this, Byte__Array* chunk, String* chunkName, void* env, MethodInfo* method));
DO_APP_FUNC(0x047ACF40, void, LuaShellManager_ReportLuaShellResult, (void* __this, String* type, String* value, MethodInfo* method)); // Anticheat info


// Debug hooks
DO_APP_FUNC(0x04D07170, AttackResult_1*, AttackResult_FillProtoAttackResult, (AttackResult* __this, uint32_t attackerID, uint32_t defenseId, AttackResult_1* protoAttackResult, MethodInfo* method));
DO_APP_FUNC(0x04BDAC80, void, LevelSyncCombatPlugin_SendFaceToDir, (void* __this, uint32_t runtimeID, Vector3 forward, MethodInfo* method));
DO_APP_FUNC(0x0163EE90, void, BaseEntity_FireEvent, (BaseEntity* __this, BaseEvent* e, bool immediately, MethodInfo* method));
DO_APP_FUNC(0x0116D200, bool, ActorAbilityPlugin_OnEvent, (void* __this, BaseEvent* e, MethodInfo* method));


// Kill aura
DO_APP_FUNC(0x04F8C3A0, void, EvtCrash_Init, (EvtCrash* __this, uint32_t targetID, MethodInfo* method)); // Manual offset
DO_APP_FUNC(0x02F3B3D0, void, EventManager_FireEvent, (EventManager* __this, BaseEvent* e, bool immediately, MethodInfo* method));
DO_APP_FUNC(0x01C11490, bool, FixedBoolStack_get_value, (FixedBoolStack* __this, MethodInfo* method));
DO_APP_FUNC(0x031ADF70, EvtCrash*, CreateCrashEvent, (void* __this, MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x0B381CF8, CreateCrashEvent__MethodInfo);
DO_APP_FUNC(0x028DD7F0, void, BaseMoveSyncPlugin_ConvertSyncTaskToMotionInfo, (BaseMoveSyncPlugin* __this, MethodInfo* method));


// Fishing
DO_APP_FUNC(0x036B9B40, void, FishingModule_RequestFishCastRod, (void* __this, uint32_t baitId, uint32_t rodId, Vector3 pos, uint32_t rodEntityId, MethodInfo* method));

DO_APP_FUNC(0x036BD030, void, FishingModule_RequestFishBite, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x036B9DB0, void, FishingModule_OnFishBiteRsp, (void* __this, FishBiteRsp* rsp, MethodInfo* method));

DO_APP_FUNC(0x036BD440, void, FishingModule_RequestFishBattleBegin, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x036BACD0, void, FishingModule_OnFishBattleBeginRsp, (void* __this, FishBattleBeginRsp* rsp, MethodInfo* method));

DO_APP_FUNC(0x036BAB00, void, FishingModule_RequestFishBattleEnd, (void* __this, FishBattleResult__Enum result, bool isAlwaysBonus, float mxBonusTime, MethodInfo* method));
DO_APP_FUNC(0x036BC180, void, FishingModule_OnFishBattleEndRsp, (void* __this, FishBattleEndRsp* rsp, MethodInfo* method));

DO_APP_FUNC(0x036B8AA0, void, FishingModule_OnExitFishingRsp, (void* __this, void* rsp, MethodInfo* method));
DO_APP_FUNC(0x036BB0B0, void, FishingModule_onFishChosenNotify, (void* __this, void* notify, MethodInfo* method));


// Visuals
DO_APP_FUNC(0x0289DE30, void, SCameraModuleInitialize_SetWarningLocateRatio, (SCameraModuleInitialize* __this, double deltaTime, CameraShareData* data, MethodInfo* method));

// Chest Indicator | RyujinZX#6666
DO_APP_FUNC(0x0487E1D0, bool, LCIndicatorPlugin_DoCheck, (LCIndicatorPlugin* __this, MethodInfo* method));
DO_APP_FUNC(0x0487F680, void, LCIndicatorPlugin_ShowIcon, (LCIndicatorPlugin* __this, MethodInfo* method));
DO_APP_FUNC(0x0487CBF0, void, LCIndicatorPlugin_HideIcon, (LCIndicatorPlugin* __this, MethodInfo* method));

// Auto Cooking | RyujinZX#6666
DO_APP_FUNC(0x01B91500, void, PlayerModule_RequestPlayerCook, (PlayerModule* __this, uint32_t recipeId, uint32_t avatarId, uint32_t qteQuality, uint32_t count, MethodInfo* method));
DO_APP_FUNC(0x01B9E8F0, void, PlayerModule_OnPlayerCookRsp, (PlayerModule* __this, PlayerCookRsp* rsp, MethodInfo* method));
DO_APP_FUNC(0x030E1000, void, CookingQtePageContext_UpdateProficiency, (CookingQtePageContext* __this, MethodInfo* method));
DO_APP_FUNC(0x03AA2920, uint32_t, CookRecipeExcelConfig_get_maxProficiency, (CookRecipeExcelConfig* __this, MethodInfo* method));


// Utility
DO_APP_FUNC(0x015DD910, float,   Miscs_CalcCurrentGroundWaterHeight, (void* __this, float x, float z, MethodInfo* method));
DO_APP_FUNC(0x015DD1D0, float,   Miscs_CalcCurrentGroundHeight,      (void* __this, float x, float z, MethodInfo* method));
DO_APP_FUNC(0x015DCEE0, float,   Miscs_CalcCurrentGroundHeight_1,    (void* __this, float x, float z, float rayStartHeight, float rayDetectLength, int32_t layer, MethodInfo* method));
DO_APP_FUNC(0x015DD370, Vector3, Miscs_CalcCurrentGroundNorm,        (void* __this, Vector3 pos, MethodInfo* method));
DO_APP_FUNC(0x015E9B40, Vector3, Miscs_GenWorldPos,                  (void* __this, Vector2 levelMapPos, MethodInfo* method));
DO_APP_FUNC(0x015E91A0, Vector2, Miscs_GenLevelPos_1,                (void* __this, Vector3 worldPos, MethodInfo* method));
DO_APP_FUNC(0x01601D90, int32_t, Miscs_GetSceneGroundLayerMask,      (void* __this, MethodInfo* method));

DO_APP_FUNC(0x060F0AA0, Vector3, WorldShiftManager_GetRelativePosition, (void* __this, Vector3 pos, MethodInfo* method));
DO_APP_FUNC(0x060F0810, Vector3, WorldShiftManager_GetAbsolutePosition, (void* __this, Vector3 pos, MethodInfo* method));

DO_APP_FUNC(0x014BC6D0, Vector3, ActorUtils_GetAvatarPos,     (void* __this, MethodInfo* method));
DO_APP_FUNC(0x014C3BF0, void,    ActorUtils_SetAvatarPos,     (void* __this, Vector3 pos, MethodInfo* method));
DO_APP_FUNC(0x014C88B0, void,    ActorUtils_SyncAvatarMotion, (void* __this, int32_t state, MethodInfo* method));

DO_APP_FUNC(0x02ECCFE0, Notify, Notify_CreateNotify_1, (void* __this, AJAPIFPNFKP__Enum type, Object* body, MethodInfo* method));

DO_APP_FUNC(0x04D3A960, float, SafeFloat_GetValue, (void* __this, SafeFloat safeFloat, MethodInfo* method));
DO_APP_FUNC(0x04D3A770, SafeFloat, SafeFloat_SetValue, (void* __this, float value, MethodInfo* method));

DO_APP_FUNC(0x01645B20, void, Entity_SetPosition, (BaseEntity* __this, Vector3 position, bool someBool, MethodInfo* method));
DO_APP_FUNC(0x05102970, LCBaseCombat*, BaseEntity_GetBaseCombat, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x0164DC50, String*, BaseEntity_ToStringRelease, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x01659210, void, BaseEntity_SetRelativePosition, (BaseEntity* __this, Vector3 position, bool forceSyncToRigidbody, MethodInfo* method));
DO_APP_FUNC(0x01645B20, void, BaseEntity_SetAbsolutePosition, (BaseEntity* __this, Vector3 abpos, bool forceSyncToRigidbody, MethodInfo* method));
DO_APP_FUNC(0x01650C50, Vector3, BaseEntity_GetAbsolutePosition, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x0164C3F0, Vector3, BaseEntity_GetRelativePosition, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x0163D480, Vector3, BaseEntity_GetForward, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x0163F7E0, Vector3, BaseEntity_GetForwardFast, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x01655C20, Vector3, BaseEntity_GetRight, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x01634200, Vector3, BaseEntity_GetUp, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x0165E590, bool, BaseEntity_IsActive, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x016425C0, Rigidbody*, BaseEntity_GetRigidbody, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x05102780, VCBaseMove*, BaseEntity_GetMoveComponent_1, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x01659D20, List_1_MoleMole_BaseComponent_*, BaseEntity_GetAllLogicComponents, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x0163DCF0, GameObject*, BaseEntity_get_gameObject, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x013B9810, GameObject*, BaseEntity_get_rootGameObject, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x0B2BBB98, BaseEntity_GetMoveComponent_1__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B2DB248, BaseEntity_GetBaseCombat__MethodInfo);

DO_APP_FUNC(0x01555150, BaseEntity*, EntityManager_GetCurrentAvatar, (EntityManager* __this, MethodInfo* method));
DO_APP_FUNC(0x0155F060, CameraEntity*, EntityManager_GetMainCameraEntity, (EntityManager* __this, MethodInfo* method));
DO_APP_FUNC(0x0154A660, BaseEntity*, EntityManager_GetValidEntity, (EntityManager* __this, uint32_t runtimeID, MethodInfo* method));
DO_APP_FUNC(0x0155A580, bool, EntityManager_RemoveEntity, (EntityManager* __this, BaseEntity* entity, uint32_t specifiedRuntimeID, MethodInfo* method));
DO_APP_FUNC(0x0154F520, bool, EntityManager_IsCachedEntity, (EntityManager* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x01560F70, List_1_MoleMole_BaseEntity_*, EntityManager_GetEntities, (EntityManager* __this, MethodInfo* method));

DO_APP_FUNC(0x05D07B50, Bounds, Utils_1_GetBounds, (void* __this, GameObject* go, MethodInfo* method));

// Modify | RyujinZX#6666
DO_APP_FUNC(0x024E0BA0, void, HumanoidMoveFSM_LateTick, (app::HumanoidMoveFSM* __this, float deltaTime, MethodInfo* method));

DO_APP_FUNC(0x03511760, bool, ScenePropManager_GetTreeTypeByPattern, (ScenePropManager* __this, String* pattern, ECGLPBEEEAA__Enum* treeType, MethodInfo* method));

DO_APP_FUNC(0x01997D90, void, NetworkManager_1_RequestHitTreeDropNotify, (NetworkManager_1* __this, Vector3 position, Vector3 hitPostion, ECGLPBEEEAA__Enum treeType, MethodInfo* method));
DO_APP_FUNC(0x0332CD30, uint64_t, GetTimestamp, (void* __this, MethodInfo* method));

DO_APP_FUNC(0x017F43F0, bool, LoadingManager_IsLoaded, (LoadingManager* __this, MethodInfo* method));

// Thanks to | RyujinZX
DO_APP_FUNC(0x019C5D50, void, LCAbilityElement_ReduceModifierDurability, (LCAbilityElement* __this, int32_t modifierDurabilityIndex, float reduceDurability, Nullable_1_Single_ deltaTime, MethodInfo* method));

DO_APP_FUNC(0x035D8B70, BaseEntity*, GadgetEntity_GetOwnerEntity, (GadgetEntity* __this, MethodInfo* method));

DO_APP_FUNC(0x0136FBD0, void, InLevelMapPageContext_ZoomMap, (InLevelMapPageContext* __this, float value, MethodInfo* method));
DO_APP_FUNC(0x013B7F90, void, InLevelMapPageContext_UpdateView, (InLevelMapPageContext* __this, MethodInfo* method));
DO_APP_FUNC(0x01C6A530, bool, UIManager_1_HasEnableMapCamera, (UIManager_1* __this, MethodInfo* method));
DO_APP_FUNC(0x03D64A80, void, MonoMiniMap_Update, (MonoMiniMap* __this, MethodInfo* method));
DO_APP_FUNC(0x03992EB0, MonoMiniMap*, MonoInLevelMainPage_get_miniMap, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x02702190, void, GadgetModule_OnGadgetInteractRsp, (void* __this, GadgetInteractRsp* notify, MethodInfo* method));
DO_APP_FUNC(0x010A60C0, float, InLevelMainPageContext_get_miniMapScale, (InLevelMainPageContext* __this, MethodInfo* method));

// UnityEngine
DO_APP_FUNC(0x073C1A30, void, RenderSettings_set_fog, (void* __this, bool value, MethodInfo* method));
DO_APP_FUNC(0x07436CF0, void, Application_set_targetFrameRate, (void* __this, int32_t value, MethodInfo* method));
DO_APP_FUNC(0x07436840, int32_t, Application_get_targetFrameRate, (void* __this, MethodInfo* method));

DO_APP_FUNC(0x083C28B0, bool, RectTransformUtility_ScreenPointToLocalPointInRectangle, (void* __this, void* rect, Vector2 screenPoint, void* cam, Vector2* localPoint, MethodInfo* method));

DO_APP_FUNC(0x073D7190, Vector3, Transform_get_position, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x073D4A90, void,    Transform_set_position, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x073DAD90, float,   Vector3_Distance, (void* __this, Vector3 a, Vector3 b, MethodInfo* method));
DO_APP_FUNC(0x073D8E70, float,   Vector2_Distance, (void* __this, Vector2 a, Vector2 b, MethodInfo* method));

DO_APP_FUNC(0x074450A0, void, Cursor_set_visible,   (void* __this, bool value, MethodInfo* method));
DO_APP_FUNC(0x07445050, void, Cursor_set_lockState, (void* __this, CursorLockMode__Enum value, MethodInfo* method));
DO_APP_FUNC(0x07445000, bool, Cursor_get_visible,   (void* __this, MethodInfo* method));

DO_APP_FUNC(0x08334350, void, Rigidbody_set_detectCollisions, (Rigidbody* __this, bool value, MethodInfo* method));
DO_APP_FUNC(0x08334530, void, Rigidbody_set_isKinematic,      (Rigidbody* __this, bool value, MethodInfo* method));
DO_APP_FUNC(0x08333840, void, Rigidbody_set_velocity,         (Rigidbody* __this, Vector3 value, MethodInfo * method));

DO_APP_FUNC(0x073D3140, float, Time_get_deltaTime, (void* __this, MethodInfo* method));

DO_APP_FUNC(0x0743D0A0, app::Vector3, Camera_WorldToScreenPoint, (app::Camera* __this, app::Vector3 position, MethodInfo* method));
DO_APP_FUNC(0x0743DBF0, Camera*, Camera_get_main, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x0743DF30, int32_t, Camera_get_pixelWidth, (Camera* __this, MethodInfo* method));
DO_APP_FUNC(0x0743DE60, int32_t, Camera_get_pixelHeight, (Camera* __this, MethodInfo* method));

DO_APP_FUNC(0x073C9A50, int32_t, Screen_get_width, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x073C98F0, int32_t, Screen_get_height, (void* __this, MethodInfo* method));

DO_APP_FUNC(0x07438F50, bool, Behaviour_get_isActiveAndEnabled, (Behaviour* __this, MethodInfo* method));

DO_APP_FUNC(0x074E9960, Vector3, Quaternion_get_eulerAngles, (Quaternion__Boxed* __this, MethodInfo* method));
DO_APP_FUNC(0x073D73E0, Quaternion, Transform_get_rotation, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x073BFD20, Rect, RectTransform_get_rect, (RectTransform* __this, MethodInfo* method));
DO_APP_FUNC(0x083C1430, float, Canvas_get_scaleFactor, (void* __this, MethodInfo* method));

// Singletons
DO_APP_FUNC(0x07626D40, void*, Singleton_GetInstance, (void* __this, MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x0B327AD0, Singleton_1_MBHLOBDPKEC__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B2C2AC0, Singleton_1_LoadingManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B2B2A80, Singleton_1_EntityManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B2B4FC8, Singleton_1_InteractionManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B37C078, Singleton_1_MessageInfo__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B29F2D8, Singleton_1_UIManager_1__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B2ACD50, Singleton_1_ItemModule__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B2B3818, Singleton_1_EventManager__get_Instance__MethodInfo);

// 2.6
DO_APP_FUNC_METHODINFO(0x0B2EC728, Singleton_1_PlayerModule__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B2FD3D0, Singleton_1_MapManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B321D50, Singleton_1_ScenePropManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x0B3A9738, Singleton_1_NetworkManager_1__get_Instance__MethodInfo);

