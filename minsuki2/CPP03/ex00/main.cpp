/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/12 14:08:43 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	ctBot("cl4p-Tp");

	ctBot.attack("hello");
	ctBot.takeDamage(3);
	ctBot.attack("nice");
	ctBot.takeDamage(7);
	ctBot.attack("nice");
	ctBot.takeDamage(7);
	ctBot.beRepaired(3);
	ctBot.takeDamage(3);
	ctBot.beRepaired(3);

	return 0;
}
