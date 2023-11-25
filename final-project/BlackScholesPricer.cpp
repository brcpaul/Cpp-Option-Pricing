#include "BlackScholesPricer.h"

double BlackScholesPricer::N(double x)
{
    return 0.5 * (1 + std::erf(x / std::sqrt(2.0)));
}

double BlackScholesPricer::operator()() {
    double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    if (option->GetOptionType() == OptionType::Call) {
        return S * N(d1) - K * std::exp(-r * T) * N(d2);
    }
    else {
        return -S * N(-d1) + K * std::exp(-r * T) * N(-d2);
    }
}

double BlackScholesPricer::delta() {
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

double BlackScholesPricer::priceDigitalOption(DigitalOption* digitalOption) {
    double d1 = (std::log(S /*/ digitalOption->getStrike()*/) + (r + (std::pow(sigma,2) / 2) * T) / (sigma * std::sqrt(T)));
    double d2 = d1 - sigma * std::sqrt(T);
    if (digitalOption->GetOptionType() == OptionType::Call) {
        return S * N(d1) - K * std::exp(-r * T) * N(d2);
    }
    else {
        //return -S * (1 - N(d1)) + K * std::exp(-r * T) * (1 - N(d2));
        //by symmetry of the standard normal distribution :
        //(1 - N(d)) == N(-d)
        return -S * N(-d1) + K * std::exp(-r * T) * N(-d2); 
    }
    //http://www.timworrall.com/fin-40008/bscholes.pdf for formulas
}