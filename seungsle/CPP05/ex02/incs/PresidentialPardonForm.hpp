/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:50:11 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 01:00:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"
class Bureaucrat;
class PresidentialPardonForm: public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm(/* args */);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& source);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm &source);

	const std::string& getTarget(void) const;

	virtual void execute(Bureaucrat const & executor) const;
};


#endif