#pragma once
#include <stdexcept>
#include <iostream>
#include <cmath>

class Option {

private:
    double expiry;


public:
    Option(double valeur) :expiry(valeur) {  }   // Constructor.
    virtual double payoff(double);
    double getExpiry() {
        return expiry;
    }
};



