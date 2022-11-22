/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:48:21 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/22 17:35:19 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

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
	~Form();
	void	beSigned(const Bureaucrat& applicant);
	bool	getSigned(void);
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



