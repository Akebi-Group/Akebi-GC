#include <pch-il2cpp.h>

#include "filters.h"

namespace cheat::game::filters
{
	namespace collection
	{
		SimpleFilter Book = { app::EntityType__Enum_1::GatherObject, "SkillObj_EmptyGadget" };
		SimpleFilter Viewpoint = { app::EntityType__Enum_1::ViewPoint, "SkillObj_EmptyGadget" };
		ChestFilter RadiantSpincrystal = ChestFilter(game::Chest::ItemType::BGM);
		ChestFilter BookPage = ChestFilter(game::Chest::ItemType::BookPage);
		ChestFilter QuestInteract = ChestFilter(game::Chest::ItemType::QuestInteract);
	}

	namespace chest
	{
		ChestFilter CommonChest = ChestFilter(game::Chest::ChestRarity::Common);
		ChestFilter ExquisiteChest = ChestFilter(game::Chest::ChestRarity::Exquisite);
		ChestFilter PreciousChest = ChestFilter(game::Chest::ChestRarity::Precious);
		ChestFilter LuxuriousChest = ChestFilter(game::Chest::ChestRarity::Luxurious);
		ChestFilter RemarkableChest = ChestFilter(game::Chest::ChestRarity::Remarkable);
		ChestFilter SearchPoint = ChestFilter(game::Chest::ItemType::Investigate);

		ChestFilter SLocked = ChestFilter(game::Chest::ChestState::Locked);
		ChestFilter SInLock = ChestFilter(game::Chest::ChestState::InRock);
		ChestFilter SFrozen = ChestFilter(game::Chest::ChestState::Frozen);
		ChestFilter SBramble = ChestFilter(game::Chest::ChestState::Bramble);
		ChestFilter STrap = ChestFilter(game::Chest::ChestState::Trap);
	}

	namespace featured
	{
		SimpleFilter Anemoculus = { app::EntityType__Enum_1::GatherObject, "WindCrystalShell" };
		SimpleFilter CrimsonAgate = { app::EntityType__Enum_1::GatherObject, "Prop_Essence" };
		SimpleFilter Electroculus = { app::EntityType__Enum_1::GatherObject, "Prop_ElectricCrystal" };
		SimpleFilter Electrogranum = { app::EntityType__Enum_1::Gadget, "ThunderSeedCreate" };
		SimpleFilter FishingPoint = { app::EntityType__Enum_1::FishPool, "_FishingShoal" };
		SimpleFilter Geoculus = { app::EntityType__Enum_1::GatherObject, "RockCrystalShell" };
		WhitelistFilter ItemDrops = { std::vector<app::EntityType__Enum_1> {app::EntityType__Enum_1::GatherObject, app::EntityType__Enum_1::DropItem }, std::vector<std::string> {"_Food_BirdMeat", "_Food_Meat", "_DropItem" } };
		SimpleFilter Lumenspar = { app::EntityType__Enum_1::GatherObject, "CelestiaSplinter" };
		SimpleFilter KeySigil = { app::EntityType__Enum_1::GatherObject, "RuneContent" };
		SimpleFilter ShrineOfDepth = { app::EntityType__Enum_1::Gadget, "Temple" };
		SimpleFilter TimeTrialChallenge = { app::EntityType__Enum_1::Field, "Challengestarter_" };
	}

	namespace guide
	{
		SimpleFilter CampfireTorch = { app::EntityType__Enum_1::Gadget, "_FireBasin" };
		SimpleFilter DayNightSwitchingMechanism = { app::EntityType__Enum_1::Field, "_CircleConsole" };
		SimpleFilter EnkanomiyaPhaseGate = { app::EntityType__Enum_1::Gadget, "_Singularity" };
		SimpleFilter MysteriousCarvings = { app::EntityType__Enum_1::Gadget, "_ReginStatue" };
		SimpleFilter PhaseGate = { app::EntityType__Enum_1::Field, "_TeleportHighway" };
		SimpleFilter PlacesofEssenceWorship = { app::EntityType__Enum_1::Field, "_EnergySource" };
		SimpleFilter Pot = { app::EntityType__Enum_1::Gadget, "_Cooking_" };
		SimpleFilter RuinBrazier = { app::EntityType__Enum_1::Gadget, "_AncientHeatSource" };
		SimpleFilter Stormstone = { app::EntityType__Enum_1::Gadget, "_ReginLamp" };
		SimpleFilter TriangularMechanism = { app::EntityType__Enum_1::Field, "_TuningFork" };
	}

