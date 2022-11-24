/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 03:48:23 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/24 13:57:18 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int N): _max(N), _storage(0)
{
	
}

Span::Span(const Span& source)
{
	*this = source;
}

Span::~Span()
{
	
}

Span& Span::operator=(const Span &source)
{
	if (this == &source)
		return (*this);
	this->_max = source._max;
	this->_storage = source._storage;
	return (*this);
}

void Span::addNumber(int number)
{
	if (!this->_storage.size())
	{
		this->_storage.push_back(number);
	}
	else if (this->_storage.size() < this->_max)
	{
		if (find(this->_storage.begin(), this->_storage.end(), number) == this->_storage.end())
		{
			this->_storage.push_back(number);
		}
		else
			throw(Span::AlreadyStoredElement());
	}
	else
		throw(Span::StorageFull());
}

int Span::shortestSpan()
{
	if (this->_storage.size() >= 2)
	{
		unsigned int minVal = UINT_MAX;
		sort(this->_storage.begin(), this->_storage.end());
		for (std::vector<int>::iterator it = this->_storage.begin(); it != this->_storage.end(); it++)
		{
			unsigned int temp = *(it + 1) - *(it);
			minVal = std::min(minVal, temp);
		}
		return (minVal);
	}
	else
		throw(Span::NotCompatiable());
	return 0;
}

int Span::longestSpan()
{
	if (this->_storage.size() >= 2)
		sort(this->_storage.begin(), this->_storage.end());
	else
		throw(Span::NotCompatiable());
	return (this->_storage.back() - this->_storage.front());
}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (end - begin == this->_max)
	{
		int i = 0;
		while (begin != end)
		{
			addNumber(*begin);
			std::cout << i << std::endl;
			begin++;
			i++;
		}
	}
	else
	{
		throw(Span::InvalidVector());
	}
}


const char *Span::AlreadyStoredElement::what() const throw()
{
	return "already existing element";
}

const char *Span::StorageFull::what() const throw()
{
	return "storage is full";
}

const char *Span::NotCompatiable::what() const throw()
{
	return "not compatiable";
}

const char *Span::InvalidVector::what() const throw()
{
	return "invalid vector";
}