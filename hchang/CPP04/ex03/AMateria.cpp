/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:45:02 by hchang            #+#    #+#             */
/*   Updated: 2022/11/17 17:53:09 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria new"<< std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout << "AMateria Constructor called" << std::endl;
}

std::string const&	AMateria::getType() const
{
	std::cout << "AMateria getType called" << std::endl;
	return (this->_type);
}

AMateria::~AMateria()
{
	std::cout << "AMateria delete\n";
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "AMateria use\n";
}