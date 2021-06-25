# Build glad2
# Configure python for glad
find_package(Python3 REQUIRED)
if(${Python3_VERSION} LESS 3.6)
    # python version too low, throw error
    message(FATAL_ERROR "-- Python version >= 3.6 required, got ${Python3_VERSION}")
else()
    message("-- Found sufficient Python version for glad2 (${Python3_VERSION} >= 3.6)")
endif()

execute_process(COMMAND  "pip install .") # install python requirements

add_subdirectory(glad/cmake)
glad_add_library(glad SHARED API gl:compatibility=1.2)

# Build SDL2
include_directories(${PROJECT_SOURCE_DIR}/SDL)
add_subdirectory(SDL)
