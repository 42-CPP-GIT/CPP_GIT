/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:06:06 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/28 20:24:57 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* paZombie = Zombie::zombieHorde(10, "heapZombie");
	for (int i = 0; i < 10; ++i)
		paZombie[i].announce();
	delete[] (paZombie);
	return (0);
}
