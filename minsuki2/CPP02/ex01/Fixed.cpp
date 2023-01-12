/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/07 20:41:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fixed_nbits_ = 8;

Fixed::Fixed(void) {
	std::cout << MSG_DEFALUT_CREATE << MSG_CALL << MSG_ENDL;
	this->fixed_num_ = 0;
}

Fixed::Fixed(const int num) {
	std::cout << MSG_INT_CREATE << MSG_CALL << MSG_ENDL;
	this->fixed_num_ = num << this->fixed_nbits_;
}

static int _bitShift(int raw_bit, int cnt) {
	return cnt > 0 ? raw_bit << cnt : raw_bit >> -cnt;
}

Fixed::Fixed(const float num) {
	std::cout << MSG_FLOAT_CREATE << MSG_CALL << MSG_ENDL;
	if (!num) {
		this->fixed_num_ = 0;
		return ;
	}
/* 드랍 더 비트적인 방식 */
	int flo_bit;
	std::memcpy(&flo_bit, &num, sizeof(float));
	this->fixed_num_ = (1 << OFFSET_FLOAT_NBITS) | (flo_bit & BIT_FLOAT_MANTISSA); // 1 추가 + mantissa 부분 추출
	const int flo_exponent = ((flo_bit & BIT_FLOAT_EXPONENT) >> OFFSET_FLOAT_NBITS) - 127; // 지수부 구하기
	const int flo_bitshift = OFFSET_FLOAT_NBITS - (flo_exponent + this->fixed_nbits_);
	this->fixed_num_ += _bitShift(1,  flo_bitshift - 1); // 반올림
	this->fixed_num_ = _bitShift(this->fixed_num_, -flo_bitshift); // fixed 으로 이동하기
	this->fixed_num_ = !(flo_bit & BIT_SIGN) ? this->fixed_num_ : ~this->fixed_num_ + 1 ; // 음수면 2의 보수
}
/* 일반적인 방식 */
	// this->fixed_num_ = static_cast<int>(std::roundf(num * (1 << fixed_nbits_)));
	// return ;
/* bit 출력 함수*/
	// std::cerr << std::bitset<32>(this->fixed_num_) << MSG_ENDL;
/* flo_bit 출력 함수*/
	// std::cerr << std::bitset<32>(flo_bit) << MSG_ENDL;

Fixed::Fixed(const Fixed& obj) {
	std::cout << MSG_COPY << MSG_CALL << MSG_ENDL;
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	if (this == &obj) // early return
		return *this;
	// [Thinking] 작동하는 상황에서만 출력
	std::cout << MSG_ASSIGN << MSG_CALL << MSG_ENDL;
	this->fixed_num_ = obj.fixed_num_;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << MSG_DESTROY << MSG_CALL << MSG_ENDL;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->fixed_num_) / (1 << this->fixed_nbits_);
}

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
