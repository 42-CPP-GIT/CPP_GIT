/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:00:30 by hchang            #+#    #+#             */
/*   Updated: 2022/11/01 11:17:35 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie		*newZombie(std::string name)
{   
    Zombie *zombie = new Zombie(name);
    return (zombie);
}
