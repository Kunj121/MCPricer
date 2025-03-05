//
// Created by Kunj Shah on 2/24/25.
//
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "MCPricer.h"
#include <random>
using namespace std;

double MCPricer::Price(const Option& option, double S0, double v, double r, unsigned long paths)


  {
  srand(static_cast<unsigned int>(time(0)));
  double T = option.getTimeToExpiration();
  // double K = option.getStrike();

  double summed = 0;
  for (unsigned int i = 0; i < paths; i++)
    {
    double z_i = normal_dist_generator(0,1);
    double ST_i = S0*exp((r-(pow(v,2))/2.0)*T + v*z_i*sqrt(T));
    double payoff = option.GetExpirationPayoff(ST_i);
    summed += max(payoff, 0);
    }
  double numerator = exp(-r*T);
  double denom = paths;
  double mc = (numerator/denom) * summed;
  return mc;
  }


double BoxMuller() {
    double x  = static_cast<double>(rand()) / RAND_MAX;
    double y  = static_cast<double>(rand()) / RAND_MAX;
    return sqrt(-2.0 * log(x)) * cos(2.0 * M_PI * y);
}
double max(double a, double b) {
  if (a > b){
    return a;
    }
  else {
      return b;
    }
}

default_random_engine generator(time(0));
double normal_dist_generator(double mean, double std) {

  normal_distribution<double> distribution(mean, std);

    return distribution(generator);
}

