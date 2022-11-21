/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:02:04 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 22:45:35 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoint(10), _attackDamage(0), _energyPoints(10)
{
	std::cout << "ClapTrap " << this -> _name << " is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this -> _name << " is destructed " << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &copy)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& c)
{
	std::cout << " = Constructor" << std::endl;
	if (this != &c)
	{
		_name = c._name;
		_hitPoint = c._hitPoint;
		_attackDamage = c._attackDamage;
		_energyPoints = c._energyPoints;
	}
	return (*this);
}

void	ClapTrap::attack( const std::string& target )
{
	if (this -> _energyPoints <= 0)
	{
		std::cout << "no energy points" << std::endl;
		return ;
	}
	this->_energyPoints --;
	std::cout << "ClapTrap " << this -> _name
		<< " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	this -> _hitPoint -= amount;
	std::cout << this -> _name << " get damaged " << amount << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this -> _energyPoints <= 0)
	{
		std::cout << "no energy points" << std::endl;
		return ;
	}
	this -> _energyPoints --;
	std::cout << this -> _name << " get repaired " << amount << std::endl;
}

int	ClapTrap::getHitpoint( void ) const
{
	return (this -> _hitPoint);
}

int	ClapTrap::getEnergyPoints( void ) const 
{
	return (this -> _energyPoints);
}

int ClapTrap::getAttackDamage ( void ) const 
{
	return (this -> _attackDamage);
}

std::string ClapTrap::getName ( void ) const 
{
	return (this -> _name);
}

void	ClapTrap::setHitpoint( int a )
{
	this -> _hitPoint = a;
}

void	ClapTrap::setEnergyPoints( int a )
{
	this -> _energyPoints = a;
}

void	ClapTrap::setAttackDamage( int a )
{
	this -> _attackDamage = a;
}

void	ClapTrap::setName( std::string name )
{
	this -> _name = name;
}
