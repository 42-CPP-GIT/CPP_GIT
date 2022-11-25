/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:50:59 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 19:37:38 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _name("Cat")
{
	std::cout << "[Cat Default Constructor Called]\n";
	_type = "Cat";
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
}

void	Cat::makeSound(void) const
{
	std::cout << "[😻" << this->_name << "(" << this->_type << ")] : " IT<< "야옹 야옹 야야옹 ~\n" RESET;
}

std::string	Cat::getName() const
{
	return (this->_name);
}
