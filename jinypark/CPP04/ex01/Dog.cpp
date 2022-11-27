/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:19:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 17:41:58 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] default constructor has been called.\n";
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor has been called.\n";
	delete this->brain;
}

Dog::Dog(const Dog &obj)
{
	this->brain = NULL;
	std::cout << "[Dog] copy constructor has been called.\n";
	*this = obj;
}

Dog	&Dog::operator=(Dog const &obj)
{
	std::cout << "[Dog] copy assignment operator has been called\n";
	if (this != &obj)
	{
		if (this->brain)
			delete this->brain;
		this->type = obj.type;
		this->brain = new Brain();
		this->brain->setIdeas(obj.getBrain()->getIdeas());
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "KANG KANG~\n";
}

Brain* Dog::getBrain(void) const
{
	return (this->brain);
}
