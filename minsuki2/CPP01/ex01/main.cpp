/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:51:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/09 17:26:46 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *heap_zom(newZombie("h_zom"));
	Zombie stack_zom;


	heap_zom->announce();
	stack_zom.announce();

	randomChump("r_zom");

	delete heap_zom;
	return (0);
}
