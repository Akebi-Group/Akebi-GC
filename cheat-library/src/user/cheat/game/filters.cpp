#include <pch-il2cpp.h>

#include "filters.h"

namespace cheat::game::filters
{
	using namespace game;
	using namespace app;

	namespace collection
	{
		SimpleFilter Book = { app::EntityType__Enum_1::GatherObject, "SkillObj_EmptyGadget" };
		SimpleFilter Viewpoint = { app::EntityType__Enum_1::ViewPoint, "SkillObj_EmptyGadget" };
		ChestFilter RadiantSpincrystal = ChestFilter(game::Chest::ItemType::BGM);
		ChestFilter BookPage = ChestFilter(game::Chest::ItemType::BookPage);
		ChestFilter QuestInteract = ChestFilter(game::Chest::ItemType::QuestInteract);
		SimpleFilter WoodenCrate = { app::EntityType__Enum_1::Chest, "Searchpoint_OnWater" };
		SimpleFilter GeoSigil = { app::EntityType__Enum_1::Chest, "Prop_Search_Point" };
	}

	namespace chest
	{
		ChestFilter CommonChest = ChestFilter(Chest::ChestRarity::Common);
		ChestFilter ExquisiteChest = ChestFilter(Chest::ChestRarity::Exquisite);
		ChestFilter PreciousChest = ChestFilter(Chest::ChestRarity::Precious);
		ChestFilter LuxuriousChest = ChestFilter(Chest::ChestRarity::Luxurious);
		ChestFilter RemarkableChest = ChestFilter(Chest::ChestRarity::Remarkable);
		ChestFilter SearchPoint = ChestFilter(Chest::ItemType::Investigate);

		ChestFilter SLocked = ChestFilter(Chest::ChestState::Locked);
		ChestFilter SInLock = ChestFilter(Chest::ChestState::InRock);
		ChestFilter SFrozen = ChestFilter(Chest::ChestState::Frozen);
		ChestFilter SBramble = ChestFilter(Chest::ChestState::Bramble);
		ChestFilter STrap = ChestFilter(Chest::ChestState::Trap);
		SimpleFilter BuriedChest = { EntityType__Enum_1::Field, "_WorldArea_Operator" };
	}

	namespace equipment
	{
		SimpleFilter Artifacts = { EntityType__Enum_1::DropItem, "_Relic" };
		SimpleFilter Bow = { EntityType__Enum_1::DropItem, "_Bow" };
		SimpleFilter Claymore = { EntityType__Enum_1::DropItem, "_Claymore" };
		SimpleFilter Catalyst = { EntityType__Enum_1::DropItem, "_Catalyst" };
		SimpleFilter Pole = { EntityType__Enum_1::DropItem, "_Pole" };
		SimpleFilter Sword = { EntityType__Enum_1::DropItem, "_Sword" };
	}

	namespace featured
	{
		SimpleFilter Anemoculus = { EntityType__Enum_1::GatherObject, "WindCrystalShell" };
		SimpleFilter CrimsonAgate = { EntityType__Enum_1::GatherObject, "Prop_Essence" };
		SimpleFilter Electroculus = { EntityType__Enum_1::GatherObject, "Prop_ElectricCrystal" };
		SimpleFilter Dendroculus = { EntityType__Enum_1::GatherObject, "_XuMiCrystal" };
		SimpleFilter EchoingConch = { EntityType__Enum_1::EchoShell, "_Echoconch" };
		SimpleFilter Electrogranum = { EntityType__Enum_1::Gadget, "ThunderSeedCreate" };
		SimpleFilter FishingPoint = { EntityType__Enum_1::FishPool, "_FishingShoal" };
		SimpleFilter Geoculus = { EntityType__Enum_1::GatherObject, "RockCrystalShell" };
		SimpleFilter ImagingConch = { EntityType__Enum_1::EchoShell, "_Dreamconch" };
		WhitelistFilter ItemDrops = { {EntityType__Enum_1::GatherObject, EntityType__Enum_1::DropItem }, {"_Food_BirdMeat", "_Food_Meat", "_DropItem" } };
		SimpleFilter Lumenspar = { EntityType__Enum_1::GatherObject, "CelestiaSplinter" };
		SimpleFilter KeySigil = { EntityType__Enum_1::GatherObject, "RuneContent" };
		SimpleFilter ShrineOfDepth = { EntityType__Enum_1::Gadget, "Temple" };
		SimpleFilter TimeTrialChallenge = { EntityType__Enum_1::Field, "Challengestarter_" };
	}

