/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:10:45 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/09 20:09:49 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);
	Zombie *array_zom = new Zombie[N];

	for (int i = 0; i < N ; i++) {
		stringstream index_ss(i);
		if (index_ss.fail())
			return ;
		int idx;
		index_stream >> idx;
	}

	return (array_zom);
}
int a = 10;
ss << a;
string str = ss.str();
