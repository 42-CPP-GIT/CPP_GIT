/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 23:27:42 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

const std::string& DiamondTrap::getName() const { return this->name_; }
const unsigned int& DiamondTrap::getAttackDamage() const { return this->attack_damage_; }

void	DiamondTrap::changeMaxValue_(void) {
	ClapTrap::max_hp_ = FT_MAX_HP;
	ClapTrap::max_ep_ = ST_MAX_EP;
	ClapTrap::max_ad_ = FT_MAX_AD;
}

DiamondTrap::DiamondTrap(void) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_DIAMONDTRAP_BORN << RESET<< std::endl;
	changeMaxValue_();
	this->name_ = "Unknow";
	ClapTrap::name_ = name_ + "_clap_name";
	this->health_point_ = max_hp_;
	this->energy_point_ = max_ep_;
	this->attack_damage_ = max_ad_;
}

DiamondTrap::DiamondTrap(const std::string& name) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_DIAMONDTRAP_BORN << RESET << std::endl;
	changeMaxValue_();
	this->name_ = name;
	ClapTrap::name_ = name_ + "_clap_name";
	this->health_point_ = max_hp_;
	this->energy_point_ = max_ep_;
	this->attack_damage_ = max_ad_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_DIAMONDTRAP_BORN << RESET << std::endl;
	changeMaxValue_();
	this->name_ = obj.name_;
	ClapTrap::name_ = name_ + "_clap_name";
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	this->name_ = obj.name_;
	ClapTrap::name_ = name_ + "_clap_name";
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' << MSG_DIAMONDTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		DiamondTrap::checkStatus() const {
	std::cout << "\n============== " << "< status >"<< " ==============" << std::endl;
	std::cout << "⦁ " << "Bot Name\t: " << this->name_ << std::endl;
	std::cout << "⦁ " << "Hit Point\t: " << this->health_point_ << std::endl;
	std::cout << "⦁ " << "Energy Point\t: " << this->energy_point_ << std::endl;
	std::cout << "⦁ " << "Attack Damage\t: " << this->attack_damage_ << std::endl;
	std::cout << "========================================\n" << std::endl;
}


