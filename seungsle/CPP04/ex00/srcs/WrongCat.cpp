/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:26 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/18 16:19:51 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat", "...", "STREET WrongCat")
{
	std::cout << "[WrongCat Constructor called]" << std::endl;
}

WrongCat::WrongCat(std::string name): WrongAnimal("WrongCat", "...", name)
{
	std::cout << "[WrongCat Constructor called]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat)
{
	this->_type = WrongCat.getType();
	this->_sound = WrongCat.getSound();
	this->_name = WrongCat.getName();
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat destructor called]" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &source)
{
	if (this == &source)
		return (*this);
	this->_type = source.getType();
	this->_sound = source.getSound();
	this->_name = source.getName();
	return (*this);
}


void WrongCat::makeSound(void) const
{
	std::cout << this->getType() << "(" << this->getName() << ") is making sound [" << this->getName() << " : "<< this->getSound() << "]" << std::endl;
}

