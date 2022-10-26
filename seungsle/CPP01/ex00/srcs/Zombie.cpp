/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:49:54 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/26 12:13:30 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}

void	Zombie::randomChump(std::string name)
{
	Zombie	*zombie;

	zombie = newZombie(name);
	zombie->announce();
	delete zombie;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " is destructed" << std::endl;
}

Zombie::Zombie()
{
	_name = "Foo";
}