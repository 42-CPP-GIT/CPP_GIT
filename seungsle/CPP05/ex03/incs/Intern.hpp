/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:21:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 20:37:22 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
private:
	/* data */
public:
	class ICannotFindFormException: public std::exception
	{
	public:
		const char *what() const throw();
	};
	Intern(/* args */);
	Intern(const Intern &source);
	~Intern();
	Intern& operator=(const Intern &source);

	Form *makeForm(std::string name, std::string target);
};

#endif