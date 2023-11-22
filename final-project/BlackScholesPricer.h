#pragma once
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "VanillaOption.h"
#include "OptionType.h"


class BlackScholesPricer {
private:
    VanillaOption* option;
    double assetPrice;
    double interestRate;
    double volatility;

public:
    BlackScholesPricer(VanillaOption* option, double assetPrice, double interestRate, double volatility)
        : option(option), assetPrice(assetPrice), interestRate(interestRate), volatility(volatility) {}


    double S = assetPrice;
    double K = option->strike;
    double T = option->getExpiry();
    double r = interestRate;
    double sigma = volatility;

    //fonction de repartition de la loi normale
    double N(double x);

    double operator()();

    double delta()
    
};

