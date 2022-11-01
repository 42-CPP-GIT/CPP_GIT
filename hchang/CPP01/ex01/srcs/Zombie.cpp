/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:16 by hchang            #+#    #+#             */
/*   Updated: 2022/11/01 12:43:57 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() { std::cout << "hey" << std::endl; }

Zombie::~Zombie() {
  // reference 변수 좀 봐두기
  // 콜론 초기화
  std::cout << "[destructor] " << this->name_ << " will be back.. "
            << std::endl;
  delete[] Zombie
}
