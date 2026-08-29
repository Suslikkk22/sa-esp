cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP)

set(CMAKE_CXX_STANDARD 17)

# Указываем, что собираем динамическую библиотеку (будущую .asi)
add_library(AmazingTreasureESP SHARED main.cpp)

# Если у тебя есть папка plugin-sdk, подключаем её инклюды
target_include_directories(AmazingTreasureESP PRIVATE plugin-sdk)

# Меняем расширение с .dll на .asi прямо при сборке
set_target_properties(AmazingTreasureESP PROPERTIES
    SUFFIX ".asi"
    PREFIX ""
)
