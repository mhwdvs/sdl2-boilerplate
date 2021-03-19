# add the executable
set(SOURCES
        main.cpp
        Car.cpp)

set(HEADERS
        Car.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 11)
add_library(${CMAKE_PROJECT_NAME}_lib SHARED STATIC ${HEADERS} ${SOURCES})
