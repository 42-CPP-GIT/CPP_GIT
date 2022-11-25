/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:57:58 by hchang            #+#    #+#             */
/*   Updated: 2022/11/14 20:16:14 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedNum(value << this->_fixedBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf((value * (1 << this->_fixedBits))));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return *this;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return ((float)(this->getRawBits()) / (1 << this->_fixedBits));
}

int Fixed::toInt( void ) const
{
	return (int)(this->_fixedNum >> this->_fixedBits);
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedNum);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedNum = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed Fixed::operator+(const Fixed& fixed)
{
	Fixed res(this->toFloat() + fixed.toFloat());
	return res;
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	Fixed res(this->toFloat() - fixed.toFloat());
	return res;
}

Fixed Fixed::operator*(const Fixed& fixed)
{
	Fixed res(this->toFloat() * fixed.toFloat());
	return res;
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	Fixed res(this->toFloat() / fixed.toFloat());
	return res;
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (!(*this == fixed));
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

Fixed		&Fixed::operator++(void)
{
	this->_fixedNum++;
	return *this;
}

Fixed		&Fixed::operator--(void)
{
	this->_fixedNum--;
	return *this;
}

const Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedNum++;
	return (tmp);
}

const Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedNum--;
	return (tmp);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return (f1 >= f2 ? f1 : f2);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return (f1 >= f2 ? f2 : f1);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return (f1 >= f2 ? f1 : f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return (f1 >= f2 ? f2 : f1);
}
