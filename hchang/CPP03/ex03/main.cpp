/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:58 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/16 13:15:54 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


// 100
// 50
// 30
int main()
{

	// FragTrap A("hchang");
	// A.attack("Monster");
	// A.printTrapInfo();

	// ScavTrap B("sesim");
	// B.attack("human");
	// B.printTrapInfo();
	
	DiamondTrap C("jinypark");
	C.attack("42 cadet");
	C.printTrapInfo();
	C.takeDamage(1);
	C.printTrapInfo();
	C.beRepaired(2);
	C.printTrapInfo();
	C.whoAmI();
}