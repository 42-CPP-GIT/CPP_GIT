/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:29 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/20 00:16:20 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "[ClapTrap] default constructor has been called.\n";
}

ClapTrap::ClapTrap(std::string name) : name_(name), hitPoint_(CLAP_HP), energyPoint_(CLAP_EP), attackDamage_(CLAP_AD)
{
	std::cout << "[ClapTrap] " + this->name_ + " constructor has been called.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] " + this->name_ + " destructor has been called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &obj)
{
	if (this != &obj)
	{
		this->name_ = obj.name_;
		this->hitPoint_ = obj.hitPoint_;
		this->energyPoint_ = obj.energyPoint_;
		this->attackDamage_ = obj.attackDamage_;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoint_ > 0)
	{
		--this->energyPoint_;
		std::cout << name_ + " attacks " + target + ", causing "
		<< attackDamage_ << " points of damage!\n";
	}
	else
		std::cout << "Not enough energy...\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ > 0)
	{
		this->hitPoint_ -= amount;
		std::cout << "[ClapTrap] " + this->name_ + " takes " << amount << " damage!\n";
	}
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint_ > 0 && this->hitPoint_ > 0)
	{
		this->hitPoint_ += amount;
		--this->energyPoint_;
		std::cout << "[ClapTrap] " + this->name_ + " is repaired " << amount << " hits point!\n";
	}
}

std::string		ClapTrap::getName(void) const
{
	return (this->name_);
}
unsigned int	ClapTrap::getHitPoint(void) const
{
	return (this->hitPoint_);
}

unsigned int	ClapTrap::getEnergyPoint(void) const
{
	return (this->energyPoint_);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage_);
}

void			ClapTrap::printStat(void)
{
	std::cout << "-------------------------------\n";
	std::cout << "NAME: " << this->name_ << "\n";
	std::cout << "HP  : " << this->hitPoint_ << "\n";
	std::cout << "EP  : " << this->energyPoint_ << "\n";
	std::cout << "AD  : " << this->attackDamage_ << "\n";
	std::cout << "-------------------------------\n";
}