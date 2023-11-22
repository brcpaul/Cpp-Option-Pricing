#include "CallOption.h"

enum OptionType CallOption::GetOptionType() const {
    return OptionType::Call;
}

double CallOption::payoff(double price) const
{
    // Implement the payoff calculation for a call option
    if (price >= strike) //price = z
        return price - strike;
    else
        return 0.0;
}