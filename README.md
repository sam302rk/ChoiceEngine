# [ChoiceEngine](https://github.com/GamingCrafthd/ChoiceEngine/releases) - [Wiki](https://github.com/GamingCrafthd/ChoiceEngine/wiki)
Logic Engine for games with dialog and advanced story games.

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
- [ ] *.ce File Editor
- [ ] Tech-demo

## Basic Concept
A folder represents a dialog element being a dialog option or dialog by a npc.<br>
A dialog element has all elements comming after that inside it (a basic folder hirachy)<br>
Also, there will be a audio line (If required) and some json data inside it.<br>

## Own Game Engine
A Game Engine like Source Engine, where you can create choice games with a built-in version of <br>the editor and a game store with community-created choice-games.

## Limitation & Solution: Character Limit for URIs
**Limitation**<br>There are some limitations regarding chracter limits in some operating systems for the path.<br>
This could become a issue, when longer games are being made or the large folder names being used.<br>
**More informations** - [Windows](https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation),  [Linux](https://unix.stackexchange.com/questions/32795/what-is-the-maximum-allowed-filename-and-folder-size-with-ecryptfss)

**Solution**<br>Splitting the game into multiple chapters or if needed into invisible chapters.
