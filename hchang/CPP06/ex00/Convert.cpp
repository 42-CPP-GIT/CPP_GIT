/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:31:43 by hchang            #+#    #+#             */
/*   Updated: 2022/11/30 18:30:20 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <cmath>

// 	0 : non displayable
// 	1 : char && int impossible double float NAN or INF
// 	2 : char && int && float impossible double printable

const char*	Convert::NotPrintableException::what() const throw()
{
	return ("ERROR : This Character is not printable");
}

const char*	Convert::NotValidException::what() const throw()
{
	return ("ERROR : Input is not valid");
}

bool	isRightForm(char *end)
{
	std::string	checker(end);

	if (checker.length() == 0 || (checker.length() == 1 && checker == "f"))
		return (true);
	return (false);
}
// '-'
// '/"'
// is_alpha()
void	Convert::isValidInput(char* input)
{
	if (this->_data.length() == 1 && !(std::isdigit(this->_data.at(0))))
		throw NotPrintableException();
	char	*end;
	double	val = strtod(input, &end);

	if ((isnan(val) || isinf(val)) && isRightForm(end))
	{
		this->_c = 1;
		this->_f = static_cast<float>(val);
		this->_d = val;
		return ;
	}
	if (end && !isRightForm(end))
		throw NotValidException();
	if (this->_data.find(".") != std::string::npos && val > __FLT_MAX__)
	{
		this->_c = 2;
		this->_d = val;
		return ;
	}
	if (val > INT_MAX || val < INT_MIN)
	{
		this->_c = 1;
		this->_f = static_cast<float>(val);
		this->_d = val;
		return ;
	}
	if (val > 126 || val < 32)
	{
		this->_c = 0;
		this->_i = static_cast<int>(val);
		this->_f = static_cast<float>(val);
		this->_d = val;
		return ;
	}
	this->_c = static_cast<char>(val);
	this->_i = static_cast<int>(val);
	this->_f = static_cast<float>(val);
	this->_d = val;
}

Convert::Convert(char *input) : _data(std::string(input))
{
	isValidInput(input);
}

Convert::Convert(const Convert& obj)
{
	*this = obj;
}

Convert& Convert::operator=(const Convert& obj)
{
	if (this == &obj)
		return (*this);
	this->_c = obj._c;
	this->_i = obj._i;
	this->_f = obj._f;
	this->_d = obj._d;
	this->_data = obj._data;
	return (*this);
}

Convert::~Convert()
{
}

void	Convert::print() const
{
	if (this->_c == 0)
	{
		std::cout << "char: Non displayable\n";
		std::cout << "int: " << this->_i << "\n";
		std::cout << "float: " << this->_f;
		if (fabs(this->_f - static_cast<float>(this->_i)) < std::numeric_limits<float>::epsilon())
			std::cout << ".0f\n";
		else
			std::cout << "f\n";
		std::cout << "double: " << this->_d;
		if (abs(this->_d - static_cast<double>(this->_i)) < std::numeric_limits<double>::epsilon())
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (this->_c == 1)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << this->_f << "f\n";
		std::cout << "double: " << this->_d << std::endl;
	}
	else if (this->_c == 2)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: " << this->_d << std::endl;
	}
	else
	{
		std::cout << "char: '" << this->_c << "'\n";
		std::cout << "int: " << this->_i << "\n";
		std::cout << "float: " << this->_f;
		if (this->_i == this->_f)
			std::cout << ".0f\n";
		else
			std::cout << "f\n";
		std::cout << "double: " << this->_d;
		if (this->_i == this->_d)
			std::cout << ".0";
		std::cout << std::endl;
	}
}
