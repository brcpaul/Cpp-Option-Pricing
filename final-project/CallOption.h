#pragma once
#include "VanillaOption.h"
#include "OptionType.h"

class CallOption : public VanillaOption
{
public:
    //CallOption classe constructor
    CallOption(double _expiry, double _strike) : VanillaOption(_expiry, _strike) {} 


    /// <summary>
    /// 
    /// </summary>
    enum optionType GetOptionType() const override;
    

    /// <summary>
    /// Payoff function in order to calculate a double result 
    /// </summary>
    /// <param name="price"> a double </param>
    /// <returns> a double </returns>
    double payoff(double price) const;
    

};