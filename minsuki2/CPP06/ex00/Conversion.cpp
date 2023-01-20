/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:05:55 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/20 21:33:48 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(double val, const std::string& end)
	: flag_(FLAG_REG)
	, val_char_(static_cast<char>(val))
	, val_int_(static_cast<int>(val))
	, val_float_(static_cast<float>(val))
	, val_double_(val) {
	// std::cout << MSG_COVERSION << MSG_DEFAULT_CONSTRUCT << std::endl;
	this->checkVaildArgument(val, end);
}

Conversion::Conversion(const Conversion& obj)
	: val_char_(obj.val_char_)
	, val_int_(obj.val_int_)
	, val_float_(obj.val_float_)
	, val_double_(obj.val_double_) {
	// std::cout << MSG_COVERSION << MSG_COPY_CONSTRUCT << std::endl;
	*this = obj;
}

Conversion&	Conversion::operator=(const Conversion& obj) {
	// std::cout << MSG_COVERSION << MSG_COPY_ASSIGN_OPERATE << std::endl;
	this->flag_ = obj.flag_;
	return *this;
}

Conversion::~Conversion(void) {
	// std::cout << MSG_COVERSION << MSG_DESTRCUT << std::endl;
}

void	Conversion::setFlag(const float val) {
	int bit;
	std::memcpy(&bit, &val, sizeof(float));
	if ((bit & BIT_FLOAT_EXPONENT) >= BIT_FLOAT_EXPONENT) {
		if (bit & BIT_FLOAT_MANTISSA)
			this->flag_ |= FLAG_NAN;
		else
			this->flag_ |= FLAG_INF;
	}
}

void	Conversion::checkVaildArgument(const double& val, const std::string& end) {
	this->setFlag(static_cast<float>(val));
	if (end != ""
		&& (end.at(0) != 'f' || (end.length() != 1 && end.at(0) == 'f'))) {
		std::cout << "end point : " << RED << end << RESET << std::endl;
		throw Conversion::ArgumentInputException();
	}
}

const char& Conversion::getFlag(void) const { return flag_; }
const char& Conversion::getChar(void) const { return val_char_; }
const int& Conversion::getInt(void) const { return val_int_; }
const float& Conversion::getFloat(void) const { return val_float_; }
const double& Conversion::getDouble(void) const { return val_double_; }

void	Conversion::printChar(void) const {
	if (this->flag_) {
		std::cout << MSG_CHAR << MSG_IMPOSSIBLE;
	}
	else {
		if (std::isprint(this->val_int_)) {
			std::cout << MSG_CHAR << '\'' << this->val_char_ << '\'';
		}
		else {
			std::cout << MSG_CHAR << MSG_NON_DISPLAY;
		}
	}
	std::cout << std::endl;
}

void	Conversion::printInt(void) const {
	std::cout << MSG_INT;
	if (this->flag_ || (this->val_double_ > static_cast<double>(INT_MAX)
						&& this->val_double_ < static_cast<double>(INT_MIN))) {
		std::cout << MSG_IMPOSSIBLE;
	}
	else {
			std::cout << this->val_int_;
	}
	std::cout << std::endl;
}

void	Conversion::checkNeedPrecision(const double value) const {
	if (std::fabs(value) - std::abs(this->val_int_) < std::numeric_limits<double>::epsilon()) {
		std::cout << ".0";
	}
}

void	Conversion::printFloat(void) const {
	std::cout << MSG_FLOAT;
	if (this->flag_) {
		std::cout << this->val_float_ << 'f'; // inff, nanf 전에 출력
	}
	else if (std::fabs(this->val_double_ > static_cast<double>(__FLT_MAX__))) {
		std::cout << MSG_IMPOSSIBLE;	// 3.402823466E+38
	}
	else {
		std::cout << this->val_float_;
		checkNeedPrecision(static_cast<double>(this->val_float_));
		std::cout << 'f';
	}
	std::cout << std::endl;
}

void	Conversion::printDouble(void) const { std::cout << MSG_DOUBLE;
	std::cout << this->val_double_;
	checkNeedPrecision(this->val_double_);
	std::cout << std::endl;
}

const char*	Conversion::ArgumentCountsException::what(void) const throw() {
	return "Argument counts is wrong";
}

const char* Conversion::ArgumentInputException::what(void) const throw() {
	return "Argument input is wrong";
}

const char* Conversion::EndPointerException::what(void) const throw() {
	return "End Pointer can not be NULL pointer";
}

const char* Conversion::JustFloatCharException::what(void) const throw() {
	return "only input 'f' is wrong";
}
