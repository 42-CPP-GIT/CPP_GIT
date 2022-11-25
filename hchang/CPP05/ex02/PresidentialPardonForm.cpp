/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:40:41 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:40:15 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

const char*	PresidentialPardonForm::NotSignedException::what() const throw()
{
	return ("ERROR : Form Not Signed");
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : Form(name, false, 25, 5)
{
	std::cout << "[PresidentialPardonForm Constructor Called]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
	std::cout << "[PresidentialPardonForm Copy Constructor Called]" << std::endl;
	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return (*this);
	this->setIsSigned(obj.getIsSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm Destructor Called]" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
	std::cout << IT << "Informs that " << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n" << RESET;
}


std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& ps)
{
	out << GRN << ps.getName() << ", PresidentialPardonForm Sign Grade " << ps.getSignGrade() << ", PresidentialPardonForm Execute Grade " << ps.getExecuteGrade() << "\n▶︎ Signed Check : " << ps.getIsSigned() << RESET;
	return out;
}
