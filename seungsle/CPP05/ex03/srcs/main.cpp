/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 20:45:11 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;
		Form* rrf;
		Form* rrff;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrff = someRandomIntern.makeForm("shrubbery creation", "form2");
		Bureaucrat A("seungsle", 1);
		rrf->signForm(A);
		rrf->execute(A);
		rrff->signForm(A);
		rrff->execute(A);
		// std::cout << rrf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// std::cout << "---------------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat A("seungsle", 10);
	// 	Form *form1 = new ShrubberyCreationForm("target1");
	// 	A.executeForm(*form1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << "---------------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat A("seungsle", 10);
	// 	Form *form1 = new ShrubberyCreationForm("target2");
	// 	form1->signForm(A);
	// 	A.executeForm(*form1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << "---------------------------" << std::endl;
	// try
	// {
	// 	// Bureaucrat A("seungsle", 150);
	// 	Bureaucrat A("seungsle", 142);
	// 	Form *form1 = new ShrubberyCreationForm("target3");
	// 	form1->signForm(A);
	// 	A.executeForm(*form1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << "---------------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat A("seungsle", 150);
	// 	Bureaucrat B("alvin", 1);
	// 	Form *form1 = new RobotomyRequestForm("target4");
	// 	Form *form2 = new RobotomyRequestForm("target5");
	// 	form1->signForm(A);
	// 	form2->signForm(B);
	// 	A.executeForm(*form1);
	// 	B.executeForm(*form2);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << "---------------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat A("seungsle", 1);
	// 	Bureaucrat B("alvin", 150);
	// 	Form *form1 = new RobotomyRequestForm("target6");
	// 	Form *form2 = new RobotomyRequestForm("target7");
	// 	form1->signForm(A);
	// 	A.executeForm(*form1);
	// 	form2->signForm(B);
	// 	// A.executeForm(*form1);
	// 	B.executeForm(*form2);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << "---------------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat A("seungsle", 1);
	// 	Bureaucrat B("alvin", 150);
	// 	Form *form1 = new PresidentialPardonForm("target8");
	// 	Form *form2 = new PresidentialPardonForm("target9");
	// 	form1->signForm(A);
	// 	A.executeForm(*form1);
	// 	form2->signForm(B);
	// 	// A.executeForm(*form1);
	// 	B.executeForm(*form2);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// system("leaks Bureaucrat");
}