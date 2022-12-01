/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:03 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/20 18:46:56 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("anonymous"), _grade(150), _size(0)
{
	// std::cout << "[Bureaucrat Constructor called]" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _size(0)
{
	// std::cout << "[Bureaucrat Constructor called]" << std::endl;
	if (this->isInvalidGrade(grade) == 0)
		setGrade(grade);
	else if (this->isInvalidGrade(grade) == 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->isInvalidGrade(grade) == 2)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat): _size(0)
{
	// std::cout << "[Bureaucrat Copy Constructor called]" << std::endl;
	*this = Bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "[Bureaucrat destructor called]" << std::endl;
	for (int i = 0; i < this->_size; i++)
	{
		// std::cout << "delete form " << i << std::endl;
		delete this->_form[i];
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &source)
{
	// std::cout << "[Bureaucrat Copy assignment oprator called]" << std::endl;
	if (this == &source)
		return (*this);
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
		throw (Bureaucrat::GradeTooHighException());
	setGrade(this->_grade - 1);
}

void Bureaucrat::decrement(void)
{
	int decremented;

	decremented = this->_grade + 1;
	if (isTooLow(decremented))
		throw (Bureaucrat::GradeTooLowException());
	setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

void Bureaucrat::signForm(int idx)
{
	this->getFormByIndex(idx).beSigned(*this);
	// delete &this->getFormByIndex(idx);
}

bool Bureaucrat::isExistInDB(Form &form)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_form[i] && (&form) == this->_form[i])
			return (true);
	}
	return (false);
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int& Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

Form& Bureaucrat::getFormByIndex(int idx)
{
	if (idx < this->_size)
		return (*this->_form[idx]);
	else
		throw (Bureaucrat::InvalidIndexForm());
}

void Bureaucrat::setGrade(const int grade)
{
	this->_grade = grade;
}

int Bureaucrat::setForm(Form &form)// const
{
	if (this->_size >= 100)
	{
		delete &form;
		throw (Bureaucrat::FormsAreFullException());
	}
	this->_form[this->_size++] = &form;
	std::cout << form.getName() << " is saved to index : " << this->_size - 1 << std::endl;
	return (this->_size - 1);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char * Bureaucrat::FormsAreFullException::what() const throw()
{
	return "forms are full";
}

const char * Bureaucrat::InvalidIndexForm::what() const throw()
{
	return "invalid form index";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade(); // for example
	return out;
}

Bureaucrat::MyException::MyException(Form &form, Bureaucrat &bureaucrat): _form(form), _bureaucrat(bureaucrat)
{
	// std::cout << "[Bureaucrat::MyException Constructor called]" << std::endl;
}

Bureaucrat::MyException::~MyException()
{
	// std::cout << "[Bureaucrat::MyException Destructor called]" << std::endl;
	if (this->_bureaucrat.isExistInDB(this->_form))
		return ;
	delete &this->_form;
}

void Bureaucrat::MyException::printException()
{
	// std::cout << "[Bureaucrat::MyException printException called]" << std::endl;
	std::cerr << "grade too low" << std::endl;
}