/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:50:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 00:18:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestFormNoTarget", 72, 45), _target("NoTarget")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm" + target, 72, 45), _target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source): Form("RobotomyRequestFormNoTarget", 72, 45)
{
	*this = source;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source)
{
	if (this == &source)
		return (*this);
	this->_target = source.getTarget();
	return (*this);
}

const std::string& RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToSign() && \
		executor.getGrade() <= this->getGradeToExecute())
	{
		if (this->getIsSigned())
		{
			std::srand(time(NULL));
			if (std::rand() % 2)
				std::cout << this->getTarget() << " has been robotomized BRRRRRRRRRRRR" << std::endl;
			else
				std::cout << this->getTarget() << " robotomy failed." << std::endl;
		}
		else
		{
			std::cout << "execute failed(RobotomyRequestForm) : ";
			throw(Form::NotExecutableException());
		}
	}
	else
	{
		std::cout << "execute failed(RobotomyRequestForm) : ";
		throw(Form::GradeTooLowException());
	}
}