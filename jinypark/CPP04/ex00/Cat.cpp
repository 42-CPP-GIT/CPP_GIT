/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:19:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/15 23:21:58 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(/* args */)
{
	this->type = "Cat";
}

Cat::~Cat()
{
}

Cat::Cat(const Cat &obj)
{
	*this = obj;
}

Cat	&Cat::operator=(Cat const &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOW~\n";
}