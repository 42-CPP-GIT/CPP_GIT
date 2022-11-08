/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:28:36 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/26 14:02:13 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	zombie;
	Zombie	*zombies;

	zombies = zombie.zombieHorde(4, "Foo");
	for (int i = 0; i < 4; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
}