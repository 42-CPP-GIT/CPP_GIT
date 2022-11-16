/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:22:07 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/16 18:57:44 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
private:
	int _health;
	int _energyPoint;
	int _attackDamage;
	std::string _name;

	bool actionIsValid(std::string action);
	bool errorPrint(std::string action, int flag);

public:
	ClapTrap(/* args */);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap();
	ClapTrap& operator = (const ClapTrap &source);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void printStatus(void);

	const int& getHealth(void) const;
	const int& getEnergy(void) const;
	const int& getAttackDamage(void) const;
	const std::string& getName(void) const;

	void setHealth(const int health);
	void setEnergy(const int energy);
	void setAttackDamage(const int damage);
	void setName(const std::string name);
};