	namespace guide
	{
		SimpleFilter CampfireTorch = { EntityType__Enum_1::Gadget, "_FireBasin" };
		SimpleFilter DayNightSwitchingMechanism = { EntityType__Enum_1::Field, "_CircleConsole" };
		SimpleFilter EnkanomiyaPhaseGate = { EntityType__Enum_1::Gadget, "_Singularity" };
		SimpleFilter MysteriousCarvings = { EntityType__Enum_1::Gadget, "_ReginStatue" };
		SimpleFilter PhaseGate = { EntityType__Enum_1::Field, "_TeleportHighway" };
		SimpleFilter PlacesofEssenceWorship = { EntityType__Enum_1::Field, "_EnergySource" };
		SimpleFilter Pot = { EntityType__Enum_1::Gadget, "_Cooking_" };
		SimpleFilter RuinBrazier = { EntityType__Enum_1::Gadget, "_AncientHeatSource" };
		SimpleFilter Stormstone = { EntityType__Enum_1::Gadget, "_ReginLamp" };
		SimpleFilter TriangularMechanism = { EntityType__Enum_1::Field, "_TuningFork" };
	}

	namespace living
	{
		SimpleFilter AvatarTeammate = { EntityType__Enum_1::Avatar, "authority :False" };
		SimpleFilter AvatarOwn = { EntityType__Enum_1::Avatar, "authority :True" };
		SimpleFilter BirdEgg = { EntityType__Enum_1::GatherObject, "BirdEgg" };
		SimpleFilter ButterflyWings = { EntityType__Enum_1::EnvAnimal, "Butterfly" };
		SimpleFilter Crab = { EntityType__Enum_1::EnvAnimal, "Crab" };
		SimpleFilter CrystalCore = { EntityType__Enum_1::EnvAnimal, "Wisp" };
		SimpleFilter Fish = { EntityType__Enum_1::EnvAnimal, "Fish" };
		SimpleFilter Frog = { EntityType__Enum_1::EnvAnimal, "Frog" };
		SimpleFilter LizardTail = { EntityType__Enum_1::EnvAnimal, "Lizard" };
		SimpleFilter LuminescentSpine = { EntityType__Enum_1::EnvAnimal, "FireFly" };
		SimpleFilter Onikabuto = { EntityType__Enum_1::GatherObject, "Electrohercules" };
		SimpleFilter Starconch = { EntityType__Enum_1::GatherObject, "_Shell" };
		SimpleFilter Eel = { EntityType__Enum_1::EnvAnimal, "Eel_" };
		SimpleFilter Inu = { EntityType__Enum_1::Monster, "_Inu_Shihandai" };
		SimpleFilter Boar = { EntityType__Enum_1::Monster, "Boar" };
		SimpleFilter Fox = { EntityType__Enum_1::Monster, "Fox" };
		SimpleFilter Squirrel = { EntityType__Enum_1::Monster, "Squirrel" };
		SimpleFilter Npc = { EntityType__Enum_1::NPC, { "_Liyue", "_Mengde", "_Inazuma", "_Enkanomiya", "_Sumeru", "_Fontaine", "_Natlan", "_Snezhnaya", "_Coop", "_Quest", "_Animal", "_Guide", "_Homeworld", "_Avatar", "_Kanban", "_Monster"} };
		SimpleFilter Crane = { EntityType__Enum_1::Monster, "Crane" };
		SimpleFilter Falcon = { EntityType__Enum_1::Monster, "Falcon" };
		SimpleFilter LucklightFly = { EntityType__Enum_1::EnvAnimal, "Boltbug_" };
		SimpleFilter Salamander = { EntityType__Enum_1::EnvAnimal, "Salamander" };
		SimpleFilter Tukan = { EntityType__Enum_1::Monster, "Pigeon_Beak" };
		SimpleFilter Pigeon = { EntityType__Enum_1::Monster, "Pigeon_0" };
		SimpleFilter Crow = { EntityType__Enum_1::Monster, "Crow" };
		SimpleFilter Finch = { EntityType__Enum_1::Monster, "Tit" };
		SimpleFilter Wigeon = { EntityType__Enum_1::Monster, "Wigeon" };
		SimpleFilter Dog = { EntityType__Enum_1::Monster, "DogPrick" };
		SimpleFilter Cat = { EntityType__Enum_1::Monster, "Cat" };
		SimpleFilter Weasel = { EntityType__Enum_1::Monster, "Marten" };
		SimpleFilter WeaselThief = { EntityType__Enum_1::Monster, "Thoarder_Weasel" };
		SimpleFilter Kitsune = { EntityType__Enum_1::EnvAnimal, "Vulpes" };
		SimpleFilter BakeDanuki = { EntityType__Enum_1::Monster, "Inu_Tanuki" };
		SimpleFilter Meat = { EntityType__Enum_1::GatherObject , { "_Food_BirdMeat", "_Food_Meat", "_Fishmeat" } };
	}

