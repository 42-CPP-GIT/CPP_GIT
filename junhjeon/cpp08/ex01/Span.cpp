/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:08:32 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/25 21:01:45 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

void Span::addNumberAll (int *x, unsigned int size)
{
	if (size > size_)
		throw error("your array size over the limit");
	(*store_).insert((*store_).begin(), x, x + size);;
	///for (unsigned i = 0; i < size; i++)
	///	std::cout << (*store_)[i] <<std::endl;

}

Span::Span(unsigned int n)
{
	store_ = new std::vector<int>;
	size_ = n;
}

Span::~Span()
{
	delete store_;
}

Span::Span(const Span& copy)
{
	store_ = 0;
	*this = copy;
}

std::vector<int> *Span::getStore( void ) const
{
	return (store_);
}

unsigned int Span::getSize( void ) const
{
	return (size_);
}

Span& Span::operator = (const Span& s)
{
	if (this !=  &s)
	{
		if (!store_)
			delete store_;
		std::vector<int> *temp;
		store_ = new std::vector<int>;
		temp = s.getStore();
		size_ = s.getSize();

		for (unsigned long i = 0; i < (*temp).size(); i++)
			store_->push_back((*temp)[i]);
	}
	return *this;
}

std::string Span::error(std::string str) const
{
	return (str);
}

void	Span::addNumber(unsigned int n)
{
	if (store_->size() == size_)
		throw error("Size is full");
	else
		store_->push_back(n);
}

int Span::shortestSpan( void ) const 
{
	if (store_->size() == 0 || store_->size() == 1)
		throw error("Size is 0 or 1");

	std::vector<int> temp(*store_);
	std::sort(temp.begin(), temp.end());
	std::vector<int> sub;

	for (unsigned long i = 0; i < temp.size() - 1; i ++)
			sub.push_back((temp)[i + 1] - (temp)[i]);

	std::sort(sub.begin(), sub.end());

	return (*sub.begin());
}

int Span::longestSpan( void ) const
{
	if (store_->size() == 0 || store_->size() == 1)
		throw error("Size is 0 or 1");

	int max = *std::max_element(store_->begin(), store_->end());
	int min = *std::min_element(store_->begin(), store_->end());

	return (max - min);
}
