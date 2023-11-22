#pragma once
#include "Option.h"
#include "OptionType.h"

class DigitalOption : public Option {
	private :
		double strike;
	public :
		friend class DigitalPutOption;
		friend class DigitalCallOption; 
		DigitalOption(double exp, double strk) : Option(exp),strike{strk}{ //"exp" for expiry and "strk" for strike
			if (exp < 0 || strk < 0) { //a verif
				std::cout << "Expiry and strike must be nonnegative.";
			}
		}
		virtual OptionType GetOptionType() const = 0;
};