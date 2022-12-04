/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:06:06 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 12:11:11 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		class NotExistFormNameException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		AForm*	genForm(std::string formName, std::string formTarget);
		AForm*	genShrubberyForm(std::string formTarget);
		AForm*	genRobotomyForm(std::string formTarget);
		AForm*	genPresidentialForm(std::string formTarget);
		~Intern();
};
