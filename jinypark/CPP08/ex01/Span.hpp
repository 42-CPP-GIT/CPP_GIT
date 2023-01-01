/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:29:06 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/01 22:21:53 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>
# include <numeric>

class Span
{
private:
	std::vector<int> arr_;
public:
	Span(unsigned int N);
	~Span();
	void addNumber(int number);

	template <typename T>
	void addNumber(T begin, T end)
	{
		if (std::distance(begin, end) > static_cast<long>((this->arr_.capacity() - this->arr_.size())))
			throw(FullException());
		for (; begin != end; ++begin)
			this->arr_.push_back(*begin);
	}

	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			print();
	class FullException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class NotFoundException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	Span&	operator=(const Span& obj);
	Span(const Span& obj);
private:
	Span();
};

#endif