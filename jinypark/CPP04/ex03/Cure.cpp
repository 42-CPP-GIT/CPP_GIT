/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:57:10 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 02:47:20 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	#ifdef EVAL
	std::cout << "[Cure] default constructor has been called.\n";
	#endif
}

Cure::~Cure()
{
	#ifdef EVAL
	std::cout << "[Cure] default destructor has been called.\n";
	#endif
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "’s wounds *\n";
}