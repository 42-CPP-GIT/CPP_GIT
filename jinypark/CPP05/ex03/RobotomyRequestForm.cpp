/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:51:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/02 21:03:02 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	this->target_ = "default";
	this->setName("Robotomy_Request_Form");
	this->setSignGrade(ROBOTOMY_SIGN_GRADE);
	this->setExecuteGrade(ROBOTOMY_EXECUTE_GRADE);
}

RobotomyRequestForm::RobotomyRequestForm(std::string& target) : target_(target)
{
	this->setName("Robotomy_Request_Form");
	this->setSignGrade(ROBOTOMY_SIGN_GRADE);
	this->setExecuteGrade(ROBOTOMY_EXECUTE_GRADE);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade())
{
	*this = obj;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	this->setSigned(obj.getSigned());
	this->target_ = obj.target_;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << "eeeeeeeeeeeeeeeeeeeeeeng....!\n";

	int	i(std::rand());

	if (i % 2 == 0)
		std::cout << this->target_ << " has been robotomized successfully.\n";
	else
		std::cout << "Robotomy failed...\n";
}