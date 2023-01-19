/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 19:24:31 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP
# define MSG_COVERSION					"[Conversion] "
# define MSG_DEFAULT_CONSTRUCT			"Default Constructor"
# define MSG_COPY_CONSTRUCT				"Copy Constructor"
# define MSG_COPY_ASSIGN_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT					"Destructor"

# include <iostream>
# include "color.h"

class Conversion {
	public:
		Conversion(void);
		Conversion(const std::string& name);
		Conversion(std::string name, int grade);
		Conversion(const Conversion& obj);
		Conversion&	operator=(const Conversion& obj);
		~Conversion(void);
		const std::string&	getName(void) const;
		const int&			getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
	private:
		const std::string		name_;
		int						grade_;
		void		checkException(void) const;

};

std::ostream& operator<<(std::ostream& out, const Conversion& obj);

#endif

