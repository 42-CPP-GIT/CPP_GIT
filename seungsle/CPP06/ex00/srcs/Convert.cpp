/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:22:59 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 22:19:28 by seungsle         ###   ########.fr       */
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
	bool start = false;

	if (!std::isspace(this->_input.at(0)))
		start = true;
	for (size_t i = 0; i < this->_input.length(); i++)
	{
		if (std::isspace(this->_input.at(i)))
		{
			if (i + 1 < this->_input.length() && std::isspace(this->_input.at(i + 1)))
				start = true;
			continue ;
		}
		if (start)
		{
			size_t k = i;
			if (((this->_input.at(k) >= 'a' && this->_input.at(k) <= 'z') || (this->_input.at(k) >= 'A' && this->_input.at(k) <= 'Z')) && this->_input.length() == k + 1)
			{
				this->_literal = this->_input.at(k);
				this->_type = 0;
				return ;
			}
			if (this->_input.at(k) == '-' || this->_input.at(k) == '+')
				k++;
			if (this->_input.at(k) == 'n' && this->_input.at(k + 1) == 'a' && this->_input.at(k + 2) == 'n' && this->_input.length() == k + 3)
			{
				this->_type = 4;
				return ;
			}
			if (this->_input.at(k) == 'i' && this->_input.at(k + 1) == 'n' && this->_input.at(k + 2) == 'f' && this->_input.length() == k + 3)
			{
				this->_type = 5;
				return ;
			}
			if (this->_input.at(k) == 'i' && this->_input.at(k + 1) == 'n' && this->_input.at(k + 2) == 'f' && this->_input.at(k + 3) == 'f' && this->_input.length() == k + 4)
			{
				this->_type = 5;
				return ;
			}
			if (this->_literal == 0)
			{
				if (this->_input.at(i) == '0' && this->_input.length() == i + 1)
				{
					this->_type = 1;
					return ;
				}
				if (this->_input.at(i) == '0' && this->_input.at(i + 1) == 'f' && this->_input.length() == i + 2)
				{
					this->_type = 2;
					return ;
				}
				if (this->_input.at(i) == '0' && this->_input.at(i + 1) == '.' && this->_input.at(i + 2) == 'f' && this->_input.length() == i + 3)
				{
					this->_type = 2;
					return ;
				}
				throw (Convert::UndefinedTypeException());
			}
			else
			{
				for (size_t j = i; j < this->_input.length(); j++)
				{						
					if (!std::isdigit(this->_input.at(j)) && (this->_input.at(j) != 'f') && this->_input.at(j) != '.' && (this->_input.at(i) != '-' && this->_input.at(i) != '+'))
						throw(Convert::UndefinedTypeException());
				}
				int rIdx = 0;
				int i = 0;
				int j = 0;
				for (size_t pos = 0; ; pos += 1)
				{
					pos = this->_input.find('.', pos);
					if (pos == std::string::npos)
						break ;
					rIdx = pos;
					i++;
				}
				std::string a(this->_input.substr(rIdx));
				for (size_t pos = 0; ; pos += 1)
				{
					pos = this->_input.find('f', pos);
					if (pos == std::string::npos)
						break ;
					j++;
				}
				if (i == 1 && j == 0)
				{
					this->_type = 3;
					return ;
				}
				else if (i == 1 && j == 1)
				{
					this->_type = 2;
					return ;
				}
				else if (i == 0 && j == 0)
				{
					this->_type = 1;
					return ;
				}
				else
					throw(Convert::UndefinedTypeException());
			}
		}
	}
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