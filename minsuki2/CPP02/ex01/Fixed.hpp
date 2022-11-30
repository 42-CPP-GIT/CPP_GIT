/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/30 17:31:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
# define MSG_CALL		" called"
# define MSG_CREATE		"Default constructor"
# define MSG_DESTROY 	"Destructor"
# define MSG_COPY		"Copy constructor"
# define MSG_ASSIGN 	"Copy assignment operator"
# define MSG_GETRB		"getRawBits member function"
# define MSG_IS			" is"
# define MSG_INTEGER	" as integer"
# define MSG_FLOAT		" as float"

# ifndef std_endl
#  define MSG_ENDL		'\n'
# else
#  define MSG_ENDL		std::endl
# endif
# define FLOAT_BITS		23

class Fixed {
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed(void);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		friend std::ostream& operator<<(std::ostream& out, const Fixed& obj);
	private:
		int					fixed_num_;
		static const int	fixed_nbits_;
};


#endif
