/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:10 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/06 17:52:03 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstring> // linux

const int	Fixed::fixed_nbits_ = 8;

Fixed::Fixed(void) { this->fixed_num_ = 0; }

Fixed::Fixed(const int num) { this->fixed_num_ = (num << this->fixed_nbits_); }

int bitShift(int raw_bit, int cnt) {
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
	this->fixed_num_ += bitShift(1,  flo_bitshift - 1);
	this->fixed_num_ = bitShift(this->fixed_num_, -flo_bitshift);
	this->fixed_num_ = !(flo_bit & BIT_SIGN) ? this->fixed_num_ : ~this->fixed_num_ + 1 ;
}

Fixed::Fixed(const Fixed& obj) {
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj) {
	if (this == &obj)
		return *this;
	this->fixed_num_ = obj.fixed_num_;
	return *this;
}

Fixed::~Fixed(void) {}

int		Fixed::toInt(void) const { return this->fixed_num_ >> fixed_nbits_; }
float	Fixed::toFloat(void) const {
	return static_cast<float>(this->fixed_num_) / (1 << fixed_nbits_);
}
int		Fixed::getRawBits(void) const { return this->fixed_num_; }
void	Fixed::setRawBits(int const raw) { this->fixed_num_ = raw; }

bool Fixed::operator<(const Fixed& obj) const { return (*this).fixed_num_ < obj.fixed_num_; }
bool Fixed::operator>(const Fixed& obj) const { return (*this).fixed_num_ > obj.fixed_num_; }
bool Fixed::operator>=(const Fixed& obj) const { return !(*this < obj); }
bool Fixed::operator<=(const Fixed& obj) const { return !(*this > obj); }
bool Fixed::operator==(const Fixed& obj) const { return (*this).fixed_num_ == obj.fixed_num_; }
bool Fixed::operator!=(const Fixed& obj) const { return !(*this == obj); }

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
	Fixed tmp;
	if (((*this).fixed_num_ & BIT_SIGN) ^ (obj.fixed_num_ & BIT_SIGN)) {
		tmp.fixed_num_ = ((*this).fixed_num_ * obj.fixed_num_) >> fixed_nbits_;
		tmp.fixed_num_ = tmp.fixed_num_ > 0 ? ~tmp.fixed_num_ + 1 : tmp.fixed_num_;
	}
	else
		tmp.fixed_num_ = static_cast<unsigned int>(
						(*this).fixed_num_ * obj.fixed_num_) >> fixed_nbits_;
	return tmp;
}

Fixed Fixed::operator/(const Fixed& obj) const {
	Fixed tmp;
	tmp.fixed_num_ = ((*this).fixed_num_ << fixed_nbits_) / obj.fixed_num_;
	return tmp;
}

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

Fixed&	Fixed::max(Fixed& a, Fixed& b) { return a > b ? a : b; }
Fixed&	Fixed::min(Fixed& a, Fixed& b) { return a < b ? a : b; }
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) \
								{ return a.fixed_num_ > b.fixed_num_? a : b; }
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) \
								{ return a.fixed_num_ < b.fixed_num_? a : b; }

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}
