/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:31:55 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/12 18:09:09 by seungsle         ###   ########.fr       */
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
	Fixed(const Fixed &Fixed);
	~Fixed();
	Fixed& operator = (const Fixed &source);
	bool operator > (const Fixed &source);
	bool operator < (const Fixed &source);
	bool operator >= (const Fixed &source);
	bool operator <= (const Fixed &source);
	bool operator == (const Fixed &source);
	bool operator != (const Fixed &source);
	Fixed operator + (const Fixed &source);
	Fixed operator - (const Fixed &source);
	Fixed operator * (const Fixed &source);
	Fixed operator / (const Fixed &source);
	Fixed operator ++ (int dummy);
	Fixed& operator ++ (void);
	Fixed operator -- (int dummy);
	Fixed& operator -- (void);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int	toInt( void ) const;
	friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif