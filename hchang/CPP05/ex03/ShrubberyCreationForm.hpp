/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:40:46 by hchang            #+#    #+#             */
/*   Updated: 2022/11/23 15:41:50 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		class	FileNotOpenException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		class	NotSignedException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		virtual bool		execute(Bureaucrat const & executor) const;

};

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& sh);

#endif
