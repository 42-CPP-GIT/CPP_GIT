/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:58:19 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 14:16:18 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <iostream>

class Zombie
{
	private:
		std::string	name_;
	public:
		Zombie(std::string name);
		void	announce(void);
		~Zombie();
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif