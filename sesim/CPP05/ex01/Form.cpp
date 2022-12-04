/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:35:25 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:41:16 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("err: Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("err: Grade is too low");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("err: This Form is Already Signed");
}

Form::Form()
: name_("Dummy"), isSigned_(false), signGrade_(150), executeGrade_(150)
{
	std::cout << this->name_ << " form has created" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade)
: name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade)
{
	std::cout << this->name_ << " form has created" << std::endl;
}

Form::Form(const Form& obj)
: name_(obj.getName()), signGrade_(obj.getSignGrade()), executeGrade_(obj.getExecuteGrade())
{
	std::cout << this->name_ << "form copied" << std::endl;
	*this = obj;
}

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	this->isSigned_ = obj.getIsSigned();
	return (*this);
}

const std::string	Form::getName(void) const
{
	return (this->name_);
}

bool	 Form::getIsSigned(void) const
{
	return (this->isSigned_);
}

int	Form::getSignGrade(void) const
{
	return (this->signGrade_);
}

int	Form::getExecuteGrade(void) const
{
	return (this->executeGrade_);
}

void	Form::beSigned(Bureaucrat &br)
{
	if (this->getIsSigned())
	{
		std::cerr << br.getGrade() << " couldn't sign " << this->getName() << " because this Form already signed" << std::endl;
		throw Form::AlreadySignedException();
	}
	else if (br.getGrade() > this->getSignGrade())
	{
		std::cerr << br.getGrade() << " couldn't sign " << this->getName() << " because " << br.getName() << "'s grade is lower than Form" << std::endl;
		throw Form::GradeTooLowException();
	}
	setIsSigned(true);
}

void	Form::setIsSigned(bool approve)
{
	this->isSigned_ = approve;
}

Form::~Form()
{
	std::cout << this->name_ << " form shredded" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << " Form\n  Sign Grade : " << form.getSignGrade() \
	<< "\n  Execute Grade : " << form.getExecuteGrade() \
	<< "\n  Form Sign Status : " << (form.getIsSigned() ? "Yes" : "No");
	return out;
}