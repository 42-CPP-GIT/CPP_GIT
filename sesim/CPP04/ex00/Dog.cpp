/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:23:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 14:06:52 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : name_("Dog")
{
	std::cout << "[ Dog Default Constructor Called ]" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "[ Dog Copy Constructor Called ]" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.getName();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[ " << this->getName() << " : Wal ]" << std::endl;
}

const std::string&	Dog::getName(void) const
{
	return (this->name_);
}

Dog::~Dog()
{
	std::cout << "[ Dog Destructor Called ]" << std::endl;
}
