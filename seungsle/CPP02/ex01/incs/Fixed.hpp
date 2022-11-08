/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:31:55 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/06 17:04:32 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_fixedPointNum;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const int fixedPointNum);
	Fixed(const float fixedPointNum);
	Fixed(Fixed &Fixed);
	~Fixed();
	Fixed& operator = (const Fixed &source);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int	toInt( void ) const;
};

#endif
