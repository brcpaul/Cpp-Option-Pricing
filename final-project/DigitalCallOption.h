#pragma once
#include "DigitalOption.h"
#include "OptionType.h"

class DigitalCallOption : public DigitalOption {
private:
	DigitalOption* dOption;
public:
	DigitalCallOption(double exp, double strk) : DigitalOption(exp, strk){}
	enum OptionType GetOptionType() const override;
	double payoff(double) const;
};