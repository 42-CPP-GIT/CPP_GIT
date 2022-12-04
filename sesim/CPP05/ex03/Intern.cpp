/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:06:06 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 12:38:36 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*	Intern::NotExistFormNameException::what() const throw()
{
	return ("err: The Form not exist");
}

Intern::Intern()
{
	std::cout << "Intenr is hired" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	std::cout << "Intenr is Cloned" << std::endl;
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return (*this);
}

AForm*	Intern::genForm(std::string formTarget, std::string formName)
{
	switch (formTarget.find('[', 0))
	{
	case std::string::npos:
		break;
	
	default:
		{
			std::cerr << "No such that form name!" << std::endl;
			throw NotExistFormNameException();
		}
	}
	AForm*		(Intern::*f[3])(std::string) = {&Intern::genShrubberyForm, &Intern::genRobotomyForm, &Intern::genPresidentialForm};
	std::string	to_find("[" + formTarget + "]");
	std::string	checker("[shrubbery creation][robotomy request][presidential pardon]");

	switch (checker.find(to_find, 0))
	{
	case 0:
		return ((this->*f[0])(formName));
	case 20:
		return ((this->*f[1])(formName));
	case 38:
		return ((this->*f[2])(formName));
	default:
		throw NotExistFormNameException();
	}
}

AForm*	Intern::genShrubberyForm(std::string formName)
{
	std::cout << "Intern creates " << formName << " ShrubberyCreationForm." << std::endl;
	return (new ShrubberyCreationForm(formName));
}

AForm*	Intern::genRobotomyForm(std::string formName)
{
	std::cout << "Intern creates " << formName << " RobotomyRequestForm." << std::endl;
	return (new RobotomyRequestForm(formName));
}

AForm*	Intern::genPresidentialForm(std::string formName)
{
	std::cout << "Intern creates " << formName << " PresidentialPardonForm." << std::endl;
	return (new PresidentialPardonForm(formName));
}

Intern::~Intern()
{
	std::cout << "Intern is Fired" << std::endl;
}
