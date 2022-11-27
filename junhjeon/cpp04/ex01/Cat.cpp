/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:35:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 19:27:02 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout <<  _type << " is created" << std::endl;
	_attribute = new Brain();
}

Cat::~Cat()
{
	std::cout <<  _type << " is destructed" << std::endl;
	delete _attribute;
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
		this -> _attribute = new Brain();
		*(_attribute) = *(d._attribute);
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << _type << " make sound myaaaaaaa " << std::endl;
}

Brain*	Cat::getBrain( void ) const
{
	return (_attribute);
}
