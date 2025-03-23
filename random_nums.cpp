//
// Created by Kunj Shah on 3/23/25.
//

#include "random_nums.h"
#include <iostream>
#include <iomanip>


float random_data(float low, float hi)
{
    float r = (float)rand() / (float)RAND_MAX;
    return low + r * (hi - low);
}

int random_int(int low, int high) {
    return low + (rand() % (high - low));
}

double random_double_step(double low, double high, double step) {
    double x = low + (rand() / (double)RAND_MAX) * (high - low) ;
      return x;

}