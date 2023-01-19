/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:08:46 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 12:42:14 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

static void	sectionTitle(const std::string& title, const std::string& COLOR) {
	std::cout << std::endl << std::endl
			  << COLOR << "--- " << title << " ---" << RESET
			  << std::endl << std::endl;
}

static void	testForm(const Bureaucrat& bureaucrat, AForm& form) {
	std::cout << CYAN << form << RESET << std::endl;
	bureaucrat.executeForm(form);
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

void	testMake(const std::string& formName, const std::string& target, const std::string& COLOR) {

	sectionTitle(formName, COLOR);
	Bureaucrat	burro("burro", 42);
	Intern		interno;
	AForm* form = interno.makeForm(formName, target);
	testForm(burro, *form);
	delete form; form = NULL;
}

int	main() {
	try {
		testMake("shrubbery creation", "home", BOLDYELLOW);
		testMake("robotomy request", "Bender", BOLDBLUE);
		testMake("presidential pardon", "lrocca", BOLDCYAN);
		testMake("not a form", "you", BOLDRED);
		testMake("presidential pardon", "is it Working?", BOLDCYAN);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	system("leaks -q bureaucrat");
}
