/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:28:11 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 10:33:01 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
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
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;
		void				beSigned(Bureaucrat &br);
		void				setIsSigned(bool approve);
		virtual void		execute(Bureaucrat const& executor) const = 0;
		virtual ~AForm();
};

std::ostream&	operator<<(std::ostream& out, const AForm& AForm);