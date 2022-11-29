/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:59:52 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 16:24:34 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "[Animal] default constructor has been called.\n";

	this->type = "Animal";
}

Animal::~Animal(void)
{
	std::cout << "[Animal] destructor has been called.\n";

}

Animal::Animal(const Animal &obj)
{
	std::cout << "[Animal] copy constructor has been called.\n";
	*this = obj;
}

Animal	&Animal::operator=(Animal const &obj)
{
	std::cout << "[Animal] copy assignment operator has been called.\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "animal sound\n";
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

Brain*	Animal::getBrain(void) const
{
	std::cout << "BAD ACCESS!\n";
	std::exit(0);
}

