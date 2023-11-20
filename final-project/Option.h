#pragma once
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cmath>

class Option {

    private:
        double expiry;


    public:
        Option(double valeur) :expiry(valeur) {  }   // Constructor.
        double getExpiry() {
            return expiry;
        }
        virtual bool isAsianOption() {
            return false;
        }

        virtual double payoff(double) const =0; // h(S_t)
        
        virtual double payoffPath(std::vector<double> h) { //h(St1,..., Stm)
            return payoff(h[0]);
        }

};



