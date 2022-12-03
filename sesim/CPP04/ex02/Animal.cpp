/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:08:50 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 14:47:33 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("Animal")
{
	std::cout << "[ Animal Default Construct Called ]" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	std::cout << "[ Animal Copy Constructor Called ]" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
	if (this == &obj)
		return (*this);
	this->type_ = obj.getType();
	return (*this);
}

const std::string&	Animal::getType(void) const
{
	return (this->type_);
}

void	Animal::getIdeas(void) const
{
	std::cout << "Animal has no ideas" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[ Animal Destructor Called ]" << std::endl;
}
