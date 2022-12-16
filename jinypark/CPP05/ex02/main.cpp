/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:59:42 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 13:13:00 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Bureaucrat	a(50);
	std::string ho("target");
	AForm* form(new ShrubberyCreationForm(ho));
	AForm* form1(new RobotomyRequestForm(ho));
	AForm* form2(new PresidentialPardonForm(ho));

	a.signForm(form);
	a.executeForm(form);
	a.signForm(form1);
	a.executeForm(form1);
	a.signForm(form2);
	a.executeForm(form2);

	delete form;
	delete form1;
	delete form2;


	return (0);
}