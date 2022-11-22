/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:26:18 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/15 23:21:48 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(/* args */)
{
	this->type = "Dog";
}

Dog::~Dog()
{
}

Dog::Dog(const Dog &obj)
{
	*this = obj;
}

Dog	&Dog::operator=(Dog const &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "WANG...!\n";
}