/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:09 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/22 14:11:18 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _name("Dog")
{
	std::cout << "[Dog Default Constructor Called]\n";
	_type = "Dog";
	this->_brain = new Brain();
}


Dog::Dog(Brain *brain) : _brain(0)
{
	std::cout << "[Dog Default Constructor Called]\n";
	_type = "Dog";
	this->_brain = brain;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "[Dog Copy Constructor Called]\n";
	this->_brain = NULL;
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
	std::cout << "[Dog Destructor Called]\n";
	if (this->_brain)
		delete	this->_brain;
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
