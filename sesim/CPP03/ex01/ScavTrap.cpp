/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:23:39 by sesim             #+#    #+#             */
/*   Updated: 2022/12/05 12:29:04 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "ScavTrap Default Constructor called" << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap Custom Constructor called" << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.name_;
	this->hit_point_ = obj.hit_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destrouctor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->hit_point_)
	{
		std::cout << "ScavTrap " << this->name_ << \
		" is dead. So can't attack to " << target << "." << std::endl;
		return ;
	}
	else if (!this->energy_point_)
	{
		std::cout << "ScavTrap " << this->name_ << \
		" has no energy point. So can't attack to " << \
		target << "." << std::endl;
		return ;
	}
	--this->energy_point_;
	std::cout << "ScavTrap " << this->name_ << \
	" attacks " << target << ", causing " << \
	this->attack_damage_ << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name_ << " is in guard mode!" << std::endl;
}

void	ScavTrap::printInfo(void) const
{
	std::cout << "+----------------[ScavTrap Status]----------------\n";
	std::cout << "| NAME          : " << this->name_ << "\n";
	std::cout << "| HIT POINT     : " << this->hit_point_ << "\n";
	std::cout << "| ENERGY POINT  : " << this->energy_point_ << "\n";
	std::cout << "| ATTACK DAMAGE : " << this->attack_damage_ << "\n";
	std::cout << "+-------------------------------------------------\n";
}
