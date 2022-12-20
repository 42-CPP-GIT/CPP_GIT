/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 17:55:26 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <typeinfo>

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

static void	_test2(void) {	// exception handling
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 2 > @@@@@@@@@@@@@@@" << std::endl;
	FragTrap	ft_bot("fr4p-Tp");

	ft_bot.attack("hello");
	ft_bot.checkStatus();

	ft_bot.takeDamage(3);
	ft_bot.checkStatus();

	for (int i = 0; i < 2; ++i) {
		ft_bot.beRepaired(2);
		ft_bot.checkStatus();
	}
	ft_bot.beRepaired(UINT_MAX);
	ft_bot.checkStatus();

	for (int i = 0; i < 46; ++i) {
		ft_bot.attack("nice");
	}
	ft_bot.checkStatus();

	ft_bot.takeDamage(8);
	ft_bot.checkStatus();

	ft_bot.attack("nice");
	ft_bot.checkStatus();

	ft_bot.beRepaired(UINT_MAX);
	ft_bot.checkStatus();

	ft_bot.takeDamage(UINT_MAX);
	ft_bot.checkStatus();

	ft_bot.beRepaired(UINT_MAX);
	ft_bot.checkStatus();

	ft_bot.takeDamage(3);
	ft_bot.checkStatus();

}


static void	_test3(void) {	// exception handling
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 3 > @@@@@@@@@@@@@@@" << std::endl;
	DiamondTrap	dt_bot("Diam-Tp");

	dt_bot.attack("hello");
	dt_bot.checkStatus();

	dt_bot.takeDamage(3);
	dt_bot.checkStatus();

	for (int i = 0; i < 2; ++i) {
		dt_bot.beRepaired(2);
		dt_bot.checkStatus();
	}
	dt_bot.beRepaired(UINT_MAX);
	dt_bot.checkStatus();

	for (int i = 0; i < 46; ++i) {
		dt_bot.attack("nice");
	}
	dt_bot.checkStatus();

	dt_bot.takeDamage(8);
	dt_bot.checkStatus();

	dt_bot.attack("nice");
	dt_bot.checkStatus();

	dt_bot.beRepaired(UINT_MAX);
	dt_bot.checkStatus();

	dt_bot.takeDamage(UINT_MAX);
	dt_bot.checkStatus();

	dt_bot.beRepaired(UINT_MAX);
	dt_bot.checkStatus();

	dt_bot.whoAmI();
	dt_bot.checkStatus();

	dt_bot.takeDamage(3);
	dt_bot.checkStatus();
}

static void	_test3_1(void) {	// DiamondTrap1 vs DiamondTrap2
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 3-1 > @@@@@@@@@@@@@@@" << std::endl;
	DiamondTrap		dt_bot1("Diam-Tp-1");
	dt_bot1.checkStatus();
	DiamondTrap		dt_bot2("Diam-Tp-2");
	dt_bot2.checkStatus();

	dt_bot1.attack(dt_bot2.getName());
	dt_bot1.checkStatus();
	dt_bot2.takeDamage(dt_bot1.getAttackDamage());
	dt_bot2.checkStatus();

	for (int i = 0; i < 2; ++i) {
		dt_bot2.attack(dt_bot1.getName());
		dt_bot2.checkStatus();
		dt_bot1.takeDamage(dt_bot2.getAttackDamage());
		dt_bot1.checkStatus();
		dt_bot1.attack(dt_bot2.getName());
		dt_bot1.checkStatus();
		dt_bot2.takeDamage(dt_bot1.getAttackDamage());
		dt_bot2.checkStatus();
	}

	dt_bot1.highFivesGuys();
	dt_bot1.checkStatus();
	dt_bot2.highFivesGuys();
	dt_bot2.checkStatus();

	dt_bot1.beRepaired(UINT_MAX);
	dt_bot1.checkStatus();
	for (int i = 0; i < 3; ++i) {
		dt_bot2.beRepaired(40);
		dt_bot2.checkStatus();
	}

	dt_bot2.takeDamage(UINT_MAX);
	dt_bot2.checkStatus();
	dt_bot2.beRepaired(UINT_MAX);
	dt_bot2.checkStatus();
}

static void _test3_2(void) {	// DiamondTrap vs ClapTrap
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 3-2 > @@@@@@@@@@@@@@@" << std::endl;
	DiamondTrap		dt_bot("Diam-Tp");
	dt_bot.checkStatus();
	ClapTrap		ct_bot("Cl4p-Tp");
	ct_bot.checkStatus();

	ct_bot.takeDamage(5);
	ct_bot.checkStatus();
	ct_bot.beRepaired(20);
	ct_bot.checkStatus();

	ct_bot.attack(dt_bot.getName());
	dt_bot.takeDamage(ct_bot.getAttackDamage());
	dt_bot.checkStatus();
	dt_bot.attack(ct_bot.getName());
	ct_bot.takeDamage(dt_bot.getAttackDamage());
	ct_bot.checkStatus();

	ct_bot.beRepaired(20);
	ct_bot.checkStatus();
	dt_bot.beRepaired(20);
	dt_bot.checkStatus();

	dt_bot.whoAmI();

}

static int _test4(void) {
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 4 > @@@@@@@@@@@@@@@" << std::endl;
	int i(40);
	{
		int i(3);
		(void)i;
	}
	std::cout << BOLDWHITE << "i Value : " << i << RESET << std::endl;
	return (i);
}

int	main(void) {
	_test0();
	_test1();
	_test2();
	_test3();
	_test3_1();
	_test3_2();
	_test4();
	return 0;
}
