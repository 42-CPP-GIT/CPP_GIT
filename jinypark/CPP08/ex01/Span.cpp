/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:55:35 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/01 21:57:49 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) { this->arr_.reserve(N); }

Span::Span(const Span& obj) { this->arr_ = obj.arr_; }

Span&	Span::operator=(const Span& obj)
{
	this->arr_ = obj.arr_; return (*this);
}

Span::~Span() {}

unsigned int	Span::shortestSpan()
{
	if (this->arr_.size() <= 1)
		throw (NotFoundException());

	std::vector<int> tmp(this->arr_);

	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return (*std::min_element(tmp.begin() + 1, tmp.end()));
}

unsigned int	Span::longestSpan()
{
	if (this->arr_.size() <= 1)
		throw (NotFoundException());

	return (*std::max_element(this->arr_.begin(), this->arr_.end())
			- *std::min_element(this->arr_.begin(), this->arr_.end()));
}

void			Span::print()
{
	for(std::vector<int>::iterator it = this->arr_.begin(); it != this->arr_.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}


void Span::addNumber(int number)
{
	if (this->arr_.size() >= this->arr_.capacity())
		throw(FullException());
	this->arr_.push_back(number);
}

const char* Span::FullException::what() const throw() { return ("Array is full!"); }

const char* Span::NotFoundException::what() const throw() { return ("Span not found!"); }