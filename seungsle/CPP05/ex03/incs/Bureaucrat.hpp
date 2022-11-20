/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 00:03:11 by seungsle         ###   ########.fr       */
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
	Bureaucrat(/* args */);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &Bureaucrat);
	~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat &source);

	void executeForm(Form const & form);

	bool isTooHigh(int grade);
	bool isTooLow(int grade);
	int isInvalidGrade(int grade);
	
	void increment(void);
	void decrement(void);

	const std::string& getName(void) const;
	const int& getGrade(void) const;
	void setGrade(const int grade);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif