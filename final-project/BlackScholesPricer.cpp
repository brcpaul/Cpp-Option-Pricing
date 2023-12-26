#include "BlackScholesPricer.h"
using namespace std;

// Method to calculate the distribution of a normal law
double N(double x)
{
    return 0.5 * (1 + std::erf(x / std::sqrt(2.0)));
}

/// <summary>
/// BlackScholesPricer operator method to calculate the price of the option
/// </summary>
/// <returns> The price of the option </returns>
double BlackScholesPricer::operator()() {
    double S = asset_price;

    double r = interest_rate;
    double sigma = volatility;

    if (vanilla) {
        double K = ((VanillaOption*)option)->_strike;
        double T = ((VanillaOption*)option)->getExpiry();
        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
        double d2 = d1 - sigma * sqrt(T);

        if (((VanillaOption*)option)->GetOptionType() == optionType::Call) {
            return S * N(d1) - K * std::exp(-r * T) * N(d2);
        }
        else {
            return -S * N(-d1) + K * std::exp(-r * T) * N(-d2);
        }
    }
    else {
        double K = ((DigitalOption*)option)->_strike;
        double T = ((DigitalOption*)option)->getExpiry();
        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
        double d2 = d1 - sigma * sqrt(T);
        
        if (((DigitalOption*)option)->GetOptionType() == optionType::Call) {
            return std::exp(-r * T) * N(d2);
        }
        else {
            return std::exp(-r * T) - std::exp(-r * T) * N(d2);
        }
        //http://www.timworrall.com/fin-40008/bscholes.pdf for formulas
    }
}


/// <summary>
/// BlackScholesPricer delta method to calculate the Delta of the option
/// </summary>
/// <returns> the Delta of the option </returns>
double BlackScholesPricer::delta() {
    double S = asset_price;
    double r = interest_rate;
    double sigma = volatility;
    //bool call; //true for call and false for put
    if (vanilla) {
        double K = ((VanillaOption*)option)->_strike;
        double T = option->getExpiry();
        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));

        if (((VanillaOption*)option)->GetOptionType() == optionType::Call) {
            return N(d1);
        }
        else {
            return N(d1) - 1;
        }
    }
    else {
        double K = ((DigitalOption*)option)->_strike;
        double T = ((DigitalOption*)option)->getExpiry();
        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
        double d2 = d1 - sigma * sqrt(T);
        double result = exp(-r * T) * N(d2) / (S * sigma * sqrt(T));
        if (((DigitalOption*)option)->GetOptionType() == optionType::Call) {
            return result;
        }
        else {
            return result - 1;
        }
    }
}