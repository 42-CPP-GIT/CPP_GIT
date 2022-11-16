/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:37:23 by hchang            #+#    #+#             */
/*   Updated: 2022/11/16 17:24:01 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character Constructor called" << std::endl;
}

Character::Character(const Character& obj)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
}

Character::~Character()
{
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	
}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, Character& target)
{
	
}
