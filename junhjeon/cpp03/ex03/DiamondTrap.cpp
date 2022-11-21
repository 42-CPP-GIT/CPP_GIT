/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:55:21 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:23:10 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap " << name << " is created" << std::endl;
	DiamondTrap::_name = name;
	DiamondTrap::setName(name + "_clap_name");
	DiamondTrap::setHitpoint(100);
	DiamondTrap::setEnergyPoints(50);
	DiamondTrap::setAttackDamage(30);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this -> getName() << " is destructed" << std::endl;
}

DiamondTrap::DiamondTrap ( const DiamondTrap& copy ) : FragTrap("temp"), ScavTrap("temp")
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator = ( const DiamondTrap& d)
{
	std::cout << " =  Constructor" << std::endl;
	if (this != &d)
	{
		this -> setName(d.getName());
		this -> setHitpoint(d.FragTrap::getHitpoint());
		this -> setAttackDamage(d.FragTrap::getAttackDamage());
		this -> setEnergyPoints(d.ScavTrap::getEnergyPoints());
	}
	return (*this);
}

void	DiamondTrap::attack ( const std::string& target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI ( void )
{
	std::cout << "I AM both " << _name << " and " << FragTrap::getName() << std::endl;
}

