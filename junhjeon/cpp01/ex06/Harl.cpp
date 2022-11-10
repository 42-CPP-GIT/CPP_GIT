/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:33:22 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 20:28:32 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string str = "[debug]0[info]1[warning]2[error]3[DEBUG]0[INFO]1[WARNING]2[ERROR]3";
	std::string lvl = "[" + level + "]";
	int	switch_case;
	int	level_size;
	int	i;

	level_size = level.size() + 2;
	switch_case = str.find(lvl, 0);
	i = str[switch_case + level_size] - '0';

	switch (i)
	{
		case 0:
			(this->*comp[0])();
		case 1:
			(this->*comp[1])();
		case 2:
			(this->*comp[2])();
		case 3:
			(this->*comp[3])();
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;

	}
}

Harl::Harl()
{
	comp[0] = &Harl::debug;
	comp[1] = &Harl::info;
	comp[2] = &Harl::warning;
	comp[3] = &Harl::error;
}
