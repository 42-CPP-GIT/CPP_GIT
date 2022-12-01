/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:07:36 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/16 16:04:19 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bit = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point_n = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_n = (n * (1 << fractional_bit));
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_n = static_cast<int>(roundf(n * (1 << fractional_bit)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this -> fixed_point_n);
}

void	Fixed::setRawBits(int const n)
{
	this -> fixed_point_n = (n * (1 << fractional_bit));
}

int	Fixed::toInt() const
{
	int	temp = fixed_point_n;
	return (temp / (1 << fractional_bit));
}

float Fixed::toFloat() const
{
	float temp = fixed_point_n / (1 << fractional_bit);
	return (temp);
}
