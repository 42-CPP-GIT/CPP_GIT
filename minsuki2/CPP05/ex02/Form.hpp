/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/11 18:18:23 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# define MSG_FORM				"[Form] "
# define MSG_D_CONSTRUCT		"Default Constructor"
# define MSG_C_CONSTRUCT		"Copy Constructor"
# define MSG_C_A_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT			"Destructor"
# define MSG_GRADE_HIGH			" Grade too high...(form)"
# define MSG_GRADE_LOW			" Grade too low...(Form)"
# define MSG_DOUBLE_SIGN		" cannot sign a form twice!(Form)"

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(const std::string& name);
		Form(std::string name, int grade_sign, int grade_excute);
		Form(const Form& obj);
		Form&	operator=(const Form& obj);
		virtual				~Form(void);

		void				setName(const std::string& name);
		void				setSigned(const bool sign);
		void				checkExec();
		const std::string&	getName(void) const;
		const bool&			getSignedIndicator(void) const;
		const int&			getGradeSign(void) const;
		const int&			getGradeExcute(void) const;
		void				beSigned(const Bureaucrat& obj);
		virtual void		execute(const Bureaucrat& obj_bure) const = 0;
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
		std::string				name_;
		bool					signed_indicator_;
		const int				grade_sign_;
		const int				grade_excute_;
		void					checkException(void) const;

};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif
class ThisIsNotSignedException : public std::exception
	{
		public:
		  const char * what(void) const throw();
	};
	virtual void execute(const Bureaucrat& b) const = 0;
	void setName(std::string name);
	void setSigned(bool b);
	void checkExec(const Bureaucrat& b) const;
