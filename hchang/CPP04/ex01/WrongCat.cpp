/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:50:59 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 19:37:38 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : _name("WrongCat")
{
	std::cout << "[WrongCat Default Constructor Called]\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "[WrongCat Copy Constructor Called]\n";
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_type = obj._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat Destructor Called]\n";
}

void	WrongCat::makeSound(void) const
{
	std::cout << "[😻" << this->_name << "(" << this->_type << ")] : " IT<< "야옹 야옹 야야옹 ~\n" RESET;
}

std::string	WrongCat::getName() const
{
	return (this->_name);
}
