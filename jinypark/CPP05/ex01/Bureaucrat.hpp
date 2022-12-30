/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:18:55 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/02 15:36:18 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
private:
	const	std::string name_;
	int		grade_;
public:
	Bureaucrat(void);
	Bureaucrat(int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat	&operator=(const Bureaucrat &obj);
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		increment(int grade);
	void		decrement(int grade);
	void		signForm(Form* form);
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