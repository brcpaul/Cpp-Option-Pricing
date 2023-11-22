#include "CallOption.h"

enum OptionType CallOption::GetOptionType() const {
    return OptionType::Call;
}

double CallOption::payoff(double price) const
{
    // Implement the payoff calculation for a call option
    if (price >= valeurStrike) //price = z
        return price - valeurStrike;
    else
        return 0.0;
}