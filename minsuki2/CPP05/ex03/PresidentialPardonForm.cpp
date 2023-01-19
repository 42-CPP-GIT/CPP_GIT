/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:22:54 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 12:31:14 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
//

PresidentialPardonForm::PresidentialPardonForm(const std::string& name)
	: AForm(name, PR_SIGN, PR_EXEC) {
	std::cout << MSG_PRESIDENTIALPARDONFORM << MSG_D_CONSTRUCT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExcute()) {
	std::cout << MSG_PRESIDENTIALPARDONFORM << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	std::cout << MSG_PRESIDENTIALPARDONFORM << MSG_C_A_OPERATE << std::endl;
	this->setSigned(obj.getSignedIndicator());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << MSG_PRESIDENTIALPARDONFORM << MSG_DESTRCUT << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& excutor) const {
	this->checkExec(excutor);
	std::cout << GREEN << this->getName()
			  << " was pardoned by President Zaphod Beeblebrox.."
			  << RESET << std::endl;
}
