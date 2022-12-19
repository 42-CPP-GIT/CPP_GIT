/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/19 16:48:30 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"


void	ScavTrap::changeMaxValue_(void) {
	ClapTrap::max_hp_ = ST_MAX_HP;
	ClapTrap::max_ep_ = ST_MAX_EP;
	ClapTrap::max_ad_ = ST_MAX_AD;
}

void	ScavTrap::inputMemberValue_(const ScavTrap& obj) {
	this->name_ = obj.name_;
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
}


ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET<< std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_("Unknow");
	this->guard_gate_mode_ = false;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET << std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_(name);
	this->guard_gate_mode_ = false;
}

ScavTrap::ScavTrap(const ScavTrap& obj) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_SCAVTRAP_BORN << RESET << std::endl; changeMaxValue_();
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
	this->guard_gate_mode_ = false;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
	this->guard_gate_mode_ = false;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' << MSG_SCAVTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		ScavTrap::attack(const std::string& target) {
	if (this->health_point_ == 0) {
		std::cout << BOLDGREEN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_HP << RESET << std::endl;
	}
	else if (this->energy_point_ == 0) {
		std::cout << BOLDGREEN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_EP << RESET << std::endl;
	}
	else {
		this->energy_point_ = this->energy_point_ > 0 \
								? this->energy_point_ - 1 : 0; std::cout << GREEN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' \
				  << MSG_ATTACK << ' ' << target << ", " \
				  << MSG_CAUSE << ' ' << this->attack_damage_ << ' ' \
				  << MSG_P_O_D << RESET << std::endl;
	}
}

void		ScavTrap::guardGate(void) {
	std::cout << BOLDCYAN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' << MSG_GATEMODE << RESET << std::endl;
	this->guard_gate_mode_ = true;
}

void		ScavTrap::checkStatus() const {
	std::cout << "\n============== " << "< status >"<< " ==============" << std::endl;
	std::cout << "⦁ " << "Bot Name\t: " << this->name_ << std::endl;
	std::cout << "⦁ " << "Hit Point\t: " << this->health_point_ << std::endl;
	std::cout << "⦁ " << "Energy Point\t: " << this->energy_point_ << std::endl;
	std::cout << "⦁ " << "Attack Damage\t: " << this->attack_damage_ << std::endl;
	std::cout << "⦁ " << "Guard Gate\t: " << (!!(this->guard_gate_mode_) ? "true" : "false") << std::endl;
	std::cout << "========================================\n" << std::endl;
}


