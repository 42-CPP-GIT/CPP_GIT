/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:16 by hchang            #+#    #+#             */
/*   Updated: 2022/11/10 13:48:56 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{ 
	std::cout << "My life for Aiur!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "[destructor] " << this->_name << " will be back.. " << std::endl;
}

void	Zombie::setZombieName(std::string name)
{
	this->_name = name;
}
