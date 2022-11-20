/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:10:13 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 20:30:20 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	A("test");

	A.attack("something");
	A.takeDamage(20);
	A.printInfo();
	A.beRepaired(5);
	A.printInfo();
	A.beRepaired(2147483649);
	A.highFivesGuys();
	A.takeDamage(12);
	A.beRepaired(12);
	A.takeDamage(2147483648);
}