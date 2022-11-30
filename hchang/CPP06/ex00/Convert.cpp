/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:31:43 by hchang            #+#    #+#             */
/*   Updated: 2022/11/30 15:51:05 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

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

bool	Convert::isValidInput(char* input)
{
	if (this->_data.length() == 1 && !(std::isdigit(this->_data.at(0))))
		throw NotPrintableException();
	char	*end;
	double	f = strtod(input, &end);
	if ((isnan(f) || isinf(f)) && isRightForm(end))
	{
		this->_c = 1;
		this->_f = static_cast<float>(f);
		this->_d
	}
	if (end)
		throw NotValidException();
	
	

}

Convert::Convert(char *input)
{
	this->_data = std::string(input);
	isValidInput(input);
}

Convert::Convert(const Convert& obj)
{
	
}

Convert& Convert::operator=(const Convert& obj)
{
	
}

Convert::~Convert()
{
	
}

void	Convert::print() const
{
	std::cout << 
}
