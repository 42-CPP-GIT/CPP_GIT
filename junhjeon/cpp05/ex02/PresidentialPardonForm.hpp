/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:19:23 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:22:45 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private :
		PresidentialPardonForm& operator = ( const PresidentialPardonForm &s );

	public :
		PresidentialPardonForm(const std::string name);
		~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &copy );
		void	virtual execute( Bureaucrat const & executor ) const;
		class lowExecuteGrade : public std::exception{
			public:
				const char * what() const throw();
						};
};

#endif
