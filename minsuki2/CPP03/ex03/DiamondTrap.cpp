/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 17:37:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

const std::string& DiamondTrap::getName() const { return this->name_; }
const unsigned int& DiamondTrap::getAttackDamage() const { return this->attack_damage_; }

void	DiamondTrap::changeMaxValue_(void) {
	ClapTrap::limit_hp_ = FT_MAX_HP;
	ClapTrap::limit_ep_ = ST_MAX_EP;
	ClapTrap::limit_ad_ = FT_MAX_AD;
}

void	DiamondTrap::inputMemberValue_(const DiamondTrap& obj) {
	this->name_ = obj.name_;
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
}

DiamondTrap::DiamondTrap(void) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_DIAMONDTRAP_BORN << RESET<< std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_("Unknow");
	ClapTrap::name_ += "_clap_name";
	this->name_ = "Unknow";
}

DiamondTrap::DiamondTrap(const std::string& name) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_DIAMONDTRAP_BORN << RESET << std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_(name);
	ClapTrap::name_ += "_clap_name";
	this->name_ = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) {//: ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_DIAMONDTRAP_BORN << RESET << std::endl;
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
	ClapTrap::name_ += "_clap_name";
	this->name_ = obj.name_;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
	ClapTrap::name_ += "_clap_name";
	this->name_ = obj.name_;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' \
			  << MSG_DIAMONDTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		DiamondTrap::whoAmI(void) {
	std::cout << BOLDCYAN << "--------------" << "[ Compare ]"<< "--------------" << std::endl;
	std::cout << "⦁ " << "ClapTrap\t: " << ClapTrap::name_ << std::endl;
	std::cout << "⦁ " << "DiamondTrap\t: " << this->name_ << std::endl;
	std::cout << "---------------------------------------\n" << RESET << std::endl;
}
