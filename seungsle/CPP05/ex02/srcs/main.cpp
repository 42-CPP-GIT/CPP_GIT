/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 00:20:36 by seungsle         ###   ########.fr       */
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
		Form *form1 = new ShrubberyCreationForm("target");
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
		Form *form1 = new ShrubberyCreationForm("target");
		form1->sign(A);
		A.executeForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		// system("leaks Bureaucrat");
}