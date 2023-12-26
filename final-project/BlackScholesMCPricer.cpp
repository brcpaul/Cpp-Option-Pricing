#include "BlackScholesMCPricer.h"
#include"BlackScholesPricer.h"
#include "Option.h"
#include "AsianOption.h"
#include "VanillaOption.h"
#include "MT.h"
#include <cmath>
#include <vector>


void BlackScholesMCPricer::generate(int nb_paths)
{    
    if (option->isAsianOption())
    {
        timeStepsVect = ((AsianOption*)option)->getTimeSteps();
    }
    else
    {
        timeStepsVect = {option->getExpiry()}; 
        //ici on définit le vecteur time steps d'une option avec seulement 1 time steps (européenne par exemple.)
    }
    
    
    double avgPrice = 0;
    double payoff = 0;

    // Méthode pour générer des chemins
    for (int i = 0; i < nb_paths; ++i) {
        double pathPrice = initialPrice;
        std::vector<double> prices;
        pathPrice = pathPrice * exp((interestRate - 0.5 * volatility * volatility)*timeStepsVect[0] + volatility*sqrt(timeStepsVect[0])*MT::rand_norm());
        prices.push_back(pathPrice);
        for (int k = 1; k < timeStepsVect.size(); k++) {
            // Formule de Black-Scholes pour générer des chemins
            double drift = exp((interestRate - 0.5 * volatility * volatility) * (timeStepsVect[k] - timeStepsVect[k - 1]));
            double diffusion = exp(volatility * sqrt(timeStepsVect[k] - timeStepsVect[k - 1]) * MT::rand_norm());

            pathPrice = pathPrice * drift * diffusion;
            prices.push_back(pathPrice);
        }

        payoff = option->payoffPath(prices);
        sumPayoffs += payoff;
        sumPayoffsSquared += payoff * payoff;
    }

    numberPaths += nb_paths;

    double price = exp(-interestRate * option->getExpiry())*1/numberPaths*sumPayoffs;
    
    empVar = sumPayoffsSquared/numberPaths - pow(sumPayoffs / numberPaths, 2);
    empVar = empVar * numberPaths / (numberPaths - 1);

    finalPrice = price;
}

double BlackScholesMCPricer::operator()()
{
    if (numberPaths == 0) {
        throw std::runtime_error("NumberPaths doit être différent de 0.");
    }
    return finalPrice;
}

std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
    double lowerBound = exp(-interestRate * option->getExpiry()) * (sumPayoffs / numberPaths - 1.96 * (sqrt(empVar) / std::sqrt(numberPaths)));
    double upperBound = exp(-interestRate * option->getExpiry()) * (sumPayoffs / numberPaths + 1.96 * (sqrt(empVar) / std::sqrt(numberPaths)));
    return { lowerBound, upperBound };
}



