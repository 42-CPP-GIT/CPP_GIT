/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:49:57 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 18:49:24 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("nothing"),  _sound("can not make sound.."), _name("no name")
{
	std::cout << "[WrongAnimal Constructor called]" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type, std::string sound, std::string name): _type(type), _sound(sound), _name(name)
{
	std::cout << "[WrongAnimal Constructor called]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &Wronganimal)
{
	std::cout << "[WrongAnimal Copy Constructor called]" << std::endl;
	this->_type = Wronganimal.getType();
	this->_sound = Wronganimal.getSound();
	this->_name = Wronganimal.getName();
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal destructor called]" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &source)
{
	std::cout << "[WrongAnimal Copy assignment oprator called]" << std::endl;
	if (this == &source)
		return (*this);
	this->_type = source.getType();
	this->_sound = source.getSound();
	this->_name = source.getName();
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "..........." << std::endl;
}

void WrongAnimal::drinkWater(void) const
{
	std::cout << "i don't have mouth" << std::endl;
}

void WrongAnimal::eatTreat(void) const
{
	std::cout << "i don't have mouth" << std::endl;
}

void WrongAnimal::who(void) const
{
	std::cout << "============WrongAnimal Info============" << std::endl;
	std::cout << "type : " << this->getType() << std::endl;
	std::cout << "name : " << this->getName() << std::endl;
	std::cout << "sound : " << this->getSound() << std::endl;
	std::cout << "====================================" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	return (this->_type);
}

const std::string& WrongAnimal::getSound(void) const
{
	return (this->_sound);
}

const std::string& WrongAnimal::getName(void) const
{
	return (this->_name);
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void WrongAnimal::setSound(std::string sound)
{
	this->_sound = sound;
}

void WrongAnimal::setName(std::string name)
{
	this->_name = name;
}