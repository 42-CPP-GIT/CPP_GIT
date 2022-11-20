/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:32 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 15:49:31 by sesim            ###   ########.fr       */
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
		Fixed&				operator=(const Fixed& obj);
		Fixed				operator+(const Fixed& obj);
		Fixed				operator-(const Fixed& obj);
		Fixed				operator*(const Fixed& obj);
		Fixed				operator/(const Fixed& obj);
		bool				operator==(const Fixed& obj) const;
		bool				operator!=(const Fixed& obj) const;
		bool				operator>(const Fixed& obj) const;
		bool				operator>=(const Fixed& obj) const;
		bool				operator<=(const Fixed& obj) const;
		bool				operator<(const Fixed& obj) const;
		Fixed&				operator++(void);
		Fixed&				operator--(void);
		const Fixed			operator++(int);
		const Fixed			operator--(int);
		static Fixed&		max(Fixed& a, Fixed& b);
		static Fixed&		min(Fixed& a, Fixed& b);
		const static Fixed&	max(const Fixed& a, const Fixed& b);
		const static Fixed&	min(const Fixed& a, const Fixed& b);
		float				toFloat( void ) const;
		int					toInt( void ) const;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		~Fixed();
};

std::ostream&				operator<<(std::ostream& out, const Fixed& obj);

#endif
