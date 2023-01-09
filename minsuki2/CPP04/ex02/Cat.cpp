/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:01:46 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/06 21:16:21 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << MSG_CAT << ' ' << MSG_D_CONSTRUCT << std::endl;
	this->type_ = "Cat";
	this->own_brain_ = new Brain();
}

Cat::Cat(const Cat& obj) : own_brain_(NULL) {
	std::cout << MSG_CAT << ' ' << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
}

Cat&	Cat::operator=(const Cat& obj) {
	std::cout << MSG_CAT << ' ' << MSG_C_A_OPERATE << std::endl;
	if (this != &obj) {
		delete this->own_brain_;
		this->type_ = obj.type_;
		this->own_brain_ = new Brain(*obj.own_brain_);
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << MSG_CAT << ' ' << MSG_DESTRCUT << std::endl;
	delete this->own_brain_;
}

void	Cat::makeSound(void) const {
	std::cout << MSG_CAT << ' ' << CAT_SOUND << std::endl;
}

// setIdea함수로 인해 const Brain 못 사용
Brain*	Cat::getBrain(void) const { return this->own_brain_; }

