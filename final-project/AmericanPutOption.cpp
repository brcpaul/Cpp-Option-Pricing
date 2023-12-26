#include "AmericanPutOption.h";
#include "AmericanOption.h"

double AmericanPutOption::payoff(double price) {
    if (_strike >= price)
        return _strike - price;
    return 0.0;
}