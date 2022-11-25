/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:31 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 16:39:25 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	X("Test", 2);

		Intern	A;

		Form *B = A.makeForm("shrubbery creation", "test");
		Form *C = A.makeForm("robotomy request", "test2");
		Form *D = A.makeForm("presidential pardon", "test3");

		X.signForm(*B);
		X.executeForm(*B);

		X.signForm(*C);
		X.executeForm(*C);

		X.signForm(*D);
		X.executeForm(*D);
		std::cout << *B << std::endl;
		std::cout << *C << std::endl;
		std::cout << *D << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what()  << RESET << '\n';
	}
}