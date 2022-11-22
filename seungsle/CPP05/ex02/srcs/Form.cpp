/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:45 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 20:19:17 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): _name("document"), _isSigned(false), _isExecuted(false), _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "[Form Constructor called]" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _isExecuted(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->isInvalidGrade(gradeToSign) == 1)
	{
		std::cout << "gradeToSign is ";
		throw(Form::GradeTooHighException());
	}
	else if (this->isInvalidGrade(gradeToSign) == 2)
	{
		std::cout << "gradeToSign is ";
		throw(Form::GradeTooLowException());
	}
	if (this->isInvalidGrade(gradeToExecute) == 1)
	{
		std::cout << "gradeToExecute is ";
		throw(Form::GradeTooHighException());
	}
	else if (this->isInvalidGrade(gradeToExecute) == 2)
	{
		std::cout << "gradeToExecute is ";
		throw(Form::GradeTooLowException());
	}
	// std::cout << "[Form Constructor called]" << std::endl;
}

Form::Form(const Form &source): _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "[Form Copy Constructor called]" << std::endl;
	*this = source;
}

Form::~Form()
{
	// std::cout << "[Form destructor called]" << std::endl;
}

Form& Form::operator=(const Form &source)
{
	if (this == &source)
		return (*this);
	this->_isSigned = getIsSigned();
	return (*this);
}

bool Form::beSigned(void)
{
	return (this->getIsSigned());
}

void Form::signForm(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->setIsSigned(true);
	else
	{
		std::cout << "sign failed : ";
		throw(Form::GradeTooLowException());
	}
}

int Form::isInvalidGrade(int grade)
{
	if (this->isTooHigh(grade)) // invalid value
		return (1);
	if (this->isTooLow(grade)) // invalid value
		return (2);
	return (0); // valid value
}

bool Form::isTooHigh(int grade)
{
	if (grade < 1)
		return (true);
	return (false);
}

bool Form::isTooLow(int grade)
{
	if (grade > 150)
		return (true);
	return (false);
}

const std::string& Form::getName(void) const
{
	return (this->_name);
}

const bool& Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

const int& Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

const int& Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void Form::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

void Form::setIsExecuted(bool isExecuted)
{
	this->_isExecuted = isExecuted;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "grade too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "grade too low";
}

const char *Form::NotExecutableException::what(void) const throw()
{
	return "not signed";
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << Form.getName() << " form, gradeToSign : " << Form.getGradeToSign() << ", gradeToExecute : " << Form.getGradeToExecute(); // for example
	return out;
}
