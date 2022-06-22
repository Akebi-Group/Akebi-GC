<h1 align="center">Akebi GC</h1>
The great software for some anime game which is for exploiting with girls (and boys).

We opened a [Discord server](https://discord.gg/MmV8hNZB9S)
<h1 align="center">Getting Started</h1>

## Building from source
It is recommended to use [Visual Studio 2022.](https://visualstudio.microsoft.com/)
As well as setting up **`cheat-library`** as startup project.
**The following is a recommended procedure, but others may be used.**
1. Clone repository with `git clone --recurse-submodules https://github.com/Akebi-Group/Akebi-GC.git`
1. Open `Akebi-GC/akebi-gc.sln`
1. Build solution `akebi-gc.sln`.

## Release
1. Head over to the releases page
1. Download the latest binaries

### Requirements
- [Visual C++ Redistributable packages for Visual Studio 2015, 2017, 2019, 2022](https://aka.ms/vs/17/release/vc_redist.x64.exe) (x64)
- [Visual C++ Redistributable packages for Visual Studio 2015, 2017, 2019, 2022](https://aka.ms/vs/17/release/vc_redist.x86.exe) (x86)

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
- Notifications

#### Player
- Invincible
- Unlimited Stamina  
- Dumb Enemies
- Attack Modifier
- No Cooldown Skill/Ultimate/Sprint

#### World
- Auto Loot  
- Auto Talk  
- Killaura  
- Auto Tree Farm  
- Mob Vacuum
- Auto Fish
- Music Event (temporary)

#### Teleport
- Chest/Oculi Teleport (Teleports to nearest)
- Map Teleport (Teleport to mark on map)
- Custom Teleport (Teleport through list)

#### Visuals 
- ESP
- Interactive Map
- Elemental Sight
- Profile Changer
- In-game Embedded Browser
- Hide UI
- Camera Zoom
- No Fog

#### Debugging
- Entities Manager
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

# Bugs
Welcome to the short explanation for bug reporting

1. You Found a bug.
1. write down what happened, as well as your first thoughts on what you think caused it.
1. can it be reproduced? Yes or no. If yes: Explain in as much clear as possible. i.e what happens when the bug occurs and why it occurs. 
1. Tell us which version you are using. copy the `SHA`/ Version Number of the latest commit when you built the mod. For example: `bd17a00ec388f3b93624280cde9e1c66e740edf9` / Release 0.7

## Bug reporting template
<br>

### Ex.
I found a bug in the feature `enemy vacuum`.  
I think it's caused by the filter functions that are defined in `someFeature.cpp`.

```
Date Occured: 5/3/2022  
Is it reproducible: Occasionally
Latest Commit used: bd17a00ec388f3b93624280cde9e1c66e740edf9
Release Version: 0.7  
```  

<h1 align="center">Contributing</h1>

## Adding a feature
1. Fork the Project
1. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
1. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
1. Push to the Branch (`git push origin feature/AmazingFeature`)
1. Open a Pull Request

## Suggestions

Open an issue with the title of the suggestion you want to make.
In the description, make sure it is descriptive enough so our devs can understand what you want and how you want it.  
