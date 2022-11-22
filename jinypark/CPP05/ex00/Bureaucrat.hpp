/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:18:55 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/22 15:19:07 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat
{
private:
	const	std::string name_;
	int		grade_;
public:
	Bureaucrat(void);
	Bureaucrat(int grade);
	~Bureaucrat();
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		increment(int grade);
	void		decrement(int grade);
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

