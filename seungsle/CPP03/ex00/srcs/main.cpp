/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:22:03 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/16 19:14:42 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap A("seungsle");

	A.attack("CPP03");
	A.beRepaired(100);
	A.printStatus();
	A.takeDamage(20);
	A.attack("CPP03");
	A.printStatus();

	ClapTrap B(A);

	B.attack("CPP04");
	B.printStatus();

	ClapTrap C("alvin");

	C.printStatus();
	for (unsigned int i = 0; i < 10; i++)
		C.attack("CPP05");
	C.attack("CPP06");

	return (0);
}