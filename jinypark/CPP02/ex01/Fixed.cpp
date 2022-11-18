/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:04:22 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/18 17:17:06 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	setRawBits(0);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	setRawBits(num << fracBits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	setRawBits(std::roundf(num * (1 << fracBits)));
}

Fixed	&Fixed::operator=(Fixed const &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		setRawBits(obj.getRawBits());
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj)
{
	os << obj.toFloat();
	return (os);
}

int		Fixed::getRawBits( void ) const
{
	return (this->numVal);
}

void	Fixed::setRawBits( int const raw )
{
	this->numVal = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->numVal) / (1 << fracBits));
}

int		Fixed::toInt( void ) const
{
	return (this->numVal >> fracBits);
}