	namespace living
	{
		SimpleFilter BirdEgg = { app::EntityType__Enum_1::GatherObject, "BirdEgg" };
		SimpleFilter ButterflyWings = { app::EntityType__Enum_1::EnvAnimal, "Butterfly" };
		SimpleFilter Crab = { app::EntityType__Enum_1::EnvAnimal, "Crab" };
		SimpleFilter CrystalCore = { app::EntityType__Enum_1::EnvAnimal, "Wisp" };
		SimpleFilter Fish = { app::EntityType__Enum_1::EnvAnimal, "Fish" };
		SimpleFilter Frog = { app::EntityType__Enum_1::EnvAnimal, "Frog" };
		SimpleFilter LizardTail = { app::EntityType__Enum_1::EnvAnimal, "Lizard" };
		SimpleFilter LuminescentSpine = { app::EntityType__Enum_1::EnvAnimal, "FireFly" };
		SimpleFilter Onikabuto = { app::EntityType__Enum_1::GatherObject, "Electrohercules" };
		SimpleFilter Starconch = { app::EntityType__Enum_1::GatherObject, "_Shell" };
		SimpleFilter Eel = { app::EntityType__Enum_1::EnvAnimal, "Eel_" };
		SimpleFilter Inu = { app::EntityType__Enum_1::EnvAnimal, "_Inu_Shihandai" };
		SimpleFilter Boar = { app::EntityType__Enum_1::Monster, "Boar" };
		SimpleFilter Fox = { app::EntityType__Enum_1::Monster, "Fox" };
		SimpleFilter Squirrel = { app::EntityType__Enum_1::Monster, "Squirrel" };
		SimpleFilter Crane = { app::EntityType__Enum_1::Monster, "Crane" };
		SimpleFilter Falcon = { app::EntityType__Enum_1::Monster, "Falcon" };
		SimpleFilter LucklightFly = { app::EntityType__Enum_1::EnvAnimal, "Boltbug_" };
		SimpleFilter Salamander = { app::EntityType__Enum_1::EnvAnimal, "Salamander" };
		SimpleFilter Pigeon = { app::EntityType__Enum_1::Monster, "Pigeon" };
		SimpleFilter Crow = { app::EntityType__Enum_1::Monster, "Crow" };
		SimpleFilter Finch = { app::EntityType__Enum_1::Monster, "Tit" };
		SimpleFilter Wigeon = { app::EntityType__Enum_1::Monster, "Wigeon" };
		SimpleFilter Dog = { app::EntityType__Enum_1::Monster, "DogPrick" };
		SimpleFilter Cat = { app::EntityType__Enum_1::Monster, "Cat" };
		SimpleFilter Weasel = { app::EntityType__Enum_1::Monster, "Marten" };
		SimpleFilter WeaselThief = { app::EntityType__Enum_1::Monster, "Thoarder_Weasel" };
		SimpleFilter Kitsune = { app::EntityType__Enum_1::EnvAnimal, "Vulpes" };
		SimpleFilter BakeDanuki = { app::EntityType__Enum_1::Monster, "Inu_Tanuki" };
	}

