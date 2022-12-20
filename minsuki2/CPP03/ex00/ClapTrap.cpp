/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 16:14:02 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

const std::string& ClapTrap::getName() const { return this->name_; }
const unsigned int& ClapTrap::getAttackDamage() const { return this->attack_damage_; }

void	ClapTrap::inputMemberValue_(const std::string& name) {
	this->name_ = name;
	this->health_point_ = this->limit_hp_;
	this->energy_point_ = this->limit_ep_;
	this->attack_damage_ = this->limit_ad_;
}

void	ClapTrap::inputMemberValue_(const ClapTrap& obj) {
	this->name_ = obj.name_;
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
}

ClapTrap::ClapTrap(void)
	: limit_hp_(CT_MAX_HP), limit_ep_(CT_MAX_EP), limit_ad_(CT_MAX_AD) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_CLAPTRAP_BORN << RESET << std::endl;
	this->inputMemberValue_("Unknown");
}

ClapTrap::ClapTrap(const std::string& name)
	: limit_hp_(CT_MAX_HP), limit_ep_(CT_MAX_EP), limit_ad_(CT_MAX_AD) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_CLAPTRAP_BORN << RESET << std::endl;
	this->inputMemberValue_(name);
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: limit_hp_(CT_MAX_HP), limit_ep_(CT_MAX_EP), limit_ad_(CT_MAX_AD) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_CLAPTRAP_BORN << RESET << std::endl;
	this->inputMemberValue_(obj);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	this->limit_hp_ = CT_MAX_HP;
	this->limit_ep_ = CT_MAX_EP;
	this->limit_ad_ = CT_MAX_AD;
	this->inputMemberValue_(obj);
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' \
			  << MSG_CLAPTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		ClapTrap::attack(const std::string& target) {
	if (this->health_point_ == 0) {
		std::cout << BOLDGREEN << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_HP << RESET << std::endl;
	} else if (this->energy_point_ == 0) {
		std::cout << BOLDGREEN << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_EP << RESET << std::endl;
	} else {
		this->energy_point_ = this->energy_point_ > 0 \
								? this->energy_point_ - 1 : 0;
		std::cout << GREEN << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_ATTACK << ' ' << target << ", " \
				  << MSG_CAUSE << ' ' << this->attack_damage_ << ' ' \
				  << MSG_P_O_D << RESET << std::endl;
	}
}

// energy_point_ X it can be.
void		ClapTrap::takeDamage(unsigned int amount) {
	if (this->health_point_ == 0) {
		std::cout << BOLDRED << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_DIED << RESET << std::endl;
	} else {
		this->health_point_ = this->health_point_ >= amount \
							  ? this->health_point_ - amount : 0;
		std::cout << RED << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_TAKE_DAMAGE << ' ' << amount << ", " \
				  << MSG_LEFT << ' ' << this->health_point_<< ' ' \
				  << MSG_HP << RESET << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (this->health_point_ == 0) {
		std::cout << BOLDYELLOW << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_HP << RESET << std::endl;
	} else if (this->energy_point_ == 0) {
		std::cout << BOLDYELLOW << MSG_CLAPTRAP<< ' ' << this->name_ << ' ' \
				  << MSG_NO_EP << RESET << std::endl;
	} else if (this->health_point_ == this->limit_hp_) {
		std::cout << BOLDYELLOW << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_FULL_HP << RESET << std::endl;
	} else {
		--this->energy_point_;
		this->health_point_ = UINT_MAX - this->health_point_ >= amount \
								? this->health_point_ + amount : UINT_MAX;
		this->health_point_ = this->health_point_ <= limit_hp_ \
								? this->health_point_ : limit_hp_;
		std::cout << YELLOW << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_REPAIR << ", " \
				  << MSG_CAUSE << ' ' << amount << ' ' \
				  << MSG_P_O_H << RESET << std::endl;
	}
}

void		ClapTrap::checkStatus() {
	std::cout << "\n============== " << "< status >" << " ==============" << std::endl;
	std::cout << "⦁ " << "Bot Name\t: " << this->name_ << std::endl;
	std::cout << "⦁ " << "Hit Point\t: " << this->health_point_ << std::endl;
	std::cout << "⦁ " << "Energy Point\t: " << this->energy_point_ << std::endl;
	std::cout << "⦁ " << "Attack Damage\t: " << this->attack_damage_ << std::endl;
	std::cout << "========================================\n" << std::endl;
}
