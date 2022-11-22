/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:06:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/01 19:39:50 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int	fixed_point_n;
		static const int fractional_bit;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator =(const Fixed& f);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
