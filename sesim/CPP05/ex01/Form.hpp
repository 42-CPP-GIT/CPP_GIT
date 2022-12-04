/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:28:11 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 00:04:49 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name_;
		bool				isSigned_;
		const int			signGrade_;
		const int			executeGrade_;

	public:
		class GradeTooHighException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		class AlreadySignedException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;
		void				beSigned(Bureaucrat &br);
		void				setIsSigned(bool approve);
		~Form();
};

std::ostream&	operator<<(std::ostream& out, const Form& form);