#include <iostream>
#include "parser.h"
#include "errors_processing.h"
#include "parser.cpp"


int processing(int argc, char **argv, std::string &filename, double &x, double &y){
    auto err_info = parse_arguments(argc, argv, filename, x, y);
    
    if (int(err_info) < 0)
    {
        std::cerr << "Error parsing command line arguments: " << get_error_name(err_info) << std::endl; 
    }
    else
    {
        std::cout << "Successfully parsed command line, filename = " << filename << ", x = " << x << ", y = " << y << std::endl; 
    }

    return 0; 
}