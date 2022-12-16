/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:51:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 11:45:18 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	this->target_ = "default";
	this->setName("Shrubbery_Creation_Form");
	this->setSignGrade(SHRUBBERY_SIGN_GRADE);
	this->setExecuteGrade(SHRUBBERY_EXECUTE_GRADE);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target) : target_(target)
{
	this->setName("Shrubbery_Creation_Form");
	this->setSignGrade(SHRUBBERY_SIGN_GRADE);
	this->setExecuteGrade(SHRUBBERY_EXECUTE_GRADE);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade())
{
	*this = obj;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	this->setSigned(obj.getSigned());
	this->target_ = obj.target_;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::string str = "                                      ██▒▒▒▒██                                                  \n"
"                                      ██░░░░▒▒██      ██                                        \n"
"                                    ▓▓▒▒▒▒▒▒▒▒██    ▓▓▒▒██                                      \n"
"                                    ██░░▒▒▒▒░░░░████▒▒▒▒▒▒████                                  \n"
"                                    ██▒▒░░░░░░▒▒▒▒░░▒▒▒▒░░░░▒▒██                                \n"
"                                ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒██          ████              ████\n"
"                              ██▒▒▒▒░░▒▒▒▒▒▒██████▒▒▒▒▒▒░░░░██            ██░░██          ██░░██\n"
"                                ██░░▒▒░░▒▒████░░░░██▒▒░░▒▒▒▒██            ██  ░░██      ██░░  ██\n"
"                                  ██▒▒▒▒██░░▒▒▒▒▒▒▒▒██████▒▒██            ██    ██████████    ██\n"
"                            ▓▓██████▒▒▒▒▒▒██▒▒▒▒▓▓▒▒▒▒▒▒░░██▒▒██          ██  ░░░░░░░░▒▒▒▒░░  ██\n"
"                    ████████▒▒▒▒▒▒▒▒░░░░████▒▒▓▓▓▓▒▒▒▒▒▒██▒▒▒▒██          ██░░░░██░░░░░░██░░░░██\n"
"                  ██▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒██░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░██░░██          ██░░░░██░░░░░░██░░░░██\n"
"                  ████▒▒▒▒▒▒░░▒▒░░░░░░██░░░░░░████▒▒▒▒▒▒░░██▒▒████        ██░░░░▒▒      ▒▒░░░░██\n"
"                      ██▒▒▒▒▒▒░░▒▒▒▒▒▒████████▒▒██░░░░████▒▒▒▒▒▒▒▒██      ██░░░░  ██▓▓██  ░░░░██\n"
"                  ████░░░░▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒▒██████▒▒▒▒▒▒▒▒░░░░██        ██  ▓▓  ██  ▓▓  ██  \n"
"                ██▒▒▒▒▒▒▒▒░░░░░░░░░░▒▒▒▒░░▒▒░░░░░░▒▒▒▒▒▒░░░░░░▒▒▓▓██      ██▒▒▓▓░░▒▒▓▓▒▒░░▓▓    \n"
"                ██████▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒░░░░░░░░▒▒████        ██░░░░░░██████████      \n"
"                      ████░░░░██▒▒▒▒██████▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██  ████░░░░░░          ░░██    \n"
"                ▓▓██▓▓▒▒░░▒▒▒▒████████▓▓██░░▒▒▒▒░░▒▒▒▒██████▒▒▒▒▒▒▓▓██▒▒▓▓░░            ░░██    \n"
"              ██░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░██▓▓██▒▒██▒▒░░░░░░██▓▓▓▓████████▒▒██▒▒████          ░░██    \n"
"              ██▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒██▒▒▓▓████▓▓██▒▒▒▒▒▒██▓▓██░░░░▒▒▒▒▓▓▒▒██▒▒▒▒██      ░░░░██    \n"
"            ██░░▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒██▓▓▓▓▒▒▓▓▓▓▓▓██▒▒▒▒▓▓██▓▓██░░▒▒▒▒▒▒▓▓▓▓▒▒▓▓▒▒▒▒▓▓    ░░▓▓      \n"
"            ██░░░░▒▒██▒▒▒▒▒▒▒▒▒▒▒▒██▓▓▒▒▓▓▓▓▒▒██████▓▓▓▓▓▓▒▒████▒▒▒▒▒▒▒▒░░██░░░░▒▒██  ░░██      \n"
"          ██▒▒██████▒▒██▒▒▒▒▒▒▒▒░░░░██▓▓▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓██▒▒░░████▒▒▒▒▒▒▒▒▒▒██░░██      \n"
"        ▓▓▒▒▒▒▓▓▒▒▒▒▒▒██░░▒▒▒▒██▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓████░░▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░████    \n"
"        ██▒▒░░▒▒▒▒░░░░██░░░░░░██▒▒▒▒▒▒▒▒██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓████▒▒████▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒██▒▒▒▒██  \n"
"    ████▒▒▒▒░░░░░░▒▒▒▒▒▒██████░░▒▒▒▒░░░░██▒▒▒▒▓▓▓▓▒▒▓▓▓▓██▒▒░░▒▒▒▒▒▒▒▒░░▒▒▒▒░░░░░░░░░░▒▒▒▒▒▒██  \n"
"  ██▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒██▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓██▒▒▒▒░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██    \n"
"  ██▒▒▒▒░░▒▒▒▒▒▒▒▒░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒░░██▒▒▒▒▓▓▓▓▓▓▓▓████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░      \n"
"████▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░░░▒▒░░░░░░░░▒▒██▓▓▓▓▒▒▒▒▒▒██▒▒▒▒░░▒▒▒▒▒▒▒▒░░░░░░░░░░▒▒▒▒▒▒░░▒▒▒▒▒▒████  \n"
"██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▓▓▓▓▓▓▓▓▓▓██▒▒▒▒░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒██\n"
"██▒▒████░░░░░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒░░░░░░▒▒██▓▓▓▓▓▓██▒▒░░▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒░░░░▒▒██\n"
"  ████  ██▒▒▒▒████░░░░░░▒▒░░▒▒▒▒░░▒▒▒▒▒▒▒▒████▓▓██▒▒░░██░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒░░▒▒▒▒██  \n"
"        ██▒▒██  ██▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒██████    ████████  ██▒▒████▒▒░░░░░░░░██▒▒▒▒▒▒████▒▒████    \n"
"        ░░████  ██▒▒████▒▒▒▒▒▒░░▒▒▒▒██                  ████░░██▒▒▒▒▒▒▒▒▓▓░░▓▓▒▒██  ██▒▒██░░    \n"
"                ██████  ██▒▒▒▒▒▒▒▒██                          ██▒▒▒▒▒▒██      ████    ██        \n"
"                        ██████████                              ██▒▒██                          \n"
"                            ░░                                  ██▓▓                            \n";
	std::ofstream file(this->target_ + "_shrubbery");
	file << str;
}