/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:49:57 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/18 16:45:58 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("nothing"),  _sound("can not make sound.."), _name("no name")
{
	std::cout << "[Animal Constructor called]" << std::endl;
}

Animal::Animal(std::string type, std::string sound, std::string name): _type(type), _sound(sound), _name(name)
{
	std::cout << "[Animal Constructor called]" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "[Animal Copy Constructor called]" << std::endl;
	this->_type = animal.getType();
	this->_sound = animal.getSound();
	this->_name = animal.getName();
}

Animal::~Animal()
{
	std::cout << "[Animal destructor called]" << std::endl;
}

Animal& Animal::operator=(const Animal &source)
{
	std::cout << "[Animal Copy assignment oprator called]" << std::endl;
	if (this == &source)
		return (*this);
	this->_type = source.getType();
	this->_sound = source.getSound();
	this->_name = source.getName();
	return (*this);
}

void Animal::drinkWater(void) const
{
	std::cout << "i don't have mouth" << std::endl;
}

void Animal::eatTreat(void) const
{
	std::cout << "i don't have mouth" << std::endl;
}

void Animal::who(void) const
{
	std::cout << "============Animal Info============" << std::endl;
	std::cout << "type : " << this->getType() << std::endl;
	std::cout << "name : " << this->getName() << std::endl;
	std::cout << "sound : " << this->getSound() << std::endl;
	std::cout << "====================================" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (this->_type);
}

const std::string& Animal::getSound(void) const
{
	return (this->_sound);
}

const std::string& Animal::getName(void) const
{
	return (this->_name);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

void Animal::setSound(std::string sound)
{
	this->_sound = sound;
}

void Animal::setName(std::string name)
{
	this->_name = name;
}