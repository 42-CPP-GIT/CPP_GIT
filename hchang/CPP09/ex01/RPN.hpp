#pragma once

#include <iostream>
#include <stack>
#include <string>

class RPN
{
	class	CannotNotCalculate : public std::exception
	{
		public :
			const char*	what() const throw();
	};
	private:
		std::stack<int>	_calculator;
		std::string		_argument;
		bool			_isCalculated;

		bool	isValidArgument();
		bool	isfourArith(const char c);
		int		partCalculate(const char c);

	public:
		RPN(const char* argv);
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();

		int	cal();
};
