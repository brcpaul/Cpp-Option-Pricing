#pragma once
#include "Option.h"


class VanillaOption : public Option
{

private:
    double strike;
    OptionType optionType;

public:
    friend class BlackScholesPricer;
    VanillaOption(double exp, double str) : Option(exp), strike(str)
    {
        if (exp < 0 || str < 0) {
            std::cout << "Expiry and strike must be nonnegative.";
        }
        strike = str;
    }
    enum OptionType GetOptionType() const override { //voir redaction enum
        return optionType;
    }

    double GetStrike() {
        return strike;
    }
};