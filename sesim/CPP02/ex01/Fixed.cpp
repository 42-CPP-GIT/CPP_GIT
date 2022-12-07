/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:48 by sesim             #+#    #+#             */
/*   Updated: 2022/12/06 15:40:05 by sesim            ###   ########.fr       */
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
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return (*this);
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

// 01111111 10100000

// 5.25 -> 101 | 01
// 101.0 * 2^0 
// 1.01 * 2^2 -> 01111111 + 0000010
// 127 + 2 -> 129
// 10000001

// 0 1000000 10100000000000
// 5.25 -> 5

// 32
// 00000000 00000000 00000000 | 00000000

