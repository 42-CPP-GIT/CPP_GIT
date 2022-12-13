/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:31:57 by sesim             #+#    #+#             */
/*   Updated: 2022/12/13 13:01:49 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	vec_;
		unsigned int		max_;
	public:
		class OutOfBoundsException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class DuplicateException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class EmptyNumberException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		Span(unsigned int n);
		Span(const Span& obj);
		Span&	operator=(const Span& obj);
		void	addNumber(int n);
		void	addNumber(int *n, unsigned int size);
		int		shortestSpan(void);
		int		longestSpan(void);
		~Span();
};