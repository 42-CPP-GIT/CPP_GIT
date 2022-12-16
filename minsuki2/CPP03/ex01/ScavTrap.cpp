/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/16 23:13:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

const unsigned int	ScavTrap::max_hp = 100;
const unsigned int	ScavTrap::max_ep = 50;
const unsigned int	ScavTrap::max_ad = 20;

ScavTrap::ScavTrap(void)
	: bot_name_("Unknown"), health_point_(max_hp), energy_point_(max_ep), attack_damage_(max_ad) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET<< std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: bot_name_(name), health_point_(max_hp), energy_point_(max_ep), attack_damage_(max_ad) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
	: bot_name_(obj.bot_name_), health_point_(obj.health_point_), energy_point_(obj.energy_point_), attack_damage_(obj.attack_damage_) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' << MSG_SCAVTRAP << ' ' MSG_GONE << RESET << std::endl;
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


