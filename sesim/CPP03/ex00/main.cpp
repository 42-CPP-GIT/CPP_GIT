/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:10:13 by sesim             #+#    #+#             */
/*   Updated: 2022/12/06 17:03:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	A("test");

	A.attack("something");
	// A.takeDamage(2147483647);
	A.beRepaired(5);
	A.takeDamage(6);
	A.beRepaired(2147483649);
	A.takeDamage(12);
	A.beRepaired(12);
}