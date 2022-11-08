/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:27:37 by hchang            #+#    #+#             */
/*   Updated: 2022/11/08 15:57:10 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_fixedNum;
	static const int	_fixedBits = 8;
public:
	Fixed();
	Fixed(const int fixed);
	Fixed(const float fixed);
	Fixed(const Fixed &fixed);
	Fixed&	operator=(const Fixed& fixed);
	Fixed	operator+(const Fixed& fixed) const;
	Fixed	operator-(const Fixed& fixed) const;
	Fixed	operator*(const Fixed& fixed) const;
	Fixed	operator/(const Fixed& fixed) const;
	bool	operator==(const Fixed& fixed) const;
	bool	operator!=(const Fixed& fixed) const;
	bool	operator>(const Fixed& fixed) const;
	bool	operator>=(const Fixed& fixed) const;
	bool	operator<(const Fixed& fixed) const;
	bool	operator<=(const Fixed& fixed) const;
	Fixed		&operator++(void);
	Fixed		&operator--(void);
	const Fixed	operator++(int);
	const Fixed	operator--(int);
	static Fixed&	max(Fixed& f1, Fixed& f2);
	static Fixed&	min(Fixed& f1, Fixed& f2);
	const static Fixed&	max(const Fixed& f1, const Fixed& f2);
	const static Fixed&	min(const Fixed& f1, const Fixed& f2);

	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif



// 00000000 00000000 00000001 00000000
// 