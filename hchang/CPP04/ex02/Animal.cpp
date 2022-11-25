/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:44:12 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/18 16:47:08 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "[Animal Default Constructor Called]\n";
}

Animal::Animal(const Animal& obj)
{
	std::cout << "[Animal Copy Constructor Called]\n";
	*this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
	if(this == &obj)
		return (*this);
	this->_type = obj._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal Destructor Called]\n";
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "~That Is the Animal Sound~" << std::endl;
}

void	Animal::noBrain(void)
{
}
