#include "AmericanCallOption.h";
#include "AmericanOption.h"

double AmericanCallOption::payoff(double price) {
    if (price >= _strike) 
        return price - _strike;
    return 0.0;
}