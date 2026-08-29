cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

set(CMAKE_CXX_STANDARD 17)

# Ищем папку plugin-sdk, которую только что склонировали
set(PLUGIN_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk")

# Добавляем пути к заголовочным файлам Plugin-SDK
include_directories(${PLUGIN_SDK_DIR}/shared)
include_directories(${PLUGIN_SDK_DIR}/plugin_sa)
include_directories(${PLUGIN_SDK_DIR}/game_sa)

# Создаем динамическую библиотеку (наш будущий .asi)
add_library(AmazingTreasureESP SHARED main.cpp)

# Превращаем .dll в .asi прямо при сборке
set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)
