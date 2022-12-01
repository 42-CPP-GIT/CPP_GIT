/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:33:43 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 11:06:45 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0)
{
	std::cout << "[MateriaSource Default Constructor called]" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << "[MateriaSource Copy Constructor called]" << std::endl;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this == &obj)
		return (*this);
	this->_idx = obj._idx;
	for (int i = 0; i < obj._idx; i++)
	{
		if (this->_item[i])
			delete _item[i];
		_item[i] = obj._item[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource Destructor called]" << std::endl;
	for (int i = 0; i < _idx; i++)
	{
		if (_item[i])
		{
			delete _item[i];
			_item[i] = 0;
		}
	}
}

void MateriaSource::learnMateria(AMateria* skill)
{
	if (!skill)
		return ;
	if (this->_idx > 3)
	{
		std::cout <<RED "You Already mastered all the skills. You should Level up to learn more skills\n" RESET;
		delete skill;
		return ;
	}
	std::cout << IT "You learn " << skill->getType() << "!!\n" RESET;
	this->_item[_idx] = skill;
	this->_idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->_idx > 3)
		this->_idx = 3;
	if (_idx < 0 || _item[_idx - 1] == 0)
		return (0);
	for (int i = 0; i < _idx; i++)
	{
		if (type == _item[i]->getType())
		{
			std::cout <<IT "you create " << _item[i]->getType() << "!!\n" RESET;
			return (_item[i]);
		}
	}
	std::cout <<RED "There is no skill named " << type << "\n" RESET;
	return (0);
}