	namespace mineral
	{
		SimpleFilter AmethystLump = { EntityType__Enum_1::GatherObject, "_Thundercrystal" };
		SimpleFilter ArchaicStone = { EntityType__Enum_1::GatherObject, "_AncientOre" };
		SimpleFilter CorLapis = { EntityType__Enum_1::GatherObject, "_ElementRock" };
		SimpleFilter CrystalChunk = { EntityType__Enum_1::GatherObject, { "_OreCrystal", "_ShiningCrystalOre" } };
		SimpleFilter CrystalMarrow = { EntityType__Enum_1::GatherObject, "_Crystalizedmarrow" };
		SimpleFilter ElectroCrystal = { EntityType__Enum_1::GatherObject, "_OreElectricRock" };
		SimpleFilter IronChunk = { EntityType__Enum_1::GatherObject, "_OreStone" };
		SimpleFilter NoctilucousJade = { EntityType__Enum_1::GatherObject, { "_OreNightBerth", "_ShiningNightBerthOre" } };
		SimpleFilter MagicalCrystalChunk = { EntityType__Enum_1::GatherObject, "_OreMagicCrystal" };
		SimpleFilter ScarletQuartz = { EntityType__Enum_1::GatherObject, "_OreDulinsBlood" };
		SimpleFilter Starsilver = { EntityType__Enum_1::GatherObject, "_OreMoonMeteor" };
		SimpleFilter WhiteIronChunk = { EntityType__Enum_1::GatherObject, "_OreMetal" };
		SimpleFilter DunlinsTooth = { EntityType__Enum_1::GatherObject, "_DunlinsTooth" };

		SimpleFilter AmethystLumpDrop = { EntityType__Enum_1::GatherObject, "_Thundercrystaldrop" };
		SimpleFilter CrystalChunkDrop = { EntityType__Enum_1::GatherObject,"_Drop_Crystal" };
		SimpleFilter ElectroCrystalDrop = { EntityType__Enum_1::GatherObject, "_Drop_Ore_ElectricRock" };
		SimpleFilter IronChunkDrop = { EntityType__Enum_1::GatherObject, "_Drop_Stone" };
		SimpleFilter NoctilucousJadeDrop = { EntityType__Enum_1::GatherObject,"_NightBerth" };
		SimpleFilter MagicalCrystalChunkDrop = { EntityType__Enum_1::GatherObject, "_DropMagicCrystal" };
		SimpleFilter ScarletQuartzDrop = { EntityType__Enum_1::GatherObject, "_DropDulinsBlood" };
		SimpleFilter StarsilverDrop = { EntityType__Enum_1::GatherObject, "_DropMoonMeteor" };
		SimpleFilter WhiteIronChunkDrop = { EntityType__Enum_1::GatherObject, "_Drop_Metal" };
	}

