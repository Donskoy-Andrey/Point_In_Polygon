#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "errors_processing.h"
#include "in_area.h"


void cmd(std::string filename, double x, double y, int text){
    /*
    Run python script to draw polygon.
    */
    std::string command = "python3 ../src/pyscripts/draw_polygon.py ";
    std::string x_string = std::to_string(x);
    std::string y_string = std::to_string(y);
    std::string text_string = std::to_string(text);
    command += filename + " " + x_string + " " + y_string + " " + text_string;
    system(command.c_str());
}


int main(int argc, char **argv) 
{
    std::string filename;
    double x, y;

    std::vector <double> data_x;
    std::vector <double> data_y;

    if (processing(argc, argv, filename, x, y, data_x, data_y) < 0){
        return -1;
    };

    // add 1st point to get loop structure of lines
    data_x.push_back(data_x[0]);
    data_y.push_back(data_y[0]);

    int result = check_edges(data_x, data_y, x, y);    

    // result of checking polygon
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

    // draw
    cmd(filename, x, y, result);

    return 0;
}