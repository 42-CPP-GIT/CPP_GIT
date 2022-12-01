/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:42:38 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 14:31:27 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name_;
	public:
		Zombie();
		void	announce(void);
		void	initialize(std::string name);
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif
