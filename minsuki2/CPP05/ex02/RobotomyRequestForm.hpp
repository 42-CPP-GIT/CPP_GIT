/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:47:19 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/11 18:41:03 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# define MSG_ROBOTOMYREQUESTFORM			"[RobotomyRequestForm] "
# define MSG_D_CONSTRUCT					"Default Constructor"
# define MSG_C_CONSTRUCT					"Copy Constructor"
# define MSG_C_A_OPERATE					"Copy assignment operator"
# define MSG_DESTRCUT						"Destructor"

# include <iostream>
# include <cstdlib>
# include "Bureaucrat.hpp"

enum e_grade { SIGN = 72, EXEC = 45 };

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm(void);
		void	excute(const Bureaucrat& excutor);
};

#endif
