/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:09:50 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 11:49:49 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
	Intern(const Intern& obj);
	Intern	&operator=(const Intern& obj);
public:
	Intern();
	~Intern();
	AForm*	makeForm(std::string formName, std::string target);
};


