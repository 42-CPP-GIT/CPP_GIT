/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:03:11 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/08 22:58:31 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "[default constructor called]" << std::endl;
}

ClapTrap::ClapTrap(std::string &name)
{
	std::cout << "[string constructor called]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{

}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{

}

ClapTrap::~ClapTrap()
{
	std::cout << "[destructor called]" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}
