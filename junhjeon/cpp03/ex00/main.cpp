/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:57:25 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 21:57:49 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");
	ClapTrap c(a);

	b = a;

	c.attack("something");
	a.takeDamage(5);
	b.beRepaired(5);

	//std::cout << a.getHitpoint() << a.getEnergyPoints() << std::endl;

	return (0);
}
