<h1 align="center">Akebi GC</h1>
The great software for some game that exploiting anime girls (and boys).

We opened [Discord server](https://discord.gg/MmV8hNZB9S)
<hr>
<h1 align="center">Getting Started</h1>

### Building from source
It is reccomended to use [Visual Studio 2022.](https://visualstudio.microsoft.com/)
As well as setting up **`cheat-library`** as startup project.
**The following is a recommended procedure, but others may be used.**
1. Clone repository with `git clone --recurse-submodules https://github.com/Akebi-Group/Akebi-GC.git`
1. Open `Akebi-GC/akebi-gc.sln`
1. Build solution `akebi-gc.sln`.

### Release
1. Head over to the releases page
1. Download the latest binaries

### Usage
(1-2 are optional if you didn't build from source)
1. Open `/bin`
1. Open Compiled version (debug, release)


1. Insure that `CLibrary.dll` is in the same folder that `injector.exe`.
1. Run `injector.exe`.

<h1 align="center">Features</h1>

#### General
- Protection Bypass
- In-Game GUI
- Hotkeys

#### Player
- God Mode
- Unlimited Stamina  
- Dumb Enemies (Enemies don't attack)
- Player
- Multiply Attacks
- No Cooldown Skill/Ultimate
- No Cooldown Sprint

#### World
- Auto Loot  
- Auto Talk  
- Killaura  
- Auto Tree Farm  
- Mob Vacuum
- Auto Fish

#### Teleport
- Chest/Oculi Teleport (Teleports to nearest)
- Map Teleport (Teleport to mark on map)

#### Visuals 
- ESP
- Interactive Map
- Elemental Sight

#### Debugging
- Entity List
- Position Info
- FPS Graph
- Packet Sniffer


<h1 align="center">Demo</h1>

<details>
  <summary>Map Teleportation</summary>
  <img src="https://github.com/CallowBlack/gif-demos/blob/main/genshin-cheat/map-teleport-demo.gif"/>
</details>
<details>
  <summary>Noclip</summary>
  <img src="https://github.com/CallowBlack/gif-demos/blob/main/genshin-cheat/noclip-demo.gif"/>
</details>
<details>
  <summary>TP to Oculi</summary>
  <img src="https://github.com/CallowBlack/gif-demos/blob/main/genshin-cheat/oculi-teleport-demo.gif"/>
</details>
<details>
  <summary>TP to Chests</summary>
  <img src="https://github.com/CallowBlack/gif-demos/blob/main/genshin-cheat/chest-teleport-demo.gif"/>
</details>
<details>
  <summary>Rapid Fire</summary>
  <img src="https://github.com/CallowBlack/gif-demos/blob/main/genshin-cheat/rapid-fire-demo.gif"/>
</details>
<details>
  <summary>Auto Talk</summary>
  <img src="https://github.com/CallowBlack/gif-demos/blob/main/genshin-cheat/auto-talk-demo.gif"/>
</details>

<h1 align="center">Contributing</h1>

## Adding a feature
1. Fork the Project
1. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
1. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
1. Push to the Branch (`git push origin feature/AmazingFeature`)
1. Open a Pull Request

## Suggestions

Open an issue with the title of the suggesstion you want to make.
In the description, make sure it is descriptive enough so our devs can understand what you want and how you want it.  

## Bugs
Welcome to the short explanation for bug reporting, as well as the bug report template.

1. Find a bug and write down what happened, as well as your first thoughts on what you think caused it.

2. Try to reproduce the bug. For this you need to understand what actually happened, leading up to the bug and when the actual bug happened. To make sure you get all this information correctly taking various forms of documentations, such as video, screenshots etc is essential. These steps makes it a lot easier to try and figure out what actually happened. Try to replicate the scenario where the bug appeared, as close to the original as possible. What we would recommend for this step is using the bug reporting template which can be found on page 2 and simply adding the information you have / find in there.

3. can it be reproduced? Yes or no. If yes: Explain in as much detail as possible what happens when the bug occurs and why it occurs. Try and explain it as cleanly and as concise as possible to make sure that the coders don’t have to read an essay to understand what could be a simple bug with a simple fix. For this, remember that information is very subjective so it is much better to over communicate than to risk confusion. If no: Try to provide as much information about the bug as possible, so that the testers will be able to replicate the scenario in which the bug occurred more easily so we can try to reproduce the bug.

4. Tell us which version you are using. Otherwise we would be getting bug reports on the same issue, that has been infact fixed in the latest commits. copy the SHA / Version Number of the latest commit when you built the mod. For example: `bd17a00ec388f3b93624280cde9e1c66e740edf9` / Release 0.7

Notes: Please remember to always record your testing sessions on your local hard drive and then upload them unlisted to youtube to conserve memory space on your computer and to give us easy access to your replays. This is to ensure that the optimal amount of documentation is available for the bug testers and coders to use as a guideline for either replicating scenarios, reproducing bugs or fixing them.

TL:DR Record all your stuff while playing the mod and report any bugs to the issues section of this repository.

### Bug reporting template
Title: e.g. “Instantly kill enemy with Shackles“
Description: “Game crashed if x, y, z“

-- Footer -- 
Date Occured: 5 / 3 / 2022
Is it reproducible: Yes / Occasionally / No
Latest Commit used: `bd17a00ec388f3b93624280cde9e1c66e740edf9`
Release Version: 0.7
