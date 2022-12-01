/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:21:28 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 20:41:36 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern &source)
{
	*this = source;
}

Intern::~Intern()
{

}

Intern& Intern::operator=(const Intern &source)
{
	if (this == &source)
		return (*this);
	return (*this);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form *ret;
	std::string forms("[shrubbery creation][robotomy request][presidential pardon]");

	name.insert(0, "[");
	name += "]";
	switch (forms.find(name))
	{
	case 0:
		ret = new ShrubberyCreationForm(target);
		break;
	
	case 20:
		ret = new RobotomyRequestForm(target);
		break;
	
	case 38:
		ret = new PresidentialPardonForm(target);
		break ;
	
	default:
		throw (Intern::ICannotFindFormException());
		break;
	}
	return (ret);
}

const char *Intern::ICannotFindFormException::what() const throw()
{
	return "i cannot find this type of form.......";
}