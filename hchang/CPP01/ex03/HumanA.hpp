/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:03 by hchang            #+#    #+#             */
/*   Updated: 2022/11/08 16:21:07 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H_
#define HUMANA_H_

#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon		&_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	void	attack(void) const;
};

#endif
