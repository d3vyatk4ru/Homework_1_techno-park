# Проверка версии Cmake. Если версия cmake ниже, произойдёт выход.
cmake_minimum_required(VERSION 3.16)

# Название проекта
project(Homework_1)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -pedantic -Werror -lgcov --coverage)
add_link_options(--coverage)

set(H_SOURCE_FILES split_logic.h waybill_structure.h get_data_by_user.h)
set(LIB_SOURCE_FILES split_logic.c get_data_by_user.c)

# Создаем статическую библиотеку
add_library(Homework1_lib STATIC ${LIB_SOURCE_FILES} ${H_SOURCE_FILES})

# Создаем исполняемый файл с именем Homework1 из указанных далее исходников
add_executable(main main.c)

target_link_libraries(main Homework1_lib)

# Включаем тестирование
enable_testing()

# Загружаем библиотеку GTest ОБЯЗАТЕЛЬНО
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Создаем исполняемый файл с именем test_program из указанных далее исходников
add_executable(test_program test_split_logic.cpp)

# Линкуем (соединяем) программу с библиотекой
target_link_libraries(test_program ${GTEST_LIBRARIES} pthread Homework1_lib)
