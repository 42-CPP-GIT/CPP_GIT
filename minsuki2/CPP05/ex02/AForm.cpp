/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:05:55 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 14:03:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void	AForm::checkException(void) const {
	if (this->grade_sign_ < MAX_GRADE || this->grade_excute_ < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->grade_sign_ > MIN_GRADE || this->grade_excute_ > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
}

void			AForm::checkSign(const Bureaucrat& obj_bure) const {
	if (this->signed_indicator_ == true) {
		throw AlreadySignedException();
	}
	else if (this->grade_sign_ < obj_bure.getGrade()) {
		throw GradeTooLowException();
	}
}

void			AForm::checkExec(const Bureaucrat& obj_bure) const {
	if (this->signed_indicator_ == false) {
		throw ThisIsNotSignedException();
	}
	else if (this->grade_excute_ < obj_bure.getGrade()) {
		throw GradeTooLowException();
	}
}

AForm::AForm(void)
	: name_("Unknow"), signed_indicator_(false)
	, grade_sign_(0), grade_excute_(0) {
	std::cout << MSG_AFORM << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", " << this->signed_indicator_ << ')' << std::endl;
	this->checkException();
}

AForm::AForm(const std::string& name)
	: name_(name), signed_indicator_(false)
	, grade_sign_(0), grade_excute_(0) {
	std::cout << MSG_AFORM << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", " << this->signed_indicator_ << ')' << std::endl;
	this->checkException();
}

AForm::AForm(std::string name, int grade_sign, int grade_excute)
	: name_(name), signed_indicator_(false)
	, grade_sign_(grade_sign), grade_excute_(grade_excute) {
	std::cout << MSG_AFORM << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", "
					 << std::boolalpha << this->signed_indicator_ << ", "
					 << this->grade_sign_ << ", "
					 << this->grade_excute_ << ')' << std::endl;
	this->checkException();
}

AForm::AForm(const AForm& obj)
	: name_(obj.name_), grade_sign_(obj.grade_sign_), grade_excute_(obj.grade_excute_) {
	std::cout << MSG_AFORM << MSG_C_CONSTRUCT << std::endl;
	this->checkException();
	*this = obj;
}

AForm&	AForm::operator=(const AForm& obj) {
	std::cout << MSG_AFORM << MSG_C_A_OPERATE << std::endl;

	// self assignment 처리 하면 오히려 비효율 => if (this != &obj)
	this->signed_indicator_ = obj.signed_indicator_;
	return *this;
}

AForm::~AForm(void) {
	std::cout << MSG_AFORM << this->name_ << ", " << MSG_DESTRCUT << std::endl;
}

void				AForm::setSigned(const bool sign) { this->signed_indicator_ = sign; };
const std::string&	AForm::getName(void) const { return this->name_; }
const bool&			AForm::getSignedIndicator(void) const { return this->signed_indicator_; }
const int&			AForm::getGradeExcute(void) const { return this->grade_excute_; }
const int&			AForm::getGradeSign(void) const { return this->grade_sign_; }

const char*		AForm::GradeTooHighException::what(void) const throw() { return MSG_GRADE_HIGH; }
const char*		AForm::GradeTooLowException::what(void) const throw() { return MSG_GRADE_LOW; }
const char*		AForm::AlreadySignedException::what() const throw() { return MSG_DOUBLE_SIGN; }
const char*		AForm::ThisIsNotSignedException::what() const throw() { return MSG_NO_SIGN; }

void			AForm::beSigned(const Bureaucrat& obj_bure) {
	this->checkSign(obj_bure);
	this->signed_indicator_ = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	out << "< AForm Class information >" << '\n'
		<< "--------------------------" << '\n'
		<< "· name\t\t\t: " << obj.getName() << '\n'
		<< "· signed_indicator\t: " << std::boolalpha << obj.getSignedIndicator() << '\n'
		<< "· grade_sign\t\t: " << obj.getGradeSign() << '\n'
		<< "· grade_excute\t\t: " << obj.getGradeExcute() << "\n";

	return out;
}
