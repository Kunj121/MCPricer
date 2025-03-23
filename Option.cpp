//
// Created by Kunj Shah on 2/19/25.
//

#include "Option.h"
#include <cmath>
#include <numbers>
using namespace std;


Option::Option(double K, double T)
    : K_(K), T_(T)
{}

double Option::d1(double S0, double r, double v) {
    double e_value = std::numbers::e;

    double d1 = log((S0*exp(r*T_)) / K_) / (v* sqrt(T_)) + (v * sqrt(T_))/2;
    return d1;

}

double Option::d2(double S0, double r, double v) {
    double e_value = std::numbers::e;

    double d2 = log((S0*exp(r*T_)) / K_) / (v* sqrt(T_)) - (v * sqrt(T_))/2;
    return d2;

}

double Option::N(double d) {
    return 0.5* (1 + erf(d/ sqrt(2)));
}

double Option::getGamma(double S0, double r, double v) {

    double d1_x = d1(S0, r, v);
    double pi_value = numbers::pi;

    double gamma = ((1/sqrt(2 * pi_value)) * exp((-pow(d1_x,2))/2)) / (S0 * v * sqrt(T_)) ;
    return gamma;
}


double Option::getTimeToExpiration() const {
    return T_;
}

double Option::getStrike() const {
    return K_;
}

