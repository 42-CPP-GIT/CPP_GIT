/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:04 by hchang            #+#    #+#             */
/*   Updated: 2022/11/03 11:01:55 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_
#define HUMANB_H_

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
    std::string _name;
    Weapon		*_weapon;
    HumanB();
public:
	void	attack(void);
    void    setWeapon(Weapon &weapon);
    HumanB(std::string name);
    ~HumanB();
};

#endif
