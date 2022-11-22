/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:12:04 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 23:08:54 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this -> getName() << " is created" << std::endl;
	this -> setHitpoint(100);
	this -> setEnergyPoints(50);
	this -> setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this -> getName() << " is destructed" << std::endl;
}

ScavTrap::ScavTrap ( const ScavTrap &copy ) : ClapTrap("temp")
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &s )
{
	std::cout << " =  Constructor" << std::endl;
	if (this != &s)
	{
		this -> setName(s.getName());
		this -> setHitpoint(s.getHitpoint());
		this -> setAttackDamage(s.getAttackDamage());
		this -> setEnergyPoints(s.getEnergyPoints());
	}
	return (*this);
}

void	ScavTrap::guardGate( void )
{
	std::cout << this->getName() <<  " is now in Gatekeeper mode " << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (this -> getEnergyPoints() <= 0)
	{
		std::cout << "no energy points" << std::endl;
		return ;
	}
	this -> setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << "this is ScavTrap's Attack fun" << std::endl;
	std::cout << "ScavTrap " << this -> getName()
		<< " attacks " << target << ", causing " << this->getAttackDamage()
		<< " points of damage!" << std::endl;
}
