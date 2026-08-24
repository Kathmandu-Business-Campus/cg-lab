
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