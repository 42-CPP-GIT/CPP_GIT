/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:50:25 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/20 21:54:09 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(const std::string& name)
	: name_(name) {
}

Data::Data(const Data& obj) {
	*this = obj;
}

Data&	Data::operator=(const Data& obj) {
	this->name_ = obj.name_;
	return *this;
}

Data::~Data() {
}
