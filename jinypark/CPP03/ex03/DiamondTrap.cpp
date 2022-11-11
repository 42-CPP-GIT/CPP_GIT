/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:49 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/11 09:51:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap: default has been constructed.\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: " + this->name_ + " has been destructed.\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	// ClapTrap::name_ = name + "_clap_trap";
	this->name_ = name;
	// this->hitPoint_ = 100;
	// this->energyPoint_ = 100;
	// this->attackDamage_ = 30;
	std::cout << "DiamondTrap: " + this->name_ + " has been constructed.\n";
}

void	DiamondTrap::attack(const std::string& target)
{
	if (this->energyPoint_ > 0)
	{
		--this->energyPoint_;
		std::cout << "DiamondTrap: " + name_ + " attacks " + target + ", causing "
		<< attackDamage_ << " points of damage!\n";
	}
	else
		std::cout << "DiamondTrap: Not enough energy...\n";
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ > 0)
	{
		this->hitPoint_ -= amount;
		std::cout << "DiamondTrap: " + this->name_ + " takes " << amount << " damage!\n";
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint_ > 0 && this->hitPoint_ > 0)
	{
		this->hitPoint_ += amount;
		--this->energyPoint_;
		std::cout << "DiamondTrap: " + name_ + " is repaired " << amount << " hits point!\n" ;
	}
}

std::string	DiamondTrap::getName(void) const
{
	return (this->name_);
}
unsigned int	DiamondTrap::getHitPoint(void) const
{
	return (this->hitPoint_);
}

unsigned int	DiamondTrap::getEnergyPoint(void) const
{
	return (this->energyPoint_);
}

unsigned int	DiamondTrap::getAttackDamage(void) const
{
	return (this->attackDamage_);
}


void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap: I am " + this->name_ + "\n";
	std::cout << "DiamondTrap: My grandparent is " + ClapTrap::name_ + "\n";
}

void			DiamondTrap::printStat(void)
{
	std::cout << "-------------------------------\n";
	std::cout << "NAME: " << this->name_ << "\n";
	std::cout << "HP  : " << this->hitPoint_ << "\n";
	std::cout << "EP  : " << this->energyPoint_ << "\n";
	std::cout << "AD  : " << this->attackDamage_ << "\n";
	std::cout << "-------------------------------\n";
}
