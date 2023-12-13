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
    //timeStepsVect =     
    if (option->isAsianOption())
    {
        timeStepsVect = ((AsianOption*)option)->getTimeSteps();
    }
    else
    {
        //timeStepsVect[timeStepsVect.size()]
        
        timeStepsVect = {0, option->getExpiry()}; //à la place du 1 : maturity à récup de ?
        //ici on définit le vecteur time steps d'une option européenne --> juste 2 time steps
    }
    
    
    
    std::vector<double> lPaths;
    double sumPaths = 0;

    // Méthode pour générer des chemins
    for (int i = 0; i < nb_paths; i++) {
        //de k=1 à n
        // calcul de S_t0
        double path = initialPrice;
        // Formule de Black-Scholes pour générer des chemins
        double drift = exp((interestRate - 0.5 * volatility * volatility) * timeStepsVect[0]); //A VERIFIER
        double diffusion = exp(volatility * sqrt(timeStepsVect[0]) * MT::rand_norm());

        path = path * drift * diffusion;
       

        for (int k = 1; k < timeStepsVect.size(); k++) {

            double path = initialPrice;
            // Formule de Black-Scholes pour générer des chemins
            double drift = exp((interestRate - 0.5 * volatility * volatility) * timeStepsVect[k]);
            double diffusion = exp(volatility * sqrt(timeStepsVect[k]) * MT::rand_norm());

            path = path * drift * diffusion;
        }
               
        lPaths.push_back(path);
        // Mettre à jour le nombre de chemins générés
        numberPaths++;

        //Somme des valeurs du SJ
        sumPaths += path;
    }
    
    //Ici on fait la moyenne des prix du SJ
    priceSJ = sumPaths / numberPaths;
    double sommeCarre = 0.0;
    for (int i = 0; i < nb_paths; ++i) {
        sommeCarre = sommeCarre + lPaths[i]* lPaths[i];
    }
    varEmp = (sommeCarre / nb_paths) - (priceSJ * priceSJ);
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

std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
    double lowerBound = currentEstimate - 1.96 * (sqrt(varEmp) / std::sqrt(numberPaths));
    double upperBound = currentEstimate + 1.96 * (sqrt(varEmp) / std::sqrt(numberPaths));
    return { lowerBound, upperBound };
}



