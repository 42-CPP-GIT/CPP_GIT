/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:50:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 00:18:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationFormNoTarget", 145, 137), _target("NoTarget")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm" + target, 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source): Form("ShrubberyCreationFormNoTarget", 145, 137)
{
	*this = source;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
	if (this == &source)
		return (*this);
	this->_target = source.getTarget();
	return (*this);
}

const std::string& ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToSign() && \
		executor.getGrade() <= this->getGradeToSign())
	{
		if (this->getIsSigned())
		{
			std::ofstream file(this->_target + "_shrubbery");
			std::string my_string = "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
			file << my_string;
		}
		else
			throw(Form::NotExecutableException());
	}
	else
		throw(Form::GradeTooLowException());
}