/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:58 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 15:54:42 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap A("hchang");

	A.attack("Monster");
	A.printTrapInfo();

	ScavTrap B("sesim");
	B.attack("human");
	B.printTrapInfo();
}