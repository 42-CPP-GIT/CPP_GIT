/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:16:08 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 11:21:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("default", 100, 50, 20), _isGateKeeperMode(false)
{
	std::cout << "[ScavTrap constructor called]" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20), _isGateKeeperMode(false)
{
	std::cout << "[ScavTrap constructor called]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	std::cout << "[ScavTrap Copy constructor called]" << std::endl;
	this->_health = scavTrap.getHealth();
	this->_energyPoint = scavTrap.getEnergy();
	this->_attackDamage = scavTrap.getAttackDamage();
	this->_name = scavTrap.getName();
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap destructor called]" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &source)
{
	std::cout << "[ScavTrap Copy assignment oprator called]" << std::endl;
	if (this == &source) // prevent self-assignment
		return (*this);
	else
	{
		this->_health = source.getHealth();
		this->_energyPoint = source.getEnergy();
		this->_attackDamage = source.getAttackDamage();
		this->_name = source.getName();
	}
	return (*this);
}

void ScavTrap::printStatus(void)
{
	std::cout << "===status=============================" << std::endl;
	std::cout << "name : " << this->getName() << std::endl;
	std::cout << "HP : " << this->getHealth() << std::endl;
	std::cout << "Energy : " << this->getEnergy() << std::endl;
	std::cout << "AttackDamage : " << this->getAttackDamage() << std::endl;
	std::cout << "GateKeeperMode : " << this->getIsGateKeeperMode() << std::endl;
	std::cout << "======================================" << std::endl;
}

const bool& ScavTrap::getIsGateKeeperMode(void)
{
	return (this->_isGateKeeperMode);
}

void ScavTrap::setIsGateKeeperMode(bool isGateKeeperMode)
{
	this->_isGateKeeperMode = isGateKeeperMode;
}

void ScavTrap::guardGate(void)
{
	this->setIsGateKeeperMode(true);
	std::cout << ">> ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->actionIsValid("attack"))
		return ;
	this->_energyPoint--;
	std::cout << ">> ScavTrap " << this->getName() <<" attacks " << target << ", causing " \
			<< this->getAttackDamage() << " points of damage!" << std::endl;
}
