/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:34:58 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 00:04:09 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string	name_;
		int					grade_;

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
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				promotion(void);
		void				demotion(void);
		void				signForm(Form& form);
		~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);