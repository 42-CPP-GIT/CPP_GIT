/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 06:47:36 by minsuki2         ###   ########.fr       */
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
	if (!num) {
		this->fixed_num_ = 0;
		return ;
	} /* 드랍 더 비트적인 방식 */
	struct s_info_float flo;
	std::memcpy(&flo.bit, &num, sizeof(float));
	flo.exponent = ((flo.bit & BIT_FLOAT_EXPONENT) >> OFFSET_FLOAT_NBITS) - 127;			// 지수부 구하기
	flo.sign = 2 * !(flo.bit & (1 << OFFSET_SIGN_NBITS)) - 1;								// sign 만들기
	this->fixed_num_ = (1 << OFFSET_FLOAT_NBITS) | (flo.bit & BIT_FLOAT_MANTISSA);			// 1 추가 + mantissa 부분 추출
	this->fixed_num_ += 1 << (OFFSET_FLOAT_NBITS - (flo.exponent + fixed_nbits_ + 1));		// 반올림 해주기
	this->fixed_num_ >>= OFFSET_FLOAT_NBITS - this->fixed_nbits_ - (flo.exponent);			// fixed 으로 이동하기
	this->fixed_num_ = flo.sign < 0 ? ~this->fixed_num_ + 1 : this->fixed_num_;				// 음수면 2의 보수

}
	/* 단순한 방식 */
	// this->fixed_num_ = static_cast<int>(std::roundf(num * (1 << fixed_nbits_)));
	// return ;

	// std::cerr << "float : " << std::bitset<32>(flo.bit) << MSG_ENDL; // c++11
	// std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
// # 0 개수 세는 함수
	// for (int i = FLOAT_BITS; i > 0; i--)
	//     cnt += !(fixed_num_ & 1 << (i - 1));

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
