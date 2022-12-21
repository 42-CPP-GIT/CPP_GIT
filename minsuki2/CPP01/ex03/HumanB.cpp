/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:10:03 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/21 18:47:34 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) {
	this->name_ = name;
	this->weapon_ = NULL;
#ifdef debug
	std::cout << MSG_HUMAN_B << '"' << this->name_ << "<+" \
			<< "(null)" << '"' << MSG_CREATE << MSG_ENDL;
#endif
}

HumanB::~HumanB(void) {
#ifdef debug
	const std::string& weapon_type = (this->weapon_ != NULL) ? \
										this->weapon_->getType() : "(null)";
	std::cout << MSG_HUMAN_B << '"' << this->name_ << "<+" \
			<< weapon_type << '"' << MSG_DESTROY << MSG_ENDL;
#endif
}

void	HumanB::attack(void) {
	std::cout << this->name_;
	if (this->weapon_) 
		std::cout << MSG_ATTACK << this->weapon_->getType();
	else
		std::cout << " couldn't attack without weapon";
	std::cout << MSG_ENDL;

}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}