	namespace mineral
	{
		SimpleFilter AmethystLump = { app::EntityType__Enum_1::GatherObject, "_Thundercrystal" };
		SimpleFilter ArchaicStone = { app::EntityType__Enum_1::GatherObject, "AncientOre" };
		SimpleFilter CorLapis = { app::EntityType__Enum_1::GatherObject, "_ElementRock" };
		SimpleFilter CrystalChunk = { app::EntityType__Enum_1::GatherObject,
			std::vector<std::string> { "_OreCrystal", "_ShiningCrystalOre" } };
		SimpleFilter CrystalMarrow = { app::EntityType__Enum_1::GatherObject, "_Crystalizedmarrow" };
		SimpleFilter ElectroCrystal = { app::EntityType__Enum_1::GatherObject, "_OreElectricRock" };
		SimpleFilter IronChunk = { app::EntityType__Enum_1::GatherObject, "_OreStone" };
		SimpleFilter NoctilucousJade = { app::EntityType__Enum_1::GatherObject,
			std::vector<std::string> { "_OreNightBerth", "_ShiningNightBerthOre" } };
		SimpleFilter MagicalCrystalChunk = { app::EntityType__Enum_1::GatherObject, "_OreMagicCrystal" };
		SimpleFilter ScarletQuartz = { app::EntityType__Enum_1::GatherObject, "_OreDulinsBlood" };
		SimpleFilter StarSilver = { app::EntityType__Enum_1::GatherObject, "_OreMoonMeteor" };
		SimpleFilter WhiteIronChunk = { app::EntityType__Enum_1::GatherObject, "_OreMetal" };
		SimpleFilter DunlinsTooth = { app::EntityType__Enum_1::GatherObject, "_DunlinsTooth" };
	}

