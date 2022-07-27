#pragma once

#include "AdvancedFilter.h"
#include "SimpleFilter.h"
#include "ChestFilter.h"

namespace cheat::game::filters
{
	namespace collection
	{
		extern SimpleFilter Book;
		extern SimpleFilter Viewpoint;
		extern SimpleFilter WoodenCrate;
		extern SimpleFilter GeoSigil;

		extern ChestFilter RadiantSpincrystal;
		extern ChestFilter BookPage;
		extern ChestFilter QuestInteract;
	}

	namespace chest
	{
		extern ChestFilter CommonChest;
		extern ChestFilter ExquisiteChest;
		extern ChestFilter PreciousChest;
		extern ChestFilter LuxuriousChest;
		extern ChestFilter RemarkableChest;
		extern ChestFilter SearchPoint;

		extern ChestFilter SLocked;
		extern ChestFilter SInLock;
		extern ChestFilter SFrozen;
		extern ChestFilter SBramble;
		extern ChestFilter STrap;
	}

	namespace equipment
	{
		extern SimpleFilter Artifacts;
		extern SimpleFilter Bow;
		extern SimpleFilter Claymore;
		extern SimpleFilter Catalyst;
		extern SimpleFilter Pole;
		extern SimpleFilter Sword;
	}

	namespace featured
	{
		extern SimpleFilter Anemoculus;
		extern SimpleFilter CrimsonAgate;
		extern SimpleFilter Electroculus;
		extern SimpleFilter Dendroculus;
		extern SimpleFilter EchoingConch;
		extern SimpleFilter Electrogranum;
		extern SimpleFilter FishingPoint;
		extern SimpleFilter Geoculus;
		extern SimpleFilter ImagingConch;
		extern WhitelistFilter ItemDrops;
		extern SimpleFilter Lumenspar;
		extern SimpleFilter KeySigil;
		extern SimpleFilter ShrineOfDepth;
		extern SimpleFilter TimeTrialChallenge;
	}

	namespace guide
	{
		extern SimpleFilter CampfireTorch;
		extern SimpleFilter DayNightSwitchingMechanism;
		extern SimpleFilter EnkanomiyaPhaseGate;
		extern SimpleFilter MysteriousCarvings;
		extern SimpleFilter PhaseGate;
		extern SimpleFilter PlacesofEssenceWorship;
		extern SimpleFilter Pot;
		extern SimpleFilter RuinBrazier;
		extern SimpleFilter Stormstone;
		extern SimpleFilter TriangularMechanism;
	}

	namespace living
	{
		extern SimpleFilter AvatarOwn;
		extern SimpleFilter AvatarTeammate;
		extern SimpleFilter BirdEgg;
		extern SimpleFilter ButterflyWings;
		extern SimpleFilter Crab;
		extern SimpleFilter CrystalCore;
		extern SimpleFilter Fish;
		extern SimpleFilter Frog;
		extern SimpleFilter LizardTail;
		extern SimpleFilter LuminescentSpine;
		extern SimpleFilter Onikabuto;
		extern SimpleFilter Starconch;
		extern SimpleFilter Eel;
		extern SimpleFilter Inu;
		extern SimpleFilter Boar;
		extern SimpleFilter Fox;
		extern SimpleFilter Squirrel;
		extern SimpleFilter Crane;
		extern SimpleFilter Falcon;
		extern SimpleFilter LucklightFly;
		extern SimpleFilter Npc;
		extern SimpleFilter Salamander;
		extern SimpleFilter Tukan;
		extern SimpleFilter Pigeon;
		extern SimpleFilter Crow;
		extern SimpleFilter Finch;
		extern SimpleFilter Wigeon;
		extern SimpleFilter Dog;
		extern SimpleFilter Cat;
		extern SimpleFilter Weasel;
		extern SimpleFilter Kitsune;
		extern SimpleFilter BakeDanuki;
		extern SimpleFilter Meat;
	}

	namespace mineral
	{
		extern SimpleFilter AmethystLump;
		extern SimpleFilter ArchaicStone;
		extern SimpleFilter CorLapis;
		extern SimpleFilter CrystalChunk;
		extern SimpleFilter CrystalMarrow;
		extern SimpleFilter ElectroCrystal;
		extern SimpleFilter IronChunk;
		extern SimpleFilter NoctilucousJade;
		extern SimpleFilter MagicalCrystalChunk;
		extern SimpleFilter ScarletQuartz;
		extern SimpleFilter Starsilver;
		extern SimpleFilter WhiteIronChunk;
		extern SimpleFilter DunlinsTooth;

