cmake_minimum_required(VERSION 3.19)
# set the project name
set(PROJECT_NAME Main)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

include(CTest)

# Build libs
add_subdirectory(lib)

# add associated directory for main executable
add_subdirectory(src)
# add associated directory for tests executable
add_subdirectory(test)

# Set compile options
target_compile_options(${PROJECT_NAME} PRIVATE 
    # Clang and AppleClang
    $<$<CXX_COMPILER_ID:Clang>:-v -Wall -Wextra -fsanitize=address,undefined,leak>

    # GNU GCC/G++
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Werror -pedantic>

    # MSVC
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

target_link_options(${PROJECT_NAME} PRIVATE
    # Clang and AppleClang
    $<$<CXX_COMPILER_ID:Clang>:-fsanitize=address,undefined,leak>
)
