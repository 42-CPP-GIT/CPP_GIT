/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:49 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/20 00:33:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "[ScavTrap] default constructor has been called.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " + this->name_ + " destructor has been called.\n";
}

ScavTrap::ScavTrap(std::string name)
{
	this->name_ = name;
	this->hitPoint_ = SCAV_HP;
	this->energyPoint_ = SCAV_EP;
	this->attackDamage_ = SCAV_AD;
	std::cout << "[ScavTrap] " + this->name_ + " constructor has been called.\n";
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	*this = obj;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &obj)
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

void	ScavTrap::attack(const std::string& target)
{
	if (this->energyPoint_ > 0)
	{
		--this->energyPoint_;
		std::cout << "[ScavTrap] " + name_ + " attacks " + target + ", causing "
		<< attackDamage_ << " points of damage!\n";
	}
	else
		std::cout << "[ScavTrap] Not enough energy...\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap] " + this->name_ + ": Guarding gates is FUN!\n";
}
