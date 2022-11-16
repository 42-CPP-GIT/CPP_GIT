/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:06:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 20:52:33 by junhjeon         ###   ########.fr       */
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
		static int& min( int& fixed_n1, int& fixed_n2 );
		static const int& min( const int& fixed_n1, const int& fixed_n2 );
		static int& max( int& fixed_n1, int& fixed_n2 );
		static const int& max( const int& fixed_n1, const int& fixed_n2 );
		static float max(Fixed& a, const Fixed&b);
};

std::ostream& operator <<(std::ostream &os, const Fixed& f);

#endif
