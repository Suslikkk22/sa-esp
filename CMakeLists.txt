cmake_minimum_required(VERSION 3.25)
project(AmazingTreasureESP CXX)

# Требуем C++23 для поддержки std::expected в safetyhook
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Плагин для GTA SA (.asi)
add_library(AmazingTreasureESP MODULE
    main.cpp
)

# Выходной файл с расширением .asi
set_target_properties(AmazingTreasureESP PROPERTIES
    PREFIX ""
    SUFFIX ".asi"
)

# ОПРЕДЕЛЯЕМ ИГРУ: Задаем макрос GTASA
target_compile_definitions(AmazingTreasureESP PRIVATE GTASA)

# Подключаем все возможные пути plugin-sdk, включая базовые типы и математику
target_include_directories(AmazingTreasureESP PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/shared
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/plugin_sa
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/plugin_sa/game_sa
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/game_sa
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/injector
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/safetyhook
)

# Флаги компилятора для MSVC
if(MSVC)
    target_compile_options(AmazingTreasureESP PRIVATE 
        /W3 
        /Zc:__cplusplus 
        /Zc:preprocessor
    )
endif()
