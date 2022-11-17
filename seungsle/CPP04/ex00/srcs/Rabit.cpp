/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rabit.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:26 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 18:44:49 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Rabit.hpp"

Rabit::Rabit(): WrongAnimal("Rabit", "...", "STREET Rabit")
{
	std::cout << "[Rabit Constructor called]" << std::endl;
}

Rabit::Rabit(std::string name): WrongAnimal("Rabit", "...", name)
{
	std::cout << "[Rabit Constructor called]" << std::endl;
}

Rabit::Rabit(const Rabit &Rabit)
{
	this->_type = Rabit.getType();
	this->_sound = Rabit.getSound();
	this->_name = Rabit.getName();
}

Rabit::~Rabit()
{
	std::cout << "[Rabit destructor called]" << std::endl;
}

Rabit& Rabit::operator=(const Rabit &source)
{
	if (this == &source)
		return (*this);
	this->_type = source.getType();
	this->_sound = source.getSound();
	this->_name = source.getName();
	return (*this);
}


void Rabit::makeSound(void) const
{
	std::cout << this->getType() << "(" << this->getName() << ") is making sound [" << this->getName() << " : "<< this->getSound() << "]" << std::endl;
}

