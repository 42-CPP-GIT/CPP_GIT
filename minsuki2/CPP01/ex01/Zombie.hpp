/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:52:13 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/17 13:42:13 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>
# define	MSG_SOUND		"BraiiiiiiinnnzzzZ..."
# define	MSG_CREATE		"is created"
# define	MSG_DESTROY		"is gone"
# define	MSG_ENDL		'\n'

class Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	setZombieName(const std::string& name);
	private:
		std::string name_;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
