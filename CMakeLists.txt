cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/permissive- /Zc:twoPhase-)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

set(PLUGIN_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk")

# Подключаем только то, что нужно для работы, исключая ломающие компоненты
include_directories(${PLUGIN_SDK_DIR})
include_directories(${PLUGIN_SDK_DIR}/shared)
include_directories(${PLUGIN_SDK_DIR}/plugin_sa)
include_directories(${PLUGIN_SDK_DIR}/game_sa)
include_directories(${PLUGIN_SDK_DIR}/injector)

# Исключаем папку safetyhook из поиска заголовочных файлов, если она там есть
rp_path_remove(${PLUGIN_SDK_DIR}/safetyhook)

add_library(AmazingTreasureESP SHARED main.cpp)

set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)
