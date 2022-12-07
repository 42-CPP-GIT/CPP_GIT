/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/07 20:45:47 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
// # include <bitset>	// linux c++11
# define MSG_CALL		" called"
# define MSG_CREATE		"Default constructor '-'"
# define MSG_DESTROY 	"Destructor '~'"
# define MSG_COPY		"Copy constructor '()'"
# define MSG_ASSIGN 	"Copy assignment operator '='"
# define MSG_GETRB		"getRawBits member function"
# define MSG_IS			" is"
# define MSG_INTEGER	" as integer"
# define MSG_FLOAT		" as float"

# ifndef ENDL
#  define MSG_ENDL		'\n'
# else
#  define MSG_ENDL		std::endl
# endif
# define FLOAT_BITS		23

enum e_off_bit {
	OFFSET_FLOAT_NBITS = 23,
	BIT_SIGN = 1 << 31,
	BIT_FIXED_MANTISSA = 0b11111111,
	BIT_FLOAT_EXPONENT = 0b11111111 << OFFSET_FLOAT_NBITS,
	BIT_FLOAT_MANTISSA = 0b11111111111111111111111
};

class Fixed {
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		bool operator>(const Fixed& obj) const;
		bool operator<(const Fixed& obj) const;
		bool operator<=(const Fixed& obj) const;
		bool operator>=(const Fixed& obj) const;
		bool operator==(const Fixed& obj) const;
		bool operator!=(const Fixed& obj) const;
		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		~Fixed(void);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		int		getMantissaBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					fixed_num_;
		static const int	fixed_nbits_;

};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
