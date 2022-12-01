/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:28:03 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:24:11 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : Form(name, 145, 137)
{
	std::cout << "scform constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "scform destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : Form(copy.getName(), 145, 137)
{
	this->setSign(copy.getSign());
	std::cout << "scform copy" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = ( const ShrubberyCreationForm &s )
{
	(void) s;
	return (*this);
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{	
	if (this->getSign() == false)
		throw ShrubberyCreationForm::SignError();
	if (this->getRequireGrade() > executor.getGrade())
	{
		std::cout << executor.getName() << " execute " << this->getName() << std::endl;
		ShrubberyCreationForm::creatTree();
	}
	else
		throw ShrubberyCreationForm::lowExecuteGrade();
}

void	ShrubberyCreationForm::creatTree( void ) const
{
	std::string filename;

	filename = this->getName();
	filename += "_shrubbery";
	std::ofstream File(filename);
	if(File.fail())
		throw lowExecuteGrade();

	File << "     ^^ " << std::endl
		 << "    ^^^^" << std::endl
		 << "   ^^^^^^"<< std::endl
		 << "     |    "<< std::endl
		 << "  ------l--"<< std::endl;

	File.close();
}

const char * ShrubberyCreationForm::lowExecuteGrade::what() const throw()
{
	return "too low execute grade !";
}
