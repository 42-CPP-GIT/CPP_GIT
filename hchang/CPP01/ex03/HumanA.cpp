/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:07 by hchang            #+#    #+#             */
/*   Updated: 2022/11/05 16:08:08 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) 
	: _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
