cmake_minimum_required(VERSION 3.2)
project(Simple_sieve LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17) 

add_executable(errors errors_processing.cpp errors_processing.h parser.cpp parser.h)
