/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:42:48 by hchang            #+#    #+#             */
/*   Updated: 2023/08/07 17:01:22 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

RPN::RPN(const char* argv)
: _argument(argv), _isCalculated(false)
{
	if (_argument.empty())
		throw CannotNotCalculate();
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
			throw CannotNotCalculate();
		}
	}
	return true;
}

int	RPN::partCalculate(const char c)
{
	int num1 = _calculator.top();
	_calculator.pop();
	int num2 = _calculator.top();
	_calculator.pop();
	switch (c)
	{
		case '+':
			num2 += num1;
			break;

		case '-':
			num2 -= num1;
			break ;

		case '*':
			num2 *= num1;
			break ;

		case '/':
			if (num1 == 0)
				throw CannotNotCalculate();
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
				throw CannotNotCalculate();
			_calculator.push(_argument.at(i) - '0');
			continue;
		}
		else if (isfourArith(_argument.at(i)))
		{
			if (_calculator.size() < 2)
				throw CannotNotCalculate();
			_calculator.push(partCalculate(_argument.at(i)));
			_isCalculated = true;
		}
	}
	if (_calculator.size() > 1 || !_isCalculated)
		throw CannotNotCalculate();
	return (_calculator.top());
}

const char*	RPN::CannotNotCalculate::what() const throw()
{
	return ("Error");
}
