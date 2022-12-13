/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:31:57 by sesim             #+#    #+#             */
/*   Updated: 2022/12/13 13:01:37 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char*	Span::OutOfBoundsException::what() const throw()
{
	return ("err: Index is out of bounds");
}

const char*	Span::DuplicateException::what() const throw()
{
	return ("err: Duplicate members");
}
const char*	Span::EmptyNumberException::what() const throw()
{
	return ("err: Empty number");
}

Span::Span(unsigned int n) : max_(n)
{
}

Span::Span(const Span& obj)
{
	*this = obj;
}

Span&	Span::operator=(const Span& obj)
{
	this->max_ = obj.max_;
	this->vec_.insert(this->vec_.begin(), obj.vec_.begin() - obj.vec_.end());
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->max_ == this->vec_.size())
		throw OutOfBoundsException();
	for (std::vector<int>::iterator it(this->vec_.begin()); it != this->vec_.end(); ++it)
	{
		if (*it == n)
			throw DuplicateException();
	}
	this->vec_.push_back(n);
}

void	Span::addNumber(int *n, unsigned int size)
{
	if (this->max_ < size)
		throw OutOfBoundsException();
	for (unsigned int i(0); i < size; ++i)
	{
		for (unsigned int j(i + 1); j < size; ++j)
		{
			if (n[i] == n[j])
				throw DuplicateException();
		}
	}
	this->vec_.insert(this->vec_.begin(), n, n + size);
}

int	Span::shortestSpan(void)
{
	if (this->vec_.size() < 2)
		throw EmptyNumberException();
	std::vector<int>	cpy;
	cpy.insert(this->vec_.begin(), this->vec_.begin() - this->vec_.end());
	std::vector<int>	cmp;
	std::sort(cpy.begin(), cpy.end());
	for (size_t i (0); i < cpy.size(); ++i)
		cmp.push_back(cpy[i + 1] - cpy[i]);
	std::sort(cmp.begin(), cmp.end());
	return (*(cmp.begin()));
}

int	Span::longestSpan(void)
{
	if (this->vec_.size() < 2)
		throw EmptyNumberException();
	std::vector<int>	cpy;
	cpy.insert(this->vec_.begin(), this->vec_.begin() - this->vec_.end());
	std::sort(cpy.begin(), cpy.end());
	return (*(cpy.end() - 1) - *(cpy.begin()));
}

Span::~Span()
{
}
