/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:33:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/17 14:33:52 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <bitset>

class Fixed
{
private:
	int					numVal;
	static const int	fracBits = 8;
public:
	Fixed();
	Fixed(const Fixed &obj);
	~Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed	&operator=(Fixed const &obj);
	bool	operator>(Fixed const &obj);
	bool	operator<(Fixed const &obj);
	bool	operator>=(Fixed const &obj);
	bool	operator<=(Fixed const &obj);
	bool	operator==(Fixed const &obj);
	bool	operator!=(Fixed const &obj);
	Fixed	operator+(Fixed const &obj);
	Fixed	operator-(Fixed const &obj);
	Fixed	operator*(Fixed const &obj);
	Fixed	operator/(Fixed const &obj);
	Fixed	&operator++(void);
	Fixed	operator++(int dummy);
	Fixed	&operator--(void);
	Fixed	operator--(int dummy);
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed	&min(Fixed const &a, Fixed const &b);
	static const Fixed	&max(Fixed const &a, Fixed const &b);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	void	printBit(void) const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &obj);

