#pragma once
#include "VanillaOption.h";

class PutOption : public VanillaOption
{
public:
    PutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

    enum OptionType GetOptionType() const
    {
        return OptionType::Put;
    }

    double valeurStrike = GetStrike();
    double payoff(double price) const
    {
        // Implement the payoff calculation for a pull option
        if (valeurStrike >= price)
            return valeurStrike - price;
        else return 0.0;
    }
};
