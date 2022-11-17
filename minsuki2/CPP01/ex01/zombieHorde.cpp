/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:10:45 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/17 12:35:01 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);
	Zombie *array_zom = new Zombie[N];

	for (int i = 0; i < N ; i++) {
		std::stringstream index_ss;
		// if (index_ss.fail())
		//     return ;
		index_ss << i;
		std::string index_str = index_ss.str();
		array_zom[i].setZombieName(name + index_str);
	}
	return (array_zom);
}
