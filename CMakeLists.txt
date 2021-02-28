cmake_minimum_required(VERSION 3.15)
# set the project name
set(PROJECT_NAME Main)
project(${PROJECT_NAME})

# add the executable
add_executable(${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

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

# --- DEPENDENCIES ---

# Google Test
# Download and unpack googletest at configure time
option(BUILD_TESTING "" OFF)
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Include and link against dependencies.
target_link_libraries(${PROJECT_NAME} PRIVATE gtest gmock gtest_main)

include(CTest)
include(GoogleTest)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    #enable_testing()
    option(BUILD_TESTING "" ON)
    gtest_discover_tests(${PROJECT_NAME})
else()
    message("yo")
    set(${BUILD_TESTING} OFF)
endif()
message(BUILD_TESTING)

add_subdirectory(src)
