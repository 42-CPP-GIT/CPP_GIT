/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:01:46 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/06 16:26:21 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << MSG_WRONGCAT << ' ' << MSG_D_CONSTRUCT << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) {
	std::cout << MSG_WRONGCAT << ' ' << MSG_C_CONSTRUCT << std::endl;
	this->type = obj.type;
}

WrongCat&	WrongCat::operator=(const WrongCat& obj) {
	std::cout << MSG_WRONGCAT << ' ' << MSG_C_A_OPERATE << std::endl;
	this->type = obj.type;
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << MSG_WRONGCAT << ' ' << MSG_DESTRCUT << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << MSG_WRONGCAT << ' ' << WRONGCAT_SOUND << std::endl;
}
