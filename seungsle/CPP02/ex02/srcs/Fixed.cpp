/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:31:52 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/16 11:43:11 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointNum = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedPointNum)
{
	this->setRawBits(fixedPointNum * (1 << this->_fractionalBits));
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixedPointNum)
{
	this->setRawBits((int)roundf(fixedPointNum * (1 << this->_fractionalBits)));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointNum = Fixed.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &source)
{
	// std::cout << "Copy assignment oprator called" << std::endl;
	if (this == &source) // prevent self-assignment
		return (*this);
	else
		this->_fixedPointNum = source.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator > (const Fixed &source) const
{
	return (this->toFloat() > source.toFloat());
}

bool Fixed::operator < (const Fixed &source) const
{
	return (this->toFloat() < source.toFloat());
}

bool Fixed::operator >= (const Fixed &source) const
{
	return (this->toFloat() >= source.toFloat());
}

bool Fixed::operator <= (const Fixed &source) const
{
	return (this->toFloat() <= source.toFloat());
}

bool Fixed::operator == (const Fixed &source) const
{
	return (this->toFloat() == source.toFloat());
}

bool Fixed::operator != (const Fixed &source) const
{
	return (this->toFloat() != source.toFloat());
}

Fixed Fixed::operator + (const Fixed &source)
{
	return (Fixed(this->toFloat() + source.toFloat()));
}

Fixed Fixed::operator - (const Fixed &source)
{
	return (Fixed(this->toFloat() - source.toFloat()));
}

Fixed Fixed::operator * (const Fixed &source)
{
	return (Fixed(this->toFloat() * source.toFloat()));
}

Fixed Fixed::operator / (const Fixed &source)
{
	return (Fixed(this->toFloat() / source.toFloat()));
}

const Fixed Fixed::operator ++ (int)
{
	Fixed tmp(*this);

	this->_fixedPointNum++;
	return (tmp);
}

Fixed &Fixed::operator ++ (void)
{
	this->_fixedPointNum++;
	return (*this);
}

const Fixed Fixed::operator -- (int)
{
	Fixed tmp(*this);

	this->_fixedPointNum--;
	return (tmp);
}

Fixed &Fixed::operator -- (void)
{
	this->_fixedPointNum--;
	return (*this);
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

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a >= b ? b : a);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a >= b ? b : a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a >= b ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat(); // for example
	return out;
}
