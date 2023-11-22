#include "PutOption.h";

enum OptionType PutOption::GetOptionType() const
{
    return OptionType::Put;
}

double PutOption::payoff(double price) const
{
    // Implement the payoff calculation for a pull option
    if (valeurStrike >= price)
        return valeurStrike - price;
    else return 0.0;
}