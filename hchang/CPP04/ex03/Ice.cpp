/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:31:45 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 11:05:11 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice& obj)
{
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "[ice delete]\n";
}

Ice::Ice(std::string const & type)
{
	this->_type = type;
}

std::string const & Ice::getType() const
{
	return (this->_type);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout <<BLE "* shoots an ice bolt at " << target.getName() << " *" RESET<< std::endl;
}
