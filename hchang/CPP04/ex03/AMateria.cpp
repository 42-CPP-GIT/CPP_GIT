/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:45:02 by hchang            #+#    #+#             */
/*   Updated: 2022/11/16 14:58:20 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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

void	AMateria::use(ICharacter& target)
{
	if (this->_type == "Ice")
		std::cout << "* shoots an ice bolt at " << target._name << " *" << std::cout;
	else if (this->_type == "Cure")
		std::cout << "* heals " << target._name << "'s wounds *" << std::cout;
}