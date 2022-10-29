#include <iostream>
#include <vector>
#include <string>
#include "in_area.h"
#include <cmath>

/*
Unused algorithm with if/else constructions.
*/
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
    /*
    Algorithm to check point in the polygon.
    */
    int result = 0;
    double eps = 1e-5;
    std::vector <double> angles;

    // c{cx = 0, cy = 0, cz = 1} - perpendicular vector to our plane
    double cx = 0, cy = 0, cz = 1;
    double angles_sum = 0;

    for (int i = 0; i < data_x.size() - 1; ++i)
    {
        // set 2 points
        double x1 = data_x[i];
        double x2 = data_x[i+1];
        double y1 = data_y[i];
        double y2 = data_y[i+1];

        // a{ax, ay, az=0} - vector to 1st point
        // b{bx, by, bz=0} - vector to 2nd point
        double ax = x1 - x;
        double ay = y1 - y;
        double az = 0;
        double bx = x2 - x;
        double by = y2 - y;
        double bz = 0;

        // determinant of the mixed product matrix
        double det = ax * by * cz + ay * bz * cx + bx * cy * az -
        az * by * cx - bx * ay * cz - ax * cy * bz;
        int sign = (det >= 0) ? 1 : -1;

        double len_a = std::sqrt(ax*ax + ay*ay);
        double len_b = std::sqrt(bx*bx + by*by);

        // a or b is null-vector
        if ((len_a < eps) or (len_b < eps)) {
            return -1;
        }

        // calculate angel between vectors a and b
        double cos_alpha = (ax*bx + ay*by) / (len_a * len_b);
        double angle = std::acos(cos_alpha);

        angles_sum += sign * angle;

        if (fabs(fabs(angle) - M_PI) < eps) 
            return -1;
    }

    result = !(fabs(fabs(angles_sum) - 2 * M_PI) < eps);
    return result;
}