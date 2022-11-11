/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:49 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/11 11:17:01 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap: default has been constructed.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " + this->name_ + " has been destructed.\n";
}

FragTrap::FragTrap(std::string name)
{
	this->name_ = name;
	this->hitPoint_ = 100;
	this->energyPoint_ = 100;
	this->attackDamage_ = 30;
	std::cout << "FragTrap: " + this->name_ + " has been constructed.\n";
}

void			FragTrap::attack(const std::string& target)
{
	if (this->energyPoint_ > 0)
	{
		--this->energyPoint_;
		std::cout << "FragTrap: " + name_ + " attacks " + target + ", causing "
		<< attackDamage_ << " points of damage!\n";
	}
	else
		std::cout << "FragTrap: Not enough energy...\n";
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ > 0)
	{
		this->hitPoint_ -= amount;
		std::cout << "FragTrap: " + this->name_ + " takes " << amount << " damage!\n";
	}
}

void			FragTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint_ > 0 && this->hitPoint_ > 0)
	{
		this->hitPoint_ += amount;
		--this->energyPoint_;
		std::cout << "FragTrap: " + name_ + " is repaired " << amount << " hits point!\n" ;
	}
}

std::string		FragTrap::getName(void) const
{
	return (this->name_);
}
unsigned int	FragTrap::getHitPoint(void) const
{
	return (this->hitPoint_);
}

unsigned int	FragTrap::getEnergyPoint(void) const
{
	return (this->energyPoint_);
}

unsigned int	FragTrap::getAttackDamage(void) const
{
	return (this->attackDamage_);
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " + this->name_ + " HIGHFIVE!\n";
}
