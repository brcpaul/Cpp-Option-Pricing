#pragma once
#include "VanillaOption.h";
#include "OptionType.h"

class PutOption : public VanillaOption
{
public:
    //CallOption classe constructor
    PutOption(double _expiry, double _strike) : VanillaOption(_expiry, _strike) {}


    /// <summary>
    /// 
    /// </summary>
    enum optionType GetOptionType() const;
    
    /// <summary>
    /// A QUOI CA SERT ?
    /// </summary>
    double valeurStrike = getStrike();

    /// <summary>
    /// Payoff function in order to calculate a double result 
    /// </summary>
    /// <param name="price"> a double </param>
    /// <returns> a double </returns>
    double payoff(double price) const;
    
};
