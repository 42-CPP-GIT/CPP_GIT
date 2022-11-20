/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:50:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 01:02:11 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonFormNoTarget", 25, 5), _target("NoTarget")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm" + target, 25, 5), _target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source): Form("PresidentialPardonFormNoTarget", 25, 5)
{
	*this = source;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source)
{
	if (this == &source)
		return (*this);
	this->_target = source.getTarget();
	return (*this);
}

const std::string& PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToSign() && \
		executor.getGrade() <= this->getGradeToExecute())
	{
		if (this->getIsSigned())
			std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
		{
			std::cout << "execute failed(PresidentialPardonForm) : ";
			throw(Form::NotExecutableException());
		}
	}
	else
	{
		std::cout << "execute failed(PresidentialPardonForm) : ";
		throw(Form::GradeTooLowException());
	}
}