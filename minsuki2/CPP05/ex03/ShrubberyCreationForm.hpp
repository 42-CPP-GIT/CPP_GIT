/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:47:19 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/18 20:29:48 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# define MSG_SHRUBBERYCREATIONFORM		"[Shrubberycreationform] "
# define MSG_D_CONSTRUCT				"Default Constructor"
# define MSG_C_CONSTRUCT				"Copy Constructor"
# define MSG_C_A_OPERATE				"Copy assignment operator"
# define MSG_DESTRCUT					"Destructor"
# define MSG_NO_SPACE					"Not enough space of disk (ShrubberyCreationForm)"

# include "AForm.hpp"

enum e_grade_ShrubberyCreationForm { SH_SIGN = 145, SH_EXEC = 137 };

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm(void);
		void		execute(Bureaucrat const& executor) const;
		class NoSpaceException : public std::exception {
			public:
				const char* what(void) const throw();
		};
	private:
		ShrubberyCreationForm(void);
		static const std::string	shrubbery;
};

#endif
