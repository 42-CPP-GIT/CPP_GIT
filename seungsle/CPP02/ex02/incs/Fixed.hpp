/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:31:55 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/16 11:43:08 by seungsle         ###   ########.fr       */
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
	bool operator > (const Fixed &source) const;
	bool operator < (const Fixed &source) const;
	bool operator >= (const Fixed &source) const;
	bool operator <= (const Fixed &source) const;
	bool operator == (const Fixed &source) const;
	bool operator != (const Fixed &source) const;
	Fixed operator + (const Fixed &source);
	Fixed operator - (const Fixed &source);
	Fixed operator * (const Fixed &source);
	Fixed operator / (const Fixed &source);
	const Fixed operator ++ (int);
	Fixed& operator ++ (void);
	const Fixed operator -- (int);
	Fixed& operator -- (void);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int	toInt( void ) const;
	static Fixed& min(Fixed &a, Fixed &b);
	const static Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &n);
	const static Fixed& max(const Fixed &a, const Fixed &b);
};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
