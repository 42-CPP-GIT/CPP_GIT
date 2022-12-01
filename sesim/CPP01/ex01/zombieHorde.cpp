/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:43:10 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 14:45:27 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 1)
		return (NULL);
	Zombie	*zombies(new Zombie[N]);

	for (int i = 0; i < N; ++i)
	{
		std::cout << "[" << i + 1 << "] ";
		zombies[i].initialize(name);
		zombies[i].announce();
	}
	return (zombies);
}