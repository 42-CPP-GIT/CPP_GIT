/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:59:42 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 09:24:45 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat c(-2);
		Bureaucrat b(150);
		Bureaucrat a(200);
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat a(3);
		while(1)
		{
			std::cout << a << "\n";
			a.increment(1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	Bureaucrat	a(25);
	Form		f("FORM", 25, 1);
	Form		f2("FORM", 1, 1);
	std::cout << f;
	a.signForm(&f);
	std::cout << "-----------------\n";
	std::cout << f;
	a.signForm(&f);

	// a.signForm(&f2);
	return (0);
}