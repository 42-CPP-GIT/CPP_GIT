/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:31:07 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 11:25:15 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# define MSG_INTERN					"[Intern] "
# define MSG_D_CONSTRUCT			"Default Constructor"
# define MSG_C_CONSTRUCT			"Copy Constructor"
# define MSG_C_A_OPERATE			"Copy assignment operator"
# define MSG_DESTRCUT				"Destructor"
# define MSG_CREATES				" creates "
# define MSG_NO_FORM				"This target doesn't include form name. (Intern)"

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);
		~Intern(void);
		class NoNameFormException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		AForm*	ShrubberyCreation(const std::string& target) const;
		AForm*	RobotomyRequest(const std::string& target) const;
		AForm*	PresidentialPardon(const std::string& target) const;
		AForm*	makeForm(const std::string& name, const std::string& target) const;

	private:
		static const std::string	target_set_[3];
		static AForm* (Intern::*form_func[3])(const std::string&) const;
};

#endif
