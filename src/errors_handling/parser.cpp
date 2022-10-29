#include <sstream>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "parser.h"

ParseErrors parse_file(std::string filename, std::vector <double> &data_x, std::vector <double> &data_y)
{
    /*
    Check values in the file line by line.
    Every line should contains 2 values that can be convert to double.
    */
    std::ifstream file(filename);
    std::string line;
    while(std::getline(file, line))
    {
        std::vector <double> coordinates;
        std::stringstream line_stream;
        line_stream << line;
        std::string point;
        while(std::getline(line_stream, point, ' ')) 
        {
            try
            {
                coordinates.push_back(std::stod(point));
            }
            catch (std::invalid_argument){
                return ParseErrors::NOT_A_NUMBER;
            }
        }
        if (coordinates.size() < 2){
            return ParseErrors::NOT_ENOUGH_VALUES_IN_FILE;
        }
        else if (coordinates.size() > 2){
            return ParseErrors::TO_MUCH_VALUES_IN_FILE;
        }
        else 
        {
            data_x.push_back(coordinates[0]);
            data_y.push_back(coordinates[1]);
        }
    }
    return ParseErrors::SUCCESS;
}


ParseErrors parse_arguments(int argc, char **argv, std::string &filename, 
double &x, double &y, std::vector <double> &data_x, std::vector <double> &data_y)
{
    /*
    Check amount of params in cmd.
    Required amount = 4.
    */
    if (argc < 4){
        return ParseErrors::INSUFFICIENT_ARGUMENTS;
    }
    if (argc > 4){
        return ParseErrors::TO_MUCH_ARGUMENTS;
    }

    filename = std::string(argv[1]);

    if (!std::filesystem::exists(filename)) {
        return ParseErrors::DOES_NOT_EXIST;
    }

    try {
        x = std::stod(argv[2]);
        y = std::stod(argv[3]);
    } catch (std::invalid_argument) {
        return ParseErrors::NOT_A_NUMBER;
    }

    return parse_file(filename, data_x, data_y);
}


std::string get_error_name(ParseErrors err_info)
{
    /*
    Description of the errors.
    */
    switch (err_info) 
    {
        case ParseErrors::TO_MUCH_VALUES_IN_FILE:
            return "File contains more than 2 values in one of the lines";
        case ParseErrors::NOT_ENOUGH_VALUES_IN_FILE:
            return "File contains less than 2 values in one of the lines";
        case ParseErrors::DOES_NOT_EXIST:
            return "File doesn't exist";
        case ParseErrors::INSUFFICIENT_ARGUMENTS:
            return "Not enough arguments";
        case ParseErrors::TO_MUCH_ARGUMENTS:
            return "To much arguments";
        case ParseErrors::NOT_A_NUMBER:
            return "Can not convert input argument to double";
        case ParseErrors::SUCCESS:
            return "No error";
    }
    return "Unknown error"; 
}
