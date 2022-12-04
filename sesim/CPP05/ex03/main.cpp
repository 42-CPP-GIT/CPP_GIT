/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:22:37 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 12:59:54 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void	test(void)
{
	try
	{
		Bureaucrat	K("test", 3);
		Intern		I;

		AForm*	A = I.genForm("shrubbery creation", "AA");
		AForm*	B = I.genForm("robotomy request", "BB");
		AForm*	C = I.genForm("presidential pardon", "CC");

		K.promotion();
		K.demotion();

		K.signForm(*A);
		K.executeForm(*A);
		
		std::cout << "\n" << *A << "\n" << std::endl;

		K.signForm(*B);
		K.executeForm(*B);

		std::cout << "\n" << *B << "\n" << std::endl;
		
		K.signForm(*C);
		K.executeForm(*C);
		
		std::cout << "\n" << *C << "\n" << std::endl;

		delete A;
		delete B;
		delete C;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	test();
	return (0);
}