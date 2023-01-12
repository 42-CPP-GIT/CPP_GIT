/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:04:15 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/06 16:26:58 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

const std::string& WrongAnimal::getType() const { return this->type; }

WrongAnimal::WrongAnimal(void) : type("Unknown") {
	std::cout << MSG_WRONGANIMAL << ' ' << MSG_D_CONSTRUCT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type) {
	std::cout << MSG_WRONGANIMAL << ' ' << MSG_C_CONSTRUCT << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	std::cout << MSG_WRONGANIMAL << ' ' << MSG_C_A_OPERATE << std::endl;
	this->type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << MSG_WRONGANIMAL << ' ' << MSG_DESTRCUT << std::endl;
	// delete this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << MSG_WRONGANIMAL << ' ' << WRONGANIMAL_SOUND << std::endl;
}

