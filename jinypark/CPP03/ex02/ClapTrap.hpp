/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:43:08 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/19 23:48:18 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

# define CLAP_HP 10
# define CLAP_EP 10
# define CLAP_AD 0

class ClapTrap
{
protected:
	std::string		name_;
	int				hitPoint_;
	unsigned int	energyPoint_;
	unsigned int	attackDamage_;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &obj);
	ClapTrap	&operator=(ClapTrap const &obj);
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName(void) const;
	unsigned int	getHitPoint(void) const;
	unsigned int	getEnergyPoint(void) const;
	unsigned int	getAttackDamage(void) const;
	void			printStat(void);
};

#endif