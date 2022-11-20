/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:22:59 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 03:33:35 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert()
{
	
}

Convert::Convert(const char *input): _input(std::string(input)), _literal(std::atof(input))
{
	this->setType();
}

Convert::Convert(const Convert &source)
{
	*this = source;
}

Convert::~Convert()
{
	
}

Convert& Convert::operator=(const Convert &source)
{
	if (this == &source)
		return (*this);
	this->_input = getInput();
	return (*this);
}

void Convert::setType(void)
{
	if (this->_literal == 0)
	{
		if (!this->iterateStinrgCheckDigit(this->_input) && this->_input.length() != 1)
			throw(Convert::UndefinedTypeException());
		else if (this->_input[0] == '0')
			this->_type = 1;
		else
			this->_type = 0;
	}
	else if (this->_input.find('.') != std::string::npos)
	{
		if (this->_input.find("f") != std::string::npos)
			this->_type = 2;
		else
			this->_type = 3;
	}
	else
		this->_type = 1;
}

bool Convert::iterateStinrgCheckDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isspace(str.at(i)))
			continue ;
		if (str.at(i) == '-' || str.at(i) == '+' || str.at(i) == '.')
			return (std::isdigit(str.at(i + 1)));
		if (std::isdigit(str.at(i)))
			return (true);
	}
	return (false);
}

void Convert::toChar(void)
{
	if (this->_literal == static_cast<int>(this->_literal))
	{
		if (this->_literal < 0 || this->_literal > 127)
			std::cout << "char: impossible" << std::endl;
		else if (this->_literal <= 31 || this->_literal == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << "'" << static_cast<char>(this->_literal) << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void Convert::toInt(void)
{
	if (this->_literal <= std::numeric_limits<int>::max() && this->_literal >= std::numeric_limits<int>::min())
		std::cout << "int: " << static_cast<int>(this->_literal) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void Convert::toFloat(void)
{
	std::cout << "float: " << static_cast<float>(this->_literal);
	if (static_cast<int>(this->_literal) == this->_literal)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void Convert::toDouble(void)
{
	std::cout << "double: " << this->_literal;
	if (static_cast<int>(this->_literal) == this->_literal)
		std::cout << ".0";
	std::cout << std::endl;
}

const std::string& Convert::getInput(void) const
{
	return (this->_input);
}

const char *Convert::UndefinedTypeException::what() const throw()
{
	return "undefined type exception";
}