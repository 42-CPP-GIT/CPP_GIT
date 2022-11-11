/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:49 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/11 10:21:47 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: default has been constructed.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " + this->name_ + " has been destructed.\n";
}

ScavTrap::ScavTrap(std::string name)
{
	this->name_ = name;
	this->hitPoint_ = 100;
	this->energyPoint_ = 50;
	this->attackDamage_ = 20;
	std::cout << "ScavTrap: " + this->name_ + " has been constructed.\n";
}

void			ScavTrap::attack(const std::string& target)
{
	if (this->energyPoint_ > 0)
	{
		--this->energyPoint_;
		std::cout << "ScavTrap: " + name_ + " attacks " + target + ", causing "
		<< attackDamage_ << " points of damage!\n";
	}
	else
		std::cout << "ScavTrap: Not enough energy...\n";
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ > 0)
	{
		this->hitPoint_ -= amount;
		std::cout << "ScavTrap: " + this->name_ + " takes " << amount << " damage!\n";
	}
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint_ > 0 && this->hitPoint_ > 0)
	{
		this->hitPoint_ += amount;
		--this->energyPoint_;
		std::cout << "ScavTrap: " + name_ + " is repaired " << amount << " hits point!\n" ;
	}
}

std::string		ScavTrap::getName(void) const
{
	return (this->name_);
}
unsigned int	ScavTrap::getHitPoint(void) const
{
	return (this->hitPoint_);
}

unsigned int	ScavTrap::getEnergyPoint(void) const
{
	return (this->energyPoint_);
}

unsigned int	ScavTrap::getAttackDamage(void) const
{
	return (this->attackDamage_);
}


void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " + this->name_ + " [GATE GUARD..]\n";
}
