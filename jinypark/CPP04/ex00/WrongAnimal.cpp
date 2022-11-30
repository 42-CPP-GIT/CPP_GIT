/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:59:52 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/15 23:22:05 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	std::cout << "[WrongAnimal] default constructor has been called.\n";
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destructor has been called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "[WrongAnimal] copy constructor has been called.\n";
	*this = obj;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &obj)
{
	std::cout << "[WrongAnimal] copy assignment operator has been called.\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "wronganimal sound\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

