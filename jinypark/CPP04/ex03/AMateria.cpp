/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:58:58 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 09:12:26 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->type_ = type;
}

std::string const & AMateria::getType() const
{
	return (this->type_);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName();
}