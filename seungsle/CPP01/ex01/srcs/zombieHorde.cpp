/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:28:27 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/26 14:01:35 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	Zombie	*newZombies;

	newZombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		newZombies[i].setName(name);
	return (newZombies);
}