/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:19:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/15 23:21:58 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
	std::cout << "[WrongCat] default constructor has been called.\n";
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor has been called.\n";
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "[WrongCat] copy constructor has been called.\n";
	*this = obj;
}

WrongCat	&WrongCat::operator=(WrongCat const &obj)
{
	std::cout << "[WrongCat] copy assignment operator has been called.\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MEOW~\n";
}