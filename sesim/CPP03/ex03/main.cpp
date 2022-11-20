/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:10:13 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 21:55:15 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	A("test");

	A.attack("something");
	A.takeDamage(30);
	A.printInfo();
	A.beRepaired(5);
	A.printInfo();
	A.guardGate();
	A.beRepaired(2147483649);
	A.highFivesGuys();
	A.whoAmI();
	A.takeDamage(12);
	A.beRepaired(12);
	A.takeDamage(2147483648);
}