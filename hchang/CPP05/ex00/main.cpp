/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:31 by hchang            #+#    #+#             */
/*   Updated: 2022/11/22 16:42:03 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	A("Test", 150);
		A.downGrade();
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what()  << RESET << '\n';
	}
}