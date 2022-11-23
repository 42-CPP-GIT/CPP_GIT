/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:08:54 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 18:46:36 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# define	NUM_FUNC	4
# define	MSG_ENDL	'\n'
# define	MSG_DEBUG	"[DEBUG]\n\
I love having extra bacon \
for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n"

# define	MSG_INFO	"[INFO]\n\
I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger!\n\
If you did, I wouldn’t be asking for more!\n"

# define	MSG_WARNING	"[WARNING]\n\
I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month.\n"

# define	MSG_ERROR	"[ERROR]\n\
This is unacceptable! I want to speak to the manager now.\n"

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		int		printOut(const int& i);
};

typedef  void (Harl::*const functionPtr)(void);

#endif
