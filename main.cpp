#include <iostream>
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "Option.h"
#include "MCPricer.h"
#include <vector>
#include <fstream>
#include <chrono>
#include "random_nums.h"
using namespace std;
using namespace std::chrono;



int main() {
    //Open file
    ofstream outputFile("results.txt"); // opens file

    //Number of iterations
    int iter = 1000000;

    //chrono to see time
    high_resolution_clock::time_point t1 = high_resolution_clock::now();


    for (int i = 0; i <= iter ; i++) {
        //parameters for call
        double S0 = random_int(20,100);
        double r = random_data(0.01,0.05);
        double v = random_double_step(0.1, 1, 0.1);
        double K = S0 + random_int(-10, 10);
        double T = random_double_step(0.5, 3, 0.5);
        EuropeanCall call(K,T);
        double callPrice =  call.Price(S0, v, r);
        outputFile << "Call Price: " << callPrice << endl;
    }

    high_resolution_clock::time_point t2 =
    high_resolution_clock::now();
    cout << "Elapsed time: " <<
    duration_cast<milliseconds>(t2 - t1).count() << " ms"<<endl;

    outputFile.close();

    cout<<"Done"<<endl;
}



//Below code was for monte carlo pricer

// double M[] = {10000, 100000, 1000000};
// double sizeM = sizeof(M) / sizeof(M[0]);
//
// for (int i = 0; i < sizeM ; i++) {
//
//     MCPricer mc;
//     EuropeanCall call(K,T);
//     for (int j = 0; j < M[i] ; j++) {}
//     double callPrice = mc.Price(call, S0, v, r, M[i]);
//     cout << "At M = "<< M[i] << " MC Call Price: " << callPrice << endl;
//     EuropeanPut put(K,T);
//     double putPrice = mc.Price(put, S0, v, r, M[i]);
//     cout << "At M = "<< M[i] << " MC Put Price: " << putPrice << endl;
// }


