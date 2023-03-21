#pragma once

#include <iostream>
#include <stack>
#include <string>

enum	fourArith
{
	PLUS,
	MINUS,
	MULTI,
	DIVIDE,
};

class RPN
{
	class	CouldNotCalculate : public std::exception
	{
		public :
			const char*	what() const throw();
	};
	private:
		std::stack<int>	_calculator;
		std::string		_argument;
		bool			_flag;

		bool	isValidArgument();
		bool	isfourArith(char c);
		int		switchCalculate(char c);

	public:
		RPN(const char* argv);
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();

		int	cal();
};
