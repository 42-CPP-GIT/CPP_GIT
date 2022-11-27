/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:53:40 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 13:05:29 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	;
}

Intern::~Intern( void )
{
	;
}

Intern::Intern ( const Intern& copy )
{
	*this = copy;
}

Intern& Intern::operator = ( const Intern& i )
{
	if (this != &i)
	{
		;
	}
	return (*this);
}

int		Intern::error( std::string name ) const
{
	std::cout << name << " is not avilable " << std::endl;
	return (-1);
}

Form*	Intern::makeForm( const std::string formType, const std::string target )
{
	std::string str;
	std::string find_str;
	int			i;
	Form		*ret;

	str = "[robotomy request]0[presidential pardon]1[shrubbery creation]2";
	find_str = "[" + formType + "]";
	if (formType.find('[',0) != std::string::npos || formType.find(']',0) != std::string::npos || str.find(formType, 0) == std::string::npos)
		throw Intern::error(formType);
	i = str.find(find_str, 0);
	if (i != -1)
		i = str[find_str.length()] - '0';
	switch (i)
	{
		case 0 :
			ret = new RobotomyRequestForm(target);
			return (static_cast<Form *> (ret));
		case 1 :
			ret = new PresidentialPardonForm(target);
			return (static_cast<Form *> (ret));
		case 2 :
			ret = new ShrubberyCreationForm(target);
			return (static_cast<Form *> (ret));
	}
	return (NULL);
}
