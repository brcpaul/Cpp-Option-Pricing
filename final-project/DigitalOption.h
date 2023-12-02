#pragma once
#include "Option.h"
#include "OptionType.h"

class DigitalOption : public Option {
	private :
		double _strike;
	public :
		friend class DigitalPutOption;
		friend class DigitalCallOption; 
		friend class BlackScholesPricer;
		DigitalOption(double exp, double strk) : Option(exp),_strike{strk}{ //"exp" for expiry and "strk" for strike
			if (exp < 0 || strk < 0) { //a verif
				std::cout << "Expiry and strike must be nonnegative.";
			}
		}
		virtual optionType GetOptionType() const = 0;
		double getStrike() { return _strike; }
};