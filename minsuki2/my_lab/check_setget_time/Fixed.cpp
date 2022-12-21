/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 14:56:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "start" << std::endl;
	this->num_ = 0;
}

Fixed::~Fixed(void) {
	std::cout << "finish"<< std::endl;
}

const int&	Fixed::getRawBits(void) const { return this->num_; }
void		Fixed::setRawBits(int const& raw) { this->num_ = raw; }

// void		Fixed::count(const int& num) {
//     this->num_ = this->num_ + num;
// }
//
void		Fixed::count(const int& i) {
	this->setRawBits(this->getRawBits() + i);
}

