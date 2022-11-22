/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:52:17 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/08 21:46:12 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap " << this -> getName() << " is created" << std::endl;
	this -> setHitpoint(100);
	this -> setEnergyPoints(100);
	this -> setAttackDamage(30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this -> getName() << " is destructed" << std::endl;
}

FragTrap::FragTrap ( const FragTrap &copy ) : ClapTrap("temp")
{
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=( const FragTrap &s )
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

void	FragTrap::highFivesGuys( void )
{
	std::cout << getName() << " high Fives Guys?" << std::endl;
}
