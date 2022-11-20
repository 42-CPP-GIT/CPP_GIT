/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:32 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 14:57:16 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					fixed_num_;
		static const int	fractional_bits_ = 8;
	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& obj);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
};

std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

#endif
