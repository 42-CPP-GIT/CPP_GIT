/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:52:32 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:53:17 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form
{
	private :
		const	std::string _name;
		bool	_sign;
		const	int	_signGrade;
		const	int	_requireGrade;
		Form& operator = ( const Form &f );
	public :
		Form( std::string name, const int signg, const int requireg );
		virtual ~Form();
		Form( const Form &copy);
		std::string	getName( void ) const;
		void		setSign( bool b );
		bool		getSign( void ) const;
		int			getSignGrade( void ) const;
		int			getRequireGrade( void ) const;
		virtual void execute(const Bureaucrat& b) const = 0;
		class GradeTooLowException : public std::exception{
			public:
				const char * what() const throw();
		};
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		class SignError : public std::exception{
			public:
				const char* what() const throw();
		};
		int			beSigned(const Bureaucrat &b );
};

std::ostream&	operator<<(std::ostream &os, const Form& f);
#endif
