/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:20:01 by sesim             #+#    #+#             */
/*   Updated: 2022/12/09 09:11:08 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(std::string name) : name_(name), idx_(0)
{
	std::cout << name << ": Character Created" << std::endl;
	for (int i(0); i < 4; ++i)
		this->slot_[i] = NULL;
}

Character::Character(const Character& obj)
{
	std::cout << obj.getName() << ": Character Copied" << std::endl;
	for (int i(0); i < 4; ++i)
		this->slot_[i] = NULL;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.getName();
	for (int i(0); i < 4; ++i)
	{
		if (this->slot_[i])
		{
			delete this->slot_[i];
			this->slot_[i] = NULL;
		}
		if (obj.slot_[i])
			this->slot_[i] = obj.slot_[i]->clone();
	}
	this->idx_ = obj.idx_;
	return (*this);
}

const AMateria*	Character::getAMateria(int idx) const
{
	if (idx < 0 || idx > this->idx_)
	{
		std::cerr << "Put right Index!" << std::endl;
		return (NULL);
	}
	if (!this->slot_[idx])
	{
		std::cerr << "Slot is Empty!" << std::endl;
		return (NULL);
	}
	return (this->slot_[idx]);
}

std::string const&	Character::getName() const
{
	return (this->name_);
}

void	Character::equip(AMateria* m)
{
	if (this->idx_ > 3)
	{
		std::cerr << "No more inventory" << std::endl;
		delete m;
		return ;
	}
	if (m)
	{
		std::cout << this->getName() << ": equiped " << m->getType() << " in slot " << this->idx_ << std::endl;
		this->slot_[this->idx_++] = m->clone();
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong Index" << std::endl;
		return ;
	}
	else if (this->idx_ == 0 || slot_[idx] == 0)
	{
		std::cout << "Slot is already Empty" << std::endl;
		return ;
	}
	if (MateriaSource::putInFloor(this->slot_[idx]))
	{
		slot_[idx] = NULL;
		int	max(this->idx_ - (this->idx_ > 3));
		for (int i(idx); i < max - 1; ++i)
		{
			if (slot_[i + 1])
			{
				slot_[i] = slot_[i + 1]->clone();
				delete slot_[i + 1];
				slot_[i + 1] = NULL;
			}
		}
	}
	else
		std::cerr << "You can't unequip now!" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->idx_ < idx)
	{
		std::cerr << "Wrong Index" << std::endl;
		return ;
	}
	else if (this->idx_ == 0 || this->slot_[idx] == 0)
	{
		std::cerr << "Slot is Empty" << std::endl;
		return ;
	}
	std::cout << this->getName() << ": use " << this->slot_[idx]->getType() << std::endl;
	this->slot_[idx]->use(target);
}

Character::~Character()
{
	std::cout << this->name_ << ": is now vanished" << std::endl;
	for (int i(0); i < 4; ++i)
	{
		if (this->slot_[i])
			delete this->slot_[i];
		this->slot_[i] = NULL;
	}
}