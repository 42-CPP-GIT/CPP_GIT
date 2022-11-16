/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:06:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 20:45:22 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	fixed_point_n;
		static const int fractional_bit;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator =(const Fixed& f);
		bool	operator <(const Fixed& f);
		bool	operator >(const Fixed& f);
		bool	operator >=(const Fixed& f);
		bool	operator <=(const Fixed& f);
		bool	operator ==(const Fixed& f);
		bool	operator !=(const Fixed& f);
		Fixed	operator +(const Fixed& f);
		Fixed	operator -(const Fixed& f);
		Fixed	operator *(const Fixed& f);
		Fixed	operator /(const Fixed& f);
		Fixed&	operator ++();
		Fixed&	operator --();
		Fixed	operator ++(int a);
		Fixed	operator --(int a);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int 	toInt( void ) const;
		static Fixed& min( Fixed& fixed_n1, Fixed& fixed_n2 );
		static const Fixed& min( const Fixed& fixed_n1, const Fixed& fixed_n2 );
		static Fixed& max( Fixed& fixed_n1, Fixed& fixed_n2 );
		static const Fixed& max( const Fixed& fixed_n1, const Fixed& fixed_n2 );
};

std::ostream& operator <<(std::ostream &os, const Fixed& f);

#endif
