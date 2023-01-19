/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:08:46 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 14:02:30 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

static void	testShrubbery(const bool mute) {
	if (!mute)
		return ;
	/* Shrubbery */
	{
		sectionTitle("Shrubbery creation : no sign, no exec", BOLDBLUE);
		Bureaucrat	bu("Bu", 149);
		ShrubberyCreationForm form("Sh");
		testForm(bu, form);
		std::cout << std::endl;
	}

	{
		sectionTitle("Shrubbery creation : yes sign, no exec", BOLDCYAN);
		Bureaucrat	bu("Bu", 141);
		ShrubberyCreationForm form("Sh");
		testForm(bu, form);
		std::cout << std::endl;
	}

	{
		sectionTitle("Shrubbery creation : yes sign, yes exec", BOLDYELLOW);
		Bureaucrat	bu("Bu", 135);
		ShrubberyCreationForm form("Sh");
		testForm(bu, form);
		std::cout << std::endl;
	}
}

static void	testRobotomy(const bool mute) {
	if (!mute)
		return ;
	/* Robotomy */
	{
		sectionTitle("Robotomy request : no sign, no exec", BOLDBLUE);
		Bureaucrat	bu("Bu", 100);
		RobotomyRequestForm form("Ro");
		testForm(bu, form);
	}

	{
		sectionTitle("Robotomy request : yes sign, no exec", BOLDCYAN);
		Bureaucrat	bu("Bu", 65);
		RobotomyRequestForm form("Ro");
		testForm(bu, form);
	}

	{
		sectionTitle("Robotomy request : yes sign, ? exec", BOLDMAGENTA);
		Bureaucrat	bu("Bu", 30);
		RobotomyRequestForm form("Ro");
		testForm(bu, form);
	}
}

static void	testPresident(const bool mute) {
	if (!mute)
		return ;
	/* President */
	{
		sectionTitle("Presidential pardon : no sign, no exec", BOLDBLUE);
		Bureaucrat	bu("Bu", 30);
		PresidentialPardonForm form("Pr");
		testForm(bu, form);
	}

	{
		sectionTitle("Presidential pardon : no sign, yes exec", BOLDCYAN);
		Bureaucrat	bu("Bu", 17);
		PresidentialPardonForm form("Pr");
		testForm(bu, form);
	}

	{
		sectionTitle("Presidential pardon : no sign, yes exec", BOLDGREEN);
		Bureaucrat	bu("Bu", 3);
		PresidentialPardonForm form("Pr");
		testForm(bu, form);
	}
}


int	main() {
	// Bureaucrat	bu0("burretto", 0);	// catch 하지 못한 throw
	Bureaucrat	bu42("Bu42", 42);
	std::cout << CYAN << bu42 << RESET << std::endl;

	try {
		// Bureaucrat	burretto("Burretto", 151);		// 1st catch에서 잡힘
		// std::cout << CYAN << burretto << RESET << std::endl;

		testShrubbery(1);
		testRobotomy(0);
		testPresident(0);

	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
