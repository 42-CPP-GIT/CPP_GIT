/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:59:42 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 12:03:21 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	try
	{
		Bureaucrat	a(50);
		Intern		intern;
		AForm* form;


		try
		{
			form = intern.makeForm("shrubbery creation request", "jiny");
			a.signForm(form);
			a.executeForm(form);
			delete form;
			form = NULL;
			form = intern.makeForm("robotomy request", "hchang");
			a.signForm(form);
			a.executeForm(form);
			delete form;
			form = NULL;
			form = intern.makeForm("presidential pardon request", "sesim");
			a.signForm(form);
			a.executeForm(form);
			delete form;
			form = NULL;
		}
		catch(const std::exception& e)
		{
			if (form)
			{
				delete form;
				form = NULL;
			}
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}