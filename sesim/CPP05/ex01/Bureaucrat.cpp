/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:34:58 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 00:07:16 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("err: Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("err: Grade is too low");
}	

Bureaucrat::Bureaucrat() : name_("Intern"), grade_(150)
{
	std::cout << this->getName() << " is hired" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
	std::cout << this->getName() << " Bureaucrat is hired" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	std::cout << this->getName() << " Bureaucrat Cloned" << std::endl;
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this == &obj)
		return (*this);
	const_cast<std::string &>(this->name_) = obj.getName();
	this->grade_ = obj.getGrade();
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->name_);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade_);
}

void	Bureaucrat::promotion(void)
{
	if (this->grade_ < 2)
		throw Bureaucrat::GradeTooHighException();
	--this->grade_;
}

void	Bureaucrat::demotion(void)
{
	if (this->grade_ > 149)
		throw Bureaucrat::GradeTooLowException();
	++this->grade_;
}

void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
	if (form.getIsSigned())
		std::cout << this->name_ << " signed " << form.getName() << "." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " is Fired" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
