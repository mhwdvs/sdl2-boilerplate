project(tests)
include_directories(${SOURCE_DIR})

file(GLOB SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")

# add executable to tests project
add_executable(tests ${SOURCES})

# Include and link against dependencies.
target_link_libraries(tests PUBLIC ${CMAKE_PROJECT_NAME}_lib)

# --- DEPENDENCIES ---
# Google Test
# Download and unpack googletest at configure time
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

include(GoogleTest)
gtest_add_tests(TARGET tests)

# END GOOGLETEST
#------------------------------------------------------