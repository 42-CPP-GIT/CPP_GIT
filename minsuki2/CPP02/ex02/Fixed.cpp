/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 14:14:13 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
	this->fixed_num_ = num << this->fixed_nbits_;
}

Fixed::Fixed(const float num) {
#ifdef debug
	std::cerr << MSG_CREATE << " float" << MSG_CALL << ' ';
#endif
	if (!num) {
		this->fixed_num_ = 0;
		return ;
	} /* 드랍 더 비트적인 방식 */
	/* 단순한 방식 */
	this->fixed_num_ = static_cast<int>(std::roundf(num * (1 << fixed_nbits_))); return ;
	struct s_info_float flo;
	std::memcpy(&flo.bit, &num, sizeof(float));
	flo.exponent = ((flo.bit & BIT_FLOAT_EXPONENT) >> OFFSET_FLOAT_NBITS) - 127;			// 지수부 구하기
	flo.sign = 2 * !(flo.bit & (1 << OFFSET_SIGN_NBITS)) - 1;								// sign 만들기
	this->fixed_num_ = (1 << OFFSET_FLOAT_NBITS) | (flo.bit & BIT_FLOAT_MANTISSA);			// 1 추가 + mantissa 부분 추출
	this->fixed_num_ += 1 << (OFFSET_FLOAT_NBITS - (flo.exponent + fixed_nbits_ + 1));		// 반올림 해주기
	this->fixed_num_ >>= OFFSET_FLOAT_NBITS - this->fixed_nbits_ - (flo.exponent);			// fixed 으로 이동하기
	this->fixed_num_ = flo.sign < 0 ? ~this->fixed_num_ + 1 : this->fixed_num_;				// 음수면 2의 보수

}

Fixed::Fixed(const Fixed& obj) {
#ifdef debug
	std::cerr << MSG_COPY << MSG_CALL << ' ';
#endif
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	if (this == &obj) // early return
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
	tmp.fixed_num_ = ((*this).fixed_num_ * obj.fixed_num_) >> fixed_nbits_;
	return tmp;
}

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
