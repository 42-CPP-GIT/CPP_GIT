/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:23:12 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 19:18:03 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl(void) {}

Harl::~Harl(void) {}


void	Harl::debug(void) {
	std::cout << MSG_DEBUG << MSG_ENDL;
}

void	Harl::info(void) {
	std::cout << MSG_INFO << MSG_ENDL;

}

void	Harl::warning(void) {
	std::cout << MSG_WARNING << MSG_ENDL;
}

void	Harl::error(void) {
	std::cout << MSG_ERROR << MSG_ENDL;
}

void	Harl::complain(std::string level) {
	const std::string	level_ar[NUM_FUNC] \
									= {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;
	while (++i < NUM_FUNC && level != level_ar[i]);
	switch (i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << MSG_ELSE << MSG_ENDL;
	}
}
