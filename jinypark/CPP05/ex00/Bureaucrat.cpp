/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:53:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/28 09:07:41 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name_("jinypark")
{
	this->grade_ = 150;
}

Bureaucrat::Bureaucrat(int grade) : name_("jinypark")
{	
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade_ = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		std::string &tmp = const_cast<std::string &>(this->name_);
		
		tmp = obj.getName();
		this->grade_ = obj.getGrade();
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name_);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade_);
}

void	Bureaucrat::increment(int grade)
{
	int tmp(this->grade_ - grade);

	if (tmp < 1)
		throw (GradeTooHighException());
	this->grade_ = tmp;
}

void	Bureaucrat::decrement(int grade)
{
	int tmp(this->grade_ + grade);

	if (tmp > 150)
		throw (GradeTooLowException());
	this->grade_ = tmp;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}