	namespace monster
	{
		SimpleFilter AbyssMage = { app::EntityType__Enum_1::Monster, "_Abyss" };
		SimpleFilter FatuiAgent = { app::EntityType__Enum_1::Monster, "_Fatuus" };
		SimpleFilter FatuiCicinMage = { app::EntityType__Enum_1::Monster, "_Fatuus_Summoner" };
		SimpleFilter FatuiMirrorMaiden = { app::EntityType__Enum_1::Monster, "_Fatuus_Maiden" };
		SimpleFilter FatuiSkirmisher = { app::EntityType__Enum_1::Monster, "_Skirmisher" };
		SimpleFilter Geovishap = { app::EntityType__Enum_1::Monster, "_Drake_Rock" };
		SimpleFilter GeovishapHatchling = { app::EntityType__Enum_1::Monster, "_Wyrm_Rock" };
		SimpleFilter Hilichurl = { app::EntityType__Enum_1::Monster, "_Hili" };
		SimpleFilter Mitachurl = { app::EntityType__Enum_1::Monster, "_Brute" };
		SimpleFilter Nobushi = { app::EntityType__Enum_1::Monster, "_Ronin" };
		SimpleFilter Kairagi = { app::EntityType__Enum_1::Monster, "_Kairagi" };
		SimpleFilter RuinGuard = { app::EntityType__Enum_1::Monster, "_Defender" };
		SimpleFilter RuinHunter = { app::EntityType__Enum_1::Monster, "_Formathr" };
		SimpleFilter RuinGrader = { app::EntityType__Enum_1::Monster, "_Konungmathr" };
		SimpleFilter RuinSentinel = { app::EntityType__Enum_1::Monster, "_Apparatus_Enigma" };
		SimpleFilter Samachurl = { app::EntityType__Enum_1::Monster, "_Shaman" };
	    SimpleFilter ShadowyHusk = { app::EntityType__Enum_1::Monster, "ForlornVessel_Strong" };
		SimpleFilter Slime = { app::EntityType__Enum_1::Monster, "_Slime" };
		SimpleFilter FloatingFungus = { app::EntityType__Enum_1::Monster, "_Fungus" };
		SimpleFilter Specter = { app::EntityType__Enum_1::Monster, "_Sylph" };
		SimpleFilter TreasureHoarder = { app::EntityType__Enum_1::Monster, "_Thoarder" };
		SimpleFilter UnusualHilichurl = { app::EntityType__Enum_1::Monster, "_Hili_Wei" };
		SimpleFilter Whopperflower = { app::EntityType__Enum_1::Monster, "_Mimik" };
		SimpleFilter RifthoundWhelp = { app::EntityType__Enum_1::Monster, "_Hound_Kanis" };
		SimpleFilter Rifthound = { app::EntityType__Enum_1::Monster, "_Hound_Riftstalker" };
		SimpleFilter Dvalin = { app::EntityType__Enum_1::Monster, "_Dragon_Dvalin" };
		SimpleFilter Andrius = { app::EntityType__Enum_1::Monster, "_Wolf_LupiBoreas" };
		SimpleFilter Tartaglia = { app::EntityType__Enum_1::Monster, "_Tartaglia" };
		SimpleFilter Azhdaha = { app::EntityType__Enum_1::Monster, "_Dahaka" };
		SimpleFilter Signora = { app::EntityType__Enum_1::Monster, "_LaSignora" };
		SimpleFilter Shogun = { app::EntityType__Enum_1::Monster, "_Shougun" };
		SimpleFilter EyeOfTheStorm = { app::EntityType__Enum_1::Monster, "_Elemental_Wind" };
		SimpleFilter ElectroHypostasis = { app::EntityType__Enum_1::Monster, "_Effigy_Electric" };
		SimpleFilter AnemoHypostasis = { app::EntityType__Enum_1::Monster, "_Effigy_Wind" };
		SimpleFilter GeoHypostasis = { app::EntityType__Enum_1::Monster, "_Effigy_Rock" };
		SimpleFilter HydroHypostasis = { app::EntityType__Enum_1::Monster, "_Effigy_Water" };
		SimpleFilter CryoHypostasis = { app::EntityType__Enum_1::Monster, "_Effigy_Ice" };
		SimpleFilter PyroHypostasis = { app::EntityType__Enum_1::Monster, "_Effigy_Fire" };
		SimpleFilter HydroHypostasisSummon = { app::EntityType__Enum_1::Monster, "_Effigy_Water_Underling_Ooze" };
		SimpleFilter Oceanid = { app::EntityType__Enum_1::Monster, "_Oceanid" };
		SimpleFilter OceanidBoar = { app::EntityType__Enum_1::Monster, "_Oceanid_Boar" };
		SimpleFilter OceanidCrane = { app::EntityType__Enum_1::Monster, "_Oceanid_Crane" };
		SimpleFilter OceanidCrab = { app::EntityType__Enum_1::Monster, "_Oceanid_Crab" };
		SimpleFilter OceanidFinch = { app::EntityType__Enum_1::Monster, "_Oceanid_Tit" };
		SimpleFilter OceanidWigeon = { app::EntityType__Enum_1::Monster, "_Oceanid_Wigeon" };
		SimpleFilter OceanidSquirrel = { app::EntityType__Enum_1::Monster, "_Oceanid_Squirrel" };
		SimpleFilter OceanidFrog = { app::EntityType__Enum_1::Monster, "_Oceanid_Frog" };
		SimpleFilter OceanidFalcon = { app::EntityType__Enum_1::Monster, "_Oceanid_Falcon" };
		SimpleFilter PerpetualMechanicalArray = { app::EntityType__Enum_1::Monster, "_Apparatus_Perpetual" };
		SimpleFilter PrimoGeovishap = { app::EntityType__Enum_1::Monster, "_Drake_Primo_Rock" };
		SimpleFilter HydroBathysmalVishap = { app::EntityType__Enum_1::Monster, "_Drake_Deepsea_Water" };
		SimpleFilter CryoBathysmalVishap = { app::EntityType__Enum_1::Monster, "_Drake_Deepsea_Ice" };
		SimpleFilter ElectroBathysmalVishap = { app::EntityType__Enum_1::Monster, "_Drake_Deepsea_Electric" };
		SimpleFilter ThunderManifestation = { app::EntityType__Enum_1::Monster, "_Raijin" };
		SimpleFilter HydroAbyssHerald = { app::EntityType__Enum_1::Monster, "_Invoker_Herald_Water" };
		SimpleFilter ElectroAbyssLector = { app::EntityType__Enum_1::Monster, "_Invoker_Deacon_Electric" };
		SimpleFilter PyroAbyssLector = { app::EntityType__Enum_1::Monster, "_Invoker_Deacon_Fire" };
		SimpleFilter BlackSerpentKnight = { app::EntityType__Enum_1::Monster, "_Darkwraith_Strong_Wind" };
		SimpleFilter GoldenWolflord = { app::EntityType__Enum_1::Monster, "_Hound_Planelurker" };
		SimpleFilter RuinSerpent = { app::EntityType__Enum_1::Monster, "_Nithhoggr" };
		SimpleFilter Millelith = { app::EntityType__Enum_1::Monster, "_Millelith_" };
		SimpleFilter ShogunateInfantry = { app::EntityType__Enum_1::Monster, "_Aahigaru_" };
		SimpleFilter SangonomiyaCohort = { app::EntityType__Enum_1::Monster, "_AahigaruTaisho_" };
		SimpleFilter CryoRegisvine = { app::EntityType__Enum_1::Monster, "_Regisvine_Ice" };
		SimpleFilter PyroRegisvine = { app::EntityType__Enum_1::Monster, "_Regisvine_Fire" };
		SimpleFilter MaguuKenki = { app::EntityType__Enum_1::Monster, "_Ningyo" };
		SimpleFilter Cicin = { app::EntityType__Enum_1::Monster, "_Cicin" };
		SimpleFilter Beisht = { app::EntityType__Enum_1::Monster, "_Eldritch" };
	}

