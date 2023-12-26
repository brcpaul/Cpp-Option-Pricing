#pragma once
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "Option.h"
#include "MT.h"
#include "AsianOption.h"
#include "VanillaOption.h"
#include "BlackScholesPricer.h"
#include <vector>

class BlackScholesMCPricer {
private:
    Option* option;
    double initialPrice;
    double interestRate;
    double volatility;
    int numberPaths = 0;
    double priceSJ = 0;
    double sumPayoffs = 0;
    double sumPayoffsSquared = 0;
    double empVar = 0; //variance empirique
    std::vector<double> timeStepsVect;
    double finalPrice = 0;

public:
    BlackScholesMCPricer(Option* option, double initialPrice, double interestRate, double volatility)
        : option(option), initialPrice(initialPrice), interestRate(interestRate), volatility(volatility) {}

    int getNbPaths() const { return numberPaths; }

    void generate(int nb_paths);
     
    double operator()();

    std::vector<double> confidenceInterval();

    
};
