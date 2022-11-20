/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 00:41:18 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "---------------------------" << std::endl;
	try
	{
		Bureaucrat A("seungsle", 10);
		Form *form1 = new ShrubberyCreationForm("target1");
		A.executeForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------------------" << std::endl;
	try
	{
		Bureaucrat A("seungsle", 10);
		Form *form1 = new ShrubberyCreationForm("target2");
		form1->sign(A);
		A.executeForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------------------" << std::endl;
	try
	{
		// Bureaucrat A("seungsle", 150);
		Bureaucrat A("seungsle", 142);
		Form *form1 = new ShrubberyCreationForm("target3");
		form1->sign(A);
		A.executeForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// try
	// {
	// 	Bureaucrat A("seungsle", 150);
	// 	Form *form1 = new ShrubberyCreationForm("target3");
	// 	form1->sign(A);
	// 	A.executeForm(*form1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
		// system("leaks Bureaucrat");
}