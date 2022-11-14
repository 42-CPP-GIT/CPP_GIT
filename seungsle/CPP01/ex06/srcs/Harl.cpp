/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:16:19 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/14 17:42:15 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

Harl::Harl()
{

}

Harl::~Harl()
{
	
}

void	Harl::complain(std::string level)
{
	std::string levels("[DEBUG][INFO][WARNING][ERROR]");
	void (Harl::* f[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	level.insert(0, "[");
	level += "]";
	switch (levels.find(level))
	{
	case 0:
		(this->*f[0]) ();
	case 7:
		(this->*f[1]) ();
	case 13:
		(this->*f[2]) ();
	case 22:
		(this->*f[3]) ();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}
}