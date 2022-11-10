/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:04:22 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/10 15:56:38 by jinypark         ###   ########.fr       */
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
	if (this != &obj)
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

bool	Fixed::operator>(Fixed const &obj)
{
	return (this->numVal > obj.numVal);
}

bool	Fixed::operator<(Fixed const &obj)
{
	return (this->numVal < obj.numVal);
}

bool	Fixed::operator>=(Fixed const &obj)
{
	return (this->numVal >= obj.numVal);
}

bool	Fixed::operator<=(Fixed const &obj)
{
	return (this->numVal <= obj.numVal);
}

bool	Fixed::operator==(Fixed const &obj)
{
	return (this->numVal == obj.numVal);
}

bool	Fixed::operator!=(Fixed const &obj)
{
	return (this->numVal != obj.numVal);
}

Fixed	Fixed::operator+(Fixed const &obj)
{
	Fixed	tmp;
	
	tmp.setRawBits(this->numVal + obj.numVal);
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const &obj)
{
	Fixed	tmp;

	tmp.setRawBits(this->numVal - obj.numVal);
	return (tmp);
}

Fixed	Fixed::operator*(Fixed const &obj)
{
	Fixed	tmp;
	
	tmp.setRawBits((this->numVal * obj.numVal) >> fracBits);
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const &obj)
{
	Fixed	tmp;
	
	tmp.setRawBits(this->numVal / obj.numVal);
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

Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	Fixed *pa = const_cast<Fixed *>(&a);  
	Fixed *pb = const_cast<Fixed *>(&b);
	
	return ((pa->numVal < pb->numVal) ? *pa : *pb);	
}

Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	Fixed *pa = const_cast<Fixed *>(&a);  
	Fixed *pb = const_cast<Fixed *>(&b);
	
	return ((pa->numVal > pb->numVal) ? *pa : *pb);		
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
