/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:20:30 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:36:37 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

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
		class	AlreadySignedException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		Form();
		Form(std::string name, bool sign, int signGrade, int executeGrade);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		void			beSigned(Bureaucrat &br);
		void			setIsSigned(bool otherSign);
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		virtual ~Form();
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
