/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:48 by sesim             #+#    #+#             */
/*   Updated: 2022/12/07 14:12:04 by sesim            ###   ########.fr       */
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
	Fixed	res;
	int		to_multiple;
	int		prime(this->getRawBits() & 0b11111111);

	res.fixed_num_ = this->getRawBits() < 0 ? ~(this->getRawBits()) + 1 : this->getRawBits();
	to_multiple = obj.getRawBits() < 0 ? ~(obj.getRawBits()) + 1 : obj.getRawBits();
	res.fixed_num_ = (res.fixed_num_ >> this->fractional_bits_) * to_multiple;
	prime *= to_multiple;
	res.fixed_num_ += (prime >> this->fractional_bits_);
	res.fixed_num_ = (((this->fixed_num_ & 1 << 31) ^ (obj.fixed_num_ & 1 << 31)) == 0) \
						? res.fixed_num_ : ~res.fixed_num_ + 1;
	return (res);
}

Fixed	Fixed::operator/(const Fixed& obj)
{
	if (obj.getRawBits() == 0)
	{
		std::cerr << "err: Divided with zero" << std::endl;
		exit(1);
	}

	Fixed	res;
	int		to_div;
	int		over_val(this->getRawBits() & 0x7f800000);

	res.fixed_num_ = this->getRawBits() < 0 ? ~(this->getRawBits()) + 1 : this->getRawBits();
	to_div = obj.getRawBits() < 0 ? ~(obj.getRawBits()) + 1 : obj.getRawBits();
	res.fixed_num_ = (static_cast<unsigned int>((this->fixed_num_ & 0x7FFFFF) \
						<< this->fractional_bits_) / to_div);
	over_val /= to_div;
	res.fixed_num_ += (over_val << this->fractional_bits_);
	res.fixed_num_ = (((this->fixed_num_ & 1 << 31) ^ (obj.fixed_num_ & 1 << 31)) == 0) \
						? res.fixed_num_ : ~res.fixed_num_ + 1;
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

const Fixed	Fixed::operator++(int a)
{
	Fixed	res(*this);

	if (a != 0)
		this->fixed_num_ += a;
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