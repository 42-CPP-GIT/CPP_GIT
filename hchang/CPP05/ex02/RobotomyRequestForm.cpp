/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:40:53 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:39:59 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <time.h>

const char*	RobotomyRequestForm::NotSignedException::what() const throw()
{
	return ("ERROR : Form Not Signed");
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : Form(name, false, 72, 45)
{
	std::cout << "[RobotomyRequestForm Constructor Called]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
	std::cout << "[RobotomyRequestForm Copy Constructor Called]" << std::endl;
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return (*this);
	this->setIsSigned(obj.getIsSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm Destructor Called]" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because this Form is already signed.\n";
		throw NotSignedException();
	}
	else if (executor.getGrade() > this->getExecuteGrade())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because " << executor.getName() << "'s grade is too low.\n";
		throw Form::GradeTooLowException();
	}
	srand(time(NULL));
	int random_var = rand();
	std::cout << this->getName() << " : DRRRRRRIIIIIILLLLLLLLLLLL NOOOOOOIIISESSSSSSS\n";
	if (random_var % 2 == 1)
		std::cout << IT << executor.getName() <<" noticed that " <<  this->getName() <<" GOT ROBOTOMIZED. \n" << RESET;
	else
		std::cout << IT << executor.getName() <<" noticed that " <<  this->getName() <<" GOT ROBOTOMIZED FAILED. \n" << RESET;
}


std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& rb)
{
	out << GRN << rb.getName() << ", RobotomyRequestForm Sign Grade " << rb.getSignGrade() << ", RobotomyRequestForm Execute Grade " << rb.getExecuteGrade() << "\n▶︎ Signed Check : " << rb.getIsSigned() << RESET;
	return out;
}
