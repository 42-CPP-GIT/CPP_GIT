/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:22:37 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:38:06 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testA(void)
{
	try
	{
		Bureaucrat				A("test", 135);
		ShrubberyCreationForm	B("tree");

		A.promotion();
		A.demotion();
		A.signForm(B);
		// A.signForm(B);
		A.executeForm(B);
		std::cout << "\n" << A << std::endl;
		std::cout << "\n" << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testB(void)
{
	try
	{
		Bureaucrat			A("test", 40);
		RobotomyRequestForm	B("tree");

		A.promotion();
		A.demotion();
		A.signForm(B);
		// A.signForm(B);
		A.executeForm(B);
		std::cout << "\n" << A << std::endl;
		std::cout << "\n" << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testC(void)
{
	try
	{
		Bureaucrat				A("test", 4);
		PresidentialPardonForm	B("tree");

		A.promotion();
		A.demotion();
		A.signForm(B);
		// A.signForm(B);
		A.executeForm(B);
		std::cout << "\n" << A << std::endl;
		std::cout << "\n" << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
int	main()
{
	testA();
	testB();
	testC();
	return (0);
}