	namespace plant
	{
		SimpleFilter AmakumoFruit = { app::EntityType__Enum_1::GatherObject, "_Electroseed" };
		SimpleFilter Apple = { app::EntityType__Enum_1::GatherObject, "_Drop_Plant_Apple" };
		SimpleFilter BambooShoot = { app::EntityType__Enum_1::GatherObject, "_Bambooshoot" };
		SimpleFilter Berry = { app::EntityType__Enum_1::GatherObject, "_Raspberry" };
		SimpleFilter CallaLily = { app::EntityType__Enum_1::GatherObject, "_Plant_Callas" };
		SimpleFilter Carrot = { app::EntityType__Enum_1::GatherObject, "_Plant_Carrot" };
		SimpleFilter Cecilia = { app::EntityType__Enum_1::GatherObject, "_Cecilia" };
		SimpleFilter DandelionSeed = { app::EntityType__Enum_1::GatherObject, "_Plant_Dandelion" };
		SimpleFilter Dendrobium = { app::EntityType__Enum_1::GatherObject, "_Blooddendrobe" };
		SimpleFilter FlamingFlowerStamen = { app::EntityType__Enum_1::GatherObject, "_Flower_FireFlower" };
		SimpleFilter FluorescentFungus = { app::EntityType__Enum_1::GatherObject, "_Lampmushroom" };
		SimpleFilter GlazeLily = { app::EntityType__Enum_1::GatherObject, "_GlazedLily" };
		SimpleFilter Horsetail = { app::EntityType__Enum_1::GatherObject, "_HorseTail" };
		SimpleFilter JueyunChili = { app::EntityType__Enum_1::GatherObject, "_UltimateChilli_Fruit" };
		SimpleFilter LavenderMelon = { app::EntityType__Enum_1::GatherObject, "_Akebia" };
		SimpleFilter LotusHead = { app::EntityType__Enum_1::GatherObject, "_Lotus_Drop" };
		SimpleFilter Matsutake = { app::EntityType__Enum_1::GatherObject, "_Food_Matsutake" };
		SimpleFilter Mint = { app::EntityType__Enum_1::GatherObject, "_Plant_Mint" };
		SimpleFilter MistFlowerCorolla = { app::EntityType__Enum_1::GatherObject, "_Flower_IceFlower" };
		SimpleFilter Mushroom = { app::EntityType__Enum_1::GatherObject, "_Plant_Mushroom" };
		SimpleFilter NakuWeed = { app::EntityType__Enum_1::GatherObject, "_Howlgrass" };
		SimpleFilter PhilanemoMushroom = { app::EntityType__Enum_1::GatherObject, "_WindmilHunter" };
		SimpleFilter Pinecone = { app::EntityType__Enum_1::GatherObject, "_Drop_Plant_Pine" };
		SimpleFilter Qingxin = { app::EntityType__Enum_1::GatherObject, "_QingXin" };
		SimpleFilter Radish = { app::EntityType__Enum_1::GatherObject, "_Plant_Radish" };
		SimpleFilter SakuraBloom = { app::EntityType__Enum_1::GatherObject, "_Cherrypetals" };
		SimpleFilter SangoPearl = { app::EntityType__Enum_1::GatherObject, "_Coralpearl" };
		SimpleFilter SeaGanoderma = { app::EntityType__Enum_1::GatherObject, "_Electroanemones" };
		SimpleFilter Seagrass = { app::EntityType__Enum_1::GatherObject, "_Seagrass" };
		SimpleFilter SilkFlower = { app::EntityType__Enum_1::GatherObject, "_NiChang_Drop" };
		SimpleFilter SmallLampGrass = { app::EntityType__Enum_1::Field, "_Plant_Fuchsia" };
		SimpleFilter Snapdragon = { app::EntityType__Enum_1::GatherObject, "_Plant_Snapdragon" };
		SimpleFilter Sunsettia = { app::EntityType__Enum_1::GatherObject, "_SunsetFruit" };
		SimpleFilter SweetFlower = { app::EntityType__Enum_1::GatherObject, "_Plant_Whiteballet" };
		SimpleFilter Valberry = { app::EntityType__Enum_1::GatherObject, "_DropingBerry_Gather" };
		SimpleFilter Violetgrass = { app::EntityType__Enum_1::GatherObject, "_GlazedGrass" };
		SimpleFilter WindwheelAster = { app::EntityType__Enum_1::GatherObject, "_WindmilDaisy" };
		SimpleFilter Wolfhook = { app::EntityType__Enum_1::GatherObject, "_GogoFruit" };
	}

