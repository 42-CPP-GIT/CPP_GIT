/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:23:39 by sesim             #+#    #+#             */
/*   Updated: 2022/12/08 08:56:37 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name_("Default"), hit_point_(10), energy_point_(10), attack_damage_(0)
{
	std::cout << "ClapTrap " << this->name_ << " Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hit_point_(10), energy_point_(10), attack_damage_(0)
{
	std::cout << "ClapTrap " << this->name_ << " Custom Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.name_;
	this->hit_point_ = obj.hit_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->hit_point_)
	{
		std::cout << "ClapTrap " << this->name_ << \
		" is dead. So can't attack to " << target << "." << std::endl;
		return ;
	}
	else if (!this->energy_point_)
	{
		std::cout << "ClapTrap " << this->name_ << \
		" has no energy point. So can't attack to " << \
		target << "." << std::endl;
		return ;
	}
	--this->energy_point_;
	std::cout << "ClapTrap " << this->name_ << \
	" attacks " << target << ", causing " << \
	this->attack_damage_ << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hit_point_)
	{
		std::cout << "ClapTrap " << this->name_ << \
		" is already dead" << std::endl;
		return ;
	}
	else if (amount >= INT_MAX)
	{
		this->hit_point_ = 0;
		std::cout << "ClapTrap " << this->name_ << \
		" is SMASHED!" << std::endl;
		return ;
	}
	this->hit_point_ -= amount;
	if (this->hit_point_ < 0)
		this->hit_point_ = 0;
	std::cout << "ClapTrap " << this->name_ << " take " << amount << \
	" damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hit_point_)
	{
		std::cout << "ClapTrap " << this->name_ << \
		" is dead. So can't repair!" << std::endl;
		return ;
	}
	else if (!amount)
	{
		std::cout << "err: no repair amount!" << std::endl;
		return ;
	}
	else if (!this->energy_point_)
	{
		std::cout << "ClapTrap " << this->name_ << \
		" has no energy point. So can't repair!" << std::endl;
		return ;
	}
	else if (this->hit_point_ >= MAX_HP)
	{
		std::cout << "ClapTrap " << this->name_ << \
		" is already full HP!" << std::endl;
		return ;
	}
	--this->energy_point_;
	if (amount >= INT_MAX)
	{
		this->hit_point_ = MAX_HP;
		std::cout << "ClapTrap " << this->name_ << \
		" is POWER OVERWHELMING!!" << std::endl;
	}
	else if (static_cast<unsigned int>(MAX_HP - this->hit_point_) < amount)
	{
		this->hit_point_ = MAX_HP;
		std::cout << "ClapTrap " << this->name_ << " repair " << \
		MAX_HP - this->hit_point_ << " hit points.\n" << \
		this->name_ << "'s HP is " << this->hit_point_ << "!" << std::endl;
	}
	else
	{
		this->hit_point_ += amount;
		std::cout << "ClapTrap " << this->name_ << " repair " << \
		amount << " hit points.\n" << \
		this->name_ << "'s HP is " << this->hit_point_ << "!" << std::endl;
	}
}
