
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:48:21 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 22:14:23 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

# define ROBOTOMY_SIGN_GRADE 72
# define ROBOTOMY_EXECUTE_GRADE 45

class RobotomyRequestForm : public AForm
{
private:
	std::string target_;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);
	~RobotomyRequestForm();
	void	execute(Bureaucrat const & executor) const;
};

#endif