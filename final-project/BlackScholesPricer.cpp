#include "BlackScholesPricer.h"


/// <summary>
/// Method to calculate the distribution of a normal law
/// </summary>
/// <param name="x"> a double </param>
/// <returns> the distribution of a normal law </returns>
double BlackScholesPricer::N(double x)
{
    return 0.5 * (1 + std::erf(x / std::sqrt(2.0)));
}



/// <summary>
/// BlackScholesPricer operator method to calculate the price of the option
/// </summary>
/// <returns> the price of the option </returns>
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


/// <summary>
/// BlackScholesPricer delta method to calculate the Dekta of the option
/// </summary>
/// <returns> the Delta of the option </returns>
double BlackScholesPricer::delta() {
    double S = asset_price;
    double K = option-> _strike;
    double T = option->getExpiry();
    double r = interest_rate;
    double sigma = volatility;

    double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));

    if (option->GetOptionType() == OptionType::Call) {
        return N(d1);
    }
    else {
        return N(d1) - 1;
    }
}



/// <summary>
/// Method to calculate the price of a digital option using the Black-Scholes formula
/// </summary>
/// <param name="digitalOption">A pointer to a digital option object</param>
/// <returns>The calculated price of the digital option</returns>
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