		extern SimpleFilter AmethystLumpDrop;
		extern SimpleFilter CrystalChunkDrop;
		extern SimpleFilter ElectroCrystalDrop;
		extern SimpleFilter IronChunkDrop;
		extern SimpleFilter NoctilucousJadeDrop;
		extern SimpleFilter MagicalCrystalChunkDrop;
		extern SimpleFilter ScarletQuartzDrop;
		extern SimpleFilter StarsilverDrop;
		extern SimpleFilter WhiteIronChunkDrop;
	}

	namespace monster
	{
		extern SimpleFilter AbyssMage;
		extern SimpleFilter Eremite;
		extern SimpleFilter FatuiAgent;
		extern SimpleFilter FatuiCicinMage;
		extern SimpleFilter FatuiMirrorMaiden;
		extern SimpleFilter FatuiSkirmisher;
		extern SimpleFilter Geovishap;
		extern SimpleFilter GeovishapHatchling;
		extern SimpleFilter Hilichurl;
		extern SimpleFilter JadeplumeTerrorshroom;
		extern SimpleFilter Mitachurl;
		extern SimpleFilter Nobushi;
		extern SimpleFilter Kairagi;
		extern SimpleFilter RuinDrake;
		extern SimpleFilter RuinGuard;
		extern SimpleFilter RuinGrader;
		extern SimpleFilter RuinHunter;
		extern SimpleFilter RuinSentinel;
		extern SimpleFilter Samachurl;
		extern SimpleFilter ShadowyHusk;
		extern SimpleFilter Slime;
		extern SimpleFilter FloatingFungus;
		extern SimpleFilter StretchyFungus;
		extern SimpleFilter WhirlingFungus;
		extern SimpleFilter WingedShroom;
		extern SimpleFilter GroundedShroom;
		extern SimpleFilter Specter;
		extern SimpleFilter TreasureHoarder;
		extern SimpleFilter UnusualHilichurl;
		extern SimpleFilter Whopperflower;
		extern SimpleFilter RifthoundWhelp;
		extern SimpleFilter Rifthound;
		extern SimpleFilter Dvalin;
		extern SimpleFilter Andrius;
		extern SimpleFilter Tartaglia;
		extern SimpleFilter Azhdaha;
		extern SimpleFilter Signora;
		extern SimpleFilter Shogun;
		extern SimpleFilter EyeOfTheStorm;
		extern SimpleFilter ElectroHypostasis;
		extern SimpleFilter AnemoHypostasis;
		extern SimpleFilter GeoHypostasis;
		extern SimpleFilter HydroHypostasis;
		extern SimpleFilter CryoHypostasis;
		extern SimpleFilter PyroHypostasis;
		extern SimpleFilter HydroHypostasisSummon;
		extern SimpleFilter Oceanid;
		extern SimpleFilter OceanidBoar;
		extern SimpleFilter OceanidCrane;
		extern SimpleFilter OceanidCrab;
		extern SimpleFilter OceanidFinch;
		extern SimpleFilter OceanidWigeon;
		extern SimpleFilter OceanidSquirrel;
		extern SimpleFilter OceanidFrog;
		extern SimpleFilter OceanidFalcon;
		extern SimpleFilter PerpetualMechanicalArray;
		extern SimpleFilter PrimoGeovishap;
		extern SimpleFilter HydroBathysmalVishap;
		extern SimpleFilter CryoBathysmalVishap;
		extern SimpleFilter ElectroBathysmalVishap;
		extern SimpleFilter ThunderManifestation;
		extern SimpleFilter HydroAbyssHerald;
		extern SimpleFilter ElectroAbyssLector;
		extern SimpleFilter PyroAbyssLector;
		extern SimpleFilter BlackSerpentKnight;
		extern SimpleFilter GoldenWolflord;
		extern SimpleFilter RuinSerpent;
		extern SimpleFilter Millelith;
		extern SimpleFilter ShogunateInfantry;
		extern SimpleFilter SangonomiyaCohort;
		extern SimpleFilter CryoRegisvine;
		extern SimpleFilter PyroRegisvine;
		extern SimpleFilter ElectroRegisvine;
		extern SimpleFilter MaguuKenki;
		extern SimpleFilter Cicin;
		extern SimpleFilter Beisht;
		extern SimpleFilter RishbolandTiger;
		extern SimpleFilter ShaggySumpterBeast;
		extern SimpleFilter Spincrocodile;
	}

