/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:34 by hchang            #+#    #+#             */
/*   Updated: 2022/11/23 15:59:49 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
		return ("ERROR : Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
		return ("ERROR : Grade Too Low");
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "[Bureaucrat default Constructor Called]\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "[Bureaucrat parameter Constructor Called]\n";
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	std::cout << "[Bureaucrat Copy Constructor Called]\n";
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this == &obj)
		return (*this);
	this->_grade = obj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat Destructor Called]\n";
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::upGrade()
{
	if (_grade < 2)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downGrade()
{
	if (_grade > 149)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.beSigned(*this))
	{
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		form.setIsSigned(true);
	}
	else
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() << " because ";
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << BLE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
	return out;
}
