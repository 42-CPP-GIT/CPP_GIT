/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:33:22 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/01 18:30:27 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string str = "[debug]0[info]1[warning]2[error]3";
	std::string lvl = "[" + level + "]";
	int	switch_case;
	int	level_size;
	int	i;

	level_size = level.size() + 2;
	switch_case = str.find(lvl, 0);

	switch (switch_case)
	{
		case -1:
			break ;
		default:
			i = str[switch_case + level_size] - '0';
			(this->*comp[i])();
	}
}

Harl::Harl()
{
	comp[0] = &Harl::debug;
	comp[1] = &Harl::info;
	comp[2] = &Harl::warning;
	comp[3] = &Harl::error;
}
