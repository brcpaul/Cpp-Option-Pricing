#include "AmericanCallOption.h";
#include "AmericanOption.h"

double AmericanCallOption::payoff(double price) {
    if (price >= _strike) //price = z
        return price - _strike;
    else
        return 0.0;
}