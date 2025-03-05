#include <iostream>
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "Option.h"
#include "MCPricer.h"
#include <vector>

using namespace std;


int main() {
    //parameters for call
    double S0 = 100;
    double r = 0.01;
    double v = 0.3;
    double K = 100;
    double T = 2;
    double M[] = {10000, 100000, 1000000};
    double sizeM = sizeof(M) / sizeof(M[0]);

    for (int i = 0; i < sizeM ; i++) {

        MCPricer mc;
        EuropeanCall call(K,T);
        for (int j = 0; j < M[i] ; j++) {}
        double callPrice = mc.Price(call, S0, v, r, M[i]);
        cout << "At M = "<< M[i] << " MC Call Price: " << callPrice << endl;
        EuropeanPut put(K,T);
        double putPrice = mc.Price(put, S0, v, r, M[i]);
        cout << "At M = "<< M[i] << " MC Put Price: " << putPrice << endl;
    }
}
