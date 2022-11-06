/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:47:05 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/06 21:18:13 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

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

