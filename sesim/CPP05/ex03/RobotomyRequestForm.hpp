/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:31:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 10:44:46 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		class NotSignedException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		virtual void	execute(Bureaucrat const& executor) const;
		~RobotomyRequestForm();
};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm sh);
