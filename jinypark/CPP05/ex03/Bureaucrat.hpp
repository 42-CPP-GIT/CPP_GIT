/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:18:55 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 11:48:11 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat
{
private:
	const	std::string name_;
	int		grade_;
public:
	Bureaucrat(void);
	Bureaucrat(int grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat	&operator=(const Bureaucrat &obj);
	~Bureaucrat();
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		increment(int grade);
	void		decrement(int grade);
	void		signForm(AForm* form);
	void		executeForm(AForm* form) const;
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

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);

#endif