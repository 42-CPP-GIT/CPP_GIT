/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:49:14 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/11 19:21:31 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private :
		;

	public :
		Intern();
		~Intern();
		Intern( const Intern& copy );
		Intern& operator = ( const Intern& i );
		Form* makeForm( const std::string formType, const std::string target );
		int		error( std::string name ) const;
};
