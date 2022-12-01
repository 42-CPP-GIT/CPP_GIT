/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:19:23 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:24:09 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	private :
		ShrubberyCreationForm& operator = ( const ShrubberyCreationForm &s );

	public :
		ShrubberyCreationForm(const std::string name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm &copy );
		void	virtual execute( Bureaucrat const & executor ) const;
		void	creatTree( void ) const;
		class lowExecuteGrade : public std::exception{
			public:
				const char * what() const throw();
						};
};
