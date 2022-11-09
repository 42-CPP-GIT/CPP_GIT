/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:05 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/08 23:34:20 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string	&name;


public:
	ClapTrap();
	ClapTrap(std::string &name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

// claptrap a.attacts { (target) lose attact damage }

//When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
//When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
//cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
//or energy points left.
//5
//C++ - Module 03 Inheritance
//In all of these member functions, you have to print a message to describe what happens. For example, the attack() function may display something like (of course, without
//the angle brackets):
//ClapTrap <name> attacks <target>, causing <damage> points of damage!