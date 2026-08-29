cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

# Ставим стандарт C++17, который нормально хавает старый код
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PLUGIN_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk")

include_directories(${PLUGIN_SDK_DIR}/shared)
include_directories(${PLUGIN_SDK_DIR}/plugin_sa)
include_directories(${PLUGIN_SDK_DIR}/game_sa)

add_library(AmazingTreasureESP SHARED main.cpp)

set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)
