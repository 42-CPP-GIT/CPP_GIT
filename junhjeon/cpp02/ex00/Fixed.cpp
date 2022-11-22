/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:07:36 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/16 16:03:13 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bit = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point_n = 0;
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
		fixed_point_n = f.getRawBits();
	}
	return (*this);
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
