/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:03 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/19 21:49:41 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("anonymous"), _grade(150)//, _exception(0)
{
	std::cout << "[Bureaucrat Constructor called]" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)//, _exception(0)
{
	std::cout << "[Bureaucrat Constructor called]" << std::endl;
	if (this->isInvalidGrade(grade))
		throw (GradeOutOfRange());
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat)
{
	std::cout << "[Bureaucrat Copy Constructor called]" << std::endl;
	*this = Bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat destructor called]" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "[Bureaucrat Copy assignment oprator called]" << std::endl;
	if (this == &source)
		return (*this);
	// this->_name = source.getName();
	this->_grade = source.getGrade();
	return (*this);
}

bool Bureaucrat::isTooHigh(int grade)
{
	if (grade < 1)
		return (true);
	return (false);
}

bool Bureaucrat::isTooLow(int grade)
{
	if (grade > 150)
		return (true);
	return (false);
}

int Bureaucrat::isInvalidGrade(int grade)
{
	if (this->isTooHigh(grade)) // invalid value
		return (1);
	if (this->isTooLow(grade)) // invalid value
		return (2);
	return (0); // valid value
}

void Bureaucrat::increment(void)
{
	int incremented;

	incremented = this->_grade - 1;
	if (isTooHigh(incremented))
		throw (GradeTooHighException());
	setGrade(this->_grade - 1);
}

void Bureaucrat::decrement(void)
{
	int decremented;

	decremented = this->_grade + 1;
	if (isTooLow(decremented))
		throw (GradeTooLowException());
	setGrade(this->_grade + 1);
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int& Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// void Bureaucrat::setName(const std::string name)
// {
// 	this->_name = name;
// }

void Bureaucrat::setGrade(const int grade)
{
	this->_grade = grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char * Bureaucrat::GradeOutOfRange::what() const throw()
{
	return "grade out of range";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade(); // for example
	return out;
}
