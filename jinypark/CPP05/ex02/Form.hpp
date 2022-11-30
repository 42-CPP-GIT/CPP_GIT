/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:48:21 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 17:03:18 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name_;
	bool				isSigned_;
	const int			signGrade_;
	const int			executeGrade_;
public:
	Form();
	Form(const std::string name, const int signedGrade, const int executeGrade);
	virtual ~Form();
	void	beSigned(const Bureaucrat& applicant);
	bool	getSigned() const;
	int		getSignGrade() const;
	int		getExecuteGrade() const;
	const std::string&	getName() const;
	void	setSigned(bool i);
	void	setSignGrade(int grade);
	void	setExecuteGrade(int grade);
	void	setName(const std::string& name);
	virtual void		execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form& obj);


#endif