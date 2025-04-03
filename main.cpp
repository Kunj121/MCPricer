#include <iostream>
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "Option.h"
#include "MCPricer.h"
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    //parameters for call
    double S0 = 100;
    double r = 0.01;
    double v = 0.3;
    double K = 100;
    double T = 2;
    double M[] = {1000000};
    double sizeM = sizeof(M) / sizeof(M[0]);


    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (int i = 0; i < sizeM ; i++) {

        MCPricer mc;
        EuropeanCall call(K,T);
        for (int j = 0; j < M[i] ; j++) {}
        double callPrice = mc.Price(call, S0, v, r, M[i]);
        cout << "At M = "<< M[i] << " MC Call Price: " << callPrice << endl;
        high_resolution_clock::time_point t2 =
        high_resolution_clock::now();
        cout << "Elapsed time: " <<
        duration_cast<milliseconds>(t2 - t1).count() << " ms"<<endl;
        // EuropeanPut put(K,T);
        // double putPrice = mc.Price(put, S0, v, r, M[i]);
        // cout << "At M = "<< M[i] << " MC Put Price: " << putPrice << endl;
    }
}
