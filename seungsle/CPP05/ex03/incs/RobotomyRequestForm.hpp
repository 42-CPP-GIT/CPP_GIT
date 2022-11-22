/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:50:13 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 00:53:51 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <random>
#include "Form.hpp"
class Bureaucrat;
class RobotomyRequestForm: public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm(/* args */);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& source);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm &source);

	const std::string& getTarget(void) const;

	virtual void execute(Bureaucrat const & executor) const;
};


#endif