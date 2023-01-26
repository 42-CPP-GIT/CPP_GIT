/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:05:11 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/26 15:30:43 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : N_(n) { }

Span::Span(const Span& obj) {
	*this = obj;
}

Span&	Span::operator=(const Span& obj) {
	this->N_ = obj.N_;
	return *this;
}

Span::~Span(void) { }

void	Span::addNumber(unsigned int n) {
	if (this->pocket_.size() == this->N_) {
		throw Span::OverMaximumStoreException();
	}
	else if (find(this->pocket_.begin(), this->pocket_.end(), n) != this->pocket_.end()) {
		throw Span::AddNumberTwiceException();
	}
	this->pocket_.push_back(n);
}

// static	void	_showVectorInt(const std::vector<int>& target) {
	// for (std::vector<int>::const_iterator it(target.begin())
		// ; it != target.end(); ++it) {
		// std::cout << *it << ' ';
	// } std::cout << std::endl;
// }

unsigned int	Span::shortestSpan(void) const {

	std::vector<unsigned int>	tmp(this->pocket_.size() < 2
								? throw AtLeastTwoException() : this->pocket_);
	// _showVectorInt(tmp);
	std::sort(tmp.begin(), tmp.end());

	return tmp.at(1) - tmp.at(0);
}

unsigned int	Span::longestSpan(void) const {
	return this->pocket_.size() < 2 ? throw AtLeastTwoException()
			: *std::max_element(this->pocket_.begin(), this->pocket_.end())
				- *std::min_element(this->pocket_.begin(), this->pocket_.end());
}


const char*	Span::AddNumberTwiceException::what() const throw() {
	return "DO NOT add number twice to Span";
}

const char*	Span::OverMaximumStoreException::what() const throw() {
	return "The Span's capacity is not enough!!";
}

const char*	Span::AtLeastTwoException::what() const throw() {
	return "LongesetSpan or ShorestSpan need two nubmers at least !";
}

void	Span::showSpanNumber(void) const {
	for (std::vector<unsigned int>::const_iterator it(this->pocket_.begin())
		; it != this->pocket_.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

const std::vector<unsigned int>&	Span::getPocket() const { return this->pocket_; }

