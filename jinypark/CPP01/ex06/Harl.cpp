/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/03 16:52:02 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}
void	Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
}
void	Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}
void	Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void    Harl::complain(std::string level)
{
	std::string	command[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};


	int	i = 0;
	while (level != command[i] && i < 4)
		++i;
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
		{
			this->error();
			break ;
		}	
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}