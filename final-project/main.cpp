#include <iostream>
#include <vector>
#include "CallOption.h"
#include "PutOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "AmericanCallOption.h"
#include "AmericanPutOption.h"
#include "CRRPricer.h"


int main() {
    double S0(95.), K(100.), T(0.5), r(0.02), sigma(80);
    int N(150);
    double U = exp(sigma * sqrt(T / N)) - 1.0;
    double D = exp(-sigma * sqrt(T / N)) - 1.0;
    double R = exp(r * T / N) - 1.0;
    std::vector<Option*> opt_ptrs;
    opt_ptrs.push_back(new CallOption(T, K));
    opt_ptrs.push_back(new PutOption(T, K));
    //opt_ptrs.push_back(new DigitalCallOption(T, K));
    //opt_ptrs.push_back(new DigitalPutOption(T, K));
    opt_ptrs.push_back(new AmericanCallOption(T, K));
    opt_ptrs.push_back(new AmericanPutOption(T, K));

    CRRPricer* pricer;

    for (auto& opt_ptr : opt_ptrs) {
        pricer = new CRRPricer(opt_ptr, 150, S0, U, D, R);

        pricer->compute();

        std::cout << "price: " << (*pricer)() << std::endl << std::endl;
        delete pricer;
        delete opt_ptr;

    }
    system("pause");
}
