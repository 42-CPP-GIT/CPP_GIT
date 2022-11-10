/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:44:12 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 19:28:41 by hojinjang        ###   ########.fr       */
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
	std::cout << "I am very Sorry sir. You should pick any animal you want first!" << std::endl;
}