	namespace monster
	{
		SimpleFilter AbyssMage = { EntityType__Enum_1::Monster, "_Abyss" };
		SimpleFilter Eremite = { EntityType__Enum_1::Monster, "_Eremite" };
		SimpleFilter FatuiAgent = { EntityType__Enum_1::Monster, "_Fatuus" };
		SimpleFilter FatuiCicinMage = { EntityType__Enum_1::Monster, "_Fatuus_Summoner" };
		SimpleFilter FatuiMirrorMaiden = { EntityType__Enum_1::Monster, "_Fatuus_Maiden" };
		SimpleFilter FatuiSkirmisher = { EntityType__Enum_1::Monster, "_Skirmisher" };
		SimpleFilter Geovishap = { EntityType__Enum_1::Monster, "_Drake_Rock" };
		SimpleFilter GeovishapHatchling = { EntityType__Enum_1::Monster, "_Wyrm_Rock" };
		SimpleFilter Hilichurl = { EntityType__Enum_1::Monster, "_Hili" };
		SimpleFilter Mitachurl = { EntityType__Enum_1::Monster, "_Brute" };
		SimpleFilter Nobushi = { EntityType__Enum_1::Monster, "_Ronin" };
		SimpleFilter Kairagi = { EntityType__Enum_1::Monster, "_Kairagi" };
		SimpleFilter RuinDrake = { EntityType__Enum_1::Monster, "_Gargoyle" };
		SimpleFilter RuinGuard = { EntityType__Enum_1::Monster, "_Defender" };
		SimpleFilter RuinHunter = { EntityType__Enum_1::Monster, "_Formathr" };
		SimpleFilter RuinGrader = { EntityType__Enum_1::Monster, "_Konungmathr" };
		SimpleFilter RuinSentinel = { EntityType__Enum_1::Monster, "_Apparatus_Enigma" };
		SimpleFilter Samachurl = { EntityType__Enum_1::Monster, "_Shaman" };
		SimpleFilter ShadowyHusk = { EntityType__Enum_1::Monster, "ForlornVessel_Strong" };
		SimpleFilter Slime = { EntityType__Enum_1::Monster, "_Slime" };
		SimpleFilter FloatingFungus = { EntityType__Enum_1::Monster, "Fungus_Un_" };
		SimpleFilter StretchyFungus = { EntityType__Enum_1::Monster, "Fungus_Deux_" };
		SimpleFilter WhirlingFungus = { EntityType__Enum_1::Monster, "Fungus_Trois_" };
		SimpleFilter WingedShroom = { EntityType__Enum_1::Monster, "Fungus_Amanita_Unu" };
		SimpleFilter GroundedShroom = { EntityType__Enum_1::Monster, "Fungus_Amanita_Du" };
		SimpleFilter Specter = { EntityType__Enum_1::Monster, "_Sylph" };
		SimpleFilter TreasureHoarder = { EntityType__Enum_1::Monster, "_Thoarder" };
		SimpleFilter UnusualHilichurl = { EntityType__Enum_1::Monster, "_Hili_Wei" };
		SimpleFilter Whopperflower = { EntityType__Enum_1::Monster, "_Mimik" };
		SimpleFilter RifthoundWhelp = { EntityType__Enum_1::Monster, "_Hound_Kanis" };
		SimpleFilter Rifthound = { EntityType__Enum_1::Monster, "_Hound_Riftstalker" };
		SimpleFilter Dvalin = { EntityType__Enum_1::Monster, "_Dragon_Dvalin" };
		SimpleFilter Andrius = { EntityType__Enum_1::Monster, "_Wolf_LupiBoreas" };
		SimpleFilter Tartaglia = { EntityType__Enum_1::Monster, "_Tartaglia" };
		SimpleFilter Azhdaha = { EntityType__Enum_1::Monster, "_Dahaka" };
		SimpleFilter Signora = { EntityType__Enum_1::Monster, "_LaSignora" };
		SimpleFilter Shogun = { EntityType__Enum_1::Monster, "_Shougun" };
		SimpleFilter EyeOfTheStorm = { EntityType__Enum_1::Monster, "_Elemental_Wind" };
		SimpleFilter ElectroHypostasis = { EntityType__Enum_1::Monster, "_Effigy_Electric" };
		SimpleFilter AnemoHypostasis = { EntityType__Enum_1::Monster, "_Effigy_Wind" };
		SimpleFilter GeoHypostasis = { EntityType__Enum_1::Monster, "_Effigy_Rock" };
		SimpleFilter HydroHypostasis = { EntityType__Enum_1::Monster, "_Effigy_Water" };
		SimpleFilter CryoHypostasis = { EntityType__Enum_1::Monster, "_Effigy_Ice" };
		SimpleFilter PyroHypostasis = { EntityType__Enum_1::Monster, "_Effigy_Fire" };
		SimpleFilter HydroHypostasisSummon = { EntityType__Enum_1::Monster, "_Effigy_Water_Underling_Ooze" };
		SimpleFilter Oceanid = { EntityType__Enum_1::Monster, "_Oceanid" };
		SimpleFilter OceanidBoar = { EntityType__Enum_1::Monster, "_Oceanid_Boar" };
		SimpleFilter OceanidCrane = { EntityType__Enum_1::Monster, "_Oceanid_Crane" };
		SimpleFilter OceanidCrab = { EntityType__Enum_1::Monster, "_Oceanid_Crab" };
		SimpleFilter OceanidFinch = { EntityType__Enum_1::Monster, "_Oceanid_Tit" };
		SimpleFilter OceanidWigeon = { EntityType__Enum_1::Monster, "_Oceanid_Wigeon" };
		SimpleFilter OceanidSquirrel = { EntityType__Enum_1::Monster, "_Oceanid_Squirrel" };
		SimpleFilter OceanidFrog = { EntityType__Enum_1::Monster, "_Oceanid_Frog" };
		SimpleFilter OceanidFalcon = { EntityType__Enum_1::Monster, "_Oceanid_Falcon" };
		SimpleFilter PerpetualMechanicalArray = { EntityType__Enum_1::Monster, "_Apparatus_Perpetual" };
		SimpleFilter PrimoGeovishap = { EntityType__Enum_1::Monster, "_Drake_Primo_Rock" };
		SimpleFilter HydroBathysmalVishap = { EntityType__Enum_1::Monster, "_Drake_Deepsea_Water" };
		SimpleFilter CryoBathysmalVishap = { EntityType__Enum_1::Monster, "_Drake_Deepsea_Ice" };
		SimpleFilter ElectroBathysmalVishap = { EntityType__Enum_1::Monster, "_Drake_Deepsea_Electric" };
		SimpleFilter ThunderManifestation = { EntityType__Enum_1::Monster, "_Raijin" };
		SimpleFilter HydroAbyssHerald = { EntityType__Enum_1::Monster, "_Invoker_Herald_Water" };
		SimpleFilter ElectroAbyssLector = { EntityType__Enum_1::Monster, "_Invoker_Deacon_Electric" };
		SimpleFilter PyroAbyssLector = { EntityType__Enum_1::Monster, "_Invoker_Deacon_Fire" };
		SimpleFilter BlackSerpentKnight = { EntityType__Enum_1::Monster, "_Darkwraith_Strong_Wind" };
		SimpleFilter GoldenWolflord = { EntityType__Enum_1::Monster, "_Hound_Planelurker" };
		SimpleFilter RuinSerpent = { EntityType__Enum_1::Monster, "_Nithhoggr" };
		SimpleFilter Millelith = { EntityType__Enum_1::Monster, "_Millelith_" };
		SimpleFilter ShogunateInfantry = { EntityType__Enum_1::Monster, "_Aahigaru_" };
		SimpleFilter SangonomiyaCohort = { EntityType__Enum_1::Monster, "_AahigaruTaisho_" };
		SimpleFilter CryoRegisvine = { EntityType__Enum_1::Monster, "_Regisvine_Ice" };
		SimpleFilter PyroRegisvine = { EntityType__Enum_1::Monster, "_Regisvine_Fire" };
		SimpleFilter ElectroRegisvine = { EntityType__Enum_1::Monster, "_Regisvine_Electric" };
		SimpleFilter MaguuKenki = { EntityType__Enum_1::Monster, "_Ningyo" };
		SimpleFilter Cicin = { EntityType__Enum_1::Monster, "_Cicin" };
		SimpleFilter Beisht = { EntityType__Enum_1::Monster, "_Eldritch" };
		SimpleFilter JadeplumeTerrorshroom = { EntityType__Enum_1::Monster, "Fungus_Raptor" };
		SimpleFilter RishbolandTiger = { EntityType__Enum_1::Monster, "_Megamoth_" };
		SimpleFilter ShaggySumpterBeast = { EntityType__Enum_1::Monster, "_Panther" };
		SimpleFilter Spincrocodile = { EntityType__Enum_1::Monster, "_Gator" };
		SimpleFilter SentryTurrets = { EntityType__Enum_1::Field, "SentryTurrets_" };
	}

