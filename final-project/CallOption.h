#pragma once
#include "VanillaOption.h"
#include "OptionType.h"

class CallOption : public VanillaOption
{
public:
    CallOption(double _expiry, double _strike) : VanillaOption(_expiry, _strike) {} 

    enum optionType GetOptionType() const override;

    double payoff(double price);
    

};