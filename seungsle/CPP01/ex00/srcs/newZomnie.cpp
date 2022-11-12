/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZomnie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:26:38 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/12 18:27:00 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}
