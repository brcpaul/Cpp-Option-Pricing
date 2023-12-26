#pragma once
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cmath>

class Option {

private:
#pragma region attributes
    double _expiry;
#pragma endregion


public:
    //Constructor of the abstract class Option
    Option(double expiry) : _expiry(expiry) {  }

    // Get function to have the value of the expiry
    double getExpiry() {
        return _expiry;
    }

    // Boolean that describes the type of the Option.
    virtual bool isAsianOption() {
        return false;
    }

    // Boolean that describes the type of the Option.
    virtual bool isAmericanOption() {
        return false;
    }

    // Payoff method to calculate the payoff of the function h in the first element
    virtual double payoff(double) = 0;

    virtual double payoffPath(std::vector<double> h) { return payoff(h.back()); }

};
