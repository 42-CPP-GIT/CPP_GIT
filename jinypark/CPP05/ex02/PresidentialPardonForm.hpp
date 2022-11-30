
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:48:21 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 22:14:23 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

# include "Form.hpp"

# define PRESIDENTIALPARDONFORM_SIGN_GRADE 72
# define PRESIDENTIALPARDONFORM_EXECUTE_GRADE 45

class PresidentialPardonForm : public Form
{
private:
	std::string target_;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string& target);
	PresidentialPardonForm(const std::string name, const int signedGrade, const int executeGrade);
	~PresidentialPardonForm();
	void	execute(Bureaucrat const & executor) const;
};

#endif