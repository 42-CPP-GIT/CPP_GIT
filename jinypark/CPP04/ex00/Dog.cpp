/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:26:18 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 16:44:31 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] default constructor has been called.\n";
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor has been called.\n";
}

Dog::Dog(const Dog &obj)
{
	std::cout << "[Dog] copy constructor has been called.\n";
	*this = obj;
}

Dog	&Dog::operator=(Dog const &obj)
{
	std::cout << "[Dog] copy assignment operator has been called.\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "WANG...!\n";
}