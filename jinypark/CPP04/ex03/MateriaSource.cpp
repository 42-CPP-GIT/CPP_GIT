/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:57:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 03:16:27 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria* m)
{
	static int i = -1;
	if (++i < 4)
		this->slots[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	}
	return (0);
}

MateriaSource::MateriaSource()
{
	#ifdef EVAL
	std::cout << "[MaterialSource] default constructor has been called.\n";
	#endif
}

MateriaSource::~MateriaSource()
{
	#ifdef EVAL
	std::cout << "[MaterialSource] default destructor has been called.\n";
	#endif
	for (int i = 0; i < 4; ++i)
	{
		delete this->slots[i];
	}
}