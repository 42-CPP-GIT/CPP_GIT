/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:29:06 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/29 23:46:17 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
# include <vector>
# include <algorithm>

class Span
{
private:
	int* arr;
public:
	Span(unsigned int N);
	Span::Span(const Span& obj);
	~Span();
	void addNumber(int number);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	class ErrorFull : std::exception
	{
	public:
		const char* what() const throw();
	};
	class ErrorNotFound : std::exception
	{
	public:
		const char* what() const throw();
	};
private:
	Span();
};

Span::Span(/* args */)
{
}

Span::Span(unsigned int N)
{
	this->arr = new int[N];
}

Span::Span(const Span& obj)
{
	(void)obj;
}

Span&	Span::operator=(const Span& obj)
{
	(void)obj;
}

Span::~Span()
{
	delete[] this->arr;
}

void addNumber(int number)
{
	
}


#endif