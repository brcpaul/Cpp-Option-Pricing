#include "BlackScholesMCPricer.h"

void BlackScholesMCPricer::generate(int nb_paths)
{// Méthode pour générer des chemins
    for (int i = 0; i < nb_paths; ++i) {
        double path = initialPrice;

        // Formule de Black-Scholes pour générer des chemins
        double drift = exp((interestRate - 0.5 * volatility * volatility) * 1.0);
        double diffusion = exp(volatility * sqrt(1.0) * MT::rand_norm());

        path = path * drift * diffusion;

        // Mettre à jour le nombre de chemins générés
        numberPaths++;

        //UPDATES the current estimate of the price of the option
        //méthode existante dans la classe BS Pricer ? TEST
        double optionPrice; //= option->computeOptionPrice(path);
        currentEstimate = ((currentEstimate * numberPaths) + optionPrice) / (numberPaths + 1);
    }
}

double BlackScholesMCPricer::operator()()
{
    if (numberPaths == 0) {
        throw std::runtime_error("Current estimate is undefined. No paths have been generated.");
    }
    return currentEstimate;
}


