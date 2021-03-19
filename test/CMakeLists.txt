project(tests)
include_directories(${SOURCE_DIR})
message(${SOURCE_DIR})

# add executable to tests project
add_executable(tests
        testlib.cpp
        )

# Include and link against dependencies.
target_link_libraries(tests PUBLIC ${CMAKE_PROJECT_NAME}_lib)
