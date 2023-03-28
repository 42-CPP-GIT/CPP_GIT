#include "RPN.hpp"

const std::string&	RPN::operator_symbol_("+-/*");

bool	RPN::isVaildPocket(void) {
	const char backup = this->pocket_.top();
	this->pocket_.pop();
	if (!isDigit(this->pocket_.top()))
		return false;
	this->pocket_.push(backup);
	if (!isDigit(this->pocket_.top()))
		return false;
	return true;
}

RPN::RPN(const std::string& eqn) {
	unsigned int	count = 0;
	size_t len(eqn.length());
	char	last = ' ';
	eqn.find_first_of("0123456789" + RPN::operator_symbol_) == std::string::npos ?
												throw EmptyEquation() : false;
	for (; len > 0; --len) {
		if (eqn.at(len - 1) == ' ') {
			continue;
		} else if (isDigit(eqn.at(len - 1))) {
			this->pocket_.push(eqn.at(len - 1)); ++count;
			last = (last == ' ') ? eqn.at(len - 1) : last;
		} else if (RPN::operator_symbol_.find(eqn.at(len - 1)) != std::string::npos) {
			this->pocket_.push(eqn.at(len - 1)); --count;
			last = (last == ' ') ? eqn.at(len - 1) : last;
		} else {
			throw WrongSymbol();
		}
	}
	count == 1 ? true : throw NotMatchCount();
	isVaildPocket() ?  true : throw WrongEquation();
	isDigit(last) ? throw WrongEquation() : false;
}

RPN::RPN(const RPN& obj) { *this = obj; }

RPN::~RPN(void) { }

RPN&	RPN::operator=(const RPN& obj) {
	static_cast<void>(obj);
	return *this;
}


int		RPN::calculate() {
	std::stack<int>	cal; // 중간 과정에서 십진수 이상으로 나옴
	// stackPrint(pocket_);
	int res;
	while (!pocket_.empty()) {
		// std::cout << pocket_.top() << std::endl;
		if (isDigit(pocket_.top())) {
			cal.push(pocket_.top() - '0');
			// stackPrint(cal);
		} else {
			const int x = cal.top(); cal.pop();
			const int y = cal.top(); cal.pop();
			switch (pocket_.top()) {
				case '+':
					res = y + x;
					// std::cerr << "y + x = " << y << " + " << x << " = " << res << "\n\n";
					break;
				case '-':
					res = y - x;
					// std::cerr << "y - x = " << y << " - " << x << " = " << res << "\n\n";
					break;
				case '/':
					res = y / x;
					// std::cerr << "y / x = " << y << " / " << x << " = " << res << "\n\n";
					break;
				case '*':
					res = y * x;
					// std::cerr << "y * x = " << y << " * " << x << " = " << res << "\n\n";
					break;
			}
			cal.push(res);
		}
		pocket_.pop();
	}
	return res;
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
