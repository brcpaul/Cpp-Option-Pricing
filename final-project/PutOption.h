#pragma once
#include "VanillaOption.h";
#include "OptionType.h"

class PutOption : public VanillaOption
{
public:
    PutOption(double _expiry, double _strike) : VanillaOption(_expiry, _strike) {}

    enum optionType GetOptionType() const;

    double payoff(double price);
    
};
