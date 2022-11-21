/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:57:25 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:11:32 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap a("ClapA");
	ScavTrap b("ScavB");
	FragTrap c("FragC");
	DiamondTrap d("DiaD");

	std::cout << "==============================" << std::endl;
	a.attack("something");
	a.beRepaired(10);
	a.takeDamage(10);

	std::cout << "==============================" << std::endl;
	b.attack("something");
	b.beRepaired(10);
	b.takeDamage(10);
	b.guardGate();

	std::cout << "==============================" << std::endl;
	c.attack("something");
	c.beRepaired(10);
	c.takeDamage(10);
	c.highFivesGuys();

	std::cout << "==============================" << std::endl;
	d.attack("something");
	d.beRepaired(10);
	d.takeDamage(10);
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();

	std::cout << "==============================" << std::endl;
	//d.ScavTrap::guardGate();
	//d.ClapTrap::beRepaired();

	return (0);
}
