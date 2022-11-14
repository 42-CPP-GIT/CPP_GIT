/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:27:37 by hchang            #+#    #+#             */
/*   Updated: 2022/11/14 19:13:12 by hchang           ###   ########.fr       */
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
	Fixed& operator=(const Fixed& fixed);
	~Fixed();
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
