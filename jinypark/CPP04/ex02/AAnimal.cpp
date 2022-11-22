/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:59:52 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 15:32:22 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	this->type = "Abstract Animal";
}

AAnimal::~AAnimal(void)
{
}

AAnimal::AAnimal(const AAnimal &obj)
{
	*this = obj;
}

AAnimal	&AAnimal::operator=(AAnimal const &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}

