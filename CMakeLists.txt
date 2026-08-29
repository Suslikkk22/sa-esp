cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

# Переключаем на C++14, чтобы старый код plugin-sdk корректно компилировался в VS 2022
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(AmazingTreasureESP MODULE main.cpp)

target_include_directories(AmazingTreasureESP PRIVATE
    plugin-sdk
    plugin-sdk/shared
    plugin-sdk/plugin_sa
)

set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)
