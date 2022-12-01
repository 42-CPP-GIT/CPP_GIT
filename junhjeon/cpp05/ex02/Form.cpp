/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:57:19 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:53:07 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( std::string name, const int signg, const int requireg ) : _name(name), _signGrade(signg), _requireGrade(requireg)
{
	std::cout << "Form constructor" << std::endl;
	_sign = false;
}

Form::~Form()
{
	std::cout << "Form Destructor" << std::endl;
}

Form::Form( const Form &copy) : _name(copy._name), _sign(copy._sign), _signGrade(copy._signGrade), _requireGrade(copy._requireGrade)
{
	std::cout << "Form copy Constructor" << std::endl;
}

Form& Form::operator = ( const Form &f )
{
	(void) f;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", bool sign : " << f.getSign() << ", signGrade: " << f.getSignGrade() << ", requiredGrade : " << f.getRequireGrade() << std::endl;
	return (os);
}

std::string Form::getName( void ) const 
{
	return (this -> _name);
}

bool		Form::getSign( void ) const
{
	return (this -> _sign);
}

int			Form::getSignGrade( void ) const
{
	return (this->_signGrade);
}

int			Form::getRequireGrade( void ) const
{
	return (this->_requireGrade);
}

int			Form::beSigned( const Bureaucrat &b )
{
	if (_signGrade >= b.getGrade())
	{
		_sign = true;
		b.signForm(*this);
		return (true);
	}
	else
	{
		b.signForm(*this);
		return (false);
	}
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char * Form::SignError::what() const throw()
{
	return "is not Signed";
}
void		Form::setSign(bool b)
{
	_sign = b;
}
