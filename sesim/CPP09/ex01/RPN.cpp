#include "RPN.hpp"
#include <cctype>

const char*	RPN::CouldNotCalculate::what() const throw()
{
	return ("Error");
}

bool	RPN::isfourArith(const char c)
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
: _argument(argv), _can_calculate_flag(false)
{
	if (_argument.empty())
		throw CouldNotCalculate();
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

int	RPN::switchCalculate(const char c)
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
			if (num1 == 0)
				throw CouldNotCalculate();
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
			if (i < _argument.length() - 1 && std::isdigit(static_cast<int>(_argument.at(i + 1))))
				throw CouldNotCalculate();
			_calculator.push(_argument.at(i) - 48);
			continue;
		}
		else if (isfourArith(_argument.at(i)))
		{
			if (_calculator.size() < 2)
				throw CouldNotCalculate();
			_calculator.push(switchCalculate(_argument.at(i)));
			_can_calculate_flag = true;
		}
	}
	if (_calculator.size() > 1 || !_can_calculate_flag)
		throw CouldNotCalculate();
	return (_calculator.top());
}
