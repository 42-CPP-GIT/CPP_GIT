/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:37:42 by junhjeon          #+#    #+#             */
/*   Updated: 2022/10/31 18:07:42 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}

Zombie::Zombie()
{
	name = "foo";
}

void	Zombie::setName( std::string var )
{
	this -> name = var;
}
