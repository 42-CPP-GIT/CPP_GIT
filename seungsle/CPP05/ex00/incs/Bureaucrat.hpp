/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/19 21:49:56 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	// Exception *_exception;
public:
	// class MyException: public std::exception
	// {
	// private:
	// 	std::string _errorMessage;
	// public:
	// 	MyException();
	// 	MyException(std::string errorMessage);
	// 	const char * what() const throw();
	// 	// ~MyException();

	// 	const std::string& getErrorMessage(void) const;
	// 	void setErrorMessage(std::string errorMessage);

	// 	std::string printException(void) const;
	// };
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
	class GradeOutOfRange: public std::exception
	{
	public:
		const char * what() const throw();
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

	// MyException *GradeTooHighException(void);
	// MyException *GradeTooLowException(void);
	// MyException *GradeOutOfRange(void);

	const std::string& getName(void) const;
	const int& getGrade(void) const;
	void setName(const std::string name);
	void setGrade(const int grade);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif