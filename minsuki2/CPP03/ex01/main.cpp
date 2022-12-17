/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 18:03:54 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	_test1_ctBot(void) {
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 1 > @@@@@@@@@@@@@@@" << std::endl;
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

static void	_test2_stBot(void) {
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 2 > @@@@@@@@@@@@@@@" << std::endl;
	ScavTrap	st_bot("sc4v-Tp");
	st_bot.checkStatus();

	st_bot.attack("hello");
	st_bot.checkStatus();

	for (int i = 0; i < 2; ++i) {
		st_bot.takeDamage(30);
		st_bot.checkStatus();
	}

	for (int i = 0; i < 2; ++i) {
		st_bot.beRepaired(20);
		st_bot.checkStatus();
	}
}

static void	_test3_cstBot(void) {
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 3 > @@@@@@@@@@@@@@@" << std::endl;
	ClapTrap	ct_bot("cl4p-Tp");
	ScavTrap	st_bot("sc4v-Tp");
	st_bot.checkStatus();
	ct_bot.checkStatus();

	ct_bot.attack("hello");
	st_bot.attack("hello");
	ct_bot.checkStatus();
	st_bot.checkStatus();

	for (int i = 0; i < 2; ++i) {
		ct_bot.takeDamage(30);
		st_bot.takeDamage(30);
		ct_bot.checkStatus();
		st_bot.checkStatus();
	}

	for (int i = 0; i < 2; ++i) {
		ct_bot.beRepaired(20);
		st_bot.beRepaired(20);
		ct_bot.checkStatus();
		st_bot.checkStatus(); }
}

int	main(void) {
	_test1_ctBot();
	_test2_stBot();
	_test3_cstBot();
	return 0;
}
