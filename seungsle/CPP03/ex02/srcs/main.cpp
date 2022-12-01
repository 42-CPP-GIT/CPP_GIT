/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:22:03 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 00:38:46 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap A("seungsle");

	A.attack("CPP03");
	A.printStatus();
	A.attack("CPP03");
	A.printStatus();
	A.highFivesGuys();
	return (0);
}