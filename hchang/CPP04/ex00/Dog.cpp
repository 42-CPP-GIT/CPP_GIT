/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:09 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 19:40:46 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _name("Dog")
{
	std::cout << "[Dog Default Constructor Called]\n";
	_type = "Dog";
}

Dog::Dog(const Dog& obj)
{
	std::cout << "[Dog Copy Constructor Called]\n";
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_type = obj._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog Destructor Called]\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "[🐶" << this->_name << "(" << this->_type << ")] : " IT<< "멍멍 멍멍 머멍 ~\n" RESET;
}

std::string	Dog::getName() const
{
	return (this->_name);
}
