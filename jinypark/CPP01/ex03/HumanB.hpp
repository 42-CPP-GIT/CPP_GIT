/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:27:46 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/03 16:31:10 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name_;
	Weapon		*weapon_;
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	void	attack(void);
	void	setWeapon(Weapon &weapon);
};

#endif