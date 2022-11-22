/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:47 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 20:19:23 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;
class Form
{
private:
	const std::string _name;
	bool _isSigned;
	bool _isExecuted;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	class GradeTooHighException: public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char* what() const throw();
	};
	class NotExecutableException: public std::exception
	{
	public:
		const char* what() const throw();
	};
	Form(/* args */);
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &source);
	virtual ~Form();
	Form& operator=(const Form &source);

	virtual void execute(Bureaucrat const & executor) const = 0;

	bool beSigned(void);
	void signForm(Bureaucrat &bureaucrat);

	bool isTooHigh(int grade);
	bool isTooLow(int grade);
	int isInvalidGrade(int grade);

	const std::string& getName(void) const;
	const bool& getIsSigned(void) const;
	const int& getGradeToSign(void) const;
	const int& getGradeToExecute(void) const;

	void setIsSigned(bool isSigned);
	void setIsExecuted(bool isExecuted);
};
std::ostream& operator<<(std::ostream& out, const Form& Form);


#endif