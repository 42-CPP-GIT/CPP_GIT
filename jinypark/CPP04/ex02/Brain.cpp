/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:15:30 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 17:54:49 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] default constructor has been called.\n";
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = "Empty";
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor has been called.\n";
}

Brain::Brain(const Brain &obj)
{
	std::cout << "[Brain] copy constructor has been called.\n";
	*this = obj;
}

Brain	&Brain::operator=(Brain const &obj)
{
	std::cout << "[Brain] copy assignment operator has been called.\n";
	if (this != &obj)
	{
		this->ideaCnt = obj.getIdeaCnt();
		for (unsigned int i = 0; i < 100; ++i)
			this->ideas[i] = obj.getIdeas(i);
	}
	return (*this);
}

void	Brain::setIdeas(const std::string& idea)
{
	this->ideas[this->ideaCnt++] = idea;
	if (this->ideaCnt == 100)
		this->ideaCnt = 0;
}

void	Brain::setIdeas(const std::string* ideas)
{
	for (unsigned int i = 0; i < 100; ++i)
	{
		this->ideas[i] = ideas[i];
	}
}

const std::string	Brain::getIdeas(unsigned int i) const
{
	return (this->ideas[i % 100]);
}

const std::string*	Brain::getIdeas(void) const
{
	return (&this->ideas[0]);
}

unsigned int	Brain::getIdeaCnt(void) const
{
	return (this->ideaCnt);
}

void	Brain::showIdeas(void) const
{
	std::cout << "  ";
	for (unsigned int n = 0; n < 10; ++n)
		std::cout << std::setw(10) << n << "|";
	std::cout << "\n";
	for (unsigned int i = 0; i < 10; ++i)
	{
		std::cout << i << "|";
		for (unsigned int j = 0; j < 10; ++j)
			std::cout << std::setw(10) << this->ideas[i * 10 + j] << "|";
		std::cout << "\n";
	}
}
