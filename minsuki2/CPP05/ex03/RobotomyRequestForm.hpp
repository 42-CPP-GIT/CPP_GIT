/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:47:19 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/18 20:40:43 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# define MSG_ROBOTOMYREQUESTFORM			"[RobotomyRequestForm] "
# define MSG_D_CONSTRUCT					"Default Constructor"
# define MSG_C_CONSTRUCT					"Copy Constructor"
# define MSG_C_A_OPERATE					"Copy assignment operator"
# define MSG_DESTRCUT						"Destructor"
# define MSG_HALF_FAILED					"50% failed (RobotomyRequestForm)"

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

enum e_grade_RobotomyRequestForm { RO_SIGN = 72, RO_EXEC = 45 };

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm(void);
		void		execute(Bureaucrat const& executor) const;
		class HalfPercentFailedException : public std::exception {
			public:
				const char* what(void) const throw();
		};
	private:
		RobotomyRequestForm(void);
};

#endif
