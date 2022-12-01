/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:31 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:20:42 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	A("Test", 1);
		// A.upGrade();
		// A.downGrade();
		Form		B("sesim", false, 1, 121);
		A.signForm(B);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what()  << RESET << '\n';
	}
}