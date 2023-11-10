#pragma once
#include "Option.h"
#include "OptionType.h"

class VanillaOption : public Option
{

private:
    double strike;

public:

    friend class BlackScholesPricer;
    VanillaOption(double exp, double str) : Option(exp), strike(str)
    {
        if (exp < 0 || str < 0) {
            std::cout << "Expiry and strike must be nonnegative.";
        }
        strike = str;
    }
    
    virtual OptionType GetOptionType() const; //voir redaction enum
    

    double GetStrike() {
        return strike;
    }
};