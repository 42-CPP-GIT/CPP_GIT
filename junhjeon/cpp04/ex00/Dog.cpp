/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:35:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 18:16:05 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout <<  _type << " is created" << std::endl;
}

Dog::~Dog()
{
	std::cout <<  _type << " is destructed" << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal("temp")
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

Dog& Dog::operator = (const Dog &d )
{
	std::cout << " =  Constructor" << std::endl;
	if (this != &d)
	{
		;
	}
	return (*this);

}

void	Dog::makeSound( void ) const
{
	std::cout << _type << " make sounds bowwow " << std::endl;
}
