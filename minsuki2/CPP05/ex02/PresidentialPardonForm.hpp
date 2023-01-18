/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:47:19 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/18 21:08:44 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# define MSG_PRESIDENTIALPARDONFORM			"[PresidentialPardonForm] "
# define MSG_D_CONSTRUCT					"Default Constructor"
# define MSG_C_CONSTRUCT					"Copy Constructor"
# define MSG_C_A_OPERATE					"Copy assignment operator"
# define MSG_DESTRCUT						"Destructor"
# define MSG_EXEC

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

enum e_grade_PresidentialPardonForm { PR_SIGN = 25, PR_EXEC = 5 };

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
		~PresidentialPardonForm(void);
		void	execute(const Bureaucrat& excutor) const;
	private:
		PresidentialPardonForm(void);
};

#endif
