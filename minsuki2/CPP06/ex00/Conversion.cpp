/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:05:55 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 19:24:50 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(void) : name_("Unknow"), grade_(0) {
}

Conversion::Conversion(const std::string& name) : name_(name), grade_(0) {
}

Conversion::Conversion(const Conversion& obj) : name_(obj.name_) {
}

Conversion&	Conversion::operator=(const Conversion& obj) {
	return *this;
}

Conversion::~Conversion(void) {
	std::cout << MSG_COVERSION << this->name_ << ", " << MSG_DESTRCUT << std::endl;
}

