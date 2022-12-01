/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:19:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 16:51:05 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] default constructor has been called.\n";
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor has been called.\n";
	delete this->brain;
}

Cat::Cat(const Cat &obj)
{
	this->brain = NULL;
	std::cout << "[Cat] copy constructor has been called.\n";
	*this = obj;
}

Cat	&Cat::operator=(Cat const &obj)
{
	std::cout << "[Cat] copy assignment operator has been called\n";
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

void	Cat::makeSound(void) const
{
	std::cout << "MEOW~\n";
}

Brain* Cat::getBrain(void) const
{
	return (this->brain);
}
