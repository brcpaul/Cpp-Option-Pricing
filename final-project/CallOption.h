#pragma once
#include "VanillaOption.h"
#include "OptionType.h"

class CallOption : public VanillaOption
{
public:
    CallOption(double expiry, double strike) : VanillaOption(expiry, strike) {} //meme nom de valeur ou non ?

    enum OptionType GetOptionType() const override;
    
    double payoff(double price) const;
    

};