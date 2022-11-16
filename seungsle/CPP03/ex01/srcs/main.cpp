/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:22:03 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 00:24:16 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap A("seungsle");

	A.attack("CPP03");
	A.printStatus();
	A.guardGate();
	A.attack("CPP03");
	A.printStatus();
	return (0);
}