cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем plugin-sdk как поддиректорию (если CMake жалуется, проверим путь)
add_subdirectory(plugin-sdk)

add_library(AmazingTreasureESP MODULE main.cpp)

# В plugin-sdk для SA цель обычно называется plugin_sa или plugin
target_link_libraries(AmazingTreasureESP PRIVATE plugin_sa)

set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)
