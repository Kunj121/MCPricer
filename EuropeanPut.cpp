//
// Created by Kunj Shah on 2/19/25.
//

#include "EuropeanPut.h"
#include <cmath>
#include <numbers>

using namespace std;


EuropeanPut::EuropeanPut(double K, double T)
    : Option(K, T)
{}


double EuropeanPut::Price(double S0, double r, double v) {

    double d1_x = d1(S0, r, v);
    double Nd1 = N(-1*d1_x);
    double d2_x = d2(S0, r, v);
    double Nd2 = N(-1*d2_x);

    return K_*exp(-r*T_) * Nd2 -  S0 * Nd1;
}

double EuropeanPut::getDelta(double S0, double r, double v) {
    double d1_x = d1(S0, r, v);
    double Nd1 = N(d1_x)-1;
    return Nd1;

}

double EuropeanPut::GetExpirationPayoff(double ST) const {
    return K_-ST;
}


