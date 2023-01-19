/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:08:46 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 11:48:43 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "color.h"

int main()
{
	{
		std::cout << std::endl << std::endl
				  << BOLDCYAN << " --- Basic Test --- " << RESET << std::endl;
		try
		{
			Bureaucrat	A("A", 150);
			Bureaucrat	B("B", -1);

			A.incrementGrade(); // 149
			// A.decrementGrade(); // 151
			std::cout << A << std::endl;
			A = B;
			std::cout << A << std::endl;
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
	}

	{
		std::cout << std::endl << std::endl
				  << BOLDBLUE << " --- Overlap Test --- " << RESET << std::endl;
		try {
			try {
				Bureaucrat test("test", 200);
				Bureaucrat unknow;
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}

			std::cout << std::endl;
			Bureaucrat a("a", 150);
			Bureaucrat b("b", 1);

			std::cout << a << std::endl;
			std::cout << b << std::endl;

			std::cout << std::endl << MAGENTA << "< operatoration > a↑ b↓" << RESET << std::endl;
			a.incrementGrade();
			b.decrementGrade();

			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << std::endl;
            //

			std::cout << std::endl << YELLOW << "< operatoration > a↓ b↑" << RESET << std::endl;
			a.decrementGrade();
			b.incrementGrade();
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << std::endl;

			Bureaucrat c("c");
			std::cout << c << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
