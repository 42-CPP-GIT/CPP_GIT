/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:57:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 11:44:43 by jinypark         ###   ########.fr       */
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
	std::cout << ss.fail() << "\n";
	return (ret);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->slotCnt < 4)
		this->slots[this->slotCnt++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria* ret = 0;
	for (unsigned int i = 0; i < slotCnt; ++i)
	{
		if (this->slots[i]->getType() == type)
		{
			unsigned int j = 0;
			for (;MateriaSource::inventory[j] && j < 100; ++j)
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
	this->slotCnt = 0;
	this->inventoryCnt = 0;
	int i = 0;
	for (; i < 4; ++i)
	{
		this->slots[i] = NULL;
	}
	// 	this->inventory[i] = NULL;
	// }
	// for (; i < INVENTORY_CNT; ++i)
	// 	this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	#ifdef DEBUG
	std::cout << "[MaterialSource] destructor has been called.\n";
	#endif
	int i = 0;
	for (; i < 4; ++i)
	{
		delete this->slots[i];
		delete MateriaSource::inventory[i];
	}
	for (; i < INVENTORY_CNT; ++i)
	{
		delete MateriaSource::inventory[i];
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
			this->slots[i] = obj.slots[i];
		this->slotCnt = obj.slotCnt;
	}
	return (*this);
}