/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:57:25 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 23:05:31 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("ClapA");
	ScavTrap b("ScavB");
	FragTrap c("FragC");

	a.attack("something");
	b.attack("something");
	c.highFivesGuys();
	b.guardGate();

	return (0);
}
