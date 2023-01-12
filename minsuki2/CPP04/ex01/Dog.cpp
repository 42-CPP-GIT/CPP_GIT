/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:45:29 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 17:20:28 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << MSG_DOG << ' ' << MSG_D_CONSTRUCT << std::endl;
	this->type_ = "Dog";
	this->own_brain_ = new Brain();
}

Dog::Dog(const Dog& obj) : own_brain_(NULL) {
	std::cout << MSG_DOG << ' ' << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
}

Dog&	Dog::operator=(const Dog& obj) {
	std::cout << MSG_DOG << ' ' << MSG_C_A_OPERATE << std::endl;
	if (this != &obj) {
		delete this->own_brain_;
		this->type_ = obj.type_;
		this->own_brain_ = new Brain(*obj.own_brain_);
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << MSG_DOG << ' ' << MSG_DESTRCUT << std::endl;
	delete this->own_brain_;
	this->own_brain_ = NULL;
}

void Dog::makeSound(void) const {
	std::cout << MSG_DOG << ' ' << DOG_SOUND << std::endl;
}

Brain*	Dog::getBrain(void) const { return this->own_brain_; }
