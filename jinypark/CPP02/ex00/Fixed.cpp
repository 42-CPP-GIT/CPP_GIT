/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:04:22 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/03 10:48:37 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// const int	Fixed::fracBits = 8;

Fixed::Fixed(/* args */)
{
	std::cout << "Default constructor called\n";
	this->numVal = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed	&Fixed::operator=(Fixed const &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->numVal);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	this->numVal = raw;
}
