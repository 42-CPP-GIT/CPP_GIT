/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:09 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/18 16:40:44 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _name("Dog")
{
	std::cout << "[Dog Default Constructor Called]\n";
	_type = "Dog";
	this->_brain = new Brain();
}


Dog::Dog(Brain *brain)
{
	std::cout << "[Dog Default Constructor Called]\n";
	_type = "Dog";
	this->_brain = brain;
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
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*obj._brain);
	return (*this);
}

Dog::~Dog()
{
	delete	this->_brain;
	std::cout << "[Dog Destructor Called]\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "[🐶" << this->_name << "(" << this->_type << ")] : " IT<< "멍멍 멍멍 머멍 ~\n" RESET;
}

void	Dog::noBrain()
{
	_brain->getIdeas();
}

std::string	Dog::getName() const
{
	return (this->_name);
}
