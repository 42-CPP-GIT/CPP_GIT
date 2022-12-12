/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/12 14:20:10 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define MSG_CONSTRUCT		"[Constructor]"
# define MSG_DESTRUCT		"[Destructor]"
# define MSG_ANNOUNCE		"[Announce]"
# define MSG_CLAPTRAP_BORN	"Seriously? Claptrap? You'vs heard about his weird Actions Skill, right? This is REALLY what you want?"
# define MSG_GONE			"hi is gone..."
# define MSG_CLAPTRAP		"ClapTrap"
# define MSG_GETRB			"getRawBits member function"
# define MSG_ATTACK			"attacks"
# define MSG_TAKE_DAMAGE	"is taken damage"
# define MSG_CAUSE			"causinig"
# define MSG_LEFT			"lefting"
# define MSG_INCREASE		"increasing"
# define MSG_HP				"HP"
# define MSG_P_O_D			"points of damage!"
# define MSG_NO_HP			"can not do anything because HP is 0!"
# define MSG_NO_MP			"can not do anything because MP is 0!"
# define MSG_DIED			"is already dead..."
# define MSG_REPAIR			"is repaired"

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
