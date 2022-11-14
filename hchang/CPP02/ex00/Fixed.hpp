/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:27:37 by hchang            #+#    #+#             */
/*   Updated: 2022/11/14 19:11:29 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_fixedNum;
	static const int	_fixedBits = 8;
public:
	Fixed();
	Fixed(const Fixed &value);
	Fixed& operator=(const Fixed& fixed);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif

// 안해놓으면 자동으로 해놓기 때문에

// 5.5

// 0.5 => 0 | 1
// 5.5 => 101 | 1 fixed 

// 101.1 -> 1.011 * (2^2)

// 01000001 00110000 00000000 00000000