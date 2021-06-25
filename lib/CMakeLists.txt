# Build glad2
add_subdirectory(glad/cmake)
glad_add_library(glad REPRODUCIBLE API gl:core=4.5)

# Build SDL2
include_directories(${PROJECT_SOURCE_DIR}/SDL)
add_subdirectory(SDL)
