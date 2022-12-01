/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:25 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/03 16:31:06 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string const &name, Weapon &weapon) : name_(name), weapon_(weapon)
{
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon_ = weapon;
}

void	HumanA::attack(void)
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType() 
	<< "\n";
}

