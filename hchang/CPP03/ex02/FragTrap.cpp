/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:24:43 by hchang            #+#    #+#             */
/*   Updated: 2022/11/16 13:13:57 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30)
{
	std::cout << "[FragTrap default constructor called]" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "[FragTrap string constructor called]" << std::endl;
	this->_name = name;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "[FragTrap copy constructor called]" << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	if (this == &obj)
		return *this;
	this->_name = obj._name;
	this->_attackDamage = obj._attackDamage;
	this->_energyPoint = obj._energyPoint;
	this->_hitPoint = obj._hitPoint;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap destructor called]" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << IT "    [" << this->_name << "] : HIGH FIVE GUYS!!!!!! " RESET<<std::endl;
}

void	FragTrap::printTrapInfo(void)
{
	std::cout << "=====================[FragTrap Trap Info]=====================" IT<< std::endl;
	std::cout << "    ► Name          : " << this->_name << std::endl;
	std::cout << "    ► Hit Point     : " << this->_hitPoint << std::endl;
	std::cout << "    ► Energy Point  : " << this->_energyPoint << std::endl;
	std::cout << "    ► Attack Damage : " << this->_attackDamage << std::endl;
	std::cout <<RESET "=============================================================" << std::endl;
}
