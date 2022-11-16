/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:58 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/16 09:20:22 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap A("hchang");

	A.attack("Monster");
	A.guardGate();
	A.printTrapInfo();
	A.takeDamage(109);
	A.printTrapInfo();
	// A.beRepaired(99);
	// A.printTrapInfo();
	// A.beRepaired(1);
	// A.printTrapInfo();

}
