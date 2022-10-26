/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:49:49 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/26 12:17:48 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main()
{
	Zombie zombie;
	
	zombie.randomChump("Alvin");
	zombie.randomChump("John");
	zombie.announce();
}