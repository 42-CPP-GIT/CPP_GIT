/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombiehorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:40:27 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/10 09:54:01 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	Zombie*				paZombie = new Zombie[N];
	std::stringstream	num;

	for (int i = 0; i < N; ++i)
	{
		num.str(std::string());
		num << i;
		paZombie[i].setName(name + num.str());
	}
	return (paZombie);
}