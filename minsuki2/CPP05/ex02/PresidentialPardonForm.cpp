/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:22:54 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/11 18:41:42 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) {
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

void	PresidentialPardonForm::excute(const Bureaucrat& excutor) const {
{
	// checkExec(excutor); ??
	std::cout << this->getName() << MSG_EXEC << std::endl;
}
