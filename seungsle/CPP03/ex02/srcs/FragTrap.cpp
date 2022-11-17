/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:16:08 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 11:21:23 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(): ClapTrap("default", 100, 100, 30)
{
	std::cout << "[FragTrap constructor called]" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "[FragTrap constructor called]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap)
{
	std::cout << "[FragTrap Copy constructor called]" << std::endl;
	this->_health = FragTrap.getHealth();
	this->_energyPoint = FragTrap.getEnergy();
	this->_attackDamage = FragTrap.getAttackDamage();
	this->_name = FragTrap.getName();
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap destructor called]" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &source)
{
	std::cout << "[FragTrap Copy assignment oprator called]" << std::endl;
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

// void FragTrap::printStatus(void)
// {
// 	std::cout << "===status=============================" << std::endl;
// 	std::cout << "name : " << this->getName() << std::endl;
// 	std::cout << "HP : " << this->getHealth() << std::endl;
// 	std::cout << "Energy : " << this->getEnergy() << std::endl;
// 	std::cout << "AttackDamage : " << this->getAttackDamage() << std::endl;
// 	std::cout << "======================================" << std::endl;
// }

void FragTrap::highFivesGuys(void)
{
	std::cout << ">> highFive Requested" << std::endl;
}