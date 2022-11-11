/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:50:59 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/11 15:36:02 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _name("Cat")
{
	std::cout << "[Cat Default Constructor Called]\n";
	_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& obj)
{
	std::cout << "[Cat Copy Constructor Called]\n";
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_type = obj._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat Destructor Called]\n";
	delete	this->brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "[😻" << this->_name << "(" << this->_type << ")] : " IT<< "야옹 야옹 야야옹 ~\n" RESET;
}

std::string	Cat::getName() const
{
	return (this->_name);
}