	namespace puzzle
	{
		SimpleFilter AncientRime = { app::EntityType__Enum_1::Gadget, "_IceSolidBulk" };
		SimpleFilter BakeDanuki = { app::EntityType__Enum_1::Monster, "Animal_Inu_Tanuki_" };
		SimpleFilter BloattyFloatty = { app::EntityType__Enum_1::Field, "_Flower_PongPongTree_" };
		WhitelistFilter CubeDevices = { std::vector<app::EntityType__Enum_1> {app::EntityType__Enum_1::Gadget, app::EntityType__Enum_1::Platform }, std::vector<std::string> {"_ElecStone", "_ElecSwitch" }};
		SimpleFilter EightStoneTablets = { app::EntityType__Enum_1::Gadget, "_HistoryBoard" };
		SimpleFilter ElectricConduction = { app::EntityType__Enum_1::Gear, "_ElectricPowerSource" };
		SimpleFilter RelayStone = { app::EntityType__Enum_1::Worktop, "_ElectricTransfer_" };
		WhitelistFilter ElectroSeelie = { std::vector<app::EntityType__Enum_1> {app::EntityType__Enum_1::Field, app::EntityType__Enum_1::Platform }, std::vector<std::string> {"_ElectricSeelie"} };
		SimpleFilter ElementalMonument = { app::EntityType__Enum_1::Gear, "_ElemTablet" };
		SimpleFilter FloatingAnemoSlime = { app::EntityType__Enum_1::Platform, "_WindSlime" };
		SimpleFilter Geogranum = { app::EntityType__Enum_1::Gadget, "_Property_Prop_RockFragment" };
		SimpleFilter GeoPuzzle = { app::EntityType__Enum_1::Field, "_Rockstraight_" };
		SimpleFilter LargeRockPile = { app::EntityType__Enum_1::Gadget, std::vector<std::string> {"_ElecRocks", "_StonePile_02" } };
		SimpleFilter LightUpTilePuzzle = { app::EntityType__Enum_1::Field, "_TwinStoryFloor" };
		SimpleFilter LightningStrikeProbe = { app::EntityType__Enum_1::Gadget, "_MagneticGear" };
		SimpleFilter LumenCage = { app::EntityType__Enum_1::Gadget, "_LitBulletLauncher" };
		SimpleFilter LuminousSeelie = { app::EntityType__Enum_1::Platform, "_LitSeelie" };
		SimpleFilter MistBubble = { app::EntityType__Enum_1::Platform, "_Suspiciousbubbles" };
		SimpleFilter OozingConcretions = { app::EntityType__Enum_1::Gadget, "_AbyssCoreLv" };
		SimpleFilter PirateHelm = { app::EntityType__Enum_1::Field, "_PirateHelm" };
		WhitelistFilter PressurePlate = { std::vector<app::EntityType__Enum_1> {app::EntityType__Enum_1::Field, app::EntityType__Enum_1::Gadget }, std::vector<std::string> {"Gear_Gravity", "_LitPathPlate" } };
		SimpleFilter SealLocations = { app::EntityType__Enum_1::Gadget, "_RunesKey" };
		SimpleFilter SeelieLamp = { app::EntityType__Enum_1::Field, "Gear_SeeliaLamp" };
		SimpleFilter Seelie = { app::EntityType__Enum_1::Platform, "Gear_Seelie" };
		SimpleFilter SmallRockPile = { app::EntityType__Enum_1::Gadget, "_StonePile_01" };
		SimpleFilter StormBarrier = { app::EntityType__Enum_1::Field, "_WindField_PushField" };
		SimpleFilter SwordHilt = { app::EntityType__Enum_1::Field, "_WastedSword_" };
		SimpleFilter Temari = { app::EntityType__Enum_1::Field, "_Temari" };
		SimpleFilter TorchPuzzle = { app::EntityType__Enum_1::Gadget, "_ImmortalFire" };
		SimpleFilter UniqueRocks = { app::EntityType__Enum_1::Gadget, "_Chalcedony" };
		SimpleFilter WarmingSeelie = { app::EntityType__Enum_1::Platform, "_FireSeelie" };
		SimpleFilter WindmillMechanism = { app::EntityType__Enum_1::Gear, "Gear_Windmill" };
	}

