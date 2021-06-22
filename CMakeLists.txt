cmake_minimum_required(VERSION 3.15)
# set the project name
set(PROJECT_NAME Main)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)

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
    $<$<CXX_COMPILER_ID:Clang>:-std=c++11 -v -Wall -Wextra -fno-omit-frame-pointer -fsanitize=address,undefined,leak>

    # GNU GCC/G++
    $<$<CXX_COMPILER_ID:GNU>:-std=c++11 -Wall -Wextra -Werror -pedantic>

    # MSVC
    $<$<CXX_COMPILER_ID:MSVC>:/std:c11 /W4 /WX>
)

target_link_options(${PROJECT_NAME} PRIVATE
    # Clang and AppleClang
    $<$<CXX_COMPILER_ID:Clang>:-fsanitize=address,undefined,leak>
)


# Doxygen and graphiz
find_package(Doxygen REQUIRED dot REQUIRED)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    add_custom_target(doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
endif ()
