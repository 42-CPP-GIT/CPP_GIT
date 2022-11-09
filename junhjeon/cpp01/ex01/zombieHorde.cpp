/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:10:32 by junhjeon          #+#    #+#             */
/*   Updated: 2022/10/31 18:12:31 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int n, std::string name )
{
	if (n < 0)
		exit(1);
	Zombie *zombies = new Zombie[n];
	if (!zombies)
		exit(1);
	for (int i = 0; i < n; i++)
		zombies[i].setName(name);
	return (zombies);
}
