/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:20:21 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 20:22:52 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (!this -> weapon)
	{
		std::cout << name << "have no weapon" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << (this -> weapon)->getType() << std::endl;
}

HumanB::HumanB( std::string name )
{
	this -> name = name;
	this -> weapon = 0;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this -> weapon = &weapon;
}
