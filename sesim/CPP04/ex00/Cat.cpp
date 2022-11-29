/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:23:59 by sesim             #+#    #+#             */
/*   Updated: 2022/11/28 15:39:04 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : name_("Cat")
{
	std::cout << "[ Cat Default Constructor Called ]" << std::endl;
}

Cat::Cat(const Cat& obj)
{
	std::cout << "[ Cat Copy Constructor Called ]" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.getName();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "[ " << this->getName() << " : Ya-ong ]" << std::endl;
}

const std::string&	Cat::getName(void) const
{
	return (this->name_);
}

Cat::~Cat()
{
	std::cout << "[ Cat Destructor Called ]" << std::endl;
}
