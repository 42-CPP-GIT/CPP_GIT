/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:20:25 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:18:54 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("ERROR : Grade Too High");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("ERROR : Grade Too Low");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("ERROR : Already Signed");
}

Form::Form() : _name("Default"), _isSigned(false), _signGrade(1), _executeGrade(75)
{
	std::cout << "[Form default Constructor Called]\n";
}

Form::Form(std::string name, bool sign, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "[Form parameter Constructor Called]\n";
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
	else if (executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (executeGrade > 150)
		throw Form::GradeTooLowException();
	else
		_isSigned = sign;
}

Form::Form(const Form& obj) : _name(obj.getName()), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade)
{
	std::cout << "[Form Copy Constructor Called]\n";
	*this = obj;
}

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	this->_isSigned = obj._isSigned;
	return (*this);
}

void	Form::beSigned(Bureaucrat &br)
{

	if (br.getGrade() > _signGrade)
	{
		std::cerr << br.getName() << " couldn't sign " << this->getName() << " because " << br.getName() << "'s grade is lower than Form\n";
		throw Form::GradeTooLowException();
	}
	else if (this->getIsSigned())
	{
		std::cerr << br.getName() << " couldn't sign " << this->getName() << " because this form already signed.\n";
		throw Form::AlreadySignedException();
	}
	setIsSigned(true);
}

Form::~Form()
{
	std::cout << "[Form Destructor Called]\n";
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << YEL << form.getName() << ", Form Sign Grade " << form.getSignGrade() << ", Form Execute Grade " << form.getExecuteGrade() << "\n▶︎ Signed Check : " << form.getIsSigned() << RESET;
	return out;
}

void	Form::setIsSigned(bool otherSign)
{
	this->_isSigned = otherSign;
}
