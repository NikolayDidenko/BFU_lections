cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME lecture01_basics) 			 # задать значение PROJECT_NAME		 
project("${PROJECT_NAME}")           # установить имя проекта

set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка

add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" main.cpp)