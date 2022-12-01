/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:27:40 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 18:15:50 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "something";
}

Animal::Animal( std::string type )
{
	std::cout << "Animal " << _type << " is created" << std::endl;
	_type = type;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " is destructed" << std::endl;
}

Animal::Animal( const Animal& copy )
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

Animal& Animal::operator = ( const Animal&  a)
{
	std::cout << " =  Constructor" << std::endl;
	if (this != &a)
	{
		this -> _type = a._type;
	}
	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << "wrong sound" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (_type);
}
