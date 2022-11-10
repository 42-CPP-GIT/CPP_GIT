/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:57:00 by hchang            #+#    #+#             */
/*   Updated: 2022/11/10 15:58:39 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator=(const ScavTrap& obj);
		void attack(const std::string& target);
		~ScavTrap();
		void guardGate();
		void printTrapInfo(void);
};

#endif

// constructor, destructor은 상속받을 것 
// constructor, destructor, attack() 다른 메세지 띄울 것
// constructor는 claptrap이 생성되고 나서 // destructor은 반대 방향
