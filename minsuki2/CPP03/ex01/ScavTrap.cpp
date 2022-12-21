/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 17:47:39 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::changeMaxValue_(void) {
	ClapTrap::limit_hp_ = ST_MAX_HP;
	ClapTrap::limit_ep_ = ST_MAX_EP;
	ClapTrap::limit_ad_ = ST_MAX_AD;
}

void	ScavTrap::inputMemberValue_(const ScavTrap& obj) {
	this->name_ = obj.name_;
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
}

ScavTrap::ScavTrap(void) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_SCAVTRAP_BORN << RESET<< std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_("Unknow");
}

ScavTrap::ScavTrap(const std::string& name) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_SCAVTRAP_BORN << RESET << std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_(name);
}

ScavTrap::ScavTrap(const ScavTrap& obj) {//: ClapTrap(obj) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_SCAVTRAP_BORN << RESET << std::endl; changeMaxValue_();
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' << MSG_SCAVTRAP << ' '\
			  << MSG_GONE << RESET << std::endl;
}

void		ScavTrap::attack(const std::string& target) {
	if (this->health_point_ == 0) {
		std::cout << BOLDGREEN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_HP << RESET << std::endl;
	} else if (this->energy_point_ == 0) {
		std::cout << BOLDGREEN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_EP << RESET << std::endl;
	} else {
		--this->energy_point_;
		std::cout << GREEN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' \
				  << MSG_ATTACK << ' ' << target << ", " \
				  << MSG_CAUSE << ' ' << this->attack_damage_ << ' ' \
				  << MSG_P_O_D << RESET << std::endl;
	}
}

void		ScavTrap::guardGate(void) const {
	std::cout << BOLDCYAN << MSG_SCAVTRAP << ' ' << this->name_ << ' ' \
			  << MSG_GATEMODE << RESET << std::endl;
}
