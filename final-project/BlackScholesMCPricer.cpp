#include "BlackScholesMCPricer.h"

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
    }

    //UPDATES the current estimate of the price of the option
    currentEstimate = (numberPaths) / (numberPaths );
}

double BlackScholesMCPricer::operator()()
{
    if (numberPaths == 0) {
        throw std::invalid_argument(" numberPaths doit être différent de 0.");
    }
    return currentEstimate;
}

std::vector<double> BlackScholesMCPricer::confidence_interval()
{
    double lowerBound = (1.96 * (std::sqrt((currentEstimate/ numberPaths) - (currentEstimate / numberPaths) * (currentEstimate / numberPaths)) / std::sqrt(numberPaths))); 
    double upperBound = (1.96 * (std::sqrt((currentEstimate / numberPaths) + (currentEstimate / numberPaths) * (currentEstimate / numberPaths)) / std::sqrt(numberPaths)));
    return { lowerBound, upperBound }; //formule à vérifier !!!
}



