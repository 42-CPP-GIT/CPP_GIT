/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:57:10 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 14:55:20 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	#ifdef DEBUG
	std::cout << "[Ice] default constructor has been called.\n";
	#endif
}

Ice::~Ice()
{
	#ifdef DEBUG
	std::cout << "[Ice] default destructor has been called.\n";
	#endif
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() + " *\n";
}