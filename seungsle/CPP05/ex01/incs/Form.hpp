/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:43:47 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 20:14:39 by seungsle         ###   ########.fr       */
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
	class AlreadySigned: public std::exception
	{
	public:
		const char *what() const throw();
	};
	Form(/* args */);
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &source);
	~Form();
	Form& operator=(const Form &source);

	void beSigned(Bureaucrat &Bureaucrat);

	bool isTooHigh(int grade);
	bool isTooLow(int grade);
	int isInvalidGrade(int grade);

	const std::string& getName(void) const;
	bool& getIsSigned(void);
	const int& getGradeToSign(void) const;
	const int& getGradeToExecute(void) const;

	void setIsSigned(bool isSigned);
};
std::ostream& operator<<(std::ostream& out, const Form& Form);


#endif