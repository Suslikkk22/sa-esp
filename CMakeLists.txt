cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(plugin-sdk)

add_library(AmazingTreasureESP MODULE main.cpp)
target_link_libraries(AmazingTreasureESP PRIVATE plugin_sa)

set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)