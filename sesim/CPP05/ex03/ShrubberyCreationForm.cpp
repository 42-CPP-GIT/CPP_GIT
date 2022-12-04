/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:31:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:38:48 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

const char*	ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("err : File Cannot Open");
}

const char*	ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return ("err : Form Not Signed");
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyDefault", 145, 137)
{
	std::cout << "ShrubberyCreation Default Form Created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
	std::cout << name << " : ShrubberyCreation Form Created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
	std::cout << obj.getName() << " : ShrubberyCreation Form Copied" << std::endl;
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return (*this);
	this->setIsSigned(obj.getIsSigned());
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because this Form is already signed" << std::endl;
		throw NotSignedException();
	}
	else if (executor.getGrade() > this->getExecuteGrade())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because " << executor.getName() << "'s execution grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::ofstream	out(executor.getName() + "_shrubbery");
	if (out.fail())
		throw FileNotOpenException();
	else
		out << ASCII_TREE;
	out.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->getName() << " : Form shredded" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm sh)
{
	out << sh.getName() << " Form\n  Sign Grade : " << sh.getSignGrade() \
	<< "\n  Execute Grade : " << sh.getExecuteGrade() \
	<< "\n  Form Sign Status : " << (sh.getIsSigned() ? "Yes" : "No");
	return out;
}