/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:19:27 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 14:55:20 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	#ifdef DEBUG
	std::cout << "[Character] default constructor has been called.\n";
	#endif
}

Character::~Character()
{
	#ifdef DEBUG
	std::cout << "[Character] default destructor has been called.\n";
	#endif
}

Character::Character(const std::string type)
{
	#ifdef DEBUG
	std::cout << "[Character] " + type + " constructor has been called.\n";
	#endif
	this->name_ = type;
	this->slotIdx = 0;
}

Character::Character(const Character &obj)
{
	*this = obj;
}

Character&	Character::operator=(Character const &obj)
{
	if (this != &obj)
	{
		this->name_ = obj.name_;
		for (int i = 0; i < 4; ++i)
			if (this->slots[i] != NULL)
				this->slots[i] = obj.slots[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name_);
}

void Character::equip(AMateria* m)
{
	if (this->slotIdx < 4)
		this->slots[this->slotIdx++] = m;
	else
		std::cout << "Slots is full\n";
}

void Character::unequip(int idx)
{
	if (idx < 4)
		this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->slots[idx] && idx < 4)
		this->slots[idx]->use(target);
	else
		std::cout << "Slot is empty.\n";
}