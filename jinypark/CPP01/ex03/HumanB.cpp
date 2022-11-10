/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:25 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/06 21:25:54 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name)
{
	this->weapon_ = NULL;
}

HumanB::HumanB(std::string name, Weapon &weapon) : name_(name), weapon_(&weapon)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon_ != NULL)
		std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << "\n";
}

