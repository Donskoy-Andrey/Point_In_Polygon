#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "in_area.h"
#include <cmath>

/*
int check_edges(const std::vector <double> &data_x, const std::vector <double> &data_y, double x, double y){

    int result = 0;
    double eps = 1e-3;
    std::vector <double> previous_x;
    std::vector <double> previous_y;

    for (int i = 0; i < data_x.size() - 1; ++i){
        double x_1 = data_x[i];
        double x_2 = data_x[i+1];
        double y_1 = data_y[i];
        double y_2 = data_y[i+1];
        double diff_x = 0;
        double diff_y = 0; 

        std::cout << "Loop: " << i << std::endl;

        if (
            ((y_1 <= y) and (y <= y_2)) or
            ((y_2 <= y) and (y <= y_1))
        )
        {
            double intersection_x, intersection_y = y; // parallel to ox
            

            double k = (y_1 - y_2) / (x_1 - x_2);
            double b = y_1 - k * x_1;

            intersection_x = (intersection_y - b) / k;
            
            std::cout << "Intersection: " <<  intersection_x << " " << intersection_y << std::endl;

            if (
                ((abs(x - x_1) < eps) and (abs(y - y_1) < eps)) or
                ((abs(x - x_2) < eps) and (abs(y - y_2) < eps))
                )
            {
                result = -1;
                break;
            }
            else if (intersection_x >= x)
            {
                if (previous_x.size() != 0) 
                {
                    double diff_x = abs(previous_x.back() - intersection_x);
                    double diff_y = abs(previous_y.back() - intersection_y);
                    std::cout << "Diff = " << diff_x << ", " << diff_y << std::endl;
                    std::cout << ((diff_x > eps) or (diff_y > eps)) << std::endl;
                }

                if (
                    ((diff_x >= eps) and (diff_y >= eps))
                    or
                    (previous_x.size() == 0)
                    )
                {
                    previous_x.push_back(intersection_x);
                    previous_y.push_back(intersection_y);
                    std::cout << "==== +1" << ", size: " << previous_x.size() << std::endl;
                    ++result;
                }
            }
        }
        
    }
    return result;
}
*/

int check_edges(const std::vector <double> &data_x, const std::vector <double> &data_y, double x, double y)
{
    int result = 0;
    double eps = 1e-5;
    std::vector <double> angles;
    double cx = 0, cy = 0, cz = 1;

    for (int i = 0; i < data_x.size() - 1; ++i)
    {
        double x1 = data_x[i];
        double x2 = data_x[i+1];
        double y1 = data_y[i];
        double y2 = data_y[i+1];

        if (
        ((abs(x - x1) < eps) and (abs(y - y1) < eps)) or
        ((abs(x - x2) < eps) and (abs(y - y2) < eps))
        ) {
            return -1;
        }
        
        double ax = x1 - x;
        double ay = y1 - y;
        double az = 0;
        double bx = x2 - x;
        double by = y2 - y;
        double bz = 0;

        double det = ax * by * cz + ay * bz * cx + bx * cy * az -
        az * by * cx - bx * ay * cz - ax * cy * bz;
        int sign = (det >= 0) ? 1 : -1;

        double len_a = std::sqrt(ax*ax + ay*ay);
        double len_b = std::sqrt(bx*bx + by*by);

        double cos_alpha = (ax*bx + ay*by) / (len_a * len_b);
        // std::cout << "RESULT_COS: " << cos_alpha << std::endl;

        double angle = std::acos(cos_alpha);
        angles.push_back(angle*sign);
    }
    double angles_sum = 0;
    for (int angle = 0; angle < angles.size(); ++angle)
    {
        // std::cout << angles[angle] << std::endl;
        angles_sum += angles[angle];
        if (fabs(fabs(angles[angle]) - M_PI) < eps) 
            return -1;
    }
    // std::cout << "RESULT: " << angles_sum << std::endl; 

    result = !(fabs(fabs(angles_sum) - 2 * M_PI) < eps);
    return result;
}