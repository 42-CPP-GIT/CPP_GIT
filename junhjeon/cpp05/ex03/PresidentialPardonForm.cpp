/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:28:03 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:27:09 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : Form(name, 25, 7)
{
	std::cout << "scform constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "scform destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : Form(copy.getName(), 
		25, 7)
{
	this->setSign(copy.getSign());
	std::cout << "scform copy" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = ( const PresidentialPardonForm &s )
{
	(void) s;
	return (*this);
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSign() == false)
		throw PresidentialPardonForm::SignError();
	if ( this->getRequireGrade() >= executor.getGrade())
	{
		std::cout << executor.getName() << " execute " << this->getName() << std::endl;
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw PresidentialPardonForm::lowExecuteGrade();
}

const char * PresidentialPardonForm::lowExecuteGrade::what() const throw()
{
	return "too low execute Grade !";
}
