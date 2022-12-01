/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:41:29 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/03 19:25:13 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType( std::string type2 )
{
	this -> type = type2;
}

const std::string&	Weapon::getType(void) const
{
	return (this -> type);
}

Weapon::Weapon( std::string type )
{
	this -> type = type;
}

Weapon::Weapon()
{
	;
}
