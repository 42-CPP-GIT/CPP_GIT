/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/12 14:21:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: bot_name_("Unknown"), health_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << MSG_CONSTRUCT << ' ' << MSG_CLAPTRAP_BORN << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: bot_name_(name), health_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << MSG_CONSTRUCT << ' ' << MSG_CLAPTRAP_BORN << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: bot_name_(obj.bot_name_), health_point_(obj.health_point_), energy_point_(obj.energy_point_), attack_damage_(obj.attack_damage_) {
	std::cout << MSG_CONSTRUCT << ' ' << MSG_CLAPTRAP_BORN << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << MSG_DESTRUCT << ' ' << MSG_GONE << std::endl;
}

void		ClapTrap::attack(const std::string& target) {
	if (this->health_point_ == 0) {
		std::cout << MSG_CLAPTRAP << ' ' << this->bot_name_ << ' ' \
				  << MSG_NO_HP << std::endl;
	}
	else {
		std::cout << MSG_CLAPTRAP << ' ' << this->bot_name_ << ' ' \
				  << MSG_ATTACK << ' ' << target << ", " \
				  << MSG_CAUSE << ' ' << this->attack_damage_ << ' ' \
				  << MSG_P_O_D << std::endl;
	}
}

// energy_point_ X it can be.
void		ClapTrap::takeDamage(unsigned int amount) {
	if (this->health_point_ == 0) {
		std::cout << MSG_CLAPTRAP << ' ' << this->bot_name_ << ' ' \
				  << MSG_DIED << std::endl;
	}
	else {
		this->health_point_ = this->health_point_ >= amount \
							  ? this->health_point_ - amount : 0;
		std::cout << MSG_CLAPTRAP << ' ' << this->bot_name_ << ' ' \
				  << MSG_TAKE_DAMAGE << ' ' << amount << ", " \
				  << MSG_LEFT << ' ' << this->health_point_<< ' ' \
				  << MSG_HP << std::endl;
	}

}

void		ClapTrap::beRepaired(unsigned int amount) {

	if (this->health_point_ == 0) {
		std::cout << MSG_CLAPTRAP << ' ' << this->bot_name_ << ' ' \
				  << MSG_NO_HP << std::endl;
	}
	else if (this->energy_point_ == 0) {
		std::cout << MSG_CLAPTRAP << ' ' << this->bot_name_ << ' ' \
				  << MSG_NO_MP << std::endl;
	}
	else {
		this->health_point_ = UINT_MAX - this->health_point_ >= amount \
								? this->health_point_ + amount : 0;
		this->energy_point_ = this->energy_point_ > 0 \
								? this->energy_point_ - 1 : 0;
		std::cout << MSG_CLAPTRAP << ' ' << this->bot_name_ << ' ' \
				  << MSG_REPAIR << ' ' << this->energy_point_ << ", " \
				  << MSG_CAUSE << ' ' << this->attack_damage_ << ' ' \
				  << MSG_P_O_D << std::endl;
	}
}
