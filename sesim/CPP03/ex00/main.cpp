/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:10:13 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 19:20:15 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	A("test");

	A.attack("something");
	A.takeDamage(6);
	A.beRepaired(5);
	A.beRepaired(2147483649);
	A.takeDamage(12);
	A.beRepaired(12);
}