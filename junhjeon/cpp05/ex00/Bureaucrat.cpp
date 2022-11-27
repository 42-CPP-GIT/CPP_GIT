/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:46:18 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 14:30:19 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor " << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Destructor" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy )
{
	std::cout << "copy constructor " << std::endl;
	*this = copy;
}

Bureaucrat& Bureaucrat::operator = ( const Bureaucrat &b )
{
	std::cout << " = constructor " << std::endl;
	if (this != &b)
	{
		std::string &temp = const_cast<std::string &> (_name);
		temp = b.getName();
		_grade = b.getGrade();

	}
	return (*this);
}

const std::string Bureaucrat::getName( void ) const
{
	return (this -> _name);
}

int	Bureaucrat::getGrade( void ) const 
{
	return (this -> _grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (os);
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

void	Bureaucrat::incre( void )
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade --;
}

void	Bureaucrat::decre( void )
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade ++;
}
