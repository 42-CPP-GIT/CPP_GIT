/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:33:43 by hchang            #+#    #+#             */
/*   Updated: 2022/11/18 14:41:11 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0)
{
	std::cout << "[MateriaSource Constructor called]\n";
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource Destructor called]\n";
	for (int i = 0; i <= _idx; i++)
		delete _item[i];
}

void MateriaSource::learnMateria(AMateria* skill)
{
	if (this->_idx > 3)
	{
		std::cout << "You Already mastered all the skills. You should Level up to learn more skills\n";
		delete skill;
		return ;
	}
	this->_item[_idx] = skill;
	this->_idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->_idx > 3)
		this->_idx = 3;
	if (_idx < 0 || _item[_idx] == 0)
		return (0);
	for (int i = 0; i <= _idx; i++)
	{
		if (type == _item[i]->getType())
		{
			std::cout << "you create " << _item[i]->getType() << "!!\n";
			return (_item[i]);
		}
	}
	std::cout << "There is no skill named " << type << "\n";
	return (0);
}
