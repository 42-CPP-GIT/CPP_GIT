/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/09 16:03:22 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n";
}
void	Harl::info(void)
{
	std::cout << "[INFO]\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}
void	Harl::warning(void)
{
	std::cout << "[WARNING]\n";
    std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n\n";
}
void	Harl::error(void)
{
	std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void    Harl::complain(std::string level)
{
	std::string	command[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = 0;
	while (i < 4 && level != command[i])
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