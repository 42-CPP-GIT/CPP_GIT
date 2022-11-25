/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:05 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/16 09:21:47 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RESET "\033[0m"
#define IT "\e[0;3m"
#define RED "\e[0;31m"
#define GRN "\e[0;33m"
#define C_HP 10
#define S_HP 100
#define F_HP 100

class ClapTrap
{
protected:
	std::string	_name;
	int 		_hitPoint;
	int 		_energyPoint;
	int 		_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hitPoint, unsigned int energyPoint, unsigned int attackDamge);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	virtual ~ClapTrap();
	virtual void attack(const std::string& target);
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