/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:49 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/11 09:51:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "[DiamondTrap] default constructor has been called.\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] " + this->name_ + " destructor has been called.\n";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), name_(name)
{
	ClapTrap::name_ = name + "_clap_name";
	this->energyPoint_ = SCAV_EP;
	std::cout << "[DiamondTrap] " + this->name_ + " constructor has been called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
	*this = obj;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &obj)
{
	if (this != &obj)
	{
		this->name_ = obj.name_;
		this->hitPoint_ = obj.hitPoint_;
		this->energyPoint_ = obj.energyPoint_;
		this->attackDamage_ = obj.attackDamage_;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap] I am " + this->name_ + "\n";
	std::cout << "[DiamondTrap] My grandparent is " + ClapTrap::name_ + "\n";
}
