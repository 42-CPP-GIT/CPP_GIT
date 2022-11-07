/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:12 by hchang            #+#    #+#             */
/*   Updated: 2022/11/05 15:49:37 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z_horde = zombieHorde(5, "hchang");

	z_horde[2].announce();
	z_horde[3].announce();

	delete [] z_horde;
}
