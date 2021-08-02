# [ChoiceEngine](https://github.com/GamingCrafthd/ChoiceEngine/releases) - [Wiki](https://github.com/GamingCrafthd/ChoiceEngine/wiki)
Logic Engine for games with dialog and advanced story games.

**⚠️ EXPERIMENTAL BRANCH ⚠️**<br>
This branch is a unstable rewrite.<br>
It may be merged into main or may be discarded.

## Features
- Fully documented
- Fully customizable
- Easy to setup
- Platform independant
- Fully open-source

## Goals
- [ ] First stable builds.
- [ ] Make ChoiceEngine ready for real games.
- [ ] User friendly documentation for wrapper & game developers

## Planned Wrappers and ports
- API Wrappers
    - [ ] Node.js
    - [ ] C#
    - [ ] Python
    - [ ] Java
- Direct Game Engine Ports
    - [ ] Unity
    - [ ] Unreal Engine
    - [ ] Godot

## Future ideas
- [ ] Story Editor (w/ nodes)
- [ ] Tech-demo

## Basic Concept
A folder represents a dialog element being a dialog option or dialog by a npc.<br>
A dialog element has all elements comming after that inside it (a basic folder hirachy)<br>
Also, there will be a audio line (If required) and some data inside it.<br>

## Own Game Engine
A Game Engine like Source Engine, where you can create choice games with a built-in version of <br>the editor and a game store with community-created choice-games.

## Limitation & Solution: Character Limit for URIs
**Limitation**<br>There are some limitations regarding chracter limits in some operating systems for the path.<br>
This could become a issue, when longer games are being made or the large folder names being used.<br>
**More informations** - [Windows](https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation),  [Linux](https://unix.stackexchange.com/questions/32795/what-is-the-maximum-allowed-filename-and-folder-size-with-ecryptfss)

**Solution**<br>Splitting the game into multiple chapters or if needed into invisible chapters.

## Limitation & Solution: Handling of files and data

**Limitation**<br>There are no easy ways to work with files and to parse data.

**Solution**<br>The Game/Wrapper needs to implement methods, that get used by the engine.