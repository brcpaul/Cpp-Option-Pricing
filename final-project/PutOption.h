#pragma once
#include "VanillaOption.h";
#include "OptionType.h"

class PutOption : public VanillaOption
{
public:
    PutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}

    enum OptionType GetOptionType() const;
    
    double valeurStrike = GetStrike();
    double payoff(double price) const;
    
};
