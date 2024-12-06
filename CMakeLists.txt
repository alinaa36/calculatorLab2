# Мінімальна версія CMake
cmake_minimum_required(VERSION 3.10)

# Ім'я проекту
project(calculator_project)

# Вказати джерела бібліотеки
set(LIBRARY_SOURCES src/calculator.cpp)
set(MAIN_SOURCES src/main.cpp)

# Включити директорії
include_directories(include)

# Створення статичної бібліотеки
add_library(calculator STATIC ${LIBRARY_SOURCES})

# Створення виконуваного файлу
add_executable(calculator_exec ${MAIN_SOURCES})

# Лінкування бібліотеки з виконуваним файлом
target_link_libraries(calculator_exec calculator)
