/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/28 23:09:56 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << MSG_CREATE << MSG_CALL << MSG_ENDL;
	this->f_num_ = 1234.43;
}

Fixed::Fixed(const int num) {
	std::cout << MSG_CREATE << MSG_CALL << MSG_ENDL;
	this->f_num_ = num << this->f_bits_;
}

Fixed::Fixed(const float num) {
	std::cout << MSG_CREATE << MSG_CALL << MSG_ENDL;
	this->f_num_ = num;
}

Fixed::Fixed(const Fixed& obj) {
	std::cout << MSG_COPY << MSG_CALL << MSG_ENDL;
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	if (this == &obj) // early return
		return *this;
	// [Thinking] 작동하는 상황에서만 출력
	std::cout << MSG_ASSIGN << MSG_CALL << MSG_ENDL;
	this->f_num_ = obj.getRawBits();
	// this->f_num_ = obj.f_num_;	// [Thinking] 이 문장이 더 맞다고 생각
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << MSG_DESTROY << MSG_CALL << MSG_ENDL;
}

int		Fixed::getRawBits(void) const {
	std::cout << MSG_GETRB << MSG_CALL << MSG_ENDL;
	return this->f_num_;
}
void	Fixed::setRawBits(int const raw) { this->f_num_ = raw; }

