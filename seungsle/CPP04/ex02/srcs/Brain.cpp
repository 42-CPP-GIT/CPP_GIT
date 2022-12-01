/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:51:32 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 23:44:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain Constructor called]" << std::endl;
}

Brain::Brain(const Brain &Brain)
{
	std::cout << "[Brain Copy Constructor called]" << std::endl;
	*this = Brain;
}

Brain::~Brain()
{
	std::cout << "[Brain destructor called]" << std::endl;
}

Brain& Brain::operator=(const Brain &source)
{
	std::cout << "[Brain Copy assignment oprator called]" << std::endl;
	if (this == &source)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = source._ideas[i];
	return (*this);
}