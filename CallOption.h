#pragma once
#include "VanillaOption.h"
#include "OptionType.h"

class CallOption : public VanillaOption
{
public:
    CallOption(double expiry, double strike) : VanillaOption(expiry, strike) {} //meme nom de valeur ou non ?

    enum OptionType GetOptionType() const override {
        return OptionType::Call;
    }

    double valeurStrike = GetStrike(); //poser question prof pour accessibilité de strike et expiry
    double payoff(double price) const
    {
        // Implement the payoff calculation for a call option
        if (price >= valeurStrike) //price = z
            return price - valeurStrike;
        else
            return 0.0;
    }

};