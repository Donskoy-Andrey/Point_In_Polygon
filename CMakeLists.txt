cmake_minimum_required(VERSION 3.2)
project(Simple_sieve LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17) 

include_directories(src/algo)
include_directories(src/errors_handling)
include_directories(src/pyscripts)

add_executable(
main main.cpp
src/errors_handling/errors_processing.cpp
src/errors_handling/errors_processing.h
src/errors_handling/parser.cpp
src/errors_handling/parser.h
src/algo/in_area.cpp
src/algo/in_area.h
)