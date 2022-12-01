/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:20:58 by junhjeon          #+#    #+#             */
/*   Updated: 2022/10/31 18:12:09 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombies;
	int		n = 10;
	std::string	name = "THE ZOMBIE";

	zombies = Zombie::zombieHorde(n, name);
	for (int i = 0; i < n; i ++)
		zombies[i].announce();
	delete []zombies;
	return (0);
}
