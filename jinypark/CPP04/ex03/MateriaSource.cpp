/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:57:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 20:25:23 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

AMateria*	MateriaSource::inventory[INVENTORY_CNT];

static unsigned int	ftGetNum(const std::string& question)
{
	std::string answer;
	std::cout << question;
	std::getline(std::cin, answer);
	if (std::cin.eof())
	{
		std::cout << "ERROR: BAD_ACCESS" << std::endl;
		std::exit(0);
	}
	while (answer.empty())
	{
		std::cout << question;
		std::getline(std::cin, answer);
		if (std::cin.eof())
		{
			std::cout << "ERROR: BAD_ACCESS" << std::endl;
			std::exit(0);
		}
	}
	unsigned int		ret;
	std::stringstream	ss(answer);

	ss >> ret;
	return (ss.fail() ? 0 : ret);
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	for (;this->slots[i] && i < SLOT_CNT; ++i)
		;
	if (i == SLOT_CNT)
	{
		std::cout << "Slot is full!\n" << std::endl;
		return ;
	}
	this->slots[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria* ret = 0;
	for (unsigned int i = 0; i < SLOT_CNT; ++i)
	{
		if (this->slots[i] && this->slots[i]->getType() == type)
		{
			unsigned int j = 0;
			for (;MateriaSource::inventory[j] && j < INVENTORY_CNT; ++j)
				;
			switch (j)
			{
			case 100:
				j = ftGetNum("Inventory is full.\nSelect the index to discard: ");
				delete MateriaSource::inventory[j];
			default:
				ret = this->slots[i]->clone();
				MateriaSource::inventory[j] = ret;
				return (ret);
			}
		}
	}
	return (ret);
}

MateriaSource::MateriaSource()
{
	#ifdef DEBUG
	std::cout << "[MaterialSource] default constructor has been called.\n";
	#endif
	int i = 0;
	for (; i < SLOT_CNT; ++i)
	{
		this->slots[i] = 0;
	}
}

MateriaSource::~MateriaSource()
{
	#ifdef DEBUG
	std::cout << "[MaterialSource] destructor has been called.\n";
	#endif
	int i = 0;
	for (; i < SLOT_CNT; ++i)
	{
		delete this->slots[i];
		delete MateriaSource::inventory[i];
		MateriaSource::inventory[i] = NULL;
		this->slots[i] = NULL;
	}
	for (; i < INVENTORY_CNT; ++i)
	{
		delete MateriaSource::inventory[i];
		MateriaSource::inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete this->slots[i];
			if (obj.slots[i])
				this->slots[i] = obj.slots[i]->clone();
		}
	}
	return (*this);
}

bool	MateriaSource::removeFromInven(AMateria* m)
{
	int i = 0;
	for(; MateriaSource::inventory[i] != m && i < 100; ++i)
		;
	if (i == 100)
		return (false);
	MateriaSource::inventory[i] = NULL;
	return (true);
}

bool	MateriaSource::putInInven(AMateria* m)
{
	int i = 0;
	for(; MateriaSource::inventory[i] != NULL && i < 100; ++i)
		;
	if (i == 100)
	{
		std::cout << "Inventory is full!\n";
		return (false);
	}
	MateriaSource::inventory[i] = m;
	return (true);
}

void	MateriaSource::printSlot(std::string name)
{
	for (int i = 0; i < SLOT_CNT; ++i)
	{
		if (this->slots[i])
			std::cout << name + ": " << i << " " <<this->slots[i]->getType() << "\n";
	}
}
