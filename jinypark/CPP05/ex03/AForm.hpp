/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:48:21 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/12 13:48:26 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	name_;
	bool				isSigned_;
	const int			signGrade_;
	const int			executeGrade_;
public:
	AForm();
	AForm(const std::string name, const int signedGrade, const int executeGrade);
	virtual ~AForm();
	void	beSigned(const Bureaucrat& applicant);
	bool	getSigned() const;
	int		getSignGrade() const;
	int		getExecuteGrade() const;
	const	std::string&	getName() const;
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
	class FormNotSigned : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, AForm& obj);


#endif