#pragma once
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "Option.h"
#include "MT.h"
#include <vector>

class BlackScholesMCPricer {
private:
    Option* option;
    double initialPrice;
    double interestRate;
    double volatility;
    int numberPaths; //unsigned pour que ce soit que des valeurs non négatives
    double currentEstimate;

public:
    BlackScholesMCPricer(Option* option, double initialPrice, double interestRate, double volatility)
        : option(option), initialPrice(initialPrice), interestRate(interestRate), volatility(volatility), numberPaths(0), currentEstimate(0.0){}

    int getNbPaths() const { return numberPaths; }

    void generate(int nb_paths);

    double operator()();

    
};
