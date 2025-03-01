//
// Created by Kunj Shah on 2/19/25.
//

#include "EuropeanCall.h"
#include <cmath>
#include <numbers>

using namespace std;


EuropeanCall::EuropeanCall(double K, double T)
    : Option(K, T)
{}


double EuropeanCall::Price(double S0, double r, double v) {

    double d1_x = d1(S0, r, v);
    double Nd1 = N(d1_x);
    double d2_x = d2(S0, r, v);
    double Nd2 = N(d2_x);

    return S0 * Nd1 - K_*exp(-r*T_) * Nd2;
}

double EuropeanCall::getDelta(double S0, double r, double v) {
    double d1_x = d1(S0, r, v);
    double Nd1 = N(d1_x);
    return Nd1;

}

double EuropeanCall::GetExpirationPayoff(double ST) const {
    return ST-K_;
}






