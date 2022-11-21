/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 18:26:34 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "---------------------------" << std::endl;
	try
	{
		Bureaucrat A("seungsle", 10);
		Form *form1 = new Form("form1", 10, 5);
		A.signForm(*form1);
		// A.signForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------------------" << std::endl;
	try
	{
		Bureaucrat A("seungsle", 10);
		Form *form1 = new Form("form1", 5, 5);
		A.signForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::MyException *e)
	{
		e->printException();
		delete e;
	}
	std::cout << "---------------------------" << std::endl;
	try
	{
		Bureaucrat A("seungsle", 151);
		Form *form1 = new Form("form1", 5, 5);
		A.signForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::MyException *e)
	{
		e->printException();
		delete e;
	}
	std::cout << "---------------------------" << std::endl;
	try
	{
		Bureaucrat A("seungsle", 15);
		Form *form1 = new Form("form1", 1, 151);
		A.signForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::MyException *e)
	{
		e->printException();
		delete e;
	}
	std::cout << "---------------------------" << std::endl;
	try
	{
		Bureaucrat A("seungsle", 8);
		Form *form1 = new Form("form1", 1, 15);
		Form *form2 = new Form("form2", 10, 15);
		Form *form3 = new Form("form3", 5, 15);
		A.setForm(*form1);
		A.setForm(*form2);
		A.setForm(*form3);
		// A.signForm(0);
		// A.signForm(1);
		A.signForm(1);
		A.signForm(2);
		A.signForm(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::MyException *e)
	{
		e->printException();
		delete e;
	}
	// system("leaks Bureaucrat");
}