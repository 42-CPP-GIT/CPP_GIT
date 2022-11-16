/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:16:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 00:18:54 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
	bool _isGateKeeperMode;
public:
	ScavTrap(/* args */);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ScavTrap);
	~ScavTrap();
	ScavTrap& operator = (const ScavTrap &source);

	void printStatus(void);

	const bool& getIsGateKeeperMode(void);
	void setIsGateKeeperMode(bool isGateKeeperMode);

	void guardGate(void);
	void attack(const std::string& target);
};

#endif