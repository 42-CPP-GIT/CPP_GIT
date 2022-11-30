/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:36:08 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 09:22:58 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("default"), signGrade_(50), executeGrade_(50)
{
}

Form::Form(const std::string name, const int signedGrade, const int executeGrade) :
name_(name), signGrade_(signedGrade), executeGrade_(executeGrade)
{
	if (this->signGrade_ < 1 || this->executeGrade_ < 1)
		throw GradeTooHighException();
	else if (this->signGrade_ > 150 || this->executeGrade_ > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
}

void	Form::beSigned(const Bureaucrat& applicant)
{
	if (applicant.getGrade() > this->signGrade_)
		throw GradeTooLowException();
	if (this->isSigned_ == true)
		throw std::exception();
	this->isSigned_ = true;
}

bool	Form::getSigned(void) const
{
	return (this->isSigned_);
}

int	Form::getSignGrade() const
{
	return (this->signGrade_);
}
int	Form::getExecuteGrade() const
{
	return (this->executeGrade_);
}

const std::string&	Form::getName() const
{
	return (this->name_);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

std::ostream& operator<<(std::ostream& os, Form& obj)
{
	os << "name: " << obj.getName() << "\n";
	os << "sign grade: " << obj.getSignGrade() << "\n";
	os << "execute grade: " << obj.getExecuteGrade() << "\n";
	os << "signed: " << std::boolalpha << obj.getSigned() << "\n";
	return (os);
}
