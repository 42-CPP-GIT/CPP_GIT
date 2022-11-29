/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:19:27 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 11:49:17 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	#ifdef DEBUG
	std::cout << "[Character] default constructor has been called.\n";
	#endif
	for(int i = 0; i < 4; ++i)
		this->slots[i] = NULL;
}

Character::~Character()
{
	#ifdef DEBUG
	std::cout << "[Character] destructor has been called.\n";
	#endif
	for(int i = 0; i < 4; ++i)
		delete this->slots[i];
}

Character::Character(const std::string type)
{
	#ifdef DEBUG
	std::cout << "[Character] " + type + " constructor has been called.\n";
	#endif
	this->name_ = type;
	for(int i = 0; i < 4; ++i)
		this->slots[i] = NULL;
}

Character::Character(const Character &obj)
{
	#ifdef DEBUG
	std::cout << "[Character] copy constructor has been called.\n";
	#endif
	for(int i = 0; i < 4; ++i)
		this->slots[i] = NULL;
	*this = obj;
}

Character&	Character::operator=(const Character &obj)
{
	#ifdef DEBUG
	std::cout << "[Character] copy assignment operator has been called.\n";
	#endif
	std::cout << "2 hae mot ham\n";
	if (this != &obj)
	{
		this->name_ = obj.name_;
		for (int i = 0; i < 4; ++i)
		{
			delete this->slots[i];
			if (obj.slots[i] != NULL)
				this->slots[i] = obj.slots[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name_);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	if (m->getIsEquipped())
	{
		std::cout << "Someone has already equipped this Materia.\n";
		return ;
	}
	int i = 0;
	for(; this->slots[i] && i < 4; ++i)
		;
	if (i < 4)
	{
		this->slots[i] = m;
		m->switchIsEquipped(ON);
	}
	else
		std::cout << "Slots is full\n";
}

void Character::unequip(int idx)
{
	if (this->slots[idx] && 0 <= idx && idx < 4)
	{
		this->slots[idx]->switchIsEquipped(OFF);
		this->slots[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (this->slots[idx] && 0 < idx && idx < 4)
		this->slots[idx]->use(target);
	else
		std::cout << "Slot is empty.\n";
}