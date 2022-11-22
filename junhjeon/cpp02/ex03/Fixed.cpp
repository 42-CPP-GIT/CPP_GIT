/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:07:36 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/05 21:18:54 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bit = 8;

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	fixed_point_n = 0;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	fixed_point_n = (n * (1 << fractional_bit));
}

Fixed::Fixed(const float n)
{
	//std::cout << "Float constructor called" << std::endl;
	fixed_point_n = static_cast<int>(roundf(n * (1 << fractional_bit)));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
		fixed_point_n = f.fixed_point_n;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}

int		Fixed::getRawBits ( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this -> fixed_point_n);
}

void	Fixed::setRawBits(int const n)
{
	this -> fixed_point_n = n;
}

int	Fixed::toInt() const
{
	int	temp = fixed_point_n;
	return (temp / 256);
}

float Fixed::toFloat() const
{
	float temp = fixed_point_n / 256.;
	return (temp);
}

bool Fixed::operator <(const Fixed& f)
{
	return (this->fixed_point_n < f.fixed_point_n);
}

bool Fixed::operator >(const Fixed& f)
{
	return (this->fixed_point_n > f.fixed_point_n);
}

bool Fixed::operator >=(const Fixed& f)
{
	return (this->fixed_point_n >= f.fixed_point_n);
}

bool Fixed::operator <=(const Fixed& f)
{
	return (this->fixed_point_n <= f.fixed_point_n);
}

bool Fixed::operator ==(const Fixed& f)
{
	return (this->fixed_point_n == f.fixed_point_n);
}

bool Fixed::operator !=(const Fixed& f)
{
	return (this->fixed_point_n != f.fixed_point_n);
}

Fixed	Fixed::operator +(const Fixed& f)
{
	float a = this->fixed_point_n / 256.0;
	float b = f.fixed_point_n / 256.0;
	float c = a + b ;
	return (Fixed(c));
}

Fixed	Fixed::operator -(const Fixed& f)
{
	float a = this->fixed_point_n / 256.0;
	float b = f.fixed_point_n / 256.0;
	float c = a - b ;
	return (Fixed(c));
}

Fixed	Fixed::operator *(const Fixed& f)
{
	float a = this->fixed_point_n / 256.0;
	float b = f.fixed_point_n / 256.0;
	float c = a * b ;
	return (Fixed(c));
}

Fixed	Fixed::operator /(const Fixed& f)
{
	float a = this->fixed_point_n / 256.0;
	float b = f.fixed_point_n / 256.0;
	float c = a / b ;
	return (Fixed(c));
}

Fixed&	Fixed::operator ++( void )
{
	++fixed_point_n;
	return (*this);
}

Fixed&	Fixed::operator --( void )
{
	--fixed_point_n;
	return (*this);
}

Fixed	Fixed::operator ++( int a )
{
	a = 0;
	float f = this->toFloat();
	Fixed temp(f);
	this->fixed_point_n ++;
	return (temp);
}

Fixed	Fixed::operator --( int b )
{
	b = 0;
	float f = this->toFloat();
	Fixed temp(f);
	f--;
	this->fixed_point_n --;
	return (temp);
}

int&	Fixed::min( int& a, int& b )
{
	if (a < b)
		return (a);
	else
		return (b);
}

int&	Fixed::max( int& a, int& b )
{
	if (a > b)
		return (a);
	else
		return (b);
}

const int& Fixed::min( const int& fixed_n1, const int &fixed_n2 )
{
	if (fixed_n1 < fixed_n2)
		return (fixed_n1);
	return (fixed_n2);
}

const int& Fixed::max( const int& fixed_n1, const int &fixed_n2)
{
	if (fixed_n1 > fixed_n2)
		return (fixed_n1);
	return (fixed_n2);
}

float	Fixed::max(Fixed &a, const Fixed& b)
{
	if (a > b)
		return (a.toFloat());
	return (b.toFloat());
}
