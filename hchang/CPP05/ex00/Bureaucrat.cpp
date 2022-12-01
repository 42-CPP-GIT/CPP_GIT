/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:34 by hchang            #+#    #+#             */
/*   Updated: 2022/11/22 16:38:05 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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


std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << BLE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
	return out;
}
