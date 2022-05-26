#include "pch-il2cpp.h"
#include "PacketParser.h"

#include "MessageManager.h"
namespace sniffer
{

	PacketParser::PacketParser(const std::string& protoDirPath, const std::string& protoIDPath)
		: m_ProtoManager()
	{
		m_ProtoManager.Load(protoIDPath, protoDirPath);
		UpdateUnionPacketIDs();
	}

	void PacketParser::SetProtoDir(const std::string& protoDir)
	{
		m_ProtoManager.LoadProtoDir(protoDir);
		UpdateUnionPacketIDs();
	}

	void PacketParser::SetProtoIDPath(const std::string& protoIDPath)
	{
		m_ProtoManager.LoadProtoDir(protoIDPath);
		UpdateUnionPacketIDs();
	}

	bool PacketParser::Parse(PacketData& data)
	{
		auto name = m_ProtoManager.GetName(data.messageID);
		if (!name)
			return false;

		auto head = m_ProtoManager.GetJson("PacketHead", data.headRawData);
		if (!head)
			return false;

		auto message = m_ProtoManager.GetJson(data.messageID, data.messageRawData);
		if (!message)
			return false;

		data.name = *name;
		data.headJson = *head;
		data.messageJson = *message;
		return true;
	}

	bool PacketParser::IsUnionPacket(const PacketData& data)
	{
		return m_UnionPacketIds.count(data.messageID) > 0;
	}

	std::vector<PacketData> PacketParser::ParseUnionPacket(const PacketData& data)
	{
		if (!IsUnionPacket(data))
			return {};

		auto parseFunction = m_UnionPacketIds[data.messageID];
		return (this->*parseFunction)(data);
	}

	PacketData PacketParser::CreateNestedPacket(const PacketData& parent, std::string bodyEncoded, int16_t packetID)
	{
		PacketData nestedPacketData = MessageManager::CreateMessage<PacketData>();
		nestedPacketData.headRawData = parent.headRawData;
		nestedPacketData.headJson = parent.headJson;
		nestedPacketData.messageRawData = util::base64_decode(bodyEncoded);
		nestedPacketData.messageID = packetID;
		nestedPacketData.valid = true;
		nestedPacketData.ioType = parent.ioType;
		nestedPacketData.parentPacketID = parent.sequenceID();

		if (packetID != 0)
			Parse(nestedPacketData);

		return nestedPacketData;
	}

	std::vector<PacketData> PacketParser::ParseUnionCmdNotify(const PacketData& data)
	{
		nlohmann::json cmdListObject = nlohmann::json::parse(data.messageJson);

		std::vector<PacketData> packets;
		for (auto& cmd : cmdListObject["cmdList"])
		{
			auto nestedPacketData = CreateNestedPacket(data, cmd["body"], cmd["messageId"]);
			packets.push_back(nestedPacketData);

			if (IsUnionPacket(nestedPacketData))
			{
				auto nestedNestedPackets = ParseUnionPacket(nestedPacketData);
				packets.insert(packets.end(), nestedNestedPackets.begin(), nestedNestedPackets.end());
			}
			continue;
		}
		return packets;
	}

	std::optional<PacketData> PacketParser::ParseAbilityInvokeEntry(const PacketData& parent, const nlohmann::json& entry)
	{
		static std::map<std::string, std::string> abilityArgument2Proto = 
		{
			{ "ABILITY_META_MODIFIER_CHANGE", "AbilityMetaModifierChange" },
			{ "ABILITY_META_COMMAND_MODIFIER_CHANGE_REQUEST", "AbilityMetaCommandModifierChangeRequest" },
			{ "ABILITY_META_SPECIAL_FLOAT_ARGUMENT", "AbilityMetaSpecialFloatArgument" },
			{ "ABILITY_META_OVERRIDE_PARAM", "AbilityMetaOverrideParam" },
			{ "ABILITY_META_CLEAR_OVERRIDE_PARAM", "AbilityMetaClearOverrideParam" },
			{ "ABILITY_META_REINIT_OVERRIDEMAP", "AbilityMetaReinitOverridemap" },
			{ "ABILITY_META_GLOBAL_FLOAT_VALUE", "AbilityMetaGlobalFloatValue" },
			{ "ABILITY_META_CLEAR_GLOBAL_FLOAT_VALUE", "AbilityMetaClearGlobalFloatValue" },
			{ "ABILITY_META_ABILITY_ELEMENT_STRENGTH", "AbilityMetaAbilityElementStrength" },
			{ "ABILITY_META_ADD_OR_GET_ABILITY_AND_TRIGGER", "AbilityMetaAddOrGetAbilityAndTrigger" },
			{ "ABILITY_META_SET_KILLED_SETATE", "AbilityMetaSetKilledSetate" },
			{ "ABILITY_META_SET_ABILITY_TRIGGER", "AbilityMetaSetAbilityTrigger" },
			{ "ABILITY_META_ADD_NEW_ABILITY", "AbilityMetaAddNewAbility" },
			{ "ABILITY_META_REMOVE_ABILITY", "AbilityMetaRemoveAbility" },
			{ "ABILITY_META_SET_MODIFIER_APPLY_ENTITY", "AbilityMetaSetModifierApplyEntity" },
			{ "ABILITY_META_MODIFIER_DURABILITY_CHANGE", "AbilityMetaModifierDurabilityChange" },
			{ "ABILITY_META_ELEMENT_REACTION_VISUAL", "AbilityMetaElementReactionVisual" },
			{ "ABILITY_META_SET_POSE_PARAMETER", "AbilityMetaSetPoseParameter" },
			{ "ABILITY_META_UPDATE_BASE_REACTION_DAMAGE", "AbilityMetaUpdateBaseReactionDamage" },
			{ "ABILITY_META_TRIGGER_ELEMENT_REACTION", "AbilityMetaTriggerElementReaction" },
			{ "ABILITY_META_LOSE_HP", "AbilityMetaLoseHp" },
			{ "ABILITY_ACTION_TRIGGER_ABILITY", "AbilityActionTriggerAbility" },
			{ "ABILITY_ACTION_SET_CRASH_DAMAGE", "AbilityActionSetCrashDamage" },
			{ "ABILITY_ACTION_EFFECT", "AbilityActionEffect" },
			{ "ABILITY_ACTION_SUMMON", "AbilityActionSummon" },
			{ "ABILITY_ACTION_BLINK", "AbilityActionBlink" },
			{ "ABILITY_ACTION_CREATE_GADGET", "AbilityActionCreateGadget" },
			{ "ABILITY_ACTION_APPLY_LEVEL_MODIFIER", "AbilityActionApplyLevelModifier" },
			{ "ABILITY_ACTION_GENERATE_ELEM_BALL", "AbilityActionGenerateElemBall" },
			{ "ABILITY_ACTION_SET_RANDOM_OVERRIDE_MAP_VALUE", "AbilityActionSetRandomOverrideMapValue" },
			{ "ABILITY_ACTION_SERVER_MONSTER_LOG", "AbilityActionServerMonsterLog" },
			{ "ABILITY_ACTION_CREATE_TILE", "AbilityActionCreateTile" },
			{ "ABILITY_ACTION_DESTROY_TILE", "AbilityActionDestroyTile" },
			{ "ABILITY_ACTION_FIRE_AFTER_IMAGE", "AbilityActionFireAfterImage" },
			{ "ABILITY_MIXIN_AVATAR_STEER_BY_CAMERA", "AbilityMixinAvatarSteerByCamera" },
			{ "ABILITY_MIXIN_MONSTER_DEFEND", "AbilityMixinMonsterDefend" },
			{ "ABILITY_MIXIN_WIND_ZONE", "AbilityMixinWindZone" },
			{ "ABILITY_MIXIN_COST_STAMINA", "AbilityMixinCostStamina" },
			{ "ABILITY_MIXIN_ELITE_SHIELD", "AbilityMixinEliteShield" },
			{ "ABILITY_MIXIN_ELEMENT_SHIELD", "AbilityMixinElementShield" },
			{ "ABILITY_MIXIN_GLOBAL_SHIELD", "AbilityMixinGlobalShield" },
			{ "ABILITY_MIXIN_SHIELD_BAR", "AbilityMixinShieldBar" },
			{ "ABILITY_MIXIN_WIND_SEED_SPAWNER", "AbilityMixinWindSeedSpawner" },
			{ "ABILITY_MIXIN_DO_ACTION_BY_ELEMENT_REACTION", "AbilityMixinDoActionByElementReaction" },
			{ "ABILITY_MIXIN_FIELD_ENTITY_COUNT_CHANGE", "AbilityMixinFieldEntityCountChange" },
			{ "ABILITY_MIXIN_SCENE_PROP_SYNC", "AbilityMixinScenePropSync" },
			{ "ABILITY_MIXIN_WIDGET_MP_SUPPORT", "AbilityMixinWidgetMpSupport" }
		};

		if (entry.count("abilityData") == 0 || entry.count("argumentType") == 0)
			return {};

		std::string argumentType = entry["argumentType"];
		if (abilityArgument2Proto.count(argumentType) == 0)
			return {};

		PacketData nestedPacketData = CreateNestedPacket(parent, entry["abilityData"]);
		nestedPacketData.name = abilityArgument2Proto[argumentType];

		auto jsonData = m_ProtoManager.GetJson(nestedPacketData.name, nestedPacketData.messageRawData);
		nestedPacketData.messageJson = jsonData ? *jsonData : "{}";
		return nestedPacketData;
	}

