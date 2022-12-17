/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 17:55:24 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

const unsigned int	ScavTrap::max_hp_ = 100;
const unsigned int	ScavTrap::max_ep_ = 50;
const unsigned int	ScavTrap::max_ad_ = 20;

ScavTrap::ScavTrap(void) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET<< std::endl;
	ClapTrap::max_hp_ = ScavTrap::max_hp_;
	ClapTrap::max_ep_ = ScavTrap::max_ep_;
	ClapTrap::max_ad_ = ScavTrap::max_ad_;
	this->bot_name_ = "Unknow";
	health_point_ = max_hp_;
	energy_point_ = max_ep_;
	attack_damage_ = max_ad_;
}

ScavTrap::ScavTrap(const std::string& name) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET << std::endl;
	ClapTrap::max_hp_ = ScavTrap::max_hp_;
	ClapTrap::max_ep_ = ScavTrap::max_ep_;
	ClapTrap::max_ad_ = ScavTrap::max_ad_;
	this->bot_name_ = name;
	health_point_ = max_hp_;
	energy_point_ = max_ep_;
	attack_damage_ = max_ad_;
}

ScavTrap::ScavTrap(const ScavTrap& obj) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET << std::endl;
	ClapTrap::max_hp_ = ScavTrap::max_hp_;
	ClapTrap::max_ep_ = ScavTrap::max_ep_;
	ClapTrap::max_ad_ = ScavTrap::max_ad_;
	this->bot_name_ = obj.bot_name_;
	health_point_ = obj.health_point_;
	energy_point_ = obj.energy_point_;
	attack_damage_ = obj.attack_damage_;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' << MSG_SCAVTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		ScavTrap::guardGate(void) {
}


void		ScavTrap::checkStatus() {
	std::cout << "\n============== " << "< status >"<< " ==============" << std::endl;
	std::cout << "⦁ " << "Bot Name\t: " << this->bot_name_ << std::endl;
	std::cout << "⦁ " << "Hit Point\t: " << this->health_point_ << std::endl;
	std::cout << "⦁ " << "Energy Point\t: " << this->energy_point_ << std::endl;
	std::cout << "⦁ " << "Attack Damage\t: " << this->attack_damage_ << std::endl;
	std::cout << "========================================\n" << std::endl;
}


