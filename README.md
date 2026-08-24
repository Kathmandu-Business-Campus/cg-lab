

## Setup Steps

### Download and install MinGW
Download from:
```
https://sourceforge.net/projects/mingw/
```

### Setup graphics.h library
- Download repo: 
```
https://github.com/acsfid/graphics.h
```

- Copy two files `graphics.h` and `winbgim.h` to the folder include of MinGW. The folder might be in this form: C:\MinGW\include\

- Copy file libbgi.a to the folder lib of MinGW. C:\MinGW\lib\

### Download and install CodeBlocks
- Download From:
```
https://www.codeblocks.org/downloads/binaries/
```

- Download:
codeblocks-25.03-setup.exe

### Setup linker

In codeblocks:
1. Go to Settings
2. Select Compiler
3. In Linker Settings tab add:

```

-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

```