/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:06:06 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/06 21:13:55 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* paZombie = Zombie::newZombie("Heap Zombie");
	Zombie	zombie;

	zombie.announce();
	paZombie->announce();
	for (int i = 0; i < 5; ++i)
	{
		Zombie::randomChump("random zombie");
	}
	delete (paZombie);
	return (0);
}
