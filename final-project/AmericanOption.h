#pragma once
#include "Option.h"
#include "OptionType.h"

class AmericanOption: public Option
{
private: 
    double _strike;
public:
    // AmericanOption constructor
    friend class AmericanCallOption;
    friend class AmericanPutOption;

    AmericanOption(double expiry, double strike) : Option(expiry), _strike(strike) {
    } 

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    bool isAmericanOption() override;

};