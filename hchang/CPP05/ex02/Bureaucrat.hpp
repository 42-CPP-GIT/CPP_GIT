/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:31:32 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:25:34 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

# define RESET "\033[0m"
# define IT "\e[0;3m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLE "\e[0;34m"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		class	GradeTooHighException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				const char * what() const throw();
		};

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();
		std::string			getName(void) const;
		int					getGrade(void) const;
		void				upGrade();
		void				downGrade();
		void				signForm(Form &form);
		void				executeForm(Form const & form);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif
