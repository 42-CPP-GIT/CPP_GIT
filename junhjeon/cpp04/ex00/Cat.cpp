/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:35:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 18:16:01 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout <<  _type << " is created" << std::endl;
}

Cat::~Cat()
{
	std::cout <<  _type << " is destructed" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal("temp")
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

Cat& Cat::operator = (const Cat &d )
{
	std::cout << " =  Constructor" << std::endl;
	if (this != &d)
	{
		;
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << _type << " make sound myaaaaaaa " << std::endl;
}
