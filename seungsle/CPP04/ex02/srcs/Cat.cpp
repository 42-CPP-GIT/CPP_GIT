/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:19 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/18 11:03:29 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat", "Meow", "STREET CAT")
{
	std::cout << "[Cat Constructor called]" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string name): Animal("Cat", "Meow", name)
{
	std::cout << "[Cat Constructor called]" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	this->_type = cat.getType();
	this->_sound = cat.getSound();
	this->_name = cat.getName();
	if (this->brain)
		delete this->brain;
	this->brain = cat.brain;
}

Cat:: ~Cat()
{
	std::cout << "[Cat destructor called]" << std::endl;
	if (this->brain)
		delete this->brain;
}

Cat& Cat::operator=(const Cat &source)
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

void Cat::makeSound(void) const
{
	std::cout << this->getType() << "(" << this->getName() << ") is making sound [" << this->getName() << " : "<< this->getSound() << "]" << std::endl;
}

void Cat::grooming(void)
{
	std::cout << this->getType() << "(" << this->getName() << ") : " << "GROOOOOOOOOOOOOMING" << std::endl;
}

void Cat::eatFish(void)
{
	std::cout << this->getType() << "(" << this->getName() << ") : " << "CHUPCHUP FISHGOOD" << std::endl;
}

void Cat::hunt(void)
{
	std::cout << this->getType() << "(" << this->getName() << ") : " << "HUNT MODE .oo." << std::endl;
}
