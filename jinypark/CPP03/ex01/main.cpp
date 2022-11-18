/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:40:01 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/18 17:49:03 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap a("A");
	// ScavTrap b("B");
	ClapTrap* c(new ClapTrap("C"));
	ScavTrap* d(new ScavTrap("D"));

	c = d;
	// a.attack(b.getName());
	// b.takeDamage(a.getAttackDamage());
	// b.attack(a.getName());
	// a.takeDamage(b.getAttackDamage());
	// a.beRepaired(1);
	// a.guardGate();
	// b.guardGate();
	c->attack("something");
	// d->attack("dd");
	delete c;
	return (0);
}