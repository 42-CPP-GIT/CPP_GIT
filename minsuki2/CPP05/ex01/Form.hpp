/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/10 16:23:55 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# define MSG_BREAUCRAT			"[Form] "
# define MSG_D_CONSTRUCT		"Default Constructor"
# define MSG_C_CONSTRUCT		"Copy Constructor"
# define MSG_C_A_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT			"Destructor"
# define MSG_GRADE				", Form grade "

# include <iostream>
# include <exception>

class Form {
	public:
		Form(void);
		Form(const std::string& name);
		Form(std::string name, int grade);
		Form(const Form& obj);
		Form&	operator=(const Form& obj);
		~Form(void);
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
		std::string				name_;
		bool					sign_;
		const int				grade_;
		void		checkException(void) const;

};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif

/*
• A constant name.
• A boolean indicating whether it is signed (at construction, it’s not). • A constant grade required to sign it.
• And a constant grade required to execute it.
*/
