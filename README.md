
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



# 4. Colors

The colors are available at:
https://www.geeksforgeeks.org/c/setcolor-function-c/

# 6. For freeglut library

PLEASE CONFIRM WHICH VERSION OF MINGW YOU ARE USINBG [DEFAULT IS 32 BIT].

## Version Check

- Go to bin directory of MINGW [Default: C:\MINGW\bin]
- In cmd in this directory run gcc.exe -v
- If you see somethong that has 32 in it, then  you are using 32 bit version and if you see 64, you are using 64 bit version

## Installation
1. From ./freeglut/bin copy libfreeglut.dll to bin directory of MINGW installation directory. use x64/libfreeglut.dll if you are using 64 bit version
2. From include/GL copy everything to include/GL directory of your mingw installation [default copy to C:\MINGW\include\GL]
3. From ./freeglut/lib copy libfreeglut.dll.a and to lib directory of MINGW installation directory. use files in x64/ directory if you are using 64 bit version

4. Then configure the linker in CodeBlocks:
- Settings -> Compiler
- Linker Settings
- Add the following libraries:

-lfreeglut -lopengl32 -lglu32

If you are using 64 bit mingw use the following libraries instead
-lfreeglut -lopengl -lglu

OR


-lfreeglut -lopengl64 -lglu64

This depends on your 64 bit compiler

You can now run lab 25


