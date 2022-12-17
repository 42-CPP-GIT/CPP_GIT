/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 23:02:34 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

void	FragTrap::changeMaxValue_(void) {
	ClapTrap::max_hp_ = FT_MAX_HP;
	ClapTrap::max_ep_ = FT_MAX_EP;
	ClapTrap::max_ad_ = FT_MAX_AD;
}

FragTrap::FragTrap(void) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_FRAGTRAP_BORN << RESET<< std::endl;
	changeMaxValue_();
	this->name_ = "Unknow";
	this->health_point_ = max_hp_;
	this->energy_point_ = max_ep_;
	this->attack_damage_ = max_ad_;
}

FragTrap::FragTrap(const std::string& name) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_FRAGTRAP_BORN << RESET << std::endl;
	changeMaxValue_();
	this->name_ = name;
	this->health_point_ = max_hp_;
	this->energy_point_ = max_ep_;
	this->attack_damage_ = max_ad_;
}

FragTrap::FragTrap(const FragTrap& obj) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_FRAGTRAP_BORN << RESET << std::endl;
	changeMaxValue_();
	this->name_ = obj.name_;
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
}


FragTrap& FragTrap::operator=(const FragTrap& obj) {
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' << MSG_FRAGTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		FragTrap::highFivesGuys(void) const {
	std::cout << BOLDCYAN << MSG_FRAGTRAP << ' ' << this->name_ << ' ' << "says, " << MSG_HIGHFIVESGUYS << RESET << std::endl;
}

void		FragTrap::checkStatus() const {
	std::cout << "\n============== " << "< status >"<< " ==============" << std::endl;
	std::cout << "⦁ " << "Bot Name\t: " << this->name_ << std::endl;
	std::cout << "⦁ " << "Hit Point\t: " << this->health_point_ << std::endl;
	std::cout << "⦁ " << "Energy Point\t: " << this->energy_point_ << std::endl;
	std::cout << "⦁ " << "Attack Damage\t: " << this->attack_damage_ << std::endl;
	std::cout << "========================================\n" << std::endl;
}


