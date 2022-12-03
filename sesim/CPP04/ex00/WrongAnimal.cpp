/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:08:50 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 14:08:00 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
	std::cout << "[ WrongAnimal Default Construct Called ]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "[ WrongAnimal Copy Constructor Called ]" << std::endl;
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this == &obj)
		return (*this);
	this->type_ = obj.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[ WrongAnimal Destructor Called ]" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[ WrongAnimal Make Sound Called ]" << std::endl;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->type_);
}
