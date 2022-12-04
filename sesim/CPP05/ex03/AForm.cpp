/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:35:25 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:41:03 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("err: Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("err: Grade is too low");
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("err: This AForm is Already Signed");
}

AForm::AForm()
: name_("Dummy"), isSigned_(false), signGrade_(150), executeGrade_(150)
{
	std::cout << this->name_ << " AForm has created" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade)
: name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade)
{
	std::cout << this->name_ << " AForm has created" << std::endl;
}

AForm::AForm(const AForm& obj)
: name_(obj.getName()), signGrade_(obj.getSignGrade()), executeGrade_(obj.getExecuteGrade())
{
	std::cout << this->name_ << "AForm copied" << std::endl;
	*this = obj;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this == &obj)
		return (*this);
	this->isSigned_ = obj.getIsSigned();
	return (*this);
}

const std::string	AForm::getName(void) const
{
	return (this->name_);
}

bool	 AForm::getIsSigned(void) const
{
	return (this->isSigned_);
}

int	AForm::getSignGrade(void) const
{
	return (this->signGrade_);
}

int	AForm::getExecuteGrade(void) const
{
	return (this->executeGrade_);
}

void	AForm::beSigned(Bureaucrat &br)
{
	if (this->getIsSigned())
	{
		std::cerr << br.getGrade() << " couldn't sign " << this->getName() << " because this AForm already signed" << std::endl;
		throw AForm::AlreadySignedException();
	}
	else if (br.getGrade() > this->getSignGrade())
	{
		std::cerr << br.getGrade() << " couldn't sign " << this->getName() << " because " << br.getName() << "'s grade is lower than AForm" << std::endl;
		throw AForm::GradeTooLowException();
	}
	setIsSigned(true);
}

void	AForm::setIsSigned(bool approve)
{
	this->isSigned_ = approve;
}

AForm::~AForm()
{
	std::cout << this->name_ << " AForm shredded" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const AForm& AForm)
{
	out << AForm.getName() << " AForm\n  Sign Grade : " << AForm.getSignGrade() \
	<< "\n  Execute Grade : " << AForm.getExecuteGrade() \
	<< "\n  AForm Sign Status : " << (AForm.getIsSigned() ? "Yes" : "No");
	return out;
}