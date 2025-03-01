//
// Created by Kunj Shah on 2/19/25.
//

#ifndef EUROPEANCALL_H
#define EUROPEANCALL_H
#include "Option.h"



class EuropeanCall : public Option {
  public:
    EuropeanCall(double K, double T);
    double Price(double S0, double r, double v) override;

    double getDelta(double S0, double r, double v) override;
    double GetExpirationPayoff(double ST) const override;


};

#endif //EUROPEANCALL_H
