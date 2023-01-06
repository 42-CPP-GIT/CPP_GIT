/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:45:29 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/23 18:40:10 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << MSG_DOG << ' ' << MSG_D_CONSTRUCT << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& obj) {
	std::cout << MSG_DOG << ' ' << MSG_C_CONSTRUCT << std::endl;
	this->type = obj.type;
}

Dog&	Dog::operator=(const Dog& obj) {
	std::cout << MSG_DOG << ' ' << MSG_C_A_OPERATE << std::endl;
	this->type = obj.type;
	return *this;
}

Dog::~Dog(void) {
	std::cout << MSG_DOG << ' ' << MSG_DESTRCUT << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << MSG_DOG << ' ' << DOG_SOUND << std::endl;
}
