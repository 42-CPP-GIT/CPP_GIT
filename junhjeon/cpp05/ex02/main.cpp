/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:16 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:29:18 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("1", 149);
		Bureaucrat b("2", 129);
		Bureaucrat c("3", 111);
		Bureaucrat d("4", 1);

		ShrubberyCreationForm fs("SC FORM");
		PresidentialPardonForm fp("PP FORM");
		RobotomyRequestForm rp("RR FORM");

		d.signForm(fs);
		d.signForm(fp);
		d.signForm(rp);

		d.executeForm(fs);
		d.executeForm(fp);
		d.executeForm(rp);
		

		std::cout << a << b << c ;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
