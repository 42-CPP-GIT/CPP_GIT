/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:31:45 by hchang            #+#    #+#             */
/*   Updated: 2022/11/21 22:12:20 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cure(std::string const & type);
// std::string const & getType() const;
// virtual AMateria* clone() const;

#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure& obj)
{
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "[cure delete]\n";
}

Cure::Cure(std::string const & type)
{
	this->_type = type;
}

std::string const & Cure::getType() const
{
	return (this->_type);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout <<GRN "* heals " << target.getName() << "'s wounds *" RESET<< std::endl;
}
// 일단 가자