/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:36:08 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/10 19:03:27 by jinypark         ###   ########.fr       */
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

Form::Form(const Form& obj) :
name_(obj.getName()), isSigned_(obj.getSigned()), signGrade_(obj.getSigned()), executeGrade_(obj.getExecuteGrade())
{
}

Form	&Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		std::string &tmpName = const_cast<std::string &>(this->name_);
		int			&tmpSign = const_cast<int &>(this->signGrade_);
		int			&tmpExecute = const_cast<int &>(this->executeGrade_);

		this->isSigned_ = obj.isSigned_;
		tmpName = obj.getName();
		tmpSign = obj.getSignGrade();
		tmpExecute = obj.getExecuteGrade();

	}
	return (*this);
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
