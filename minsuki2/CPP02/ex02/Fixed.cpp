/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/05 16:41:05 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// # include <cstring>	// linux

const int	Fixed::fixed_nbits_ = 8;

Fixed::Fixed(void) {
#ifdef debug
	std::cerr << MSG_CREATE << MSG_CALL << ' ';
#endif
	this->fixed_num_ = 0;
}

Fixed::Fixed(const int num) {
#ifdef debug
	std::cerr << MSG_CREATE << " int" << MSG_CALL << ' ';
#endif
	this->fixed_num_ = (num << this->fixed_nbits_);
}

static int _bitShift(int raw_bit, int cnt) {
	return cnt > 0 ? raw_bit << cnt : raw_bit >> -cnt;
}

Fixed::Fixed(const float num) {
#ifdef debug
	std::cout << MSG_CREATE << MSG_CALL << MSG_ENDL;
#endif
	if (!num) {
		this->fixed_num_ = 0;
		return ;
	} /* 일반적인 방식 */
	this->fixed_num_ = static_cast<int>(std::roundf(num * (1 << fixed_nbits_))); return ;
	/* 드랍 더 비트적인 방식 */
	struct s_info_float flo;
	std::memcpy(&flo.bit, &num, sizeof(float));
	flo.exponent = ((flo.bit & BIT_FLOAT_EXPONENT) >> OFFSET_FLOAT_NBITS) - 127;			// 지수부 구하기
	flo.sign_flag = flo.bit & BIT_SIGN;														// sign 만들기
	this->fixed_num_ = (1 << OFFSET_FLOAT_NBITS) | (flo.bit & BIT_FLOAT_MANTISSA);	// 1 추가 + mantissa 부분 추출
	this->fixed_num_ += _bitShift(1,  (OFFSET_FLOAT_NBITS - (flo.exponent + fixed_nbits_ + 1)));		// 반올림 해주기
	this->fixed_num_ = _bitShift(this->fixed_num_, \
					this->fixed_nbits_ + flo.exponent - OFFSET_FLOAT_NBITS);							// fixed 으로 이동하기
	this->fixed_num_ = (flo.sign_flag == true) ? ~this->fixed_num_ + 1 : this->fixed_num_;							// 음수면 2의 보수
}

Fixed::Fixed(const Fixed& obj) {
#ifdef debug
	std::cerr << MSG_COPY << MSG_CALL << ' ';
#endif
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	if (this == &obj)
		return *this;
#ifdef debug
	std::cerr << MSG_ASSIGN << MSG_CALL << ' ';
#endif
	this->fixed_num_ = obj.fixed_num_;
	return *this;
}


Fixed::~Fixed(void) {
#ifdef debug
	std::cerr << MSG_DESTROY << MSG_CALL << MSG_ENDL;
#endif
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->fixed_num_) / (1 << fixed_nbits_);
}

int		Fixed::toInt(void) const {
	return this->fixed_num_ >> fixed_nbits_;
}

int		Fixed::getRawBits(void) const { return this->fixed_num_; }
int		Fixed::getMantissaBits(void) const { return this->fixed_num_ & fixed_nbits_; }
void	Fixed::setRawBits(int const raw) { this->fixed_num_ = raw; }

/* 관계 연산자 */
bool Fixed::operator<(const Fixed& obj) const \
								{ return (*this).fixed_num_ < obj.fixed_num_; }

bool Fixed::operator>(const Fixed& obj) const \
								{ return (*this).fixed_num_ > obj.fixed_num_; }

bool Fixed::operator>=(const Fixed& obj) const { return !(*this < obj); }

bool Fixed::operator<=(const Fixed& obj) const { return !(*this > obj); }

bool Fixed::operator==(const Fixed& obj) const \
								{ return (*this).fixed_num_ == obj.fixed_num_; }

bool Fixed::operator!=(const Fixed& obj) const { return !(*this == obj); }

/* 산술 연산자 */
Fixed Fixed::operator+(const Fixed& obj) const {
	Fixed tmp;
	tmp.fixed_num_ = (*this).fixed_num_ + obj.fixed_num_;
	return tmp;
}

Fixed Fixed::operator-(const Fixed& obj) const {
	Fixed tmp;
	tmp.fixed_num_ = (*this).fixed_num_ - obj.fixed_num_;
	return tmp;
}

Fixed Fixed::operator*(const Fixed& obj) const {
	Fixed tmp;				// 생성과 동시에 초기화하면 int 생성자로 감
	// 부호 다른 지 체크
	if (((*this).fixed_num_ & BIT_SIGN) ^ (obj.fixed_num_ & BIT_SIGN)) {
	//     // 음수 비트 살려서 이동 + 음수가 아니면 2의 보수 취하기
		tmp.fixed_num_ = ((*this).fixed_num_ * obj.fixed_num_) >> fixed_nbits_;
		tmp.fixed_num_ = tmp.fixed_num_ > 0 ? ~tmp.fixed_num_ + 1 : tmp.fixed_num_;
	}
	else
		tmp.fixed_num_ = static_cast<unsigned int>( // 음수 비트 없애서 이동
						(*this).fixed_num_ * obj.fixed_num_) >> fixed_nbits_;
	// std::cerr << "this : " << std::bitset<32>((*this).fixed_num_) << MSG_ENDL;
	// std::cerr << "obj  : " << std::bitset<32>(obj.fixed_num_) << MSG_ENDL;
	// std::cerr << "obj  : " << std::bitset<32>((*this).fixed_num_ * obj.fixed_num_) << MSG_ENDL;
	// std::cerr << "res  : " << std::bitset<32>(tmp.fixed_num_) << MSG_ENDL;
	return tmp;
}

	// 1. 나눠서 하는 것은 연산 시간에 효율이 안 좋음
	// 2. 부호가 음수 범위를 침범하면 undefined 됨...
	// std::cerr << "this : " << std::bitset<32>((*this).fixed_num_) << MSG_ENDL;
	// std::cerr << "obj  : " << std::bitset<32>(obj.fixed_num_) << MSG_ENDL;
	// std::cerr << "obj  : " << std::bitset<32>((*this).fixed_num_ * obj.fixed_num_) << MSG_ENDL;
	// std::cerr << "res  : " << std::bitset<32>(tmp.fixed_num_) << MSG_ENDL;

Fixed Fixed::operator/(const Fixed& obj) const {
	Fixed tmp;
	tmp.fixed_num_ = ((*this).fixed_num_ << fixed_nbits_) / obj.fixed_num_;
	return tmp;
}


/* 증감 연산자 */
Fixed& Fixed::operator++(void) {
	this->fixed_num_++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--(void) {
	this->fixed_num_ -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(this->fixed_num_);
	--(*this);
	return tmp;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
#ifdef debug
	std::cerr << "<just max()> ";
#endif
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
#ifdef debug
	std::cerr << "<const max()> ";
#endif
	return a.fixed_num_ > b.fixed_num_? a : b;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) { return a < b ? a : b; }

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) \
								{ return a.fixed_num_ < b.fixed_num_? a : b; }

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}
