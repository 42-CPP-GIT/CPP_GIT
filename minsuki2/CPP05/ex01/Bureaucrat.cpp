/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:05:55 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/11 17:20:56 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::checkException(void) const {
	if (this->grade_ < MAX_GRADE) { throw Bureaucrat::GradeTooHighException(); }
	else if (this->grade_ > MIN_GRADE) { throw Bureaucrat::GradeTooLowException(); }
}

Bureaucrat::Bureaucrat(void) : name_("Unkwon"), grade_(0) {
	std::cout << MSG_BREAUCRAT << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", " << this->grade_ << ')' << std::endl;
	this->checkException();
}

Bureaucrat::Bureaucrat(const std::string& name) : name_(name), grade_(0) {
	std::cout << MSG_BREAUCRAT << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", " << this->grade_ << ')' << std::endl;
	this->checkException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	std::cout << MSG_BREAUCRAT << MSG_D_CONSTRUCT << ' '
			  << '(' << this->name_ << ", " << this->grade_ << ')' << std::endl;
	this->checkException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
	std::cout << MSG_BREAUCRAT << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj) {
	std::cout << MSG_BREAUCRAT << MSG_C_A_OPERATE << std::endl;

	// self assignment 처리 하면 오히려 비효율 => if (this != &obj)
	this->name_ = obj.name_;
	this->grade_ = obj.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << MSG_BREAUCRAT << this->name_ << ", " << MSG_DESTRCUT << std::endl;
}

const std::string&	Bureaucrat::getName(void) const { return this->name_; }
const int&			Bureaucrat::getGrade(void) const { return this->grade_; }
void				Bureaucrat::incrementGrade(void) {
	--this->grade_;
	this->checkException();
}
void				Bureaucrat::decrementGrade(void) {
	++this->grade_;
	this->checkException();
}

const char*		Bureaucrat::GradeTooHighException::what(void) const throw() \
												{ return "Grade too high..."; }
const char*		Bureaucrat::GradeTooLowException::what(void) const throw() \
												{ return "Grade too low..."; }

void				Bureaucrat::signForm(Form& obj_form) const {
	try {
		obj_form.beSigned(*this);
		std::cout << this->name_ << MSG_SIGNED
				  << obj_form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << this->name_ << MSG_NOT_SIGNED
				  << obj_form.getName() << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << MSG_GRADE << obj.getGrade() << ".";
	return out;
}
