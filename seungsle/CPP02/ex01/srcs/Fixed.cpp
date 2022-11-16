/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:31:52 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/16 14:01:59 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedPointNum)
{
	this->setRawBits(fixedPointNum * (1 << this->_fractionalBits));
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixedPointNum)
{
	this->setRawBits((int)roundf(fixedPointNum * (1 << this->_fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = Fixed;
	// this->_fixedPointNum = Fixed.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << "Copy assignment oprator called" << std::endl;
	if (this == &source) // prevent self-assignment
		return (*this);
	else
		this->_fixedPointNum = source.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointNum = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat(); // for example
	return out;
}