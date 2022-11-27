/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 12:52:26 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Form;
class Bureaucrat
{
	private :
		const	std::string _name;
		int					_grade;
	public :
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat( const Bureaucrat &copy);
		Bureaucrat& operator = ( const Bureaucrat &b );
		std::string getName ( void ) const;
		int				  getGrade ( void ) const;
		class GradeTooLowException : public std::exception{
			public:
				const char * what() const throw();
					};
		class GradeTooHighException : public std::exception{
			public :
				const char* what() const throw();
						};
		class Nosign : public std::exception{
			public :
				const char* what() const throw();
		};
		void	signForm(Form &f) const;
		void	executeForm(Form const & form) const;
		void	incre( void );
		void	decre( void );
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& b);

#endif
