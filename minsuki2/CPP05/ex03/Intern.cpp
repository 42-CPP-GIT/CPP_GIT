/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:31:06 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 12:18:46 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::target_set_[3] = {"shrubbery creation",
									"robotomy request",
									"presidential pardon"};

AForm* (Intern::*Intern::form_func[3])(const std::string&) const = \
												{&Intern::ShrubberyCreation,
												 &Intern::RobotomyRequest,
												 &Intern::PresidentialPardon};

Intern::Intern(void) {
	std::cout << MSG_INTERN << MSG_D_CONSTRUCT << std::endl;
}

Intern::Intern(const Intern& obj) {
	std::cout << MSG_INTERN << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
}

Intern&	Intern::operator=(const Intern& obj) {
	std::cout << MSG_INTERN << MSG_C_A_OPERATE << std::endl;
	(void)obj;
	return *this;
}

Intern::~Intern(void) {
	std::cout << MSG_INTERN << MSG_DESTRCUT << std::endl;
}

const char*		Intern::NoNameFormException::what() const throw() {
	return MSG_NO_FORM;
}

AForm*	Intern::ShrubberyCreation(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}
AForm*	Intern::RobotomyRequest(const std::string& target) const {
	return new RobotomyRequestForm(target);
}
AForm*	Intern::PresidentialPardon(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const {
	int i = 0;
	for (; i < 3 && Intern::target_set_[i] != name; ++i);
	i < 3 ? true : throw NoNameFormException();
	std::cout << "Intern" <<  MSG_CREATES << target << std::endl;
	return (this->*Intern::form_func[i])(target);
}