	namespace plant
	{
		SimpleFilter AmakumoFruit = { EntityType__Enum_1::GatherObject, "_Electroseed" };
		SimpleFilter Apple = { EntityType__Enum_1::GatherObject, "_Drop_Plant_Apple" };
		SimpleFilter BambooShoot = { EntityType__Enum_1::GatherObject, "_Bambooshoot" };
		SimpleFilter Berry = { EntityType__Enum_1::GatherObject, "_Raspberry" };
		SimpleFilter CallaLily = { EntityType__Enum_1::GatherObject, "_Plant_Callas" };
		SimpleFilter Cabbage = { EntityType__Enum_1::GatherObject, "_Plant_Cabbage" };
		SimpleFilter Carrot = { EntityType__Enum_1::GatherObject, "_Plant_Carrot" };
		SimpleFilter Cecilia = { EntityType__Enum_1::GatherObject, "_Cecilia" };
		SimpleFilter DandelionSeed = { EntityType__Enum_1::GatherObject, "_Plant_Dandelion" };
		SimpleFilter Dendrobium = { EntityType__Enum_1::GatherObject, "_Blooddendrobe" };
		SimpleFilter FlamingFlowerStamen = { EntityType__Enum_1::GatherObject, "_Flower_FireFlower" };
		SimpleFilter FluorescentFungus = { EntityType__Enum_1::GatherObject, "_Lampmushroom" };
		SimpleFilter GlazeLily = { EntityType__Enum_1::GatherObject, "_GlazedLily" };
		SimpleFilter Horsetail = { EntityType__Enum_1::GatherObject, "_HorseTail" };
		SimpleFilter JueyunChili = { EntityType__Enum_1::GatherObject, "_UltimateChilli_Fruit" };
		SimpleFilter LavenderMelon = { EntityType__Enum_1::GatherObject, "_Akebia" };
		SimpleFilter LotusHead = { EntityType__Enum_1::GatherObject, "_Lotus_Drop" };
		SimpleFilter Matsutake = { EntityType__Enum_1::GatherObject, "_Food_Matsutake" };
		SimpleFilter Mint = { EntityType__Enum_1::GatherObject, "_Plant_Mint" };
		SimpleFilter MistFlowerCorolla = { EntityType__Enum_1::GatherObject, "_Flower_IceFlower" };
		SimpleFilter Mushroom = { EntityType__Enum_1::GatherObject, "_Plant_Mushroom" };
		SimpleFilter NakuWeed = { EntityType__Enum_1::GatherObject, "_Howlgrass" };
		SimpleFilter PhilanemoMushroom = { EntityType__Enum_1::GatherObject, "_WindmilHunter" };
		SimpleFilter Pinecone = { EntityType__Enum_1::GatherObject, "_Drop_Plant_Pine" };
		SimpleFilter Potato = { EntityType__Enum_1::GatherObject, "_Plant_Potato" };
		SimpleFilter Qingxin = { EntityType__Enum_1::GatherObject, "_QingXin" };
		SimpleFilter Radish = { EntityType__Enum_1::GatherObject, "_Plant_Radish" };
		SimpleFilter SakuraBloom = { EntityType__Enum_1::GatherObject, "_Cherrypetals" };
		SimpleFilter SangoPearl = { EntityType__Enum_1::GatherObject, "_Coralpearl" };
		SimpleFilter SeaGanoderma = { EntityType__Enum_1::GatherObject, "_Electroanemones" };
		SimpleFilter Seagrass = { EntityType__Enum_1::GatherObject, "_Seagrass" };
		SimpleFilter SilkFlower = { EntityType__Enum_1::GatherObject, "_NiChang_Drop" };
		SimpleFilter SmallLampGrass = { EntityType__Enum_1::Field, "_Plant_Fuchsia" };
		SimpleFilter Snapdragon = { EntityType__Enum_1::GatherObject, "_Plant_Snapdragon" };
		SimpleFilter Sunsettia = { EntityType__Enum_1::GatherObject, "_SunsetFruit" };
		SimpleFilter SweetFlower = { EntityType__Enum_1::GatherObject, "_Plant_Whiteballet" };
		SimpleFilter Valberry = { EntityType__Enum_1::GatherObject, "_DropingBerry_Gather" };
		SimpleFilter Violetgrass = { EntityType__Enum_1::GatherObject, "_GlazedGrass" };
		SimpleFilter Wheat = { EntityType__Enum_1::GatherObject, "_Plant_Wheat" };
		SimpleFilter WindwheelAster = { EntityType__Enum_1::GatherObject, "_WindmilDaisy" };
		SimpleFilter Wolfhook = { EntityType__Enum_1::GatherObject, "_GogoFruit" };
		SimpleFilter RadishDrop = { EntityType__Enum_1::GatherObject, "_Plant_Carrot02_Clear" };
		SimpleFilter CarrotDrop = { EntityType__Enum_1::GatherObject, "_Plant_Radish02_Clear" };
		SimpleFilter HarraFruit = { EntityType__Enum_1::GatherObject, "_Ligusticum" };
		SimpleFilter KalpalataLotus = { EntityType__Enum_1::GatherObject, "_Kalpalata" };
		SimpleFilter NilotpalaLotus = { EntityType__Enum_1::GatherObject, "_MoonLotus" };
		SimpleFilter Padisarah = { EntityType__Enum_1::GatherObject, "_Pasusalan" };
		SimpleFilter RukkhashavaMushrooms = { EntityType__Enum_1::GatherObject, "_HolyMushroom" };
		SimpleFilter SumeruRose = { EntityType__Enum_1::GatherObject, "_XumiRose" };
		//SimpleFilter Viparyas = { EntityType__Enum_1::GatherObject, "_" };
		SimpleFilter ZaytunPeach = { EntityType__Enum_1::GatherObject, "_Olea" };
	}

