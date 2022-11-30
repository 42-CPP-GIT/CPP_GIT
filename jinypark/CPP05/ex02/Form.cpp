/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:36:08 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 09:42:33 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("default"), isSigned_(0), signGrade_(50), executeGrade_(50)
{
}

Form::Form(const std::string name, const int signedGrade, const int executeGrade) :
name_(name), isSigned_(0), signGrade_(signedGrade), executeGrade_(executeGrade)
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

void	Form::setSigned(bool i)
{
	this->isSigned_ = i;
}
void	Form::setSignGrade(int grade)
{
	const_cast<int &>(this->signGrade_) = grade;
}

void	Form::setExecuteGrade(int grade)
{
	const_cast<int &>(this->executeGrade_) = grade;
}

void	Form::setName(const std::string& name)
{
	const_cast<std::string &>(this->name_) = name;
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
