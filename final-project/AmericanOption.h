#pragma once
#include "Option.h"
#include "OptionType.h"

class AmericanOption: public Option
{
public:
    // AmericanOption constructor
    AmericanOption(double expiry, double strike) : Option(expiry) {
    } 

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    bool isAmericanOption() override;

};