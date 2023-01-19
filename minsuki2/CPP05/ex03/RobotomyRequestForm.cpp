/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:22:26 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 12:31:22 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
	: AForm(name, RO_SIGN, RO_EXEC) {
	std::cout << MSG_ROBOTOMYREQUESTFORM << MSG_D_CONSTRUCT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExcute()) {
	std::cout << MSG_ROBOTOMYREQUESTFORM << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	std::cout << MSG_ROBOTOMYREQUESTFORM << MSG_C_A_OPERATE << std::endl;
	this->setSigned(obj.getSignedIndicator());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << MSG_ROBOTOMYREQUESTFORM << MSG_DESTRCUT << std::endl;
}

const char*		RobotomyRequestForm::HalfPercentFailedException::what() const throw() { return MSG_HALF_FAILED; }

void	RobotomyRequestForm::execute(const Bureaucrat& excutor) const {
	this->checkExec(excutor);
	std::srand(time(NULL));
	std::cout << CYAN << "Bzzzz or Zzzz... " << RESET << std::endl;
	if (std::rand() % 2) {
		throw HalfPercentFailedException();
	}
	std::cout << GREEN << this->getName()
			  << " has been robotomized successfully 50% of the time"
			  << RESET << std::endl;
}
