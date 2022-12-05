/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:16:38 by sesim             #+#    #+#             */
/*   Updated: 2022/12/05 12:38:30 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), name_("Default")
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	ClapTrap::name_ = this->name_ + "_clap_name";
	this->attack_damage_ = 30;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name), name_(name)
{
	std::cout << "DiamondTrap " << this->name_ << " Custom Constructor called" << std::endl;
	ClapTrap::name_ = this->name_ + "_clap_name";
	this->attack_damage_ = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : FragTrap(obj), ScavTrap(obj)
{
	std::cout << "Diamond Copy Constructor called" << std::endl;
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this == &obj)
		return (*this);
	this->hit_point_ = obj.hit_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "+-------------------- Who am I ---------------------+\n";
	std::cout << "DiamondTrap Name : " << this->name_ << "\n";
	std::cout << "ClapTrap Name    : " << ClapTrap::name_ << std::endl;
	std::cout << "+----------------------------------------------------\n";
}

void	DiamondTrap::printInfo() const
{
	std::cout << "+----------------[DiamondTrap Status]----------------\n";
	std::cout << "| NAME          : " << this->name_ << "\n";
	std::cout << "| HIT POINT     : " << this->hit_point_ << "\n";
	std::cout << "| ENERGY POINT  : " << this->energy_point_ << "\n";
	std::cout << "| ATTACK DAMAGE : " << this->attack_damage_ << "\n";
	std::cout << "+----------------------------------------------------\n";
}
