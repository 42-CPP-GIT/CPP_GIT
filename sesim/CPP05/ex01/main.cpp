/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:22:37 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:42:34 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	A("test", 2);
		Form		B("form", 1, 30);

		std::cout << "\n" << B << std::endl;
		std::cout << "\n";
		A.promotion();
		// A.demotion();
		A.signForm(B);
		std::cout << "\n";
		std::cout << B << std::endl;
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
}