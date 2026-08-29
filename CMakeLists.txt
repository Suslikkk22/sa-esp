cmake_minimum_required(VERSION 3.25)
project(AmazingTreasureESP CXX)

# Требуем C++23 для поддержки std::expected в safetyhook
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Плагины для GTA (ASI) собираются как динамические библиотеки
add_library(AmazingTreasureESP MODULE
    main.cpp
)

# Переименовываем библиотеку в .asi расширение вместо .dll
set_target_properties(AmazingTreasureESP PROPERTIES
    PREFIX ""
    SUFFIX ".asi"
)

# Подключаем пути к заголовочным файлам plugin-sdk, shared и safetyhook
target_include_directories(AmazingTreasureESP PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/shared
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/safetyhook
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin-sdk/game_sa
)

# Дополнительные флаги для компилятора MSVC (на Windows)
if(MSVC)
    target_compile_options(AmazingTreasureESP PRIVATE 
        /W3 
        /Zc:__cplusplus 
        /Zc:preprocessor
    )
endif()
