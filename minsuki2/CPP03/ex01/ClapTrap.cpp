/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 23:46:48 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

unsigned int	ClapTrap::max_hp_ = 10;
unsigned int	ClapTrap::max_ep_ = 10;
unsigned int	ClapTrap::max_ad_ = 0;

const std::string& ClapTrap::getName() const { return this->name_; }
const unsigned int& ClapTrap::getAttackDamage() const { return this->attack_damage_; }

ClapTrap::ClapTrap(void)
	: name_("Unknown"), health_point_(max_hp_), energy_point_(max_ep_), attack_damage_(max_ad_),
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_CLAPTRAP_BORN << RESET<< std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name_(name), health_point_(CT_MAX_HP), energy_point_(CT_MAX_EP), attack_damage_(CT_MAX_AD),
	  max_hp_(CT_MAX_HP), max_ep_(CT_MAX_EP), max_ad_(CT_MAX_AD) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_CLAPTRAP_BORN << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: name_(obj.name_), health_point_(obj.health_point_), energy_point_(obj.energy_point_), attack_damage_(obj.attack_damage_),
	  max_hp_(CT_MAX_HP), max_ep_(CT_MAX_EP), max_ad_(CT_MAX_AD) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' << MSG_CLAPTRAP_BORN << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' << MSG_CLAPTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		ClapTrap::attack(const std::string& target) {
	if (this->health_point_ == 0) {
		std::cout << BOLDGREEN << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_HP << RESET << std::endl;
	}
	else if (this->energy_point_ == 0) {
		std::cout << BOLDGREEN << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_NO_EP << RESET << std::endl;
	}
	else {
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
	}
	else {
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
	}
	else if (this->energy_point_ == 0) {
		std::cout << BOLDYELLOW << MSG_CLAPTRAP<< ' ' << this->name_ << ' ' \
				  << MSG_NO_EP << RESET << std::endl;
	}
	else if (this->health_point_ == ClapTrap::max_hp_) {
		std::cout << BOLDYELLOW << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_FULL_HP << RESET << std::endl;
	}
	else {
		this->health_point_ = UINT_MAX - this->health_point_ >= amount \
								? this->health_point_ + amount : UINT_MAX;
		this->health_point_ = this->health_point_ <= max_hp_ \
								? this->health_point_ : max_hp_;
		std::cout << YELLOW << MSG_CLAPTRAP << ' ' << this->name_ << ' ' \
				  << MSG_REPAIR << ' ' << amount << ", " \
				  << MSG_USE << ' ' <<  this->energy_point_-- << ' ' \
				  << MSG_P_O_E << RESET << std::endl;
		// this->energy_point_ = this->energy_point_ > 0 \
		//                         ? this->energy_point_ - 1 : 0;
	}
}

void		ClapTrap::checkStatus() {
	std::cout << "\n============== " << "< status >"<< " ==============" << std::endl;
	std::cout << "⦁ " << "Bot Name\t: " << this->name_ << std::endl;
	std::cout << "⦁ " << "Hit Point\t: " << this->health_point_ << std::endl;
	std::cout << "⦁ " << "Energy Point\t: " << this->energy_point_ << std::endl;
	std::cout << "⦁ " << "Attack Damage\t: " << this->attack_damage_ << std::endl;
	std::cout << "========================================\n" << std::endl;
}