	namespace puzzle
	{
		SimpleFilter AncientRime = { EntityType__Enum_1::Gadget, "_IceSolidBulk" };
		SimpleFilter BakeDanuki = { EntityType__Enum_1::Monster, "Animal_Inu_Tanuki_" };
		SimpleFilter BloattyFloatty = { EntityType__Enum_1::Field, "_Flower_PongPongTree_" };
		WhitelistFilter CubeDevices = { {EntityType__Enum_1::Gadget, EntityType__Enum_1::Platform }, {"_ElecStone", "_ElecSwitch" } };
		SimpleFilter EightStoneTablets = { EntityType__Enum_1::Gadget, "_HistoryBoard" };
		SimpleFilter ElectricConduction = { EntityType__Enum_1::Gear, "_ElectricPowerSource" };
		SimpleFilter RelayStone = { EntityType__Enum_1::Worktop, "_ElectricTransfer_" };
		WhitelistFilter ElectroSeelie = { {EntityType__Enum_1::Field, EntityType__Enum_1::Platform }, "_ElectricSeelie" };
		SimpleFilter ElementalMonument = { EntityType__Enum_1::Gear, "_ElemTablet" };
		SimpleFilter FloatingAnemoSlime = { EntityType__Enum_1::Platform, "_WindSlime" };
		SimpleFilter Geogranum = { EntityType__Enum_1::Gadget, "_Property_Prop_RockFragment" };
		SimpleFilter GeoPuzzle = { EntityType__Enum_1::Field, "_Rockstraight_" };
		SimpleFilter LargeRockPile = { EntityType__Enum_1::Gadget, {"_ElecRocks", "_StonePile_02" } };
		SimpleFilter LightUpTilePuzzle = { EntityType__Enum_1::Field, "_TwinStoryFloor" };
		SimpleFilter LightningStrikeProbe = { EntityType__Enum_1::Gadget, "_MagneticGear" };
		SimpleFilter LumenCage = { EntityType__Enum_1::Gadget, "_LitBulletLauncher" };
		SimpleFilter LuminousSeelie = { EntityType__Enum_1::Platform, "_LitSeelie" };
		SimpleFilter MistBubble = { EntityType__Enum_1::Platform, "_Suspiciousbubbles" };
		SimpleFilter OozingConcretions = { EntityType__Enum_1::Gadget, "_AbyssCoreLv" };
		SimpleFilter PirateHelm = { EntityType__Enum_1::Field, "_PirateHelm" };
		WhitelistFilter PressurePlate = { {EntityType__Enum_1::Field, EntityType__Enum_1::Gadget }, {"Gear_Gravity", "_LitPathPlate" } };
		SimpleFilter SealLocations = { EntityType__Enum_1::Gadget, "_RunesKey" };
		SimpleFilter SeelieLamp = { EntityType__Enum_1::Field, "Gear_SeeliaLamp" };
		SimpleFilter Seelie = { EntityType__Enum_1::Platform, "Gear_Seelie" };
		SimpleFilter SmallRockPile = { EntityType__Enum_1::Gadget, "_StonePile_01" };
		SimpleFilter StormBarrier = { EntityType__Enum_1::Field, "_WindField_PushField" };
		SimpleFilter SwordHilt = { EntityType__Enum_1::Field, "_WastedSword_" };
		SimpleFilter Temari = { EntityType__Enum_1::Field, "_Temari" };
		SimpleFilter TorchPuzzle = { EntityType__Enum_1::Gadget, "_ImmortalFire" };
		SimpleFilter UniqueRocks = { EntityType__Enum_1::Gadget, "_Chalcedony" };
		SimpleFilter WarmingSeelie = { EntityType__Enum_1::Platform, "_FireSeelie" };
		SimpleFilter WindmillMechanism = { EntityType__Enum_1::Gear, "Gear_Windmill" };
		WhitelistFilter MelodicBloom = { {EntityType__Enum_1::Worktop, EntityType__Enum_1::Gadget }, {"_TransferFlowerSmall", "_NotePlant" } };
		SimpleFilter CloudleisureSteps = { EntityType__Enum_1::Field, "_CloudPlatform" };
		WhitelistFilter DreamForm = { {EntityType__Enum_1::Field, EntityType__Enum_1::Platform }, "_AnimalSeelie" };
		SimpleFilter StarlightCoalescence = { EntityType__Enum_1::Field, "_PaperStar" };
		SimpleFilter TheRavenForum = { EntityType__Enum_1::Gadget, "_NightCrowStatue" };

	}

