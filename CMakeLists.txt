cmake_minimum_required(VERSION 3.2)
project(Simple_sieve LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17) 

include_directories(src)

add_executable(main main.cpp)