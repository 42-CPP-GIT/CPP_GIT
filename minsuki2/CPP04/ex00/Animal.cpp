/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:04:15 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/23 18:32:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

const std::string& Animal::getType() const { return this->type; }


Animal::Animal(void) : type("Unknown") {
	std::cout << MSG_ANIMAL << ' ' << MSG_D_CONSTRUCT << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type) {
	std::cout << MSG_ANIMAL << ' ' << MSG_C_CONSTRUCT << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
	std::cout << MSG_ANIMAL << ' ' << MSG_C_A_OPERATE << std::endl;
	this->type = obj.type;
	return *this;
}

Animal::~Animal(void) {
	std::cout << MSG_ANIMAL << ' ' << MSG_DESTRCUT << std::endl;
	// delete this;
}

void	Animal::makeSound(void) const {
	std::cout << MSG_ANIMAL << ' ' << ANIMAL_SOUND << std::endl;
}

