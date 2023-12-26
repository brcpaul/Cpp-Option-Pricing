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
        /// Declaration the class declared as a friend class of VanillaOption
        /// </summary>
        friend class CallOption;
        friend class PutOption;
        friend class BlackScholesPricer;


        /// <summary>
        /// Vanilla constructor with the verification of the parameters 
        /// </summary>
        /// <param name="exp"> expiry </param>
        /// <param name="str"> strike </param>
        VanillaOption(double exp, double str) : Option(exp), _strike(str)
        {
            if (exp < 0 || str < 0) {
                throw std::runtime_error("Expiry and strike must be nonnegative.");
            }
        }
    


        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        virtual optionType GetOptionType() const=0; //voir redaction enum : doit-on le supp ? avec le const, juste initialisation ?
    
        //virtual double payoff(double price)=0; //doit-on le supp ?


        /// <summary>
        /// Get function to have the value of the strike
        /// </summary>
        /// <returns> The value of the strike </returns>
        double getStrike() {
            return _strike;
        }
};