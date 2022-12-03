/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:52:24 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 21:02:48 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "[ AMateria Created ]" << std::endl;
}

AMateria::AMateria(std::string const & type) : type_(type)
{
	std::cout << "[ AMateria " << type << " Created ]" << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	std::cout << "[ AMateria Copied ]" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria & obj)
{
	if (this == &obj)
		return (*this);
	this->type_ = obj.getType();
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->type_);
}

void		AMateria::use(ICharacter& target)
{
	std::cout << "[ AMateria " << this->getType() << " use to " << target.getName() << " ]" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "[ AMateria " << this->getType() << " Vanished ]" << std::endl;
}
