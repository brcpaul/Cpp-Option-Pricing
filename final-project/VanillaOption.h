#pragma once
#include "Option.h"
#include "OptionType.h"

class VanillaOption : public Option
{

    private:
    #pragma region attributes
        double _strike;
    #pragma endregion

    public:
        /// <summary>
        /// Declare these classes as friends of VanillaOption
        /// </summary>
        friend class CallOption;
        friend class PutOption;
        friend class BlackScholesPricer;

        VanillaOption(double exp, double str) : Option(exp), _strike(str)
        {
            if (exp < 0 || str < 0) {
                throw std::runtime_error("Expiry and strike must be nonnegative.");
            }
        }
    
        virtual optionType GetOptionType() const=0; 
    
        double getStrike() {
            return _strike;
        }
};