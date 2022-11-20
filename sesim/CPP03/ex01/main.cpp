/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:10:13 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 20:15:43 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	A("test");

	A.attack("something");
	A.takeDamage(20);
	A.printInfo();
	A.beRepaired(5);
	A.printInfo();
	A.beRepaired(2147483649);
	A.guardGate();
	A.takeDamage(12);
	A.beRepaired(12);
}