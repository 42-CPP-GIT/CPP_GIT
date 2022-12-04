/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:31:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:38:33 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

const char*	RobotomyRequestForm::NotSignedException::what() const throw()
{
	return ("err : Form Not Signed");
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyDefault", 72, 45)
{
	std::cout << "Default Robotomy Request Form Created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
	std::cout << name << " : Robotomy Request Form Created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
	std::cout << obj.getName() << " : Robotomy Request Form Copied" << std::endl;
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return (*this);
	this->setIsSigned(obj.getIsSigned());
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because this Form is already signed" << std::endl;
		throw NotSignedException();
	}
	else if (executor.getGrade() > this->getExecuteGrade())
	{
		std::cerr << executor.getName() << " couldn't execute " << this->getName() << " because " << executor.getName() << "'s execution grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::srand(static_cast<unsigned int>(std::time(0)));
	int	random_val(rand());
	std::cout << this->getName() << " : DDRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	if (random_val % 2 == 1)
		std::cout << "   > " << this->getName() << " : robotomized Success!" << std::endl;
	else
		std::cout << "   > " << this->getName() << " : BEEP--- robotomized Failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName() << " : Form shredded" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm rr)
{
	out << rr.getName() << " Form\n  Sign Grade : " << rr.getSignGrade() \
	<< "\n  Execute Grade : " << rr.getExecuteGrade() \
	<< "\n  Form Sign Status : " << (rr.getIsSigned() ? "Yes" : "No");
	return out;
}