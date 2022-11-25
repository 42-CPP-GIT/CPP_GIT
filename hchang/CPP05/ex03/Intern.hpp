/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:07 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 16:03:10 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Form.hpp"

class Intern
{
	public:
		class	InvalidFormNameException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern();
		Form*	(Intern::*f[3])(std::string);
		Form	*makeForm(std::string formName, std::string formTarget);
		Form	*makeShrubberyCreationForm(std::string formTarget);
		Form	*makeRobotomyRequestForm(std::string formTarget);
		Form	*makePresidentialPardonForm(std::string formTarget);
};

#endif
