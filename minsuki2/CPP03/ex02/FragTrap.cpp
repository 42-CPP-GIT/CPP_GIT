/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 17:38:50 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::changeMaxValue_(void) {
	ClapTrap::limit_hp_ = FT_MAX_HP;
	ClapTrap::limit_ep_ = FT_MAX_EP;
	ClapTrap::limit_ad_ = FT_MAX_AD;
}

void	FragTrap::inputMemberValue_(const FragTrap& obj) {
	this->name_ = obj.name_;
	this->health_point_ = obj.health_point_;
	this->energy_point_ = obj.energy_point_;
	this->attack_damage_ = obj.attack_damage_;
}

FragTrap::FragTrap(void) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_FRAGTRAP_BORN << RESET<< std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_( "Unknow");
}

FragTrap::FragTrap(const std::string& name) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_FRAGTRAP_BORN << RESET << std::endl;
	this->changeMaxValue_();
	ClapTrap::inputMemberValue_(name);
}

FragTrap::FragTrap(const FragTrap& obj) {//: ClapTrap(obj) {
	std::cout << MAGENTA << MSG_CONSTRUCT << ' ' \
			  << MSG_FRAGTRAP_BORN << RESET << std::endl;
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	this->changeMaxValue_();
	this->inputMemberValue_(obj);
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << BOLDMAGENTA << MSG_DESTRUCT << ' ' \
			  << MSG_FRAGTRAP << ' ' << MSG_GONE << RESET << std::endl;
}

void		FragTrap::highFivesGuys(void) const {
	std::cout << BOLDCYAN << MSG_FRAGTRAP << ' ' << this->name_ \
			  << ' ' << "says, " << MSG_HIGHFIVESGUYS << RESET << std::endl;
}
