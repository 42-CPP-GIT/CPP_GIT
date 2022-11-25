/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:37:23 by hchang            #+#    #+#             */
/*   Updated: 2022/11/22 14:23:17 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

const AMateria* Character::getAMateria(int idx) const
{
	return (_slot[idx]);
}

Character::Character(std::string name) : _name(name), _slotIdx(0)
{
	std::cout << "[Character Constructor called]" << std::endl;
	for (int i = 0; i < 4; i++)
		_slot[i] = 0;
}

Character::Character(const Character& obj)
{
	std::cout << "[Character Copy Constructor called]" << std::endl;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	std::cout << "[Character copy Assignmet called]" << std::endl;
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_slotIdx = obj._slotIdx;
	for (int i = 0; i < obj._slotIdx; i++)
	{
		if (_slot[i])
			delete _slot[i];
		_slot[i] = obj.getAMateria(i)->clone();
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "["<< this->getName() << "] THE END" << std::endl;
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	std::cout << "equiped " << _slotIdx << " <- your slot Idx" << std::endl;
	if (_slotIdx > 3)
	{
		std::cout <<RED "NO More skills\n" RESET;
		return ;
	}
	_slot[_slotIdx] = m;
	_slotIdx++;
}

void	Character::unequip(int idx)
{
	if (_slotIdx < 0)
		return ;
	else if (_slot[idx] == 0)
		return ;
	_slot[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (_slotIdx < 0 || _slotIdx < idx || _slot[idx] == 0)
	{
		std::cout << RED"Your slot [" << idx << "] is empty!\n" RESET;
		return ;
	}
	std::cout << "[" <<  this->getName() << "] use " << _slot[idx]->getType() << "!\n";
	_slot[idx]->use(target);
}
