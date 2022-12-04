/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:48 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 19:20:59 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixed_num_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw) : fixed_num_(raw << this->fractional_bits_)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(roundf(raw * (1 << this->fractional_bits_))));
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& obj)
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + obj.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed& obj)
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - obj.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed& obj)
{
	Fixed	res(this->toFloat() * obj.toFloat());
	return (res);
}

Fixed	Fixed::operator/(const Fixed& obj)
{
	Fixed	res(this->toFloat() / obj.toFloat());
	return (res);
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (!(*this == obj));
}

bool	Fixed::operator>(const Fixed& obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

Fixed&	Fixed::operator++(void)
{
	this->fixed_num_ += 1;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->fixed_num_ -= 1;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	Fixed	res(*this);

	this->fixed_num_ += 1;
	return (res);
}

const Fixed	Fixed::operator--(int)
{
	Fixed	res(*this);
	
	this->fixed_num_ -= 1;
	return (res);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a.getRawBits() >= b.getRawBits()) ? a : b);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a.getRawBits() <= b.getRawBits()) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a.getRawBits() >= b.getRawBits()) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a.getRawBits() <= b.getRawBits()) ? a : b);
}


float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->fractional_bits_));
}

int	Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->fractional_bits_);
}

int		Fixed::getRawBits(void) const
{
	return (this->fixed_num_);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_num_ = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

// 1331 * 1331 = 6920.16015625
// 6920 / 256 = 27.03125

// 1331 / 256 = 5.19921875
// 27.0318756

// 27.04