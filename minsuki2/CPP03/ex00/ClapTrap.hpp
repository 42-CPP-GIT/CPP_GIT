/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/10 17:04:44 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define MSG_ANNOUNCE		"[Announce]"
# define MSG_CLAPTRAP_BORN	"Seriously? Claptrap? You'vs heard about his weird Actions Skill, right? This is REALLY what you want?"
# define MSG_GONE			"hi is gone..."
# define MSG_CLAPTRAP		"ClapTrap"
# define MSG_GETRB			"getRawBits member function"
# define MSG_ATTACK			"attacks"
# define MSG_CAUSE			"causinig"
# define MSG_DAMAGE_POINT	"points of damage"

class ClapTrap {
	const std::string	bot_name_;
	unsigned int		health_point_;
	unsigned int		energy_point_;
	unsigned int		attack_damage_;

	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);
		~ClapTrap(void);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
