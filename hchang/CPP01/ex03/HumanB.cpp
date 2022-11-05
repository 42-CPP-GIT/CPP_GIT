/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:11 by hchang            #+#    #+#             */
/*   Updated: 2022/11/02 19:48:52 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    std::cout << weapon.getType() <<  std::endl;
    this->_weapon = &weapon;
}
