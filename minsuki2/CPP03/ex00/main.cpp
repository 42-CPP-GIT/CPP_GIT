/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 16:16:51 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	_test0(void) {
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 0 > @@@@@@@@@@@@@@@" << std::endl;
	ClapTrap	ct_bot("cl4p-Tp");

	ct_bot.attack("hello");
	ct_bot.checkStatus();

	ct_bot.takeDamage(3);
	ct_bot.checkStatus();

	for (int i = 0; i < 2; ++i) {
		ct_bot.beRepaired(2);
	}
	ct_bot.checkStatus();

	ct_bot.beRepaired(UINT_MAX);
	ct_bot.checkStatus();

	for (int i = 0; i < 10; ++i) {
		ct_bot.attack("nice");
	}
	ct_bot.checkStatus();

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

static void	_test0_1(void) {	// ClapTrap vs ClapTrap
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 0-1 > @@@@@@@@@@@@@@@" << std::endl;
	ClapTrap	ct_bot1("cl4p-Tp-1");
	ct_bot1.checkStatus();

	ClapTrap	ct_bot2("cl4p-Tp-2");
	ct_bot2.checkStatus();

	ct_bot2.attack(ct_bot1.getName());
	ct_bot2.checkStatus();
	ct_bot1.takeDamage(ct_bot2.getAttackDamage());
	ct_bot1.checkStatus();

	ct_bot1.attack(ct_bot2.getName());
	ct_bot1.checkStatus();
	ct_bot2.takeDamage(ct_bot1.getAttackDamage());
	ct_bot2.checkStatus();

	ct_bot2.beRepaired(3);		// already Dead
	ct_bot2.checkStatus();
	ct_bot1.beRepaired(3);		// HP is full
	ct_bot1.checkStatus();
}

int	main(void) {
	_test0();
	_test0_1();
	return 0;
}
