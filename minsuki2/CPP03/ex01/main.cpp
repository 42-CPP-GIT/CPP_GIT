/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 23:50:22 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	_test1(void) {	// exception handling
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 1 > @@@@@@@@@@@@@@@" << std::endl;
	ScavTrap	st_bot("sc4p-Tp");

	st_bot.attack("hello");
	st_bot.checkStatus();

	st_bot.takeDamage(3);
	st_bot.checkStatus();

	for (int i = 0; i < 2; ++i) {
		st_bot.beRepaired(2);
		st_bot.checkStatus();
	}
	st_bot.beRepaired(UINT_MAX);
	st_bot.checkStatus();

	for (int i = 0; i < 10; ++i) {
		st_bot.attack("nice");
		st_bot.checkStatus();
	}

	st_bot.takeDamage(8);
	st_bot.checkStatus();

	st_bot.attack("nice");
	st_bot.checkStatus();

	st_bot.takeDamage(UINT_MAX);
	st_bot.checkStatus();

	st_bot.beRepaired(UINT_MAX);
	st_bot.checkStatus();

	st_bot.takeDamage(3);
	st_bot.checkStatus();

	st_bot.beRepaired(3);
	st_bot.checkStatus();

}

static void	_test2(void) {	// ScavTrap1 vs ScavTrap2
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 2 > @@@@@@@@@@@@@@@" << std::endl;
	ScavTrap	st_bot1("sc4v-Tp-1");
	st_bot1.checkStatus();
	ScavTrap	st_bot2("sc4v-Tp-2");
	st_bot2.checkStatus();

	st_bot1.attack(st_bot2.getName());
	st_bot1.checkStatus();
	st_bot2.takeDamage(st_bot1.getAttackDamage());
	st_bot2.checkStatus();

	for (int i = 0; i < 2; ++i) {
		st_bot2.attack(st_bot1.getName());
		st_bot2.checkStatus();
		st_bot1.takeDamage(st_bot2.getAttackDamage());
		st_bot1.checkStatus();
		st_bot1.attack(st_bot2.getName());
		st_bot1.checkStatus();
		st_bot2.takeDamage(st_bot1.getAttackDamage());
		st_bot2.checkStatus();
	}
	st_bot1.guardGate();
	st_bot1.checkStatus();
	st_bot2.checkStatus();

	st_bot1.beRepaired(UINT_MAX);
	st_bot1.checkStatus();
	for (int i = 0; i < 3; ++i) {
		st_bot2.beRepaired(40);
		st_bot2.checkStatus();
	}

	st_bot2.takeDamage(UINT_MAX);
	st_bot2.checkStatus();
	st_bot2.beRepaired(UINT_MAX);
	st_bot2.checkStatus();
}



static void	_test3(void) {	// ScavTrap vs ClapTrap
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 3 > @@@@@@@@@@@@@@@" << std::endl;
	ClapTrap	ct_bot("cl4p-Tp");
	ScavTrap	st_bot("sc4v-Tp");
	st_bot.checkStatus();
	ct_bot.checkStatus();

	ct_bot.attack(st_bot.getName());
	ct_bot.checkStatus();
	st_bot.takeDamage(ct_bot.getAttackDamage());
	st_bot.checkStatus();

	st_bot.attack(ct_bot.getName());
	st_bot.checkStatus();
	ct_bot.takeDamage(st_bot.getAttackDamage());
	ct_bot.checkStatus();

	ct_bot.beRepaired(20);		// already Dead
	ct_bot.checkStatus();
	st_bot.beRepaired(20);		// HP is full 
	st_bot.checkStatus();
}

int	main(void) {
	ClapTrap::max_hp_ = 10;
	ClapTrap::max_hp_ = 0;
	ClapTrap::max_hp_ = 10;
	_test1();
	_test2();
	_test3();
	return 0;
}
