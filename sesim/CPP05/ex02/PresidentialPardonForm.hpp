/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:31:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 11:19:53 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		class NotSignedException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		virtual void	execute(Bureaucrat const& executor) const;
		~PresidentialPardonForm();
};

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm rr);
