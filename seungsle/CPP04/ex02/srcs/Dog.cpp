/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:26 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/18 11:03:42 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog", "Whoaph", "STREET Dog")
{
	std::cout << "[Dog Constructor called]" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string name): Animal("Dog", "Whoaph", name)
{
	std::cout << "[Dog Constructor called]" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &Dog)
{
	this->_type = Dog.getType();
	this->_sound = Dog.getSound();
	this->_name = Dog.getName();
	if (this->brain)
		delete this->brain;
	this->brain = Dog.brain;
}

Dog::~Dog()
{
	std::cout << "[Dog destructor called]" << std::endl;
	if (this->brain)
		delete this->brain;
}

Dog& Dog::operator=(const Dog &source)
{
	if (this == &source)
		return (*this);
	this->_type = source.getType();
	this->_sound = source.getSound();
	this->_name = source.getName();
	if (this->brain)
		delete this->brain;
	this->brain = source.brain;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() << "(" << this->getName() << ") is making sound [" << this->getName() << " : "<< this->getSound() << "]" << std::endl;
}


void Dog::playWithBall(void)
{
	std::cout << this->getType() << "(" << this->getName() << ") : " << "HAPPY~~~" << std::endl;
}

void Dog::waggingTail(void)
{
	std::cout << this->getType() << "(" << this->getName() << ") : " << "WAGING! WAGGING!" << std::endl;
}
