/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:04:22 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/23 15:19:37 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called\n";
	setRawBits(0);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called\n";
	this->setRawBits(num << fracBits);
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called\n";
	this->setRawBits(std::roundf(num * (1 << fracBits)));
}

Fixed	&Fixed::operator=(Fixed const &obj)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		setRawBits(obj.getRawBits());
	return (*this);
}

bool	Fixed::operator>(Fixed const &obj) const
{
	return (this->numVal > obj.numVal);
}

bool	Fixed::operator<(Fixed const &obj) const
{
	return (this->numVal < obj.numVal);
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	return (this->numVal >= obj.numVal);
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	return (this->numVal <= obj.numVal);
}

bool	Fixed::operator==(Fixed const &obj) const
{
	return (this->numVal == obj.numVal);
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (this->numVal != obj.numVal);
}

Fixed	Fixed::operator+(Fixed const &obj) const
{
	Fixed	tmp;
	
	tmp.setRawBits(this->numVal + obj.numVal);
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const &obj) const
{
	Fixed	tmp;

	tmp.setRawBits(this->numVal - obj.numVal);
	return (tmp);
}

Fixed	Fixed::operator*(Fixed const &obj) const
{
	Fixed	tmp;

	tmp.setRawBits(((this->numVal * obj.numVal) >> fracBits));
	return (tmp);
}


Fixed	Fixed::operator/(Fixed const &obj) const
{
	Fixed	tmp;
	
	tmp.setRawBits(((this->numVal << fracBits) / obj.numVal));
	return (tmp);
}

Fixed	Fixed::operator++(int dummy)
{
	static_cast<void>(dummy);
	Fixed	tmp(*this);

	this->numVal += 1;
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	this->numVal += 1;
	return (*this);
}

Fixed	Fixed::operator--(int dummy)
{
	static_cast<void>(dummy);
	Fixed	tmp(*this);

	this->numVal -= 1;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->numVal -= 1;
	return (*this);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a.numVal < b.numVal) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a.numVal > b.numVal) ? a : b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{	
	return ((a.numVal < b.numVal) ? a : b);	
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{	
	return ((a.numVal > b.numVal) ? a : b);		
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
	return (static_cast<float>(numVal) / (1 << fracBits));
}

int		Fixed::toInt( void ) const
{
	return (numVal >> fracBits);
}

void	Fixed::printBit(void) const
{
	std::cout << std::bitset<8>(this->numVal >> 24) << "  ";
	std::cout << std::bitset<8>(this->numVal >> 16) << "  ";
	std::cout << std::bitset<8>(this->numVal >> 8) << "  ";
	std::cout << std::bitset<8>(this->numVal) << "\n";
}

