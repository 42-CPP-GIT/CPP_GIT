/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:16 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 13:06:41 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat test("5", 1);
	try
	{
		Bureaucrat a("1", 130);
		Bureaucrat b("2", 129);
		Bureaucrat c("3", 111);
		Bureaucrat d("4", 1);
		Intern	someone;
		Form*	rrf;

		ShrubberyCreationForm fs("SC FORM");
		PresidentialPardonForm fp("PP FORM");
		RobotomyRequestForm rp("RR FORM");

		d.signForm(fs);
		d.signForm(fp);
		d.signForm(rp);

		d.executeForm(fs);
		d.executeForm(fp);
		d.executeForm(rp);
		
		rrf = someone.makeForm("robotomy request", "Bender");
		//rrf = someone.makeForm("[robotomy request", "Bender");
		//rrf = someone.makeForm("someting request", "Bender");
		d.signForm(*rrf);
		d.executeForm(*rrf);

		if (!rrf)
			delete rrf;

		std::cout << a << b << c ;
	}
	catch(int& a)
	{
		std::cout << "error is occured" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
