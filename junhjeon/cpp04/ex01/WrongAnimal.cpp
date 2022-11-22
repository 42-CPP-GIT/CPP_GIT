/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:27:40 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/18 16:59:57 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "something";
}

WrongAnimal::WrongAnimal( std::string type )
{
	std::cout << "WrongAnimal " << _type << " is created" << std::endl;
	_type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << _type << " is destructed" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy )
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator = ( const WrongAnimal&  a)
{
	std::cout << " =  Constructor" << std::endl;
	if (this != &a)
	{
		this -> _type = a._type;
	}
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "wrongAnimal :: wrong sound" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (_type);
}
