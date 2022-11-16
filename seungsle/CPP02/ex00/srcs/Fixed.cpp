/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:31:52 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/16 14:00:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << "Copy assignment oprator called" << std::endl;
	if (this == &source) // prevent self-assignment
		return (*this);
	this->_fixedPointNum = source.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed &Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = Fixed;
	// this->_fixedPointNum = Fixed.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointNum = raw;
}