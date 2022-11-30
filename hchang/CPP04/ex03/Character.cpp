/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:37:23 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 13:48:43 by hchang           ###   ########.fr       */
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
	for (int i = 0; i < obj._slotIdx; i++)
	{
		if (i < this->_slotIdx && _slot[i])
			delete _slot[i];
		_slot[i] = obj.getAMateria(i)->clone();
	}
	this->_name = obj._name;
	this->_slotIdx = obj._slotIdx;
	return (*this);
}

Character::~Character()
{
	std::cout << "["<< this->getName() << "] THE END" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_slot[i])
		{
			delete _slot[i];
			_slot[i] = NULL;
		}
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (_slotIdx > 3)
	{
		std::cout <<RED "No More Skills\n" RESET;
		return ;
	}
	if (m)
	{
		std::cout << "equiped " << _slotIdx << " <- your slot Idx" << std::endl;
		_slot[_slotIdx] = m->clone();
		_slotIdx++;
	}
}

void	Character::unequip(int idx)
{
	if (_slotIdx < 0 || _slot[idx] == 0)
	{
		std::cout << RED << "You can't unequip the slot[" << idx << "] - There is no slot[" << idx << "]" << RESET << std::endl;
		return ;
	}
	if (_floorIdx > 8)
	{
		std::cout << RED << "You can't unequip the slot[" << idx << "] - Floor is Already Full Dirty" << RESET << std::endl;
		_floorIdx = 9;
		return ;
	}
	_floor[_floorIdx] = _slot[idx];
	_slot[idx] = 0;
	std::cout << _floor[_floorIdx]->getType() << " unequip!" << std::endl;
	_slotIdx--;
	_floorIdx++;
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
