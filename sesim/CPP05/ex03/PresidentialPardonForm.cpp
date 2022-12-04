/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:31:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:38:25 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const char*	PresidentialPardonForm::NotSignedException::what() const throw()
{
	return ("err : Form Not Signed");
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Default", 25, 5)
{
	std::cout << "Default Presidential Pardon Form Created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
	std::cout << name << " : Presidential Pardon Form Created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
	std::cout << obj.getName() << " : Presidential Pardon Form Copied" << std::endl;
	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return (*this);
	this->setIsSigned(obj.getIsSigned());
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
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
	std::cout << this->getName() << " : has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName() << " : Form shredded" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm rr)
{
	out << rr.getName() << " Form\n  Sign Grade : " << rr.getSignGrade() \
	<< "\n  Execute Grade : " << rr.getExecuteGrade() \
	<< "\n  Form Sign Status : " << (rr.getIsSigned() ? "Yes" : "No");
	return out;
}