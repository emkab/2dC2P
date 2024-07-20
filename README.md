# 2dC2P

A C++ graphics library using SDL2.
Only scene is a physics simulation of balls colliding inside a circle.

# Usage - Windows only!

Download MSYS2 [here](https://www.msys2.org) and run it.
Install MINGW in the MSYS2 terminal using the following command:

    $ pacman -S mingw-w64-ucrt-x86_64-gcc

And add the UCRT bin directory to windows PATH:

    "[MSYS2-Installtion-Directory]\ucrt64\bin"

The default MSYS2 installation directory is "C:\msys64".

Unzip the release folder and open the executable.

To use Command-Line arguments execute from the terminal.
**Keybinds:**

> Left-click - Drag ball
> 
> Middle-click - Toggle momentum loss
> 
> Right-click - Toggle gravity

**Command-Line argument format:**

> ./main.exe ballCount[int] gravity[bool] randDensity[bool] randSpeed[int] momentumLoss[bool]
