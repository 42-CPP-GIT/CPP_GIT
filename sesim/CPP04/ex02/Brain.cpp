/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:12:57 by sesim             #+#    #+#             */
/*   Updated: 2022/12/05 12:50:11 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[ Brain Constructor Called ]" << std::endl;
	for (int i(0); i < 100; ++i)
		this->_ideas[i] = "I HAVE NO IDEA";
}

Brain::Brain(const Brain& obj)
{
	std::cout << "[ Brain Copy Constructor Called ]" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	if (this == &obj)
		return (*this);
	for (int i(0); i < 100; ++i)
		this->_ideas[i] = obj._ideas[i];
	return (*this);
}

void	Brain::showIdeas(void)
{
	for (int i(0); i < 100; ++i)
		std::cout << this->_ideas[i] << "\t";
	std::cout << std::endl;
}

Brain::~Brain()
{
	std::cout << "[ Brain Destructor Called ]" << std::endl;
}
