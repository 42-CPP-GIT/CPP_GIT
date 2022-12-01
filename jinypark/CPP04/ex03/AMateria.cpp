/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:58:58 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 15:33:03 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	#ifdef DEBUG
	std::cout << "[AMateria] default constructor has been called.\n";
	#endif
	this->isEquipped = 0;
}


AMateria::AMateria(std::string const & type)
{
	#ifdef DEBUG
	std::cout << "[AMateria] " + type + " constructor has been called.\n";
	#endif
	this->type_ = type;
	this->isEquipped = 0;
}

AMateria::AMateria(const AMateria &obj)
{
	#ifdef DEBUG
	std::cout << "[AMateria] copy constructor has been called.\n";
	#endif
	*this = obj;
}

AMateria&	AMateria::operator=(AMateria const &obj)
{
	#ifdef DEBUG
	std::cout << "[AMateria] copy assignment operator has been called.\n";
	#endif
	if (this != &obj)
	{
		this->type_ = obj.type_;
		this->isEquipped = 0;
	}
	return (*this);
}


std::string const & AMateria::getType() const
{
	return (this->type_);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName();
}

unsigned int	AMateria::getIsEquipped() const
{
	return (this->isEquipped);
}

void			AMateria::switchIsEquipped(int i)
{
	this->isEquipped = i;
}