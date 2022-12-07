/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/07 20:05:44 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# define MSG_CALL		" called"
# define MSG_CREATE		"Default constructor"
# define MSG_DESTROY 	"Destructor"
# define MSG_COPY		"Copy constructor"
# define MSG_ASSIGN 	"Copy assignment operator"
# define MSG_GETRB		"getRawBits member function"

# ifndef ENDL
#  define MSG_ENDL		'\n'
# else
#  define MSG_ENDL		std::endl
# endif

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					fixed_num_;
		static const int	fixed_nbits_;
};

#endif
