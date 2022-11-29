/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/28 23:01:59 by minsuki2         ###   ########.fr       */
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

# ifndef std_endl
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
		int					f_num_;
		static const int	f_bits_;
};


#endif
