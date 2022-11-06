/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:03:55 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/06 21:15:54 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	Zombie zombie(name);

	zombie.announce();
}

// void	Zombie::randomChump(std::string name)
// {
// 	Zombie	*zombie = new Zombie(name);

// 	zombie->announce();
// 	delete zombie;
// }
