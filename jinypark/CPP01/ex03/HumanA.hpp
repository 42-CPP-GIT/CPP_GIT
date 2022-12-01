/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:27:46 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/31 19:28:43 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	std::string		name_;
	Weapon			&weapon_;
public:
	HumanA(std::string const &name, Weapon &weapon);
	void	attack(void);
	void	setWeapon(Weapon &weapon);
};

#endif