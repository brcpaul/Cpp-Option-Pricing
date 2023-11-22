#pragma once
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cmath>

class Option {

    private:
    #pragma region attributes
            double expiry;
    #pragma endregion


    public:
        Option(double valeur) : expiry(valeur) {  }


        double getExpiry() {
            return expiry;
        }

        
        virtual bool isAsianOption() {
            return false;
        }
        virtual bool isAmericanOption(){
            return false;
        }


        virtual double payoff(double) const =0; // h(S_t)
        
        virtual double payoffPath(std::vector<double> h) { //h(St1,..., Stm)
            return payoff(h[0]);
        }

};



