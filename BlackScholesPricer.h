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
    double N(double x)
    {
        return 0.5 * (1 + std::erf(x / std::sqrt(2.0)));
    }

    double operator()() {



        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
        double d2 = d1 - sigma * sqrt(T);

        if (option->GetOptionType() == OptionType::Call) {
            return S * N(d1) - K * std::exp(-r * T) * N(d2);
        }
        else {
            return -S * N(-d1) + K * std::exp(-r * T) * N(-d2);
        }
    }

    double delta() {
        double S = assetPrice;
        double K = option->strike;
        double T = option->getExpiry();
        double r = interestRate;
        double sigma = volatility;

        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));

        if (option->GetOptionType() == OptionType::Call) {
            return N(d1);
        }
        else {
            return N(d1) - 1;
        }
    }
};

