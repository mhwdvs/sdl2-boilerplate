cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Main)

# set the project name
project(${PROJECT_NAME} LANGUAGES C)

# add the executable
add_executable(${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)

# Set compile flags.
target_compile_options(${PROJECT_NAME} PRIVATE
        # Clang
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
        -Weverything -fcolor-diagnostics
        # Disable specific warnings.
        -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded
        -Wno-deprecated-declarations -Wno-exit-time-destructors
        -Wno-switch-enum -Wno-weak-vtables -Wno-global-constructors>
        # GCC
        $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic -fdiagnostics-color=always>
        # Visual Studio
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        # Enable the clang sanitizer.
        $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>,$<PLATFORM_ID:${SANITIZER_OS}>>:${SANITIZER_FLAGS}>
        )

# Link against the clang sanitizer.
target_link_options(${PROJECT_NAME} PRIVATE
        $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>,$<PLATFORM_ID:${SANITIZER_OS}>>:${SANITIZER_FLAGS}>
        )

if (LINUX)
    target_link_libraries(${PROJECT_NAME} PRIVATE -lm)
endif()

# DEPENDENCIES
# find_package(OpenGL REQUIRED) # OpenGL

# Include and link against dependencies.
#target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT ${CMAKE_DL_LIBS})

add_subdirectory(src)

