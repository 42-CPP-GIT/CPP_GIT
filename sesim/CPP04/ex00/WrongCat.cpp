/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:23:59 by sesim             #+#    #+#             */
/*   Updated: 2022/11/28 16:48:58 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : name_("WrongCat")
{
	std::cout << "[ WrongCat Default Constructor Called ]" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "[ WrongCat Copy Constructor Called ]" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.getName();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "[ " << this->getName() << " : Ya-ong ]" << std::endl;
}

const std::string&	WrongCat::getName(void) const
{
	return (this->name_);
}

WrongCat::~WrongCat()
{
	std::cout << "[ WrongCat Destructor Called ]" << std::endl;
}
