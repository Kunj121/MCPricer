//
// Created by Kunj Shah on 2/19/25.
//

#ifndef OPTION_H
#define OPTION_H



class Option {
  public: Option(double K, double T);

    virtual double Price(double S0, double r, double v) = 0; //if virtual then we would have to use it for call and put both
    //delta can be a virtual functions in the base class
    //each derived class has to provide implementation
    //gamma is the same in call and put and so you can put in the base class

    virtual double getDelta(double S0, double r, double v) =0;

    double getGamma(double S0, double r, double v);

    virtual double GetExpirationPayoff(double ST) const = 0;

    double getTimeToExpiration() const;
    double getStrike() const;



    protected:
      double d1(double S0, double r, double v);

      double d2(double S0, double r, double v);

      double N(double d);

      double K_;
      double T_;


};



#endif //OPTION_H
