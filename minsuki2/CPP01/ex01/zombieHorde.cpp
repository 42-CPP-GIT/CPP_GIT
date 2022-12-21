/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:10:45 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/02 18:25:23 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);
	Zombie *array_zom = new Zombie[N];

	for (int i = 0; i < N ; i++) {
		std::stringstream index_ss;
		index_ss << name << '_' << i;
		if (index_ss.fail()) {
			delete[] array_zom;
			return (NULL);
		}
		std::string index_name = index_ss.str();
		array_zom[i].setZombieName(index_name);
		// array_zom[i].announce();
		// index_ss.str(std::string());
	}
	return (array_zom);
}
