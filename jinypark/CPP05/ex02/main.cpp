/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:59:42 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/02 21:01:18 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	// try
	// {
	// 	Bureaucrat c(-2);
	// 	Bureaucrat b(150);
	// 	Bureaucrat a(200);
	// 	std::cout << b;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// try
	// {
	// 	Bureaucrat a(3);
	// 	while(1)
	// 	{
	// 		std::cout << a << "\n";
	// 		a.increment(1);
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }


	Bureaucrat	a(50);
	std::string ho("target");
	Form* form(new ShrubberyCreationForm(ho));
	Form* form1(new RobotomyRequestForm(ho));
	Form* form2(new PresidentialPardonForm(ho));

	a.signForm(form);
	a.executeForm(form);
	a.signForm(form1);
	a.executeForm(form1);
	a.signForm(form2);
	a.executeForm(form2);


	return (0);
}