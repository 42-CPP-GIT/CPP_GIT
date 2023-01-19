/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:08:46 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 11:32:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "Form.hpp"

void	testName(const std::string& title) {
	std::cout	<< std::endl
				<< " --- " << title << " --- "
				<< std::endl << std::endl;
}

int	main() {
	Bureaucrat	burro("burro", 42);
	std::cout << GREEN << burro << RESET << std::endl;

	std::cout << BOLDWHITE; testName("constructor"); std::cout << RESET;
	try {
		Form	formaccio("formaccio", 1000, 1);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Form	formaccio("formaccio", 42, 0);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << BOLDRED; testName("Sign twice"); std::cout << RESET;
	try {
		Form	formino("formino", 42, 42);

		std::cout << CYAN << formino <<  RESET << std::endl;
		std::cout << GREEN; burro.signForm(formino); std::cout << RESET;
		std::cout << std::endl;

		std::cout << CYAN << formino << RESET << std::endl;
		std::cout << RED; burro.signForm(formino); std::cout << RESET;

		std::cout << BOLDBLUE; testName("Grade too low"); std::cout << RESET;
		Form	formone("formone", 1, 1);
		std::cout << CYAN << formone << RESET << std::endl;
		std::cout << RED; burro.signForm(formone); std::cout << RESET;
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