	namespace combined
	{
		SimpleFilter Oculies = {
			featured::Anemoculus,
			featured::CrimsonAgate,
			featured::Electroculus,
			featured::Geoculus,
			featured::Lumenspar,
			featured::KeySigil
		};
		SimpleFilter Chests = { EntityType__Enum_1::Chest };
		SimpleFilter Ores = {
			mineral::AmethystLump,
			mineral::ArchaicStone,
			mineral::CorLapis,
			mineral::CrystalChunk,
			mineral::CrystalMarrow,
			mineral::ElectroCrystal,
			mineral::IronChunk,
			mineral::NoctilucousJade,
			mineral::MagicalCrystalChunk,
			mineral::Starsilver,
			mineral::WhiteIronChunk
		};
		SimpleFilter PlantDestroy = {
			//plant::SakuraBloom,
			plant::DandelionSeed,
			plant::MistFlowerCorolla,
			plant::FlamingFlowerStamen
		};

		WhitelistFilter Doodads = {
			EntityType__Enum_1::Gadget,
			{
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
			}
		};
		SimpleFilter Animals = { EntityType__Enum_1::EnvAnimal };
		SimpleFilter AnimalDrop = {
			living::Falcon,
			living::Pigeon,
			living::Finch,
			living::Wigeon,
			living::Crane,
			living::Crow,
			living::Fox,
			living::Squirrel,
			living::Boar,
			living::Weasel,
			living::Tukan
		};
		SimpleFilter AnimalPickUp = {
			living::CrystalCore,
			living::Salamander,
			living::Frog,
			living::Crab,
			living::LizardTail,
			living::Eel,
			living::Onikabuto,
			living::ButterflyWings,
			living::LucklightFly,
			living::LuminescentSpine,
			living::Starconch,
			living::BirdEgg,
			living::WeaselThief,
			living::Fish
		};
		SimpleFilter AnimalNPC = {
			living::Dog,
			living::Cat,
			living::Kitsune,
			living::BakeDanuki
		};
		SimpleFilter Monsters = { EntityType__Enum_1::Monster };
		SimpleFilter MonsterCommon = {
			monster::Slime,
			monster::FloatingFungus,
			monster::Specter,
			monster::Whopperflower,
			monster::Hilichurl,
			monster::Samachurl,
			monster::UnusualHilichurl,
			monster::FatuiSkirmisher,
			monster::TreasureHoarder,
			monster::Nobushi,
			monster::Kairagi,
			monster::Millelith,
			monster::ShogunateInfantry,
			monster::SangonomiyaCohort,
			monster::Eremite,
			monster::StretchyFungus,
			monster::WhirlingFungus,
			monster::WingedShroom,
			monster::GroundedShroom,
			monster::ShaggySumpterBeast,
			monster::RishbolandTiger,
			monster::Spincrocodile
		};
		SimpleFilter MonsterElites = {
			monster::Mitachurl,
			monster::AbyssMage,
			monster::HydroAbyssHerald,
			monster::PyroAbyssLector,
			monster::ElectroAbyssLector,
			monster::RifthoundWhelp,
			monster::Rifthound,
			monster::ShadowyHusk,
			monster::RuinDrake,
			monster::RuinGuard,
			monster::RuinHunter,
			monster::RuinGrader,
			monster::RuinSentinel,
			monster::Cicin,
			monster::FatuiCicinMage,
			monster::FatuiAgent,
			monster::FatuiMirrorMaiden,
			monster::GeovishapHatchling,
			monster::Geovishap,
			monster::HydroBathysmalVishap,
			monster::EyeOfTheStorm,
			monster::BlackSerpentKnight
		};
		SimpleFilter MonsterBosses = {
			// Adding these comments for better tracking.
			// Trounce
			monster::Dvalin,
			monster::Azhdaha,
			monster::Signora,
			monster::Shogun,
			monster::Andrius,
			monster::Tartaglia,
			// Mondstadt
			monster::CryoRegisvine,
			monster::ElectroHypostasis,
			monster::AnemoHypostasis,
			monster::CryoHypostasis,
			// Liyue
			monster::PyroRegisvine,
			monster::Oceanid,
			monster::OceanidBoar,
			monster::OceanidCrab,
			monster::OceanidCrane,
			monster::OceanidFalcon,
			monster::OceanidFinch,
			monster::OceanidFrog,
			monster::OceanidSquirrel,
			monster::OceanidWigeon,
			monster::GeoHypostasis,
			monster::RuinSerpent,
			monster::PrimoGeovishap,
			monster::Beisht,
			// Inazuma
			monster::PerpetualMechanicalArray,
			monster::PyroHypostasis,
			monster::MaguuKenki,
			monster::ThunderManifestation,
			monster::GoldenWolflord,
			monster::HydroHypostasis,
			monster::HydroHypostasisSummon,
			monster::CryoBathysmalVishap,
			monster::ElectroBathysmalVishap,
			// Sumeru
			monster::ElectroRegisvine,
			monster::JadeplumeTerrorshroom

		};
		SimpleFilter MonsterShielded = {
			// Taken from https://genshin-impact.fandom.com/wiki/Shields/Enemy.
			// We won't be including Regisvines and enemy objects here,
			// just regular monsters.
			monster::AbyssMage,
			monster::Slime,
			monster::Mitachurl,
			monster::ElectroAbyssLector,
			monster::HydroAbyssHerald,
			monster::PyroAbyssLector,
			monster::FatuiCicinMage,
			monster::Cicin,
			monster::Whopperflower
		};
		SimpleFilter MonsterEquips = { EntityType__Enum_1::MonsterEquip };
		BlacklistFilter Living = {
			{EntityType__Enum_1::EnvAnimal, EntityType__Enum_1::Monster},
			{
				// Environmental mobs
				"Cat", "DogPrick", "Vulpues", "Inu_Tanuki",
				// Overworld bosses
				"Ningyo", "Regisvine", "Hypostasis", "Planelurker", "Nithhoggr"
			}
		};
		SimpleFilter OrganicTargets = { Monsters, Animals }; // Solael: Please don't mess around with this filter.
		//m0nkrel: We can choose the entities we need ourselves so as not to magnetize cats, dogs, etc.
		//AdvancedFilter Animals = { {EntityType__Enum_1::EnvAnimal, EntityType__Enum_1::Monster }, {"Crane", "Tit", "Boar", "Squirrel", "Fox", "Pigeon", "Wigeon", "Falcon" ,"Marten" } };

		SimpleFilter Lightning = { EntityType__Enum_1::Lightning };
	}
}
