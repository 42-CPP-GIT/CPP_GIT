/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:19:29 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 12:31:27 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

const std::string ShrubberyCreationForm::shrubbery =\
								"               ,@@@@@@@,					\n"
								"       ,,,.   ,@@@@@@/@@,  .oo8888o.		\n"
								"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o		\n"
								"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'	\n"
								"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'	\n"
								"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'	\n"
								"   `&%\\ ` /%&'    |.|        \\ '|8'		\n"
								"       |o|        | |         | |			\n"
								"       |.|        | |         | |			\n"
								"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
	: AForm(name, SH_SIGN, SH_EXEC) {
	std::cout << MSG_SHRUBBERYCREATIONFORM << MSG_D_CONSTRUCT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExcute()) {
	std::cout << MSG_SHRUBBERYCREATIONFORM << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	std::cout << MSG_SHRUBBERYCREATIONFORM << MSG_C_A_OPERATE << std::endl;
	this->setSigned(obj.getSignedIndicator());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << MSG_SHRUBBERYCREATIONFORM << MSG_DESTRCUT << std::endl;
}

const char*		ShrubberyCreationForm::NoSpaceException::what() const throw() { return MSG_NO_SPACE; }

void		ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	this->checkExec(executor);
	std::ofstream ofs;
	ofs.open(this->getName() + "_shrubbery");
	if (ofs.fail()) {			 // ex) 용량이 꽉찼을 때
		throw NoSpaceException();
	}
	ofs << ShrubberyCreationForm::shrubbery;
	ofs.close();
}
