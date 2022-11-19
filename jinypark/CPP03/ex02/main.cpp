/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:40:01 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/19 23:48:30 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a("A");
	FragTrap b("B");

	a.printStat();
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(1);
	a.highFivesGuys();
	b.highFivesGuys();
	return (0);
}