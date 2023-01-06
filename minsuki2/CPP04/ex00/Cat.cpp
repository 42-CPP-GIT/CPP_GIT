/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:01:46 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/23 18:28:09 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << MSG_CAT << ' ' << MSG_D_CONSTRUCT << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& obj) {
	std::cout << MSG_CAT << ' ' << MSG_C_CONSTRUCT << std::endl;
	this->type = obj.type;
}

Cat&	Cat::operator=(const Cat& obj) {
	std::cout << MSG_CAT << ' ' << MSG_C_A_OPERATE << std::endl;
	this->type = obj.type;
	return *this;
}

Cat::~Cat(void) {
	std::cout << MSG_CAT << ' ' << MSG_DESTRCUT << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << MSG_CAT << ' ' << CAT_SOUND << std::endl;
}
