/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 17:52:15 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;
class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	Form *_form[100];
	int _size;
public:
	class GradeTooHighException: public std::exception
	{
	public:
		const char * what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char * what() const throw();
	};
	class FormsAreFullException: public std::exception
	{
	public:
		const char * what() const throw();	
	};
	class InvalidIndexForm: public std::exception
	{
	public:
		const char * what() const throw();
	};
	class MyException
	{
	private:
		Form &_form;
		Bureaucrat &_bureaucrat;
	public:
		MyException(Form &Form, Bureaucrat &bureaucrat);
		~MyException();
		void printException();
	};
	Bureaucrat(/* args */);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &Bureaucrat);
	~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat &source);

	bool isTooHigh(int grade);
	bool isTooLow(int grade);
	int isInvalidGrade(int grade);
	
	void increment(void);
	void decrement(void);

	void signForm(Form &form);
	void signForm(int idx);

	bool isExistInDB(Form &form);

	const std::string& getName(void) const;
	const int& getGrade(void) const;
	Form& getFormByIndex(int idx);
	void setGrade(const int grade);
	int setForm(Form &form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif