/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:12:25 by hchang            #+#    #+#             */
/*   Updated: 2022/11/24 12:13:01 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*	Intern::InvalidFormNameException::what() const throw()
{
	return ("ERROR : Form Name Invalid");
}

Intern::Intern()
{
	std::cout << "[Intern default Constructor Called]\n";
}

Intern::Intern(const Intern& obj)
{
	std::cout << "[Intern Copy Constructor Called]\n";
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[Intern Destructor Called]\n";
}

Form*	Intern::makeForm(std::string formName, std::string formTarget)
{
	int	checkValidSqureBracket = formName.find('[', 0);

	switch (checkValidSqureBracket)
	{
		case static_cast<int>(std::string::npos):
			break;
		default:
			throw InvalidFormNameException();
	}
	
	std::string	to_find = "[" + formName + "]";
	std::string key = "[shrubbery creation][robotomy request][presidential pardon]";
	size_t hi = key.find(to_find, 0);

	f[0] = &Intern::makeShrubberyCreationForm;
	f[1] = &Intern::makeRobotomyRequestForm;
	f[2] = &Intern::makePresidentialPardonForm;
	
	switch (hi)
	{
		case 0:
			return (this->*f[0])(formTarget);
		case 20:
			return (this->*f[1])(formTarget);
		case 38:
			return (this->*f[2])(formTarget);
		default:
			throw InvalidFormNameException();
	}
}

Form*	Intern::makeShrubberyCreationForm(std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

Form*	Intern::makeRobotomyRequestForm(std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

Form*	Intern::makePresidentialPardonForm(std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

