/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:15:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/02 18:24:51 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "HumanA.hpp"
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	HumanA();
	~HumanA();
	void	attack();
};

#endif