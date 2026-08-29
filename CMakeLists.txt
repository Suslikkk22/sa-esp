cmake_minimum_required(VERSION 3.15)
project(AmazingTreasureESP CXX)

# Жестко требуем C++20, чтобы компилятор понимал современные фичи и не падал на concepts
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ASI плагин собирается как динамическая библиотека (DLL)
add_library(AmazingTreasureESP SHARED
    main.cpp
)

# Меняем расширение с .dll на .asi и убираем префикс "lib"
set_target_properties(AmazingTreasureESP PROPERTIES PREFIX "")
set_target_properties(AmazingTreasureESP PROPERTIES SUFFIX ".asi")

# Подключаем все необходимые внутренние пути Plugin-SDK, чтобы компилятор видел CRGBA.h и прочее
target_include_directories(AmazingTreasureESP PRIVATE
    plugin-sdk
    plugin-sdk/shared
    plugin-sdk/injector
    plugin-sdk/game_sa
)
