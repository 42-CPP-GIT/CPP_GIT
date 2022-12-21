/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 16:56:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	for (int i = 0; i < 96; ++i) {
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

static void	_test2_1(void) {	// FragTrap1 vs FragTrap2
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 2-1 > @@@@@@@@@@@@@@@" << std::endl;
	FragTrap	ft_bot1("fr4g-Tp-1");
	ft_bot1.checkStatus();
	FragTrap	ft_bot2("fr4g-Tp-2");
	ft_bot2.checkStatus();

	ft_bot1.attack(ft_bot2.getName());
	ft_bot1.checkStatus();
	ft_bot2.takeDamage(ft_bot1.getAttackDamage());
	ft_bot2.checkStatus();

	for (int i = 0; i < 2; ++i) {
		ft_bot2.attack(ft_bot1.getName());
		ft_bot1.takeDamage(ft_bot2.getAttackDamage());
		ft_bot1.checkStatus();
		ft_bot1.attack(ft_bot2.getName());
		ft_bot2.takeDamage(ft_bot1.getAttackDamage());
		ft_bot2.checkStatus();
	}

	ft_bot1.highFivesGuys();
	ft_bot1.checkStatus();
	ft_bot2.highFivesGuys();
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

static void	_test2_2(void) {	// FragTrap vs ClapTrap
	std::cout << "\n\n@@@@@@@@@@@@@@@ < TEST 2-2 > @@@@@@@@@@@@@@@" << std::endl;
	FragTrap	ft_bot("fr4g-Tp");
	ft_bot.checkStatus();
	ClapTrap	ct_bot("cl4p-Tp");
	ct_bot.checkStatus();

	ct_bot.takeDamage(5);
	ct_bot.checkStatus();
	ct_bot.beRepaired(20);
	ct_bot.checkStatus();

	ct_bot.attack(ft_bot.getName());
	ft_bot.takeDamage(ct_bot.getAttackDamage());
	ft_bot.checkStatus();
	ft_bot.attack(ct_bot.getName());
	ct_bot.takeDamage(ft_bot.getAttackDamage());
	ct_bot.checkStatus();

	ct_bot.beRepaired(20);
	ct_bot.checkStatus();
	ft_bot.beRepaired(20);
	ft_bot.checkStatus();

	ft_bot.highFivesGuys();
}

int	main(void) {
	_test0();
	_test1();
	_test2();
	_test2_1();
	_test2_2();
	return 0;
}
