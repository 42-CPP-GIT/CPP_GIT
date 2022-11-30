/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:51:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 20:40:37 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	this->target_ = "default";
	this->setName("Presidential_Pardon_Form");
	this->setSignGrade(PRESIDENTIALPARDONFORM_SIGN_GRADE);
	this->setExecuteGrade(PRESIDENTIALPARDONFORM_EXECUTE_GRADE);
}

PresidentialPardonForm::PresidentialPardonForm(std::string& target) : target_(target)
{
	this->setName("Presidential_Pardon_Form");
	this->setSignGrade(PRESIDENTIALPARDONFORM_SIGN_GRADE);
	this->setExecuteGrade(PRESIDENTIALPARDONFORM_EXECUTE_GRADE);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox.\n";
}