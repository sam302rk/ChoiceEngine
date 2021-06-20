# [ChoiceEngine](https://github.com/GamingCrafthd/ChoiceEngine/releases)
Engine for Text-based Story games like [Emily is Away](https://store.steampowered.com/app/417860/Emily_is_Away/) or [Doki Doki Literature Club](https://ddlc.plus/)

## Plans for the future
- API
    - [ ] C++
- API Wrappers
    - [ ] Node.js
    - [ ] C#
    - [ ] Python
    - [ ] Java
- [ ] Editor
- Direct Game Engine Ports
    - [ ] Unity
    - [ ] Unreal Engine
    - [ ] Godot

## Install
- Get the latest release [here](https://github.com/GamingCrafthd/ChoiceEngine/releases)
- Move the `*.cpp` File and the `*.h` File into your codebase.
- Import using 
  ```cpp
  #include "ChoiceEngine.h"
  #include "ChoiceEngine.cpp"
  ```
- Create a implementation<br>
  **Example:**
  ```cpp
  namespace your_game
  {
    class ce_impl : public implementation
    {
    public:
        void on_..._event(...) override
        {
        // ...
        }
    }
  }
  ```

## Basic Concept
A folder represents a dialog element being a dialog option or dialog by a npc.<br>
A dialog element has all elements comming after that inside it (a basic folder hirachy)<br>
Also, there will be a audio line (If required) and some json data inside it.<br>

## Own Game Engine
A Game Engine like Source Engine, where you can create choice games with a built-in version of <br>the editor and a game store with community-created choice-games.

## Limitation & Solution: Character Limit for URIs
**Limitation**<br>There are some limitations regarding chracter limits in some operating systems for the path.<br>
This could become a issue, when longer games are being made or the large folder names being used.

**Solution**<br>Splitting the game into multiple chapters or if needed into invisible chapters.
