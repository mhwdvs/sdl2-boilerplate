# Build glad2
add_subdirectory(glad/cmake)
glad_add_library(glad SHARED API gl:core=4.5 LOCATION ${CMAKE_BINARY_DIR}/src)
execute_process(COMMAND  "pip install .") # install python requirements

# Build SDL2
include_directories(${PROJECT_SOURCE_DIR}/SDL)
add_subdirectory(SDL)
