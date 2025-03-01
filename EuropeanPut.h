//
// Created by Kunj Shah on 2/19/25.
//

#ifndef EUROPEANPUT_H
#define EUROPEANPUT_H

#include "Option.h"


class EuropeanPut: public Option{
public:
  EuropeanPut(double K, double T);
  double Price(double S0, double r, double v) override;

  double getDelta(double S0, double r, double v) override;
  double GetExpirationPayoff(double ST) const override;


};






#endif //EUROPEANPUT_H
