#pragma once
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cmath>

class Option {

    private:
    #pragma region attributes
            double _expiry;
    #pragma endregion


    public:

        //Constructor of the abstract class Option
        Option(double value) : _expiry(value) {  }

        /// <summary>
        /// Get function to have the value of the expiry
        /// </summary>
        /// <returns> The value of the expiry </returns>
        double getExpiry() {
            return _expiry;
        }


        /// <summary>
        /// Boolean function to initialize the type of the chosen Option.
        /// At the beginning the Option is not an asian option.
        /// </summary>
        /// <returns> A boolean </returns>
        virtual bool isAsianOption() {
            return false;
        }

        /// <summary>
        /// Boolean function to initialize the type of the chosen Option.
        /// At the beginning the Option is not an american option.
        /// </summary>
        /// <returns> A boolean </returns>
        virtual bool isAmericanOption(){
            return false;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name=""></param>
        /// <returns></returns>
        virtual double payoff(double) const =0; // h(S_t)
        
        /// <summary>
        /// Payoff method to calculate the payoff of the function h in the first element
        /// </summary>
        /// <param name="h"> vector double </param>
        /// <returns> The payoff of the function h in the first element </returns>
        virtual double payoffPath(std::vector<double> h) { //h(St1,..., Stm)
            return payoff(h[0]);
        }

};
