/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:47:19 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/11 18:53:46 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# define MSG_SHRUBBERYCREATIONFORM			"[Shrubberycreationform] "
# define MSG_D_CONSTRUCT					"Default Constructor"
# define MSG_C_CONSTRUCT					"Copy Constructor"
# define MSG_C_A_OPERATE					"Copy assignment operator"
# define MSG_DESTRCUT						"Destructor"

# include <iostream>
# include "Form.hpp"


enum e_grade1 { SIGN = 145, EXEC = 137 };

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm(void);
		void	excute(const Bureaucrat& excutor);
	private:
		static const std::string	shrubbery;

};

#endif