	std::vector<PacketData> PacketParser::ParseAbilityInvocationsNotify(const PacketData& data)
	{
		auto combatJsonObject = nlohmann::json::parse(data.messageJson);
		std::vector<PacketData> packets = {};
		for (auto& invokeEntry : combatJsonObject["invokes"])
		{
			auto abilityPacketData = ParseAbilityInvokeEntry(data, invokeEntry);
			if (abilityPacketData)
				packets.push_back(*abilityPacketData);
		}
		return packets;
	}

	std::optional<PacketData> PacketParser::ParseCombatInvokeEntry(const PacketData& parent, const nlohmann::json& entry)
	{
		static std::map<std::string, std::string> combateTypeProtos = {
			{ "ENTITY_MOVE", "EntityMoveInfo" },
			{ "COMBAT_EVT_BEING_HIT", "EvtBeingHitInfo" },
			{ "COMBAT_ANIMATOR_STATE_CHANGED", "EvtAnimatorStateChangedInfo" },
			{ "COMBAT_FACE_TO_DIR", "EvtFaceToDirInfo" },
			{ "COMBAT_SET_ATTACK_TARGET", "EvtSetAttackTargetInfo" },
			{ "COMBAT_RUSH_MOVE", "EvtRushMoveInfo" },
			{ "COMBAT_ANIMATOR_PARAMETER_CHANGED", "EvtAnimatorParameterInfo" },
			{ "SYNC_ENTITY_POSITION", "EvtSyncEntityPositionInfo" },
			{ "COMBAT_STEER_MOTION_INFO", "EvtCombatSteerMotionInfo" },
			{ "COMBAT_FORCE_SET_POSITION_INFO", "EvtCombatForceSetPosInfo" },
			{ "COMBAT_FORCE_SET_POS_INFO", "EvtCombatForceSetPosInfo" },
			{ "COMBAT_COMPENSATE_POS_DIFF", "EvtCompensatePosDiffInfo" },
			{ "COMBAT_MONSTER_DO_BLINK", "EvtMonsterDoBlink" },
			{ "COMBAT_FIXED_RUSH_MOVE", "EvtFixedRushMove" },
			{ "COMBAT_SYNC_TRANSFORM", "EvtSyncTransform" },
			{ "COMBAT_LIGHT_CORE_MOVE", "EvtLightCoreMove" }
		};

		if (!entry["argumentType"].is_string())
			return {};

		std::string argumentType = entry["argumentType"];

		if (combateTypeProtos.count(argumentType) == 0)
		{
			LOG_WARNING("Failed to find argument type %s", argumentType.c_str());
			return {};
		}

		PacketData nestedPacketData = CreateNestedPacket(parent, entry["combatData"]);
		nestedPacketData.name = combateTypeProtos[argumentType];

		auto jsonData = m_ProtoManager.GetJson(nestedPacketData.name, nestedPacketData.messageRawData);
		nestedPacketData.messageJson = jsonData ? *jsonData : "{}";
		return nestedPacketData;
	}

	std::vector<PacketData> PacketParser::ParseCombatInvocationsNotify(const PacketData& data)
	{
		auto combatJsonObject = nlohmann::json::parse(data.messageJson);
		std::vector<PacketData> packets = {};
		for (auto& invokeEntry : combatJsonObject["invokeList"])
		{
			auto combatPacketData = ParseCombatInvokeEntry(data, invokeEntry);
			if (combatPacketData)
				packets.push_back(*combatPacketData);
		}
		return packets;
	}

	void PacketParser::UpdateUnionPacketIDs()
	{
		m_UnionPacketIds.clear();
		for (auto& [unionPacketName, parserFunc] : s_UnionPacketNames)
		{
			m_UnionPacketIds[m_ProtoManager.GetId(unionPacketName)] = parserFunc;
		}
	}
}