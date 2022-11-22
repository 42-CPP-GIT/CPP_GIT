/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:20:30 by hchang            #+#    #+#             */
/*   Updated: 2022/11/22 16:49:33 by hchang           ###   ########.fr       */
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
		bool			beSigned(Bureaucrat bureaucrat);
		std::string		getName() const;
		void			setIsSigned(bool otherSign);
		bool			getIsSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		virtual bool	execute(Bureaucrat const & executor) const = 0;
		virtual ~Form();
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
