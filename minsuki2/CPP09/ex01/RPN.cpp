#include "RPN.hpp"

template<typename T>
void stackPrint(T cal) {
	std::cerr << "Top | ";
	while (!cal.empty()) {
		std::cout << '\'' << cal.top() << '\'' << " ↔ ";
		cal.pop();
	}
	std::cerr << "| Bottom " << "\n\n";
}


const std::string&	RPN::operator_symbol_("+-/*");

// bool	RPN::isVaildPocket(void) {
//     const char backup = this->pocket_.top();
//     this->pocket_.pop();
//     if (this->pocket_.size() && !isDigit(this->pocket_.top()))
//         return false;
//     this->pocket_.push(backup);
//     if (!isDigit(this->pocket_.top()))
//         return false;
//     return true;
// }

RPN::RPN(const std::string& eqn) {
	unsigned int	count = 0;
	// char	last = ' ';
	eqn.find_first_of("0123456789" + RPN::operator_symbol_) == std::string::npos
												? throw EmptyEquation() : false;
	for (size_t len(eqn.length()); len > 0; --len) {
		if (eqn.at(len - 1) == ' ') {
			continue;
		} else if (isDigit(eqn.at(len - 1))) {
			this->pocket_.push(eqn.at(len - 1)); ++count;
			// last = (last == ' ') ? eqn.at(len - 1) : last;
		} else if (RPN::operator_symbol_.find(eqn.at(len - 1)) != std::string::npos) {
			this->pocket_.push(eqn.at(len - 1)); --count;
			// last = (last == ' ') ? eqn.at(len - 1) : last;
		} else {
			throw WrongSymbol();
		}
	}
	count == 1 ? true : throw NotMatchCount();
	// isVaildPocket() ?  true : throw WrongEquation();
	// isDigit(last) ? throw WrongEquation() : false;
}

RPN::RPN(const RPN& obj) {
	static_cast<void>(obj);
}

RPN::~RPN(void) { }

RPN&	RPN::operator=(const RPN& obj) {
	static_cast<void>(obj);
	return *this;
}

int		RPN::calculate() {
	std::stack<int>	cal; // stackPrint(pocket_);
	int res;
	while (!pocket_.empty()) {
		if (isDigit(pocket_.top())) {
			res = pocket_.top() - '0';
		} else {
			cal.size() == 2 ? true : throw WrongEquation();
			const int x = cal.top(); cal.pop();
			const int y = cal.top(); cal.pop();
			switch (pocket_.top()) {
				case '+':
					res = y + x; // std::cerr << "y + x = " << y << " + " << x << " = " << res << "\n\n";
					break;
				case '-':
					res = y - x; // std::cerr << "y - x = " << y << " - " << x << " = " << res << "\n\n";
					break;
				case '/':
					x == 0 ? throw std::out_of_range("Error(div)") : false;
					res = y / x; // std::cerr << "y / x = " << y << " / " << x << " = " << res << "\n\n";
					break;
				case '*':
					res = y * x; // std::cerr << "y * x = " << y << " * " << x << " = " << res << "\n\n";
					break;
			}
		}
		cal.push(res); // stackPrint(pocket_);
		pocket_.pop();
	}
	cal.size() != 1 ? throw WrongEquation() : false;
	return cal.top();
}

bool		RPN::isDigit(char c) const { return '0' <= c && c <= '9'; }

const char*		RPN::WrongSymbol::what(void) const throw() {
	return "Error";
}
const char*		RPN::NotMatchCount::what(void) const throw() {
	return "Error(cnt)";
}
const char*		RPN::WrongEquation::what(void) const throw() {
	return "Error(eqn)";
}
const char*		RPN::EmptyEquation::what(void) const throw() {
	return "Error(emt)";
}
