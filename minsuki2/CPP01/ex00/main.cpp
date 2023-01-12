/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:51:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 19:22:57 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *heap_z(newZombie("heap_zom"));
	Zombie stack_z;

	heap_z->announce();
	stack_z.announce();
	randomChump("random_zom");

	delete heap_z;
	return (0);
}
