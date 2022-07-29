#pragma once

#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>
#include <cheat/game/Entity.h>
#include <cheat/game/IEntityFilter.h>

namespace cheat::feature 
{

	class InteractiveMap : public Feature
    {
	public:
		enum class SaveAttachType
		{
			Account,
			Profile,
			Global
		};

		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<bool> f_SeparatedWindows;
		config::Field<bool> f_CompletionLogShow;

		config::Field<config::Enum<SaveAttachType>> f_STFixedPoints;
		config::Field<config::Enum<SaveAttachType>> f_STCustomPoints;
		config::Field<config::Enum<SaveAttachType>> f_STCompletedPoints;

		config::Field<float> f_IconSize;
		config::Field<float> f_MinimapIconSize;
		config::Field<bool> f_DynamicSize;
		config::Field<bool> f_ShowHDIcons;
		
		config::Field<bool> f_ShowCompleted;
		config::Field<float> f_CompletePointTransparency;
		config::Field<bool> f_ShowInCompleted;
		config::Field<float> f_InCompletePointTransparency;

		config::Field<bool> f_AutoDetectNewItems;
		config::Field<bool> f_AutoFixItemPositions;
		config::Field<bool> f_ObjectCheckOnlyShowed;
		config::Field<float> f_ObjectDetectRange;
		config::Field<int> f_CheckObjectsDelay;

		config::Field<bool> f_AutoDetectGatheredItems;
		config::Field<float> f_GatheredItemsDetectRange;
		
		config::Field<Hotkey> f_CompleteNearestPoint;
		config::Field<Hotkey> f_RevertLatestCompletion;
		config::Field<bool> f_CompleteOnlyViewed;
		config::Field<float> f_PointFindRange;
		
		static InteractiveMap& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		void DrawExternal() override;

		struct PointData
		{
			uint32_t id;

			uint32_t sceneID;
			uint32_t labelID;

			app::Vector2 levelPosition;

			bool completed;
			int64_t completeTimestamp;

			bool custom;
			int64_t creationTimestamp;

			bool fixed;
			app::Vector2 originPosition;
		};

		// std::optional<PointData> GetSelectedPoint();
		PointData* GetHoveredPoint();

		std::vector<PointData*> GetEntityPoints(game::Entity* entity, bool completed = false, uint32_t sceneID = 0);
		PointData* FindNearestPoint(const app::Vector2& levelPosition, float range = 0.0f, bool onlyShowed = true, bool completed = false, uint32_t sceneID = 0);
		PointData* FindEntityPoint(game::Entity* entity, float range = 0.0f, uint32_t sceneID = 0);

		void CompletePoint(PointData* pointData);
		void UncompletePoint(PointData* pointData);
		void RevertLatestPointCompleting();

		void FixPointPosition(PointData* pointData, app::Vector2 fixedPosition);
		void UnfixPoitnPosition(PointData* pointData);

		void AddCustomPoint(uint32_t sceneID, uint32_t labelID, app::Vector2 levelPosition);
		void RemoveCustomPoint(PointData* pointData);

	private:

		InteractiveMap();

		struct ScallingInput
		{
			app::Vector2 normal1;
			app::Vector2 normal2;
			app::Vector2 scalled1;
			app::Vector2 scalled2;
		};

		struct LabelData
		{
			uint32_t id;
			uint32_t sceneID;

			std::string name;
			std::string clearName;
			config::Field<bool> enabled;

			std::map<uint32_t, PointData> points;
			uint32_t completedCount;

			game::IEntityFilter* filter;
			bool supportGatherDetect;
		};

		struct CategoryData
		{
			std::string name;
			std::vector<LabelData*> children;
		};

		struct SceneData
		{
			std::map<uint32_t, LabelData> labels;
			std::map<std::string, LabelData*> nameToLabel;
			std::vector<CategoryData> categories;
		};

		std::map<uint32_t, SceneData> m_ScenesData;

		std::mutex m_UserDataMutex; // Support multithread
		config::Field<nlohmann::json> f_CustomPointsJson;
		config::Field<nlohmann::json> f_FixedPointsJson;
		config::Field<nlohmann::json> f_CompletedPointsJson;
		
		config::Field<uint32_t> f_CustomPointIndex; // Stores last index for new custom points
		config::Field<uint32_t> f_LastUserID;

