/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:35:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:27:16 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout <<  _type << " is created" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout <<  _type << " is destructed" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAnimal("temp")
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator = (const WrongCat &d )
{
	std::cout << " =  Constructor" << std::endl;
	if (this != &d)
	{
		;
	}
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "wrong cat sound" << std::endl;
}
