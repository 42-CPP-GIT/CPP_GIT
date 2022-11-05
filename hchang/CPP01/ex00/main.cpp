/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:22:06 by hchang            #+#    #+#             */
/*   Updated: 2022/11/01 11:30:52 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie_ptr;

    zombie_ptr = newZombie("Heap Zombie");
    randomChump("Stack Zombie");

    delete zombie_ptr;
}
