/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:57:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 16:51:05 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->slotCnt < 4)
		this->slots[this->slotCnt] = m;
	++this->slotCnt;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (unsigned int i = 0; i < slotCnt; ++i)
	{
		if (this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	}
	return (0);
}

MateriaSource::MateriaSource()
{
	#ifdef DEBUG
	std::cout << "[MaterialSource] default constructor has been called.\n";
	#endif
	this->slotCnt = 0;
	for (int i = 0; i < 4; ++i)
		slots[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	#ifdef DEBUG
	std::cout << "[MaterialSource] destructor has been called.\n";
	#endif
	for (int i = 0; i < 4; ++i)
	{
		delete this->slots[i];
	}
}