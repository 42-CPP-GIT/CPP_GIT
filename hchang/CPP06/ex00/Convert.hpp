/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:31:53 by hchang            #+#    #+#             */
/*   Updated: 2022/11/30 18:03:00 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>

class Convert
{
	private:
		std::string	_data;
		char		_c;
		int			_i;
		float		_f;
		double		_d;

	public:
		class	NotPrintableException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		class	NotValidException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		Convert(char *input);
		Convert(const Convert& obj);
		Convert& operator=(const Convert& obj);
		~Convert();
		void print() const;
		void isValidInput(char *input);
};

#endif
