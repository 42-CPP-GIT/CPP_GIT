/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:40:51 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/22 19:59:33 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) {
	this->type_ = type;
#ifdef debug
	std::cout << MSG_WEAPON << '"' << this->type_ << '"' << MSG_CREATE << MSG_ENDL;
#endif
}

Weapon::~Weapon(void) {
#ifdef debug
	std::cout << MSG_WEAPON << '"' << this->type_ << '"' << MSG_DESTROY << MSG_ENDL;
#endif
}

const std::string&	Weapon::getType(void) { return this->type_; }

void	Weapon::setType(const std::string &input_type) {
#ifdef debug
	std::cout << MSG_WEAPON << '"' << this->type_ << '"' << " -> " << '"' << input_type << '"' << MSG_CHANGE << MSG_ENDL;
#endif
	this->type_ = input_type;
}
