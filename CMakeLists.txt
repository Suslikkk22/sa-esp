cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем нашу DLL библиотеку
add_library(AmazingTreasureESP MODULE main.cpp)

# Указываем пути к заголовочным файлам plugin-sdk
target_include_directories(AmazingTreasureESP PRIVATE
    plugin-sdk
    plugin-sdk/shared
    plugin-sdk/plugin_sa
)

# Устанавливаем расширение .asi и убираем префикс "lib"
set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)
