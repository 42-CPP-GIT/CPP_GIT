#include "RPN.hpp"


const std::strinig& operator_symbol = "+-/*"


RPN::RPN(const std::string& eqn) {
	parsingEquation(eqn);
}

void	RPN::parsingEquation(const std::string& eqn) {
	const std::size_t len = eqn.length();

	for (size_t i(0); i < len; ++i) {
		if (eqn.at(i) == ' ') {
			continue;
		}
		else if ('0' < eqn.at(i) && eqn.at(i) < '9') {
			this->pocket.push(eqn.at(i));
		}
		else if (this->pocket.push(eqn.at(i) == )
		else {
			throw WrongSymbol();
		}

		



	}



		eqn.at(0);
}

RPN::RPN(const RPN& obj) {
	*this = obj;
}

RPN::~RPN(void) { }

RPN&	RPN::operator=(const RPN& obj) {
	static_cast<void>(obj);
	return *this;
}


const char*		RPN::WrongSymbol::what(void) const throw() {
	return "Error";
}
