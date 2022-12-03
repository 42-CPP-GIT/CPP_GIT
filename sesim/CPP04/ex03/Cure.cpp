/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:03 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 20:23:20 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type_ = "cure";
}

Cure::Cure(std::string const & type)
{
	this->type_ = type;
}

Cure::Cure(const Cure& obj)
{
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this == &obj)
		return (*this);
	this->type_ = obj.getType();
	return (*this);
}

std::string const &	Cure::getType() const
{
	return (this->type_);
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Materia Destroyed" << std::endl;
}
