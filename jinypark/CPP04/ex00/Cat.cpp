/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:19:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 16:43:28 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] default constructor has been called.\n";
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor has been called.\n";
}

Cat::Cat(const Cat &obj)
{
	std::cout << "[Cat] copy constructor has been called.\n";
	*this = obj;
}

Cat	&Cat::operator=(Cat const &obj)
{
	std::cout << "[Cat] copy assignment operator has been called.\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Nyang~\n";
}