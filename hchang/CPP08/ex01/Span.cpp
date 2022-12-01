/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:33:28 by hchang            #+#    #+#             */
/*   Updated: 2022/12/01 17:09:51 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char * Span::OutofBoundException::what() const throw()
{
	return ("ERROR : You Access Out of Bounds");
}

const char * Span::DuplicateException::what() const throw()
{
	return ("ERROR : You insert dupliacted number(s)");
}

const char * Span::EmptyNumberException::what() const throw()
{
	return ("ERROR : There is no Number or only one Number");
}

int		Span::shortestSpan(void)
{
	if (_vec.size() < 2)
		throw EmptyNumberException();
	std::vector<int> result;
	std::sort(_vec.begin(), _vec.end());
	for (size_t i = 0; i < _vec.size() - 1; i++)
		result.push_back(_vec[i + 1] - _vec[i]);
	std::sort(result.begin(), result.end());
	return (*(result.begin()));
}

void Span::print_vec()
{
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

int		Span::longestSpan(void)
{
	if (_vec.size() < 2)
		throw EmptyNumberException();
	std::sort(_vec.begin(), _vec.end());
	return (*(_vec.end() - 1) - *(_vec.begin()));
}

void	Span::addNumber(int num)
{
	if (this->_max == this->_vec.size())
		throw OutofBoundException();
	for ( std::vector<int>::iterator it(_vec.begin()); 
	it != _vec.end();
	++(it))
	{
		if ((*it) == num)
			throw DuplicateException();
	}
	this->_vec.push_back(num);
}

void	Span::addNumbers(int *num, unsigned int num_size)
{
	if (this->_max < num_size)
		throw OutofBoundException();
	for (unsigned int i = 0; i < num_size; i++)
	{
		for (unsigned int j = i + 1; j < num_size; j++)
		{
			if (num[i] == num[j])
				throw DuplicateException();
		}
	}
	_vec.insert(_vec.begin(), num, num + num_size);
}

Span::Span(unsigned int N) : _max(N)
{
}

Span::Span(const Span& obj)
{
	*this = obj;
}

Span& Span::operator=(const Span& obj)
{
	if (this == &obj)
		return (*this);
	this->_max = obj._max;
	this->_vec.insert(_vec.begin(), obj._vec.begin(), obj._vec.end());
	return (*this);
}

Span::~Span()
{
}

