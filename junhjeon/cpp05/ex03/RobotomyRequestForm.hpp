/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:19:23 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:23:27 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	private :
		RobotomyRequestForm& operator = ( const RobotomyRequestForm &s );

	public :
		RobotomyRequestForm(const std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &copy );
		virtual void	execute( Bureaucrat const & executor ) const;
		void	randomR( void ) const;
		class lowExecuteGrade : public std::exception{
			public:
				const char * what() const throw();
						};
};
