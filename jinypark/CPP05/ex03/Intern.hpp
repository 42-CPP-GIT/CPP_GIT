/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:09:50 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/02 19:30:38 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
public:
	Intern(/* args */);
	~Intern();
	Intern(const Intern& obj);
	Intern	&operator=(const Intern& obj);
	Form*	makeForm(std::string formName, std::string target);
};


