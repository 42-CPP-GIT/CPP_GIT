/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:17 by hchang            #+#    #+#             */
/*   Updated: 2022/11/05 15:27:07 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon()
{

}

const	std::string& Weapon::getType() const
{
    return (this->_type);
}

void	Weapon::setType(const std::string type)
{
    this->_type = type;
}
