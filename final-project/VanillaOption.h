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
        }
    
        virtual OptionType GetOptionType() const=0; //voir redaction enum
    
        //virtual double payoff(double price)=0;

        double GetStrike() {
            return strike;
        }
};