/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 12:29:22 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# define MSG_AFORM				"[AForm] "
# define MSG_D_CONSTRUCT		"Default Constructor"
# define MSG_C_CONSTRUCT		"Copy Constructor"
# define MSG_C_A_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT			"Destructor"
# define MSG_GRADE_HIGH			"Grade too high (Aform)"
# define MSG_GRADE_LOW			"Grade too low (AForm)"
# define MSG_DOUBLE_SIGN		"Form cannot be signed twice! (Form)"
# define MSG_NO_SIGN			"of empty sign (AForm)"

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm {
	public:
		AForm(void);
		AForm(const std::string& name);
		AForm(std::string name, int grade_sign, int grade_excute);
		AForm(const AForm& obj);
		AForm&	operator=(const AForm& obj);
		virtual				~AForm(void);

		void				setSigned(const bool sign);
		void				checkSign(const Bureaucrat& obj_bure) const;
		void				checkExec(const Bureaucrat& obj_bure) const;
		const std::string&	getName(void) const;
		const bool&			getSignedIndicator(void) const;
		const int&			getGradeSign(void) const;
		const int&			getGradeExcute(void) const;
		void				beSigned(const Bureaucrat& obj);
		virtual void		execute(Bureaucrat const& executor) const = 0;
		// struct으로 사용하면 더 깔끔할 듯(과제 조건 어쩔 수 없음)
		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class ThisIsNotSignedException : public std::exception {
			public:
				const char* what(void) const throw();
		};

	private:
		const std::string		name_;
		bool					signed_indicator_;
		const int				grade_sign_;
		const int				grade_excute_;
		void					checkException(void) const;

};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
