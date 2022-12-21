/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:51:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 18:14:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
# define N_ZOM		5

int main(void) {

	Zombie *heap_zom = zombieHorde(N_ZOM, "HeapZom");
	Zombie *null_zom = NULL;
	Zombie name_zom("NameZom");
	Zombie stack_zom;

	for (int i = 0; i < N_ZOM; i++)
		heap_zom[i].announce();

	name_zom.announce();
	stack_zom.announce();
	delete[] heap_zom;
	delete[] null_zom;
	return (0);
}
