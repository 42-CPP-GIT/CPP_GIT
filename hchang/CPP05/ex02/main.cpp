/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:31 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 16:00:33 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	A("Test", 135);
		ShrubberyCreationForm B("Hi"); // 145 137
		// A.signForm(B);
		A.signForm(B);
		A.executeForm(B);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		
		// Bureaucrat A("test", 40);
		// RobotomyRequestForm B("hi");

		// A.signForm(B);
		// A.executeForm(B);
		// std::cout << A << std::endl;
		// std::cout << B << std::endl;

		// Bureaucrat A("test", 4);
		// PresidentialPardonForm B("hi");

		// A.signForm(B);
		// A.executeForm(B);
		// std::cout << A << std::endl;
		// std::cout << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what()  << RESET << '\n';
	}
}