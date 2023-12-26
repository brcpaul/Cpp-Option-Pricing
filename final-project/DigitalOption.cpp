#include "DigitalOption.h"
DigitalOption::DigitalOption(double exp, double strk) : Option(exp), _strike{ strk } {
	if (exp < 0 || strk < 0) {
		std::cout << "Expiry and strike must be nonnegative.";
	}
}