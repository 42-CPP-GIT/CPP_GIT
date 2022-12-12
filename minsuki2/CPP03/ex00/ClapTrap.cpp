/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/12 07:38:34 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: bot_name_("Unknown"), health_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << MSG_BORN << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: bot_name_(obj.bot_name_), health_point_(obj.health_point_), energy_point_(obj.energy_point_), attack_damage_(obj.attack_damage_) {
	std::cout << MSG_BORN << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << MSG_GONE << std::endl;
}

void		ClapTrap::attack(const std::string& target) {
	std::cout << MSG_ANNOUNCE << ' ' \
			  << MSG_CLAPTRAP << this->bot_name_ << ' '\
			  << MSG_ATTACK << ' ' << 
}
void		ClapTrap::takeDamage(unsigned int amount) {
}
void		ClapTrap::beRepaired(unsigned int amount) {
}
