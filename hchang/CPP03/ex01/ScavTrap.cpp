/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:56:58 by hchang            #+#    #+#             */
/*   Updated: 2022/11/10 14:24:16 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20)
{
	std::cout << "[ScavTrap default constructor called]" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "[ScavTrap string constructor called]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "[ScavTrap copy constructor called]" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this == &obj)
		return *this;
	this->_name = obj._name;
	this->_attackDamage = obj._attackDamage;
	this->_energyPoint = obj._energyPoint;
	this->_hitPoint = obj._hitPoint;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap destructor called]" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << IT "    [" << this->_name << "] : You Shall Not Passssssssssssssssssssss!" RESET<<std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	// energy point 나 hit point가 없으면 아무것도 못한다.
	// target이 attack damage만큼 hit point를 잃는다.
	// energy point 하나 잃는다
	std::cout << RED"[ANNOUNCEMENT] ";
	if (!this->_energyPoint)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack." \
		<< " because not enongh energy Point"RESET<< std::endl;
		return ;
	}
	else if (!this->_hitPoint)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack." \
		<< " because not enongh hit Point" RESET<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target \
	<< ", causing " << this->_attackDamage << " points of damage!" RESET << std::endl;
	this->_energyPoint--;
}