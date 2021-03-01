cmake_minimum_required(VERSION 3.15)
# set the project name
set(PROJECT_NAME Main)
project(${PROJECT_NAME})

# add the executable
add_executable(${PROJECT_NAME})
# add associated directory for main executable
add_subdirectory(src)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Tests enabled in debug build!")
    # create tests projects
    project(tests)
    # add executable to tests project
    add_executable(tests)
    # add associated directory for tests executable
    add_subdirectory(test)
endif()

