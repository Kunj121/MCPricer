//
// Created by Kunj Shah on 2/24/25.
//

#ifndef MCPRICER_H
#define MCPRICER_H
#include "Option.h"



class MCPricer
{
    public: double Price(const Option& option, double S0, double v, double r,
               unsigned long paths);

};

double BoxMuller();
double max(double a, double b);



#endif //MCPRICER_H
