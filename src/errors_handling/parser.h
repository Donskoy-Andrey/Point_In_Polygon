#pragma once
#include <string>

enum class ParseErrors
{
    TO_MUCH_VALUES_IN_FILE = -6,
    NOT_ENOUGH_VALUES_IN_FILE = -5,
    DOES_NOT_EXIST = -4,
    INSUFFICIENT_ARGUMENTS = -3,
    TO_MUCH_ARGUMENTS = -2,
    NOT_A_NUMBER = -1,
    SUCCESS = 0
};

ParseErrors parse_file(std::string filename, std::vector <double> &data_x, std::vector <double> &data_y);

ParseErrors parse_arguments(int argc, char **argv, std::string &filename, 
double &x, double &y, std::vector <double> &data_x, std::vector <double> &data_y);

std::string get_error_name(ParseErrors err_info); 
