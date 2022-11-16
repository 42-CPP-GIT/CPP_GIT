/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:33:43 by hchang            #+#    #+#             */
/*   Updated: 2022/11/16 17:53:14 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(-1)
{
	std::cout << "[MateriaSource Constructor called]\n";
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource Destructor called]\n";
	for (int i = 0; i < getItemIdx(); i++)
		delete _item[i];
}

void MateriaSource::learnMateria(AMateria* skill)
{
	if (this->_idx > 3)
	{
		std::cout << "You Already mastered all the skills. You should Level up to learn more skills\n";
		return ;
	}
	this->_item[getItemIdx()] = skill;
	this->_idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (getItemIdx() < 0)
		return 0;
	for (int i = 0; i < getItemIdx(); i++)
	{
		if (type == _item[i]->getType())
	}
}

int	MateriaSource::getItemIdx(void) const
{
	return (this->_idx);
}
