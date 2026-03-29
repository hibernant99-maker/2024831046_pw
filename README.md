# SDL2 Circle Drawing - Tasks 101 & 102
**Author:** Addin Ahmed Digonto

## Project Overview
This repository contains two C++ applications developed with the **SDL2** library on macOS. These tasks demonstrate trigonometric rendering and basic frame-based animation.

## Tasks
- **Task 101 (Static Circle):** Renders a fixed green circle at the center of the window.
- **Task 102 (Expanding Circle):** Animates a circle that increases in radius until it reaches the window boundaries.

## Features
- Manual circle rendering logic using $x = r \cdot \cos(\theta)$ and $y = r \cdot \sin(\theta)$.
- SDL2 window management and event polling.
- Automated build system via a single Makefile.

## Prerequisites
- macOS with **SDL2.framework** installed in `/Library/Frameworks/`.

## Terminal Commands
- `make` : Compiles both Task 101 and Task 102.
- `./circle101` : Runs the static circle task.
- `./circle102` : Runs the expanding circle task.
- `make clean` : Removes both executable files.