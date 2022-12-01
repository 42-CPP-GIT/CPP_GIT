/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:18:52 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/02 20:05:05 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << (this -> weapon).getType() << std::endl;
}

HumanA::HumanA( std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}
