/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:48:14 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/09 16:19:47 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
			Zombie(void);
			Zombie(std::string name);
    		~Zombie();
	void	announce(void);
	static Zombie* newZombie(std::string name);
	static void	randomChump(std::string name);
};
