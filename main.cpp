#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "src/errors_handling/errors_processing.h"
#include "src/errors_handling/errors_processing.cpp"
#include "src/algo/in_area.h"
#include "src/algo/in_area.cpp"

void cmd(std::string filename, double x, double y, int text){
    std::string command = "python3 ../draw_polygon.py ";
    std::string x_string = std::to_string(x);
    std::string y_string = std::to_string(y);
    std::string text_string = std::to_string(text);
    command += filename + " " + x_string + " " + y_string + " " + text_string;
    // std::cout << command << std::endl;
    system(command.c_str());
}


int main(int argc, char **argv) 
{
    std::string filename;
    double x, y;

    processing(argc, argv, filename, x, y);

    std::vector <double> data_x;
    std::vector <double> data_y;
    double elem, elem2;

    // read file
    std::ifstream file(filename);
    while (file >> elem >> elem2){
        data_x.push_back(elem);
        data_y.push_back(elem2);
    }

    // add 1st point to get loop structure of lines
    data_x.push_back(data_x[0]);
    data_y.push_back(data_y[0]);

    int result = check_edges(data_x, data_y, x, y);    

    std::string text;
    if (result == -1)
    {
        std::cout << "The point (" << x << ", " << y << ") is on the edge of the poly." << std::endl;
    }
    else if (result == 0)
    {
        std::cout << "The point (" << x << ", " << y << ") is inside of the polygon." << std::endl;
    } else 
    {
        std::cout << "The point (" << x << ", " << y << ") is outside the polygon." << std::endl;
    }

    cmd(filename, x, y, result);

    return 0;
}