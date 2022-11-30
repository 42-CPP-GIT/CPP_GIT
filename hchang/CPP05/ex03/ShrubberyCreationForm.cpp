/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:40:49 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:39:51 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

const char*	ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("ERROR : File Failed To Open");
}

const char*	ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return ("ERROR : Form Not Signed");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : Form(name, false, 145, 137)
{
	std::cout << "[ShrubberyCreationForm Constructor Called]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
	std::cout << "[ShrubberyCreationForm Copy Constructor Called]" << std::endl;
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return (*this);
	this->setIsSigned(obj.getIsSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm Destructor Called]" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because this Form is already signed.\n";
		throw NotSignedException();
	}
	else if (executor.getGrade() > this->getExecuteGrade())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because " << executor.getName() << "'s grade is too low.\n";
		throw Form::GradeTooLowException();
	}
	std::ofstream out(executor.getName() + "_shrubbery");
	if (out.fail())
		throw FileNotOpenException();
	else
	{
		out << \
		"	              _{\\ _{\\{\\/}/}/}__\n"
		"				{/{/\\}{/{/\\}(\\}{/\\} _\n"
		"				{/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
		"			{\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
		"			{/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
		"		_{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
		"		{/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
		"		_{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
		"		{/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
		"		{\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
		"		{/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
		"		{/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
		"		{/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
		"			{/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
		"			(_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
		"				{/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
		"				{/{\\{\\{\\/}/}{\\{\\\\}/}\n"
		"				{){/ {\\/}{\\/} \\}\\}\n"
		"				(_)  \\.-'.-/\n"
		"			__...--- |'-.-'| --...__\n"
		"	_...--    .-'   |'-.-'|  ' -.  ""--..__ \n"
		"	-     ' .  . '    |.'-._| '  . .  '    | \n"
		"	.  '-  '    .--'  | '-.'|    .  '  . '\n"
		"			' ..     |'-_.-|\n"
		"	.  '  .       _.-|-._ -|-._  .  '  .\n"
		"				.'   |'- .-|   '.\n"
		"	..-'   ' .  '.   `-._.-'   .'  '  - .\n"
		"	.-' '        '-._______.-'     '  .\n"
		"			.      ~, \n"
		"		.       .   |\\   .    ' '-.\n"
		"	  _____________/  \\____________\n"
		"  	 /   ShrubberyCreationForm     \\ \n"
		"	 |       Excute       Called   |\n"
		"	 \\____________________________/\n";
	}
	out.close();
}

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& sh)
{
	out << GRN << sh.getName() << ", ShrubberyCreationForm Sign Grade " << sh.getSignGrade() << ", shrubberyCreationForm Execute Grade " << sh.getExecuteGrade() << "\n▶︎ Signed Check : " << sh.getIsSigned() << RESET;
	return out;
}



