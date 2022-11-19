/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/19 18:37:02 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Exception.hpp"

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	// Exception *_exception;
public:
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

	Exception *GradeTooHighException(void);
	Exception *GradeTooLowException(void);
	Exception *GradeOutOfRange(void);

	const std::string& getName(void) const;
	const int& getGrade(void) const;
	void setName(const std::string name);
	void setGrade(const int grade);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif