/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:33:28 by hchang            #+#    #+#             */
/*   Updated: 2022/12/01 17:07:39 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	_vec;
		unsigned int		_max;
	public:
		class	OutofBoundException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		class	DuplicateException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		class	EmptyNumberException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		void	addNumber(int num);
		void	addNumbers(int *num, unsigned int num_size);
		int		shortestSpan(void);
		int		longestSpan(void);
		Span(unsigned int N);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();
		void print_vec();

};

#endif