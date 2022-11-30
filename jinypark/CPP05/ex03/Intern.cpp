/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:13:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 21:26:30 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Form*	Intern::makeForm(std::string formName, std::string target)
{
	std::string formArr[3] = {"shrubbery creation request", "robotomy request", "presidential pardon request"};

	int i = 0;
	for (; formArr[i].compare(formName) && i < 3; ++i)
		;
	switch (i)
	{
	case 0:
		return (new ShrubberyCreationForm(target));		
	case 1:
		return (new RobotomyRequestForm(target));		
	case 2:
		return (new PresidentialPardonForm(target));
	default:
		break;
	}
	return 0;
}
