/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:56:57 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/09 16:07:23 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string&	Weapon::getType(void) const
{
	const std::string& ret = type_;
	return (ret);
}

void	Weapon::setType(std::string const &type)
{
	this->type_ = type;
}

Weapon::Weapon(std::string const &type)
{
	this->type_ = type;
}
