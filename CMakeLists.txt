cmake_minimum_required(VERSION 3.15)
# set the project name
set(PROJECT_NAME Main)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
project(${PROJECT_NAME})

include(CTest)

# add associated directory for main executable
add_subdirectory(src)
# add associated directory for tests executable
add_subdirectory(test)

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
