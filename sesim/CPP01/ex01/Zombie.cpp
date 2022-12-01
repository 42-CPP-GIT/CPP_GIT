/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:42:50 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 14:26:31 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::initialize(std::string name)
{
	this->name_ = name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name_ << ": is dead" << std::endl;
}