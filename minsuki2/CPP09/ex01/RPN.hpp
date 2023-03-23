#pragma once

#include <iostream>
#include <stack>

class RPN {
	public:
		RPN(const std::string& eqn);
		RPN(const RPN& obj);
		~RPN(void);

		RPN&	operator=(const RPN& obj);

		int		calculate(void);

		class WrongSymbol : public std::exception {
			const char*		what(void) const throw();
		};

	private:
		std::stack<char>	pocket;
		static const std::string& operator_symbol;

		void	parsingEquation(const std::string& eqn);
};

