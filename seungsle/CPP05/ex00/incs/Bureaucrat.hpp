/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/20 16:23:55 by seungsle         ###   ########.fr       */
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

	const std::string& getName(void) const;
	const int& getGrade(void) const;
	void setGrade(const int grade);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif