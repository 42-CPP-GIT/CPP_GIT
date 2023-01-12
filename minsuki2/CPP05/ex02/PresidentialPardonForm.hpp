/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:47:19 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/11 18:41:24 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# define MSG_PRESIDENTIALPARDONFORM			"[PresidentialPardonForm] "
# define MSG_D_CONSTRUCT					"Default Constructor"
# define MSG_C_CONSTRUCT					"Copy Constructor"
# define MSG_C_A_OPERATE					"Copy assignment operator"
# define MSG_DESTRCUT						"Destructor"
# define MSG_EXEC							" was pardoned by President Zaphod Beeblebrox.."

# include <iostream>
# include "Bureaucrat.hpp"

enum e_grade { SIGN = 25, EXEC = 5 };

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
		~PresidentialPardonForm(void);
		void	excute(const Bureaucrat& excutor) const;
};

#endif
