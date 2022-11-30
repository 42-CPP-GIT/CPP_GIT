/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/30 23:21:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fixed_nbits_ = 8;
const int	Fixed::float_nbits_ = 23; // 23개
const int	Fixed::float_exponent_bit_ = 0b11111111 << float_nbits_;
const int	Fixed::float_mantissa_bit_ = 0b11111111111111111111111; // 23개
const int	Fixed::sign_bit_ = 1 << 31;

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
	}

	/* 단순한 방식 */
	// this->fixed_num_ = static_cast<int>(std::roundf(num * (1 << fixed_nbits_)));
	// return ;
	/* 드랍 더 비트적인 방식 */
	struct s_info_float flo;
	std::memcpy(&flo.bit, &num, sizeof(float));
	this->fixed_num_ = flo.bit;
	std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
	flo.exponent = ((this->fixed_num_ & this->float_exponent_bit_) >> this->float_nbits_) - 127;
	flo.sign = this->fixed_num_ & this->sign_bit_;
	this->fixed_num_ &= this->float_mantissa_bit_;// >> this->float_nbits_;
	std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
	std::cerr << "exp : " << flo.exponent << MSG_ENDL; // c++11
	const int tmp = 1 << (22 - (flo.exponent + fixed_nbits_));
	this->fixed_num_ += tmp;
	std::cerr << "compl : " << std::bitset<32>(tmp) << MSG_ENDL; // c++11
	std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
	this->fixed_num_ |= 1 << 23;
	std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
	this->fixed_num_ >>= 23 - this->fixed_nbits_ - (flo.exponent);
	std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11 / STL
	if (flo.sign)
		this->fixed_num_ = ~this->fixed_num_ + 1; // 2의 보수
	std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
	std::cerr << "res : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
	std::cerr << "ans : " << std::bitset<32>(static_cast<int>\
				(std::roundf(num * (1 << fixed_nbits_)))) << MSG_ENDL; // c++11
}

	// std::cerr << "float : " << std::bitset<32>(flo.bit) << MSG_ENDL; // c++11
	// std::cerr << "fixed : " << std::bitset<32>(this->fixed_num_) << MSG_ENDL; // c++11
	// std::cerr << "Dec : " << num << MSG_ENDL;
	// std::cerr << "exp : " << flo.exponent << MSG_ENDL; // c++11
	// std::cerr << "bin : " << std::bitset<32>(flo.raw_bit) << MSG_ENDL; // c++11
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

float	Fixed::toFloat(void) const {		// 기존 널리 알려진 방식
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
