/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:22:00 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/14 22:05:46 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) { this->name_ = "UnKnown"; }

Zombie::Zombie(std::string name) { this->name_ = name; }

Zombie::~Zombie(void) {
	std::cout << this->name_ << ": " << MSG_DESTROY << MSG_ENDL;
}

void Zombie::announce() {
	std::cout << this->name_ << ": " << MSG_SOUND << MSG_ENDL;
}

