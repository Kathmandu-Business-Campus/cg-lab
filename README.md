
# Computer Graphics Lab Setup Guide

## 1. Install MinGW / MinGW-w64
Download one of the following:
- MinGW-w64: https://www.mingw-w64.org/downloads/
- Legacy MinGW: https://sourceforge.net/projects/mingw/

Make sure the compiler and libraries are added to PATH.

## 2. Install the graphics library
The BGI-based programs in this repository use the classic WinBGIm graphics library.

1. Download the graphics.h package from:
   https://github.com/acsfid/graphics.h
2. Copy these files into the MinGW include directory:
   - graphics.h
   - winbgim.h
3. Copy this file into the MinGW lib directory:
   - libbgi.a

Typical locations:
- C:\MinGW\include\
- C:\MinGW\lib\

## 3. Install CodeBlocks
Download from:
https://www.codeblocks.org/downloads/binaries/

Then configure the linker in CodeBlocks:
1. Settings -> Compiler
2. Linker Settings
3. Add the following libraries:

-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

## 4. OpenGL / GLUT notes for the cube demo
The OpenGL demo file uses GLUT and GLU. If the system does not provide GLUT directly, use FreeGLUT instead.

### Preferred option
Install FreeGLUT and link with:

-lfreeglut -lopengl32 -lglu32

### If system has only raw GLUT
Use:

-lglut32 -lopengl32 -lglu32

### With MinGW on Windows
The usual include headers are:

#include <GL/glut.h>
#include <GL/glu.h>

### If using Linux or a non-Windows toolchain
Use the system package manager:
- Ubuntu/Debian: sudo apt install freeglut3-dev libglu1-mesa-dev
- Fedora: sudo dnf install freeglut-devel mesa-libGLU-devel

Then compile with:

g++ lap_24_opengl_3d_cube_demo_issue.cpp -o cube -lglut -lGLU -lGL

## 5. Important note
The BGI programs are Windows-oriented because they rely on graphics.h and WinBGIm. If you are working on Linux, these programs may require a Windows cross-compiler or a virtualized Windows environment for execution.

For the newer transformed demos, the project now includes separate folders for 2D and 3D transformation examples so each operation can be studied on its own.

# Colors

The colors are available at:
https://www.geeksforgeeks.org/c/setcolor-function-c/