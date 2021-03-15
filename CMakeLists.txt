cmake_minimum_required(VERSION 3.15)
# set the project name
set(PROJECT_NAME Main)
project(${PROJECT_NAME})

# add the executable
add_executable(${PROJECT_NAME})
# add associated directory for main executable
add_subdirectory(src)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# GoogleTest
if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Tests enabled in debug build!")
    # create tests projects
    project(tests)
    # add executable to tests project
    add_executable(tests)
    # add associated directory for tests executable
    add_subdirectory(test)
endif()

# Doxygen
find_package(Doxygen REQUIRED dot REQUIRED)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    add_custom_target(doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
endif ()

