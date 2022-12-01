/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:28:03 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:23:25 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : Form(name, 72, 45)
{
	std::cout << "scform constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "scform destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : Form(copy.getName(), 72, 45)
{
	this->setSign(copy.getSign());
	std::cout << "scform copy" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator = ( const RobotomyRequestForm &s )
{
	(void) s;
	return (*this);
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSign() == false)
		throw RobotomyRequestForm::SignError();
	if (this->getRequireGrade() >= executor.getGrade())
	{
		std::cout << executor.getName() << " execute " << this->getName() << std::endl;
		RobotomyRequestForm::randomR();
	}
	else
		throw RobotomyRequestForm::lowExecuteGrade();
}

void	RobotomyRequestForm::randomR( void ) const
{
	srand((unsigned int)time(NULL));

	std::cout << "Make Some drilllllllllllllling noizzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
	int num = rand();
	if (num % 2 == 0)
		std::cout << this->getName() << " is Robotomized !!!!! " << std::endl;
	else
		std::cout << this->getName() << " isn't robotomized :( " << std::endl;
}

const char *RobotomyRequestForm::lowExecuteGrade::what() const throw()
{
	return "too low execute Grade !";
}
