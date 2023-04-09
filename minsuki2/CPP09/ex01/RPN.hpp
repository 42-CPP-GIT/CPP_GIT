#pragma once
#ifndef RPN_hpp

# include <iostream>
# include <stack>

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
		class NotMatchCount : public std::exception {
			const char*		what(void) const throw();
		};
		class WrongEquation : public std::exception {
			const char*		what(void) const throw();
		};
		class EmptyEquation : public std::exception {
			const char*		what(void) const throw();
		};

	private:
		std::stack<char>			pocket_;
		static const std::string&	operator_symbol_;

		bool		isDigit(char c) const;
		bool		isVaildPocket(void);
};
#endif
