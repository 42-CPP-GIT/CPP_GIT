/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 17:29:22 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	_test0(void) {
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 0 > @@@@@@@@@@@@@@@" << std::endl;
	ClapTrap	ct_bot("cl4p-Tp");

	ct_bot.attack("hello");
	ct_bot.checkStatus();

	ct_bot.takeDamage(3);
	ct_bot.checkStatus();

	for (int i = 0; i < 2; ++i) {
		ct_bot.beRepaired(2);
		ct_bot.checkStatus();
	}
	ct_bot.beRepaired(UINT_MAX);
	ct_bot.checkStatus();

	for (int i = 0; i < 10; ++i) {
		ct_bot.attack("nice");
		ct_bot.checkStatus();
	}

	ct_bot.takeDamage(8);
	ct_bot.checkStatus();

	ct_bot.attack("nice");
	ct_bot.checkStatus();

	ct_bot.takeDamage(UINT_MAX);
	ct_bot.checkStatus();

	ct_bot.beRepaired(UINT_MAX);
	ct_bot.checkStatus();

	ct_bot.takeDamage(3);
	ct_bot.checkStatus();

	ct_bot.beRepaired(3);
	ct_bot.checkStatus();

}

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

	for (int i = 0; i < 46; ++i) {
		st_bot.attack("nice");
	}
	st_bot.checkStatus();

	st_bot.takeDamage(8);
	st_bot.checkStatus();

	st_bot.attack("nice");
	st_bot.checkStatus();

	st_bot.beRepaired(UINT_MAX);
	st_bot.checkStatus();

	st_bot.takeDamage(UINT_MAX);
	st_bot.checkStatus();

	st_bot.beRepaired(UINT_MAX);
	st_bot.checkStatus();


	st_bot.takeDamage(3);
	st_bot.checkStatus();

}

static void	_test1_1(void) {	// ScavTrap1 vs ScavTrap2
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
		st_bot1.takeDamage(st_bot2.getAttackDamage());
		st_bot1.checkStatus();
		st_bot1.attack(st_bot2.getName());
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

static void	_test1_2(void) {	// ScavTrap vs ClapTrap
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 3 > @@@@@@@@@@@@@@@" << std::endl;
	ClapTrap	ct_bot("cl4p-Tp");
	ct_bot.checkStatus();
	ScavTrap	st_bot("sc4v-Tp");
	st_bot.checkStatus();

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
	st_bot.guardGate();
}

int	main(void) {
	_test0();
	_test1();
	_test1_1();
	_test1_2();

	return 0;
}
