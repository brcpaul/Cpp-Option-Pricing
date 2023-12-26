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
		DigitalOption(double exp, double strk);
		virtual optionType GetOptionType() const = 0;
};