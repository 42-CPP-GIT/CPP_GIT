/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:36:08 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 21:01:35 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("default"), isSigned_(0), signGrade_(50), executeGrade_(50)
{
}

AForm::AForm(const std::string name, const int signedGrade, const int executeGrade) :
name_(name), isSigned_(0), signGrade_(signedGrade), executeGrade_(executeGrade)
{
	if (this->signGrade_ < 1 || this->executeGrade_ < 1)
		throw GradeTooHighException();
	else if (this->signGrade_ > 150 || this->executeGrade_ > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

void	AForm::beSigned(const Bureaucrat& applicant)
{
	if (applicant.getGrade() > this->signGrade_)
		throw GradeTooLowException();
	this->isSigned_ = true;
}

bool	AForm::getSigned(void) const
{
	return (this->isSigned_);
}

int	AForm::getSignGrade() const
{
	return (this->signGrade_);
}
int	AForm::getExecuteGrade() const
{
	return (this->executeGrade_);
}

const std::string&	AForm::getName() const
{
	return (this->name_);
}

void	AForm::setSigned(bool i)
{
	this->isSigned_ = i;
}
void	AForm::setSignGrade(int grade)
{
	const_cast<int &>(this->signGrade_) = grade;
}

void	AForm::setExecuteGrade(int grade)
{
	const_cast<int &>(this->executeGrade_) = grade;
}

void	AForm::setName(const std::string& name)
{
	const_cast<std::string &>(this->name_) = name;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("Form not signed");
}

std::ostream& operator<<(std::ostream& os, AForm& obj)
{
	os << "name: " << obj.getName() << "\n";
	os << "sign grade: " << obj.getSignGrade() << "\n";
	os << "execute grade: " << obj.getExecuteGrade() << "\n";
	os << "signed: " << std::boolalpha << obj.getSigned() << "\n";
	return (os);
}
