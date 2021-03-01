cmake_minimum_required(VERSION 3.15)
# set the project name
set(PROJECT_NAME Main)
project(${PROJECT_NAME})

# add the executable
add_executable(${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Tests enabled")
    add_subdirectory(test)
endif()
#option(BUILD_TESTING "" OFF)

add_subdirectory(src)