	namespace combined
	{
		SimpleFilter Oculies = {
			featured::Anemoculus +
			featured::CrimsonAgate +
			featured::Electroculus +
			featured::Geoculus +
			featured::Lumenspar +
			featured::KeySigil
		};
		SimpleFilter Chests = { app::EntityType__Enum_1::Chest };
		SimpleFilter Ores = {
			mineral::AmethystLump +
			mineral::ArchaicStone +
			mineral::CorLapis +
			mineral::CrystalChunk +
			mineral::CrystalMarrow +
			mineral::ElectroCrystal +
			mineral::IronChunk +
			mineral::NoctilucousJade +
			mineral::MagicalCrystalChunk +
			mineral::StarSilver +
			mineral::WhiteIronChunk
		};
		WhitelistFilter Doodads = {
			std::vector<app::EntityType__Enum_1> { app::EntityType__Enum_1::Gadget },
			std::vector<std::string> {
			"Monster_Effigy_Electric_01",
			"Monster_Effigy_Electric_02",
			"Monster_Effigy_Wind_01",
			"Monster_Effigy_Wind_02",
			"Monster_Effigy_Rock_01",
			"Monster_Effigy_Rock_02",
			"Monster_Effigy_Water_01",
			"Monster_Effigy_Ice_01",
			"Monster_Effigy_Fire_01",
			"Monster_Effigy_Water_Underling_Ooze_01",
			"Monster_Effigy_Water_Underling_Ooze_02",
			"Monster_Effigy_Water_Underling_Ooze_03",
			"Monster_Effigy_Water_Underling_Ooze_04",
			"HiliWoodenBox",
			"HiliWoodenBarrel",
			"HumanBox",
			"HumanJars",
			"QQTotem",
			"WatchTower01",
			"WatchTower02",
			"StonePile",
			"BrokenWall",
			"WoodenBox"
		} };
		SimpleFilter Animals = { app::EntityType__Enum_1::EnvAnimal };
		SimpleFilter AnimalDrop = {
			living::Falcon +
			living::Pigeon +
			living::Finch +
			living::Wigeon +
			living::Crane +
			living::Crow +
			living::Fox +
			living::Squirrel +
			living::Boar +
			living::Weasel
		};
		SimpleFilter AnimalPickUp = {
			living::CrystalCore +
			living::Salamander +
			living::Frog +
			living::Crab +
			living::LizardTail +
			living::Eel +
			living::Onikabuto +
			living::ButterflyWings +
			living::LucklightFly +
			living::LuminescentSpine +
			living::Starconch +
			living::BirdEgg +
			living::WeaselThief +
			living::Fish
		};
		SimpleFilter AnimalNPC = {
			living::Dog +
			living::Cat +
			living::Kitsune +
			living::BakeDanuki
		};
		SimpleFilter Monsters = { app::EntityType__Enum_1::Monster };
		SimpleFilter MonsterCommon = {
			monster::Slime +
			monster::FloatingFungus +
			monster::Specter +
			monster::Whopperflower +
			monster::Hilichurl +
			monster::Samachurl +
			monster::UnusualHilichurl +
			monster::FatuiSkirmisher +
			monster::TreasureHoarder +
			monster::Nobushi +
			monster::Kairagi +
			monster::Millelith +
			monster::ShogunateInfantry +
			monster::SangonomiyaCohort
		};
		SimpleFilter MonsterElites = {
			monster::Mitachurl +
			monster::AbyssMage +
			monster::HydroAbyssHerald +
			monster::PyroAbyssLector +
			monster::ElectroAbyssLector +
			monster::RifthoundWhelp +
			monster::Rifthound +
			monster::ShadowyHusk +
			monster::RuinGuard +
			monster::RuinHunter +
			monster::RuinGrader +
			monster::RuinSentinel +
			monster::Cicin +
			monster::FatuiCicinMage +
			monster::FatuiAgent +
			monster::FatuiMirrorMaiden +
			monster::GeovishapHatchling +
			monster::Geovishap +
			monster::HydroBathysmalVishap +
			monster::EyeOfTheStorm +
			monster::BlackSerpentKnight
		};
		SimpleFilter MonsterBosses = {
			// Adding these comments for better tracking.
			// Trounce
			monster::Dvalin +
			monster::Azhdaha +
			monster::Signora +
			monster::Shogun +
			monster::Andrius +
			monster::Tartaglia +
			// Mondstadt
			monster::CryoRegisvine +
			monster::ElectroHypostasis +
			monster::AnemoHypostasis +
			monster::CryoHypostasis +
			// Liyue
			monster::PyroRegisvine +
			monster::Oceanid +
			monster::OceanidBoar +
			monster::OceanidCrab +
			monster::OceanidCrane +
			monster::OceanidFalcon +
			monster::OceanidFinch +
			monster::OceanidFrog +
			monster::OceanidSquirrel +
			monster::OceanidWigeon +
			monster::GeoHypostasis +
			monster::RuinSerpent +
			monster::PrimoGeovishap +
			monster::Beisht +
			// Inazuma
			monster::PerpetualMechanicalArray +
			monster::PyroHypostasis +
			monster::MaguuKenki +
			monster::ThunderManifestation +
			monster::GoldenWolflord +
			monster::HydroHypostasis +
			monster::HydroHypostasisSummon +
			monster::CryoBathysmalVishap +
			monster::ElectroBathysmalVishap
		};
		SimpleFilter MonsterShielded = {
			// Taken from https://genshin-impact.fandom.com/wiki/Shields/Enemy.
			// We won't be including Regisvines and enemy objects here,
			// just regular monsters.
			monster::AbyssMage +
			monster::Slime +
			monster::Mitachurl +
			monster::ElectroAbyssLector +
			monster::HydroAbyssHerald +
			monster::PyroAbyssLector +
			monster::FatuiCicinMage +
			monster::Cicin +
			monster::Whopperflower
		};
		SimpleFilter MonsterEquips = { app::EntityType__Enum_1::MonsterEquip };
		BlacklistFilter Living = {
			std::vector<app::EntityType__Enum_1> {
				app::EntityType__Enum_1::EnvAnimal,
				app::EntityType__Enum_1::Monster
			},
			std::vector<std::string> {
				// Environmental mobs
				"Cat", "DogPrick", "Vulpues", "Inu_Tanuki",
				// Overworld bosses
				"Ningyo", "Regisvine", "Hypostasis", "Planelurker", "Nithhoggr"
			}
		};
		SimpleFilter OrganicTargets = Monsters + Animals; // Solael: Please don't mess around with this filter.
		//m0nkrel: We can choose the entities we need ourselves so as not to magnetize cats, dogs, etc.
		//AdvancedFilter Animals = { std::vector<app::EntityType__Enum_1> {app::EntityType__Enum_1::EnvAnimal, app::EntityType__Enum_1::Monster }, std::vector<std::string> {"Crane","Tit", "Boar" , "Squirrel", "Fox", "Pigeon", "Wigeon", "Falcon" ,"Marten" } };
	}
}