/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:22:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 11:21:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _health(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "[ClapTrap Constructor called]" << std::endl;
	setName("default");
}

ClapTrap::ClapTrap(std::string name): _health(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "[ClapTrap Constructor called]" << std::endl;
	setName(name);
}

ClapTrap::ClapTrap(std::string name, int health, int energy, int damage): _health(health), _energyPoint(energy), _attackDamage(damage), _name(name)
{
	std::cout << "[ClapTrap Constructor called]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "[ClapTrap Copy constructor called]" << std::endl;
	this->_health = clapTrap.getHealth();
	this->_energyPoint = clapTrap.getEnergy();
	this->_attackDamage = clapTrap.getAttackDamage();
	this->_name = clapTrap.getName();
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap destructor called]" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &source)
{
	std::cout << "[ClapTrap Copy assignment oprator called]" << std::endl;
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

void ClapTrap::attack(const std::string& target)
{
	if (!this->actionIsValid("attack"))
		return ;
	this->_energyPoint--;
	std::cout << ">> ClapTrap " << this->getName() <<" attacks " << target << ", causing " \
			<< this->getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->actionIsValid("takeDamage"))
		return ;
	this->_energyPoint--;
	this->setAttackDamage(amount);
	std::cout << ">> ClapTrap " << this->getName() << " takes " << amount << " damage power!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->actionIsValid("beRepaired"))
		return ;
	this->_health += amount;
	this->_energyPoint--;
	std::cout << ">> ClapTrap " << this->getName() << " repaired " << amount << " HP!" << std::endl;
}

void ClapTrap::printStatus(void)
{
	std::cout << "===status=============================" << std::endl;
	std::cout << "name : " << this->getName() << std::endl;
	std::cout << "HP : " << this->getHealth() << std::endl;
	std::cout << "Energy : " << this->getEnergy() << std::endl;
	std::cout << "AttackDamage : " << this->getAttackDamage() << std::endl;
	std::cout << "======================================" << std::endl;
}

bool ClapTrap::actionIsValid(std::string action)
{
	if ((this->getHealth() > 0) && (this->getEnergy() > 0))
		return (true);
	else if (this->getHealth() <= 0)
		return (errorPrint(action, 0));
	else if (this->getEnergy() <= 0)
		return (this->errorPrint(action, 1));
	else
		return false;
}

bool ClapTrap::errorPrint(std::string action, int flag)
{
	if (flag == 0)
		std::cout << ">> [!!] not enough HP(";
	else
		std::cout << ">> [!!] not enough Energy(";
	std::cout << action << " is dinied)" << std::endl;
	return false;
}

const int& ClapTrap::getHealth(void) const
{
	return (this->_health);
}

const int& ClapTrap::getEnergy(void) const
{
	return (this->_energyPoint);
}

const int& ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

const std::string& ClapTrap::getName(void) const
{
	return (this->_name);
}

void ClapTrap::setHealth(const int health)
{
	this->_health = health;
}

void ClapTrap::setEnergy(const int energy)
{
	this->_energyPoint = energy;
}

void ClapTrap::setAttackDamage(const int damage)
{
	this->_attackDamage = damage;
}

void ClapTrap::setName(const std::string name)
{
	this->_name = name;
}