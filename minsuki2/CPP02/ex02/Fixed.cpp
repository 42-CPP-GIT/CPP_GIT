/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/07 20:51:33 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// # include <cstring>	// linux

const int	Fixed::fixed_nbits_ = 8;

Fixed::Fixed(void) { this->fixed_num_ = 0; }

Fixed::Fixed(const int num) { this->fixed_num_ = (num << this->fixed_nbits_); }

static int _bitShift(int raw_bit, int cnt) {
	return cnt > 0 ? raw_bit << cnt : raw_bit >> -cnt;
}

Fixed::Fixed(const float num) {
	if (!num) {
		this->fixed_num_ = 0;
		return ;
	}
	int flo_bit;
	std::memcpy(&flo_bit, &num, sizeof(float));
	this->fixed_num_ = (1 << OFFSET_FLOAT_NBITS) | (flo_bit & BIT_FLOAT_MANTISSA);
	const int flo_exponent = ((flo_bit & BIT_FLOAT_EXPONENT) >> OFFSET_FLOAT_NBITS) - 127;
	const int flo_bitshift = OFFSET_FLOAT_NBITS - (flo_exponent + this->fixed_nbits_);
	this->fixed_num_ += _bitShift(1,  flo_bitshift - 1);
	this->fixed_num_ = _bitShift(this->fixed_num_, -flo_bitshift);
	this->fixed_num_ = !(flo_bit & BIT_SIGN) ? this->fixed_num_ : ~this->fixed_num_ + 1 ;
}

Fixed::Fixed(const Fixed& obj) { *this = obj; }

Fixed&	Fixed::operator=(const Fixed& obj) {
	if (this == &obj)
		return *this;
	this->fixed_num_ = obj.fixed_num_;
	return *this;
}

Fixed::~Fixed(void) {}

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
	const int abs_this = this->fixed_num_ > 0 ? this->fixed_num_ : ~this->fixed_num_ + 1;
	const int abs_obj = obj.fixed_num_ > 0 ? obj.fixed_num_ : ~obj.fixed_num_ + 1;
	const int right_val = abs_this > abs_obj ? abs_obj : abs_this;
	tmp.fixed_num_ = abs_this > abs_obj ? abs_this : abs_obj;
	const int backup_bit = tmp.fixed_num_ & BIT_FIXED_MANTISSA;
	tmp.fixed_num_ = (tmp.fixed_num_ >> this->fixed_nbits_) * right_val;
	tmp.fixed_num_ += (backup_bit * right_val) >> this->fixed_nbits_;
	tmp.fixed_num_ = ((this->fixed_num_ & BIT_SIGN) ^ (obj.fixed_num_ & BIT_SIGN)) == 0 \
					 ? tmp.fixed_num_ : ~tmp.fixed_num_ + 1;
	return tmp;
}

Fixed Fixed::operator/(const Fixed& obj) const {
	if (obj.fixed_num_ == 0) {
		std::cerr << "\nError: Dividing with zero" << MSG_ENDL; std::exit(1);
	}
	Fixed	tmp;
	tmp.fixed_num_ = this->fixed_num_ > 0 ? this->fixed_num_ : ~this->fixed_num_ + 1;
	const int abs_obj = obj.fixed_num_ > 0 ? obj.fixed_num_ : ~obj.fixed_num_ + 1;
	const int backup_bit = tmp.fixed_num_ & BIT_FLOAT_EXPONENT;
	tmp.fixed_num_ = static_cast<unsigned int>((tmp.fixed_num_ & BIT_FLOAT_MANTISSA) \
												<< this->fixed_nbits_) / abs_obj; // res로 받기
	tmp.fixed_num_ += (backup_bit / abs_obj) << this->fixed_nbits_;
	tmp.fixed_num_ = ((this->fixed_num_ & BIT_SIGN) ^ (obj.fixed_num_ & BIT_SIGN)) == 0 \
					 ? tmp.fixed_num_ : ~tmp.fixed_num_ + 1;
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
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return a.fixed_num_ > b.fixed_num_? a : b;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) { return a < b ? a : b; }

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) \
								{ return a.fixed_num_ < b.fixed_num_? a : b; }

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}
