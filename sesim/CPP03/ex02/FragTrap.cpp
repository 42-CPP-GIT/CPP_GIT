/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:23:39 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 20:29:20 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap Default Constructor called" << std::endl; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Custom Constructor called" << std::endl; 
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.name_;
	this->hit_point_ = obj.hit_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destrouctor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name_ << " is waiting for Highfive!" << std::endl;
}

void	FragTrap::printInfo(void) const
{
	std::cout << "+----------------[FragTrap Status]----------------\n";
	std::cout << "| NAME          : " << this->name_ << "\n";
	std::cout << "| HIT POINT     : " << this->hit_point_ << "\n";
	std::cout << "| ENERGY POINT  : " << this->energy_point_ << "\n";
	std::cout << "| ATTACK DAMAGE : " << this->attack_damage_ << "\n";
	std::cout << "+-------------------------------------------------\n";
}
