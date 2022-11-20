/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:16:01 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 20:16:00 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define MAX_HP 100

# include <iostream>

class ClapTrap
{
	protected:
		std::string		name_;
		int				hit_point_;
		unsigned int	energy_point_;
		unsigned int	attack_damage_;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hit_point, unsigned int energy_point, unsigned int attack_damage);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);
		virtual ~ClapTrap();
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif
