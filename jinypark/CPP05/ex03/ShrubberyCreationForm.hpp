
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:48:21 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 22:14:23 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

# include <fstream>
# include "Form.hpp"

# define SHRUBBERY_SIGN_GRADE 145
# define SHRUBBERY_EXECUTE_GRADE 137

class ShrubberyCreationForm : public Form
{
private:
	std::string target_;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string& target);
	ShrubberyCreationForm(const std::string name, const int signedGrade, const int executeGrade);
	~ShrubberyCreationForm();
	void	execute(Bureaucrat const & executor) const;
};

#endif