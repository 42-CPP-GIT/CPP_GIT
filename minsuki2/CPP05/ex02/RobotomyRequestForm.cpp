/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:22:26 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/11 18:40:00 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) {
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

void	RobotomyRequestForm::excute(const Bureaucrat& excutor) {
	std::srand(time(NULL));

	if (std::rand() % 2) {
		// Success
	}
	else {
		// Failed
	}
}
