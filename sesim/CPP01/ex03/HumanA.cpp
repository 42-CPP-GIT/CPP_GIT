/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:36:00 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 15:02:23 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon)
{
}

void	HumanA::attack(void)
{
	std::cout << this->name_ << " attacks with " << this->weapon_.getType() << std::endl;
}

HumanA::~HumanA()
{
}