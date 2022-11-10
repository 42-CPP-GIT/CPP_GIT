/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:38:26 by hchang            #+#    #+#             */
/*   Updated: 2022/11/10 16:32:40 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std::cout << "[DiamondTrap default constructor called]" << std::endl;
	
	_name = "default";
	ClapTrap::_name = _name + "_clap_name";
	this->_attackDamage = 30;	
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << "[DiamondTrap string constructor called]" << std::endl;
	
	_name = name;
	this->_attackDamage = 30;
	ClapTrap::_name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : FragTrap(obj), ScavTrap(obj)
{
	std::cout << "[DiamondTrap copy constructor called]" << std::endl;
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this == &obj)
		return (*this);
	_hitPoint = obj._hitPoint;
	_energyPoint = obj._energyPoint;
	_attackDamage = obj._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap destructor called]" << std::endl;

}

void DiamondTrap::whoAmI(void)
{
	std::cout <<RED "    [ " << this->_name << " / ??? ] : 에드워드 .... 오빠 ..... 놀자 ......." RESET << std::endl;
}

void	DiamondTrap::printTrapInfo(void)
{
	std::cout << "=====================[Diamond Trap Info]=====================" IT<< std::endl;
	std::cout << "    ► Name          : " << this->_name << std::endl;
	std::cout << "    ► Hit Point     : " << this->_hitPoint << std::endl;
	std::cout << "    ► Energy Point  : " << this->_energyPoint << std::endl;
	std::cout << "    ► Attack Damage : " << this->_attackDamage << std::endl;
	std::cout <<RESET "=============================================================" << std::endl;
}