#include "AmericanCallOption.h";
#include "Option.h"

double AmericanCallOption::payoff(double price) {
    return 0.0;
    /*
    if (price >= getStrike()) //price = z
        return price - getStrike();
    else
        return 0.0;
        */

}