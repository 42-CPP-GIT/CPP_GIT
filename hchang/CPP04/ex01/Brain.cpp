/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:08:32 by hchang            #+#    #+#             */
/*   Updated: 2022/11/11 15:36:38 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain Default Constructor Called]\n";
	this->ideas = new std::string[100];
}

Brain::Brain(const Brain& obj)
{
	std::cout << "[Brain Copy Constructor Called]\n";
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	if (this == &obj)
		return (*this);
	if (this->ideas)
	{
		delete [] this->ideas;
		this->ideas = NULL;
	}
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[Brain Destructor Called]\n";
	delete [] this->ideas;
}
