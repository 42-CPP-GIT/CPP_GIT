#include "RPN.hpp"
#include <cctype>

const char*	RPN::CouldNotCalculate::what() const throw()
{
	return ("Error");
}

bool	RPN::isfourArith(char c)
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return false;
	return true;
}

bool	RPN::isValidArgument()
{
	for (size_t i = 0; i < _argument.length(); i++)
	{
		if (_argument.at(i) != ' ' 
			&& !std::isdigit(static_cast<int>(_argument.at(i))) 
			&& !isfourArith(_argument.at(i)))
		{
			throw CouldNotCalculate();
		}
	}
	return true;
}


RPN::RPN(const char* argv)
: _argument(argv)
{
	
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN&	RPN::operator=(const RPN& other)
{
	this->_calculator = other._calculator;
	this->_argument = other._argument;
	return (*this);
}

RPN::~RPN()
{
}

int	RPN::switchCalculate(char c)
{
	int num1;
	int num2;
	switch (c)
	{
		case '+':
			num1 = _calculator.top();
			_calculator.pop();
			num2 = _calculator.top();
			_calculator.pop();
			num2 += num1;
			break;

		case '-':
			num1 = _calculator.top();
			_calculator.pop();
			num2 = _calculator.top();
			_calculator.pop();
			num2 -= num1;
			break ;

		case '*':
			num1 = _calculator.top();
			_calculator.pop();
			num2 = _calculator.top();
			_calculator.pop();
			num2 *= num1;
			break ;

		case '/':
			num1 = _calculator.top();
			_calculator.pop();
			num2 = _calculator.top();
			_calculator.pop();
			num2 /= num1;
	}
	return (num2);
}

int	RPN::cal()
{
	for (size_t i = 0; i < _argument.length(); i++)
	{
		if (_argument.at(i) == ' ')
			continue;
		else if (std::isdigit(static_cast<int>(_argument.at(i))))
		{
			_calculator.push(_argument.at(i) - 48);
			continue;
		}
		else if (isfourArith(_argument.at(i)))
		{
			if (_calculator.size() < 2)
				throw CouldNotCalculate();
			_calculator.push(switchCalculate(_argument.at(i)));
		}
	}
	return (_calculator.top());
}
