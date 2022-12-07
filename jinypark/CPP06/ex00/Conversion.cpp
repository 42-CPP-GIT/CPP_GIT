/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:39:29 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/06 22:30:24 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(const char* str)
{
	if (!str[1] && !std::isdigit(str[0]))
		this->valueDouble_ = (str[0]);
	else
		this->valueDouble_ = std::strtod(str, NULL);
	this->valueChar_ = static_cast<char>(this->valueDouble_);
	this->valueInt_ = static_cast<int>(this->valueDouble_);
	this->valueFloat_ = static_cast<float>(this->valueDouble_);
}

Conversion::~Conversion()
{

}

Conversion::Conversion(const Conversion& obj)
{
	*this = obj;
}

Conversion& Conversion::operator=(const Conversion& obj)
{
	if (this != &obj)
	{
		this->valueChar_ = obj.valueChar_;
		this->valueInt_ = obj.valueInt_;
		this->valueFloat_ = obj.valueFloat_;
		this->valueDouble_ = obj.valueDouble_;
	}
	return (*this);
}

char	Conversion::getChar() const
{
	return (this->valueChar_);
}

int	Conversion::getInt() const
{
	return (this->valueInt_);
}

float	Conversion::getFloat() const
{
	return (this->valueFloat_);
}

double	Conversion::getDouble() const
{
	return (this->valueDouble_);
}


std::ostream& operator<<(std::ostream& os, const Conversion& obj)
{
	if (std::isnan(obj.getDouble()) || std::isinf(obj.getDouble())
		|| obj.getDouble() > 127 || obj.getDouble() < 0)
		std::cout << "char: impossible" << ENDL;
	else if ((0 <= obj.getDouble() && obj.getDouble() < 32) || obj.getDouble() == 127)
		std::cout << "char: Non displayable" << ENDL;
	else
		std::cout << "char: '" << obj.getChar() << "'" << ENDL;

	if (std::isnan(obj.getDouble()) || std::isinf(obj.getDouble()))
		std::cout << "int: impossible" << ENDL;
	else
		std::cout << "int: " << obj.getInt() << ENDL;

	std::cout << "float: " << obj.getFloat();
	if (static_cast<float>(obj.getInt()) == obj.getFloat())
		std::cout << ".0";
	std::cout << "f" << ENDL;
	std::cout << "double: " << obj.getDouble();
	if (static_cast<double>(obj.getInt()) == obj.getDouble())
		std::cout << ".0";
	std::cout << ENDL;
	return (os);
}