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
    double S0(100), K(101.), T(5), r(0.01), sigma(0.1);
    std::vector<Option*> opt_ptrs;
    opt_ptrs.push_back(new CallOption(T, K));
    opt_ptrs.push_back(new PutOption(T, K));
    opt_ptrs.push_back(new DigitalCallOption(T, K));
    opt_ptrs.push_back(new DigitalPutOption(T, K));
    opt_ptrs.push_back(new AmericanCallOption(T, K));
    opt_ptrs.push_back(new AmericanPutOption(T, K));

    CRRPricer* pricer;

    for (auto& opt_ptr : opt_ptrs) {
        pricer = new CRRPricer(opt_ptr, 5, S0,0.05,-0.045,0.01);

        pricer->compute();

        std::cout << "price: " << (*pricer)() << std::endl << std::endl;
        delete pricer;
        delete opt_ptr;

    }

    system("pause");
}
