# simpleterm

The goal of this library is to create a cross-platform terminal library that works on (at least):

  - Linux
  - MacOSx
  - Windows

For POSIX platforms (i.e. non-Windows) I will be using ANSI escape sequences to control the terminal. On Windows, we will be using Windows-specific calls and libraries (such as the "windows.h" include file).

## Why Not Curses?

Good question! If you have to ask this, you probably just want to use curses :)

If you insist, here are some reasons:

  - Small library size
  - Permissive license
  - Cross-platform (hopefully without using stuff like MinGW)
