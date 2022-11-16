/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:03:11 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/16 08:55:53 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "[default constructor called]" << std::endl;
	this->_name = "default";
}

ClapTrap::ClapTrap(std::string name) : _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "[string constructor called]" << std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "[copy constructor called]" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this == &obj)
		return *this;
	this->_attackDamage = obj._attackDamage;
	this->_energyPoint = obj._energyPoint;
	this->_hitPoint = obj._hitPoint;
	this->_name = obj._name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[destructor called]" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	// energy point 나 hit point가 없으면 아무것도 못한다.
	// target이 attack damage만큼 hit point를 잃는다.
	// energy point 하나 잃는다
	std::cout << RED"[ANNOUNCEMENT] ";
	if (!this->_energyPoint)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack." \
		<< " because not enongh energy Point"RESET<< std::endl;
		return ;
	}
	else if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack." \
		<< " because not enongh hit Point" RESET<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target \
	<< ", causing " << this->_attackDamage << " points of damage!" RESET << std::endl;
	this->_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	// energy point 나 hit point가 없으면 아무것도 못한다.
	std::cout << RED"[ANNOUNCEMENT] ";
	std::cout << "ClapTrap " << this->_name << " take "<< amount << " damage! "<< std::endl;
	std::cout <<IT "     [" << this->_name << "] : I can see... the code" RESET<< std::endl;
	this->_hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	// energy point 나 hit point가 없으면 아무것도 못한다.
	// amount만큼 hit point를 얻는디
	// energy point 하나 잃는다
	std::cout << RED"[ANNOUNCEMENT] ";
	if (!this->_energyPoint)
	{
		std::cout << "ClapTrap " << this->_name << " can't repaire." \
		<< " because not enongh energy Point" RESET<< std::endl;
		return ;
	}
	else if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't repaire." \
		<< " because not enongh hit Point" RESET<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repaired itself! " \
	<< "ClapTrap " << this->_name << "'s hit points " << amount << " up!" RESET << std::endl;
	if (this->_hitPoint + amount >= C_HP)
		this->_hitPoint = C_HP;
	else
		this->_hitPoint += amount;
	this->_energyPoint--;
}

void	ClapTrap::printTrapInfo(void)
{
	std::cout << "=====================[ClapTrap Trap Info]=====================" IT<< std::endl;
	std::cout << "    ► Name          : " << this->_name << std::endl;
	std::cout << "    ► Hit Point     : " << this->_hitPoint << std::endl;
	std::cout << "    ► Energy Point  : " << this->_energyPoint << std::endl;
	std::cout << "    ► Attack Damage : " << this->_attackDamage << std::endl;
	std::cout <<RESET "=============================================================" << std::endl;
}
