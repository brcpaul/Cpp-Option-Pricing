#include "BlackScholesMCPricer.h"
#include"BlackScholesPricer.h"
#include "Option.h"
#include "AsianOption.h"
#include "VanillaOption.h"
#include "MT.h"
#include <cmath>


void BlackScholesMCPricer::generate(int nb_paths)
{    
    
    if (option->isAsianOption())
    {
        timeStepsVect = ((AsianOption*)option)->getTimeSteps();
    }
    else
    {
        timeStepsVect; //ici on définit le vecteur time steps d'une option européenne --> juste 2 time steps
    }
    
    
    // calcul de S_t0
    double path = initialPrice;
    double sumPaths = 0;
    // Formule de Black-Scholes pour générer des chemins
    double drift = exp((interestRate - 0.5 * volatility * volatility) * timeStepsVect[0]);
    double diffusion = exp(volatility * sqrt(timeStepsVect[0]) * MT::rand_norm());

    path = path * drift * diffusion;
    
    // Méthode pour générer des chemins
    for (int i = 0; i < nb_paths; ++i) {
        double path = initialPrice;
        // Formule de Black-Scholes pour générer des chemins
        double drift = exp((interestRate - 0.5 * volatility * volatility) * timeStepsVect[i]);
        double diffusion = exp(volatility * sqrt(timeStepsVect[i]) * MT::rand_norm());

        path = path * drift * diffusion;
         
        // Mettre à jour le nombre de chemins générés
        numberPaths++;

        //Somme des valeurs du SJ
        sumPaths += path;
    }

    //Ici on fait la moyenne des prix du SJ
    priceSJ = sumPaths / numberPaths;
}

double BlackScholesMCPricer::operator()()
{
    if (numberPaths == 0) {
        throw std::invalid_argument(" numberPaths doit être différent de 0.");
    }
    //UPDATES the current estimate of the price of the option
    double S = priceSJ;
    double K = ((VanillaOption*)option)->getStrike();
    double T = option->getExpiry();
    double r = interestRate;
    double sigma = volatility;
    double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    if (((VanillaOption*)option)->GetOptionType() == optionType::Call) {
        currentEstimate = S * ((BlackScholesPricer*)option)->N(d1) - K * std::exp(-r * T) * ((BlackScholesPricer*)option)->N(d2);
    }
    else {
        currentEstimate= -S * ((BlackScholesPricer*)option)->N(-d1) + K * std::exp(-r * T) * ((BlackScholesPricer*)option)->N(-d2);
    }
    return currentEstimate;
}

std::vector<double> BlackScholesMCPricer::confidence_interval()
{
    double lowerBound = currentEstimate - 1.96*(volatility / std::sqrt(numberPaths)); 
    double upperBound = currentEstimate + 1.96 * (volatility / std::sqrt(numberPaths)); 
    return { lowerBound, upperBound };
}



