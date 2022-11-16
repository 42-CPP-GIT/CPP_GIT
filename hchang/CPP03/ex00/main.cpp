/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:58 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/16 08:58:23 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap A("hchang");

	A.attack("Monster");
	A.takeDamage(5);
	// A.takeDamage(5);
	A.beRepaired(10);
	A.attack("Monster");
	A.printTrapInfo();
	// A.takeDamage(5);
	A.attack("Monster");
	A.printTrapInfo();
	A.beRepaired(20);
	A.printTrapInfo();
	A.beRepaired(1);
	A.printTrapInfo();
}