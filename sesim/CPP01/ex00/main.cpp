/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:59 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 14:24:00 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie;

	heap_zombie = newZombie("Heap");
	heap_zombie->announce();
	randomChump("Stack");
	delete heap_zombie;
	heap_zombie = NULL;
	return (0);
}