/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:11:30 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/21 18:35:39 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA:: HumanA(const std::string& name, Weapon& weapon)
	: weapon_(weapon) {
	this->name_ = name;
#ifdef debug
	std::cout << MSG_HUMAN_A << '"' << this->name_ << "<+" \
		<< this->weapon_.getType() << '"' << MSG_CREATE << MSG_ENDL;
#endif
}

HumanA::~HumanA(void) {
#ifdef debug
	std::cout << MSG_HUMAN_A << '"' << this->name_ << "<+" \
		<< this->weapon_.getType() << '"' << MSG_DESTROY << MSG_ENDL;
#endif
}

void HumanA::attack() {
	std::cout << this->name_ << MSG_ATTACK << weapon_.getType() << MSG_ENDL;
}
