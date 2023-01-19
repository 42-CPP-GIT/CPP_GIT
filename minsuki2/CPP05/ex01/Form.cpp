/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:05:55 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 14:04:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	Form::checkException(void) const {
	if (this->grade_sign_ < MAX_GRADE || this->grade_excute_ < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->grade_sign_ > MIN_GRADE || this->grade_excute_ > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Form::Form(void)
	: name_("Unkwon"), signed_indicator_(false)
	  , grade_sign_(0), grade_excute_(0) {
	std::cout << MSG_FORM << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", " << this->signed_indicator_ << ')' << std::endl;
	this->checkException();
}

Form::Form(const std::string& name)
	: name_(name), signed_indicator_(false)
	  , grade_sign_(0), grade_excute_(0) {
	std::cout << MSG_FORM << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", " << this->signed_indicator_ << ')' << std::endl;
	this->checkException();
}

Form::Form(std::string name, int grade_sign, int grade_excute)
	: name_(name), signed_indicator_(false)
	  , grade_sign_(grade_sign), grade_excute_(grade_excute) {
	std::cout << MSG_FORM << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", "
					 << std::boolalpha << this->signed_indicator_ << ", "
					 << this->grade_sign_ << ", "
					 << this->grade_excute_ << ')' << std::endl;
	this->checkException();
}

Form::Form(const Form& obj)
	: name_(obj.name_), grade_sign_(obj.grade_sign_), grade_excute_(obj.grade_excute_) {
	std::cout << MSG_FORM << MSG_C_CONSTRUCT << std::endl;
	this->checkException();
	*this = obj;
}

Form&	Form::operator=(const Form& obj) {
	std::cout << MSG_FORM << MSG_C_A_OPERATE << std::endl;

	// self assignment 처리 하면 오히려 비효율 => if (this != &obj)
	this->signed_indicator_ = obj.signed_indicator_;
	return *this;
}

Form::~Form(void) {
	std::cout << MSG_FORM << this->name_ << ", " << MSG_DESTRCUT << std::endl;
}

const std::string&	Form::getName(void) const { return this->name_; }
const bool&			Form::getSignedIndicator(void) const { return this->signed_indicator_; }
const int&			Form::getGradeExcute(void) const { return this->grade_excute_; }
const int&			Form::getGradeSign(void) const { return this->grade_sign_; }

const char*			Form::GradeTooHighException::what(void) const throw() { return MSG_GRADE_HIGH; }
const char*			Form::GradeTooLowException::what(void) const throw() { return MSG_GRADE_LOW; }
const char*			Form::AlreadySignedException::what() const throw() { return MSG_DOUBLE_SIGN; }

void			Form::beSigned(const Bureaucrat& obj_bure) {
	if (this->signed_indicator_ == true) {
		throw AlreadySignedException();
	}
	else if (this->grade_sign_ < obj_bure.getGrade()) {
		throw GradeTooLowException();
	}
	this->signed_indicator_ = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << "< Form Class information >" << '\n'
		<< "-----------------------------------" << '\n'
		<< "· name\t\t\t: " << obj.getName() << '\n'
		<< "· signed_indicator\t: " << std::boolalpha << obj.getSignedIndicator() << '\n'
		<< "· grade_sign\t\t: " << obj.getGradeSign() << '\n'
		<< "· grade_excute\t\t: " << obj.getGradeExcute() << "\n";

	return out;
}
