/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:38:15 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 19:17:11 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor " << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor " << std::endl;
}

Brain::Brain( const Brain& copy)
{
	std::cout << "Brain copy construct" << std::endl;
	*this = copy;
}

Brain& Brain::operator = ( const Brain& b )
{
	std::cout << "Brain = construct" << std::endl;
	if (this != &b)
	{
		for (int i = 0; i < 100 ; i++)
		{
			_ideas[i] = b._ideas[i];
		}
	}
	return (*this);
}

std::string* Brain::getIdeas ( void )
{
	return (&(_ideas[0]));
}
