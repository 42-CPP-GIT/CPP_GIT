/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:50:08 by sesim             #+#    #+#             */
/*   Updated: 2022/11/08 12:00:29 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name_ = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->name_ << "attacks with " << this->weapon_->getType() << std::endl;
}

HumanB::~HumanB()
{
}