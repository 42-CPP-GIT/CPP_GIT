/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 03:48:18 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/23 05:10:35 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
private:
	unsigned int _max;
	std::vector<int> _storage;
public:
	class AlreadyStoredElement: public std::exception
	{
	public:
		const char *what() const throw();
	};
	class StorageFull: public std::exception
	{
		const char *what() const throw();
	};
	class NotCompatiable: public std::exception
	{
		const char *what() const throw();
	};
	Span(/* args */);
	Span(unsigned int N);
	Span(const Span& source);
	~Span();
	Span& operator=(const Span &source);

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
};

#endif