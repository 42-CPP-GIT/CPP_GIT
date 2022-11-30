/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/30 17:39:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fixed_nbits_ = 8;

Fixed::Fixed(void) {
	std::cout << MSG_CREATE << MSG_CALL << MSG_ENDL;
	this->fixed_num_ = 0;
}

Fixed::Fixed(const int num) {
	std::cout << MSG_CREATE << MSG_CALL << MSG_ENDL;
	this->fixed_num_ = num << this->fixed_nbits_;
}

Fixed::Fixed(const float num) {
	std::cout << MSG_CREATE << MSG_CALL << MSG_ENDL;
	this->fixed_num_ = static_cast<int>(std::roundf(num * (1 << fixed_nbits_)));
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
	this->fixed_num_ = obj.getRawBits();
	// this->fixed_num_ = obj.fixed_num_;	// [Thinking] 이 문장이 더 맞다고 생각
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << MSG_DESTROY << MSG_CALL << MSG_ENDL;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->fixed_num_) / (1 << fixed_nbits_);
}
	// for (int i = FLOAT_BITS; i > 0; i--)
	//     cnt += !(fixed_num_ & 1 << (i - 1));
//     |      |
	// return (this->fixed_num_ << cnt) | ((127 + cnt) << 16);

int		Fixed::toInt(void) const {
	return this->fixed_num_ >> fixed_nbits_;
}

int		Fixed::getRawBits(void) const {
	std::cout << MSG_GETRB << MSG_CALL << MSG_ENDL;
	return this->fixed_num_;
}
void	Fixed::setRawBits(int const raw) { this->fixed_num_ = raw; }

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}