		std::unordered_set<PointData*> m_CustomPoints;
		std::unordered_set<PointData*> m_FixedPoints;
		std::list<PointData*> m_CompletedPoints;

		std::mutex m_PointMutex;
		// PointData* m_SelectedPoint;
		PointData* m_HoveredPoint;

		std::string m_SearchText;
	
		// Parsing map data
		PointData ParsePointData(const nlohmann::json& data);
		void LoadLabelData(const nlohmann::json& data, uint32_t sceneID, uint32_t labelID);
		void LoadCategoriaData(const nlohmann::json& data, uint32_t sceneID);
		void LoadSceneData(const nlohmann::json& data, uint32_t sceneID);
		void LoadScenesData();

		
		void ApplySceneScalling(uint32_t sceneId, const ScallingInput& input);
		void ApplyScaling();

		void InitializeEntityFilter(game::IEntityFilter* filter, const std::string& clearName);
		void InitializeEntityFilters();

		void InitializeGatherDetectItems();

		// Loading user data
		using ResetElementFunc = bool (InteractiveMap::*)(LabelData* labelData, PointData* point);
		using LoadElementFunc = void (InteractiveMap::*)(LabelData* labelData, const nlohmann::json& data);
		using SaveElementFunc = void (InteractiveMap::*)(nlohmann::json& jObject, PointData* point);

		void ResetUserData(ResetElementFunc func);
		void LoadUserData(const nlohmann::json& data, LoadElementFunc func);
		void SaveUserData(nlohmann::json& data, SaveElementFunc func);

		void LoadCompletedPointData(LabelData* labelData, const nlohmann::json& data);
		void SaveCompletedPointData(nlohmann::json& jObject, PointData* point);
		bool ResetCompletedPointData(LabelData* label, PointData* point);
		void ReorderCompletedPointDataByTimestamp();
		
		void LoadCustomPointData(LabelData* labelData, const nlohmann::json& data);
		void SaveCustomPointData(nlohmann::json& jObject, PointData* point);
		bool ResetCustomPointData(LabelData* label, PointData* point);

		void LoadFixedPointData(LabelData* labelData, const nlohmann::json& data);
		void SaveFixedPointData(nlohmann::json& jObject, PointData* point);
		bool ResetFixedPointData(LabelData* label, PointData* point);

		void LoadCompletedPoints();
		void SaveCompletedPoints();
		void ResetCompletedPoints();

		void LoadCustomPoints();
		void SaveCustomPoints();
		void ResetCustomPoints();

		void LoadFixedPoints();
		void SaveFixedPoints();
		void ResetFixedPoints();

		void CreateUserDataField(const char* name, config::Field<nlohmann::json>& field, SaveAttachType saveType);
		void UpdateUserDataField(config::Field<nlohmann::json>& field, SaveAttachType saveType, bool move = false);
		std::string GetUserDataFieldSection(SaveAttachType saveType);

		void OnConfigProfileChanged();
		void OnAccountChanged(uint32_t userID);

		// Drawing
		void DrawMenu();
		void DrawFilters(const bool searchFixed = true);
		void DrawFilter(LabelData& label);

		void DrawPoint(const PointData& pointData, const ImVec2& screenPosition, float radius, float radiusSquared, ImTextureID texture, bool selectable = true);
		void DrawPoints();

		void DrawMinimapPoints();
		
		// Block interact
		void OnWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool& cancelled);

		// Detecting stuff
		void OnGameUpdate();
		void CheckObjects();
		void OnItemGathered(game::Entity* entity);

		// Utility
		static PointData* FindNearestPoint(const LabelData& label, const app::Vector2& levelPosition, float range = 0.0f, bool completed = false);
		std::vector<InteractiveMap::LabelData*> FindLabelsByClearName(const std::string& clearName);

		// Hooks
		static void GadgetModule_OnGadgetInteractRsp_Hook(void* __this, app::GadgetInteractRsp* notify, MethodInfo* method);
		static void InLevelMapPageContext_UpdateView_Hook(app::InLevelMapPageContext* __this, MethodInfo* method);
		static void InLevelMapPageContext_ZoomMap_Hook(app::InLevelMapPageContext* __this, float value, MethodInfo* method);
		static void MonoMiniMap_Update_Hook(app::MonoMiniMap* __this, MethodInfo* method);
	};
}

