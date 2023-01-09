/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:04:15 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 15:52:44 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

const std::string& AAnimal::getType() const { return this->type_; }


AAnimal::AAnimal(void) : type_("Unknown") {
	std::cout << MSG_ANIMAL << ' ' << MSG_D_CONSTRUCT << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) : type_(obj.type_) {
	std::cout << MSG_ANIMAL << ' ' << MSG_C_CONSTRUCT << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& obj) {
	std::cout << MSG_ANIMAL << ' ' << MSG_C_A_OPERATE << std::endl;
	this->type_ = obj.type_;
	return *this;
}

AAnimal::~AAnimal(void) {
	std::cout << MSG_ANIMAL << ' ' << MSG_DESTRCUT << std::endl;
}

void	AAnimal::makeSound(void) const {
	std::cout << MSG_ANIMAL << ' ' << ANIMAL_SOUND << std::endl;
}

