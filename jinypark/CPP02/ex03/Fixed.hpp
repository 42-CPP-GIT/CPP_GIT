/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:33:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/17 14:54:59 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					numVal;
	static const int	fracBits = 16;
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
	static Fixed	&max(Fixed const &a, Fixed const &b);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &obj);

#endif