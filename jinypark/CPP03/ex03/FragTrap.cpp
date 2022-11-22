/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:49 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/20 00:04:44 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "[FragTrap] default constructor has been called.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " + this->name_ + " destructor has been called.\n";
}

FragTrap::FragTrap(std::string name)
{
	this->name_ = name;
	this->hitPoint_ = FRAG_HP;
	this->energyPoint_ = FRAG_EP;
	this->attackDamage_ = FRAG_AD;
	std::cout << "[FragTrap] " + this->name_ + " constructor has been called.\n";
}

FragTrap::FragTrap(const FragTrap &obj)
{
	*this = obj;
}

FragTrap	&FragTrap::operator=(FragTrap const &obj)
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " + this->name_ + ": Gimme five!\n";
}
