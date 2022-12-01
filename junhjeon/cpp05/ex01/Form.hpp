/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:52:32 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 14:41:42 by junhjeon         ###   ########.fr       */
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
		Form( std::string name, const int signG, const int requireG );
		~Form();
		Form( const Form &copy);
		std::string	getName( void ) const;
		bool		getSign( void ) const;
		int			getSignGrade( void ) const;
		int			getRequireGrade( void ) const;
		void		setSign( bool b);
		class GradeTooLowException : public std::exception{
			public:
				const char * what() const throw();
		};
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		int			beSigned(const Bureaucrat &b );
};

std::ostream&	operator<<(std::ostream &os, const Form& f);
#endif
