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
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
}

WrongCat::WrongCat(const WrongCat &obj)
{
	*this = obj;
}

WrongCat	&WrongCat::operator=(WrongCat const &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MEOW~\n";
}