	namespace plant
	{
		extern SimpleFilter AmakumoFruit;
		extern SimpleFilter Apple;
		extern SimpleFilter BambooShoot;
		extern SimpleFilter Berry;
		extern SimpleFilter Cabbage;
		extern SimpleFilter CallaLily;
		extern SimpleFilter Carrot;
		extern SimpleFilter Cecilia;
		extern SimpleFilter DandelionSeed;
		extern SimpleFilter Dendrobium;
		extern SimpleFilter FlamingFlowerStamen;
		extern SimpleFilter FluorescentFungus;
		extern SimpleFilter GlazeLily;
		extern SimpleFilter Horsetail;
		extern SimpleFilter JueyunChili;
		extern SimpleFilter LavenderMelon;
		extern SimpleFilter LotusHead;
		extern SimpleFilter Matsutake;
		extern SimpleFilter Mint;
		extern SimpleFilter MistFlowerCorolla;
		extern SimpleFilter Mushroom;
		extern SimpleFilter NakuWeed;
		extern SimpleFilter PhilanemoMushroom;
		extern SimpleFilter Pinecone;
		extern SimpleFilter Potato;
		extern SimpleFilter Qingxin;
		extern SimpleFilter Radish;
		extern SimpleFilter SakuraBloom;
		extern SimpleFilter SangoPearl;
		extern SimpleFilter SeaGanoderma;
		extern SimpleFilter Seagrass;
		extern SimpleFilter SilkFlower;
		extern SimpleFilter SmallLampGrass;
		extern SimpleFilter Snapdragon;
		extern SimpleFilter Sunsettia;
		extern SimpleFilter SweetFlower;
		extern SimpleFilter Valberry;
		extern SimpleFilter Violetgrass;
		extern SimpleFilter Wheat;
		extern SimpleFilter WindwheelAster;
		extern SimpleFilter Wolfhook;
		extern SimpleFilter RadishDrop;
		extern SimpleFilter CarrotDrop;
		extern SimpleFilter HarraFruit;
		extern SimpleFilter KalpalataLotus;
		extern SimpleFilter NilotpalaLotus;
		extern SimpleFilter Padisarah;
		extern SimpleFilter RukkhashavaMushrooms;
		extern SimpleFilter SumeruRose;
		//extern SimpleFilter Viparyas;
		extern SimpleFilter ZaytunPeach;
	}

	namespace puzzle
	{
		extern SimpleFilter AncientRime;
		extern SimpleFilter BakeDanuki;
		extern SimpleFilter BloattyFloatty;
		extern WhitelistFilter CubeDevices;
		extern SimpleFilter EightStoneTablets;
		extern SimpleFilter ElectricConduction;
		extern SimpleFilter RelayStone;
		extern WhitelistFilter ElectroSeelie;
		extern SimpleFilter ElementalMonument;
		extern SimpleFilter FloatingAnemoSlime;
		extern SimpleFilter Geogranum;
		extern SimpleFilter GeoPuzzle;
		extern SimpleFilter LargeRockPile;
		extern SimpleFilter LightUpTilePuzzle;
		extern SimpleFilter LightningStrikeProbe;
		extern SimpleFilter LumenCage;
		extern SimpleFilter LuminousSeelie;
		extern SimpleFilter MistBubble;
		extern SimpleFilter OozingConcretions;
		extern SimpleFilter PirateHelm;
		extern WhitelistFilter PressurePlate;
		extern SimpleFilter SealLocations;
		extern SimpleFilter SeelieLamp;
		extern SimpleFilter Seelie;
		extern SimpleFilter SmallRockPile;
		extern SimpleFilter StormBarrier;
		extern SimpleFilter SwordHilt;
		extern SimpleFilter Temari;
		extern SimpleFilter TorchPuzzle;
		extern SimpleFilter UniqueRocks;
		extern SimpleFilter WarmingSeelie;
		extern SimpleFilter WindmillMechanism;
		extern WhitelistFilter MelodicBloom;
		extern SimpleFilter CloudleisureSteps;
		extern WhitelistFilter DreamForm;
		extern SimpleFilter StarlightCoalescence;
		extern SimpleFilter TheRavenForum;
	}

	namespace combined
	{
		extern SimpleFilter Oculies;
		extern SimpleFilter Chests;
		extern SimpleFilter Ores;
		extern WhitelistFilter Doodads;
		extern SimpleFilter Animals;
		extern SimpleFilter AnimalDrop;
		extern SimpleFilter AnimalPickUp;
		extern SimpleFilter AnimalNPC;
		extern SimpleFilter Monsters;
		extern SimpleFilter MonsterCommon;
		extern SimpleFilter MonsterElites;
		extern SimpleFilter MonsterBosses;
		extern SimpleFilter MonsterShielded;
		extern SimpleFilter MonsterEquips;
		extern BlacklistFilter Living;
		extern SimpleFilter OrganicTargets;
		extern SimpleFilter Lightning;
	}
}