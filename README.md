# C++ SDL2 Boilerplate

A general purpose C++ SDL2 boilerplate. 

Comes preconfigured with Google Test/CTest and basic project structure

## Compatability

- It is recommended that Ninja and the `ninja` CMake generator is used (`-G Ninja`)

- Clang on Linux/MacOS systems
- MSVC on Windows systems
  - This is due to SDL not building with other compilers on Windows, such as GCC and Clang, due to issues with their CMake support.
  - If MSVC was undesirable, it should be possible to build the rest of the project with any standards-complient compiler and provide a pre-built SDL `dll`
    - TODO

## How to clone

This project utilises *git submodules*. To both clone this and the required submodules run;

`git clone --recurse-submodules https://github.com/mhwdvs/sdl2-boilerplate`
