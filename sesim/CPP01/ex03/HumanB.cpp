/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:50:08 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 15:13:48 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name_ = name;
	this->weapon_ = NULL;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon_)
		std::cout << this->name_ << " attacks with " << this->weapon_->getType() << std::endl;
	else
		std::cout << this->name_ << " is unarmed" << std::endl;
}

HumanB::~HumanB()
{
}