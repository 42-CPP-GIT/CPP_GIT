/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:16 by hchang            #+#    #+#             */
/*   Updated: 2022/11/02 11:24:02 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name_ << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{ 
	std::cout << "My life for Aiur!" << std::endl;
}

Zombie::~Zombie() {
	// reference 변수 좀 봐두기
	// 콜론 초기화
	std::cout << "[destructor] " << this->name_ << " will be back.. " << std::endl;
}

void	Zombie::setZombieName(std::string name)
{
	this->name_ = name;
}
