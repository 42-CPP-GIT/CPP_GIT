/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:53:08 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 15:43:42 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Convert
{
	private:
		std::string	data_;
		double		d_;
		float		f_;
		int			i_;
		char		c_;

	public:
		class	NonDisplayableException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class	NotValidException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		Convert(char* input);
		Convert(const Convert& obj);
		Convert& operator=(const Convert& obj);
		bool	isRightForm(char* end) const;
		void	print() const;
		void	isValidInput(char* input);
		bool	isNan(double val) const;
		bool	isInf(double val) const;
		~Convert();
};
