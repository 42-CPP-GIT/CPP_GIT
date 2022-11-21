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
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	*this = obj;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "wrong animal sound\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

