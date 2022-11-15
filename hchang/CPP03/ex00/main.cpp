/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:58 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/09 17:10:13 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap A("hchang");

	A.attack("Monster");
	A.takeDamage(5);
	A.takeDamage(5);
	A.beRepaired(10);
	A.attack("Monster");
	A.printTrapInfo();
	A.takeDamage(5);
	A.attack("Monster");
	A.printTrapInfo();

}