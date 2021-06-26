# C++ SDL2 Boilerplate

A general purpose C++ SDL2 boilerplate. 

Comes preconfigured with Google Test/CTest and basic project structure

## Cloning

This project utilises *git submodules*. To both clone this and the required submodules run `git clone --recurse-submodules https://github.com/mhwdvs/sdl2-boilerplate`

Alternatively, you can run `git submodules init && git submodules update` if you have already cloned the repo without submodules

## Dependencies

### Linux

- `sudo apt install clang build-essential git make cmake ninja-build autoconf automake libtool pkg-config libasound2-dev libpulse-dev libaudio-dev libjack-dev libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxi-dev libxinerama-dev libxxf86vm-dev libxss-dev libgl1-mesa-dev libdbus-1-dev libudev-dev libgles2-mesa-dev libegl1-mesa-dev libibus-1.0-dev fcitx-libs-dev libsamplerate0-dev libsndio-dev libwayland-dev libxkbcommon-dev libdrm-dev libgbm-dev`

### MacOS

TODO

### Windows

- git
- MSVC
- CMake

## Building

Generate Ninja build files:
`cmake -S . -B build --DCMAKE_BUILD_TYPE=Release -G Ninja`

Build with Ninja
`cmake --build build`

## Run

### Linux/MacOS

`cd build/src/ && ./Main`

### Windows

`cd build/src/ && Main.exe`

## Using unsupported software

## Compatability

### CMake generators

It is recommended that Ninja and the `ninja` CMake generator is used (`-G Ninja`). Theoretically any generator can be used, but some generators will use odd directory structures that will interfere with things such as copying resources into the correct places in the build directory.

### Compilers

It is recommended that `clang` is used on Linux/MacOS systems, and `MSVC` on Windows systems.

- GCC is untested on Linux but should work fine
- From my testing, GCC/Clang will not build SDL on Windows wit the CMake script they provide
- If MSVC was undesirable, it should be possible to build the rest of the project with any standards-complient compiler and provide a pre-built SDL `dll`
    - TODO

### SDL version control

Currently this project is configured to build the latest stable release of SDL from source.

This project dynamically links SDL, so if you would like to provide your own version simply *replace `SDL2d.dll` on Windows or TODO on Linux/MacOS. If your replacement is in PATH, simply delete the SDL dynamic library built by this project

TODO: CMake should detect if SDL is available in PATH