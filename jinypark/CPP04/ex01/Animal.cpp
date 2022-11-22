/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:59:52 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 15:32:22 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
}

Animal::~Animal(void)
{
}

Animal::Animal(const Animal &obj)
{
	*this = obj;
}

Animal	&Animal::operator=(Animal const &obj)
{
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

