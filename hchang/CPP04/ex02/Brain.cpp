/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:08:32 by hchang            #+#    #+#             */
/*   Updated: 2022/11/21 13:44:34 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain Default Constructor Called]\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "hello";
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
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = obj._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[Brain Destructor Called]\n";
}

void	Brain::getIdeas(void)
{
	for (int i = 0; i < 100; i++)
		std::cout << this->_ideas[i] << " ";
	std::cout << std::endl;
}
