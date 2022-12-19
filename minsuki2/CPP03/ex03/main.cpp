/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/19 17:30:47 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <typeinfo>

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

static void	_test2(void) {	// FragTrap1 vs FragTrap2
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 2 > @@@@@@@@@@@@@@@" << std::endl;
	ScavTrap	ft_bot1("sc4v-Tp-1");
	ft_bot1.checkStatus();
	ScavTrap	ft_bot2("sc4v-Tp-2");
	ft_bot2.checkStatus();

	ft_bot1.attack(ft_bot2.getName());
	ft_bot1.checkStatus();
	ft_bot2.takeDamage(ft_bot1.getAttackDamage());
	ft_bot2.checkStatus();

	for (int i = 0; i < 2; ++i) {
		ft_bot2.attack(ft_bot1.getName());
		ft_bot2.checkStatus();
		ft_bot1.takeDamage(ft_bot2.getAttackDamage());
		ft_bot1.checkStatus();
		ft_bot1.attack(ft_bot2.getName());
		ft_bot1.checkStatus();
		ft_bot2.takeDamage(ft_bot1.getAttackDamage());
		ft_bot2.checkStatus();
	}
	ft_bot1.guardGate();
	ft_bot1.checkStatus();
	ft_bot2.checkStatus();

	ft_bot1.beRepaired(UINT_MAX);
	ft_bot1.checkStatus();
	for (int i = 0; i < 3; ++i) {
		ft_bot2.beRepaired(40);
		ft_bot2.checkStatus();
	}

	ft_bot2.takeDamage(UINT_MAX);
	ft_bot2.checkStatus();
	ft_bot2.beRepaired(UINT_MAX);
	ft_bot2.checkStatus();
}



static void	_test3(void) {	// FragTrap vs ClapTrap
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 3 > @@@@@@@@@@@@@@@" << std::endl;
	DiamondTrap	dt_bot("Diam-Tp");
	dt_bot.checkStatus();
	ClapTrap	ct_bot("cl4p-Tp");
	ct_bot.checkStatus();

	ct_bot.attack(dt_bot.getName());
	ct_bot.checkStatus();
	dt_bot.takeDamage(ct_bot.getAttackDamage());
	dt_bot.checkStatus();

	dt_bot.attack(ct_bot.getName());
	dt_bot.checkStatus();
	ct_bot.takeDamage(dt_bot.getAttackDamage());
	ct_bot.checkStatus();

	ct_bot.beRepaired(20);		// already Dead
	ct_bot.checkStatus();
	dt_bot.beRepaired(20);		// HP is full
	dt_bot.checkStatus();

	dt_bot.highFivesGuys();

}

int	main(void) {
	_test1();
	_test2();
	_test3();
	ClapTrap	A;
	std::cout << typeid(A).name() << std::endl;
	return 0;
}
